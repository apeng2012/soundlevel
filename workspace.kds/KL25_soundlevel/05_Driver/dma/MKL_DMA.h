/*********************************************Copyright (c)***********************************************
**                                Guangzhou ZLG MCU Technology Co., Ltd.
**
**                                        http://www.zlgmcu.com
**
**      广州周立功单片机科技有限公司所提供的所有服务内容旨在协助客户加速产品的研发进度，在服务过程中所提供
**  的任何程序、文档、测试结果、方案、支持等资料和信息，都仅供参考，客户有权不使用或自行参考修改，本公司不
**  提供任何的完整性、可靠性等保证，若在客户使用过程中因任何原因造成的特别的、偶然的或间接的损失，本公司不
**  承担任何责任。
**                                                                        ——广州周立功单片机科技有限公司
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               MKL_DMA.h
** Last modified date:      2012-12-14
** Last version:            V1.0
** Descriptions:            DMA驱动程序
**
**--------------------------------------------------------------------------------------------------------
** Created by:              Li Xiang
** Created date:            2012-12-14
** Version:                 V0.9
** Descriptions:            The original version 初始版本
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
*********************************************************************************************************/
#ifndef __MKL_DMA_H__
#define __MKL_DMA_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "common.h"    //包含公共要素头文件

/*********************************************************************************************************
  宏定义
*********************************************************************************************************/
/*********************************************************************************************************
**  MKL25 DMA Request Source
**
**2 UART0 Receive
**3 UART0 Transmit
**4 UART1 Receive
**5 UART1 Transmit
**6 UART2 Receive
**7 UART2 Transmit
**8 Reserved
**9 Reserved
**10 Reserved
**11 Reserved
**12 Reserved
**13 Reserved
**14 Reserved
**15 Reserved
**16 SPI0 Receive
**17 SPI0 Transmit
**18 SPI1 Receive
**19 SPI1 Transmit
**20 Reserved
**21 Reserved
**22 I2C0
**23 I2C1
**24 TPM0 Channel 0
**25 TPM0 Channel 1
**26 TPM0 Channel 2
**27 TPM0 Channel 3
**28 TPM0 Channel 4
**29 TPM0 Channel 5
**30 Reserved
**31 Reserved
**32 TPM1 Channel 0
**33 TPM1 Channel 1
**34 TPM2 Channel 0
**35 TPM2 Channel 1
**36 Reserved
**37 Reserved
**38 Reserved
**39 Reserved
**40 ADC0
**41 Reserved
**42 CMP0
**43 Reserved
**44 Reserved
**45 DAC0
**46 Reserved
**47 Reserved
**48 Reserved
**49 Port control module Port A
**50 Reserved
**51 Reserved
**52 Port control module Port D
**53 Reserved
**54 TPM0 Overflow
**55 TPM1 Overflow
**56 TPM2 Overflow
**57 TSI
**58 Reserved
**59 Reserved
**60 DMA MUX Always enabled
**61 DMA MUX Always enabled
**62 DMA MUX Always enabled
**63 DMA MUX Always enabled
*********************************************************************************************************/
/*
 * DMA序号宏定义
 */
#define MKL_DMA0        0
#define MKL_DMA1        1
#define MKL_DMA2        2
#define MKL_DMA3        3
/*
 * DMA状态宏定义
 */
#define DMA_BUSY            0
#define DMA_DONE            1
#define DMA_ERROR           2

/*********************************************************************************************************
  函数声明
*********************************************************************************************************/
extern uint_8 dmaInitMemToMem(uint_8 ucDMAn,
                             void *pulSrcAddress,
                             void *pulDestAddress,
                             uint_32 ulDMASize,
                             uint_32 ucIntCon);
extern uint_8 dmaInitMemToPer(uint_8 ucDMAn,
                             uint_8 ucDMAReSource,
                             void *pulSrcAddress,
                             void *pulDestAddress,
                             uint_32 ulDMASize,
                             uint_32 ucIntCon);
extern uint_8 dmaInitPerToMem(uint_8 ucDMAn,
                             uint_8 ucDMAReSource,
                             void *pulSrcAddress,
                             void *pulDestAddress,
                             uint_32 ulDMASize,
                             uint_32 ucIntCon);

extern void dmaStartTran(uint_8 ucDMAn);
extern uint_8 dmaStatus(uint_8 ucDMAn);
#ifdef __cplusplus
}
#endif

#endif








