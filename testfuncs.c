#include "testfuncs.h"

void printSections(char* file){
	#ifdef DEBUG
	fprintf(stderr, "[DEBUG] Print Code for getting Sections out of ini file\n");
	#endif	
	llist sections = getinisec(file);
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
		printf("%3d | %s\n", num, (char*)getNext(it));
		num++;
	}
	kill_it(it);
	rmlist(sections);
	#ifdef DEBUG
	fprintf(stderr, "[DEBUG] Leaving Sections test\n");
	#endif
}
