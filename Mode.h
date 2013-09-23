#ifndef MODE_H
#define MODE_H

#include <string>
#include <fstream>
#include "List.h"

class Mode{
	protected:
		const std::string modeName;
		const int modeNumber;
	public:
		// En caso de extension a otros casos voy a tener que saber 
		// de que modo estamos hablando
		Mode(const std::string name,const int num);
		virtual const std::string getModeName()const;
		virtual const int getModeNum()const;
		virtual void print(List* printList)=0;
		virtual ~Mode(){}
};

#endif 
