/*
 * lcd_interface.h
 *
 * Created: 7/15/2024 3:21:46 PM
 *  Author: Ahmed Ali
 */ 


#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include "STD_TYPES.h"
#include "lcd_config.h"


void LCD_voidInit(void);
void LCD_voidSendCommand(u8 copy_u8Cmnd);
void LCD_voidDisplayChar(u8 copy_u8Data);
void LCD_voidDisplayString(u8* copy_pu8String);
void LCD_voidClear(void);
void LCD_voidClearLine(u8 copy_u8LineNumber);
void LCD_voidDisplayNumber(u32 copy_u32Number);
void LCD_voidShift(u8 copy_u8ShifttingDirection);
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position);
void LCD_voidClearSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position) ;

#endif /* LCD_INTERFACE_H */
