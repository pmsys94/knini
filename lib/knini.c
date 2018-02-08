#include "knini.h"

llist getinisec(char* filename){
	FILE fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	llist secstore = newlist(&nocompare);
	if (secstore == NULL){
		fclose(fp);
		return NULL;
	}
	char* readline = NULL;
	int readchars = 0;
	while((readchars = readToRelevant(fp, readline))){
		if(*readline == '['){
			char* secstr = readline + 1;
			secstr = strndup(secstr, readchars - 2);
			if(addItem(secstore, secstr) == 0){
				free(secstr);
				rmlist(secstore);
				secstore = NULL;
				break;
			}	
		}
		free(readline);
		readline = NULL;
	}
	if(readline != NULL) free(readline);
	fclose(fp);
	return secstore;
}


