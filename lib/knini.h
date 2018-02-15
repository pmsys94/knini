#ifndef KNINI_H
#define KNINI_H
#include <stdio.h>
#include <string.h>
#include "libknsll/knsll.h"
#include "iniparsefuncs.h"

#define verKNINI 0.3

// Begin interface function prototypes

	llist getinisec(char* filename, int (*listCompareF)(void* key1, void* key2)); // returns NULL if there was an error || knsll with section name strings
	llist getiniseckeys(char* filename, int (*listCompareF)(void* key1, void* key2), char* secname); // like getinisec - returns NULL if error || knsll with key name strings
	char* inireadvalue(char* section, char* key, char* filename); // returns the value of a specific key of a section or if sth. went wrong a NULL pointer

// end interface function prototypes

#endif
