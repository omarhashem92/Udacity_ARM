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
#include "../Includes/Dio_Types.h"
#include "../Includes/Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/* ports address */

#define __Port_A_Address        0x40004000  //Start Address of port A.
#define __Port_B_Address        0x40005000  //Start Address of port B.
#define __Port_C_Address        0x40006000  //Start Address of port C.
#define __Port_D_Address        0x40007000  //Start Address of port D.
#define __Port_E_Address        0x40024000  //Start Address of port E.
#define __Port_F_Address        0x40025000  //Start Address of port F.


#define UNLOCK       0x4C4F434B  //Write this value to the register to unlock GPIOCR Register, If pin is shared with NMI (Non-Maskable Interrupt),
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

/***********************************************************************************
*
*       Data Register               **0x000**   (GPIODATA)
*
***********************************************************************************/
#define Data_A (*((volatile u32*)(__Port_A_Address + _DATA_Offset)))
#define Data_B (*((volatile u32*)(__Port_B_Address + _DATA_Offset)))
#define Data_C (*((volatile u32*)(__Port_C_Address + _DATA_Offset)))
#define Data_D (*((volatile u32*)(__Port_D_Address + _DATA_Offset)))
#define Data_E (*((volatile u32*)(__Port_E_Address + _DATA_Offset)))
#define Data_F (*((volatile u32*)(__Port_F_Address + 0x3FC)))

/***********************************************************************************
*
*       Pull-Up Resistor Register   **0x510**   (GPIOPUR)
*
***********************************************************************************/
#define PullUp_A (*((volatile u32*)(__Port_A_Address + _PUE_Offset)))
#define PullUp_B (*((volatile u32*)(__Port_B_Address + _PUE_Offset)))
#define PullUp_C (*((volatile u32*)(__Port_C_Address + _PUE_Offset)))
#define PullUp_D (*((volatile u32*)(__Port_D_Address + _PUE_Offset)))
#define PullUp_E (*((volatile u32*)(__Port_E_Address + _PUE_Offset)))
#define PullUp_F (*((volatile u32*)(__Port_F_Address + _PUE_Offset)))

/***********************************************************************************
*
*       Pull-Up Resistor Register   **0x514**   (GPIOPDR)
*
***********************************************************************************/
#define PullDown_A (*((volatile u32*)(__Port_A_Address + _PDE_Offset)))
#define PullDown_B (*((volatile u32*)(__Port_B_Address + _PDE_Offset)))
#define PullDown_C (*((volatile u32*)(__Port_C_Address + _PDE_Offset)))
#define PullDown_D (*((volatile u32*)(__Port_D_Address + _PDE_Offset)))
#define PullDown_E (*((volatile u32*)(__Port_E_Address + _PDE_Offset)))
#define PullDown_F (*((volatile u32*)(__Port_F_Address + _PDE_Offset)))

/***********************************************************************************
*
*       Interrupt Sense Register    **0x404**   (GPIOIS)
*
***********************************************************************************/
#define InterruptSense_A (*((volatile u32*)(__Port_A_Address + _IS_Offset)))
#define InterruptSense_B (*((volatile u32*)(__Port_B_Address + _IS_Offset)))
#define InterruptSense_C (*((volatile u32*)(__Port_C_Address + _IS_Offset)))
#define InterruptSense_D (*((volatile u32*)(__Port_D_Address + _IS_Offset)))
#define InterruptSense_E (*((volatile u32*)(__Port_E_Address + _IS_Offset)))
#define InterruptSense_F (*((volatile u32*)(__Port_F_Address + _IS_Offset)))

/***********************************************************************************
*
*       Interrupt Both Edges Register   **0x408**   (GPIOIBE)
*
***********************************************************************************/
#define InterruptBothEdges_A (*((volatile u32*)(__Port_A_Address + _IBE_Offset)))
#define InterruptBothEdges_B (*((volatile u32*)(__Port_B_Address + _IBE_Offset)))
#define InterruptBothEdges_C (*((volatile u32*)(__Port_C_Address + _IBE_Offset)))
#define InterruptBothEdges_D (*((volatile u32*)(__Port_D_Address + _IBE_Offset)))
#define InterruptBothEdges_E (*((volatile u32*)(__Port_E_Address + _IBE_Offset)))
#define InterruptBothEdges_F (*((volatile u32*)(__Port_F_Address + _IBE_Offset)))

/***********************************************************************************
*
*       Interrupt Event Register        **0x40C**   (GPIOIEV)
*
***********************************************************************************/
#define InterruptEvent_A (*((volatile u32*)(__Port_A_Address + _IEV_Offset)))
#define InterruptEvent_B (*((volatile u32*)(__Port_B_Address + _IEV_Offset)))
#define InterruptEvent_C (*((volatile u32*)(__Port_C_Address + _IEV_Offset)))
#define InterruptEvent_D (*((volatile u32*)(__Port_D_Address + _IEV_Offset)))
#define InterruptEvent_E (*((volatile u32*)(__Port_E_Address + _IEV_Offset)))
#define InterruptEvent_F (*((volatile u32*)(__Port_F_Address + _IEV_Offset)))

/***********************************************************************************
*
*       Interrupt Mask Register     **0x410**   (GPIOIM)
*
***********************************************************************************/
#define InterruptMask_A (*((volatile u32*)(__Port_A_Address + _IM_Offset)))
#define InterruptMask_B (*((volatile u32*)(__Port_B_Address + _IM_Offset)))
#define InterruptMask_C (*((volatile u32*)(__Port_C_Address + _IM_Offset)))
#define InterruptMask_D (*((volatile u32*)(__Port_D_Address + _IM_Offset)))
#define InterruptMask_E (*((volatile u32*)(__Port_E_Address + _IM_Offset)))
#define InterruptMask_F (*((volatile u32*)(__Port_F_Address + _IM_Offset)))

/***********************************************************************************
*
*       Raw Interrupt Status Register       **0x414**   (GPIORIS)
*
***********************************************************************************/
#define RawInterruptStatus_A (*((volatile u32*)(__Port_A_Address + _RIS_Offset)))
#define RawInterruptStatus_B (*((volatile u32*)(__Port_B_Address + _RIS_Offset)))
#define RawInterruptStatus_C (*((volatile u32*)(__Port_C_Address + _RIS_Offset)))
#define RawInterruptStatus_D (*((volatile u32*)(__Port_D_Address + _RIS_Offset)))
#define RawInterruptStatus_E (*((volatile u32*)(__Port_E_Address + _RIS_Offset)))
#define RawInterruptStatus_F (*((volatile u32*)(__Port_F_Address + _RIS_Offset)))

/***********************************************************************************
*
*       Masked Interrupt Status Register        **0x418**   (GPIOMIS)
*
***********************************************************************************/
#define MaskedInterruptStatus_A (*((volatile u32*)(__Port_A_Address + _MIS_Offset)))
#define MaskedInterruptStatus_B (*((volatile u32*)(__Port_B_Address + _MIS_Offset)))
#define MaskedInterruptStatus_C (*((volatile u32*)(__Port_C_Address + _MIS_Offset)))
#define MaskedInterruptStatus_D (*((volatile u32*)(__Port_D_Address + _MIS_Offset)))
#define MaskedInterruptStatus_E (*((volatile u32*)(__Port_E_Address + _MIS_Offset)))
#define MaskedInterruptStatus_F (*((volatile u32*)(__Port_F_Address + _MIS_Offset)))

/***********************************************************************************
*
*       Interrupt Clear Register        **0x41C**   (GPIOICR)
*
***********************************************************************************/
#define InterruptClear_A (*((volatile u32*)(__Port_A_Address + _ICR_Offset)))
#define InterruptClear_B (*((volatile u32*)(__Port_B_Address + _ICR_Offset)))
#define InterruptClear_C (*((volatile u32*)(__Port_C_Address + _ICR_Offset)))
#define InterruptClear_D (*((volatile u32*)(__Port_D_Address + _ICR_Offset)))
#define InterruptClear_E (*((volatile u32*)(__Port_E_Address + _ICR_Offset)))
#define InterruptClear_F (*((volatile u32*)(__Port_F_Address + _ICR_Offset)))

/***********************************************************************************
*
*       Alternate Function Select Register      **0x420**   (GPIOAFSEL)
*
***********************************************************************************/
#define AltFunSet_A (*((volatile u32*)(__Port_A_Address + _AFSEL_Offset)))
#define AltFunSet_B (*((volatile u32*)(__Port_B_Address + _AFSEL_Offset)))
#define AltFunSet_C (*((volatile u32*)(__Port_C_Address + _AFSEL_Offset)))
#define AltFunSet_D (*((volatile u32*)(__Port_D_Address + _AFSEL_Offset)))
#define AltFunSet_E (*((volatile u32*)(__Port_E_Address + _AFSEL_Offset)))
#define AltFunSet_F (*((volatile u32*)(__Port_F_Address + _AFSEL_Offset)))

/***********************************************************************************
*
*       Drive Select 2mA Register       **0x500**   (GPIODR2R)
*
***********************************************************************************/
#define DriveSel2mA_A (*((volatile u32*)(__Port_A_Address + _DRV2_Offset)))
#define DriveSel2mA_B (*((volatile u32*)(__Port_B_Address + _DRV2_Offset)))
#define DriveSel2mA_C (*((volatile u32*)(__Port_C_Address + _DRV2_Offset)))
#define DriveSel2mA_D (*((volatile u32*)(__Port_D_Address + _DRV2_Offset)))
#define DriveSel2mA_E (*((volatile u32*)(__Port_E_Address + _DRV2_Offset)))
#define DriveSel2mA_F (*((volatile u32*)(__Port_F_Address + _DRV2_Offset)))

/***********************************************************************************
*
*       Drive Select 4mA Register       **0x504**   (GPIODR4R)
*
***********************************************************************************/
#define DriveSel4mA_A (*((volatile u32*)(__Port_A_Address + _DRV4_Offset)))
#define DriveSel4mA_B (*((volatile u32*)(__Port_B_Address + _DRV4_Offset)))
#define DriveSel4mA_C (*((volatile u32*)(__Port_C_Address + _DRV4_Offset)))
#define DriveSel4mA_D (*((volatile u32*)(__Port_D_Address + _DRV4_Offset)))
#define DriveSel4mA_E (*((volatile u32*)(__Port_E_Address + _DRV4_Offset)))
#define DriveSel4mA_F (*((volatile u32*)(__Port_F_Address + _DRV4_Offset)))

/***********************************************************************************
*
*       Drive Select 8mA Register       **0x508**   (GPIODR8R)
*
***********************************************************************************/
#define DriveSel8mA_A (*((volatile u32*)(__Port_A_Address + _DRV8_Offset)))
#define DriveSel8mA_B (*((volatile u32*)(__Port_B_Address + _DRV8_Offset)))
#define DriveSel8mA_C (*((volatile u32*)(__Port_C_Address + _DRV8_Offset)))
#define DriveSel8mA_D (*((volatile u32*)(__Port_D_Address + _DRV8_Offset)))
#define DriveSel8mA_E (*((volatile u32*)(__Port_E_Address + _DRV8_Offset)))
#define DriveSel8mA_F (*((volatile u32*)(__Port_F_Address + _DRV8_Offset)))

/***********************************************************************************
*
*       Open Drain Register     **0x50C**   (GPIOORD)
*
***********************************************************************************/
#define OpenDrain_A (*((volatile u32*)(__Port_A_Address + _ODE_Offset)))
#define OpenDrain_B (*((volatile u32*)(__Port_B_Address + _ODE_Offset)))
#define OpenDrain_C (*((volatile u32*)(__Port_C_Address + _ODE_Offset)))
#define OpenDrain_D (*((volatile u32*)(__Port_D_Address + _ODE_Offset)))
#define OpenDrain_E (*((volatile u32*)(__Port_E_Address + _ODE_Offset)))
#define OpenDrain_F (*((volatile u32*)(__Port_F_Address + _ODE_Offset)))

/***********************************************************************************
*
*       Slew Rate Control Select Register       **0x518**   (GPIOSLR)
*
***********************************************************************************/
#define SlewRateCtrlSel_A (*((volatile u32*)(__Port_A_Address + _SRL_Offset)))
#define SlewRateCtrlSel_B (*((volatile u32*)(__Port_B_Address + _SRL_Offset)))
#define SlewRateCtrlSel_C (*((volatile u32*)(__Port_C_Address + _SRL_Offset)))
#define SlewRateCtrlSel_D (*((volatile u32*)(__Port_D_Address + _SRL_Offset)))
#define SlewRateCtrlSel_E (*((volatile u32*)(__Port_E_Address + _SRL_Offset)))
#define SlewRateCtrlSel_F (*((volatile u32*)(__Port_F_Address + _SRL_Offset)))

/***********************************************************************************
*
*       Lock Register       **0x520**   (GPIOLOCK)
*
***********************************************************************************/
#define LOCK_A (*((volatile u32*)(__Port_A_Address + _LOCK_Offset)))
#define LOCK_B (*((volatile u32*)(__Port_B_Address + _LOCK_Offset)))
#define LOCK_C (*((volatile u32*)(__Port_C_Address + _LOCK_Offset)))
#define LOCK_D (*((volatile u32*)(__Port_D_Address + _LOCK_Offset)))
#define LOCK_E (*((volatile u32*)(__Port_E_Address + _LOCK_Offset)))
#define LOCK_F (*((volatile u32*)(__Port_F_Address + _LOCK_Offset)))

/***********************************************************************************
*
*       Commit Register     **0x524**   (GPIOCR)
*
***********************************************************************************/
#define Commit_A (*((volatile u32*)(__Port_A_Address + _CR_Offset)))
#define Commit_B (*((volatile u32*)(__Port_B_Address + _CR_Offset)))
#define Commit_C (*((volatile u32*)(__Port_C_Address + _CR_Offset)))
#define Commit_D (*((volatile u32*)(__Port_D_Address + _CR_Offset)))
#define Commit_E (*((volatile u32*)(__Port_E_Address + _CR_Offset)))
#define Commit_F (*((volatile u32*)(__Port_F_Address + _CR_Offset)))

/***********************************************************************************
*
*       Analog Mode Select Register     **0x528**   (GPIOAMSEL)
*
***********************************************************************************/
#define AnalogMode_A (*((volatile u32*)(__Port_A_Address + _GPIOAMSEL_Offset)))
#define AnalogMode_C (*((volatile u32*)(__Port_B_Address + _GPIOAMSEL_Offset)))
#define AnalogMode_B (*((volatile u32*)(__Port_C_Address + _GPIOAMSEL_Offset)))
#define AnalogMode_D (*((volatile u32*)(__Port_D_Address + _GPIOAMSEL_Offset)))
#define AnalogMode_E (*((volatile u32*)(__Port_E_Address + _GPIOAMSEL_Offset)))
#define AnalogMode_F (*((volatile u32*)(__Port_F_Address + _GPIOAMSEL_Offset)))

/***********************************************************************************
*
*       Port Control Register       **0x52C**   (GPIOPCTL)      >>>>CASE STUDY<<<
*
***********************************************************************************/
#define Control_A (*((volatile u32*)(__Port_A_Address + _PC_Offset)))
#define Control_B (*((volatile u32*)(__Port_B_Address + _PC_Offset)))
#define Control_C (*((volatile u32*)(__Port_C_Address + _PC_Offset)))
#define Control_D (*((volatile u32*)(__Port_D_Address + _PC_Offset)))
#define Control_E (*((volatile u32*)(__Port_E_Address + _PC_Offset)))
#define Control_F (*((volatile u32*)(__Port_F_Address + _PC_Offset)))

/***********************************************************************************
*
*       ADC Control Register        **0x530**   (GPIOADCCTL)
*
***********************************************************************************/
#define ADCControl_A (*((volatile u32*)(__Port_A_Address + _ADCEN_Offset)))
#define ADCControl_B (*((volatile u32*)(__Port_B_Address + _ADCEN_Offset)))
#define ADCControl_C (*((volatile u32*)(__Port_C_Address + _ADCEN_Offset)))
#define ADCControl_D (*((volatile u32*)(__Port_D_Address + _ADCEN_Offset)))
#define ADCControl_E (*((volatile u32*)(__Port_E_Address + _ADCEN_Offset)))
#define ADCControl_F (*((volatile u32*)(__Port_F_Address + _ADCEN_Offset)))

/***********************************************************************************
*
*       DMA Control Register        **0x534**   (GPIODMACTL)
*
***********************************************************************************/
#define DMAControl_A (*((volatile u32*)(__Port_A_Address + _DMAEN_Offset)))
#define DMAControl_B (*((volatile u32*)(__Port_B_Address + _DMAEN_Offset)))
#define DMAControl_C (*((volatile u32*)(__Port_C_Address + _DMAEN_Offset)))
#define DMAControl_D (*((volatile u32*)(__Port_D_Address + _DMAEN_Offset)))
#define DMAControl_E (*((volatile u32*)(__Port_E_Address + _DMAEN_Offset)))
#define DMAControl_F (*((volatile u32*)(__Port_F_Address + _DMAEN_Offset)))

/***********************************************************************************
*
*       Clock Enable Register       **0x608**   (GPIOCEN)
*
***********************************************************************************/
#define CLK_Enable (*(volatile u32*)__Clock_Enable)
#define RCGC_2     (*(volatile u32*)(0x400FE108))

/***********************************************************************************
*
*       Peripheral Identification 0 Register        **0xFE0**   (GPIOPeriphID0)
*
***********************************************************************************/
#define PeripheralID0_A (*((volatile u32*)(__Port_A_Address + _PID0__Offset)))
#define PeripheralID0_B (*((volatile u32*)(__Port_B_Address + _PID0__Offset)))
#define PeripheralID0_C (*((volatile u32*)(__Port_C_Address + _PID0__Offset)))
#define PeripheralID0_D (*((volatile u32*)(__Port_D_Address + _PID0__Offset)))
#define PeripheralID0_E (*((volatile u32*)(__Port_E_Address + _PID0__Offset)))
#define PeripheralID0_F (*((volatile u32*)(__Port_F_Address + _PID0__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 1 Register        **0xFE4**   (GPIOPeriphID1)
*
***********************************************************************************/
#define PeripheralID1_A (*((volatile u32*)(__Port_A_Address + _PID1__Offset)))
#define PeripheralID1_B (*((volatile u32*)(__Port_B_Address + _PID1__Offset)))
#define PeripheralID1_C (*((volatile u32*)(__Port_C_Address + _PID1__Offset)))
#define PeripheralID1_D (*((volatile u32*)(__Port_D_Address + _PID1__Offset)))
#define PeripheralID1_E (*((volatile u32*)(__Port_E_Address + _PID1__Offset)))
#define PeripheralID1_F (*((volatile u32*)(__Port_F_Address + _PID1__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 2 Register        **0xFE8**   (GPIOPeriphID2)
*
***********************************************************************************/
#define PeripheralID2_A (*((volatile u32*)(__Port_A_Address + _PID2__Offset)))
#define PeripheralID2_B (*((volatile u32*)(__Port_B_Address + _PID2__Offset)))
#define PeripheralID2_C (*((volatile u32*)(__Port_C_Address + _PID2__Offset)))
#define PeripheralID2_D (*((volatile u32*)(__Port_D_Address + _PID2__Offset)))
#define PeripheralID2_E (*((volatile u32*)(__Port_E_Address + _PID2__Offset)))
#define PeripheralID2_F (*((volatile u32*)(__Port_F_Address + _PID2__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 3 Register        **0xFEC**   (GPIOPeriphID3)
*
***********************************************************************************/
#define PeripheralID3_A (*((volatile u32*)(__Port_A_Address + _PID3__Offset)))
#define PeripheralID3_B (*((volatile u32*)(__Port_B_Address + _PID3__Offset)))
#define PeripheralID3_C (*((volatile u32*)(__Port_C_Address + _PID3__Offset)))
#define PeripheralID3_D (*((volatile u32*)(__Port_D_Address + _PID3__Offset)))
#define PeripheralID3_E (*((volatile u32*)(__Port_E_Address + _PID3__Offset)))
#define PeripheralID3_F (*((volatile u32*)(__Port_F_Address + _PID3__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 4 Register        **0xFD0**   (GPIOPeriphID4)
*
***********************************************************************************/
#define PeripheralID4_A (*((volatile u32*)(__Port_A_Address + _PID4__Offset)))
#define PeripheralID4_B (*((volatile u32*)(__Port_B_Address + _PID4__Offset)))
#define PeripheralID4_C (*((volatile u32*)(__Port_C_Address + _PID4__Offset)))
#define PeripheralID4_D (*((volatile u32*)(__Port_D_Address + _PID4__Offset)))
#define PeripheralID4_E (*((volatile u32*)(__Port_E_Address + _PID4__Offset)))
#define PeripheralID4_F (*((volatile u32*)(__Port_F_Address + _PID4__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 5 Register        **0xFD4**   (GPIOPeriphID5)
*
***********************************************************************************/
#define PeripheralID5_A (*((volatile u32*)(__Port_A_Address + _PID5__Offset)))
#define PeripheralID5_B (*((volatile u32*)(__Port_B_Address + _PID5__Offset)))
#define PeripheralID5_C (*((volatile u32*)(__Port_C_Address + _PID5__Offset)))
#define PeripheralID5_D (*((volatile u32*)(__Port_D_Address + _PID5__Offset)))
#define PeripheralID5_E (*((volatile u32*)(__Port_E_Address + _PID5__Offset)))
#define PeripheralID5_F (*((volatile u32*)(__Port_F_Address + _PID5__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 6 Register        **0xFD8**   (GPIOPeriphID6)
*
***********************************************************************************/
#define PeripheralID6_A (*((volatile u32*)(__Port_A_Address + _PID6__Offset)))
#define PeripheralID6_B (*((volatile u32*)(__Port_B_Address + _PID6__Offset)))
#define PeripheralID6_C (*((volatile u32*)(__Port_C_Address + _PID6__Offset)))
#define PeripheralID6_D (*((volatile u32*)(__Port_D_Address + _PID6__Offset)))
#define PeripheralID6_E (*((volatile u32*)(__Port_E_Address + _PID6__Offset)))
#define PeripheralID6_F (*((volatile u32*)(__Port_F_Address + _PID6__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 7 Register        **0xFDC**   (GPIOPeriphID7)
*
***********************************************************************************/
#define PeripheralID7_A (*((volatile u32*)(__Port_A_Address + _PID7__Offset)))
#define PeripheralID7_B (*((volatile u32*)(__Port_B_Address + _PID7__Offset)))
#define PeripheralID7_C (*((volatile u32*)(__Port_C_Address + _PID7__Offset)))
#define PeripheralID7_D (*((volatile u32*)(__Port_D_Address + _PID7__Offset)))
#define PeripheralID7_E (*((volatile u32*)(__Port_E_Address + _PID7__Offset)))
#define PeripheralID7_F (*((volatile u32*)(__Port_F_Address + _PID7__Offset)))

/***********************************************************************************
*
*       Peripheral Identification 0 Register        **0xFF0**   (GPIOPeriphID0)
*
***********************************************************************************/
#define PrimeCellID0_A (*((volatile u32*)(__Port_A_Address + _CID0_Offset)))
#define PrimeCellID0_B (*((volatile u32*)(__Port_B_Address + _CID0_Offset)))
#define PrimeCellID0_C (*((volatile u32*)(__Port_C_Address + _CID0_Offset)))
#define PrimeCellID0_D (*((volatile u32*)(__Port_D_Address + _CID0_Offset)))
#define PrimeCellID0_E (*((volatile u32*)(__Port_E_Address + _CID0_Offset)))
#define PrimeCellID0_F (*((volatile u32*)(__Port_F_Address + _CID0_Offset)))

/***********************************************************************************
*
*       Peripheral Identification 1 Register        **0xFF4**   (GPIOPeriphID1)
*
***********************************************************************************/
#define PrimeCellID1_A (*((volatile u32*)(__Port_A_Address + _CID1_Offset)))
#define PrimeCellID1_B (*((volatile u32*)(__Port_B_Address + _CID1_Offset)))
#define PrimeCellID1_C (*((volatile u32*)(__Port_C_Address + _CID1_Offset)))
#define PrimeCellID1_D (*((volatile u32*)(__Port_D_Address + _CID1_Offset)))
#define PrimeCellID1_E (*((volatile u32*)(__Port_E_Address + _CID1_Offset)))
#define PrimeCellID1_F (*((volatile u32*)(__Port_F_Address + _CID1_Offset)))

/***********************************************************************************
*
*       Peripheral Identification 2 Register        **0xFF8**   (GPIOPeriphID2)
*
***********************************************************************************/
#define PrimeCellID2_A (*((volatile u32*)(__Port_A_Address + _CID2_Offset)))
#define PrimeCellID2_B (*((volatile u32*)(__Port_B_Address + _CID2_Offset)))
#define PrimeCellID2_C (*((volatile u32*)(__Port_C_Address + _CID2_Offset)))
#define PrimeCellID2_D (*((volatile u32*)(__Port_D_Address + _CID2_Offset)))
#define PrimeCellID2_E (*((volatile u32*)(__Port_E_Address + _CID2_Offset)))
#define PrimeCellID2_F (*((volatile u32*)(__Port_F_Address + _CID2_Offset)))
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
 * to be modified later
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
u8 Dio_ReadChannel (u8 Port, Dio_ChannelType ChannelId)
{




}

/******************************************************************************
* to be modified later
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
void Dio_WriteChannel (u8 PortId, Dio_ChannelType ChannelId, u8 Level)
{

    //temporary for testing
       // RCGCGPIO = 0x20U;
        //DDR_F = 0x0EU;
        //DEN_F = 0x0EU;

    switch (PortId)
    {
    case Port_A:
                if (Level == STD_LOW)
                {
                   CLEAR_BIT(Data_A, ChannelId);
                }
                else
                {
                    SET_BIT(Data_A, ChannelId);
                }
                break;
    case Port_B:
                if (Level == STD_LOW)
                {
                   CLEAR_BIT(Data_B, ChannelId);
                }
                else
                {
                    SET_BIT(Data_B, ChannelId);
                }
                break;
    case Port_C:
                if (Level == STD_LOW)
                {
                   CLEAR_BIT(Data_C, ChannelId);
                }
                else
                {
                    SET_BIT(Data_C, ChannelId);
                }
                break;
    case Port_D:
                if (Level == STD_LOW)
                {
                   CLEAR_BIT(Data_D, ChannelId);
                }
                else
                {
                    SET_BIT(Data_D, ChannelId);
                }
                break;
    case Port_E:
                if (Level == STD_LOW)
                {
                   CLEAR_BIT(Data_E, ChannelId);
                }
                else
                {
                    SET_BIT(Data_E, ChannelId);
                }
                break;
    case Port_F:
                if (Level == STD_LOW)
                {
                   CLEAR_BIT(Data_F, ChannelId);
                   Data_F = 0x0EU;
                }
                else
                {
                    SET_BIT(Data_F, ChannelId);
                }

    }

}

/******************************************************************************
 * to be modified later
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
void Dio_WritePort (u8 PortId, u8 Level)
{

    /* temoprary for testing */
           // RCGCGPIO = 0x20U;
            //DDR_F = 0x0EU;
           // DEN_F = 0x0EU;
    switch (PortId)
        {
    case Port_A:
                Data_A = Level;
                break;
    case Port_B:
                Data_B = Level;
                break;
    case Port_C:
                Data_C = Level;
                break;
    case Port_D:
                Data_D = Level;
                break;
    case Port_E:
                Data_E = Level;
                break;
    case Port_F:
                Data_F = Level;
        }
}





void Dio_FlipChannel(u8 PortId, Dio_ChannelType ChannelId)
{

    switch (PortId)
        {
        case Port_A:
            TOGGLE_BIT(Data_A, ChannelId);
                    break;
        case Port_B:
            TOGGLE_BIT(Data_B, ChannelId);
                    break;
        case Port_C:
            TOGGLE_BIT(Data_C, ChannelId);
                    break;
        case Port_D:
            TOGGLE_BIT(Data_D, ChannelId);
                    break;
        case Port_E:
            TOGGLE_BIT(Data_E, ChannelId);
                    break;
        case Port_F:

                    TOGGLE_BIT(Data_F, ChannelId);
        }

 }




/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
