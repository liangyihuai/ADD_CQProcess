#pragma once
#ifndef QUERIES
#define QUERIES

#include "Condition.h"
#include "CountOperator.h"
#include "QueryManager.h"
#include "IncomingManager.h"

static class Queries {
private:

public:
	static void countBySpeed(string topicName, float down, float up, bool downInclusive, bool upInclusive,
		int timeWinLen, long eventTrigger);

	static void countByElevation(string topicName, float down, float up, bool downInclusive ,
		bool upInclusive , int timeWinLen , long eventTrigger);

	static void countByDirection(string topicName, float down, float up, bool downInclusive,
		bool upInclusive , int timeWinLen, long eventTrigger);

	static void countByRectRegion(string topicName, float lon_left_bot, float lat_left_bot, float lon_right_up, float lat_right_up, int timeWinLen , long eventTrigger);

	static Condition* countByMultiCondition(string topicName, int timeWinLen, long eventTrigger);

	static void start();
};

void Queries::countBySpeed(string topicName, float down, float up, bool downInclusive = false, 
		bool upInclusive = false, int timeWinLen = 1000, long eventTrigger = 1L) {
	CountOperator* cq1 = new CountOperator(eventTrigger, topicName);
	cq1->setTimeWindow(0, timeWinLen);
	Condition* condition = new Condition();
	condition->speedGreater(down);
	condition->speedLess(up);
	cq1->setCondition(condition);
	QueryManager::addEventTriggerQuery(cq1->getTopic(), cq1);
}

void Queries::countByElevation(string topicName, float down, float up, bool downInclusive = false,
	bool upInclusive = false, int timeWinLen = 1000, long eventTrigger = 1) {
	CountOperator* cq1 = new CountOperator(eventTrigger, topicName);
	cq1->setTimeWindow(0, timeWinLen);
	Condition* condition = new Condition();
	condition->elevationGreater(down);
	condition->elevationLess(up);
	cq1->setCondition(condition);
	QueryManager::addEventTriggerQuery(cq1->getTopic(), cq1);
}

void Queries::countByDirection(string topicName, float down, float up, bool downInclusive = false,
	bool upInclusive = false, int timeWinLen = 1000, long eventTrigger = 1) {
	CountOperator* cq1 = new CountOperator(eventTrigger, topicName);
	cq1->setTimeWindow(0, timeWinLen);
	Condition* condition = new Condition();
	condition->directionGreater(down);
	condition->directionLess(up);
	cq1->setCondition(condition);
	QueryManager::addEventTriggerQuery(cq1->getTopic(), cq1);
}

void Queries::countByRectRegion(string topicName, float lon_left_bot, float lat_left_bot,
	float lon_right_up, float lat_right_up, int timeWinLen = 1000, long eventTrigger = 1) {
	CountOperator* cq1 = new CountOperator(eventTrigger, topicName);
	cq1->setTimeWindow(0, timeWinLen);
	Condition* condition = new Condition();
	condition->rectangleRegion(lon_left_bot, lat_left_bot, lon_right_up, lat_right_up);
	cq1->setCondition(condition);
	QueryManager::addEventTriggerQuery(cq1->getTopic(), cq1);
}


Condition* Queries::countByMultiCondition(string topicName, int timeWinLen, long eventTrigger) {
	CountOperator* cq1 = new CountOperator(eventTrigger, topicName);
	cq1->setTimeWindow(0, timeWinLen);
	Condition* condition = new Condition();
	cq1->setCondition(condition);
	return condition;
}

void Queries::start() {
	IncomingManager* incomingManager = new IncomingManager();
	incomingManager->outputEvents();
}

#endif // !QUERIES