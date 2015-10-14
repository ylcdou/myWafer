/*
 * File:   user.c
 * Author: Lawrence
 * Created on September 18, 2015, 9:20 PM
 * version 1.0
 * 
 * Comments:
 *     Some useful function not specific for special MCU.
 
 * Revision history: 
 
 * Modified: 
 
 * Note:
 *  
 */
#define USER_GLOBALS
#include "..\sys\includes.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/*
 * delay_ms at 16MHz oscillator
 */
void delay_ms(unsigned int x )
{
    unsigned int i,j;
    
    for ( j=0 ; j<x ;j++ )
    {
      for ( i=0; i<400; i++ );
    }
}


/*
 * delay_s at 16MHz oscillator
 */
void delay_s(unsigned int x) 
{
     unsigned int i;
    
    for ( i=0; i<x ; i++ )
    {
        delay_ms(1000);
    }
}

/*
 * delay_10us at 16MHz oscillator
 */
void delay_10us(void)
{
    unsigned int i;
      for (i=0; i<4; i++);
}

//*****************************************************************************
// END OF FILE
//*****************************************************************************
