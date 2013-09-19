#include "Node.h"

using namespace std;

Node::Node(const string adata) : data(adata){
	this->nextDocument=NULL;
	this->nextWord=NULL;
}

Node::~Node(){
	cout << "borrando: "<<this->data << endl;
}

Node* Node::getNextDocument()const{
	return this->nextDocument;
}

Node* Node::getNextWord()const{
	return this->nextWord;
}

void Node::setNextDocument(Node* next){
	this->nextDocument=next;
}

void Node::setNextWord(Node* next){
	this->nextWord=next;
}

const string Node::getData()const {
	return data;
}
