#pragma once

#ifndef SLIDING_WINDOW
#define SLIDING_WINDOW

#include <iostream>
#include <list>
#include "Event.h"
#include "MyType.h"
#include "SharedWindow.h"

#define DEFAULT_WINDOW_CAPACITY 1000

enum WINDOW_TYPE{
	TIME_LEN_TIME_STRIDE,
	TIME_LEN_EVENT_STRIDE,
	EVENT_LEN_TIME_STRIDE,
	EVENT_LEN_EVENT_STRIDE
};

class SlidingWindow {
protected:
	//protected:
	int startTime = 0;//millisecond, the start time of the window
	//millisecond, the end time of the window
	//endTime is earlier than startTime, i.e. endTime is smaller than startTime
	int endTime = 0; 
	long startEvent = 0;
	long endEvent = 0;
	int timeStride = 0;//millisecond, time stride to pre-process.
	long eventStride = 0;

	list<EventPtr> events;
	

	//it increase 1 over one event arrival. if it equals to eventIntervalLen, 
	//It triggers to result the result, and it is set to 0.
	int eventTriggerCount = 0;

	WINDOW_TYPE windowType;


	SharedWindow<string>* shareWindow = nullptr;
	

public:
	SlidingWindow(){}

	void setTimeWindow(int startTime, int offset) {
		this->startTime = startTime;
		this->endTime = startTime + offset;

		this->windowType = getWindowType();
		//this->events = new list<EventPtr>(DEFAULT_WINDOW_CAPACITY);
	}

	void setSharedWindow(SharedWindow<int>* sharedWindow) {
		this->shareWindow = sharedWindow;
	}

	/*void setTimeInterval(long timeLength) {
		this->timeIntervalLen = timeLength;
	}*/

	void setEventWindow(long startEvent, long offset) {
		this->startEvent = startEvent;
		this->endEvent = startEvent + offset;

		this->windowType = getWindowType();
		//this->events = new list<EventPtr>(startEvent+offset);
	}

	//void setEventInterval(long eventNum) {
	//	this->eventIntervalLen = eventNum;
	//}

	virtual void updateWindow() = 0;

	void checkWindow() {
		if ((timeStride != 0 && eventStride != 0)
			|| (timeStride == 0 && eventStride == 0)) {
			std::cout << "both 0 or neither 0" << std::endl;
			throw 0;
		}
		
		if ((endTime == 0 && endEvent == 0)
			|| (endTime != 0 && endEvent != 0)) {
			std::cout << "both 0 or neither 0" << std::endl;
			throw 0;
		}
	}


	WINDOW_TYPE getWindowType() {
		checkWindow();
		if (endTime != 0) {
			if (timeStride != 0) 
				return WINDOW_TYPE::TIME_LEN_TIME_STRIDE;
			else return WINDOW_TYPE::TIME_LEN_EVENT_STRIDE;
		}
		else {
			if (timeStride != 0)
				return WINDOW_TYPE::EVENT_LEN_TIME_STRIDE;
			else return WINDOW_TYPE::EVENT_LEN_EVENT_STRIDE;
		}
	}
};

#endif // !SLIDING_WINDOW

