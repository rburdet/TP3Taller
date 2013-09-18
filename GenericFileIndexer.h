//por cada archivo a indexar va a haber una instancia distinta heredera
//de esta clase
#ifndef GENERIC_FORMAT_H
#define GENERIC_FORMAT_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "List.h"

class GenericFileIndexer{
	protected:
		std::ifstream file;
		std::string format;		//Solo lleva la extension (sin el . )
		std::string redFileName;	// El nombre del archivo sin extension
		std::string compFileName;	// El nombre del archivo con extension
		List* indexList;
	public:
		//El estado una vez creado tiene como format a la extension del archivo
		//a fileName al nombre SIN la extension
		//y un file descriptor con el archivo abierto
		GenericFileIndexer(std::string fileName,List* indexList);
		virtual std::string toLower(std::string inString);
		virtual ~GenericFileIndexer();
		virtual void indexFile()=0;
};

#endif