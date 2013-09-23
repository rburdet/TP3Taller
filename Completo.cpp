#include "Completo.h"

using namespace std;

void Completo::print(List* printList){
	char times;
	string fileName;
	string line;
	Node* aux;
	for ( aux = printList->first ; aux != NULL ; aux = aux->getNextWord()){
		times=0;
		fileName= aux->getData();
		cout << fileName << endl;
		ifstream inFile(fileName.c_str());
		while ( (getline(inFile,line)) && (times<4) ){
			times++;
			cout << line << endl;
		}
	}

}
