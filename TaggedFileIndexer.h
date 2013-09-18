#ifndef TAGGED_FILE_INDEXER_H
#define TAGGED_FILE_INDEXER_H

#include "NormalFileIndexer.h"

class TaggedFileIndexer : public NormalFileIndexer {
	protected:
		char openTag;
		char closeTag;
	public: 
		TaggedFileIndexer(std::string fileName, List* aList) : NormalFileIndexer(fileName, aList){};
		virtual void untag(std::string& line);
		virtual void indexFile();
};

#endif
