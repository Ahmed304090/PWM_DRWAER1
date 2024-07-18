/*
 * lcd_program.c
 *
 * Created: 7/15/2024 3:21:27 PM
 *  Author: Ahmed Ali
 */ 

#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "PWM_interface.h"
#include "lcd_interface.h"
#include <string.h>
#include <stdio.h>  // Include standard I/O for sprintf
#include <stdint.h> // For standard integer types


void LCD_voidSendCommand(u8 copy_u8Cmnd) {
	LCD_DATA_PORT = copy_u8Cmnd;
	CLR_BIT(LCD_CTRL_PORT, RS); // RS = 0 for command 
	CLR_BIT(LCD_CTRL_PORT, RW); // RW = 0 for write 
	SET_BIT(LCD_CTRL_PORT, E);  // Enable pulse 
	_delay_us(1);
	CLR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(2); 
	
	
}

void LCD_voidDisplayChar(u8 copy_u8Data) {
	LCD_DATA_PORT = copy_u8Data;
	SET_BIT(LCD_CTRL_PORT, RS);  // RS = 1 for data 
	CLR_BIT(LCD_CTRL_PORT, RW);  // RW = 0 for write /
	SET_BIT(LCD_CTRL_PORT, E);   // Enable pulse /
	_delay_us(1);
	CLR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(2);
}




void LCD_voidInit(void) {
	LCD_DATA_DDR = 0xFF; /* Set data port as output */
	SET_BIT(LCD_CTRL_DDR, RS);
	SET_BIT(LCD_CTRL_DDR, RW);
	SET_BIT(LCD_CTRL_DDR, E);

	_delay_ms(20); /* Wait for LCD to power up */

	LCD_voidSendCommand(0x38); /* Function set: 8-bit mode, 2 lines, 5x8 dots */
	LCD_voidSendCommand(LCD_CMD_DISPLAY_CONTROL); /* Display on, cursor on, blink on */
	LCD_voidSendCommand(LCD_CMD_CLEAR_DISPLAY); /* Clear display */
	_delay_ms(2);
	LCD_voidSendCommand(LCD_CMD_ENTRY_MODE_SET); /* Entry mode set */
}

void LCD_voidClear(void) {
	LCD_voidSendCommand(LCD_CMD_CLEAR_DISPLAY);
	_delay_ms(2);
}
void LCD_voidClearLine(u8 copy_u8LineNumber) {
	u8 i;
	LCD_voidGoToSpecificPosition(copy_u8LineNumber, 0); /* Move to the start of the specified line */
	for (i = 0; i < 40; i++) { /* Assuming 40 characters per line */
		LCD_voidDisplayChar(' '); /* Clear each character by writing a space */
	}
	LCD_voidGoToSpecificPosition(copy_u8LineNumber, 0); /* Move back to the start of the line */
}
void LCD_voidDisplayString(u8* copy_pu8String) {
	while (*copy_pu8String) {
		LCD_voidDisplayChar(*copy_pu8String++);
	}
}

/*void LCD_voidDisplayNumber(u32 copy_u32Number) {
	char buffer[11]; // Buffer to hold the number as string 
	itoa(copy_u32Number, buffer, 10); // Convert number to string 
	LCD_voidDisplayString((u8*)buffer);
}*/
	


void LCD_voidDisplayNumber(uint32_t copy_u32Number) {
	char buffer[11]; /* Buffer to hold the number as string */
	sprintf(buffer, "%u", copy_u32Number); /* Convert number to string */
	LCD_voidDisplayString((uint8_t*)buffer);
}
void LCD_voidShift(u8 copy_u8ShifttingDirection) {
	if (copy_u8ShifttingDirection == 0) {
		LCD_voidSendCommand(LCD_CMD_CURSOR_SHIFT_LEFT);
		} else {
		LCD_voidSendCommand(LCD_CMD_CURSOR_SHIFT_RIGHT);
	}
}

void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position) {
	u8 address;
	switch (copy_u8LineNumber) {
		case 0:
		address = 0x00 + copy_u8Position;
		break;
		case 1:
		address = 0x40 + copy_u8Position;
		break;
		case 2:
		address = 0x14 + copy_u8Position;
		break;
		case 3:
		address = 0x54 + copy_u8Position;
		break;
		default:
		return; /* Invalid line number */
	}
	LCD_voidSendCommand(LCD_CMD_SET_CURSOR_POSITION | address);
}

void LCD_voidClearSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position) {
	LCD_voidGoToSpecificPosition(copy_u8LineNumber, copy_u8Position); /* Set cursor to the specific position */
	LCD_voidDisplayChar(' '); /* Display a space character to clear the position */
}

