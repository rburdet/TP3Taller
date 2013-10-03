#include <string>
#include "NormalFileIndexer.h"

using std::string;

bool NormalFileIndexer::isNormalIndexable(const string& word)const{
	return(word.size() >= 4);
}

void NormalFileIndexer::indexFile(){
	string line, rawWord,word;
	//Mientras no sea fin de archivo
	while (!file.eof()){
		//Mientras tenga palabras
		while (this->file>>rawWord){
			word = toLower(rawWord);
			//Si puedo le saco los tags
			untag(word);
			//Si la palabra tiene mas de 4 letras
			if (isNormalIndexable(word)){
				//Si la palabra no fue indexada
				if (this->indexList->searchWord(word)==NULL){
					this->indexList->addWord(word);
					this->indexList->addDocToEnd(this->compFileName);
				}else{
					//La palabra fue indexada pero no en este documento
					if (indexList->searchDoc(word,this->compFileName) == NULL){
						indexList->addDocument(indexList->searchWord(word)
								,compFileName);
					}
				}		
			}
		}
	}
}

