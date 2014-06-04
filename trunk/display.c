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
//
// Driver for 4 digits led display clock module with
// common two multiplexed cathodes
//
// For module:
// fttl655s
// ltc-637d1g
// or similar - only 24h
//
////////////////////////////////////////////////
//
// For configuring example check initializeIODisplay body
//
////////////////////////////////////////////////

#include <util/delay.h>
#include <avr/io.h>

#include "display.h"

uint32_t displayMatrixByDigit0[4][10] = {{

0b00000000000000000000000000000000,//0,0//
0b00000000000000000000000000000000,//0,1
0b00000011000000000000000000000000,//0,2
0b00000011000000000000000000000000,//0,3//
0b00000000000000000000000000000000,//0,4//
0b00000011000000000000000000000000,//0,5//
0b00000011000000000000000000000000,//0,6//
0b00000010000000000000000000000000,//0,7//
0b00000011000000000000000000000000,//0,8//
0b00000011000000000000000000000000 //0,9//

},{

0b00000000100110000000000000000000,//1,0
0b00000000000000000000000000000000,//1,1
0b00000000110100000000000000000000,//1,2
0b00000000010100000000000000000000,//1,3
0b00000000010010000000000000000000,//1,4
0b00000000010110000000000000000000,//1,5
0b00000000110110000000000000000000,//1,6
0b00000000000000000000000000000000,//1,7
0b00000000110110000000000000000000,//1,8
0b00000000010110000000000000000000 //1,9

},{

0b00000000000000111000000000000000,//2,0
0b00000000000000011000000000000000,//2,1
0b00000000000000110000000000000000,//2,2
0b00000000000000111000000000000000,//2,3
0b00000000000000011000000000000000,//2,4
0b00000000000000101000000000000000,//2,5
0b00000000000000101000000000000000,//2,6
0b00000000000000111000000000000000,//2,7
0b00000000000000111000000000000000,//2,8
0b00000000000000111000000000000000 //2,9

},{

0b00000000000000000101100000000000,//3,0
0b00000000000000000000000000000000,//3,1
0b00000000000000000111000000000000,//3,2
0b00000000000000000011000000000000,//3,3
0b00000000000000000010100000000000,//3,4
0b00000000000000000011100000000000,//3,5
0b00000000000000000111100000000000,//3,6
0b00000000000000000000000000000000,//3,7
0b00000000000000000111100000000000,//3,8
0b00000000000000000011100000000000 //3,9

}};

uint32_t displayMatrixByDigit1[4][10] = {{

0b00000000000000000000000000000000,//0,0//
0b00000100100000000000000000000000,//0,1
0b00000111000000000000000000000000,//0,2
0b00000110100000000000000000000000,//0,3//
0b00000110100000000000000000000000,//0,4//
0b00000010100000000000000000000000,//0,5//
0b00000011100000000000000000000000,//0,6//
0b00000100100000000000000000000000,//0,7//
0b00000111100000000000000000000000,//0,8//
0b00000110100000000000000000000000,//0,9//

},{

0b00000000010110000000000000000000,//1,0
0b00000000010100000000000000000000,//1,1
0b00000000010010000000000000000000,//1,2
0b00000000010110000000000000000000,//1,3
0b00000000010100000000000000000000,//1,4
0b00000000000110000000000000000000,//1,5
0b00000000000110000000000000000000,//1,6
0b00000000010110000000000000000000,//1,7
0b00000000010110000000000000000000,//1,8
0b00000000010110000000000000000000,//1,9

},{

0b00000000000000101100000000000000,//2,0
0b00000000000000000000000000000000,//2,1
0b00000000000000011100000000000000,//2,2
0b00000000000000011000000000000000,//2,3
0b00000000000000110000000000000000,//2,4
0b00000000000000111000000000000000,//2,5
0b00000000000000111100000000000000,//2,6
0b00000000000000000000000000000000,//2,7
0b00000000000000111100000000000000,//2,8
0b00000000000000111000000000000000,//2,9

},{

0b00000000000000000011100000000000,//3,0
0b00000000000000000011000000000000,//3,1
0b00000000000000000010100000000000,//3,2
0b00000000000000000011100000000000,//3,3
0b00000000000000000011000000000000,//3,4
0b00000000000000000001100000000000,//3,5
0b00000000000000000001100000000000,//3,6
0b00000000000000000011100000000000,//3,7
0b00000000000000000011100000000000,//3,8
0b00000000000000000011100000000000,//3,9

}};

void initializeIODisplay(void){

	int counter;
		
	for(counter = 31; counter >= 0; counter--){
		
		switch(counter){
		
			case 31://pin1
			
				setIOLineDependOf(1,DDRD,PD6);
				
				break;
				
			case 30://pin2
			
				setIOLineDependOf(1,DDRC,PC0);
				
				break;
				
			case 26://pin6 
			
				setIOLineDependOf(1,DDRC,PC1);
				
				break;
				
			case 25://pin7
			
				setIOLineDependOf(1,DDRC,PC2);
				
				break;
				
			case 24://pin8
			
				setIOLineDependOf(1,DDRC,PC3);
				
				break;
				
			case 23://pin9
			
				setIOLineDependOf(1,DDRC,PC4);
				
				break;
				
			case 22://pin10
			
				setIOLineDependOf(1,DDRC,PC5);
				
				break;
				
			case 20://pin12
			
				setIOLineDependOf(1,DDRC,PC6);
				
				break;
				
			case 19://pin13
			
				setIOLineDependOf(1,DDRC,PC7);
				
				break;
				
			case 18://pin14
			
				setIOLineDependOf(1,DDRA,PA7);
				
				break;
				
			case 17://pin15
			
				setIOLineDependOf(1,DDRA,PA6);
				
				break;
				
			case 16://pin16
			
				setIOLineDependOf(1,DDRA,PA5);
				
				break;
				
			case 15://pin17
			
				setIOLineDependOf(1,DDRA,PA4);
				
				break;
				
			case 14://pin18
			
				setIOLineDependOf(1,DDRA,PA3);
				
				break;
				
			case 13://pin19
			
				setIOLineDependOf(1,DDRA,PA2);
				
				break;
				
			case 12://pin20
			
				setIOLineDependOf(1,DDRA,PA1);
				
				break;

			case 11://pin21
			
				setIOLineDependOf(1,DDRD,PD7);
				
				break;
				
			case 2://pin30
			
				setIOLineDependOf(1,DDRA,PA0);
				
				break;
				
			default:
			
				break;
			
		}
		
	}
				
	multiplexStatus = 0;
	
}

void multiplexHandler(void){
	
	multiplexStatus = !multiplexStatus;
	
	displayMatrix = 0;
	
	turnDigit(0,digits[0]);

	turnDigit(1,digits[1]);

	turnDigit(2,digits[2]);
	
	turnDigit(3,digits[3]);
	
	turnColon(colonStatus);
	
	applyDisplayMatrix();
	
};

void turnDigit(int8_t digitNum, int8_t digitValue){

	if(!multiplexStatus){
	
		setMatrixAt(31);
		
		displayMatrix |=
			displayMatrixByDigit0[digitNum][digitValue];
	
	} else {

		setMatrixAt(30);

		displayMatrix |=
			displayMatrixByDigit1[digitNum][digitValue];
	
	}
	
}

void turnColon(int8_t onOff){

	if(onOff)
	
		setMatrixAt(2);

}

void applyDisplayMatrix(void){

	int counter; uint32_t booleanValue;
		
	for(counter = 31; counter >= 0; counter--){

		booleanValue = displayMatrix & ((int32_t)1 << counter);
		
		switch(counter){
		
			case 31://pin1
			
				setOutputDependOf(booleanValue,PORTD,PD6);
				
				break;
				
			case 30://pin2
			
				setOutputDependOf(booleanValue,PORTC,PC0);
				
				break;
				
			case 26://pin6 
			
				setOutputDependOf(booleanValue,PORTC,PC1);
				
				break;
				
			case 25://pin7
			
				setOutputDependOf(booleanValue,PORTC,PC2);
				
				break;
				
			case 24://pin8
			
				setOutputDependOf(booleanValue,PORTC,PC3);
				
				break;
				
			case 23://pin9
			
				setOutputDependOf(booleanValue,PORTC,PC4);
				
				break;
				
			case 22://pin10
			
				setOutputDependOf(booleanValue,PORTC,PC5);
				
				break;
				
			case 20://pin12
			
				setOutputDependOf(booleanValue,PORTC,PC6);
				
				break;
				
			case 19://pin13
			
				setOutputDependOf(booleanValue,PORTC,PC7);
				
				break;
				
			case 18://pin14
			
				setOutputDependOf(booleanValue,PORTA,PA7);
				
				break;
				
			case 17://pin15
			
				setOutputDependOf(booleanValue,PORTA,PA6);
				
				break;
				
			case 16://pin16
			
				setOutputDependOf(booleanValue,PORTA,PA5);
				
				break;
				
			case 15://pin17
			
				setOutputDependOf(booleanValue,PORTA,PA4);
				
				break;
				
			case 14://pin18
			
				setOutputDependOf(booleanValue,PORTA,PA3);
				
				break;
				
			case 13://pin19
			
				setOutputDependOf(booleanValue,PORTA,PA2);
				
				break;
				
			case 12://pin20
			
				setOutputDependOf(booleanValue,PORTA,PA1);
				
				break;

			case 11://pin21
			
				setOutputDependOf(booleanValue,PORTD,PD7);
				
				break;
				
			case 2://pin30
			
				setOutputDependOf(booleanValue,PORTA,PA0);
				
				break;
				
			default: //rest of 32bit integer
					//and other never used pins
			
				break;
		
		}
	
	}

}