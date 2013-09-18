#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "List.h"
#include "GenericFileIndexer.h"
#include "TxtIndexer.h"

using namespace std;

int main(int argc, char* argv[]){
	int value;
	char mode;
	int posQ,posD;
	//Node* aNode = new Node("pepe");
	//Node* anotherNode = new Node("pelotudo");
	List* aList = new List();
	ifstream file;
	file.open("prueba.txt");
	string  word,line;
	printf("\n\n\n");
	while (!file.eof()){
		while(file>>word)
			cout << word << endl;
	}
	GenericFileIndexer* anIndexer ;
	anIndexer = new TxtIndexer("prueba.txt",aList);
	anIndexer->indexFile();
	
	//Pruebas de la lista ::
	//FUNCIONA
//	aList->addWord("Palabra1");
//	aList->addWord("Palabra2");
//	aList->addWord("Palabra3");
//	aList->addDocument(aList->searchWord("Palabra1"),"doc1");
//	aList->addDocument(aList->searchWord("Palabra1"),"doc2");
//	aList->addDocument(aList->searchWord("Palabra1"),"doc3");
//	aList->addDocument(aList->searchWord("Palabra2"),"doc2.1");
//	aList->addDocument(aList->searchWord("Palabra2"),"doc2.2");
//	aList->addDocument(aList->searchWord("Palabra2"),"doc2.3");
//	aList->addDocument(aList->searchWord("Palabra3"),"doc3.1");
//	aList->addDocument(aList->searchWord("Palabra3"),"doc3.2");
//	aList->addDocument(aList->searchWord("Palabra3"),"doc3.3");
//	cout << "encontre el documento: " <<aList->searchDoc("Palabra1","doc1")->getData()<<endl;

//	cout << " la que encontre es: "<< aList->searchNode("unaPalabra")->getNextDocument()->getNextDocument()->getNextDocument()->getData()<<endl;
//	cout << " la que encontre es: "<< aList->searchNode("otraPalabra")->getNextDocument()->getNextDocument()->getNextDocument()->getData()<<endl;
//	//cout << "la prosima e: " <<aList->first->getNextDocument()->getData()<<endl; 
	//value = parseArguments(argc,argv,mode,posQ,posD);
	//cout <<"el modo es: "<<(int)mode<< "\b posQ es: "<<posQ<<" posD es: "<<posD<<endl;
	//delete aNode;
	delete aList;
	delete anIndexer;
	//delete anotherNode;
	
return value;
}
