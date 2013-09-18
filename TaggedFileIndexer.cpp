#include "TaggedFileIndexer.h"

using namespace std;

void TaggedFileIndexer::untag(string& line){
	string aux;
	unsigned i;
	bool isTag=false;
	for ( i = 0 ; i < line.size() ; i++ ){
		if (line[i] == '<')
			isTag=true;
		if (!isTag)
			aux.push_back(line[i]);
		if (line[i] == '>') 
			isTag=false;
	}
	line=aux;
}

void TaggedFileIndexer::indexFile(){
	string line, rawWord,word;
	//Mientras no sea fin de archivo
	while (!file.eof()){
		//Mientras tenga palabras
		while (this->file>>rawWord){
			word = toLower(rawWord);
			//Si la palabra tiene mas de 4 letras
			if (isNormalIndexable(word)){
				untag(word);
				//Si la palabra no fue indexada
				if (this->indexList->searchWord(word)==NULL){
					this->indexList->addWord(word);
				}else{
					//La palabra fue indexada pero no en este documento
					if (this->indexList->searchDoc(word,this->compFileName) == NULL){
						this->indexList->addDocument(this->indexList->searchWord(word),this->compFileName);
					}
				}		
			}
		}
	}
}