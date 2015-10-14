/* 
 * File:   keyboard.h
 * Author: Lawrence
 *
 * MCU: PIC18F2420
 * 
 * Created on September 25, 2015 14:56 PM
 * 
 * Comment: in the Wafer board, there is only one button
 *  
 */

#ifndef _KEYBOARD_H_
#define	_KEYBOARD_H_

#ifdef KEYBOARD_GLOBALS
#define KEYBOARD_EXT
#else
#define KEYBOARD_EXT extern
#endif

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
#define BUTTON_POWER_ON         88
#define BUTTON_SINGLE_CLICK     1
#define BUTTON_DOUBLE_CLICK     2
#define BUTTON_POWER_OFF        3
#define BUTTON_NO_CLICK         0

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/
void LevelTmpSetShow();    // according the levelTmpSetting show the 
                                  // Temperature setting level
void  turnOffAllLed() ;            // turn off all RGB led .


#endif   // _KEYBOARD_H_


//*****************************************************************************
// END OF FILE
//*****************************************************************************

