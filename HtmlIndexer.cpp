#include "HtmlIndexer.h"

using namespace std;

HtmlIndexer::HtmlIndexer(const string fileName, List* aList) : TaggedFileIndexer(fileName,aList){
	this->openTag='<';
	this->closeTag='>';
}


