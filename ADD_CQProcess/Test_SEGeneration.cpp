#include <iostream>
#include "Car1Topic.h"
#include "ClassFactory.h"
#include "MyType.h"
#include "EventGeneration.h"
#include "Car2Topic.h"

int main() {
	Car1Topic car1;
	car1.elevation = 13;
	car1.topicName = "car1";

	Car2Topic car2;
	car2.elevation = 16;
	car2.topicName = "car2";

	TopicTuple* tuple_car1 = (TopicTuple*)&car1;
	TopicTuple* tuple_car2 = (TopicTuple*)&car2;

	EventPtr event1 = EventGeneration::generateEvent(tuple_car1);
	EventPtr event2 = EventGeneration::generateEvent(tuple_car2);

	std::cout << event1->elevation << "," <<event1->topicName << std::endl;
	std::cout << event2->elevation << "," <<event2->topicName << std::endl;

	system("pause");
	return 0;
}