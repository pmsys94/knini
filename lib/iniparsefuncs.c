#include "iniparsefuncs.h"

int readToRelevant(FILE* fp, char** line){
	char buf[MAX_ENTRY] = {'\0'};
	while(fgets(buf, MAX_ENTRY, fp) != NULL){
		if((buf[0] != ';') && (buf[0] != '#') && (isNewLine(buf[0]) == 0))
		{ // found relevant line
			for(int i = 0; i < MAX_ENTRY; i++){
				if(isNewLine(buf[i]) == 1){
					buf[i] = '\0';
					(*line) = strdup(buf);
					return i; // end with succsess - return value is count of read chars
				}
			}
			(*line) = strndup(buf, MAX_ENTRY);
			return MAX_ENTRY; // end with success - but max chars where read
		}
	}
	return 0; // end with error
}

int isNewLine(char c){
	if((c == '\n') || (c == '\r')) return 1;
	return 0;
}
