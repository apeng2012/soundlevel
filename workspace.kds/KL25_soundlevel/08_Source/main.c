//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//============================================================================

#include "includes.h"  //包含总头文件
#include <math.h>

uint_16 ADCResult;
int_16 voice_buf[4000]; // 0.5s @ 8ksps

static void UART2PC_int16(uint16_t num) {
    uint8_t tmp;
    uint16_t tmp16;

    tmp = num/10000;
    uart_send1(UART_TEST, tmp+'0');

    tmp16 = num % 10000;
    tmp = tmp16 / 1000;
    uart_send1(UART_TEST, tmp+'0');

    tmp16 = num % 1000;
    tmp = tmp16 / 100;
    uart_send1(UART_TEST, tmp+'0');

    tmp = num % 100;
    tmp /= 10;
    uart_send1(UART_TEST, tmp+'0');

    tmp %= 10;
    uart_send1(UART_TEST, tmp+'0');
}

static void UART2PC_float(float num) {
    uint8_t tmp;
    uint16_t tmp16;
    uint16_t num16;

    num16 = (uint16_t)(num * 10.0);
    tmp = num16/1000;
    uart_send1(UART_TEST, tmp+'0');

    tmp16 = num16 % 1000;
    tmp = tmp16 / 100;
    uart_send1(UART_TEST, tmp+'0');

    tmp = num16 % 100;
    tmp /= 10;
    uart_send1(UART_TEST, tmp+'0');

    uart_send1(UART_TEST, '.');
    tmp %= 10;
    uart_send1(UART_TEST, tmp+'0');
}

static uint_16 calc_rms(void) {
	/*
	uint_32 sum[50];
	uint_32 i, j;
	int16_t *p = &voice_buf[0];
	int16_t tmp;

	for (i=0; i<50; i++) {
		sum[i] = 0;
		for (j=0; j<80; j++) {
			tmp = *p++;
			sum[i] += tmp * tmp;
		}
		sum[i] /= 80;
	}
	j = 0;
	for(i=0; i<50; i++) {
		j += sum[i];
	}
	j /= 50;

	return sqrt(j);
	*/

	unsigned long long sum = 0;
	uint_32 i;

	for (i=0; i<4000; i++) {
		sum += voice_buf[i] * voice_buf[i];
	}
	sum /= 4000;

	return sqrt((uint_32)sum);
}

#define A (0.001339)
#define B (-0.76712)

static float rms2spl(uint_16 rms) {
	/*
	float mic_mv, Pa;

	mic_mv = A*rms + B;
	Pa = mic_mv/7.943; // -42dBV/Pa @datasheet SPU0410

	return 20 * log(Pa/0.00002);
	*/

	uint_32 tmp;

	tmp = ((uint_32)rms) * 95;
	if (tmp < 2700) {
		return 0;
	} else {
		tmp = (tmp - 2700) >> 4;
	}

	return 20.0 * log10(tmp);
}

int main(void)
{
	//1. 声明主函数使用的变量
	uint_32  mRuncount;     //主循环计数器
	//2. 关总中断
	DISABLE_INTERRUPTS;
	//3. 初始化外设模块
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //初始化蓝色RUN灯
    uart_init (UART_TEST,BUSCLK,9600);     //串口1初始化, 总线时钟24000Khz,波特率9600
    adc_init(DIFFERENTIAL, 16, 0);       //ADC0初始化单端输入，16位采样精度
    dmaInitPerToMem (MKL_DMA1, 40, (void*)&ADC0_RA, voice_buf, 4000*2, 1);
//    uart_send_string(UART_TEST, "This is sound level Test!");
//    uart_send1(UART_TEST, '\n');
    pit_init(PIT0, 125); // 8kHz
    //4. 给有关变量赋初值
	mRuncount=0;            //主循环计数器
    ADCResult=0;
    //5. 使能模块中断
    uart_enable_re_int(UART_TEST);
    enable_irq(MKL_DMA1);
    //6. 开总中断
	ENABLE_INTERRUPTS;
    
	//进入主循环
	//主循环开始=============================================================
	for(;;)
	{
		mRuncount++;
		//循环计数到一定的值，使小灯的亮、暗状态切换
		if (mRuncount > RUN_COUNTER_MAX)
		{
			mRuncount = 0;
			//指示灯的亮、暗状态切换
		    light_change(RUN_LIGHT_BLUE);  //蓝色运行指示灯（RUN_LIGHT_BLUE）状态变化
		} // end_if

		if (ADCResult != 0) {
			ADCResult = calc_rms();
//			UART2PC_int16(ADCResult);
//			uart_send1(UART_TEST, '@');
			UART2PC_float(rms2spl(ADCResult));
			ADCResult = 0;
			uart_send1(UART_TEST, 'd');
			uart_send1(UART_TEST, 'B');
			uart_send1(UART_TEST, '\n');

			dmaInitPerToMem (MKL_DMA1, 40, (void*)&ADC0_RA, voice_buf, 4000*2, 1);
			PIT_TCTRL(PIT0)|=PIT_TCTRL_TEN_MASK;       //使能pit模块运行
		}
	}//主循环end_for
	//主循环结束==================================================================
	return 0;
}
