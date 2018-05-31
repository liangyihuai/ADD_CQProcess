#pragma once

#ifndef QUERY
#define QUERY

#include "Event.h"

#include <iostream>
#include "utils.h"
#include <string>
#include "MyType.h"
#include "Condition.h"

class Query {
protected:
	//topic name of event stream. 
	string topicName;

	//query condition of this query.
	Condition * condition = nullptr;

public:
	Query(string topicName) :topicName(topicName) {
		this->name = to_string(querySize++);
	}

	Query(string queryName, string topicName) {
		this->name = queryName;
		this->topicName = topicName;
	}

	//the name of this query, also indicates the query ID.
	//so each query has an unique name.
	string name = "";

	void setTopic(string topicName) { this->topicName = topicName; }

	string getTopic() { return this->topicName; }

	void setCondition(Condition * conditon) {this->condition = conditon;}

	virtual void insert(EventPtr event) = 0;

	virtual void display() = 0;

	bool matchingCondition(EventPtr event);

};
#endif // !QUERY


bool Query::matchingCondition(EventPtr event) {
	if (!this->condition) {
		cout << "the query condition is unset!" << endl;
		throw 1;
	}
	condition->setCurrentEvent(event);
	return condition->satisfyConditon();
}


