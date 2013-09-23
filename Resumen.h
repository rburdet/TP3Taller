#ifndef RESUMEN_H
#define RESUMEN_H

#include "Mode.h"

class Resumen : public Mode {
	public:
		Resumen() : Mode("resumen",2){}
		void print(List* listToPrint){listToPrint->printList();}
};

#endif 
