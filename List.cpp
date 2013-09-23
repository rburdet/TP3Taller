#include <string>
#include "List.h"

using std::string;
using std::cout;
using std::endl;

List::List(){
	this->first=NULL;
	this->actual=NULL;
}

void List::addWord(const string word){
	Node* auxNode = new Node(word);
	if (this->first==NULL){
		this->first=auxNode;
		this->actual=auxNode;
	}else{
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
void List::addDocument(Node* wN,string doc){
	Node* auxNode = new Node(doc);
	while((wN->getNextDocument())!=NULL){
		wN->setNextDocument(wN->getNextDocument());
		wN=wN->getNextDocument();
	}
	wN->setNextDocument(auxNode);
}


Node* List::searchWord(const string data){
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


Node* List::searchDoc(const string word, const string doc){
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

void List::markWord(const string word){
	Node* auxNode;
	if ((auxNode=this->searchWord(word))!=NULL)
		auxNode->markNode();
}

string List::fillIntersecter(){
	Node* wN;
	Node* dN;
	string docs;
	for ( wN=this->first ; wN!= NULL ; wN = wN->getNextWord() ){
		if (wN->isMarked()){
			for ( dN=wN->getNextDocument() ; dN != NULL ; dN = dN->getNextDocument() ){
					docs.append(dN->getData());
					docs.insert(docs.end(),',');
			}
		}
	}
	if (docs.size()>0)
		docs.erase(docs.size()-1);
	return docs;
}

void List::intersect(int numberOfWords,string &docs,List* aList){
	size_t fpos,wpos,npos;
	string adoc;
	string aux = docs;
	while(aux.size()>0){
		int times=1;
		fpos=aux.find(',');
		if (fpos != string::npos){
			adoc = aux.substr(0,fpos);
			npos=fpos;
		}else{
			break;
			//adoc = aux.substr(0,aux.size());
			//npos=aux.size();
		}
		//cout << "adoc: " <<adoc<<endl;
		//cout << "\t aux: \t" << aux << endl;
		while ((wpos=aux.find(adoc,npos)) != string::npos){
			times++;
			npos = aux.find(',',wpos);
			aux.erase(wpos,npos-wpos+1);
		}
		if (fpos != string::npos)
			aux.erase(0,fpos+1);
		if (times == numberOfWords){
			aList->addWord(adoc);
		}
	}
}

void List::printList()const{
	Node* auxNode;
	for ( auxNode = first ; auxNode!= NULL ; auxNode = auxNode->getNextWord() ){
		cout << auxNode->getData()<<endl;
	}
}

void List::printMarkedDocuments(){
	Node* wN;
	Node* dN;
	for ( wN = this->first ; wN != NULL ; wN=wN->getNextWord() ){
		if (wN->isMarked())
		for ( dN = wN->getNextDocument() ; dN != NULL ;
				dN = dN->getNextDocument() ){
			if (dN->isMarked())
				cout << dN->getData()<<endl;
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

	void List::fill(const string word,List* aList){
		cout << "busqueda:\""<<word<<"\""<<endl;
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

