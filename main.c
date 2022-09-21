
//ss
/**
 * main.c
 */

#include "Src/common/Macros.h"
#include "Src/common/Std_Types.h"
#include "Src/MCAL/Includes/Dio.h"
#include "Src/MCAL/Includes/Port.h"
#include "Src/MCAL/CFGs/Port_Cfg.h"
#include "Src/MCAL/Includes/Timer.h"

#define NVIC_ISER       (((u32*)0xE000E100))
#define NVIC_ICER       (((u32*)0xE000E180))
#define NVIC_SETPEN     (((u32*)0xE000E200))
#define NVIC_CLRPEN     (((u32*)0xE000E280))
#define NVIC_IABR       (((u32*)0xE000E300))
#define NVIC_IPR        (((u32*)0xE000E400))
#define SCB_IARC        *(((u32*)0xE000ED0C))



void display(void);


void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}


int main(void)
{





    // init timer 1A

    //to do enable global interrupt

   // Nvic_Init();
    //STK_voidInit();
    Port_Init(port_InitConfigArr);
    //Timer1_Init();
    GPT_TIM0_voidSetCallBack(display);
    Timer1_Init();

   // Port_Init(port_InitConfigArr);

        while(1){





          //Dio_FlipChannel(PORT_F, PIN_1);
          //delayMs(100);
          //Dio_FlipChannel(PORT_F, PIN_1);
          //delayMs(100);


            /*
           _delay_s(5000);
           Dio_WriteChannel(PORT_F, PIN_3, STD_HIGH);
           _delay_s(5000);
           Dio_WriteChannel(PORT_F, PIN_3, STD_LOW);
           _delay_s(5000);
           Dio_WriteChannel(PORT_F, PIN_3, STD_HIGH);
           _delay_s(5000);
           */




           /*
           Dio_WritePort(PORT_F, 0x02);
           _delay_s(2000);
           Dio_WritePort(PORT_F, 0x04);
           _delay_s(2000);
           Dio_WritePort(PORT_F, 0x08);
           _delay_s(2000);
           Dio_WritePort(PORT_F, 0x0E);
           _delay_s(2000);

            */



           //to do: pullup/down in port, external interrupt in interrupt mask in port in case they are needed.
        }

    return 0;
}


void display(void)
{
               //Dio_WritePort(PORT_F, 0x0E);
    Dio_FlipChannel(PORT_F, PIN_3);
}

//void TIMER1A_Handler(void)
//{
//GPT_TIM0_CallBack();
    //Dio_FlipChannel(PORT_F, PIN_3);
//}
