/*
 * lcd_config.h
 *
 * Created: 7/15/2024 3:22:08 PM
 *  Author: Ahmed Ali
 */ 

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"


#define F_CPU 16000000UL  /* Define CPU frequency */
#include <util/delay.h>

#define LCD_DATA_PORT PORTB_REG
#define LCD_DATA_DDR  DDRB_REG

#define LCD_D0_PIN    DIO_PIN0
#define LCD_D1_PIN    DIO_PIN1
#define LCD_D2_PIN    DIO_PIN2
#define LCD_D3_PIN    DIO_PIN3
#define LCD_D4_PIN    DIO_PIN4
#define LCD_D5_PIN    DIO_PIN5
#define LCD_D6_PIN    DIO_PIN6
#define LCD_D7_PIN    DIO_PIN7

#define LCD_CTRL_PORT PORTC_REG
#define LCD_CTRL_DDR  DDRC_REG
#define RS DIO_PIN0
#define RW DIO_PIN1
#define E  DIO_PIN2

#define LCD_CMD_CLEAR_DISPLAY       0x01
#define LCD_CMD_RETURN_HOME         0x02
#define LCD_CMD_ENTRY_MODE_SET      0x06
#define LCD_CMD_DISPLAY_CONTROL     0x0F
#define LCD_CMD_CURSOR_SHIFT_LEFT   0x10
#define LCD_CMD_CURSOR_SHIFT_RIGHT  0x14
#define LCD_CMD_SET_CURSOR_POSITION 0x80

#endif /* LCD_CONFIG_H */
