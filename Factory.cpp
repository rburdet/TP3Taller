#include <string>
#include "Factory.h"

GenericFileIndexer* Factory::createIndexer(std::string& fileName,List* list){
	GenericFileIndexer* indexer = NULL;
	std::string extension = fileName.substr(fileName.find('.')+1,fileName.size());
	if (extension.compare(GenericFileIndexer::toLower("Txt"))==0){
		indexer = new NormalFileIndexer(fileName,list);
	}else if (extension.compare(GenericFileIndexer::toLower("Tex"))==0){
		indexer = new TexIndexer(fileName,list);
	}else if (extension.compare(GenericFileIndexer::toLower("Html"))==0){
		indexer = new HtmlIndexer(fileName,list);
	}else{
		std::cerr << "Error al parsear archivo: "<<fileName << std::endl;
		delete indexer;
		indexer=NULL;
	}
	if ( (indexer!=NULL) && (!(indexer->isOpen())) ){
		delete indexer;
		indexer=NULL;
	}
	return indexer;
}
