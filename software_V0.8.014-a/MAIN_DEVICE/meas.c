/*
 * meas.c
 *
 * Created: 18.10.2013 12:20:42
 *  Author: vmk
 */

#include "meas.h"

//***************************************************************************************
//Оцифровка по указаному каналу
//***************************************************************************************
unsigned int read_adc(unsigned char adc_input)
{
	unsigned int ADC_RESULT;
	ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
	// Delay needed for the stabilization of the ADC input voltage
	_delay_us(200);
	// Start the AD conversion
	ADCSRA|=0x40;
	// Wait for the AD conversion to complete
	while ((ADCSRA & 0x10)==0);
	ADCSRA|=0x10;
	ADC_RESULT=ADCL;
	ADC_RESULT=ADC_RESULT+(ADCH<<8);
	return ADC_RESULT;
};
//***************************************************************************************
unsigned int rd_adc(unsigned char adc_input)
{
	unsigned int temp_adc = 0;
	//_delay_us(500);
	temp_adc=read_adc(adc_input);
	_delay_us(10);//_delay_us(50);
	temp_adc=temp_adc + read_adc(adc_input);
	_delay_us(10);//_delay_us(50);
	temp_adc=temp_adc + read_adc(adc_input);
	_delay_us(10);//_delay_us(50);
	temp_adc=temp_adc + read_adc(adc_input);
	temp_adc=temp_adc>>2;
	return temp_adc;
};
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************