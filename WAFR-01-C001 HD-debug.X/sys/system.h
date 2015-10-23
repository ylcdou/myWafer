
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

/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/
#define TRUE    1
#define FALSE   0  

// All countup timers are for 10 ms
#define SHUTDOWN_COUNT          600
#define DOUBLE_CLICK_COUNT      50
#define DEBOUNCE_COUNT          2
#define IN_HEAT_COUNT           500
#define IN_HEAT_DWELL_COUNT     1500
#define IN_STATE_COUNT          505
#define WAIT_FOR_POWEROFF_COUNT 30000
#define BUTTON_LATENCY_COUNT    50

#define NUMBER_OF_DWELL_LEVELS  12
// PWM timer always runs for 256, 64 is 1/4 on
#define HEATER_CURRENT_LIMIT    64
#define HEATER_SCALE     1


#define TEMPERATURE_LOW    1   // The level Temperature setting
#define TEMPERATURE_MEDIUM 2
#define TEMPERATURE_HIGH   3
                                           // need check it in device
#define TEMPERATURE_LOW_ADC     180// 460  // the AD_value of 185'C
#define TEMPERATURE_MEDIUM_ADC  200   // 520  // the AD_value of 200'C(514-550)
#define TEMPERATURE_HIGH_ADC    220     //  610  // the AD_value of 210'C(607-614)

#define TEMPERATURE_LOW_SET     1
#define TEMPERATURE_MEDIUM_SET  2
#define TEMPERATURE_HIGH_SET    3

#define BATTERY_MEDIUM_ADC      0x330
#define BATTERY_HIGH_ADC        0x390

#define BATTERY_LOW             0
#define BATTERY_MEDIUM          1
#define BATTERY_HIGH            2

#define RED_LOW                 16
#define GREEN_LOW               64
#define BLUE_LOW                256

#define RED_MEDIUM              192
#define GREEN_MEDIUM            192
#define BLUE_MEDIUM             64

#define RED_HIGH                256
#define GREEN_HIGH              128
#define BLUE_HIGH               128

#define RED_BATTERY             255
#define GREEN_BATTERY           247
#define BLUE_BATTERY            183

#define STATE_SHOW_TEMPERATURE  1
#define STATE_STARTUP           2
#define STATE_SHOW_BATTERY      3
#define STATE_CYCLE_LOW         4
#define STATE_CYCLE_MEDIUM      5
#define STATE_CYCLE_HIGH        6
#define STATE_HEAT              7
#define STATE_SET_TEMPERATURE   8
#define STATE_WAIT              9
#define STATE_POWEROFF          10
#define STATE_HEAT_DWELL        11
#define STATE_HEAT_FAILURE      12

#define NUMBER_OF_PWM_PHASES    256
// All countup timers are for 10 ms
#define SHUTDOWN_COUNT          600
#define DOUBLE_CLICK_COUNT      50
#define DEBOUNCE_COUNT          2
#define IN_HEAT_COUNT           500
#define IN_HEAT_DWELL_COUNT     1500
#define IN_STATE_COUNT          505
#define WAIT_FOR_POWEROFF_COUNT 30000
#define BUTTON_LATENCY_COUNT    50

#define NUMBER_OF_DWELL_LEVELS  12
// PWM timer always runs for 256, 64 is 1/4 on
#define HEATER_CURRENT_LIMIT    64
#define HEATER_SCALE     1

#define AD_AVERAGE_NUMBER  10   // for average the AD_result


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
#pragma config BORV = 3        // Brown Out Reset Voltage bits (Minimum setting, normally it is 19-- all the three config2L=19,not this bit)

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


// System running time, it depend on the time Timer0 interrupt once
SYSTEM_EXT uint32 systemRunCount = 0;
SYSTEM_EXT uint16 keyPowerDwellCount = 0;
SYSTEM_EXT uint16 keyPowerFlag = 0;
SYSTEM_EXT uint32 keyPowerLastPushTimer = 0;
SYSTEM_EXT uint32 keyPowerCurrentPushTimer = 0;
SYSTEM_EXT uint32 keyPowerDebounceCount = 0;// button pushed process variable
SYSTEM_EXT uint32 buttonLatencyCount = 0;
SYSTEM_EXT uint32 keyPowerThisDwell = 0;

SYSTEM_EXT int16 temperatureTarget = TEMPERATURE_LOW_ADC;
SYSTEM_EXT uint8 currentState = STATE_STARTUP;
SYSTEM_EXT uint8 lastState = STATE_WAIT;
SYSTEM_EXT uint8 stateChange = FALSE ;
SYSTEM_EXT uint8 batteryState = BATTERY_LOW;

SYSTEM_EXT uint8   timer0Count = 0 ;
SYSTEM_EXT uint16  timerHalfSecond = 0 ;

SYSTEM_EXT uint32 buttonPushTimeStop  ;  //record the first click button time
SYSTEM_EXT uint32 buttonPushTimeStart ;  //record the second click button time

SYSTEM_EXT uint16 pwmTimer = 0;
SYSTEM_EXT uint16 pwmPhase = 0;
SYSTEM_EXT uint16 stateTimer = 0;

SYSTEM_EXT uint8 dwellIndex = 0;
SYSTEM_EXT uint16 ledTarget = 0;
SYSTEM_EXT uint16 dwellLed1[NUMBER_OF_DWELL_LEVELS] = 
                            { 64, 128, 192, 256, 256, 256, 256, 256,
                                            256, 256, 256, 256};
SYSTEM_EXT uint16 dwellLed2[NUMBER_OF_DWELL_LEVELS] = 
                            {  0,   0,   0,   0,  64, 128, 192, 256,
                                            256, 256, 256, 256};
SYSTEM_EXT uint16 dwellLed3[NUMBER_OF_DWELL_LEVELS] = 
                            {  0,   0,   0,   0,   0,   0,   0,   0,
                                             64, 128, 192, 256};
SYSTEM_EXT int32 temperaturePWM = 0;
SYSTEM_EXT uint8 preheatFailed = FALSE;

SYSTEM_EXT uint16 redTarget = RED_LOW;
SYSTEM_EXT uint16 greenTarget = GREEN_LOW;
SYSTEM_EXT uint16 blueTarget = BLUE_LOW;

SYSTEM_EXT uint8   timer1Count = 0 ;

// levelTmpSetting = 1 --->  low     185 C 
                       // levelTmpSetting = 2 --->  medium  200 C 
                       // levelTmpSetting = 3 --->  high    210 C 
SYSTEM_EXT uint8 levelTmpSetting;

SYSTEM_EXT uint16 adcValueHelper  ;


// must have these two globe variable, because we need to do 8 times average
// so we must save every time value in a variable. 
// here is a good method from Jeff, not using +,+,... and then using * to save
// a lot of time of calculation.
// and using these two variable ,we can save space for not using array[8]
// another lot of space to save . 
// of course the disadvantage is it only have 4,8. 16 average way.
SYSTEM_EXT uint16 temperatureValue ;
SYSTEM_EXT uint16 batteryValue ;
SYSTEM_EXT uint16 batteryChargeValue ;

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* System initialization */
void InitializeOscillator() ;
void InitializeInterrupts() ;
void InitializePinmux() ;
void InitializeI2c() ;

void InitializeTimer0();
void InitializeINT0();  // S2 Key_Power
void InitializeADC();    

void InitializeWafer();

/* ADC relative function */
//uint16 AD_Converter(int8 channelNumber) ; not use this, see function's note
uint16 GetBatteryValue();      // ADC convert result, having a 8-Average algorithm
uint16 GetTemperatureValue();  // ADC convert result, having a 8-Average algorithm
uint16 GetBatteryChargeValue();// ADC convert result,having a 8-Average algorithm
                              // this version we use ADC to get the state of
                              // Bat charge, because of the pin is analog_PIN
uint16 ADC_ConvertTemperature();   // do once ADC convert of AD597
uint16 ADC_ConvertBattery();       // do once ADC convert of Battery voltage
uint16 ADC_ConvertBatteryCharge(); // do once ADC convert of checking charger OK


/* System process function */
uint8 ProcessButton();         // process the S2 button pushed event.

void  ShutDownSystem() ;       // turn off the device
void ProcessHeat();            // process heat according : levelTmpSetting
                                                // charger from 73831
#endif  // _SYSTEM_H_


//*****************************************************************************
// END OF FILE
//*****************************************************************************
