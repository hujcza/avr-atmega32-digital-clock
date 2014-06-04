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
// Project of digital clock for avr atmel atmega16l@8MHz
// using of clock 4 digit led display
//
////////////////////////////////////////////////
//
// > "avr-objdump.exe" -h main.elf
//
// main.elf:     file format elf32-avr
//
// Sections:
// Idx Name          Size      VMA       LMA       File off  Algn
//   0 .text         00000f3c  00000000  00000000  00000094  2**1
//                   CONTENTS, ALLOC, LOAD, READONLY, CODE
//   1 .data         00000140  00800060  00000f3c  00000fd0  2**0
//                   CONTENTS, ALLOC, LOAD, DATA
//   2 .bss          00000013  008001a0  008001a0  00001110  2**0
//                   ALLOC
//
// > Process Exit Code: 0
// > Time Taken: 00:00
//
////////////////////////////////////////////////

#include <util/delay.h>
#include <avr/interrupt.h>

#include "keyConfig.h"
#include "display.h"
#include "clockTimer.h"

void main(void){
	
	initializeIODisplay();
	
	keyInit();
	
	clockInit();
	
	sei();
		
	while(1){

		keyTakeOperate();
		
		timeTakeOperate();
		
		multiplexHandler();
		
		_delay_ms(10);
	
	}
	
	return;

}