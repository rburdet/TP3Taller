#include "HtmlIndexer.h"

using namespace std;

HtmlIndexer::HtmlIndexer(string fileName, List* aList) : TaggedFileIndexer(fileName,aList){
	this->openTag='<';
	this->closeTag='>';
}


