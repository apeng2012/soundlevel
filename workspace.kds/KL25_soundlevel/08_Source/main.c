//说明见工程文件夹下的Doc文件夹内Readme.txt文件
//============================================================================

#include "includes.h"  //包含总头文件


int main(void)
{
	//1. 声明主函数使用的变量
	uint_32  mRuncount;     //主循环计数器
	uint_16 ADCResult;
	//2. 关总中断
	DISABLE_INTERRUPTS;
	//3. 初始化外设模块
	light_init(RUN_LIGHT_BLUE,LIGHT_OFF);     //初始化蓝色RUN灯
    uart_init (UART_TEST,BUSCLK,9600);     //串口1初始化, 总线时钟24000Khz,波特率9600
    adc_init(SINGLE_END,10,SAMPLE32);       //ADC0初始化单端输入，10位采样精度，32次硬件均值
    uart_send_string(UART_TEST, "This is sound level Test!");
    uart_send1(UART_TEST, '\n');
    //4. 给有关变量赋初值
	mRuncount=0;            //主循环计数器
    ADCResult=0;
    //5. 使能模块中断
    uart_enable_re_int(UART_TEST);
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
		    //进行一次模块0通道采样
			ADCResult = adc_read(MIC_CH);
			//将采集的A/D值通过串口发送到PC
			uart_send1 (UART_TEST ,(uint_8)(ADCResult>>8));
			uart_send1 (UART_TEST ,ADCResult);
		} // end_if
	}//主循环end_for
	//主循环结束==================================================================
	return 0;
}
