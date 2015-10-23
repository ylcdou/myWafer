/*
 * File:   interrupts.c
 * Author: Lawrence
 * Created on September 18, 2015, 8:39 PM
 * version 1.0
 
 * * Comments:
 *   PIC interrupt function
 * 
 * Revision history: 
 * Modified: 
 * Note:
 *  
 */

#include "..\sys\includes.h"    

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

void interrupt ISR()
{
    
 // Timer0 interrupted ?   
    if ( INTCONbits.TMR0IE  && INTCONbits.TMR0IF)   
    {
        INTCONbits.TMR0IF = 0; 
        keyPowerDwellCount++ ;  // for calculate the Key_Push_Time
        buttonLatencyCount++ ;  // for delay check the key_Pushed,
        stateTimer++ ;
        systemRunCount++   ;    // Note: it is 0.01S=10mS  +1
                               // this is a uint32, it can run 497 days.
        
        TMR0H = (65536-40000)/256;   // 10ms one interrupt
        TMR0L = (65536-40000)%256 ;
    }
 
 
 // INT0 --- S2 button pushed ?
   if ( INTCONbits.INT0IF  && INTCONbits.INT0IE ) 
  {
     INTCONbits.INT0IF = 0 ;

     // two interrupt time <20ms, it was a button jitter 
     if (  (systemRunCount - keyPowerDebounceCount) < DEBOUNCE_COUNT ){
         // nothing to do , it was a button jitter
     }else{
            if ( !Key_Power )    
            {
                    INTCON2bits.INTEDG0 = 1 ; // External Interrupt 0 Edge Select
                                              // bit: 1 = on raising edge
                    timerHalfSecond = 0 ;
            }else
            {
               INTCON2bits.INTEDG0 = 0 ; // External Interrupt 0 Edge Select 
                                         // bit: 0 = on falling edge

               keyPowerFlag = TRUE  ;

               keyPowerLastPushTimer = keyPowerCurrentPushTimer;
               keyPowerCurrentPushTimer = systemRunCount;
               keyPowerThisDwell = keyPowerDwellCount;
            } // end of else 
            // and edge of push clear it = 0, 
            // in the upper else , push_last time = keyPowerDwellcount
            keyPowerDwellCount = 0 ; 
     }  // end of else{
            keyPowerDebounceCount = systemRunCount ;// record the last interrupt
  }
    

/*  for PWM Led control , tried to use Timer2 , but I think it cannot work
 *  at the 1mS interrupt, it is still blinking there, but I don't think we can 
 *  decrease the interrupt time more
 * 
    // Timer2 interrupted ?
    if ( PIE1bits.TMR1IE  && PIR1bits.TMR1IF)   
    {
        PIR1bits.TMR1IF = 0; 
        timer1Count++ ;

        if (timer1Count == 25)   
        {
            timer1Count = 0 ;
        }
    
        temp++;
        
        if(temp>200)
        {
            temp=0;
            Led_HighBlue = !Led_HighBlue ;
        }
        
        
        TMR1H = (65536-5500)/256;   // 1ms one interrupt
        TMR1L = (65536-5500)%256 ;
    }
 **/     
}


//*****************************************************************************
// END OF FILE
//*****************************************************************************
 