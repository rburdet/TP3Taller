#include <string>
#include "Mode.h"

using std::string;

Mode::Mode(const string& mode,const int num) : modeName(mode), modeNumber(num){}

const string Mode::getModeName()const{
	return this->modeName;
}

const int Mode::getModeNum()const{
	return this->modeNumber;
}
