#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <string>
#include "Node.h"

class List{
	private:
		std::string data;
		Node* first;
		Node* actual;
	public:
		List();
		~List();
		//Siempre se agrega al final
		//Ya sea para agregar un documento o una palabra
		void addDocToEnd(const std::string doc);
		void addDocument(Node* wordNode,std::string doc);
		void addWord(const std::string doc);
		Node* searchWord(const std::string data);
		Node* searchDoc(const std::string word,const std::string doc);
};

#endif
