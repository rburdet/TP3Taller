#ifndef NODE_H
#define NODE_H
//Se penso que los nodos tuvieran 2 punteros en caso de que se quiera usar para
//guardar otra informacion en los nodos de los documentos
#include <string>
#include <iostream>
class Node{
	private:
		bool marked;
		Node* nextDocument;
		Node* nextWord;
		const std::string data;
	public:
		//Un nodo se crea con sus punteros a NULL,no marcado y con una 
		//informacion data que puede ser documento o palabra de una manera
		//indistinta
		Node(const std::string data);
		~Node();
		//POST: devuelve puntero a proximo documento
		Node* getNextDocument()const;
		//POST: devuelve puntero a proxima palabra
		Node* getNextWord()const;
		//POST: devuelve los datos en el nodo
		const std::string getData()const;
		//POST: setea como siguiente palabra al nodo next
		void setNextWord(Node* next);
		//POST: setea como siguiente documento al nodo next
		void setNextDocument(Node* next);
		//Operador utilizado para comparar nombres de documentos o palabras
		//Uso: *NODO==data.
		//POST: Devuelve true si el dato contenido en el nodo y data son iguales
		//false en otro caso
		bool operator ==(const std::string data);
		//Si un nodo esta marcado quiere decir que me interesa para la busqueda
		//Un nodo puede estar marcado si: 
		//	La palabra que contiene es relevante a la busqueda
		//	El documento  que contiene se intersecta con otros nodos
		void markNode();
		//POST: Devuelve true si esta marcado, false en otro caso
		bool isMarked();
};

#endif
