/*
 * init_mcu.h
 *
 * Created: 03.10.2013 16:10:53
 *  Author: vmk
 */

#ifndef INIT_MCU_H_
#define INIT_MCU_H_
//---------------------------------------------------------------------------------------
#define F_CPU 8000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/io.h>
//***************************************************************************************
static void init_periphery (void)
{
	//---------------------------------------------------------------------------------------
	// Crystal Oscillator division factor: 1
	//#pragma optsize-
	CLKPR=0x80;
	CLKPR=0x00;
	//#ifdef _OPTIMIZE_SIZE_
	//#pragma optsize+
	//#endif
	//---------------------------------------------------------------------------------------
	// Input/Output Ports initialization
	// Port B initialization
	// Func5=Out Func4=Out Func3=Out Func2=In Func1=In Func0=In
	// State5=0 State4=0 State3=0 State2=P State1=P State0=P
	PORTB=0x07;
	DDRB=0x38;

	// Timer/Counter 0 initialization
	// Clock source: System Clock
	// Clock value: Timer 0 Stopped
	// Mode: Normal top=0xFF
	// OC0A output: Disconnected
	// OC0B output: Disconnected
	TCCR0A=0x00;
	TCCR0B=0x00;
	TCNT0=0x00;
	OCR0A=0x00;
	OCR0B=0x00;

	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: Timer1 Stopped
	// Mode: Normal top=0xFF
	// OC1A output: Disconnected
	// OC1B output: Disconnected
	// Timer1 Overflow Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	PLLCSR=0x00;

	TCCR1=0x00;
	GTCCR=0x00;
	TCNT1=0x00;
	OCR1A=0x00;
	OCR1B=0x00;
	OCR1C=0x00;

	// External Interrupt(s) initialization
	// INT0: On
	// INT0 Mode: Falling Edge
	// Interrupt on any change on pins PCINT0-5: Off
	GIMSK=0x40;
	MCUCR=0x02;
	GIFR=0x40;

	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK=0x00;

	// Universal Serial Interface initialization
	// Mode: Disabled
	// Clock source: Register & Counter=no clk.
	// USI Counter Overflow Interrupt: Off
	USICR=0x00;

	// Analog Comparator initialization
	// Analog Comparator: Off
	ACSR=0x80;
	ADCSRB=0x00;
	DIDR0=0x00;

	// ADC initialization
	// ADC disabled
	ADCSRA=0x00;

	_delay_ms(100);													//Settle pause
};
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
#endif /* INIT_MCU_H_ */