#ifndef MODE_H
#define MODE_H

#include <string>

class Mode{
	protected:
		const std::string modeName;
	public:
		Mode(const std::string name) : modeName(name){};
		const std::string getMode()const;
		

};

#endif 
