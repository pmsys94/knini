#include "testfuncs.h"

void printSections(char* file){
	#ifdef DEBUG
	fprintf(stderr, "[DEBUG] Print Code for getting Sections out of ini file\n");
	#endif	
	llist sections = getinisec(file, &nocompare);
	if(sections == NULL){
		fprintf(stderr, "[TEST CODE] sections llist is null!!\n");
		return;
	}
	printf("%d sections were read.\n", getItemCount(sections));
	unsigned int num = 1;
	literator it = init_it(sections);
	if(it == NULL){
		fprintf(stderr, "[TEST CODE] llist iterator is null!\n");
	}
	printf("NUM | NAME\n");
	while(hasNext(it)){
		char* secName = (char*)getNext(it);
		printf("%3d | %s\n", num, secName);
		free(secName);
		num++;
	}
	kill_it(it);
	rmlist(sections, 0);
	#ifdef DEBUG
	fprintf(stderr, "[DEBUG] Leaving print sections test\n");
	#endif
}

int nocompare(void* key1, void* key2){
	if(key1 == key2) return 0;
	return 0;
}

void printSecKeys(char* file, char* section){
	#ifdef DEBUG
	fprintf(stderr, "[DEBUG] Print Code for getting Key names for a specific section out of ini file\n");
	#endif
	if(section == NULL){
		printf("Enter target section name: ");
		if(scanf("%ms", &section) == 0) fprintf(stderr, "Error reading input for section name\n");
		printf("Your enter was %s.\n", section);
	}
	llist keys = getiniseckeys(file, &nocompare, section);
	if(keys == NULL){
		fprintf(stderr, "[TEST CODE] keys llist is null!!\n");
		return;
	}
	printf("%d keys were read for section %s.\n", getItemCount(keys), section);
	unsigned int num = 1;
	literator it = init_it(keys);
	if(it == NULL){
		fprintf(stderr, "[TEST CODE] llist iterator is null!\n");
	}
	printf("NUM | NAME\n");
	while(hasNext(it)){
		char* keyName = (char*)getNext(it);
		printf("%3d | %s\n", num, keyName);
		free(keyName);
		num++;
	}
	kill_it(it);
	rmlist(keys, 0);
	#ifdef DEBUG
	fprintf(stderr, "[DEBUG] Leaving Keys of section print test\n");
	#endif
}
