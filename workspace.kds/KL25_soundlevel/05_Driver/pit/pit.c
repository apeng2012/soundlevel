//==========================================================================
//文件名称：pit.c
//功能概要：KL25 pit底层驱动程序文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//版本更新：2013-5-5  V2.0
//==========================================================================
#include "pit.h"
//==========================================================================
//函数名称: pit_init
//函数返回: 无
//参数说明: pitno:表示pit通道号，0,1。
//          int_us:表示定时器运行的周期单位微秒.一般取5ms.即5000
//功能概要: 设置相关寄存器的值
//==========================================================================
void pit_init(uint_8 pitno,uint_32 int_us)
{
     uint_32 int_ticks;
     //中断时间计算公式:(24000000/1000)*5(ms).周期为5ms
     int_ticks=24*int_us-1;             //24000*int_us/1000-1;
     BSET(SIM_SCGC6_PIT_SHIFT,SIM_SCGC6);        //开PIT时钟门
     BCLR(PIT_MCR_MDIS_SHIFT,PIT_MCR);           //使能PIT模块
     BCLR(PIT_MCR_FRZ_SHIFT,PIT_MCR);            //调试模式下使能
     //PIT的时钟采用总线时钟24MHZ
     PIT_LDVAL(pitno)=int_ticks;
//   PIT_TCTRL(pitno)|=(PIT_TCTRL_TIE_MASK); 	//开pit模块中断
     PIT_TCTRL(pitno)|=PIT_TCTRL_TEN_MASK;       //使能pit模块运行
     PIT_TCTRL(pitno)|=(PIT_TCTRL_TIE_MASK); 
}
    
//==========================================================================
//函数名称: enable_pit_int
//函数返回: 无
//参数说明: 无
//功能概要: 开PIT中断
//==========================================================================
void enable_pit_int()
{
     enable_irq(PIT_IRQ_NO);    //开接收引脚的IRQ中断
}

//==========================================================================
//函数名称: disable_pit_int
//函数返回: 无
//参数说明: 无
//功能概要: 关闭PIT中断
//==========================================================================
void disable_pit_int()
{
     disable_irq(PIT_IRQ_NO);    //关接收引脚的IRQ中断
}
