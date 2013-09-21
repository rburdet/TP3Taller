#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "List.h"
#include "GenericFileIndexer.h"
#include "Factory.h"
using namespace std;

int main(int argc, char* argv[]){
	int value;
	char mode;
	int posQ,posD;
	//Node* aNode = new Node("pepe");
	//Node* anotherNode = new Node("pelotudo");
	List* aList = new List();
	ifstream file;
	//file.open("pruebatex.tex");
	GenericFileIndexer* anIndexer ;
	GenericFileIndexer* anIndexer2 ;
	GenericFileIndexer* anIndexer3;

	anIndexer = Factory::createIndexer("pruebatex.tex",aList);
	anIndexer2 = Factory::createIndexer("pruebahtml.html",aList);
	anIndexer3 = Factory::createIndexer("pruebatxt.txt",aList);

	anIndexer->indexFile();
	anIndexer2->indexFile();
	anIndexer3->indexFile();

	//cout << "busco archivo y me tiene que devolver pruebahtml.html " << aList->searchWord("archivo")->getNextDocument()->getData()<<endl;
	//cout << "la lista en first tiene : "<< aList->first->getData()<<endl;
		
	//PRUEBA DE ITERACION SOBRE LISTA 
	Node* aux;
	Node* aux2;
	Node* aux3;
	Node* aux4;
	//aList->markWord("comunes");
	//aList->markWord("palabras");
	aList->markWord("archivos");
	for (aux=aList->first ; aux!=NULL; aux = aux->getNextWord() ){
		if (aux->isMarked())
			for (aux2 = aux->getNextDocument() ; aux2 != NULL ; aux2 = aux2->getNextDocument()) {
				for ( aux3 = aux ; aux3 != NULL ; aux3 = aux3->getNextWord() ){
					if (aux3->isMarked())
						for ( aux4 = aux3->getNextDocument() ; aux4 != NULL ; aux4 = aux4->getNextDocument()) {
							//if (aux2->getData()==aux4->getData())
								//if(aux3->getData()==aux->getData())
									cout << "aux1: " <<aux->getData() <<setw(20)<<"aux2: "<<aux2->getData()<<setw(20)<<"aux3: "<<aux3->getData()<<setw(20)<<"aux4: "<<aux4->getData()<<endl;
						}
				}
			}
	}	
	
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
	value = parseArguments(argc,argv,mode,posQ,posD);
	//cout <<"el modo es: "<<(int)mode<< "\b posQ es: "<<posQ<<" posD es: "<<posD<<endl;
	printf("\n\n\n\n");
	delete aList;
	delete anIndexer;
	//delete anotherNode;
	
return value;
}
