#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

//0 si estan todos 2 si hay problemas con -d
//mode 1 es completo, 2 es resumen
char parseArguments(int argc, char*argv[],int &mode,int &posOfQ, int &posOfD);
 
#endif
