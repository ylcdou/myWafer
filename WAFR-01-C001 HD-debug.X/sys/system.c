 /*
 * File: system.c  
 * Author: Lawrence
 * Created on September 18, 2015, 10:48 PM
 * version 1.0
 * 
 * Comments:
 *     PIC system Initial and  those cannot classified to other modules
 
 * Revision history: 
 
 * Modified: 
 
 * Note:
 
 */

#define SYSTEM_GLOBALS
#include "..\sys\includes.h"


/* Refer to the device datasheet for information about available
oscillator configurations. */
void InitializeOscillator() 
{
/*
    OSCCONbits.IRCF0 = TRUE;  // Internal Oscillator Frequence Select bits
    OSCCONbits.IRCF1 = TRUE; 
    OSCCONbits.IRCF2 = TRUE;  // 111: 8MHz
    // System clock select bits
    OSCCONbits.SCS0 = FALSE;    // System Clock Select bits
    OSCCONbits.SCS1 = FALSE;    // 00: Primary oscillator

    OSCTUNEbits.PLLEN = TRUE;   // Frequency Multiplier PLL for INTOSC Enable
                                // bits 
                                //1 : Enabled for INTOSC ( 4MHz and 8MHz only)
//  OSCCON2bits.MFIOSEL = FALSE; 
    OSCTUNEbits.INTSRC = TRUE;  // Internal Oscillator Low_Frequency Source 
                                // Select bit
                                // 0: 31KHz; 1 = 31.25KHz
*/
}

/*
 *  Initialize the Interrupt
  *    
 */
void InitializeInterrupts()
{
    // Enable INT0 interrupt    
    INTCONbits.INT0IE = TRUE;   
    
    // Enable TMR0IE interrupt    
    INTCONbits.TMR0IE = TRUE;   // Enable the TMR0 overflow interrupt
  
    // Global Interrupt Enable
    INTCONbits.GIE = TRUE;
}

/*
 *    Initialize the PIN of PIC18F2240
 */
void InitializePinmux() 
{
    // LED control
    TRISCbits.TRISC0 = OUTPUT;   // LedLowRed
    TRISCbits.TRISC1 = OUTPUT;   // LedLowGreen
    TRISCbits.TRISC2 = OUTPUT;   // LedLowBlue
    TRISCbits.TRISC3 = OUTPUT;   // Led_MediumRed
    TRISCbits.TRISC4 = OUTPUT;   // Led_MediumGreen
    TRISCbits.TRISC5 = OUTPUT;   // Led_MediumBlue
    TRISCbits.TRISC6 = OUTPUT;   // Led_HighRed
    TRISCbits.TRISC7 = OUTPUT;   // Led_HighGreen
    // LED control
    TRISBbits.TRISB3 = OUTPUT;   // Led_HighBlue

    // AD579 input
    TRISAbits.TRISA0 = INPUT ;   
    
    // Bat1_ChargeOK 
    TRISAbits.TRISA1 = INPUT;
    
    TRISAbits.TRISA2 = INPUT ;   // we use it as  VREF- 
    TRISAbits.TRISA3 = INPUT ;   // we use it as  VREF+ 2.5V
    
    //Check_USB_Power_In
    TRISAbits.TRISA4 = INPUT;
    
    // Check Battery Voltage
    TRISAbits.TRISA5 = INPUT;
    
    // Key_Power input 
    TRISBbits.TRISB0 = INPUT;
    
    // Heat the bowl
    TRISBbits.TRISB1 = OUTPUT;
    
    // Maintain the Power--control PIN
    TRISBbits.TRISB2 = OUTPUT;
    
    // Inside temperature checking by DS18B20
    TRISBbits.TRISB4 = INPUT;
    
}

/*
 * Initialize Timer0
 */
void InitializeTimer0()
{
    T0CONbits.T08BIT = 0 ;  // Timer0 8-Bit/16Bit Control bit; 0 = 16-bit
    T0CONbits.T0CS   = 0 ;  // Internal clock
    T0CONbits.PSA    = 1 ;  // Timer0 Prescaler is not assigned , Timer0 clock input bypasses prescaler

    TMR0H = (65536-40000)/256;   // 10ms once Timer0 interrupt
    TMR0L = (65536-40000)%256 ;

    T0CONbits.TMR0ON = 1 ;  // Timer0 ON/Off Control bit 1=Enables

    
    INTCONbits.TMR0IF = 0 ;     // Clear timer0 overflow interrupt flag
    INTCONbits.TMR0IE = TRUE;   // Enable the TMR0 overflow interrupt
  
    
    INTCONbits.PEIE = 1 ;  // periphyrel interrupt enable
//    // Global Interrupt Enable
//    INTCONbits.GIE = TRUE;

}

/*
 * Initialize Timer1
 */
/*
void InitializeTimer1()
{
    T1CONbits.T1CKPS1 = 0 ;  // 
    T1CONbits.T1CKPS0 = 0 ;  //  1:1 pRESCALE VALUE 00
    
    T0CONbits.T0CS   = 0 ;  // Internal clock

    TMR0H = (65536-4000)/256;   // 1ms once Timer1 interrupt
    TMR0L = (65536-4000)%256 ;

    T1CONbits.TMR1ON = 1 ;  // Timer1 ON/Off Control bit 1=Enables

    PIR1bits.TMR1IF = 0 ;     // Clear timer1 overflow interrupt flag
    PIE1bits.TMR1IE = 1 ;     // Enable the TMR1 overflow interrupt
    
    INTCONbits.PEIE = 1 ;  // periphyrel interrupt enable
//    // Global Interrupt Enable
//    INTCONbits.GIE = TRUE;
}
*/

/*
 * Initialize InitializeINT0
* Note:
 *  On the board, there is button of S2 , it is the button:
 *     to turn on the system:  hardware
 *     to turn off the system: firmware check it ,and when it pushed lasting >3 second
 *                             then turn off system
 *      This button using INT0 interrupt.
 */
void InitializeINT0()
{
    INTCON2bits.INTEDG0 = 0 ;     // External Interrupt 0 Edge Select bit: 0 = on falling edge
    INTCONbits.INT0IF = 0 ;       // INT0 External Interrupt Flag     bit 1 = occurred
    
    INTCONbits.INT0IE = 1 ;        // INT0 External interrupt Enable  bit 1 = Enable
}

/*
 * Initialize AD
 * comment: ( Page 225 of Data Sheet)
 *    to perform and A/D conversion:
 *   1 configure the A/D module
 *      Configure analog pins, voltage reference and digital I/O---ADCON1
 *      Select A/D input channel ---ADCON0
 *      Select A/D acquisition time (ADCON2)
 *      Select A/D conversion clock (ADCON2)
 *      Ture on A/D module (ADCON0)
 *   2  Configure A/D interrupt (if desired ):
 *      Clear ADIF bit
 *      Set   ADIE bit
 *      Set   GIE  bit
 *   3 Wait the required acquisition time (if required)
 *   4 Start conversion
 *       Set GO/ (/DONE) bit (ADCON0)
 *   5 Wait for A/D conversion to complete, by either
 *       Polling for GO/ (/DONE) bit to be cleared 
 *     OR
 *       Waiting for the A/D interrupt
 *   6 Read A/D result registers (ADRESH:ADRESL); 
 *     Clear bit, ADIF, if required 
 *   7 For next conversion, go to step1 or step2, as required.The A/D conversion 
 *     time per bit is defined as TAD. A minimum wait of 2 TAD is required before
 *     the next acquisition starts
 * 
 * Note:
 *  There is:
 *    1 AD597 input signal respond the temperature checked
 *    2 Battery voltage 
 * 
 */
void InitializeAD()
{
  /*        ADCON1: A/D Control register1;   
   *  U-0 U-0  R/W-0  R/W-0  R/W-0   R/W-q   R/W-q  R/W-q 
   *   -- --   VCFG1  VCFG0  PCFG3   PCFG2   PCFG1  PCFG0
   *           1=Vref- (AN2)  
   *           0=Vss      
   *                  1= Vref+ (AN3)   
   *                  0= VDD
  */
  
  ADCON1bits.PCFG3 = 1;     // Set RA1--RA5 to be Analog input
  ADCON1bits.PCFG2 = 0; 
  ADCON1bits.PCFG1 = 0; 
  ADCON1bits.PCFG0 = 1; 
  
  ADCON1bits.VCFG1 = 1 ;   // Vref-  ( using a 0 Om connect to Vss)
  ADCON1bits.VCFG0 = 1 ;   // Vref+   
  
  /*        ADCON2: A/D Control register2
   *  R/W-0   U-0   R/W-0   R/W-0   R/W-0   R/W-0   R/W-0   R/W-0
   *  ADFM     --   ACQT2   ACQT1   ACQT0   ADCS2   ADCS1   ADCS0
   *  1=Right justified
   *  0=Left justified 
   *               
   *                ACQT<2:0>: A/D Acquisition Time Select bits
   *                ADCS<2:0>  A/D Conversion Clock Select bits                  
   */
  ADCON2bits.ADCS2 = 0 ;  // 010 = Fosc/32 
  ADCON2bits.ADCS1 = 1 ;
  ADCON2bits.ADCS0 = 0 ;
  
   ADCON2bits.ADFM = 1 ;  // Right justified 
   
   ADCON2bits.ACQT2 = 1;  // 110=16 TAD
   ADCON2bits.ACQT1 = 1;
   ADCON2bits.ACQT0 = 0;

   /*   ADCON0: A/D CONTROL REGISTER 0
    *  U-0  U-0 R/W-0   R/W-0   R/W-0   R/W-0   R/W-0          R/W-0
    * --    --  CHS3    CHS2    CHS1    CHS0    GO/ (/DONE)    ADON
    *           CHS<3:0> Channel Select bits
    *                                           1=A/D in process
    *                                           0=A/D idle
    *                                                          1=A/D Enabled
    *                                                          0=A/D Disabled
    */
   ADCON0bits.ADON = 1 ;   // Enable A/D
}

/* AD_Converter
 * Comments:
 *    Select channel and start A/D converter, then return the adValue
 * 
 * Note:
 *     Here use the Polling method for result of AD conversion
 * 
 */
uint16 AD_Converter( int8 channelNumber)
{
    uint16 AD_Result ;          //  save the value of AD results for return ;
   /*   ADCON0: A/D CONTROL REGISTER 0
    *  U-0  U-0 R/W-0   R/W-0   R/W-0   R/W-0   R/W-0          R/W-0
    * --    --  CHS3    CHS2    CHS1    CHS0    GO/ (/DONE)    ADON
    *           CHS<3:0> Channel Select bits
    *                                           1=A/D in process
    *                                           0=A/D idle
    *                                                          1=A/D Enabled
    *                                                          0=A/D Disabled
    */
    ADCON0 =  ((channelNumber & 0x07) << 2) | 0x01; // select AD channel
                                                    // |0x01 to always enable AD
                                                    //  = ADCON0bits.ADON=1
    
    // ADCON0bits.ADON = 1 ;   // Enable A/D 
    delay_10us() ;                         // wait for Voltage stability
    delay_10us() ;                         // wait for Voltage stability

    ADCON0bits.GO = 1;                      // start AD
    
    while( ADCON0bits.GODONE ) ;            // wait for AD 
    
    PIR1bits.ADIF = 0 ;                     // clear AD converter interrupt flag bit

    AD_Result =( ADRESH << 8 ) | ADRESL ;   // save AD_result in uint16 variable      
    
    return (AD_Result);
    
}


/*InitializeHardware
 * 
 * comment:  
 *    read the EEprom to get the status ( levelTempSetting ) user set last time
 *           
 * Note:
 * 
 */
void   InitializeHardware()
{
        // indicate the device status remembered in EEprom
           // ...
        levelTmpSetting = 1 ;

        LevelTmpSetShow ();
}
  
/* 
 * Shut down device
 * Comment:  when user push the S2 button for > 6 Second, device shut down
 *
 * Note:
 *      Here we need a Led blinking when firmware have detect a > 6S long
 *      holding on S2 button to remind user releasing the button, otherwise
 *      it maybe will again turn on the device
 *      But, because we use button rising edge interrupt to end the button
 *      push and tell system there is button push, so, before user release
 *      the button, firmware would not be able to know the time of PUSH,
 *      So, here to remain the user releasing the button DON't complete,
 *      Instead of this, when user releases the button ( > 6 S ), the device
 *      will have a led blinking to show that system is going shut down. 
 *
 */
void  ShutDownSystem()
{
    // turn off the System, because of >6 second pushed continually.
     turnOffAllLed();
     while(TRUE)
     {
       Power_On = NO ;   // shut down system
       Led_LowBlue    = ! Led_LowBlue ; // blink LED1Blue to ask user release 
                                        // the S2 button.
       Led_LowGreen   = ! Led_LowGreen ;
       delay_ms(80);
     } // end while
}


/*
 * ProcessHeat
 * Comment: according levelTmpSetting heat the bowl to its temperature
 * 
 * Note:
 */
void ProcessHeat()
{
    uint8 i ;
    int8 keyValue;
    uint16 adcValue;
    uint8  flagStop=0 ;  // when temperature rising to setting, = 1 ;
    uint32 countHeatTime = 0 ; // using this to limit the heat_time
                               // the current is huge, it is dangerous
    uint8 Kp = 30 ;
    uint8 count = 0 ;
    
    
    // to remember the Temp_setting
    // write the TempSetting in 0 location of EEPROM
    WriteEEprom ( TEMP_SETTING_EEPROM_LOCATION, levelTmpSetting );
    
#ifdef debug
    // for debug checking the process of EEPROM
    levelTmpSetting = ReadEEprom( TEMP_SETTING_EEPROM_LOCATION );
#endif    
    Drive_Plates = ON ;

    turnOffAllLed();  // erase the  trail of Led blink
    countHeatTime = timeSystemRun ; 
    while(TRUE)
  { 
     // if heating time > 15S, then stop heating, 
     if (  (countHeatTime + 2500 ) < timeSystemRun )   //  2500 = 25S * 0.01
     {
         flagStop = 1 ;
         break;
     }
     
     // if heating some time and the temperature is still not hight then 100'C
     // means that maybe the thermocouple is not contact bowl well, so give out
     // a alarm and stop heating
     if( 1)
     {}

#ifdef debug
              turnOffAllLed();        // turn off all RGB LED
        if ( adcValue > 345 )   // ( 0.92/2.5 ) * 1024 = 367
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
        }else if (adcValue >330) //( 0.82/2.5 ) * 1024 = 335
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowGreen = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = OFF ;

            Led_HighRed = OFF ;
            Led_HighGreen = ON ;
        } else if ( adcValue > 315 )  // ( 0.76/2.5 ) * 1024 = 310
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = OFF ;

            Led_HighRed = ON ;
        } else if (adcValue >300 )  // ( 0.751/2.5 ) * 1024 = 307
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = OFF ;
            Led_MediumBlue = ON ;
        }else if( adcValue > 285 ) // ( 0.731/2.5 ) * 1024 = 299

        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = OFF ;
            Led_MediumGreen = ON ;
        }else if(adcValue > 270)  // ( 0.667/2.5 ) * 1024 = 272
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = OFF ;
            Led_MediumRed = ON ;
        }else if(adcValue> 255)   // ( 0.625/2.5 ) * 1024 = 255
        {
            Led_LowRed = OFF ;
            Led_LowGreen = OFF ;
            Led_LowBlue = ON ;
        }else if (adcValue> 240)   // ( 0.623/2.5 ) * 1024 = 254
        {
            Led_LowRed = OFF ;
            Led_LowGreen = ON ;
            Led_LowBlue = OFF ;
        }else
        {
            Led_LowRed = ON ;
        }
#else
    HeatProcessLedShow(); 
#endif
    adcValue = GetAdcAD597Value( AD_AD597_CHANNEL  );

    switch ( levelTmpSetting )
    {
        case TEMPERATURE_LOW:
            if ( adcValue < TEMPERATURE_LOW_AD_VALUE * 0.8)
            { 
                Drive_Plates = ON ;
            }else
            {
                // 15? we need research for detail ,this is the scope of temp
                // vary around the setting value
                if (adcValue > TEMPERATURE_LOW_AD_VALUE + 15)  
                {
                    count++;
                    if( count > 50 )
                    {
                        count = 0 ;
                        Kp--;      // temper > setting, decrease duty cycle
                    }
                }else
                {
                    count++ ;
                    if (count >50)
                    {
                        count = 0 ;
                        Kp++;     // temper < setting, increase duty cycle
                    }
                }
                // according the duty cycle heat the bowl
                Drive_Plates = ON ;
                for (i=0; i<Kp ;i++)
                {
                delay_10us();
                }
                Drive_Plates = 0 ;
                for( i=0; i< (256-Kp); i++ )
                {
                 delay_10us();
                }
            }
     
            break;
        case TEMPERATURE_MEDIUM:
            if ( adcValue < TEMPERATURE_MEDIUM_AD_VALUE * 0.8)
            { 
                Drive_Plates = ON ;
            }else
            {
                // 15? we need research for detail ,this is the scope of temp
                // vary around the setting value
                if (adcValue > TEMPERATURE_MEDIUM_AD_VALUE + 15)  
                {
                    count++;
                    if( count > 50 )
                    {
                        count = 0 ;
                        Kp--;      // temper > setting, decrease duty cycle
                    }
                }else
                {
                    count++ ;
                    if (count >50)
                    {
                        count = 0 ;
                        Kp++;     // temper < setting, increase duty cycle
                    }
                }
                // according the duty cycle heat the bowl
                Drive_Plates = ON ;
                for (i=0; i<Kp ;i++)
                {
                delay_10us();
                }
                Drive_Plates = 0 ;
                for( i=0; i< (256-Kp); i++ )
                {
                 delay_10us();
                }
            }
             break;
        case TEMPERATURE_HIGH:
            if ( adcValue < TEMPERATURE_HIGH_AD_VALUE * 0.8)
            { 
                Drive_Plates = ON ;
            }else
            {
                // 15? we need research for detail ,this is the scope of temp
                // vary around the setting value
                if (adcValue > TEMPERATURE_HIGH_AD_VALUE + 15)  
                {
                    count++;
                    if( count > 50 )
                    {
                        count = 0 ;
                        Kp--;      // temper > setting, decrease duty cycle
                    }
                }else
                {
                    count++ ;
                    if (count >50)
                    {
                        count = 0 ;
                        Kp++;     // temper < setting, increase duty cycle
                    }
                }
                // according the duty cycle heat the bowl
                Drive_Plates = ON ;
                for (i=0; i<Kp ;i++)
                {
                delay_10us();
                }
                Drive_Plates = 0 ;
                for( i=0; i< (256-Kp); i++ )
                {
                 delay_10us();
                }
            }
           break;
        default:
           break;
    } // end of switch (levelTmpSetting)
    
    if ( flagStop )
    {
      break;   // break while( TRUE )
    }

    keyValue = ProcessButton();
    if( keyValue == BUTTON_SINGLE_CLICK )
     {
        flagS2KeyPushed = 0 ;  // clear button_press flag this time
        break;  // should be halt heating for some confirming things.
     } else if ( keyValue == BUTTON_DOUBLE_CLICK)
        {
            flagS2KeyPushed = 0 ;// clear button_press flag this time
            break;
        }
  
   }
    // clear the heating
    Drive_Plates = OFF ;
}


/* 
 *  GetADC_Value
 *  comment: using  AD_AVERAGE_NUMBER time AD_converter average result as the
 *           real adcValue
 * 
 *  input parameter:  channelNumber
 * 
 *  output parameter:  the average value of 10 times detect value
 * 
 * Note:  This is only for check Battery's voltage
 * 
 */
uint16 GetAdcBatValue(uint8 channelNumber)   // get adcValue from 10 times average.
{
    uint8 i;
    uint16 temp = 0 ;
    for ( i=0; i< ( AD_AVERAGE_NUMBER-1) ;i++)   // shift AD_AVERAGE_NUMBER-1 bit
    {
        adcBatValue[i] = adcBatValue[i+1] ;
    }
    
    adcBatValue[AD_AVERAGE_NUMBER-1]  = AD_Converter( channelNumber ) ;  // get once AD_result
    
    for ( i=0 ;i<AD_AVERAGE_NUMBER ;i++)
    {
        temp = temp + adcBatValue[i] ;
    }
    
    return ( temp/AD_AVERAGE_NUMBER );
}


/* 
 *  GetADC_Value
 *  comment: using  AD_AVERAGE_NUMBER time AD_converter average result as the
 *           real adcValue
 * 
 *  input parameter:  channelNumber
 * 
 *  output parameter:  the average value of 10 times detect value
 * 
 * Note: This is for check the output of AD597
 * 
 */
uint16 GetAdcAD597Value(uint8 channelNumber)   // get adcValue from 10 times average.
{
    uint8 i;
    uint16 temp = 0 ;
    
    
    for ( i=0; i< ( AD_AVERAGE_NUMBER-1) ;i++)   // shift AD_AVERAGE_NUMBER-1 bit
    {
        adcAD597Value[i] = adcAD597Value[i+1] ;
    }
    
    adcAD597Value[AD_AVERAGE_NUMBER-1]  = AD_Converter( channelNumber ) ;  // get once AD_result

    for ( i=0 ;i<AD_AVERAGE_NUMBER ;i++)
    {
        temp += adcAD597Value[i] ;
    }
    
    return ( temp/AD_AVERAGE_NUMBER );
}

/* 
 *  GetADC_Value
 *  comment: using  AD_AVERAGE_NUMBER time AD_converter average result as the
 *           real adcValue
 * 
 *  input parameter:  channelNumber
 * 
 *  output parameter:  the average value of 10 times detect value
 * 
 * Note: This is really only for charge battery STAT of MCP73831 output 
 * 
 */
uint16 GetAdcChargBatValue(uint8 channelNumber)   // get adcValue from 10 times average.
{
    uint8 i;
    uint16 temp = 0 ;
    for ( i=0; i< ( AD_AVERAGE_NUMBER-1) ;i++)   // shift AD_AVERAGE_NUMBER-1 bit
    {
        adcChargeStatValue[i] = adcChargeStatValue[i+1] ;
    }
    
    adcChargeStatValue[AD_AVERAGE_NUMBER-1]  = AD_Converter( channelNumber ) ;  // get once AD_result
    
    for ( i=0 ;i<AD_AVERAGE_NUMBER ;i++)
    {
        temp = temp + adcChargeStatValue[i] ;
    }
    
    return ( temp/AD_AVERAGE_NUMBER );
}

//*****************************************************************************
// END OF FILE
//*****************************************************************************
