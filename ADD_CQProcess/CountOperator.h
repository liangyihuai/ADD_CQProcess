#pragma once

#ifndef COUNT_OPERATOR
#define COUNT_OPERATOR

#include <iostream>
#include "Query.h"
#include "SlidingWindow.h"
#include <string>
#include "MyType.h"
#include "QueryManager.h"


class CountOperator : public Query, public SlidingWindow {
public:

	CountOperator(int timeStride, string topicName)
		:Query(topicName) {
		SlidingWindow::timeStride = timeStride;
		QueryManager::addTimeTriggerQuery(topicName, this);
	}

	CountOperator(long eventStride, string topicName)
		:Query(topicName) {
		SlidingWindow::eventStride = eventStride;
		QueryManager::addEventTriggerQuery(topicName, this);
	}

	~CountOperator() {
		this->events.clear();
	}

	void insert(EventPtr event);
	void display();

private:
	long currCount = 0;
	void updateWindow();
	void eventTrigger();

	long count_shared_window = 0;

	void updateOwnWindow();

	void updateSharedWindow();

	void addEventInSharedWin(EventPtr event);
};

void CountOperator::display() {
	std::cout << "==  count" << name << " result: "<< currCount << "=="<<std::endl;
}

void CountOperator::updateWindow() {
	checkWindow();
	WINDOW_TYPE window = this->windowType;

	if (window == WINDOW_TYPE::TIME_LEN_TIME_STRIDE || window == WINDOW_TYPE::TIME_LEN_EVENT_STRIDE) {
		//window length is "timelen", return result every "stride"
		int currSize = events.size();

		//get latest event
		EventPtr latestEvent = nullptr;
		if (currSize != 0) {
			latestEvent = events.back();
		}
		if(shareWindow->back()){
			if (currSize != 0 && shareWindow->back()->time > latestEvent->time)
				latestEvent = shareWindow->back();
			else if (currSize == 0) latestEvent = shareWindow->back();
		}

		if (latestEvent) {
			long long smallestTime = latestEvent->time - endTime;
			//own window
			while (currSize > 0 && events.front()->time < smallestTime) {
				EventPtr tmpEvent = events.front();
				events.pop_front();

				currSize--;
			}
			currCount = currSize;
			//shared window
			while (count_shared_window > 0 && shareWindow->front(Query::name)->time < smallestTime) {
				if (!shareWindow->pop_front(Query::name)) {
					count_shared_window = 0;
					break;
				}
				count_shared_window--;
			}
			currCount += count_shared_window;
		}
	}
}

//void CountOperator::updateOwnWindow() {
//	WINDOW_TYPE window = this->windowType;
//	if (window == WINDOW_TYPE::eventLenEventStride
//		|| window == WINDOW_TYPE::eventLenTimeStride) {
//		//window length is sold, result result every "stride"
//		while ((long)events.size() > endEvent) {
//			events.pop_front();
//		}
//		if (events.size() == endEvent) {
//			currCount = endEvent - startEvent;
//			return;
//		}
//		else currCount = events.size();
//	}
//	else if (window == WINDOW_TYPE::timeLenTimeStride || window == WINDOW_TYPE::timeLenEventStride) {
//		//window length is "timelen", return result every "stride"
//		int currSize = events.size();
//		if (currSize == 0) {
//			currCount = 0;
//			return;
//		}
//		EventPtr latestEvent = events.back();
//		//long long biggistTime = latestEvent->time - startTime;
//		long long smallestTime = latestEvent->time - endTime;
//
//		while (currSize > 0 && events.front()->time < smallestTime) {
//			EventPtr tmpEvent = events.front();
//			events.pop_front();
//
//			currSize--;
//		}
//		currCount = currSize;
//	}
//}


//insert an event data into the circle link.
void CountOperator::insert(EventPtr event) {
	bool inSharedWin = false;//whether the event store in the shared window
	if (shareWindow) {//there is shared window
		shareWindow->getQueryCondition()->setCurrentEvent(event);
		//satisfied the query condition of shared window
		if (shareWindow->getQueryCondition()->satisfyConditon()) {
			shareWindow->addEvent(event);
			inSharedWin = true;
		}
	}
	if(!inSharedWin) events.push_back(event);
	WINDOW_TYPE window = this->windowType;
	if (window == WINDOW_TYPE::EVENT_LEN_EVENT_STRIDE || window == WINDOW_TYPE::TIME_LEN_EVENT_STRIDE) {
		eventTrigger();
	}
	else {
		//time trigger
	}
}

void CountOperator::eventTrigger() {
	eventTriggerCount++;
	//have triggered
	if (eventTriggerCount >= eventStride) {
		updateWindow();
		display();
		eventTriggerCount = 0;
	}
}

void CountOperator::addEventInSharedWin(EventPtr event) {
	count_shared_window++;
	if (shareWindow->back() == event) return;
	shareWindow->addEvent(event);
}

#endif // !COUNT_OPERATOR

