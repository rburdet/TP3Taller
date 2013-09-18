#include "Parser.h"
//
//TODO:
//tener en cuenta extension de modos a otros modos
char parseArguments(int argc, char* argv[],char &mode,int &posOfQ,int &posOfd){
	int i,j;
	char c[256];
	char aux;
	for ( i=1 ; i<argc-1 ; i++ ){
		for (j=0 ; argv[i][j]!='\0' ; j++){	
			if (argv[i][j]=='-'){
				if (argv[i][j+1]=='m'){
					mode = 1;
					if ((sscanf(argv[i+1],"%s",c)) && (argv[i+1][0]!='-')){ 
						printf("entre aca \n");
						if (std::string(c)!="completo")
							mode = 2;
					}
				}
				else if ( argv[i][j+1] == 'q' ){
					posOfQ=i+1;
				}
				else if ( argv[i][j+1] == 'd' ){
					posOfd=i+1;
				}
			}
		}
	}
	printf("el mode es: %d\n",mode);
	return 0;
} 
