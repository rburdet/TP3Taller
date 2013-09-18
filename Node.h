#ifndef NODE_H
#define NODE_H
//Se penso que los nodos tuvieran 2 punteros en caso de que se quiera usar para
//guardar otra informacion en los nodos de los documentos
#include <string>
#include <iostream>
class Node{
	private:
		Node* nextDocument;
		Node* nextWord;
		std::string data;
	public:
		Node(std::string data);
		~Node();
		Node* getNextDocument();
		Node* getNextWord();
		std::string getData();
		void setNextWord(Node* next);
		void setNextDocument(Node* next);
};

#endif
