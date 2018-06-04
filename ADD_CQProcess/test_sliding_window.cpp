#include <iostream>
#include "MyType.h"
#include <boost/shared_ptr.hpp>
#include "IncomingManager.h"
#include "CountOperator.h"
#include <chrono>
#include <thread>

using namespace std;

bool ran = false;

void test_count_operator() {
	
	//generate 10 event.
	for (int i = 0; i < 20; i++) {
		boost::shared_ptr<Event> msg(new Event());
		//EventPtr msg(new Event());
		msg->id = IncomingManager::eventID++;
		msg->direction = randomFloat(0, 360);
		msg->topicName = "car1";
		msg->elevation = random(30, 50);
		msg->speed = random(10, 15);
		if (ran) {
			msg->longitude = random(30, 50);
			msg->latitude = random(30, 50);
			ran = !ran;
		}
		else {
			msg->longitude = random(51, 100);
			msg->latitude = random(51, 100);
			ran = !ran;
		}
		
		msg->time = getTime();

		//cout << *msg << endl;
		IncomingManager::reveiveEvents(msg);
	}



	CountOperator* cq1 = new CountOperator(2L, "car1");
	cq1->setTimeWindow(0, 10000);
	Condition* condition1 = new Condition();
	condition1->rectangleRegion(30, 30, 50, 50);
	cq1->setCondition(condition1);
	QueryManager::addEventTriggerQuery(cq1->getTopic(), cq1);

	IncomingManager* incomingManager = new IncomingManager();
	incomingManager->outputEvents();
}

void generate() {
	this_thread::sleep_for(chrono::milliseconds(3500));
	cout << "====================3.5 second later==============\n" << endl;

	//generate 10 event.
	for (int i = 0; i < 6; i++) {
		boost::shared_ptr<Event> msg(new Event());
		//EventPtr msg(new Event());
		msg->id = IncomingManager::eventID++;
		msg->direction = randomFloat(0, 360);
		msg->topicName = "car1";
		msg->elevation = random(30, 50);
		msg->speed = random(10, 15);
		if (ran) {
			msg->longitude = random(30, 50);
			msg->latitude = random(30, 50);
			ran = !ran;
		}
		else {
			msg->longitude = random(51, 100);
			msg->latitude = random(51, 100);
			ran = !ran;
		}

		msg->time = getTime();

		//cout << *msg << endl;
		IncomingManager::reveiveEvents(msg);
	}
}

//first generage 10 events, after 3.5s, generate another 10 events.
void test_sliding_window() {
	CountOperator* cq1 = new CountOperator(2L, "car1");
	cq1->setTimeWindow(0, 3000);
	Condition* condition1 = new Condition();
	condition1->rectangleRegion(30, 30, 50, 50);
	cq1->setCondition(condition1);
	QueryManager::addEventTriggerQuery(cq1->getTopic(), cq1);

	//generate 10 event.
	for (int i = 0; i < 6; i++) {
		boost::shared_ptr<Event> msg(new Event());
		//EventPtr msg(new Event());
		msg->id = IncomingManager::eventID++;
		msg->direction = randomFloat(0, 360);
		msg->topicName = "car1";
		msg->elevation = random(30, 50);
		msg->speed = random(10, 15);
		if (ran) {
			msg->longitude = random(30, 50);
			msg->latitude = random(30, 50);
			ran = !ran;
		}
		else {
			msg->longitude = random(40, 70);
			msg->latitude = random(40, 70);
			ran = !ran;
		}

		msg->time = getTime();

		//cout << *msg << endl;
		IncomingManager::reveiveEvents(msg);
	}

	thread task(generate);
	task.detach();

	
	IncomingManager::outputEvents();
}

void test_shared_window() {
	//shared window1
	CountOperator* cq1 = new CountOperator(2L, "car1");
	cq1->setTimeWindow(0, 10000);
	Condition* condition1 = new Condition();
	condition1->rectangleRegion(30, 30, 50, 50);
	cq1->setCondition(condition1);
	QueryManager::addEventTriggerQuery(cq1->getTopic(), cq1);
	
	CountOperator* cq2 = new CountOperator(2L, "car1");
	cq2->setTimeWindow(0, 30000);
	Condition* condition2 = new Condition();
	condition2->rectangleRegion(40, 40, 60, 60);
	cq2->setCondition(condition2);
	QueryManager::addEventTriggerQuery(cq2->getTopic(), cq2);
	
	Condition* sharedCon1 = new Condition();
	sharedCon1->rectangleRegion(40, 40, 50, 50);
	SharedWindow<string>* sharedWindow1 = new SharedWindow<string>();
	sharedWindow1->setQueryCondition(sharedCon1);
	
	cq1->setSharedWindow(sharedWindow1);
	cq2->setSharedWindow(sharedWindow1);

	//generate 10 event.
	for (int i = 0; i < 20; i++) {
		boost::shared_ptr<Event> msg(new Event());
		//EventPtr msg(new Event());
		msg->id = IncomingManager::eventID++;
		msg->direction = randomFloat(0, 360);
		msg->topicName = "car1";
		msg->elevation = 12.0;
		if (i < 2) msg->speed = 32;
		else if (i < 6) msg->speed = 45;
		else msg->speed = 55;
		msg->longitude = random(20, 70);
		msg->latitude = random(20, 70);
		msg->time = getTime();

		//cout << *msg << endl;
		IncomingManager::reveiveEvents(msg);
	}

	IncomingManager::outputEvents();
}

int main() {
	//test_count_operator();
	test_sliding_window();
	//test_shared_window();
	
	

	system("pause");
	return 0;
}