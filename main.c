

/**
 * main.c
 */

#include "Src/common/Macros.h"
#include "Src/common/Std_Types.h"
#include "Src/MCAL/Includes/Dio_Types.h"
#include "Src/MCAL/Includes/Dio.h"


int main(void)
{


        while(1){


           Dio_WriteChannel(PORT_F, PIN_3, STD_HIGH);
        }

    return 0;
}
