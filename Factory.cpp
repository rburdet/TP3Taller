#include "Factory.h"

GenericFileIndexer* Factory::createIndexer(std::string fileName,List* list){
	GenericFileIndexer* mySon = NULL;
	std::string extension = fileName.substr(fileName.find('.')+1,fileName.size());
	if (extension.compare(GenericFileIndexer::toLower("Txt"))==0)
		mySon = new TxtIndexer(fileName,list);
	else if (extension.compare(GenericFileIndexer::toLower("Tex"))==0)
		mySon = new TexIndexer(fileName,list);
	else if (extension.compare(GenericFileIndexer::toLower("Html"))==0)
		mySon = new HtmlIndexer(fileName,list);
	else{
		std::cerr << "Error al parsear archivo: "<<fileName << std::endl;
		delete mySon;
		mySon=NULL;
	}
	if ( (mySon!=NULL) && (!(mySon->isOpen())) ){
		delete mySon;
		mySon=NULL;
	}
	return mySon;
}
