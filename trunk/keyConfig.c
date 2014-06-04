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
#include <avr/io.h>

#include "commonProcs.h"
#include "keyConfig.h"
#include "display.h"
#include "clockSettings.h"

#define modeInput				PIND
#define modePin 				PD5
#define modeDir					DDRD
#define checkModeButton \
	!(modeInput & ( 1 << modePin))

#define changeValueInput		PIND
#define changeValuePin 			PD3
#define changeValueDir			DDRD
#define checkChangeValueButton \
	!(changeValueInput & ( 1 << changeValuePin))

uint8_t modePressed = 0;
uint8_t changeValuePressed = 0;

void keyInit(void) {

	clrBitAt(modeDir,modePin);
	clrBitAt(changeValueDir,changeValuePin);

	timer0Init();

}

void timer0Init(void) {

	//mode normal
	clrBitAt(TCCR0,WGM00);
	clrBitAt(TCCR0,WGM01);

	//normal port operation, oc0 disconnected
	clrBitAt(TCCR0,COM00);
	clrBitAt(TCCR0,COM01);
	
	//prescaler /256
	setBitAt(TCCR0,CS02);
	clrBitAt(TCCR0,CS01);
	clrBitAt(TCCR0,CS00);
	
	TCNT0 = 0;
	
	//allowed to interrupt at overflow
	setBitAt(TIMSK,TOIE0);
	
}

ISR (TIMER0_OVF_vect){

	static uint8_t modeHistory = 0;
	static uint8_t changeValueHistory = 0;
	 
	modeHistory <<= 1;
	changeValueHistory <<= 1;
	
	setBitDependOf(checkModeButton,modeHistory,0);
	setBitDependOf(checkChangeValueButton,changeValueHistory,0);
	
	if(modeHistory == 0x7F){
		
		modePressed = 1;
		
	}
	
	if(changeValueHistory == 0x7F){
		
		changeValuePressed = 1;
		
	}
	
}

void keyTakeOperate(void){

	if(modePressed){
		
		modePressed = 0;
		
		changeMode();
		
	}
		
	if(changeValuePressed){
		
		changeValuePressed = 0;
		
		changeValueProc();

	}
		
}