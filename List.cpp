#include <string>
#include "List.h"

using std::string;

List::List(){
	this->first=NULL;
	this->actual=NULL;
}

void List::addWord(const string& word){
	Node* auxNode = new Node(word);
	if (this->first==NULL){
		this->first=auxNode;
		this->actual=auxNode;
	}else{
		this->actual->setNextWord(auxNode);
		this->actual = auxNode;
	}
}

void List::addDocToEnd(const string& doc){
	Node* auxNode = new Node(doc);
	this->actual->setNextDocument(auxNode);
}

	//para agregar un documento se llamara a 
	//List->addDocument(searchWord(palabra),documento)
	//el doc1 estara en aList->searchWord(string)->getNextDocument()
void List::addDocument(Node* wN,string doc){
	Node* auxNode = new Node(doc);
	while((wN->getNextDocument())!=NULL){
		wN->setNextDocument(wN->getNextDocument());
		wN=wN->getNextDocument();
	}
	wN->setNextDocument(auxNode);
}


Node* List::searchWord(const string& data){
	if (this->first==NULL)
		return NULL;
	if ((*this->first)==data){
		return this->first;
	}else{
		Node* auxNode = this->first;
		do {
			auxNode = auxNode->getNextWord();
			if ( auxNode == NULL )
				return NULL;
		}while ( !(*auxNode==data));
		return auxNode;
	}
}


Node* List::searchDoc(const string& word, const string& doc){
	if (this->searchWord(word)==NULL)
		return NULL;
	Node* auxNode = this->searchWord(word)->getNextDocument();
	if ((*auxNode==doc)){
		return (auxNode);
	}else{
		do{
			auxNode = auxNode->getNextDocument();
			if (auxNode == NULL ) 
				return NULL;
		}while( !(*auxNode==doc) );
		return auxNode;
	}
}

void List::markWord(const string& word){
	Node* auxNode;
	if ((auxNode=this->searchWord(word))!=NULL)
		auxNode->markNode();
}

void List::intersect(int numberOfWords,List* inList,List* outList){
	Node* aux;
	Node* another;
	for ( aux = inList->getFirst() ; aux != NULL ; 
			aux = aux->getNextWord() ){
		int times = 1;
		for ( another = aux->getNextWord() ; another != NULL ; 
				another = another->getNextWord()){
			if (another->getData() == aux->getData())
				times++;
		}
		if (times == numberOfWords){
			outList->addWord(aux->getData());
		}
	}
}

void List::unmarkAll(){
	Node* wN;
	Node* dN;
	for ( wN = this->first ; wN != NULL ; wN = wN->getNextWord() ){
		for ( dN = wN->getNextDocument() ; dN!=NULL ;
						dN = dN->getNextDocument() ){
				dN->unmarkNode();
			}
			wN->unmarkNode();
		}
	}

void List::fill(const string& word,List* aList){
	Node* wN = this->searchWord(word);
	if (wN!=NULL){
		Node* auxNode;
	for ( auxNode= wN->getNextDocument() ; auxNode!=NULL ;
			auxNode = auxNode->getNextDocument() ){
		aList->addWord(auxNode->getData());
	}
}
}

List::~List(){
	Node* wordToDestroy;
	Node* docToDestroy;
	Node* aux;
	wordToDestroy=this->first;
	while (wordToDestroy != NULL){
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

Node* List::getFirst(){
	return this->first;
}

void List::fillList(List* aList){
	Node* wN;
	Node* dN;
	for ( wN=this->first; wN!= NULL ; wN = wN->getNextWord() ){
		if (wN->isMarked()){
			for ( dN=wN->getNextDocument() ; dN != NULL ;
					dN = dN->getNextDocument() ){
				aList->addWord(dN->getData());
			}
		}
	}
}
