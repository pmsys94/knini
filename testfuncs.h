#ifndef TESTFUNCS_H
#define TESTFUNCS_H

#include <stdio.h>
#include "lib/knini.h"
#include "lib/knsll/knsll.h"

	void printSections(char* file);
	int nocompare(void* key1, void* key2);
	void printSecKeys(char* file, char* section);

#endif
