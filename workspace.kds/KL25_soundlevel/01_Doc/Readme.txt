
功能概要：简易声压计
版权所有：
版本更新：
硬件说明：PORTB19=红灯；PORTB18= 绿灯；PORTB9= 蓝灯；
        PORTE20=ADC0_DP0,PORTE21=ADC0_DM0；


1. 工程概述
声音信号由硅麦克风采集，放大40db，将声音信号输送给 KL25 ADC。KL25计算一帧均方根值，结果通过串口传输给电脑显示。
http://www.amobbs.com/thread-5611291-1-1.html

2. 软件环境
(1)Kinetis Design Studio IDE v2.0.0.

3. 硬件环境
(1)KL25 SD13-01 EVB板
(2)蓝灯对应引脚为PTB9
(3)串口1发送引脚为PTE0，接收引脚为PTE1
(4)PORTE20=ADC0_DP0,PORTE21=ADC0_DM0
	
4. 实验现象
(1)KL25 SD13-01 EVB板板上的蓝灯闪烁
(2)通过串口发送测量结果

5. 实验注意
(1)先打开串口，后开启KL25 SD13-01 EVB板电源


