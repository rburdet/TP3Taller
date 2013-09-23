#include "Mode.h"

using namespace std;

Mode::Mode(const string mode,const int num) : modeName(mode), modeNumber(num){}

const string Mode::getModeName()const{
	return this->modeName;
}

const int Mode::getModeNum()const{
	return this->modeNumber;
}
