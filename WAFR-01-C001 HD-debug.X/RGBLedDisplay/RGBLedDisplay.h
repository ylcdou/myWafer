/* 
 * File:   RGBLedDisplay.h
 * Author: Lawrence
 *
 * MCU: PIC18F2420
 * 
 * Created on September 24, 2015 17:16 PM
 * 
 * According Joel Plan: the function of three RGB Led are:
    LED Colours:
    1.	Low Temp = R:198 G:246 B:255 (Blue)
    2.	Med Temp= R:198 G:255 B:222 (Green)
    3.	High Temp= R:255 G:198 B:198 (Red)
    4.	Battery State = R:255 G:247 B:183 (Yellow)
    LED Operation:
    1.	3 LEDs indicate temp settings
    2.	On startup, the three LEDs will pulse/breath yellow to indicate battery
        capacity
    3.	Single yellow LED for 30% capacity, two yellow LEDs for 60% capacity,
        and three yellow LEDs for 100% capacity
    4.	When cycling through the settings, a single LED will glow white for
        "Low" setting
    5.	Next temp setting "Medium" will show two LEDs and both will be white
    6.	Final temp setting "High" will show three LEDs and all will glow white
    7.	Once selected with a double button click, the LEDs will "pulse" in the
        correct colors (above) until the temperature setpoint is achieved.
    8.	Set temperature will be indicated by a solid LED glowing in the 
        specified color
  *
 *  
 */

#ifndef _RGBLedDisplay_H_
#define	_RGBLedDisplay_H_

#ifdef RGBLedDisplay_GLOBALS
#define RGBLedDisplay_EXT
#else
#define RGBLedDisplay_EXT extern
#endif

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/


/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/
void LevelTmpSetShow();    // according the levelTmpSetting show the 
                                  // Temperature setting level
void  turnOffAllLed() ;    // turn off all RGB led .
void HeatProcessLedShow(); // when in heating process, Led shows system's status

#endif   // _RGBLedDisplay_H_


//*****************************************************************************
// END OF FILE
//*****************************************************************************

