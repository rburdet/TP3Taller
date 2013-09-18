#include "Node.h"

using namespace std;

Node::Node(string data){
	this->data = data;
	this->nextDocument=NULL;
	this->nextWord=NULL;
}

Node::~Node(){
	cout << "borrando: "<<this->data << endl;
}

Node* Node::getNextDocument(){
	return this->nextDocument;
}

Node* Node::getNextWord(){
	return this->nextWord;
}

void Node::setNextDocument(Node* next){
	this->nextDocument=next;
}

void Node::setNextWord(Node* next){
	this->nextWord=next;
}

string Node::getData(){
	return data;
}
