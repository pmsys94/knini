#include <stdio.h>
#include <stdlib.h>
#include "testfuncs.h"

void showMenu();
void cmdUsage();

int main(int argc, char* argv[]){
	int freeName = 0;
	char* inifile = NULL;
#ifdef DEBUG
	fprintf(stderr, "[DEBUG] PROGRAM RUNS IN DEBUG MODE !!\n");
	fprintf(stderr, "[DEBUG] Argc = %d\n", argc);
	fprintf(stderr, "[DEBUG] Argv[0]= %s\n", argv[0]);
#endif
	if (argc > 1){ // cmd arg init
		if(argc > 2){
			fprintf(stderr, "To many arguments!\n");
			cmdUsage();
			return 1;
		} else {
			inifile = argv[1];
#ifdef DEBUG
			fprintf(stderr, "[DEBUG] argv[1] = %s\ninifile = %s\n", argv[1], inifile);
#endif
		}
	} else { // normal testprogram init
		printf("Ini file parser test application\n");
		int menupoint = 99;
		do{
			printf("\n\n");
			showMenu();
			printf("choice: ");
			if(scanf("%d", &menupoint) == 0) fprintf(stderr, "Menu choice was not a vaild input\n");
			switch(menupoint){
			case 0:
				break;
			case 1: {
				printf("Please enter fileme: ");
				if(scanf("%ms", &inifile) == 0) fprintf(stderr, "Ini file string can not been read\n");
				freeName++;
				printf("Your enter was: \"%s\"\n", inifile);
				break;
				}
			case 2: {
				printSections(inifile);				
				break;
				}
			default: {
				printf("Input is not a valid menu point!\n");
				}
			}
		}while(menupoint);
	}
#ifdef DEBUG
	if (freeName) 
		fprintf(stderr, "[DEBUG] free -> char* inifile\n");
	else
		fprintf(stderr, "[DEBUG] No free of char* inifile\n");
#endif
	if(freeName) free(inifile);
	return 0;
}

void showMenu(){
	printf(	"[0] - End Application\n"
		"[1] - Enter ini file name to operate on it\n"
		"[2] - Print list of sections\n"
	);
}

void cmdUsage(){
	fprintf(stderr, "Usage of testing application:\n"
			"<app> <ini-file>\n"
			"e.g. <app> mytest.ini\n"
	);
}
