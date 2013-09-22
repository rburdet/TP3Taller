#include "Searcher.h"

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
	Node* node1;
	Node* node2;
	bool needToCloseFile=false;
	bool match=false;
	//Si tengo un archivo intento abrirlo
	if (this->fileName!=""){
		inputFile.open(this->fileName.c_str());
		//Si no lo pude abrir
		if (!inputFile.good()){
			cerr << "Error al parsear archivo en searcher: "<<this->fileName<<endl;
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

