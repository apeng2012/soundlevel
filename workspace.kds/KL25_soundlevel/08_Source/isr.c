//===========================================================================
//文件名称：isr.c
//功能概要： 中断底层驱动构件源文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2012-11-12   V1.0
//===========================================================================
#include "includes.h"

extern uint_16 ADCResult;

//========================中断函数服务例程===============================
//串口0接收中断服务例程
void isr_uart1_re(void)
{
    uint_8 ch;
    uint_8 flag = 1;
    
    enter_critical();DISABLE_INTERRUPTS;
    ch = uart_re1(UART_TEST, &flag);
    if (0 == flag)
    {
        uart_send1(UART_TEST, ch);
    }
    
    ENABLE_INTERRUPTS;
}


void isr_adc(void) {
	enter_critical();
	ADCResult = (uint_16)ADC0_RA; //读取转换结果
	exit_critical();
}


void isr_dma1(void) {
	enter_critical();
	PIT_TCTRL(PIT0) &= ~(PIT_TCTRL_TEN_MASK);       //禁止pit模块运行
	DMA_DSR_BCR1 |= DMA_DSR_BCR_DONE_MASK;
	DMA_DCR1 &= ~DMA_DCR_EINT_MASK;
	DMAMUX0_CHCFG(MKL_DMA1) = 0x00;         // 禁能DMAMUX
	ADCResult = 1;//建立完成标志，供主程序进行查询
	exit_critical();
}
