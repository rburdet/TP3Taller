#ifndef COMPLETO_H
#define COMPLETO_H

#include "Mode.h"

class Completo : public Mode {
	public:
		Completo() : Mode("completo",1){}
		void print(List* printList);
};

#endif
