#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include "List.h"
#include "GenericFileIndexer.h"
#include "Factory.h"

//ESta clase corre peligro de desaparecer
class Indexer{
	private:
		std::string files;
		List* indexList;
	public:
		Indexer(std::string listOfFiles,List*);
		void index();
		std::string getFileToIndex();	
};

#endif
