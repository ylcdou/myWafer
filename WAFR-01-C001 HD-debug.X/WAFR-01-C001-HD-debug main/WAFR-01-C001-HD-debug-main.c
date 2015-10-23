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
 */

#define WAFER_GLOBALS
#include "..\sys\includes.h"    

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

 int main(int argc, char** argv)
{
    int16 i;
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

    InitializeWafer();   // initial all the variable used in wafer.

    // Maintain the System Power ON , it has done in InitializeWafer
    // Now do it again, show it is very important in this system
    Power_On = YES;
    /* turn off the heating drive !!! */
    Drive_Plates = OFF ;  
    /* OK , it is safe now */

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
    InitializeADC();
    
    turnOffAllLed();        // turn off all RGB LED
            
    
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
    
    
    /*-------Show battery capacitor-----------------------*/
    /* In 10 Second of startup, show the battery capacity */
    /* using can break it by push S2 button */
    while(systemRunCount < 10 * 100)    // Note: it is 0.01S=10mS  +1
    {
        adcValue = GetBatteryValue();

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
    
#ifdef Check_Temp_AD597output    
    uint8 flagHeat = 0 ;
    uint8 count=0 ;
    int16 Kp ; 
    int16 temp;
    while(1)
    {
         //get the Temp from voltage from AD597output
         // using the data check with thermometer 
        //    iron station  thermometer      AD597 Output
        //   350 ( 176 'C)                    0.623  V
        //   356 ( 180 'C)                    0.625  V
        //   370 ( 187 'C)                    0.667  V
        //                      88'C          0.722  V
        //   400 ( 204 'C)                    0.735  V
        //   410 ( 210 'C)                    0.731  V
        //   420 ( 216 'C)                    0.76   V
        //   450 ( 232 'C)                    0.82   V
        //   500 ( 260 'C)                    0.92   V
        //                      114'C         0.86   V
        //                      185'C         1.42V
        //                      190'c         1.45V
        //                      210'C         1.5V
        adcValue =  GetTemperatureValue();
        
         turnOffAllLed();        // turn off all RGB LED
        if ( adcValue > 630 )   // ( 0.92/2.5 ) * 1024 = 367
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
        }else if (adcValue >600) //( 0.82/2.5 ) * 1024 = 335
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowGreen = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = OFF ;

            Led_HighRed = OFF ;
            Led_HighGreen = ON ;
        } else if ( adcValue > 570 )  // ( 0.76/2.5 ) * 1024 = 310
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = OFF ;

            Led_HighRed = ON ;
        } else if (adcValue >540 )  // ( 0.751/2.5 ) * 1024 = 307
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = ON ;
        }else if( adcValue > 510 ) // ( 0.731/2.5 ) * 1024 = 299

        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = ON ;
        }else if(adcValue > 480)  // ( 0.667/2.5 ) * 1024 = 272
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = ON ;
        }else if(adcValue> 450)   // ( 0.625/2.5 ) * 1024 = 255
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = ON ;
        }else if (adcValue> 420)   // ( 0.623/2.5 ) * 1024 = 254
        {
            Led_LowRed = OFF ;
            Led_LowGreen = ON ;
            Led_LowBlue = OFF ;
        }else
        {
            Led_LowRed = ON ;
        }
  
         
         if (flagHeat)
         {
             // Uo = 64 ;
             // Dt =  573 - adcValue
            
             temp = 573- adcValue ;
             temp = temp * 4.0 ;
             Kp = temp ;
             
             if ( Kp > 573 )
             {
                 Kp = 573 ;
             }
             
             temp= 0 ;
             
                Drive_Plates = 1 ;

                for (i=0; i<Kp ;i++)
                {
                  delay_10us();
                }

                Drive_Plates = 0 ;
                for( i=0; i< (573-Kp); i++ )
                {
                 delay_10us();
                }
         } else
         {
             Drive_Plates = 0 ;
             delay_ms(100);
         }
         
         /* using half drive heat to see what temperature it can get */
         /*
         if (flagHeat)
         {
                
               Drive_Plates = 1 ;
                for (i=0; i<Kp ;i++)
                {
                delay_10us();
                }
                Drive_Plates = 0 ;

                for( i=128; i< (256-Kp); i++ )
                {
                 delay_10us();
                }
         }
         
         */
             keyValue = ProcessButton();
             if( keyValue == BUTTON_SINGLE_CLICK )
             {
              Drive_Plates = OFF ;
              flagHeat = !flagHeat ;              
             } else if ( keyValue == BUTTON_DOUBLE_CLICK)
             {
              Drive_Plates = OFF ;
              flagHeat = !flagHeat ;              
                 break;
             }    
      }   // end of if(flagHeat)
         
    
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
           adcValue = GetBatteryChargeValue();
          if ( adcValue > 800 )
          {
              // it OK to charge the battery
                    Led_LowGreen = ON;
                    Led_MediumGreen = ON;
                    Led_HighGreen = ON;

          }else
          {
              adcValue = GetBatteryValue();

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
                    delay_ms(200);
                    
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
                        delay_ms(200);
                }else if ( adcValue > 816) 
                        {
                          Led_LowRed = ON;
                          Led_LowGreen = ON;
                          delay_ms(200);
                          Led_LowRed = OFF;
                          Led_LowGreen = OFF;
                          delay_ms(200);
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
        adcValue = GettemperatureValue;
        
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
    
    
    

