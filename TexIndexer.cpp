#include "TexIndexer.h"

using namespace std;

TexIndexer::TexIndexer(string fileName, List* aList) : TaggedFileIndexer (fileName, aList){
	this->openTag='{';
	this->closeTag='}';
}


