#ifndef NORMAL_INDEXER_H
#define NORMAL_INDEXER_H

#include <string>
#include "GenericFileIndexer.h"
//Esta clase es para trabajar con los formatos que especifica el Tp, ya que
//habiendo otros pueden no cumplir con estos standards
class NormalFileIndexer: public GenericFileIndexer{
	public:
		//Crea el objeto NormalFileIndexer llamando al constructor de la 
		//clase padre.
		//Todos los modos de este trabajo practico heredan de esta clase
		//En caso de extension pueden extender de la clase padre 
		//GenericFileIndexer
		//fileName es el archivo que se esta indexando, aList es la lista 
		//sobre la que se indexa
		NormalFileIndexer(const std::string& fileName,List* aList) : 
			GenericFileIndexer(fileName, aList) {}
		//Prueba si cumple los requisitos basicos para este TP, estos tienen
		//que ver con el largo de las palabras
		//POST: Devuelve true si las palabras tienen 4 o mas caracteres
		bool isNormalIndexable(const std::string&)const;
		//Indexa el archivo sobre la lista 
		virtual void indexFile();
		//Saca los tags al archivo, el caso mas generico es no haya tags
		//En caso de archivos con tags se redefenira este metodo
		virtual void untag(std::string& line){}
};

#endif
