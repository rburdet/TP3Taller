#ifndef SEARCHER_H
#define SEARCHER_H

//#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "List.h"

class Searcher{
	private:
		std::string fileName;
		List* anIndexList;
	public:
		Searcher(std::string infile, List* aList); 
		//Abre el archivo y busca linea por linea imprimiendo por pantalla 
		//los resultados
		//POST: Devuelve 1 si no existe el archivo o no se puede leer
		//0 en caso contrario
		int search()const;

};

#endif
