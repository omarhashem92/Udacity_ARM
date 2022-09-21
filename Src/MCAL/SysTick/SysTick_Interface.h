/* File Header */
/********************************/
/* Author	:	Omar Hashem		*/
/* Date		:	16 Feb 2019		*/
/* Version	:	V0.2			*/
/********************************/
/* Header File Guard */
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void STK_voidInit(void);
void STK_voidStart(u32 Copy_u32Val);
void STK_voidStop(void);
void STK_voidSetCallBack(void (*Copy_ptr)(void));


#endif
