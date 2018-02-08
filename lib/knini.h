#ifndef KNINI_H
#define KNINI_H
#include "iniparsefuncs.h"

#define ver 0.1

// Begin interface function prototypes

	int getinisec(char* filename, unsigned int max, char* sections[]); // returns -1 if there was an error || number of found sctions

// end interface funtion prototypes

#endif
