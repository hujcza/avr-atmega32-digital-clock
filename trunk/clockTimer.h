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

#ifndef clockTimer_h
#define clockTimer_h

#include <stdint.h>

enum timePart {HOUR = 0, MIN, SEC};

void clockInit(void);

void timer1Init(void);

void timeTakeOperate(void);

void divIntegerToDigits(int8_t *tabForDigits, int8_t countOfDigits, int8_t value);

void digitsToTime(int8_t tabOfDigits[], int8_t countOfDigits, int8_t *value);

#endif