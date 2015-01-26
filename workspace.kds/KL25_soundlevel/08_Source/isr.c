//===========================================================================
//文件名称：isr.c
//功能概要： 中断底层驱动构件源文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2013-4-7   
//===========================================================================
#include "includes.h"

//========================测试===============================
//串口1接收中断服务例程
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



