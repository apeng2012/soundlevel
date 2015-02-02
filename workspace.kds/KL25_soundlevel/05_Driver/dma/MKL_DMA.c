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
#include "MKL_DMA.h"
/*********************************************************************************************************
** Function name:           dmaInitMemToMem
** Descriptions:            dma 内存到内存初始化
** input parameters:        ucDMAn：          DMA通道号
**                          pulSrcAddress：   存储区源地址
**                          pulDestAddress：  存储区目标地址
**                          ulDMASize：       传输字节个数
**                          ucIntCon:         中断配置
** output parameters:       none
** Returned value:          配置成功：1 配置失败：0
** Created by:              Li Xiang
** Created date:            2012-05-14
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
uint_8 dmaInitMemToMem (uint_8  ucDMAn,
                        void  *pulSrcAddress,
                        void  *pulDestAddress,
                       uint_32  ulDMASize,
                       uint_32  ucIntCon)
{
    SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;                                    /* 时钟配置                     */
    DMA_SAR_REG(DMA_BASE_PTR, ucDMAn) = (uint_32)pulSrcAddress;          /* 源地址配置                   */
    DMA_DAR_REG(DMA_BASE_PTR, ucDMAn) = (uint_32)pulDestAddress;         /* 目的地址配置                 */

    DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) |= DMA_DSR_BCR_DONE_MASK;     /* 清除Done标志位               */
    DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) = DMA_DSR_BCR_BCR(ulDMASize); /* 传输大小配置                 */

    DMA_DCR_REG(DMA_BASE_PTR, ucDMAn) =  (ucIntCon << 31)|              /* 中断配置                     */
                                         DMA_DCR_SINC_MASK|             /* 源地址自动增加               */
                                         DMA_DCR_SSIZE(1)|              /* 00-32bits 01-8bits 10-16bits */
                                         DMA_DCR_DINC_MASK|             /* 目的地址自动增加             */
                                         DMA_DCR_DSIZE(1);              /* 00-32bits 01-8bits 10-16bits */


    if (DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) & DMA_DSR_BCR_CE_MASK) {
        return 0;
    } else {
        return 1;
    }
}

/*********************************************************************************************************
** Function name:           dmaInitMemToPer
** Descriptions:            dma 内存到外设初始化
** input parameters:        ucDMAn：          DMA通道号
**                          ucDMAReSource：   DMA请求源
**                          pulSrcAddress：   存储区源地址
**                          pulDestAddress：  存储区目标地址
**                          ulDMASize：       传输字节个数
**                          ucIntCon:         中断配置
** output parameters:       none
** Returned value:          配置成功：1 配置失败：0
** Created by:              Li Xiang
** Created date:            2012-05-14
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
uint_8  dmaInitMemToPer (uint_8  ucDMAn,
                        uint_8  ucDMAReSource,
                        void  *pulSrcAddress,
                        void  *pulDestAddress,
                       uint_32  ulDMASize,
                       uint_32  ucIntCon)
{
    SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;                                    /* 时钟配置                     */
    SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;                                 /* 时钟配置                     */
    DMAMUX0_CHCFG(ucDMAn) = 0x00;                                       /* 禁能DMAMUX                   */
    DMA_SAR_REG(DMA_BASE_PTR, ucDMAn) = (uint_32)pulSrcAddress;          /* 源地址配置                   */
    DMA_DAR_REG(DMA_BASE_PTR, ucDMAn) = (uint_32)pulDestAddress;         /* 目的地址配置                 */

    DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) |= DMA_DSR_BCR_DONE_MASK;     /* 清除Done标志位               */
    DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) = DMA_DSR_BCR_BCR(ulDMASize); /* 传输大小配置                 */

    DMA_DCR_REG(DMA_BASE_PTR, ucDMAn) =  (ucIntCon << 31)|              /* 中断配置                     */
                                         DMA_DCR_ERQ_MASK|              /* 外设请求配置                 */
                                         DMA_DCR_CS_MASK|               /* 单次传输                     */
                                         DMA_DCR_SINC_MASK|             /* 源地址自动增加               */
                                         DMA_DCR_SSIZE(1)|              /* 00-32bits 01-8bits 10-16bits */
                                         DMA_DCR_DSIZE(1);              /* 00-32bits 01-8bits 10-16bits */

    DMAMUX0_CHCFG(ucDMAn) = DMAMUX_CHCFG_SOURCE(ucDMAReSource);         /* 选择DMA请求源                */

    if (DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) & DMA_DSR_BCR_CE_MASK) {
        return 0;
    } else {
        DMAMUX0_CHCFG(ucDMAn) |= DMAMUX_CHCFG_ENBL_MASK;                /* DMAMUX使能                   */
        return 1;
    }
}

/*********************************************************************************************************
** Function name:           dmaInitPerToMem
** Descriptions:            dma 外设到内存初始化
** input parameters:        ucDMAn：          DMA通道号
**                          ucDMAReSource：   DMA请求源
**                          pulSrcAddress：   存储区源地址
**                          pulDestAddress：  存储区目标地址
**                          ulDMASize：       传输字节个数
**                          ucIntCon:         中断配置
** output parameters:       none
** Returned value:          配置成功：1 配置失败：0
** Created by:              Li Xiang
** Created date:            2012-05-14
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
uint_8  dmaInitPerToMem (uint_8  ucDMAn,
                        uint_8  ucDMAReSource,
                        void  *pulSrcAddress,
                        void  *pulDestAddress,
                       uint_32  ulDMASize,
                       uint_32  ucIntCon)
{
    SIM_SCGC7 |= SIM_SCGC7_DMA_MASK;                                    /* 时钟配置                     */
    SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;                                 /* 时钟配置                     */
    DMAMUX0_CHCFG(ucDMAn) = 0x00;                                       /* 禁能DMAMUX                   */
    DMA_SAR_REG(DMA_BASE_PTR, ucDMAn) = (uint_32)pulSrcAddress;          /* 源地址配置                   */
    DMA_DAR_REG(DMA_BASE_PTR, ucDMAn) = (uint_32)pulDestAddress;         /* 目的地址配置                 */

    DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) |= DMA_DSR_BCR_DONE_MASK;     /* 清除Done标志位               */
    DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) = DMA_DSR_BCR_BCR(ulDMASize); /* 传输大小配置                 */

    DMA_DCR_REG(DMA_BASE_PTR, ucDMAn) =  (ucIntCon << 31)|              /* 中断配置                     */
                                         DMA_DCR_ERQ_MASK|              /* 外设请求配置                 */
                                         DMA_DCR_CS_MASK|               /* 单次传输                     */
                                         DMA_DCR_DINC_MASK|             /* 目的地址自动增加             */
                                         DMA_DCR_SSIZE(2)|              /* 00-32bits 01-8bits 10-16bits */
                                         DMA_DCR_DSIZE(2);              /* 00-32bits 01-8bits 10-16bits */
    
    DMAMUX0_CHCFG(ucDMAn) = DMAMUX_CHCFG_SOURCE(ucDMAReSource);         /* 选择DMA请求源                */

    if (DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) & DMA_DSR_BCR_CE_MASK) {
        return 0;
    } else {
        DMAMUX0_CHCFG(ucDMAn) |= DMAMUX_CHCFG_ENBL_MASK;                /* DMAMUX使能                   */
        return 1;
    }
}

/*********************************************************************************************************
** Function name:           dmaStartTran
** Descriptions:            dma启动传输
** input parameters:        ucDMAn：          DMA通道号
** output parameters:       none
** Returned value:          none
** Created by:              Li Xiang
** Created date:            2012-05-14
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
void  dmaStartTran (uint_8  ucDMAn)
{
    DMA_DCR_REG(DMA_BASE_PTR, ucDMAn) |= (1 << 16);
}

/*********************************************************************************************************
** Function name:           dmaStatus
** Descriptions:            dma传输状态查询
** input parameters:        ucDMAn：          DMA通道号
** output parameters:       none
** Returned value:          DMA当前状态
** Created by:              Li Xiang
** Created date:            2012-05-14
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
*********************************************************************************************************/
uint_8  dmaStatus (uint_8  ucDMAn)
{
    if (DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) &
        (DMA_DSR_BCR_BES_MASK|DMA_DSR_BCR_BED_MASK|DMA_DSR_BCR_CE_MASK)) {
        return DMA_ERROR;
    }

    if (DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) & DMA_DSR_BCR_BSY_MASK ) {
        return DMA_BUSY;
    }

    if (DMA_DSR_BCR_REG(DMA_BASE_PTR, ucDMAn) & DMA_DSR_BCR_DONE_MASK ) {
        return DMA_DONE;
    }

    return DMA_ERROR;
}
/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
