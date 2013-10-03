#ifndef TEXINDEXER_H
#define TEXINDEXER_H

#include <string>
#include "TaggedFileIndexer.h"

//La siguiente clase se utilizara para tratar archivos .tex 

class TexIndexer : public TaggedFileIndexer {
	public: 
		//Contructor que llama al constructor de su clase padre 
		//Le pasa como parametros los caracteres de apertura y cierre de tags
		TexIndexer(const std::string& fileName, List* aList) :
			TaggedFileIndexer(fileName, aList,'{','}'){
		}
};

#endif
