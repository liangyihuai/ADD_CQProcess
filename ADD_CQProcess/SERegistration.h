#pragma once
#ifndef SE_REGISTRATION
#define SE_REGISTRATION

#include "Event.h"
#include "ClassFactory.h"
#include <map>

class SERegistration {
public:

	SERegistration(string className, PTRCreateObject ptrCreateFn) {
		ClassFactory::getInstance().registClass(className, ptrCreateFn);
	}

};


#endif // !SE_REGISTRATION
