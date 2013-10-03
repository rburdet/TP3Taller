#ifndef COMPLETO_H
#define COMPLETO_H

#include "Mode.h"

#define COMPLETOWORD "completo"
#define COMPLETO 1
class Completo : public Mode {
	public:
		Completo() : Mode(COMPLETOWORD,COMPLETO){}
		void print(List* printList)const;
};

#endif
