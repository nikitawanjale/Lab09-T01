#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"

#ifndef M_PI
#define M_PI                    3.14159265358979323846
#endif

#define SERIES_LENGTH 100

float gSeriesData[SERIES_LENGTH];

int32_t i32DataCount = 0;

int main(void)
{
    float fRadians;

    //Turn on lazy stacking
    ROM_FPULazyStackingEnable();
    //Turn on the FPU
    ROM_FPUEnable();

    //Set the system clock
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    fRadians = ((2 * M_PI) / SERIES_LENGTH);

    /*This loop will calculate the cosine value for each of the 100 values of the
  	  angle and place them in our data array*/
    while(i32DataCount < SERIES_LENGTH)
    {
    	gSeriesData[i32DataCount] = cosf(fRadians * i32DataCount);

    	i32DataCount++;
    }

    while(1)
    {
    }
}
