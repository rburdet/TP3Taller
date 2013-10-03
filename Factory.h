#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include "GenericFileIndexer.h"
#include "TexIndexer.h"
#include "HtmlIndexer.h"
#include "List.h"

//Clase usada para crear instancias de otras clases siguiendo un patron
//Factory
class Factory{
	public:
		//Crea un heredero de GenericFileIndexer dependiendo de la extension
		static GenericFileIndexer* createIndexer(std::string& fileName, List* list);
};


#endif
