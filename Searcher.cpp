#include "Searcher.h"
#include <iomanip>

using namespace std;

Searcher::Searcher(string inFile, List* aList) {
	anIndexList = aList;
	this->fileName=inFile;
}

int Searcher::search()const{
	string word,line;
	ifstream inputFile;
	istream* in = &cin;
	int numberOfWords; 
	bool needToCloseFile=false;
	//Si tengo un archivo intento abrirlo
	if (this->fileName!=""){
		inputFile.open(this->fileName.c_str());
		//Si no lo pude abrir
		if (!inputFile.good()){
			return 1;
		}else{
			in = &inputFile;
			needToCloseFile=true;
		}
	}
	//Leo archivo linea por linea
	while ( (getline(*in,line)) && (line!="") ){
		numberOfWords=0;
		stringstream ss(line);
		//para cada palabra
		while ( ss >>word ){
			numberOfWords++;
			//marco las palabras en la lista que matchean a la busqueda
			this->anIndexList->markWord(word);
		}
		if (numberOfWords>1){
			cout<<"busqueda:\""<<line<<"\""<<endl;
			this->anIndexList->markDocuments();

		printf("\n\n\n\n\n");
			Node* aux;
			Node* aux2;

		//Imprimir lista:
		for ( aux=anIndexList->first ; aux!= NULL ; aux = aux->getNextWord() ){
			if (aux->isMarked()){
				cout << setw(15)<<aux->getData() << " -> " ;
				for (aux2=aux->getNextDocument() ; aux2 != NULL ; aux2 = aux2->getNextDocument() ){
					if (aux2->isMarked())
						cout << setw(10) << aux2->getData() << " -> " ;
				}
				cout <<endl<<setw(15)<< "|"<< endl;
			}
		}	
		//this->anIndexList->printMarkedDocuments();
			this->anIndexList->unmarkAll();
		}else{
			this->anIndexList->printDocuments(word);
		}
	}
	//Si abri el archivo lo tengo que cerrar
	if (needToCloseFile)
		inputFile.close();
	return 0;
}

