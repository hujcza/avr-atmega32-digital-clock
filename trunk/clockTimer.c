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

#include <avr/interrupt.h>
#include <math.h>

#include "commonProcs.h"
#include "clockTimer.h"
#include "display.h"
#include "clockSettings.h"

extern int8_t colonStatus;
extern modeType mode;

int8_t timeTab[3] = {0};

int8_t timeWasChange = 0;

void clockInit(void){

	timer1Init();
	
}

void timer1Init(void) {

	//mode ctc
	clrBitAt(TCCR1B,WGM13);
	setBitAt(TCCR1B,WGM12);
	clrBitAt(TCCR1A,WGM11);
	clrBitAt(TCCR1A,WGM10);
		
	//prescaler /256
	setBitAt(TCCR1B,CS12);
	clrBitAt(TCCR1B,CS11);
	clrBitAt(TCCR1B,CS10);
	
	//interrupt on every second
	TCNT1 = 0; OCR1A = 31248;
	
	setBitAt(TIMSK,OCIE1A);
	
}

ISR (TIMER1_COMPA_vect){

		if(mode != normal) return;

		colonStatus = !colonStatus;
	
		if(timeTab[SEC]+1 > 59){
		
			timeWasChange = 1;
			
			if(timeTab[MIN]+1 > 59){
			
				if(timeTab[HOUR]+1 > 23){
				
					timeTab[HOUR] = 0;
				
				} else {
				
					timeTab[HOUR]++;
				
				}
				
				timeTab[MIN] = 0;
			
			} else {
			
				timeTab[MIN]++;
			
			}
			
			timeTab[SEC] = 0;
		
		} else {
	
			timeTab[SEC]++;

		}
		
}

void timeTakeOperate(void){

	if(timeWasChange && mode == normal){
	
		//update digit table for display
		
		divIntegerToDigits(digits,2,timeTab[HOUR]);
	
		divIntegerToDigits(digits+2,2,timeTab[MIN]);
	
	}

}

void divIntegerToDigits(int8_t *tabForDigits, int8_t countOfDigits, int8_t value){
	
	do {
	
		countOfDigits--;
		
		*(tabForDigits+countOfDigits) =
			value % 10;
			
		value /= 10;
	
	} while(countOfDigits);

}

void digitsToTime(int8_t tabOfDigits[], int8_t countOfDigits, int8_t *value){

	int8_t sum = 0;
	
	int counter;
	
	for(counter = 0; counter < countOfDigits; counter++){
	
		sum += tabOfDigits[counter] * pow(10,countOfDigits-1-counter);
	
	}
	
	*value = sum;

}
