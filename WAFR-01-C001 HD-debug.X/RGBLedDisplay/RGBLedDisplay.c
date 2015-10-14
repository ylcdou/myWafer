
/*
 * File: RGBLedDisplay.c  
 * Author: Lawrence
 * Created on September 24, 2015, 17:16 PM
 * version 1.0
 * 
 * Comments:
 *     PIC  related function , look at its .h
 
 * Revision history: 
 
 * Modified: 
 
 * Note:
 *  
 */


#define RGBLedDisplay_GLOBALS
#include "..\sys\includes.h"

/*
 *  LevelTmpSetShow
 *  comment:
 *      according the levelTmpSetting, show the level of temperature now
 *                  = low:   LedLowRed   = ON ;
 *                  = medium Led_MediumGreen = ON :
 *                  = high   Led_HighBlue  = ON :
 * 
 */
void  LevelTmpSetShow ()
{
     /* to avoid the garbage show left, turn all RGB Led off */
    turnOffAllLed();
    switch ( levelTmpSetting )
    {
      case TEMPERATURE_LOW: 
           Led_LowRed   = ON ;   // indicate the level is at LOW
           Led_LowGreen   = ON ;   // indicate the level is at LOW
           Led_LowBlue   = ON ;   // indicate the level is at LOW
           break;
      case TEMPERATURE_MEDIUM: 
           Led_LowRed   = ON ;   // indicate the level is at LOW
           Led_LowGreen   = ON ;   
           Led_LowBlue   = ON ;   
           Led_MediumRed   = ON ;
           Led_MediumGreen   = ON ;   
           Led_MediumBlue   = ON ;   
           break;
      case TEMPERATURE_HIGH:
           Led_LowRed   = ON ;   // indicate the level is at LOW
           Led_LowGreen   = ON ;   
           Led_LowBlue   = ON ;   
           Led_MediumRed   = ON ;
           Led_MediumGreen   = ON ;   
           Led_MediumBlue   = ON ;   
           Led_HighRed   = ON ;   // indicate the level is at LOW
           Led_HighGreen   = ON ;   
           Led_HighBlue   = ON ;   
           break;
      default:
           break;
    }
}


/*
 * turnOffAllLed
 * comment: the three RGB led connected to PortC and PORTB.3
 * 
 * 
 */
void turnOffAllLed()
{
   /* turn off all LED */
    PORTC = 0;  // turn off all LED; PORTC --8 Led
    Led_HighBlue = OFF;  // turn off the Led_HighBlue ;
}


/*
 *  HeatProcessLedShow
 *  comment: when system go into Heating process, there is a level responding
 *           Led blink shows the system's status is in heating up 
 *           when the temperature has raised at the setting, the Led is at
 *           solid status to show that the temperature is arrived and system
 *           now is maintain the temperature
 * 
 */

void HeatProcessLedShow()
{

   while(TRUE)
  {
     switch ( levelTmpSetting )
    {
      case TEMPERATURE_LOW:
            if ( timerHalfSecond < 1)   
          {
            Led_LowBlue = ON ;
          }
            else if ( timerHalfSecond <2 )
            {
              Led_LowBlue = OFF ;
            }else
            {
                timerHalfSecond = 0 ;
            }
          break;
       case TEMPERATURE_MEDIUM:
            if ( timerHalfSecond < 1)   
          {
            Led_LowGreen = ON ;
            Led_MediumGreen = ON;
          }
            else if ( timerHalfSecond < 2 )
            {
             Led_LowGreen = OFF;
             Led_MediumGreen = OFF;
            }else
            {
                timerHalfSecond = 0 ;
            }
             break;
       case TEMPERATURE_HIGH:
            if ( timerHalfSecond < 1)   
          {
            Led_LowRed = ON ;
            Led_MediumRed = ON;
            Led_HighRed = ON;
          }
            else if ( timerHalfSecond < 2 )
            {
                Led_LowRed = OFF ;
                Led_MediumRed = OFF;
                Led_HighRed = OFF;
            }else
            {
                timerHalfSecond = 0 ;
            }
           break;
       default:
           break;
    } // end of switch (levelTmpSetting)

     break;
   }  // end While(TRUE)
}

//*****************************************************************************
// END OF FILE
//*****************************************************************************
