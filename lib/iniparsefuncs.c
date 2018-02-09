#include "iniparsefuncs.h"

int readToRelevant(FILE fp, char* line){
	char buf[MAX_ENTRY] = {'\0'};
	while(fgets(buf, MAX_ENTRY, fp) != NULL){
		if((buf[0] != ';') || (buf[0] != '#') || (!(_isNewLine(buf[0], buf[1]))){ // found relevant line
			for(int i = 0; i < MAX_ENTRY; i++;){
				if(_isNewLine(buf[i], buf[i+1])){
					buf[i] = '\0';
					line = strdup(buf);
					return i+1; // end with succsess - return value is count of read chars
				}
			}
			line = strndup(buf, (MAX_ENTRY - 1));
			return MAX_ENTRY; // end with success - but max chars where read
		}
	}
	return 0; // end with error
}

#if os = tux
int isNewLine(char c){
	if(c == '\n') return 1;
	return 0;
}
#elif os = windows 
int isNewLine(char c1, char c2){
	if(c1 == '\r') && (c2 == '\n') return 1;
	return 0;
}
#elif os = mac
int isNewLine(char c){
	if(c == '\n') || (c == '\r') return 1;
	return 0;
}
#endif
