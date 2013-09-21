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
		GenericFileIndexer* anIndexer = Factory::createIndexer(file,indexList);
		anIndexer->indexFile();
		delete anIndexer;
	}while (file=="");
	
}

string Indexer::getFileToIndex(){
	string actual;
	size_t actualPos = files.find(',');
	size_t nextPos = files.find(',',actualPos+1);
	if (actualPos == string::npos){
		actual= "";
	}else{
		actual = files.substr(0,actualPos);
	} 
	if (nextPos != string::npos )
		this->files = files.substr(actualPos+1,files.size());
	return actual;
}
