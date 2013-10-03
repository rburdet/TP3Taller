#ifndef SEARCHER_H
#define SEARCHER_H

//#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "List.h"
#include "Mode.h"

class Searcher{
	private:
		std::string fileName;
		List* anIndexList;
		Mode* openMode;
	public:
		Searcher(const std::string& infile, List* aList,Mode* openMode); 
		//Abre el archivo y busca linea por linea imprimiendo por pantalla 
		//los resultados
		//POST: Devuelve 1 si no existe el archivo o no se puede leer
		//0 en caso contrario
		int search()const;
};

#endif
