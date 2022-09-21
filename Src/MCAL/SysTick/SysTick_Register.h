/* File Header */
/********************************/
/* Author	:	Omar Hashem		*/
/* Date		:	15 Feb 2019		*/
/* Version	:	V0.1			*/
/********************************/
/* Header File Guard */
#ifndef SYSTICK_REGISTER_H
#define SYSTICK_REGISTER_H


typedef struct{

	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
	

}STKT_type;

#define STK      ((STKT_type *)0xE000E010)


#endif
