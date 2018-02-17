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
			keystr = strdup(keystr);
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
			char* valueptr = NULL;
			char* keystr = strtok_r(readline, "=", &valueptr);
			if(strcmp(key, keystr) == 0){
				valuestr = strdup(valueptr);
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

int iniwritevalue(char* section, char* key, char* value, char* filename){
	llist checklist = NULL;
	char* checkname = NULL;
	int extists = 0; // -2 (0 secs - ), -1 (both no), 0 (sec yes, key no), 1 (both yes)
	if((section == NULL) || (key == NULL) || (value == NULL) || (filename == NULL)) return 0;
	// Check if section already exists
	checklist = getinisec(filename, &namecmp);
	if(checklist == NULL){
		return 0; // ? offen mi r ha nicht funktioniert -datei nicht da?
	} else if(getItemCount(checklist) != 0){
		checkname = searchItem(checklist, section);
	} else {
		return 0;
	}
	rmlist(checklist, 1);
	checklist = NULL;
	if(checkname == NULL){
		exists--;
	} else{
		exists++;
		checkname = NULL;
	}
	// if section was found check if key is existing
	if(exists == 1){
		checklist = getiniseckeys(filename, &namecmp, section);
		checkname = searchItem(checklist, key);
		rmlist(checklist, 1);
		
	}
	
}
