#ifndef TXTINDEXER_H
#define TXTINDEXER_H

#include "NormalFileIndexer.h"

class TxtIndexer : public NormalFileIndexer {
	public: 
		TxtIndexer(std::string fileName, List* aList) : NormalFileIndexer(fileName, aList){};
		void indexFile();
};

#endif

