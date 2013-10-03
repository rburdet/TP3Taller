#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include "List.h"
#include "GenericFileIndexer.h"
#include "Factory.h"

//Clase encargada de hacer las indexaciones
class Indexer{
	private:
		std::string files;
		List* indexList;
	public:
		//Crea el indexador con la lista de archivos a indexar y una lista
		//donde se van a hacer las indexaciones
		Indexer(std::string listOfFiles,List*);
		//Hace la indexaciones
		void index();
		//Devuelve un archivo a indexar
		std::string getFileToIndex();	
};

#endif
