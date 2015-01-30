

#ifndef SYSINIT_H
#define SYSINIT_H

#include "common.h"
#include "vectors.h"

//定义系统时钟、总线时钟
#define  MCGFLL_CLK_KHZ         48000    //FLL输出时钟频率，kHz
#define  MCGPLL_CLK_KHZ         48000    //PLL输出时钟频率，kHz
#define  CORE_CLK_KHZ   MCGPLL_CLK_KHZ   //芯片内核时钟频率，kHz
#define  BUS_CLK_KHZ             24000   //芯片总线时钟频率，Khz
#define  MCGIR_CLK_KHZ           4000    //内部参考时钟频率，kHz

//===========================================================================
//函数名称：sys_init
//函数返回：无
//参数说明：无
//功能概要：(1)KL25的EXTAL(40)、XTAL(41)接8Mhz外部晶振，产生PLL/FLL输出时钟频
//             率48MHz,内核时钟48MHz，总线时钟24MHz，内部参考时钟4MHz。
//          (2)对于这些频率，sys_init.h有相应的宏常量定义可以供编程时使用
//===========================================================================
void sys_init(void);

#endif 
