#ifndef MODE_H
#define MODE_H

#include <string>

class Mode{
	protected:
		std::string modeName;
	public:
		Mode(std::string modeName);
		std::string getMode();
		

};

#endif 
