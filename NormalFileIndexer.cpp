#include "NormalFileIndexer.h"

using namespace std;

bool NormalFileIndexer::isNormalIndexable(const string word)const {
	return( word.size() >= 4 );
}


