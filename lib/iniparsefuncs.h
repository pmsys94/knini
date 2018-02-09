#ifndef INIPARSEFUNCS_H
#define INIPARSEFUNCS_H

#define 0.1

#include "osmak.h"

#if os = tux
#define _isNewLine(a,b) isNewLine(a)
#elif os = windows
#define _isNewLine(a,b) isNewLine(a,b)
#elif os = mac
#define _isNewLine(a,b) isNewLine(a)
#else
#error "OS makro not specified"
#endif

#include <string.h>

	enum {MAX_ENTRY = 1024};
	int readToRelevant(FILE fp, char* line); // reads a line and if it is relevant it copies the line with strdup!
	// check if char(s) mark a newline -> OS specific; controlled by makro os
	#if os = tux
	int isNewLine(char c);
	#elif os = windows 
	int isNewLine(char c1, char c2);
	#elif os = mac
	int isNewLine(char c);
	#endif
	// end newline check funtion deklarations
#endif
