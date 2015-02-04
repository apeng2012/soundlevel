//===========================================================================
//文件名称：isr.h
//功能概要： 中断底层驱动构件头文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2012-11-12   V1.0
//===========================================================================

#ifndef _ISR_H
#define _ISR_H


// 注册串口1中断向量
#ifdef VECTOR_029
	#undef VECTOR_029
#endif
extern void isr_uart1_re(void);
#define VECTOR_029  isr_uart1_re

// 注册ADC中断向量
#ifdef VECTOR_031
	#undef VECTOR_031
#endif
extern void isr_adc(void);
#define VECTOR_031  isr_adc


#ifdef VECTOR_017
	#undef VECTOR_017
#endif
extern void isr_dma1(void);
#define VECTOR_017  isr_dma1

#endif


