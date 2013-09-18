#ifndef HTMLINDEXER_H
#define HTMLINDEXER_H

#include "TaggedFileIndexer.h"

class HtmlIndexer : public TaggedFileIndexer {
	public: 
		HtmlIndexer(std::string fileName, List* aList);
		//void indexFile();
		//void untag(std::string& line);
};

#endif
