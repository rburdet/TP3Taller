#ifndef HTMLINDEXER_H
#define HTMLINDEXER_H

#include <string>
#include "TaggedFileIndexer.h"

class HtmlIndexer : public TaggedFileIndexer {
	public: 
		HtmlIndexer(const std::string fileName, List* aList) :
			TaggedFileIndexer(fileName,aList){
		this->openTag='<';
		this->closeTag='>';
		}
};

#endif
