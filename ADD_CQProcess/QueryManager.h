#pragma once

#ifndef QUERY_MANAGER
#define QUERY_MANAGER

#include <iostream>
#include <map>
#include "Query.h"
#include <set>
#include "MyType.h"

static class QueryManager {
public:
	static void addTimeTriggerQuery(string topicName, Query * query) {
		if (timeTriggerQueries.find(topicName) == timeTriggerQueries.end()) {
			set<Query*> * newSet = new set<Query*>();//create a new set as the value of the map
			newSet->insert(query);
			timeTriggerQueries[topicName] = newSet;
		}
		else timeTriggerQueries[topicName]->insert(query);
	}

	static void addEventTriggerQuery(string topicName, Query * query) {
		if (eventTriggerQueries.find(topicName) == eventTriggerQueries.end()) {
			set<Query*> * newSet = new set<Query*>();//create a new set as the value of the map
			newSet->insert(query);
			eventTriggerQueries[topicName] = newSet;
		}
		else eventTriggerQueries[topicName]->insert(query);
	}

	static bool deleteQuery(string &topicName) {}

	static set<Query*>* getQuery(string &topicName) {
		if (eventTriggerQueries.find(topicName) != eventTriggerQueries.end()) {
			return eventTriggerQueries[topicName];
		}
		if (timeTriggerQueries.find(topicName) != timeTriggerQueries.end()) {
			return timeTriggerQueries[topicName];
		}
		return nullptr;
	}

	static void matchCQs(EventPtr event) {
		//time trigger queries
		for (auto iter = timeTriggerQueries.begin(); iter != timeTriggerQueries.end(); iter++) {//map
			set<Query*> * vec = iter->second;
			for (auto vecIter = vec->begin(); vecIter != vec->end(); vecIter++) {//vector
				if ((*vecIter)->matchingCondition(event)) {
					updateCQ(*vecIter, event);
				}
			}	
		}
		//event trigger queries
		for (auto iter = eventTriggerQueries.begin(); iter != eventTriggerQueries.end(); iter++) {//map
			set<Query*> * vec = iter->second;
			for (auto vecIter = vec->begin(); vecIter != vec->end(); vecIter++) {//vector
				//cout << *event << endl;
				if ((*vecIter)->matchingCondition(event)) {
					//cout << "-count-" << *event << endl;
					updateCQ(*vecIter, event);
				}
			}

		}
	}

	static void updateCQ(Query* query, EventPtr eventPtr) {
		query->insert(eventPtr);
	}

	static void timeTrigger() {}

private:
	// topic name <-> Query object
	//store the queies triggered by event arrival
	static map<string, set<Query*>*> eventTriggerQueries;
	
	//store the queies triggered by time.
	static map<string, set<Query*>*> timeTriggerQueries;

};

map<string, set<Query*>*> QueryManager::eventTriggerQueries;

map<string, set<Query*>*> QueryManager::timeTriggerQueries;

#endif // !QUERY_MANAGER
