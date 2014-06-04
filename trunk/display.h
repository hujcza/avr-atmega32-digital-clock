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

#ifndef _display_h
#define _display_h 

int8_t digits[4];

int8_t colonStatus;

int8_t multiplexStatus;

uint32_t displayMatrix;

uint32_t displayMatrixByDigit0[4][10];

uint32_t displayMatrixByDigit1[4][10];

#define setMatrixAt(bitNum){\
\
	displayMatrix |= (uint32_t)1 << bitNum;\
\
}

#define setOutputDependOf(dependBoolean,port,pin){\
\
	if(dependBoolean)\
		port |= 1 << pin;\
	else\
		port &= ~(1 << pin);\
\
}

#define setIOLineDependOf(dependBoolean,ddr,pin){\
\
	setOutputDependOf(dependBoolean,ddr,pin);\
\
}	

void initializeIODisplay(void);

void multiplexHandler(void);

void turnDigit(int8_t digitNum, int8_t digitValue);

void turnColon(int8_t onOff);

void applyDisplayMatrix(void);

#endif