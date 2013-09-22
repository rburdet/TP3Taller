#include "Indexer.h"

using namespace std;

Indexer::Indexer(string fileList, List* aList){
	this->indexList = aList;
	this->files = fileList;
}

void Indexer::index(){
	string file;
	do{
		file = getFileToIndex();
		if (file!=""){
			GenericFileIndexer* anIndexer = Factory::createIndexer(file,indexList);
			if (anIndexer!=NULL)
				anIndexer->indexFile();
			delete anIndexer;
		}
	}while (file.size()!=0);
	
}

string Indexer::getFileToIndex(){
	string actual;
	size_t actualPos = files.find(',');
	actual = "";
	if (this->files.size()>0){
		actual = files.substr(0,actualPos);
		this->files = files.substr(actualPos+1,files.size());
		if (actualPos==string::npos)
			this->files="";
	}
	return actual;
}
