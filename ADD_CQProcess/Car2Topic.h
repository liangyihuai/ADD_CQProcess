#pragma once

#ifndef CAR2_TOPIC

#include "SERegistration.h"
#include "MyType.h"
#include "TopicTuple.h"

class Car2Topic : public TopicTuple {

private:

public:
	float elevation;
};

EventPtr createEventObjCar2(TopicTuple* tuple) {
	Car2Topic* car = (Car2Topic*)tuple;
	EventPtr event(new Event());
	event->topicName = car->topicName;
	event->elevation = car->elevation;
	return event;
}

SERegistration registration2("car2", (PTRCreateObject)createEventObjCar2);

#endif // !CAR2_TOPIC
