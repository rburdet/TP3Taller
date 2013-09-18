#ifndef INDEXER_H
#define INDEXER_H

#include "List.h"
#include "GenericFileIndexer.h"
//ESta clase corre peligro de desaparecer
class Indexer{
	public:
		static void Index(GenericFileIndexer* ,List* );
		std::string getWordToIndex(GenericFileIndexer* );
		bool isIndexable(GenericFileIndexer* ,std::string);
			
};

#endif
