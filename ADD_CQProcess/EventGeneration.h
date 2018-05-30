#pragma once
#ifndef EVENT_GENERATION

#include <iostream>
#include <string>
#include "MyType.h"
#include "TopicTuple.h"
#include "SERegistration.h"
#include "ClassFactory.h"

class EventGeneration {
private:
	
public:

	static EventPtr generateEvent(TopicTuple* tuple);
};
#endif // !EVENT_GENERATION


EventPtr EventGeneration::generateEvent(TopicTuple* tuple) {
	string topicName = tuple->topicName;
	EventPtr event = ClassFactory::getInstance().getClassByName(topicName, tuple);
	return event;
}
