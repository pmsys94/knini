#ifndef INIPARSEFUNCS_H
#define INIPARSEFUNCS_H

#define 0.1

#define tux 2
#define windows 4
#define os = tux

#if os = tux
#define _isNewLine(a,b) isNewLine(a)
#elif os = windows
#define _isNewLine(a,b) isNewLine(a,b)
#endif

#include <string.h>

	enum {MAX_ENTRY = 1024};
	int readToRelevant(FILE fp, char* line); // reads a line and if it is relevant it copies the line with strdup!
	// check if char(s) mark a newline -> OS specific; controlled by makro os
	#if os = tux
	int isNewLine(char c);
	#elif os = windows 
	int isNewLine(char c1, char c2);
	#endif
	// end newline check funtion deklarations
#endif
