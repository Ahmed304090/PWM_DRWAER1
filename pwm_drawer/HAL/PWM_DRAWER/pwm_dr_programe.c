/*
 * pwm_dr_programe.c
 *
 * Created: 7/17/2024 1:43:28 PM
 *  Author: Ahmed Ali
 */ 



#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "PWM_interface.h"
#include "PWM_register.h"
#include "lcd_interface.h"
#include "pwm_dr_interface.h"


#include <string.h>
#include <stdio.h>  // Include standard I/O for sprintf
#include <stdint.h> // For standard integer types

void PWM_DRAWER_voidStart(){
	
	
	
	LCD_voidInit();

	// Clear the display
	LCD_voidClear();
	LCD_voidGoToSpecificPosition(0,0);
	LCD_voidDisplayString("welcome to my");
	LCD_voidGoToSpecificPosition(1,0);
	LCD_voidDisplayString("graduation project");
	LCD_voidGoToSpecificPosition(2,8);
	LCD_voidDisplayString("with");
	
	LCD_voidGoToSpecificPosition(3,0);
	LCD_voidDisplayString("--------AMIT--------");
	
	
	_delay_ms(4000);
	LCD_voidClear();
	
	
	LCD_voidGoToSpecificPosition(1,0);
	LCD_voidDisplayString("-----PWM_DRAWER-----");
	
	LCD_voidDisplayString("BY: AHMED ALI");
	_delay_ms(4000);
	LCD_voidClear();
	
	
	
}


void LCD_voidScrollPattern100(u8 freq1) {
	char pattern[] = "---------";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time1=1000/freq1;
	
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time1);
	LCD_voidDisplayString("ms");

	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		
		
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}

void LCD_voidScrollPattern90  (u8 freq2){
	char pattern[] = "---------|_|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time2=1000/freq2;
	u8 Ton=(time2*9)/10;
	u8 Toff=time2-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time2);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}
void LCD_voidScrollPattern80  (u8 freq3){
	char pattern[] = "--------|__|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time3=1000/freq3;
	u8 Ton=(time3*8)/10;
	u8 Toff=time3-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time3);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}

void LCD_voidScrollPattern75(u8 freq4){
	char pattern[] = "------|__|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time4=1000/freq4;
	u8 Ton=(time4*3)/4;
	u8 Toff=time4-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time4);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
	
	
	
	
}

void LCD_voidScrollPattern70  (u8 freq5){
	char pattern[] = "-------|___|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time5=1000/freq5;
	
	u8 Ton=(time5*7)/10;
	u8 Toff=time5-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time5);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}
void LCD_voidScrollPattern60  (u8 freq6){
	char pattern[] = "------|____|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time6=1000/freq6;
	
	u8 Ton=(time6*6)/10;
	u8 Toff=time6-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time6);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}

void LCD_voidScrollPattern50(u8 freq7){
	
	
	char pattern[] = "-----|_____|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
    u8 time7=1000/freq7;

u8 Ton=(time7*5)/10;
u8 Toff=time7-Ton;
LCD_voidGoToSpecificPosition(2,0);
LCD_voidDisplayString("Ton= ");
LCD_voidDisplayNumber(Ton);
LCD_voidDisplayString("ms");
LCD_voidGoToSpecificPosition(2,9);
LCD_voidDisplayString(" Toff= ");
LCD_voidDisplayNumber(Toff);

LCD_voidDisplayString("ms");
LCD_voidGoToSpecificPosition(1,9);
LCD_voidDisplayString("time = ");
LCD_voidDisplayNumber(time7);
LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
	
	
}

void LCD_voidScrollPattern40  (u8 freq8){
	char pattern[] = "----|______|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time8=1000/freq8;
	
	u8 Ton=(time8*4)/10;
	u8 Toff=time8-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time8);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}
void LCD_voidScrollPattern30  (u8 freq9){
	char pattern[] = "---|_______|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time9=1000/freq9;
	
	u8 Ton=(time9*3)/10;
	u8 Toff=time9-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time9);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}


void LCD_voidScrollPattern25(u8 freq10){
	
	
	
	char pattern[] = "--|______|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
    u8 time10=1000/freq10;
    
    u8 Ton=(time10*1)/4;
    u8 Toff=time10-Ton;
LCD_voidGoToSpecificPosition(2,0);
LCD_voidDisplayString("Ton= ");
LCD_voidDisplayNumber(Ton);
LCD_voidDisplayString("ms");
LCD_voidGoToSpecificPosition(2,9);
LCD_voidDisplayString(" Toff= ");
LCD_voidDisplayNumber(Toff);
LCD_voidDisplayString("ms");
LCD_voidGoToSpecificPosition(1,9);
LCD_voidDisplayString("time = ");
LCD_voidDisplayNumber(time10);
LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
	
	
}
void LCD_voidScrollPattern20  (u8 freq11){
	char pattern[] = "--|________|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time11=1000/freq11;
	
	u8 Ton=(time11*2)/10;
	u8 Toff=time11-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time11);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
}
void LCD_voidScrollPattern10  (u8 freq12){
	char pattern[] = "-|_________|";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
	u8 time12=1000/freq12;
	
	u8 Ton=(time12*1)/10;
	u8 Toff=time12-Ton;
	LCD_voidGoToSpecificPosition(2,0);
	LCD_voidDisplayString("Ton= ");
	LCD_voidDisplayNumber(Ton);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(2,9);
	LCD_voidDisplayString(" Toff= ");
	LCD_voidDisplayNumber(Toff);
	LCD_voidDisplayString("ms");
	LCD_voidGoToSpecificPosition(1,9);
	LCD_voidDisplayString("time = ");
	LCD_voidDisplayNumber(time12);
	LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
	
}

void LCD_voidScrollPattern0(u8 freq13){
	
	
	
	char pattern[] = "________";
	char display[21]; // Buffer to hold the current display string (for 20x4 LCD)
	u8 length = strlen(pattern);
	u8 pos = 0;
u8 time13=1000/freq13;
LCD_voidGoToSpecificPosition(2,0);
LCD_voidDisplayString("time = ");
LCD_voidDisplayNumber(time13);
LCD_voidDisplayString("ms");
	while (1) {
		for (u8 i = 0; i < 20; i++) {
			display[i] = pattern[(pos + i) % length];
		}
		display[20] = '\0'; // Null-terminate the string

		LCD_voidGoToSpecificPosition(3, 0); // Set cursor to the first line
		LCD_voidDisplayString(display); // Display the current pattern
		_delay_ms(300); // Delay for visible scrolling effect

		pos = (pos + 1) % length; // Increment position
	}
	
	
}

void PWM_DRAWER_voidDISPLAY(u8 frequency,u8 dutyy){
	

	
	switch(dutyy){
		
		case 100:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern100(frequency);
		
		
		
		break;
		case 90:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern90(frequency);
		
		break;
		
		case 80:
		
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern80(frequency);
		
		break;
		case 75:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern75(frequency);
		
		
	
		break;
		
		case 70:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern70(frequency);
		
		break;
		
		
		case 60:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern60(frequency);
		
		break;
		
		
		case 50:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		
		
		
		LCD_voidScrollPattern50(frequency);
		break;
		
		case 40:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern40(frequency);
		
		break;
		case 30:
		
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern30(frequency);
		
		break;
		
		case 25:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern25(frequency);
		
		
	
		break;
		
		case 20:
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern20(frequency);
		
		
		break;
		
		
		case 10:
		
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern10(frequency);
		
		break;
		
		case 0:
		
		DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT); // OC1A
		PWM_voidInitChannel_1A();
		PWM_voidGenerate_PWM_Channel_1A(frequency,dutyy); //0
		
		
		LCD_voidInit();

		// Clear the display
		LCD_voidClear();
		
		
		LCD_voidGoToSpecificPosition(0,0);
		LCD_voidDisplayString("freq=");
		LCD_voidDisplayNumber(frequency);
		LCD_voidDisplayString("HZ");
		LCD_voidGoToSpecificPosition(1,0);
		LCD_voidDisplayString("duty=");
		LCD_voidDisplayNumber(dutyy);
		LCD_voidDisplayString("%");
		LCD_voidGoToSpecificPosition(3,0);
		LCD_voidScrollPattern0(frequency);
		
		
		
		break;
	}
	
	
	
	
	
	
	
}


