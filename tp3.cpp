#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "List.h"
#include "GenericFileIndexer.h"
#include "Factory.h"
#include "Searcher.h"
#include "Indexer.h"

using namespace std;

int main(int argc, char* argv[]){
	int value;
	char mode;
	int posQ,posD;
	List* aList = new List();
	string queries = "";
	value = parseArguments(argc,argv,mode,posQ,posD);
	//cout <<"el modo es: "<<(int)mode<< "\b posQ es: "<<posQ<<" posD es: "<<posD<<endl;
	if (value)
		return value;
	Indexer* indexer = new Indexer(string(argv[posD]),aList);
	indexer->index();
	//GenericFileIndexer* anIndexer ;
	//GenericFileIndexer* anIndexer2 ;
	//GenericFileIndexer* anIndexer3;
	//anIndexer = Factory::createIndexer("PROBANDO/text.txt",aList);
	//anIndexer2 = Factory::createIndexer("PROBANDO/latextext.tex",aList);
	//anIndexer3 = Factory::createIndexer("PROBANDO/htmltext.html",aList);
	if (posQ>1)
		queries=string(argv[posQ]);
	Searcher* searcher = new Searcher(queries,aList);

	//anIndexer->indexFile();
	//anIndexer2->indexFile();
	//anIndexer3->indexFile();
	
	//cout << "busco archivo y me tiene que devolver pruebahtml.html " << aList->searchWord("archivo")->getNextDocument()->getData()<<endl;
	//cout << "la lista en first tiene : "<< aList->first->getData()<<endl;
		
	//PRUEBA DE ITERACION SOBRE LISTA 
	

	Node* aux;
	Node* aux2;
	//Node* aux3;
	//Node* aux4;


	//Imprimir lista:
//	for ( aux=aList->first ; aux!= NULL ; aux = aux->getNextWord() ){
//		cout << setw(15)<<aux->getData() << " -> " ;
//		for (aux2=aux->getNextDocument() ; aux2 != NULL ; aux2 = aux2->getNextDocument() ){
//			cout << setw(10) << aux2->getData() << " -> " ;
//		}
//		cout <<endl<<setw(15)<< "|"<< endl;
//	}
//	printf("\n\n\n\n");
	value = searcher->search();
	//printf("\n\n\n\n");

	//aList->markWord("texto");
	//aList->markWord("libre");
	//aList->markDocuments();
	//aList->printMarkedDocuments();

	//Pruebas de la lista ::
	//FUNCIONA
	//aList->addWord("Palabra1");
	//aList->addDocToEnd("DOC");
	//aList->addWord("Palabra2");
	//aList->addWord("Palabra3");
	//aList->addDocument(aList->searchWord("Palabra1"),"doc1");
	//aList->addDocument(aList->searchWord("Palabra1"),"doc2");
	//aList->addDocument(aList->searchWord("Palabra1"),"doc3");
	//aList->addDocument(aList->searchWord("Palabra2"),"doc2.1");
	//aList->addDocument(aList->searchWord("Palabra2"),"doc2.2");
	//aList->addDocument(aList->searchWord("Palabra2"),"doc2.3");
	//aList->addDocument(aList->searchWord("Palabra3"),"doc3.1");
	//aList->addDocument(aList->searchWord("Palabra3"),"doc3.2");
	//aList->addDocument(aList->searchWord("Palabra3"),"doc3.3");
	//cout << "encontre el documento: " <<aList->searchDoc("Palabra1","DOC")->getData()<<endl;

	//cout << " la que encontre es: "<< aList->searchWord("Palabra1")->getNextDocument()->getData()<<endl;
	//cout << " la que encontre es: "<< aList->searchWord("Palabra1")->getNextDocument()->getNextDocument()->getData()<<endl;
	//cout << " la que encontre es: "<< aList->searchWord("Palabra1")->getNextDocument()->getNextDocument()->getNextDocument()->getData()<<endl;
	//cout << " la que encontre es: "<< aList->searchWord("Palabra3")->getNextDocument()->getNextDocument()->getNextDocument()->getData()<<endl;
//	//cout << "la prosima e: " <<aList->first->getNextDocument()->getData()<<endl; 
	//cout <<"el modo es: "<<(int)mode<< "\b posQ es: "<<posQ<<" posD es: "<<posD<<endl;
	delete aList;
	delete indexer;
	//delete anIndexer;
	//delete anIndexer2;
	//delete anIndexer3;
	//delete anotherNode;
	
return value;
}
