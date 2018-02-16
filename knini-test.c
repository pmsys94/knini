#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		if(argc == 2){
			fprintf(stderr, "To less arguments!\n");
			cmdUsage();
			return 1;
		} else if(argc > 5){
			fprintf(stderr, "To many arguments!\n");
			cmdUsage();
			return 1;
		} else {
			inifile = argv[2];
#ifdef DEBUG
			fprintf(stderr, "[DEBUG] argv[1] = %s\n", argv[1]);
			fprintf(stderr, "[DEBUG] argv[2] = %s\n-> inifile = %s\n", argv[2], inifile);
			for (int args = 4; args <= argc; args++){
				fprintf(stderr, "[DEBUG] argv[%d] = %s\n", args-1, argv[args-1]);
			}
#endif
			if(strcmp(argv[1], "psections\0") == 0){
				printSections(inifile);
			} else if(strcmp(argv[1], "pseckeys\0") == 0){
				if(argc == 3){
					printSecKeys(inifile, NULL);
				}else if(strcmp(argv[3], "NULL\0") == 0){
					printSecKeys(inifile, NULL);
				} else {
					printSecKeys(inifile, argv[3]);
				}
			} else if(strcmp(argv[1], "pkeyval\0") == 0){
				if(argc == 3){
					printKeyVal(inifile, NULL, NULL);
				} else if(strcmp(argv[3], "NULL\0") == 0){
					printKeyVal(inifile, NULL, NULL);
				} else if(argc == 5){
					printKeyVal(inifile, argv[3], argv[4]);
				} else {
					fprintf(stderr, "pkeyval needs Section name and key name!\n");
					cmdUsage();
					return 1;
				}
			} else {
				fprintf(stderr, "Paramater 1 '%s' was not a valid action!\n", argv[1]);
				cmdUsage();
				return 1;
			}
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
			case 3: {
				printSecKeys(inifile, NULL);
				break;
				}
			case 4: {
				printKeyVal(inifile, NULL, NULL);
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
		"[3] - Print list of key names of a specified section name\n"
		"[4] - Print a Value of a key to a given section name\n"
	);
}

void cmdUsage(){
	fprintf(stderr, "Usage of testing application:\n"
			"<app> <action> <ini-file> [<action-parmater>]\n"
			"Actions are:\n"
			"psections - <void>\n"
			"pseckeys - <section-name> | NULL (as word)\n"
			"pkeyval - (section-name> <key-name>) | NULL (as word)\n"
			"e.g. <app> psections mytest.ini\n"
	);
}
