#pragma once
#include <map>
#include "TopicTuple.h"
#include "MyType.h"

#ifndef PTR_CREATE_OBJECT
#define PTR_CREATE_OBJECT

typedef EventPtr (*PTRCreateObject)(TopicTuple* tuple);
#endif // !PTR_CREATE_OBJECT

#ifndef EVENT_FACTORY
#define EVENT_FACTORY



class ClassFactory {
private:
	map<string, PTRCreateObject> m_classMap;
	ClassFactory() {}; //构造函数私有化

public:
	EventPtr getClassByName(string className, TopicTuple* tuple);
	void registClass(string name, PTRCreateObject method);
	static ClassFactory& getInstance();
};


ClassFactory& ClassFactory::getInstance() {
	static ClassFactory sLo_factory;
	return sLo_factory;
}

EventPtr ClassFactory::getClassByName(string className, TopicTuple* tuple) {
	map<string, PTRCreateObject>::const_iterator iter;
	iter = m_classMap.find(className);
	if (iter == m_classMap.end())
		return nullptr;
	else
		return iter->second(tuple);
}


void ClassFactory::registClass(string name, PTRCreateObject method) {
	m_classMap.insert(pair<string, PTRCreateObject>(name, method));
}
#endif // !EVENT_FACTORY
