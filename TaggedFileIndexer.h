#ifndef TAGGED_FILE_INDEXER_H
#define TAGGED_FILE_INDEXER_H

#include <string>
#include "NormalFileIndexer.h"

class TaggedFileIndexer : public NormalFileIndexer {
	private:
		char openTag;
		char closeTag;
	public: 
		TaggedFileIndexer(const std::string& fileName, List* aList,char oT,char cT) :
			NormalFileIndexer(fileName, aList){
				this->openTag=oT;
				this->closeTag=cT;
			}
		virtual void untag(std::string& line);
};

#endif
