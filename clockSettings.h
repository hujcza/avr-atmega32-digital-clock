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

#ifndef clockSetting_h
#define clockSetting_h

#include <stdint.h>

typedef enum modeEnum { normal, settingTimeDigit1,
	settingTimeDigit2, settingTimeDigit3,
		settingTimeDigit4 } modeType;
		
modeType mode;

void changeMode(void);

void changeValueProc(void);

#endif