#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <string>
#include "Node.h"

class List{
	//private:
	public:
		//Cualquier miembro que use la lista puede acceder a su primer posicion
		//y a la actual
		Node* first;
		Node* actual;

		List();
		~List();
		//Agrego un documento al final de la ultima palabra que se agrego
		void addDocToEnd(const std::string doc);
		//Agrego un documento en la palabra indicada por wordNode
		void addDocument(Node* wordNode,std::string doc);
		//Agrego una palabra con el documento en el que aparecio
		void addWord(const std::string doc);
		//Busco palabra por palabra hasta que data matchea con la palabra en 
		//la lista. 
		//POST: devuelve el nodo que matcheo
		Node* searchWord(const std::string data);
		//Para la palabra indicada por word busco el documento doc. 
		//POST: devuelve el nodo que matcheo para un documento en una palabra
		Node* searchDoc(const std::string word,const std::string doc);
		//Marca las palabras que se quieren en una busqueda para luego hacer
		//la interseccion de sus documentos
		void markWord(const std::string word);
		//Marca los documentos que se intersectan
		void markDocuments();
		//Imprime los documetnos marcados
		void printMarkedDocuments();
		//Pone la lista en el estado inicial (todo desmarcado)
		void unmarkAll();
		//TODO: CAMBIAR ESTO
		//Si solo tengo que buscar una palabra tengo que imprimir solo sus documentos
		void fill(const std::string word,List* aList);
		//Intersecta todos los documentos
		void intersect(int numberOfWords,std::string &docs,List* aList);
		//Llena el string que se va a usar como intersectador
		std::string fillIntersecter();
		//imprime la lista
		void printList()const;
};

#endif
