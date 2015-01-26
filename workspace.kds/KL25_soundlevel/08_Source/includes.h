//============================================================================
//�ļ���ƣ�includes.h
//���ܸ�Ҫ��Ӧ�ù�����ͷ�ļ�
//��Ȩ���У����ݴ�ѧ��˼����Ƕ��ʽ����(sumcu.suda.edu.cn)
//�汾���£�2012-11-12  V2.0
//============================================================================

#ifndef _INCLUDES_H
#define _INCLUDES_H

#include "common.h"
#include "gpio.h"
#include "light.h"
#include "uart.h"
#include "adc.h"
#include "sysinit.h"

//����ȫ�ֱ���
//����ϵͳʱ�ӡ�����ʱ��
#define  core_clk_khz      48000   //оƬ�ں�ʱ��Ƶ�ʣ�kHz
#define  bus_clk_khz       24000   //оƬ����ʱ��Ƶ�ʣ�Khz

//����С����˸Ƶ��
#define RUN_COUNTER_MAX   1500000ul 

//����ʹ�õĵ��Ժ�
#define UART_TEST UART_1
#define TEST_UART_BAUDRATE   9600UL

// ADC0 ch0 connect mic
#define MIC_CH (0)

#endif
