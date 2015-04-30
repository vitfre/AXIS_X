/*
 * buttons.h
 *
 * Created: 03.10.2013 16:04:14
 *  Author: vmk
 */ 

#ifndef	BUTTONS_H_
#define	BUTTONS_H_
//---------------------------------------------------------------------------------------
//#define norm
#define lin
//---------------------------------------------------------------------------------------
#include <avr/io.h>
//---------------------------------------------------------------------------------------
#include "bit_macros.h"
//---------------------------------------------------------------------------------------
#define MASK_BUTTONS 			(1<<speed_1_increment)|(1<<speed_1_decrement)|(1<<OK)|(1<<speed_2_increment)|(1<<speed_2_decrement)|(1<<length_increment)

#define MASK_BUTTONS_2			(1<<length_decrement)
//---------------------------------------------------------------------------------------
//����, � �������� ���������� ������
#define PORT_BUTTON 			PORTC
#define PIN_BUTTON 				PINC
#define DDRX_BUTTON 			DDRC

#define PORT_BUTTON_2 			PORTA
#define PIN_BUTTON_2 			PINA
#define DDRX_BUTTON_2 			DDRA
//---------------------------------------------------------------------------------------
//������ �������, � ������� ���������� ������
#define speed_1_increment		0UL
#define speed_1_decrement 		1UL
#define OK						2UL
#define speed_2_increment 		3UL
#define speed_2_decrement 		4UL
#define length_increment		5UL
#define length_decrement		1UL
//---------------------------------------------------------------------------------------
//����, ������� ����� ������������ � �����
#define KEY_NULL      			0UL
#define KEY_OK					1UL
#define KEY_CANCEL     			2UL
#define KEY_EXIT	   			3UL
#define KEY_RIGHT      			4UL
#define KEY_LEFT      			5UL
#define KEY_SIX      			6UL
#define KEY_SEVEN      			7UL
//---------------------------------------------------------------------------------------
//������� ������ ������ ������ ������ ������������
#define THRESHOLD				20UL
#define THRESHOLD2				250UL
//---------------------------------------------------------------------------------------
volatile unsigned char pressedKey = 0;
unsigned char comp = 0;
/**************************************************************************
*   Function name : BUT_Init
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ������������� ������ �����/������
*                   ���������� ������ � ������ main`a
****************************************************************************/
void BUT_Init(void)
{
	DDRX_BUTTON &= ~(MASK_BUTTONS);
	PORT_BUTTON |= MASK_BUTTONS;
	
	DDRX_BUTTON_2 &= ~(MASK_BUTTONS_2);
	PORT_BUTTON_2 |= MASK_BUTTONS_2;
};
/**************************************************************************
*   Function name : BUT_Debrief
*   Returns :       ���
*   Parameters :    ���
*   Purpose :       ���������� ������. ���������� ������ �� ����������
*                   ���� ������ ������ � ������� 20 ����������,
*                   �� ����� ������������ � �����
****************************************************************************/
void BUT_Debrief(void)
{
	unsigned char key;

	//���������������� ����� ������� ��
	if (BitVal(PIN_BUTTON, speed_1_increment)==0)
	key = KEY_OK;
	else if (BitVal(PIN_BUTTON, speed_1_decrement)==0)
	key = KEY_CANCEL;
	else if (BitVal(PIN_BUTTON, OK)==0)
	key = KEY_EXIT;
	else if (BitVal(PIN_BUTTON, speed_2_increment)==0)
	key = KEY_RIGHT;
	else if (BitVal(PIN_BUTTON, speed_2_decrement)==0)
	key = KEY_LEFT;
	else if (BitVal(PIN_BUTTON, length_increment)==0)
	key = KEY_SIX;
	else if (BitVal(PIN_BUTTON_2, length_decrement)==0)
	key = KEY_SEVEN;
	else {
		key = KEY_NULL;
	};
	
	
	#ifdef norm
		//---------------------------------------------------------------------------------------
		//���� �� ��������� ���������� ���-�� ����
		if (key!=0)
		{
			//� ���� ������ ������������ �����
			//�������� �� ����� � �����
			if (comp == THRESHOLD)
			{
				comp = THRESHOLD+10;
				pressedKey = key;
				return;
			}
			else if (comp < (THRESHOLD+5))
			{
				comp++;
			};
		}
		else
		{
			comp=0;
		};
		//---------------------------------------------------------------------------------------
	#endif
	#ifdef lin
		//---------------------------------------------------------------------------------------
		//���� �� ��������� ���������� ���-�� ����
		if (key!=0)
		{
			//� ���� ������ ������������ ����� �����
			//�� ����� ����� �� ����� � �����
			if (comp > THRESHOLD2)
			{
				comp = THRESHOLD2 - 40;
				pressedKey = key;
				return;
			}
			else
			{
				comp++;
			};
			//� ���� ������ ������������ �����
			//�������� �� ����� � �����
			if (comp == THRESHOLD)
			{
				pressedKey = key;
				return;
			};
		}
		else
		{
			comp=0;
		};
		//---------------------------------------------------------------------------------------
	#endif
};
/**************************************************************************
*   Function name : BUT_GetKey
*   Returns :       ����� ������� ������
*   Parameters :    ���
*   Purpose :       ���������� ���������� ���������� ������
*                   ��� ���� ����� ���������
*                   ���������� ������ � main`e � ����� while
*
****************************************************************************/
unsigned char BUT_GetKey(void)
{
	unsigned char key = pressedKey;
	pressedKey = KEY_NULL;
	return key;
};
/**************************************************************************
*   Function name : BUT_SetKey
*   Returns :       ���
*   Parameters :    ����� ������
*   Purpose :       ���������� � ��������� ����� ��������
*                   ��������� ������ ��� �������� ������� ������
****************************************************************************/
void BUT_SetKey(unsigned char key)
{
	pressedKey = key;
};
#endif //BUTTONS_H_
