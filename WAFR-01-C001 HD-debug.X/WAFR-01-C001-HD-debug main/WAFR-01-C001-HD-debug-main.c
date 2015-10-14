/*
 * File:   WAFR-01-C001-HD-debug-main18.c
 * Author: Lawrence
 * Created on September 18, 2015, 8:39 PM
 * version 1.0
 *  Comments:
 *     This is for Wafer vapor first version PCB debugging.
 *     There is some mistake or because some un_understanding about the PIC
 *        AD specific. So here the AD_input not in the sequence of AN0-.. ANx
 *     So , this will give some trouble in debugging the Digital Input between
 *          two Analog Input 
 * 
 * Revision history: 

 *  * Modified: 

 *  * Note:
 * 
 * 
 *  for checking GitHub
 *  and then check in GitHub
 *  
 */

#define WAFER_GLOBALS
#include "..\sys\includes.h"    


//#define Check_Battery_ability

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

 int main(int argc, char** argv)
{
    unsigned int i;
    int8 keyValue;     // for S2 button using:
                       // keyValue = 0 --->  no button pushed
                       //          = 1 --->  short pushed 
                       //          = 2 --->  double short pushed 
    int16 adcValue; 
  
    uint32 countHeatTime = 0 ;
    uint8 flagChargeBat = 0 ;
    
    /* Configure the oscillator for the device */
    InitializeOscillator();
    /* Initialize I/O and Peripherals for application */
    InitializePinmux();
    // Maintain the System Power ON
    Power_On = YES;
    /* Timer0 initial function, the system clock uses it 
     * ( like the Arduino 32 clock)
     * and the general clock uses it
     */
    /* Using Timer1 to simulate the PWM Led control */
//    InitializeTimer1();

    /* Initialize the interrupt this board need to use */
    InitializeInterrupts();

    InitializeTimer0();
    /* Initialize the INT0 , the S2 button use it */
    InitializeINT0();
    /* Initialize the AD system,
     *  in this system, we only using the Polling AD
     */
    InitializeAD();

    turnOffAllLed();        // turn off all RGB LED
            
    /* turn off the heating drive !!! */
    Drive_Plates = OFF ;  
    /* OK , it is safe now */
    
    /*  waiting for user to release the button to avoid startup system and then
     *  shutdown the system for a long push
     */
    while ( !button )
    {
      Led_LowRed    = ! Led_LowRed ;  // blink LED1Red to ask user release the button
      Led_LowBlue   = ! Led_LowBlue;
      delay_ms(80);
    }
    Led_LowRed = OFF ;
    
    /* Initialize the system clock*/
    timeSystemRun = 0 ;
    
    /* Initialize the battery's capacitor value */
    /* because of the average calculating need some time 
     * So, here give the array a low battery capacitor value
     */ 
    for ( i = 0 ; i < AD_AVERAGE_NUMBER ; i++)
    {
     adcBatValue[i] = 816 ;      // 3.12V
     adcAD597Value[i] = 0 ;     
    }    
    
    /* Initialize the buttonPushTime */
    buttonPushTimeStart = 0 ;
    buttonPushTimeStop = 0 ; 
    
    /*-------Show battery capacitor-----------------------*/
    /* In 10 Second of startup, show the battery capacity */
    /* using can break it by push S2 button */
    while(timeSystemRun < 10 * 100)    // Note: it is 0.01S=10mS  +1
    {
        adcValue = GetAdcBatValue( AD_BAT_CHANNEL );

        turnOffAllLed();   // clear the trail of history display
        if ( adcValue > 996)   // 4.01 V
        {
            // display 100% battery capacitor
            Led_LowRed = ON;
            Led_LowGreen = ON;
            Led_MediumRed = ON;
            Led_MediumGreen = ON;
            Led_HighRed = ON;
            Led_HighGreen = ON;
        }else if ( adcValue > 891 )
        {
                Led_LowRed = ON;
                Led_LowGreen = ON;
                Led_MediumRed = ON;
                Led_MediumGreen = ON;
        }else if ( adcValue > 816) 
                {
                  Led_LowRed = ON;
                  Led_LowGreen = ON;
                } else
                {
                  Led_LowRed = ON;
                  Led_LowGreen = ON;
                  delay_ms(100);
                  Led_LowRed = OFF;
                  Led_LowGreen = OFF;
                  delay_ms(100);
                }
        
        keyValue = ProcessButton();
        if ( keyValue != BUTTON_NO_CLICK )
        {
            break;  // Have button pushed , then skip show battery capacitor
        }
    }                                        
    
    // Put this behind last while is because in last while, there is a 
    //  keyValue = ProcessButton , it will effect the value of levelTmpSetting
        
    /* Read the Temperature setting last time */
    levelTmpSetting = ReadEEprom( TEMP_SETTING_EEPROM_LOCATION );
    if ( (levelTmpSetting > 3) | (levelTmpSetting == 0 ) )
    {
        levelTmpSetting = 1 ;   // only have 3 level, now it is a new system, 
                                // initial it at 1 level
    }
    
#ifdef Check_Battery_ability
  
    uint32 countHeatTime = 0 ;
    // check the battery ability to heat bowl , how many times when every circle
    // is about 15 second.
    while(TRUE)
    {
             // heat for 15 second; 
             countHeatTime = timeSystemRun ;   
             Drive_Plates = ON ;
             while ( (countHeatTime + 1500) > timeSystemRun )// 1500= 15S / 0.01
             {
                adcValue = GetAdcAD597Value( AD_AD597_CHANNEL  );
             }  // end of while

            //  stop for 15 second
              countHeatTime = timeSystemRun ;   
             Drive_Plates = OFF ;
             while ( (countHeatTime + 1500) > timeSystemRun )// 1500= 15S / 0.01
             {
                adcValue = GetAdcAD597Value( AD_AD597_CHANNEL  );
             }  // end of while
    
    }
#endif     
    
    /* start */ 
    while(TRUE)
    {
       if ( !flagChargeBat ) 
       {
         keyValue = ProcessButton();
         switch ( keyValue)
         {
             case BUTTON_SINGLE_CLICK :  // Nothing to do, in ProcessButton
                                         // the single push has been process
                                         // That is levelTmpSetting be changed
                                         // and led display be changed.
                 break;
             case BUTTON_DOUBLE_CLICK :
                 ProcessHeat();
                 break;
             case BUTTON_POWER_OFF :
                 ShutDownSystem();
                 break;
             default: break;
         }
 
        // Delay 0.5S to display the status of stepping into next 
        // temperature level setting to be sure there is no double click
        // That is , if it is surly a double_click, we should not step in
        // next Temperature level setting, 
        // Here, when released the button, the rising edge interrupt will
        // clear timeHalfSecond, so ,here timerHalfSecond >= 1 can delay
        // display for 0.5S
         if ( timerHalfSecond >= 1 ) 
        {                            
              LevelTmpSetShow();  // refresh the level show
        }    
       }  // end if if ( ! flagChargBat )
       
        // check if USB is plug in , then show the battery is charging.
        // and show the Bat_value and if battery is charged OK.
        if ( Check_USB_Power_In ) 
        {
          flagChargeBat = 1;    
            // sure the USB has plugged in
          adcValue = GetAdcChargBatValue( AD_BAT_OK_CHANNEL );
          if ( adcValue > 800 )
          {
              // it OK to charge the battery
                    Led_LowGreen = ON;
                    Led_MediumGreen = ON;
                    Led_HighGreen = ON;

          }else
          {
                adcValue = GetAdcChargBatValue( AD_BAT_OK_CHANNEL );

                turnOffAllLed();   // clear the trail of history display
                if ( adcValue > 996)   // 4.01 V
                {
                    // display 100% battery capacitor
                    Led_LowRed = ON;
                    Led_LowGreen = ON;
                    Led_MediumRed = ON;
                    Led_MediumGreen = ON;
                    Led_HighRed = ON;
                    Led_HighGreen = ON;
                    delay_ms(200);
                    Led_LowRed = OFF;
                    Led_LowGreen = OFF;
                    Led_MediumRed = OFF;
                    Led_MediumGreen = OFF;
                    Led_HighRed = OFF;
                    Led_HighGreen = OFF;
                    
                }else if ( adcValue > 891 )
                {
                        Led_LowRed = ON;
                        Led_LowGreen = ON;
                        Led_MediumRed = ON;
                        Led_MediumGreen = ON;
                        delay_ms(200);
                        Led_LowRed = OFF;
                        Led_LowGreen = OFF;
                        Led_MediumRed = OFF;
                        Led_MediumGreen = OFF;
                }else if ( adcValue > 816) 
                        {
                          Led_LowRed = ON;
                          Led_LowGreen = ON;
                          delay_ms(200);
                          Led_LowRed = OFF;
                          Led_LowGreen = OFF;
                        } else
                        {
                          Led_LowRed = ON;
                          Led_LowGreen = ON;
                          delay_ms(100);
                          Led_LowRed = OFF;
                          Led_LowGreen = OFF;
                          delay_ms(100);
                        }
          }  // end of else{
          

        } else 
        {
            flagChargeBat = 0 ;
        }
    } /// main while
    return ( EXIT_SUCCESS);
}



//*****************************************************************************
// END OF FILE
//*****************************************************************************

    
    /*  checking thermal couple on board
     */
  /*
    while(1)
    {
        adcValue = GetAdcAD597Value( AD_AD597_CHANNEL  );
        
         turnOffAllLed();        // turn off all RGB LED
        if ( adcValue >175 )
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowGreen = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = OFF ;

            Led_HighRed = OFF ;
            Led_HighGreen = OFF ;
            Led_HighBlue = ON ;
        }else if (adcValue >160)     // 160 ---> 350F 180C
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowGreen = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = OFF ;

            Led_HighRed = OFF ;
            Led_HighGreen = ON ;
        } else if ( adcValue >145 )
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = OFF ;

            Led_HighRed = ON ;
        } else if (adcValue >130 )
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = ON ;
        }else if( adcValue > 115 )
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = ON ;
        }else if(adcValue > 100)
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = ON ;
        }else if(adcValue>85)
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = ON ;
        }else
        {
            Led_LowGreen = OFF ;
            Led_LowRed = ON ;
        }
        
        
            delay_ms(200);
    }
    
    
    */
    
    
    

