
/*
 * File: keyboard.c  
 * Author: Lawrence
 * Created on September 25, 2015, 14:56 PM
 * version 1.0
 * 
 * Comments:
 *     PIC system keyboard related function , look at its .h
 
 * Revision history: 
 
 * Modified: 
 
 * Note:
 *  
 */

#define KEYBOARD_GLOBALS
#include "..\sys\includes.h"

/* 
 *   ProcessButton
 *   process the S2 button pushed event 
 * 
 *   input parameter:  None
 *   return :
 *   for S2 button using:
 *       keyValue = 0 --->  no button pushed
 *                = 1 --->  short pushed 
 *                = 2 --->  double short pushed      
 *  Note:   
 *  0  Using INT0 to get the button pushed and using Timer0 interrupt to get
 *     the pushed time
 *  1  When click the button, the Led display changes completes in this function
 *  2  To every short click, system will have a response, and step into next 
 *     temperature setting. then when next click happens, system will check the 
 *     period between these two clicks, if it short then , < 0.5 (?)S , system
 *     get to know , there is double_click happened, and then delete the first
 *     click record.
 */
uint8 ProcessButton()
{
    uint32 buttonPushPeriod = 0 ;
    
    if ( keyPowerFlag )    // whether there is a pushed event happened 
        {
            keyPowerFlag = FALSE ;   // clear pushed flag , 

            
           /*====================================================*/
           /* first to see if user want to shut down the machine */
           /*====================================================*/
            if ( keyPowerThisDwell >= SHUTDOWN_COUNT )  //  >= 6Second 
            {                          
                 lastState = currentState;
                 currentState = STATE_POWEROFF;
                 stateTimer = 0 ;
                 return ( BUTTON_POWER_OFF ) ;  
            }
            else
            {
                buttonLatencyCount = 0 ;    // any key_Pushed will clear this
                                            // variable, so ,next if, we only 
                                            // begin to check if there is key
                                            // single or double pushed after
                                            // delay 500ms:BUTTON_LATENCY_COUNT
                   // the disadvantage is :responsible for key pushed slowly
                   //                    because of the 500ms delay ;
                   // The advantage is : it can void first respond the single
                   //                    click, then know it was the first 
                   //                    click of double click, so must delete
                   //                    the responded action for single click
                   //                    and change to process the double_click.
            
            }  // end else
        }
         
    if (buttonLatencyCount == BUTTON_LATENCY_COUNT )
    {
        buttonLatencyCount++ ;  // ++ to avoid next time enter this function
                                // to check double_click again AND again goto
                                // a single push process
        if(keyPowerCurrentPushTimer - keyPowerLastPushTimer < DOUBLE_CLICK_COUNT)
        {
            lastState = currentState ;
            currentState = STATE_HEAT;
            stateChange = TRUE ;
            stateTimer = 0 ;
            return ( BUTTON_DOUBLE_CLICK );
        }else{
                // It was not the double push
                // Refresh the button push time 
                if ( temperatureTarget == TEMPERATURE_LOW_ADC )
                {
                    temperatureTarget = TEMPERATURE_MEDIUM_ADC;
                } else if ( temperatureTarget == TEMPERATURE_MEDIUM_ADC ) 
                {
                    temperatureTarget = TEMPERATURE_HIGH_ADC;
                } else
                {
                    temperatureTarget = TEMPERATURE_LOW_ADC;
                }
                // Mark this PUSH as the first PUSH of double_click for when next
                // button_push happen, to check the double_click.
                lastState = currentState;
                currentState = STATE_SHOW_TEMPERATURE;
                stateChange = TRUE;
                stateTimer = 0;
            return ( BUTTON_SINGLE_CLICK) ; // reserve my return 
                                            // record the state is Jeff's style
        }   // end of els
           /*----------------------------------------------------*/
    }  // end if(buttonLatencyCount == buttonPushPeriod )
    return ( BUTTON_NO_CLICK );
}  // end  ProcessButton()


//*****************************************************************************
// END OF FILE
//*****************************************************************************
