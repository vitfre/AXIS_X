﻿/*
 * main.h
 *
 * Created: 11.02.2014 17:51:42
 *  Author: Администратор
 */ 

#ifndef MAIN_H_
#define MAIN_H_
//---------------------------------------------------------------------------------------
#define F_CPU 8000000UL // or whatever may be your frequency
//---------------------------------------------------------------------------------------
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
//---------------------------------------------------------------------------------------
#include "init_mcu.h"
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#define CLK_OUT_ON		(PORTB|=(1<<3))		//
#define CLK_OUT_OFF		(PORTB&=~(1<<3))	//
#define CLK_OUT			(((PORTB)>>(3))&1)	//
//---------------------------------------------------------------------------------------
#define CS				(((PINB)>>(2))&1)   //
#define EN				(((PINB)>>(4))&1)   //
#define CLK				(((PINB)>>(1))&1)   //
#define S_DATA_IN		(((PINB)>>(0))&1)   //
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#endif /* MAIN_H_ */