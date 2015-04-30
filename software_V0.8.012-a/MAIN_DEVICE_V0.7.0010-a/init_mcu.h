/*
 * init_mcu.h
 *
 * Created: 03.10.2013 16:10:53
 *  Author: vmk
 */

#ifndef INIT_MCU_H_
#define INIT_MCU_H_
//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
#define ADC_VREF_TYPE 0xC0
//---------------------------------------------------------------------------------------
#define _MOWER_EN	(PORTE|=(1<<1))		//
#define _MOWER_DIS	(PORTE&=~(1<<1))	//
#define _MOWER_ON	(PORTE|=(1<<3))		//
#define _MOWER_RES	(PORTE&=~(1<<3))	//
//---------------------------------------------------------------------------------------
#include <avr/io.h>
//***************************************************************************************
void init_mcu(void)
{
	/*
	// Input/Output Ports initialization
	// Port A initialization
	// Func7=In Func6=In Func5=In Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out
	// State7=T State6=T State5=T State4=0 State3=0 State2=0 State1=0 State0=0
	PORTA=0x00;
	DDRA=0x1F;

	// Port B initialization
	// Func7=Out Func6=Out Func5=Out Func4=Out Func3=In Func2=In Func1=In Func0=In
	// State7=0 State6=0 State5=0 State4=0 State3=T State2=T State1=T State0=T
	PORTB=0x00;
	DDRB=0xF0;

	// Port C initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
	// State7=T State6=T State5=T State4=P State3=P State2=P State1=P State0=P
	PORTC=0x1F;
	DDRC=0x00;

	// Port D initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=Out
	// State7=T State6=T State5=P State4=P State3=P State2=P State1=P State0=0
	PORTD=0x3E;
	DDRD=0x01;
*/
	// Port E initialization
	// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out
	// State7=1 State6=1 State5=1 State4=1 State3=0 State2=0 State1=0 State0=0
	PORTE=0xF0;
	DDRE=0xFF;
	_delay_ms(10);
	//_delay_ms(100);
	_MOWER_EN;
	_delay_ms(10);
	_MOWER_ON;
	
/*
	// Port F initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
	PORTF=0x00;
	DDRF=0x00;

	// Port G initialization
	// Func4=In Func3=In Func2=In Func1=In Func0=In
	// State4=T State3=T State2=T State1=T State0=T
	PORTG=0x00;
	DDRG=0x00;
	*/

	// Timer/Counter 0 initialization
	// Clock source: System Clock
	// Clock value: 250,000 kHz
	// Mode: Normal top=0xFF
	// OC0 output: Disconnected
	ASSR=0x00;
	TCCR0=0x04;
	TCNT0=0x00;
	OCR0=0x00;

	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: 62,500 kHz
	// Mode: Normal top=0xFFFF
	// OC1A output: Discon.
	// OC1B output: Discon.
	// OC1C output: Discon.
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer1 Overflow Interrupt: On
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	// Compare C Match Interrupt: Off
	TCCR1A=0x00;
	TCCR1B=0x04;
	TCNT1H=0x0B;
	TCNT1L=0xDC;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;
	OCR1CH=0x00;
	OCR1CL=0x00;

	// Timer/Counter 2 initialization
	// Clock source: System Clock
	// Clock value: Timer2 Stopped
	// Mode: Normal top=0xFF
	// OC2 output: Disconnected
	TCCR2=0x00;
	TCNT2=0x00;
	OCR2=0x00;

	// Timer/Counter 3 initialization
	// Clock source: System Clock
	// Clock value: Timer3 Stopped
	// Mode: Normal top=0xFFFF
	// OC3A output: Discon.
	// OC3B output: Discon.
	// OC3C output: Discon.
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer3 Overflow Interrupt: Off
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	// Compare C Match Interrupt: Off
	TCCR3A=0x00;
	TCCR3B=0x00;
	TCNT3H=0x00;
	TCNT3L=0x00;
	ICR3H=0x00;
	ICR3L=0x00;
	OCR3AH=0x00;
	OCR3AL=0x00;
	OCR3BH=0x00;
	OCR3BL=0x00;
	OCR3CH=0x00;
	OCR3CL=0x00;
	
	// External Interrupt(s) initialization
	// INT0: Off
	// INT1: Off
	// INT2: Off
	// INT3: Off
	// INT4: Off
	// INT5: Off
	// INT6: Off
	// INT7: Off
	EICRA=0x00;
	EICRB=0x00;
	EIMSK=0x00;

	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK=0x05;

	ETIMSK=0x00;

	// USART0 initialization
	// USART0 disabled
	UCSR0B=0x00;

	// USART1 initialization
	// USART1 disabled
	UCSR1B=0x00;

	// Analog Comparator initialization
	// Analog Comparator: Off
	// Analog Comparator Input Capture by Timer/Counter 1: Off
	ACSR=0x80;
	SFIOR=0x00;

	// ADC initialization
	// ADC Clock frequency: 250,000 kHz
	// ADC Voltage Reference: Internal 2.56V Voltage Reference with external capacitor at AREF pin
	ADMUX=ADC_VREF_TYPE & 0xff;
	ADCSRA=0x86;

	// SPI initialization
	// SPI disabled
	SPCR=0x00;

	// TWI initialization
	// TWI disabled
	TWCR=0x00;
	
};
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
#endif /* INIT_MCU_H_ */