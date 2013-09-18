#include "Parser.h"

using namespace std;

//TODO:
//tener en cuenta extension de modos a otros modos
char parseArguments(int argc, char* argv[],char &mode,int &posOfQ,int &posOfd){
	int i,j;
	char aux;
	posOfQ=-1;
	posOfd=-1;
	string modeName;
	//Desde el segundo argumento hasta el final
	for ( i=1 ; i<argc-1 ; i++ ){
		// Para cada palabra
		for (j=0 ; argv[i][j]!='\0' ; j++){	
			if (argv[i][j]=='-'){
				//por default es completo
				if (argv[i][j+1]=='m'){
					mode = 1;
					modeName=string(argv[i+1]);
					if (argv[i+1][0]!='-'){ 
						printf("entre aca \n");
							mode = 2;
					}
				}
				else if ( ( argv[i][j+1] == 'q' ) && ( argv[i+1][0]!='-' ) ){
					posOfQ=i+1;
				}
				else if ( argv[i][j+1] == 'd' ){
					posOfd=i+1;
				}
			}
		}
	}
	if ( ( posOfd < 1 ) || ( argv[posOfd] == NULL ) || ( argv[posOfd][0] =='-' ) )
		return 2;
	return 0;
} 
