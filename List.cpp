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
	Node* outW;		//outWord 
	Node* inW;		//inWord
	Node* outD;		//outDoc
	Node* inD;		//inDoc
	string files;
	bool needMark;
	//Para cada palabra
	for (outW=this->first ; outW!=NULL; outW = outW->getNextWord() ){
		//Si la estoy buscando
		if (outW->isMarked())
			//Para cada documento
			for (outD = outW->getNextDocument() ; outD != NULL ; outD = outD->getNextDocument()) {
				//Si esta marcado es porque ya lo encontre antes
				needMark=false;
				if (!outD->isMarked())
				//Palabra a buscar 
				for ( inW = outW ; inW != NULL ; inW = inW->getNextWord() ){
					//if (inW->isMarked())
						//Documento a comparar
						for ( inD = inW->getNextDocument() ; inD != NULL ; inD = inD->getNextDocument()) {
							if (outD->getData() == inD->getData()){
								needMark=true;
								//inD->markNode();
								//if(outW->getData() != inW->getData()){
									//cout << "puedo agregar : " << outD->getData() << " o el in: " << inD->getData() << endl;
//									if (files.find_first_of(outD->getData())==string::npos){
//										files.append(outD->getData());
//										files.insert(files.end(),';');
									//}
								//}
							}
						}
				}
				if (needMark){
					//outD->markNode();
					cout << outD->getData() << endl;
				}
			}
	}
}

string List::fillIntersecter(){
	Node* wordNode;
	Node* docNode;
	string docs;
	for ( wordNode=this->first ; wordNode!= NULL ; wordNode = wordNode->getNextWord() ){
		if (wordNode->isMarked()){
			for ( docNode=wordNode->getNextDocument() ; docNode != NULL ; docNode = docNode->getNextDocument() ){
					docs.append(docNode->getData());
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
		}
		else{
			break;
			//adoc = aux.substr(0,aux.size());
			//npos=aux.size();
		}
		//cout << "adoc: " <<adoc<<endl;
		//cout << "\t aux: \t" << aux << endl;
		while ( ( wpos=aux.find(adoc,npos)) !=string::npos){
			times++;
			npos = aux.find(',',wpos);
			//cout << "\t times: "<<times <<"\t npos: "<<npos<<"\t wpos: "<<wpos<<"\t aux: "<<aux<<endl;
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
	for ( auxNode = this->first ; auxNode!= NULL ; auxNode = auxNode->getNextWord()){
		cout << auxNode->getData()<<endl;
	}
}

void List::printMarkedDocuments(){
	Node* wordNode;
	Node* docNode;
	for ( wordNode = this->first ; wordNode != NULL ; wordNode=wordNode->getNextWord()){
		if (wordNode->isMarked())
		for ( docNode = wordNode->getNextDocument() ; docNode != NULL ; docNode = docNode->getNextDocument()){
			if (docNode->isMarked())
				cout << docNode->getData()<<endl;
		}
	}

}
void List::unmarkAll(){
	Node* wordNode;
	Node* docNode;
	for ( wordNode = this->first ; wordNode != NULL ; wordNode = wordNode->getNextWord()){
		for (docNode = wordNode->getNextDocument() ; docNode!=NULL ; docNode = docNode->getNextDocument()){
			docNode->unmarkNode();
		}
		wordNode->unmarkNode();
	}
}

void List::fill(const string word,List* aList){
	cout << "busqueda:\""<<word<<"\""<<endl;
	Node* wordNode = this->searchWord(word);
	if (wordNode!=NULL){
		Node* auxNode;
		for ( auxNode= wordNode->getNextDocument() ; auxNode!=NULL ; auxNode = auxNode->getNextDocument() ){
			aList->addWord(auxNode->getData());
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

