#include <string> 
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "List.h"
#include "GenericFileIndexer.h"
#include "Factory.h"
#include "Searcher.h"
#include "Indexer.h"
#include "Mode.h"
#include "Resumen.h"
#include "Completo.h"

#define RESUMEN 2
#define COMPLETO 1
using std::string;

int main(int argc, char* argv[]){
	int value;
	int mode=COMPLETO;
	int posQ,posD;
	string queries="";
	value = parseArguments(argc,argv,mode,posQ,posD);
	if (value)
		return value;
	List aList;
	Mode* openMode=NULL;
	switch(mode){
		case COMPLETO:
			openMode = new Completo();
			break;
		case RESUMEN:
			openMode = new Resumen();
			break;
	}
	Indexer indexer(string(argv[posD]),&aList);
	indexer.index();
	if (posQ>1)
		queries=string(argv[posQ]);
	Searcher searcher(queries,&aList,openMode);
	value = searcher.search();
	delete openMode;
return value;
}
