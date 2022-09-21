/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../common/Std_Types.h"
#include "../../common/Macros.h"
#include "../Includes/Timer.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void (*GPT_TIM0_CallBack)(void)= 0 ;


#define GPT_ACTIVATED_CHANNELS_SIZE 2



//const Gpt_ConfigType Gpt_Config[GPT_ACTIVATED_CHANNELS_SIZE] =
//{
/* channel channelTickFreq            channelTickMaxValue                channelMode gptNotification */
//{0, 500, 0xFF,        1, 1},
//{1,        1000,    0xFFFF,            1,          0}
//};

#define   Timer_3       0x40033000      //Base address of timer 3

#define   RCGC          0x400FE000      //Base address of RCGC.
#define RCGC_T          0x604   //Offset of timer.
#define   Timer_0       0x40030000
#define   Timer_1       0x40031000
#define   Timer_2       0x40032000
#define   Timer_3       0x40033000
#define   Timer_4       0x40034000
#define   Timer_5       0x40035000
#define RCGC_T 0x604 //Offset of timer.
#define GPTMCFG 0x000 //GPTM Configuration
#define GPTMTAMR 0x004 //GPTM Timer A Mode
#define GPTMTBMR 0x008 //GPTM Timer B Mode
#define GPTMCTL 0x00C //GPTM Control
#define GPTMSYNC 0x010 //GPTM Synchronize
#define GPTMIMR 0x018 //GPTM Interrupt Mask
#define GPTMRIS 0x01C //GPTM Raw Interrupt Status
#define GPTMMIS 0x020 //GPTM Masked Interrupt Status
#define GPTMICR 0x024 //GPTM Interrupt Clear
#define GPTMTAILR 0x028 //GPTM Timer A Interval Load
#define GPTMTBILR 0x02C //GPTM Timer B Interval Load
#define GPTMTAMATCHR 0x030 //GPTM Timer A Match
#define GPTMTBMATCHR 0x034 //GPTM Timer B Match
#define GPTMTAPR 0x038 //GPTM Timer A PRESCALER
#define GPTMTBPR 0x03C //GPTM Timer B PRESCALER
#define GPTMTAPMR 0x040 //GPTM TimerA PRESCALER Match
#define GPTMTBPMR 0x044 //GPTM TimerB PRESCALER Match
#define GPTMTAR 0x048 //GPTM Timer A
#define GPTMTBR 0x04C //GPTM Timer B
#define GPTMTAV 0x050 //GPTM Timer A Value
#define GPTMTBV 0x054 //GPTM Timer B Value
#define GPTMRTCPD 0x058 //GPTM RTC PreDivide
#define GPTMTAPS 0x05C //GPTM Timer A PRESCALER Snapshot
#define GPTMTBPS 0x060 //GPTM Timer B PRESCALER Snapshot
#define GPTMTAPV 0x064 //GPTM Timer A PRESCALER Value
#define GPTMTBPV 0x068 //GPTM Timer B PRESCALER Value
#define GPTMPP 0xFC0 //GPTM Peripheral Properties

#define Timer_RCGC       (*((volatile u32*)(RCGC + RCGC_T)))

#define Timer1_GPTMCFG   (*((volatile u32*)(Timer_1 + GPTMCFG)))
#define Timer1_GPTMCTL   (*((volatile u32*)(Timer_1 + GPTMCTL)))
#define Timer1_GPTMTAMR  (*((volatile u32*)(Timer_1 + GPTMTAMR)))
#define Timer1_GPTMTAILR (*((volatile u32*)(Timer_1 + GPTMTAILR)))
#define Timer1_GPTMRIS   (*((volatile u32*)(Timer_1 + GPTMRIS)))
#define Timer1_GPTMICR   (*((volatile u32*)(Timer_1 + GPTMICR)))
#define Timer1_GPTMIMR   (*((volatile u32*)(Timer_1 + GPTMIMR)))
#define Timer1_GPTMTAPR   (*((volatile u32*)(Timer_1 + GPTMTAPR)))
#define Timer1_GPTMMIS   (*((volatile u32*)(Timer_1 + GPTMMIS)))




#define NVIC_ISER       (((u32*)0xE000E100))
#define NVIC_ISER_PEN       (((u32*)0xE000E200))




void Gpt_Init( const Gpt_ConfigType* ConfigPtr)
{

u8 i;
for(i=0;i<GPT_ACTIVATED_CHANNELS_SIZE;i++)
{
 //GPTMCFG_0 =

}





}









/*
void _delay_s(u32 Sec){
    u32 i;
    Timer_RCGC      |= (1 << 3);
    Timer3_GPTMCTL   = 0;                 //Disable timer for configuration.
    Timer3_GPTMCFG   = 0x04;               //Set 16-bit Mode.
    Timer3_GPTMTAMR = 0x02;               //Periodic mode Mode.
    Timer3_GPTMTAILR = (16000000  - 1); //16 (PIOC in RCGC2 register provides 16MHz)
    Timer3_GPTMICR |= 0x1;
    Timer3_GPTMCTL  |= 0x01;

    for (i=0;i<Sec;i++){
        while((Timer3_GPTMRIS & 0x1) == 0);
        Timer3_GPTMICR = 0x1;
    }
}
*/
/*
void _delay_s(u32 Sec){
    u32 i;
    Timer_RCGC      |= (1 << 0);
    Timer_RCGC      |= (1 << 1);
    Timer_RCGC      |= (1 << 2);
    Timer_RCGC      |= (1 << 3);
    Timer3_GPTMCTL   = 0;                 //Disable timer for configuration.
    Timer3_GPTMCFG   = 0x04;               //Set 16-bit Mode.
    Timer3_GPTMTAMR = 0x02;               //Periodic mode Mode.
    Timer3_GPTMTAILR = (16000000  - 1); //16 (PIOC in RCGC2 register provides 16MHz)
    Timer3_GPTMICR |= 0x1;
    Timer3_GPTMCTL  |= 0x01;
    //Timer3_GPTMTAMR = (1<<5);
    SET_BIT(Timer3_GPTMTAMR, 5);
    for (i=0;i<Sec;i++){
        Timer3_GPTMICR = 0x1;
    }
}
*/
/*
void Timer3_Init(void)
{
    Timer_RCGC      |= (1 << 3);
    Timer3_GPTMCTL   = 0;                 //Disable timer for configuration.
    Timer3_GPTMCFG   = 0x04;               //Set 16-bit Mode.
    //Timer3_GPTMTAMR = 0x02;
    SET_BIT(Timer3_GPTMTAMR, 1);           //Periodic mode Mode.
    Timer3_GPTMTAILR = (16000000  - 1); //16 (PIOC in RCGC2 register provides 16MHz)
    Timer3_GPTMICR |= 0x1;
    Timer3_GPTMCTL  |= 0x01;
    SET_BIT(Timer3_GPTMTAMR, 5);
    Timer3_GPTMIMR = 0x01;
}
*/


void Timer1_Init(void)
{


/*
    //NVIC_ISER[0] = 0x00000800;
    NVIC_ISER[0] |= 0x00200000;
    NVIC_ISER[0] |= 0x00800000;
   // NVIC_ISER[0] |= (1<<21); //enable IRQ21
*/
    SET_BIT(Timer_RCGC, 1);            //enable clock to Timer Block 1
    CLEAR_BIT(Timer1_GPTMCTL, 0);       //disable Timer2 before initialization
    Timer1_GPTMCFG   = 0x04;            // 16-bit option
    Timer1_GPTMTAMR = 0x02;             // periodic mode and down-counter
    Timer1_GPTMTAPR = 250;               /// 16000000 Hz / 250 = 64000 Hz
    Timer1_GPTMTAILR = 64000;           //64000 Hz / 64000 = 1 Hz   16000000
    Timer1_GPTMICR = 0x1;               //clear the Timer1A timeout flag
    Timer1_GPTMIMR |= 0x01;               //enable Timer1A timeout interrupt
    SET_BIT(Timer1_GPTMCTL, 0);             //enable Timer1A after initialization
    Timer1_GPTMICR = 0x1;
    NVIC_ISER[1] |= 0xffffffff;        // enable IRQ21 (D21 of ISER[0])
    NVIC_ISER[0] |= 0xffffffff;
    //NVIC_ISER_PEN[0] |= 0x00200000;
}







void GPT_TIM0_voidSetCallBack(void (*Copy_ptr)(void))
{
GPT_TIM0_CallBack=Copy_ptr;
}


void TIMER1A_Handler(void)
{
 if (Timer1_GPTMMIS & 0x1){
     GPT_TIM0_CallBack();
     Timer1_GPTMICR |= 0x1;
 }


}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
