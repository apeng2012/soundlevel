//===========================================================================
//文件名称：adc.c
//功能概要：ADC底层驱动构件源文件
//版权所有：苏州大学飞思卡尔嵌入式中心(sumcu.suda.edu.cn)
//更新记录：2013-4-7   V1.0
//===========================================================================
#include "adc.h"

//============================================================================
//函数名称：adc_init
//功能概要：初始化adc模块
//参数说明：diff配置模式：单端输入SINGLE_END
//                 差分输入DIFFERENTIAL
//       accurary采样精度:单端8-12-10-16；差分9-13-11-16
//       HardwareAverage硬件滤波：sample4/sample8/sample16/sample32
//============================================================================
void adc_init( uint_8 diff,uint_8 accurary,uint_8 HardwareAverage)
{
	uint_8 ADCCfg=0;

	//打开ADC0模块时钟
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	SIM_SOPT7 |= (SIM_SOPT7_ADC0ALTTRGEN_MASK
			| !SIM_SOPT7_ADC0PRETRGSEL_MASK
			| SIM_SOPT7_ADC0TRGSEL(4)) ; // PIT 0

	ADCCfg=ADC0_CFG1;
	switch(accurary)
	{
	case 8:
		ADCCfg = ADC_CFG1_MODE(0); 
		break;
	case 9:
		ADCCfg = ADC_CFG1_MODE(0); 
		break;
	case 12:
		ADCCfg = ADC_CFG1_MODE(1);
		break;
	case 13:
		ADCCfg = ADC_CFG1_MODE(1);
		break;
	case 10:
		ADCCfg = ADC_CFG1_MODE(2);
		break;
	case 11:
		ADCCfg = ADC_CFG1_MODE(2);
		break;
	case 16:
		ADCCfg = ADC_CFG1_MODE(3);
		break;
	default:
		ADCCfg = ADC_CFG1_MODE(0);		
	}
	
	//配置CFG1寄存器:正常功耗，总线时钟4分频，总线时钟/2，常采样时间
	ADCCfg |=  (ADC_CFG1_ADIV(2) | ADC_CFG1_ADICLK(1) | ADC_CFG1_ADLSMP_MASK);	
	ADC0_CFG1 = ADCCfg;
	
	//配置CFG2寄存器
    ADC0_CFG2 &= ~(ADC_CFG2_MUXSEL_MASK      //默认选择a通道
                 + ADC_CFG2_ADACKEN_MASK     //异步时钟输出禁止ֹ
                 + ADC_CFG2_ADHSC_MASK       //普通转换
                 + ADC_CFG2_ADLSTS_MASK);    //默认最长采样时间
	
    //配置ADC0_SC2：硬件触发，比较功能禁用；DMA禁用；默认外部参考电压 VREFH and VREFL
     ADC0_SC2 = ADC_SC2_ADTRG_MASK;
    
     ADC0_SC1A = ADC_SC1_ADCH(0);

    //选择差分输入或是单端输入
    if(DIFFERENTIAL == diff)
    	ADC0_SC1A |= (ADC_SC1_DIFF_MASK);
    else if(SINGLE_END == diff)
    	ADC0_SC1A &= ~(ADC_SC1_DIFF_MASK );
    //ADC模块中断
    ADC0_SC1A |= (ADC_SC1_AIEN_MASK);
}

//============================================================================
//函数名称：adc_read
//功能概要：初始化adc模块
//参数说明：channel：单端输入 通道范围 0~ 23
//               差分输入通道范围 0~ 3
//============================================================================

uint_16 adc_read(int channel)
{
	uint_16 ADCResult = 0;
	
	//设置SC1A寄存器通道号
	ADC0_SC1A = ADC_SC1_ADCH(channel);		
	
	//等待转换完成
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK));

	//读取转换结果
	ADCResult = (uint_16)ADC0_RA;
	//清ADC转换完成标志־
	ADC0_SC1A &= ~ADC_SC1_COCO_MASK;
	//返回读取结果
	return ADCResult;
}

//============================================================================
//函数名称：adc_cal
//功能概要：adc模块校正功能函数
//说明：在校正之前，须正确配置ADC时钟、采样时间、模式、硬件滤波32次，详见KL25芯片手册28.4.6
//============================================================================
uint_8 adc_cal()
{
	uint_8 cal_var;
  
  ADC0_SC2 &=  ~ADC_SC2_ADTRG_MASK ; // 使能软件触发
  ADC0_SC3 &= ( ~ADC_SC3_ADCO_MASK & ~ADC_SC3_AVGS_MASK ); //单次转换
  ADC0_SC3 |= ( ADC_SC3_AVGE_MASK | ADC_SC3_AVGS(SAMPLE32) );  //硬件平均滤波32次
  ADC0_SC3 |= ADC_SC3_CAL_MASK ;      //开始标定
  while (!(ADC0_SC1A & ADC_SC1_COCO_MASK)); // 等待标定结束
  	
  if (ADC0_SC3& ADC_SC3_CALF_MASK)
  {  
   return(1);    // 校正失败
  }
  
  // 计算正向输入校正
  cal_var = 0x00;
  cal_var =  ADC0_CLP0; 
  cal_var += ADC0_CLP1;
  cal_var += ADC0_CLP2;
  cal_var += ADC0_CLP3;
  cal_var += ADC0_CLP4;
  cal_var += ADC0_CLPS;

  cal_var = cal_var/2;
  cal_var |= 0x8000;   //Set MSB

  ADC0_PG = ADC_PG_PG(cal_var);
 
  // 计算负向输入校正
  cal_var = 0x00;
  cal_var =  ADC0_CLM0; 
  cal_var += ADC0_CLM1;
  cal_var += ADC0_CLM2;
  cal_var += ADC0_CLM3;
  cal_var += ADC0_CLM4;
  cal_var += ADC0_CLMS;

  cal_var = cal_var/2;

  cal_var |= 0x8000; // Set MSB

  ADC0_MG = ADC_MG_MG(cal_var); 
  
  ADC0_SC3 &= ~ADC_SC3_CAL_MASK ; //请CAL

  return(0);
}

void adc_enable_int(void) {
    enable_irq(ADC_IRQ_NO);   //开中断控制器IRQ中断
}
