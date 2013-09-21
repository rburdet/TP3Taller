#include "List.h"

using namespace std;

List::List(){
	this->first=NULL;
	this->actual=NULL;
}

void List::addWord(const string word){
	Node* auxNode = new Node(word);
	if ( this->first==NULL ){
		this->first=auxNode;
		this->actual=auxNode;
	}
	else{
		this->actual->setNextWord(auxNode);
		this->actual = auxNode;
	}
}

void List::addDocToEnd(const string doc){
	Node* auxNode = new Node(doc);
	this->actual->setNextDocument(auxNode);
}

//para agregar un documento se llamara a 
//List->addDocument(searchWord(palabra),documento)
//el doc1 estara en aList->searchWord(string)->getNextDocument()
void List::addDocument(Node* wordNode,string doc){
	Node* auxNode = new Node(doc);
	while((wordNode->getNextDocument())!=NULL){
		wordNode->setNextDocument(wordNode->getNextDocument());
		wordNode=wordNode->getNextDocument();
	}
	wordNode->setNextDocument(auxNode);
}


Node* List::searchWord(const string data){
	if (this->first==NULL)
		return NULL;
	if (*this->first==data )
		return this->first;
	else{
		Node* auxNode = this->first;
		do {
			auxNode = auxNode->getNextWord();
			if ( auxNode == NULL )
				return NULL;
		}while ( !(*auxNode==data));
		return auxNode;
	}
}


Node* List::searchDoc(const string word, const string doc){
	if (this->searchWord(word)==NULL)
		return NULL;
	Node* auxNode = this->searchWord(word)->getNextDocument();
	if ((*auxNode==doc))  
		return (auxNode);
	else{
		do{
			auxNode = auxNode->getNextDocument();
			if (auxNode == NULL ) 
				return NULL;
		}while( !(*auxNode==doc) );
		return auxNode;
	}
}

void List::markWord(const string word){
	Node* auxNode;
	if ((auxNode=this->searchWord(word))!=NULL)
		auxNode->markNode();
}

void List::markDocuments(){
	Node* aDocNode;
	Node* aWordNode = this->first;
	Node* nextWord = this->first->getNextWord();
	while (aWordNode->getNextWord() != NULL ){
		if (aWordNode->isMarked()){
			while ((aDocNode=aWordNode->getNextDocument()) != NULL){
				if (aDocNode->isMarked()){
					while ((nextWord=aWordNode->getNextWord()) != NULL)
						if (nextWord->isMarked()){
							//while 
						}
				}
			}
		}
	}
}

List::~List(){
	Node* wordToDestroy;
	Node* docToDestroy;
	Node* aux;
	wordToDestroy=this->first;
	while (wordToDestroy != NULL ){
		this->actual = wordToDestroy->getNextWord();
		docToDestroy=wordToDestroy->getNextDocument();
		while ( docToDestroy != NULL ){
			aux = docToDestroy->getNextDocument();
			delete docToDestroy;
			docToDestroy = aux;
		}
		delete wordToDestroy;
		wordToDestroy = this->actual;
	}
}

