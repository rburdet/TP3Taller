#include <string>
#include "NormalFileIndexer.h"

using std::string;

bool NormalFileIndexer::isNormalIndexable(const string word)const{
	return(word.size() >= 4);
}


