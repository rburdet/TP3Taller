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
		const std::string data;
	public:
		Node(const std::string data);
		~Node();
		Node* getNextDocument()const;
		Node* getNextWord()const;
		const std::string getData()const;
		void setNextWord(Node* next);
		void setNextDocument(Node* next);
};

#endif
