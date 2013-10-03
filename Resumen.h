#ifndef RESUMEN_H
#define RESUMEN_H

#include "Mode.h"

#define RESUMENWORD "resumen"
#define RESUMEN 2
class Resumen : public Mode {
	public:
		//El constructor llama al constructor del padre con el nombre
		//del modo y el numero correspondiente como parametros
		Resumen() : Mode(RESUMENWORD,RESUMEN){}
		//Imprime la lista, en cada palabra tiene un documento, imprimiendo 
		//solamente si todos los documentos que se enuentren en la lista
		void print(List* listToPrint)const{
				Node* auxNode;
				for ( auxNode = listToPrint->getFirst() ; auxNode!= NULL ; 
						auxNode = auxNode->getNextWord() ){
					std::cout << auxNode->getData()<<std::endl;
				}
		}
};

#endif 
