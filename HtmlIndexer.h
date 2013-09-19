#ifndef HTMLINDEXER_H
#define HTMLINDEXER_H

#include "TaggedFileIndexer.h"

class HtmlIndexer : public TaggedFileIndexer {
	public: 
		HtmlIndexer(const std::string fileName, List* aList);
};

#endif
