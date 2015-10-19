/* 
 * File:   WAFR-01-C001 HD-debug-main18.h
 * Author: Lawrence
 *
 * MCU: PIC18F2420
 * 
 * Created on September 14, 2015, 1:17 PM
 */

#ifndef _WAFER_H_
#define	_WAFER_H_

#ifdef WAFER_GLOBALS
#define WAFER_EXT
#else
#define WAFER_EXT extern
#endif

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#define  Led_LowRed            PORTCbits.RC0 
#define  Led_LowGreen          PORTCbits.RC1 
#define  Led_LowBlue           PORTCbits.RC2 

#define  Led_MediumRed            PORTCbits.RC3 
#define  Led_MediumGreen          PORTCbits.RC4 
#define  Led_MediumBlue           PORTCbits.RC5 

#define  Led_HighRed            PORTCbits.RC6 
#define  Led_HighGreen          PORTCbits.RC7 
#define  Led_HighBlue           PORTBbits.RB3 

#define AD597_out           PORTAbits.RA0

#define Bat1_ChargeOK       PORTAbits.RA1

#define Check_USB_Power_In  PORTAbits.RA4

#define AD_Bat              PORTAbits.RA5

#define Key_Power           PORTBbits.RB0  // when power the device it is Key_Power
#define button              PORTBbits.RB0  // normally using , it is button
#define Drive_Plates        PORTBbits.RB1
#define Power_On            PORTBbits.RB2
#define DS18B20             PORTBbits.RB4

#define AD_AD597_CHANNEL 0
#define AD_BAT_OK_CHANNEL 1
#define AD_VREF 3      // this is the real VREF+ it is 2.5V   
#define AD_BAT_CHANNEL  4

#define debug
//#define Check_Battery_ability
 #define Check_Temp_AD597output

#endif	/* _WAFER_H_ */

