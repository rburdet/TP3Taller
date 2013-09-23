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

using std::string;

int main(int argc, char* argv[]){
	int value;
	int mode=1;
	int posQ,posD;
	string queries="";
	value = parseArguments(argc,argv,mode,posQ,posD);
	if (value)
		return value;
	List* aList = new List();
	Mode* openMode=NULL;
	switch(mode){
		case 1:
			openMode = new Completo();
			break;
		case 2:
			openMode = new Resumen();
			break;
	}
	Indexer* indexer = new Indexer(string(argv[posD]),aList);
	indexer->index();
	delete indexer;
	if (posQ>1)
		queries=string(argv[posQ]);
	Searcher* searcher = new Searcher(queries,aList,openMode);
	value = searcher->search();
	delete aList;
	delete searcher;
	delete openMode;
return value;
}
