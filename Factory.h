#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include "GenericFileIndexer.h"
#include "TxtIndexer.h"
#include "HtmlIndexer.h"
#include "TexIndexer.h"
#include "List.h"
class Factory{
	public:
		static GenericFileIndexer* createIndexer(std::string fileName, List* list);
};


#endif
