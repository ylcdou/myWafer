
/*
 * File: keyboard.c  
 * Author: Lawrence
 * Created on September 25, 2015, 14:56 PM
 * version 1.0
 * 
 * Comments:
 *     PIC system keyboard related function , look at its .h
 
 * Revision history: 
 
 * Modified: 
 
 * Note:
 *  
 */

#define KEYBOARD_GLOBALS
#include "..\sys\includes.h"

/* 
 *   ProcessButton
 *   process the S2 button pushed event 
 * 
 *   input parameter:  None
 *   return :
 *   for S2 button using:
 *       keyValue = 0 --->  no button pushed
 *                = 1 --->  short pushed 
 *                = 2 --->  double short pushed      
 *  Note:   
 *  0  Using INT0 to get the button pushed and using Timer0 interrupt to get
 *     the pushed time
 *  1  When click the button, the Led display changes completes in this function
 *  2  To every short click, system will have a response, and step into next 
 *     temperature setting. then when next click happens, system will check the 
 *     period between these two clicks, if it short then , < 0.5 (?)S , system
 *     get to know , there is double_click happened, and then delete the first
 *     click record.
 */
uint8 ProcessButton()
{
    uint32 buttonPushPeriod = 0 ;
    
    if ( flagS2KeyPushed )    // whether there is a pushed event happened 
        {
            flagS2KeyPushed = 0 ;   // clear pushed flag , 

            // time between two button pushed raising edge 
            // using it to check if there is a double click
            buttonPushPeriod = buttonPushTimeStop-buttonPushTimeStart ;
                       
           /*====================================================*/
           /* first to see if user want to shut down the machine */
           /*====================================================*/
            if ( S2KeyPushTime < 12 )  // NOTE: here the unit is 0.5S
            {                          // So the turn off setting is 6 Second 
                // it is a short push, then change the temperature setting
                levelTmpSetting ++ ;    // move to next temperature setting
                if ( levelTmpSetting > 3 )
                {
                    levelTmpSetting = 1 ;
                }

                timerHalfSecond = 0 ; // clear timer to wait for be sure that
                                       // there is no next fast push--that is 
                                       // this click is not the first click in
                                       // a double click.
            }
            else
            {
                // Shut down device
                return ( BUTTON_POWER_OFF ) ;  
            }  // end else
            /*---------------------------------------------------*/
            
            /*===================================================*/
            /* Then to see if there is a double click            */
            /*===================================================*/
            if( buttonPushPeriod < 50 )   // period < 0.5S = 50 * 10mS; 
           {
               // it is a fast double pushing
               
               // first delete the first click result
               levelTmpSetting -- ;
               if (levelTmpSetting < 1 )   
               {
                   levelTmpSetting = 3 ;
               }
                 // then delete the second click result 
                 // that is : the first click enter next level
                 //           the second click enter next level
                 // but the last two click is a double click.
                 // So,it will not enter next step, it gonna go into heating.
                 //    so delete this two click stepping in and start heating.
                    levelTmpSetting -- ;
                    if (levelTmpSetting < 1 )   
                    {
                        levelTmpSetting = 3 ;
                    }
               
               LevelTmpSetShow ();
               return ( BUTTON_DOUBLE_CLICK );
            }else
           {
             buttonPushTimeStart = buttonPushTimeStop ;  //
                                                // It was not the double push
                                                // Refresh the button push time 
                                                // Mark this PUSH as the first 
                                                // double_click's PUSH

             return ( BUTTON_SINGLE_CLICK) ;
           }   // end of els
           /*----------------------------------------------------*/
        }  // end if( S2KeyPushTime < 12 )
 
    return ( BUTTON_NO_CLICK );
}  // end  ProcessButton()


//*****************************************************************************
// END OF FILE
//*****************************************************************************
