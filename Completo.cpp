#include <string>
#include "Completo.h"

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

void Completo::print(List* printList)const{
	char times;
	string fileName;
	string line;
	Node* aux;
	for ( aux = printList->getFirst() ; aux != NULL ; aux = aux->getNextWord() ){
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
