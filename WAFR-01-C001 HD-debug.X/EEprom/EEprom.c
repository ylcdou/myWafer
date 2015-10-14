/*
 * File: EEprom.c  
 * Author: Lawrence
 * Created on September 21, 2015, 9:20 AM
 * version 1.0
 * 
 * Comments:
 *    MCU: PIC18F2420 for Wafer Vapor project create it.
 *    EEprom related function
 *    Five SFPs are used to read and write to the data EEPROM as well as the 
 *    program memory. they are:
 *      EECON1
 *      EECON2
 *      EEDATA
 *      EEADR

 * Name	Bit 7	   Bit 6        Bit 5	Bit 4	Bit 3	Bit 2	Bit 1	Bit 0	
INTCON	GIE/GIEH   PEIE/GIEL	TMR0IE	INT0IE	RBIE	TMR0IF	INT0IF	RBIF	
EEADR	EEPROM Address Register						
EEDATA	EEPROM Data Register						
EECON2	EEPROM Control Register 2 (not a physical register)
EECON1	EEPGD      CFGS     	?      FREE 	WRERR	WREN	WR	    RD	
IPR2	OSCFIP     CMIP     	?      EEIP    BCLIP	HLVDIP	TMR3IP	CCP2IP	
PIR2	OSCFIF     CMIF     	?      EEIF    BCLIF	HLVDIF	TMR3IF	CCP2IF	
PIE2	OSCFIE     CMIE     	?      EEIE    BCLIE	HLVDIE	TMR3IE	CCP2IE	
 * 
 * Revision history: 
 *
 * Modified: 
 *
 * Note:
 *  
 */

#define EEPROM_GLOBALS
#include "..\sys\includes.h"


/*
 * WriteEEprom
 * comment:  write one byte data into EEprom
 * 
 * Parameter : addr = address of EEprom to write into
 *             data = data gonna be wrote into EEprom
 * return : no
 */
void WriteEEprom ( uint8 addr, uint8 data )
{
    do{}
    while( EECON1bits.WR ) ; // waiting for writing finished
    
    EEADR = addr ;              // address be written to the EEADR register.
    EEDATA = data ;             // data written to the EEDATA register
    EECON1bits.EEPGD = 0 ;      //  0 = Access EEprom
                                //  1 = Access Flash program memory
    EECON1bits.WREN  = 1 ;      //  1 = Enable write cycles to Flash program/data EEprom
                                //  0 = Inhibits write cycles to Flash program/data EEprom
    
    INTCONbits.GIE = 0 ;       // Disable interrupts. must!!!
    EECON2 = 0X55;
    EECON2 = 0XAA;             // must have this sequence before set WR bit
    EECON1bits.WR   = 1 ;      // begin write
    INTCONbits.GIE = 1 ;       // Enable interrupts. must!!!
    
    do{}
    while( EECON1bits.WR) ;    // wait for completion
    EECON1bits.WREN = 0 ;      // Disable writes on write complete (EEIF set))
}


/*
 * ReadEEprom
 * comment:  read one byte from EEprom
 *
 * Parameter: addr = data's address to be read
 * 
 * return: the data be read
 */
uint8 ReadEEprom( uint8 addr )
{
    do{}
    while( EECON1bits.RD ) ; // wait for reading complete
    
    EEADR = addr ;          // the address of EEprom to be read
    EECON1bits.EEPGD = 0 ;      //  0 = Access EEprom
                                //  1 = Access Flash program memory
    EECON1bits.RD = 1 ;         // read EEprom
    do{}
    while ( EECON1bits.RD )  ; //waiting for complete
    
    return( EEDATA );           // return data
}

//*****************************************************************************
// END OF FILE
//*****************************************************************************
