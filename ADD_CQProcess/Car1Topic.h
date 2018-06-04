#pragma once

#ifndef CAR1_TOPIC
#define CAR1_TOPIC

#include "SERegistration.h"
#include "MyType.h"
#include "TopicTuple.h"

class Car1Topic: public TopicTuple{

private:

public:
	float elevation;
};

EventPtr createEventObjCar1(TopicTuple* tuple) {
	Car1Topic* car = (Car1Topic*)tuple;
	EventPtr event(new Event());
	event->topicName = car->topicName;
	event->elevation = car->elevation;
	return event;
}

SERegistration registration1("car1", (PTRCreateObject)createEventObjCar1);

#endif // !CAR1_TOPIC
