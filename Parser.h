#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string>

//0 si estan todos 2 si hay problemas con -d
//mode 1 es completo, 2 es resumen
char parseArguments(int argc, char*argv[],char &mode,int &posOfQ, int &posOfD);
 
#endif
