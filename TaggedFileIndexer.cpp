#include <string>
#include "TaggedFileIndexer.h"

using std::string;
using std::cin;
using std::stringstream;

void TaggedFileIndexer::untag(string& line){
	string aux;
	unsigned i;
	bool isTag=false;
	for ( i = 0 ; i < line.size() ; i++ ){
		if (line[i] == openTag)
			isTag=true;
		if (!isTag)
			aux.push_back(line[i]);
		if (line[i] == closeTag) 
			isTag=false;
	}
	line=aux;
}
