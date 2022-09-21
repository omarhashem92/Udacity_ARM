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
#include "../Includes/Port_Types.h"
#include "../Includes/Port.h"
#include "../CFGs/Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static void ApplyDir(u8 portName, u8 pinNumber , u8 pinMode);
static void ApplyDen(u8 portName, u8 pinNumber , u8 pinMode);



#define RCGCGPIO    (*((volatile unsigned long*)0x400FE608U))   // it enables clock for ports..
/* ports address */

#define __Port_A_Address        0x40004000  //Start Address of port A.
#define __Port_B_Address        0x40005000  //Start Address of port B.
#define __Port_C_Address        0x40006000  //Start Address of port C.
#define __Port_D_Address        0x40007000  //Start Address of port D.
#define __Port_E_Address        0x40024000  //Start Address of port E.
#define __Port_F_Address        0x40025000  //Start Address of port F.


/* ports offset */

#define     _DATA_Offset    0x3FC       //Offset of Data.
#define     _DIR_Offset     0x400       //Offset of Data Direction.
#define     _IS_Offset      0x404       //Offset of Interrupt Sense.
#define     _IBE_Offset     0x408       //Offset of Interrupt Both Edges.
#define     _IEV_Offset     0x40C       //Offset of Interrupt Event.

#define     _IM_Offset      0x410       //Offset of Interrupt Mask.
#define     _RIS_Offset     0x414       //Offset of Raw Interrupt Status.
#define     _MIS_Offset     0x418       //Offset of Masked Interrupt Status.
#define     _ICR_Offset     0x41C       //Offset of Interrupt Clear.
#define     _AFSEL_Offset   0x420       //Offset of Alternate Function Select.

#define     _DRV2_Offset    0x500       //Offset of 2-mA Drive Select.
#define     _DRV4_Offset    0x504       //Offset of 4-mA Drive Select.
#define     _DRV8_Offset    0x508       //Offset of 8-mA Drive Select.
#define     _ODE_Offset     0x50C       //Offset of Open Drain Select.
#define     _PUE_Offset     0x510       //Offset of Pull-Up Select.

#define     _PDE_Offset     0x514       //Offset of Pull-Down Select.
#define     _SRL_Offset     0x518       //Offset of Slew Rate Control Select.
#define     _DEN_Offset     0x51C       //Offset of Digital Enable.
#define     _LOCK_Offset    0x520       //Offset of LOCK.
#define     _CR_Offset      0x524       //Offset of Commit.

#define     _CID3_Offset    0xFFC       //Offset of PrimeCell Identification 3.
#define     _PC_Offset      0x52C       //Offset of Port Control.
#define     _ADCEN_Offset   0x530       //Offset of ACD Control.
#define     _DMAEN_Offset   0x534       //Offset of DMA Control.
#define     _Clock_Enable   0x608       //Offset of CE
#define     _PID4__Offset   0xFD0       //Offset of Peripheral Identification 4.

#define     _PID5__Offset   0xFD4       //Offset of Peripheral Identification 5.
#define     _PID6__Offset   0xFD8       //Offset of Peripheral Identification 6.
#define     _PID7__Offset   0xFDC       //Offset of Peripheral Identification 7.
#define     _PID0__Offset   0xFE0       //Offset of Peripheral Identification 0.
#define     _PID1__Offset   0xFE4       //Offset of Peripheral Identification 1.

#define     _PID2__Offset   0xFE8       //Offset of Peripheral Identification 2.
#define     _PID3__Offset   0xFEC       //Offset of Peripheral Identification 3.
#define     _CID0_Offset    0xFF0       //Offset of PrimeCell Identification 0.
#define     _CID1_Offset    0xFF4       //Offset of PrimeCell Identification 1.
#define     _CID2_Offset    0xFF8       //Offset of PrimeCell Identification 2.
#define     _GPIOAMSEL_Offset   0x528   //Offset of Analog Mode Select.


/***********************************************************************************
*
*       DATA Direction Register     **0x400**   (GPIODATA)
*
***********************************************************************************/
#define DDR_A (*((volatile u32*)(__Port_A_Address + _DIR_Offset)))
#define DDR_B (*((volatile u32*)(__Port_B_Address + _DIR_Offset)))
#define DDR_C (*((volatile u32*)(__Port_C_Address + _DIR_Offset)))
#define DDR_D (*((volatile u32*)(__Port_D_Address + _DIR_Offset)))
#define DDR_E (*((volatile u32*)(__Port_E_Address + _DIR_Offset)))
#define DDR_F (*((volatile u32*)(__Port_F_Address + _DIR_Offset)))

/***********************************************************************************
*
*       Digital Enable Register     **0x51C**   (GPIODEN)
*
***********************************************************************************/
#define DEN_A (*((volatile u32*)(__Port_A_Address + _DEN_Offset)))
#define DEN_B (*((volatile u32*)(__Port_B_Address + _DEN_Offset)))
#define DEN_C (*((volatile u32*)(__Port_C_Address + _DEN_Offset)))
#define DEN_D (*((volatile u32*)(__Port_D_Address + _DEN_Offset)))
#define DEN_E (*((volatile u32*)(__Port_E_Address + _DEN_Offset)))
#define DEN_F (*((volatile u32*)(__Port_F_Address + _DEN_Offset)))
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
static void ApplyDir(u8 portName, u8 pinNumber , u8 pinDir)
{

    switch (portName)
    {
    case Port_A:
        if (pinDir == DIR_OUTPUT)
        {
            SET_BIT(DDR_A, pinNumber);
        }
        else
        {
            CLEAR_BIT(DDR_A, pinNumber);
        }
        break;
    case Port_B:
            if (pinDir == DIR_OUTPUT)
            {
                SET_BIT(DDR_B, pinNumber);
            }
            else
            {
                CLEAR_BIT(DDR_B, pinNumber);
            }
            break;
    case Port_C:
            if (pinDir == DIR_OUTPUT)
            {
                SET_BIT(DDR_C, pinNumber);
            }
            else
            {
                CLEAR_BIT(DDR_C, pinNumber);
            }
            break;
    case Port_D:
            if (pinDir == DIR_OUTPUT)
            {
                SET_BIT(DDR_D, pinNumber);
            }
            else
            {
                CLEAR_BIT(DDR_D, pinNumber);
            }
            break;
    case Port_E:
            if (pinDir == DIR_OUTPUT)
            {
                SET_BIT(DDR_E, pinNumber);
            }
            else
            {
                CLEAR_BIT(DDR_E, pinNumber);
            }
            break;
    case Port_F:
            if (pinDir == DIR_OUTPUT)
            {
                SET_BIT(DDR_F, pinNumber);
            }
            else
            {
                CLEAR_BIT(DDR_F, pinNumber);
            }
            break;
    default:
        //do nothing
    }


}




static void ApplyDen(u8 portName, u8 pinNumber , u8 pinMode)
{

    switch (portName)
    {
    case Port_A:
        if (pinMode == DEN)
        {
            SET_BIT(DEN_A, pinNumber);
        }
        else
        {
            CLEAR_BIT(DEN_A, pinNumber);
        }
        break;
    case Port_B:
            if (pinMode == DEN)
            {
                SET_BIT(DEN_B, pinNumber);
            }
            else
            {
                CLEAR_BIT(DEN_B, pinNumber);
            }
            break;
    case Port_C:
            if (pinMode == DEN)
            {
                SET_BIT(DEN_C, pinNumber);
            }
            else
            {
                CLEAR_BIT(DEN_C, pinNumber);
            }
            break;
    case Port_D:
            if (pinMode == DEN)
            {
                SET_BIT(DEN_D, pinNumber);
            }
            else
            {
                CLEAR_BIT(DEN_D, pinNumber);
            }
            break;
    case Port_E:
            if (pinMode == DEN)
            {
                SET_BIT(DEN_E, pinNumber);
            }
            else
            {
                CLEAR_BIT(DEN_E, pinNumber);
            }
            break;
    case Port_F:
            if (pinMode == DEN)
            {
                SET_BIT(DEN_F, pinNumber);
            }
            else
            {
                CLEAR_BIT(DEN_F, pinNumber);
            }
            break;
    default:
        //do nothing
    }


}
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
void Port_Init (const Port_ConfigType* ConfigPtr){

            u8 i = 0;
           for(i=0 ; i < NUM_OF_CONFIGURED_PINS ; i++)
           {
               SET_BIT (RCGCGPIO, ConfigPtr[i].portName);
               ApplyDir(ConfigPtr[i].portName, ConfigPtr[i].pinNumber, ConfigPtr[i].pinDirection);
               ApplyDen(ConfigPtr[i].portName, ConfigPtr[i].pinNumber, ConfigPtr[i].pinMode);







           }
           //DEN_F = 0x0EU;


}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
