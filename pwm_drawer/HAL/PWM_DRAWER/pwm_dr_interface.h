/*
 * pwm_dr_interface.h
 *
 * Created: 7/17/2024 1:43:12 PM
 *  Author: Ahmed Ali
 */ 


#ifndef PWM_DR_INTERFACE_H_
#define PWM_DR_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "PWM_interface.h"
#include "PWM_register.h"
#include "lcd_interface.h"

void PWM_DRAWER_voidStart     ();
void PWM_DRAWER_voidDISPLAY   (u8 frequency,u8 dutyy);
void LCD_voidScrollPattern100 (u8 freq1);
void LCD_voidScrollPattern90  (u8 freq2);
void LCD_voidScrollPattern80  (u8 freq3);
void LCD_voidScrollPattern75  (u8 freq4);
void LCD_voidScrollPattern70  (u8 freq5);
void LCD_voidScrollPattern60  (u8 freq6);
void LCD_voidScrollPattern50  (u8 freq7);
void LCD_voidScrollPattern40  (u8 freq8);
void LCD_voidScrollPattern30  (u8 freq9);
void LCD_voidScrollPattern25  (u8 freq10);
void LCD_voidScrollPattern20  (u8 freq11);
void LCD_voidScrollPattern10  (u8 freq12);
void LCD_voidScrollPattern0   (u8 freq13);








#endif /* PWM_DR_INTERFACE_H_ */