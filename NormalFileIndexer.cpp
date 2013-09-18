#include "NormalFileIndexer.h"

using namespace std;

	//void NormalFileIndexer::indexFile(){
//	//this->redFileName = fileName.substr(0,fileName.find('.'));
//	//this->format = fileName.substr(fileName.find('.')+1,fileName.size());
//	string line, word;
//	while (!file.eof()){
//		do{
//			while(this->file>>word){
//				if (isNormalIndexable(word)){
//					
//				}
//			}	
//		}while(getline(this->file,line));
//	}
//}

bool NormalFileIndexer::isNormalIndexable(string word){
	return( word.size() >= 4 );
}


