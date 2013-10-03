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
		const std::string compFileName;	// El nombre del archivo con extension
		List* indexList;
	public:
		//El estado una vez creado tiene como format a la extension del archivo
		//a fileName al nombre SIN la extension
		//y un file descriptor con el archivo abierto
		GenericFileIndexer(const std::string& fileName,List* indexList);
		//Sirve para ver si el archivo sigue abierto
		//POST: devuelve true si esta abierto, false en caso contrario
		virtual bool isOpen();
		//Transforma palabras a minusculas
		static std::string toLower(const std::string& inString);
		//Destruye el objeto padre
		virtual ~GenericFileIndexer();
		//Indexa el archivo sobre la lista 
		virtual void indexFile()=0;
};

#endif
