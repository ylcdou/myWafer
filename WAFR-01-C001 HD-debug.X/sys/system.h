
/* 
 * File:   system.h
 * Author: Lawrence
 * Comments:
 *       MCU: PIC18F2420 for Wafer Vapor project create it.
 * 
 * Revision history: 
 * 
 * Created on September 14, 2015, 1:17 PM
 */

#ifndef _SYSTEM_H_
#define	_SYSTEM_H_

#ifdef SYSTEM_GLOBALS
#define SYSTEM_EXT
#else
#define SYSTEM_EXT extern
#endif

#define _XTAL_FREQ 16000000

#define TEMPERATURE_LOW    1   // The level Temperature setting
#define TEMPERATURE_MEDIUM 2
#define TEMPERATURE_HIGH   3
                                           // need check it in device
#define TEMPERATURE_LOW_AD_VALUE     180// 460  // the AD_value of 185'C
#define TEMPERATURE_MEDIUM_AD_VALUE  200   // 520  // the AD_value of 200'C(514-550)
#define TEMPERATURE_HIGH_AD_VALUE    220     //  610  // the AD_value of 210'C(607-614)

#define AD_AVERAGE_NUMBER  10

/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* TODO Define system operating frequency */

/* Microcontroller MIPs (FCY) */
//#define SYS_FREQ        16000000L
//#define FCY             SYS_FREQ/4


// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF //SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3        // Brown Out Reset Voltage bits (Minimum setting, normally it is 1.9)

// CONFIG2H
#pragma config WDT = OFF         // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
//#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)
#pragma config MCLRE = ON      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
//#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config LVP = OFF         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)


SYSTEM_EXT uint8   timer0Count = 0 ;
SYSTEM_EXT uint16  timerHalfSecond = 0 ;
SYSTEM_EXT uint32  timeSystemRun = 0 ;   // System running time, it depend on 

SYSTEM_EXT uint32 buttonPushTimeStop  ;  //record the first click button time
SYSTEM_EXT uint32 buttonPushTimeStart ;  //record the second click button time


SYSTEM_EXT uint8   timer1Count = 0 ;

SYSTEM_EXT uint8 S2KeyPushTime = 0 ;
SYSTEM_EXT uint8 flagS2KeyPushed = 0 ;

                       // levelTmpSetting = 1 --->  low     185 C 
                       // levelTmpSetting = 2 --->  medium  200 C 
                       // levelTmpSetting = 3 --->  high    210 C 
SYSTEM_EXT uint8 levelTmpSetting;

SYSTEM_EXT uint32 pushButtonJitterTime = 0 ; // button pushed process variable

SYSTEM_EXT uint16 adcBatValue[AD_AVERAGE_NUMBER]  ;// get average the adcValue
                                                   //  detected of Battery cap.
SYSTEM_EXT uint16 adcAD597Value[AD_AVERAGE_NUMBER];// get average the adcValue
                                                   //  detected of AD597 
SYSTEM_EXT uint16 adcChargeStatValue[AD_AVERAGE_NUMBER]; // get average the 
                                                         //adcValue detected of 
                                                         //STAT of MCP78381 

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/
void InitializeOscillator() ;
void InitializeInterrupts() ;
void InitializePinmux() ;
void InitializeI2c() ;

void InitializeTimer0();
void InitializeINT0();  // S2 Key_Power
void InitializeAD();    

void InitializeHardware();

uint16 AD_Converter(int8 channelNumber) ;
uint8 ProcessButton();         // process the S2 button pushed event.

void  ShutDownSystem() ;       // turn off the device
void ProcessHeat();            // process heat according : levelTmpSetting
uint16 GetAdcBatValue(uint8 channelNumber);   // get adcValue from 10 times average.
uint16 GetAdcAD597Value(uint8 channelNumber);  
uint16 GetAdcChargBatValue(uint8 channelNumber) ;
#endif  // _SYSTEM_H_


//*****************************************************************************
// END OF FILE
//*****************************************************************************
