#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <string>
#include "Node.h"

class List{
	private:
		Node* first;
		Node* actual;

	public:
		List();
		~List();
		//Devuelve el puntero al primer nodo
		Node* getFirst();
		//Agrego un documento al final de la ultima palabra que se agrego
		void addDocToEnd(const std::string& doc);
		//Agrego un documento en la palabra indicada por wordNode
		void addDocument(Node* wordNode,std::string doc);
		//Agrego una palabra con el documento en el que aparecio
		void addWord(const std::string& doc);
		//Busco palabra por palabra hasta que data matchea con la palabra en 
		//la lista. 
		//POST: devuelve el nodo que matcheo
		Node* searchWord(const std::string& data);
		//Para la palabra indicada por word busco el documento doc. 
		//POST: devuelve el nodo que matcheo para un documento en una palabra
		Node* searchDoc(const std::string& word,const std::string& doc);
		//Marca las palabras que se quieren en una busqueda para luego hacer
		//la interseccion de sus documentos
		void markWord(const std::string& word);
		//Pone la lista en el estado inicial (todo desmarcado)
		void unmarkAll();
		//llena aList con los documentos que luego voy a imprimir
		//Esta version es una version mas sencilla que fillList
		void fill(const std::string& word,List* aList);
		//llena la lista con todos los documentos marcados
		void fillList(List* aList);
		//Realiza la interseccion entre documentos
		//La interseccion es correcta cuando la cantidad de veces que aparece
		//el documento es igual a numberOfWords que representa la cantidad 
		//de palabras que se estan buscando
		void intersect(int numberOfWords,List* filledList,List* aList);
};

#endif
