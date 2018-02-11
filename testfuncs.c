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
	rmlist(sections);
	#ifdef DEBUG
	fprintf(stderr, "[DEBUG] Leaving Sections test\n");
	#endif
}

int nocompare(void* key1, void* key2){
	if(key1 == key2) return 0;
	return 0;
}
