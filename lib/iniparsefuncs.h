#ifndef INIPARSEFUNCS_H
#define INIPARSEFUNCS_H

#define verIPF 0.2

#include "osmak.h"
#include <stdio.h>

#include <string.h>

	enum {MAX_ENTRY = 1024};
	int readToRelevant(FILE* fp, char** line); // reads a line and if it is relevant it copies the line with strdup!
	int isNewLine(char c); // check if c is a newline byte OR (for Windows) is a carriage return byte
	// end newline check funtion deklarations
#endif
