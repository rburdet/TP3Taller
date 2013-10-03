#include <string>
#include "Indexer.h"

using std::string;

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
			Node* aux;
	Node* aux2;

	//Node* aux3;
	//Node* aux4;


	//Imprimir lista:
	//for ( aux=aList->first ; aux!= NULL ; aux = aux->getNextWord() ){
	//	cout << setw(15)<<aux->getData() << " -> " ;
	//	for (aux2=aux->getNextDocument() ; aux2 != NULL ; aux2 = aux2->getNextDocument() ){
	//		cout << setw(10) << aux2->getData() << " -> " ;
	//	}
	//	cout <<endl<<setw(15)<< "|"<< endl;
	//}
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
