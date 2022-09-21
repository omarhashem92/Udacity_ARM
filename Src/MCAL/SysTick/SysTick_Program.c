/* File Header */
/********************************/
/* Author	:	Omar Hashem		*/
/* Date		:	16 Feb 2019		*/
/* Version	:	V0.2			*/
/********************************/

#include "../../common/Std_Types.h"
#include "../../common/Macros.h"
#include "SysTick_Interface.h"
#include "SysTick_Register.h"
void (*STK_CallBack)(void)= 0 ;
/*
void STK_voidInit(void)
{
	STK->CTRL = 0x00000003;
	STK->VAL = 1000000;
	STK->LOAD = 1000000;
}
*/
void STK_voidInit(void)
{
 /* choose clock to be AHB/8  */
	STK->CTRL = 0;
}
void STK_voidStart(u32 Copy_u32Val)
{

	STK->VAL  = Copy_u32Val;
	STK->LOAD = Copy_u32Val;
	STK->CTRL |= 3;
}
void STK_voidStop(void)
{
	STK->CTRL &= 0xFFFFFFFC;
}
void STK_voidSetCallBack(void (*Copy_ptr)(void))
{
	STK_CallBack=Copy_ptr;
}


void SysTick_Handler(void)
{
	STK_CallBack();
	/*
	static u8 Local_u8flag = 0;
	if( Local_u8flag == 0)
	{
		DIO_voidSetPinVal(DIO_u8_PORTC , DIO_u32_PIN13 , GPIO_u8LOW);
		Local_u8flag = 1;
	}
	
	else if(Local_u8flag == 1 )
	{
		DIO_voidSetPinVal(DIO_u8_PORTC , DIO_u32_PIN13 , GPIO_u8HIGH);
		Local_u8flag = 0;
	}
	*/
}
