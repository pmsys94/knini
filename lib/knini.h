#ifndef KNINI_H
#define KNINI_H
#include <stdio.h>
#include <string.h>
#include "knsll/knsll.h"
#include "iniparsefuncs.h"

#define verKNINI 0.2

// Begin interface function prototypes

	llist getinisec(char* filename, int (*listCompareF)(void* key1, void* key2)); // returns -1 if there was an error || number of found sctions

// end interface function prototypes

#endif
