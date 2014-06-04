////////////////////////////////////////////////
//
// Author: Arkadiusz Kiciak (WITS)
// City: Gdansk POLAND
// Date: 18 May 2014
// License: GPLV3
//
////////////////////////////////////////////////
//
// Feel free to redistributing this code but never
// forget to add original place where you found this
// Thanks!!!
//
////////////////////////////////////////////////

#include "clockSettings.h"
#include "display.h"
#include "clockTimer.h"

modeType mode = normal;

extern int8_t digits[4];

extern int8_t timeTab[3];

void changeMode(void){

	mode++;
	
	if(mode>settingTimeDigit4){
	
		timeTab[SEC] = 0;
		
		digitsToTime(digits,2,&timeTab[HOUR]);
		
		digitsToTime(digits+2,2,&timeTab[MIN]);
		
		mode = normal;
	
	}

}

void changeValueProc(void){

	switch(mode){
	
		case normal:
		
			break;
			
		case settingTimeDigit1:
		
			if(digits[0]>=2){
			
				digits[0] = 0;
			
			} else {
			
				digits[0]++;
				
			}
			
			break;
			
		case settingTimeDigit2:
		
			if(digits[0]>=2){
			
				if(digits[1]>=3){
				
					digits[1] = 0;
				
				} else {
				
					digits[1]++;
					
				}
			
			} else {
			
				if(digits[1]>=9){
				
					digits[1] = 0;
				
				} else {
				
					digits[1]++;
					
				}

			}
			
			break;
		
		case settingTimeDigit3:
		
			if(digits[2]>=5){
			
				digits[2] = 0;
			
			} else {
			
				digits[2]++;
				
			}
			
			break;
			
		case settingTimeDigit4:
	
			if(digits[3]>=9){
			
				digits[3] = 0;
			
			} else {
			
				digits[3]++;
				
			}
			
			break;
	
	}

}