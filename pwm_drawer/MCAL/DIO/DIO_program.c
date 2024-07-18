/*
 * DIO_program.c
 *
 * Created: 3/31/2024 10:01:50 PM
 *  Author:Ahmed Ali
 */ 




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"


void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	switch (copy_u8PortId)
	{
	case DIO_PORTA:
	switch(copy_u8PinDirection)
	{
		case DIO_PIN_INPUT:
		CLR_BIT(DDRA_REG, copy_u8PinId);
		break;
		
		case DIO_PIN_OUTPUT:
		SET_BIT(DDRA_REG, copy_u8PinId);
		break;
	}
	break;
	
	case DIO_PORTB:
	switch(copy_u8PinDirection)
	{
		case DIO_PIN_INPUT:
		CLR_BIT(DDRB_REG, copy_u8PinId);
		break;
		
		case DIO_PIN_OUTPUT:
		SET_BIT(DDRB_REG, copy_u8PinId);
		break;
	}
	break;
	
	case DIO_PORTC:
	switch(copy_u8PinDirection)
	{
		case DIO_PIN_INPUT:
		CLR_BIT(DDRC_REG, copy_u8PinId);
		break;
		
		case DIO_PIN_OUTPUT:
		SET_BIT(DDRC_REG, copy_u8PinId);
		break;
	}
	break;
	
	case DIO_PORTD:
	switch(copy_u8PinDirection)
	{
		case DIO_PIN_INPUT:
		CLR_BIT(DDRD_REG, copy_u8PinId);
		break;
		
		case DIO_PIN_OUTPUT:
		SET_BIT(DDRD_REG, copy_u8PinId);
		break;
	}
	break;
	}
}


void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8)&&((DIO_PIN_LOW==copy_u8PinValue)||(DIO_PIN_HIGH==copy_u8PinValue)))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTA_REG, copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTA_REG, copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTB:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTB_REG, copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTB_REG, copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTC:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTC_REG, copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTC_REG, copy_u8PinId);
				break;
			}
			break;
			
			case DIO_PORTD:
			switch(copy_u8PinValue)
			{
				case DIO_PIN_LOW:
				CLR_BIT(PORTD_REG, copy_u8PinId);
				break;
				
				case DIO_PIN_HIGH:
				SET_BIT(PORTD_REG, copy_u8PinId);
				break;
			}
			break;
		}
	}
	else
	{
		// return Error State
	}
}


void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8)&&(copy_pu8PinValue!=NULL))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			*copy_pu8PinValue = GET_BIT(PINA_REG, copy_u8PinId);
			break;
			
			case DIO_PORTB:
			*copy_pu8PinValue = GET_BIT(PINB_REG, copy_u8PinId);
			break;
			
			case DIO_PORTC:
			*copy_pu8PinValue = GET_BIT(PINC_REG, copy_u8PinId);
			break;
			
			case DIO_PORTD:
			*copy_pu8PinValue = GET_BIT(PIND_REG, copy_u8PinId);
			break;
		}
	}
	else
	{
		// return Error State
	}
}


void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA_REG, copy_u8PinId);
			break;
			
			case DIO_PORTB:
			TOG_BIT(PORTB_REG, copy_u8PinId);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC_REG, copy_u8PinId);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD_REG, copy_u8PinId);
			break;
		}
	}
	else
	{
		// return Error State
	}
}


void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	if((copy_u8PortId<4)&&(copy_u8PinId<8))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			SET_BIT(PORTA_REG, copy_u8PinId);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB_REG, copy_u8PinId);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC_REG, copy_u8PinId);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD_REG, copy_u8PinId);
			break;
		}
	}
	else
	{
		// return Error State
	}
}


// PORT APIS
void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	if((copy_u8PortId<4)&&((copy_u8PortDirection==DIO_PORT_OUTPUT)||(copy_u8PortDirection==DIO_PORT_INPUT)))
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_OUTPUT:
				DDRA_REG = 0xff;
				break;
				
				case DIO_PORT_INPUT:
				DDRA_REG = 0x00;
				break;
			}
			break;
			
			case DIO_PORTB:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_OUTPUT:
				DDRB_REG = 0xff;
				break;
				
				case DIO_PORT_INPUT:
				DDRB_REG = 0x00;
				break;
			}
			break;
			
			case DIO_PORTC:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_OUTPUT:
				DDRC_REG = 0xff;
				break;
				
				case DIO_PORT_INPUT:
				DDRC_REG = 0x00;
				break;
			}
			break;
			
			case DIO_PORTD:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_OUTPUT:
				DDRD_REG = 0xff;
				break;
				
				case DIO_PORT_INPUT:
				DDRD_REG = 0x00;
				break;
			}
			break;
		}
	}
	else
	{
		// return Error State
	}
}


void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	if(copy_u8PortId<4)
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			PORTA_REG = (~PORTA_REG); // PORTA^=0XFF;
			break;
			
			case DIO_PORTB:
			PORTB_REG = (~PORTB_REG); // PORTA^=0XFF;
			break;
			
			case DIO_PORTC:
			PORTC_REG = (~PORTC_REG); // PORTA^=0XFF;
			break;
			
			case DIO_PORTD:
			PORTD_REG = (~PORTD_REG); // PORTA^=0XFF;
			break;
		}
	}
	else
	{
		// return Error State
	}
}