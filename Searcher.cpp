#include <string>
#include "Searcher.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::stringstream;
using std::istream;
using std::ifstream;

Searcher::Searcher(const string& inFile, List* aList,Mode* aMode){
	anIndexList = aList;
	this->fileName=inFile;
	this->openMode=aMode;
}

int Searcher::search()const{
	string word,line;
	ifstream inputFile;
	istream* in = &cin;
	int numberOfWords; 
	//bool needToCloseFile=false;
	//Si tengo un archivo intento abrirlo
	if (this->fileName!=""){
		inputFile.open(this->fileName.c_str());
		//Si no lo pude abrir
		if (!inputFile.good()){
			return 1;
		}else{
			in = &inputFile;
			//needToCloseFile=true;
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
		List aList;
		if (numberOfWords>1){
			cout<<"busqueda:\""<<line<<"\""<<endl;
			List inList;
			this->anIndexList->fillList(&inList);
			this->anIndexList->intersect(numberOfWords,&inList,&aList);
			this->openMode->print(&aList);
			this->anIndexList->unmarkAll();
		}else{
			cout << "busqueda:\""<<word<<"\""<<endl;
			this->anIndexList->fill(word,&aList);
			this->openMode->print(&aList);
		}
	}
	return 0;
}

