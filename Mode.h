#ifndef MODE_H
#define MODE_H

#include <string>
#include <fstream>
#include "List.h"

class Mode{
	private:
		const std::string modeName;
		const int modeNumber;
	public:
		// En caso de extension a otros casos voy a tener que saber 
		// de que modo estamos hablando
		Mode(const std::string& name,const int num);
		//Devuelve el nombre del modo
		virtual const std::string getModeName()const;
		//Devuelve el numero del modo
		virtual const int getModeNum()const;
		//Imprime la lista dependiendo el modo que sea
		virtual void print(List* printList)const=0;
		//Destruye el objeto modo
		virtual ~Mode(){}
};

#endif 
