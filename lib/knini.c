#include "knini.h"

llist getinisec(char* filename){
	FILE fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	llist secstore = newlist(&nocompare);
	if (secstore == NULL){
		free(fp);
		return NULL;
	}
	
	return secstore;
}
