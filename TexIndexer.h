#ifndef TEXINDEXER_H
#define TEXINDEXER_H

#include "TaggedFileIndexer.h"

class TexIndexer : public TaggedFileIndexer {
	public: 
		TexIndexer(const std::string fileName, List* aList) : TaggedFileIndexer (fileName, aList){
			this->openTag='{';
			this->closeTag='}';
		}
};

#endif
