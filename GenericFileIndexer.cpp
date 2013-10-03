#include <string>
#include "GenericFileIndexer.h"

using std::string;
using std::cerr;
using std::endl;

GenericFileIndexer::GenericFileIndexer(const string& fileName,List* indexList) :
	compFileName(fileName){
	this->redFileName = fileName.substr(0,fileName.find('.'));
	this->format = fileName.substr(fileName.find('.')+1,fileName.size());
	(this->file).open(fileName.c_str());
	if (!file)
		cerr<<"Error al parsear archivo: "<<fileName<<endl;
	this->indexList = indexList;
}

GenericFileIndexer::~GenericFileIndexer(){
	(this->file).close();
}

bool GenericFileIndexer::isOpen(){
	return (file.is_open());
}

string GenericFileIndexer::toLower(const string& in){
	string newOut;
	char* out = (char*)malloc(sizeof(char)*in.size()+1);
	unsigned i=0;
	for ( i=0 ; i < in.size() ; i++ )
		out[i]=(char)tolower(in[i]);
	newOut = string(out);
	free(out);
	return newOut;
}

void GenericFileIndexer::indexFile(){
	string line, rawWord,word;
	//Mientras no sea fin de archivo
	while (!file.eof()){
		//Mientras tenga palabras
		while (this->file>>rawWord){
			word = toLower(rawWord);
			//Si la palabra tiene mas de 4 letras
				this->indexWord(word,indexList); 
		}
	}
}

const string GenericFileIndexer::getFileName(){
	return this->compFileName;
}
