#include "GenericFileIndexer.h"

using namespace std;

GenericFileIndexer::GenericFileIndexer(const string fileName,List* indexList) : compFileName(fileName){
	this->redFileName = fileName.substr(0,fileName.find('.'));
	this->format = fileName.substr(fileName.find('.')+1,fileName.size());
	(this->file).open(fileName.c_str());
	if (!file)
		cerr<<"Error al parsear archivo "<<fileName<<endl;
	this->indexList = indexList;
}

GenericFileIndexer::~GenericFileIndexer(){
	(this->file).close();
}

string GenericFileIndexer::toLower(const string in){
	string newOut;
	int dif = 'a'-'A';
	char* out = (char*)calloc(1,sizeof(char)*in.size()+1);
	unsigned i=0;
	for ( i=0 ; i < in.size() ; i++){
		if (in[i]<='Z' && in[i]>='A')
			out[i] = in[i]+dif;
		else 
			out[i]=in[i];
	}
	newOut = string(out);
	free(out);
	return newOut;
}

