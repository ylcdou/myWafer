/* 
 * File:   EEprom.h
 * Author: Lawrence
 * Comments:
 *       MCU: PIC18F2420 for Wafer Vapor project create it.
 * 
 * Revision history: 
 * 
 * Created on September 21, 2015, 9:17 AM
 */


#ifndef _EEPROM_H_
#define	_EEPROM_H_

#ifdef EEPROM_GLOBALS
#define EEPROM_EXT
#else
#define EEPROM_EXT extern
#endif

#define TEMP_SETTING_EEPROM_LOCATION  0



 EEPROM_EXT uint8 cyData ;  
 
 void WriteEEprom( uint8 addr, uint8 data);
 uint8 ReadEEprom( uint8 addr );
        
 
 
#endif

//*****************************************************************************
// END OF FILE
//*****************************************************************************
