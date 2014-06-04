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

#ifndef _COMMON_PROCS_H
#define _COMMON_PROCS_H

#define setBitAt(port,index) ( port |= 1 << index )

#define clrBitAt(port,index) ( port &= ~(1<<index) )

#define setBitDependOf(booleanValue,port,index) ( (booleanValue) ?\
	setBitAt(port,index) : clrBitAt(port,index) )

#endif /* _COMMON_PROCS_H */