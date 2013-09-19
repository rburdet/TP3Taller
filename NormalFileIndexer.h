#ifndef NORMAL_INDEXER_H
#define NORMAL_INDEXER_H

#include "GenericFileIndexer.h"
//Esta clase es para trabajar con los formatos que especifica el Tp, ya que
//habiendo otros pueden no cumplir con estos standards
class NormalFileIndexer: public GenericFileIndexer{
	public:
		NormalFileIndexer(const std::string fileName,List* aList) : GenericFileIndexer(fileName, aList) {}
		bool isNormalIndexable(const std::string)const;
		virtual void indexFile()=0;

};

#endif
