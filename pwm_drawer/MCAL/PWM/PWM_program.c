/*
 * PWM_program.c
 *
 * Created: 5/10/2024 2:35:29 PM
 *  Author: Ahmed Ali
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "PWM_interface.h"
#include "PWM_config.h"
#include "PWM_private.h"
#include "PWM_register.h"


void PWM_voidInitChannel_0(void)
{
	SET_BIT(TCCR0_REG, WGM00);
	SET_BIT(TCCR0_REG, WGM01);

    // NON Inverting	
	CLR_BIT(TCCR0_REG, COM00);
	SET_BIT(TCCR0_REG, COM01);
}


void PWM_voidGenerate_PWM_Channel_0(u8 copy_u8DutyCycle)
{
	if(copy_u8DutyCycle<=100)
	{
		// NON Inverting
		OCR0_REG = (((u16)copy_u8DutyCycle*256)/100)-1;
		
		// Select Prescaler Value = 64
		SET_BIT(TCCR0_REG ,CS00);
		SET_BIT(TCCR0_REG ,CS01);
		CLR_BIT(TCCR0_REG ,CS02);
	}
	else
	{
		//return Error
	}
}


void PWM_voidInitChannel_1A(void)
{
	CLR_BIT(TCCR1A_REG, WGM10);
	SET_BIT(TCCR1A_REG, WGM11);
	SET_BIT(TCCR1B_REG, WGM12);
	SET_BIT(TCCR1B_REG, WGM13);
	
	CLR_BIT(TCCR1A_REG, COM1A0);
	SET_BIT(TCCR1A_REG, COM1A1);
}


void PWM_voidGenerate_PWM_Channel_1A(u16 copy_u16Frequency_hz, f32 copy_f32DutyCycle)
{
	if(copy_f32DutyCycle<=100.0)
	{
		// under condition tick time 4 MS by setting prescaller 64
		ICR1_u16_REG = ((1000000UL/copy_u16Frequency_hz)/4)-1;
		
		OCR1A_u16_REG = ((copy_f32DutyCycle*(ICR1_u16_REG+1))/100)-1;
		
		// select prescaller 64
		SET_BIT(TCCR1B_REG, CS10);
		SET_BIT(TCCR1B_REG, CS11);
		CLR_BIT(TCCR1B_REG, CS12);
	}
	else
	{
		//return Error State
	}
}