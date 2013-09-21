#include "Node.h"

using namespace std;

Node::Node(const string adata) : data(adata){
	this->nextDocument=NULL;
	this->nextWord=NULL;
	this->marked=false;
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

bool Node::operator == (const string doc){
	return (this->getData().compare(doc) == 0);
}

void Node::markNode(){
	this->marked=true;
}

bool Node::isMarked(){
	return (this->marked);
}
