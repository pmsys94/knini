#include "knini.h"

llist getinisec(char* filename, int (*listCompareF)(void* key1, void* key2)){
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	llist secstore = newlist(listCompareF);
	if (secstore == NULL){
		fclose(fp);
		return NULL;
	}
	char* readline = NULL;
	int readchars = 0;
	while((readchars = readToRelevant(fp, &readline))){
		if(*readline == '['){
			char* secstr = readline + 1;
			secstr = strndup(secstr, readchars - 2);
			if(addItem(secstore, secstr) == 0){
				free(secstr);
				rmlist(secstore, 1);
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

llist getiniseckeys(char* filename, int (*listCompareF)(void* key1, void* key2), char* secname){
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	llist keystore = newlist(listCompareF);
	if (keystore == NULL){
		fclose(fp);
		return NULL;
	}
	char* readline = NULL;
	int readchars = 0;
	int readKeys = 0;
	while((readchars = readToRelevant(fp, &readline))){
		if(*readline == '['){
			if(readKeys) break;
			char* secstr = readline + 1;
			if(strncmp(secstr, secname, readchars - 2) == 0){
				readKeys++;
			}
		}else if(readKeys){
			char* keystr = strtok(readline, "=");
			for(int count = 1; count <= MAX_ENTRY; count++){
				if(*keystr == '\0'){
					keystr = strdnup(keystr, count);
					break;
				} else {
					keystr++;
				}
			}
			if(addItem(keystore, keystr) == 0){
				free(keystr);
				rmlist(keystore, 1);
				keystore = NULL;
				break;
			}
		}
		free(readline);
		readline = NULL;
	}
	if(readline != NULL) free(readline);
	fclose(fp);
	return keystore;
}

char* inireadvalue(char* section, char* key, char* filename){
	char* valuestr = NULL;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) return NULL;
	char* readline = NULL;
	int readchars = 0;
	int readKeys = 0;
	while((readchars = readToRelevant(fp, &readline))){
		if(*readline == '['){
			if(readKeys) break;
			char* secstr = readline + 1;
			if(strncmp(secstr, section, readchars - 2) == 0){
				readKeys++;
			}
		}else if(readKeys){
			char** valueptr = NULL;
			char* keystr = strtok_r(readline, "=", valueptr);
			if(strcmp(key, keystr) == 0){
				int keychars;
				for(keychars = 1; keychars < MAX_ENTRY; keychars++){
					if(*keystr == '\0'){
						break;
					} else {
						keystr++;
					}
				}
				keychars++;
				valuestr = strndup(*valueptr, readchars - keychars);
				break;
			}
		}
		free(readline);
		readline = NULL;
	}
	if(readline != NULL) free(readline);
	fclose(fp);
	return valuestr;
}
