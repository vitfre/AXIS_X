﻿/*
 * main.h
 *MAIN_DEVICE_V0.7.0011-a
 * Created: 11.02.2014 17:51:42
 *  Author: Администратор
 */ 


#ifndef LD_H_
#define LD_H_

#include <avr/io.h>

//---------------------------------------------------------------------------------------
#define F_CPU 16000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <avr/io.h>
//---------------------------------------------------------------------------------------
#include "bit_macros.h"
#include "init_mcu.h"
#include "buttons.h"
#include "usart_debug\buart_1.h"
#include "stepper.h"
#include "meas.h"
#include "menu.h"
#include "song.h"
#include "lcd.h"
//---------------------------------------------------------------------------------------

unsigned int cnt = 0;
//---------------------------------------------------------------------------------------
void(* resetFunc) (void) = 0; // Reset MC function
//---------------------------------------------------------------------------------------
void Func_reset(void)
{
	// Watchdog Timer initialization
	// Watchdog Timer Prescaler: OSC/16k
	WDTCR=0x08;
	while (1)
	{
	};
};
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
#endif /* LD_H_ */