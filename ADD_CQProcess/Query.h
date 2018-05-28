#pragma once

#ifndef QUERY
#define QUERY


#include "Event.h"

#include <iostream>
#include "utils.h"
#include <string>
#include "MyType.h"
#include "Condition.h"

//a pointer points to a function.
//typedef bool(*ConditionFuncType)(EventPtr eventPtr);


class Query {
protected:
	string topicName;

	Condition * condition = nullptr;

public:
	Query(string topicName) :topicName(topicName) {
		this->name = to_string(querySize++);
	}

	Query(string queryName, string topicName) {
		this->name = queryName;
		this->topicName = topicName;
	}

	string name = "";

	void setTopic(string topicName) { this->topicName = topicName; }

	string getTopic() { return this->topicName; }

	void setCondition(Condition * conditon) {
		this->condition = conditon;
	}

	virtual void insert(EventPtr event) = 0;

	virtual void display() = 0;

	bool matchingCondition(EventPtr event) {
		if (!this->condition) {
			cout << "the query condition is unset!" << endl;
			throw 1;
		}
		condition->setCurrentEvent(event);
		return condition->satisfyConditon();
	}


	//ConditionFuncType conditionFunction = nullptr;

};
#endif // !QUERY

