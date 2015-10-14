/* 
 * File:   DS18B20.h
 * Author: Lawrence
 *
 * MCU: PIC18F2420
 * 
 * Created on September 19, 2015 10:56 PM
 */

#ifndef _DS18B20_H_
#define	_DS18B20_H_

#ifdef DS18B20_GLOBALS
#define DS18B20_EXT
#else
#define DS18B20_EXT extern
#endif

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

#define TRUE    1
#define FALSE   0  

#define YES     1
#define NO      0     

#define INPUT   1
#define OUTPUT  0

#define ON      1    // in this system , Led = 1 ---> turn on
#define OFF     0

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */
void delay_s(unsigned int x) ;
void delay_ms(unsigned int x) ;
void delay_10us (void) ;

#endif   // _USER_H_


//*****************************************************************************
// END OF FILE
//*****************************************************************************
