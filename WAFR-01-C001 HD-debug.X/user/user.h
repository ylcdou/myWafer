/* 
 * File:   user.h
 * Author: Lawrence
 *
 * MCU: PIC18F2420
 * 
 * Created on September 16, 2015
 */

#ifndef _USER_H_
#define	_USER_H_

#ifdef USER_GLOBALS
#define USER_EXT
#else
#define USER_EXT extern
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
void delay_s(unsigned int  x) ;
void delay_ms(unsigned int x) ;
void delay_10us(void);

#endif   // _USER_H_


//*****************************************************************************
// END OF FILE
//*****************************************************************************
