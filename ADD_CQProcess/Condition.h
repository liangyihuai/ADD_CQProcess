#pragma once

#ifndef CONDITION
#define CONDITION

#include "MyType.h"

const float DEFAULT_VALUE = -9999999.0;

class Condition {
private:
	EventPtr event = nullptr;

	float speedGr = DEFAULT_VALUE;
	bool speedGrInclusive = false;
	float speedLe = DEFAULT_VALUE;
	bool speedLeInclusive = false;
	float elevationGr = DEFAULT_VALUE;
	bool elevationGrInclusive = false;
	float elevationLe = DEFAULT_VALUE;
	bool elevationLeInclusive = false;
	float directionGr = DEFAULT_VALUE;
	bool directionGrInclusive = false;
	float directionLe = DEFAULT_VALUE;
	bool directionLeInclusive = false;
public:
	

	void setCurrentEvent(EventPtr event) {
		this->event = event;
	}
	

	void speedGreater(float speed, bool isInclusive);

	void speedLess(float speed, bool isInclusive);

	void elevationGreater(float elevation, bool isInclusive);

	void elevationLess(float elevation, bool isInclusive);

	void directionLess(float direction, bool isInclusive);

	void directionGreater(float direction, bool isInclusive);

	bool satisfyConditon() {
		bool result = true;
		if (speedGr != DEFAULT_VALUE) {
			if (speedGrInclusive) result = result && event->speed >= speedGr;
			else result = result && event->speed > speedGr;
		}
		if (speedLe != DEFAULT_VALUE) {
			if (speedLeInclusive) result = result && event->speed <= speedLe;
			else result = result && event->speed < speedLe;
		}
		if (elevationGr != DEFAULT_VALUE) {
			if (elevationGrInclusive) result = result && event->elevation >= elevationGr;
			else result = result && event->elevation > elevationGr;
		}
		if (elevationLe != DEFAULT_VALUE) {
			if (elevationLeInclusive)result = result && event->elevation <= elevationLe;
			else result = result && event->elevation < elevationLe;
		}
		if (directionGr != DEFAULT_VALUE) {
			if (directionGrInclusive)result = result && event->direction >= directionGr;
			else result = result && event->direction > directionGr;
		}
		if (directionLe != DEFAULT_VALUE) {
			if (directionLeInclusive) result = result && event->direction <= directionLe;
			else result = result && event->direction < directionLe;
		}
		return result;
	}
};


void Condition::speedGreater(float speed, bool isInclusive) {
	this->speedGr = speed;
	this->speedGrInclusive = isInclusive;
}

void Condition::speedLess(float speed, bool isInclusive) {
	this->speedLe = speed;
	this->speedLeInclusive = isInclusive;
}


void Condition::elevationGreater(float elevation, bool isInclusive) {
	this->elevationGr = elevation;
	this->elevationGrInclusive = isInclusive;
}

void Condition::elevationLess(float elevation, bool isInclusive) {
	this->elevationLe = elevation;
	this->elevationLeInclusive = isInclusive;
}

void Condition::directionGreater(float direction, bool isInclusive) {
	this->directionGr = direction;
	this->directionGrInclusive = isInclusive;
}

void Condition::directionLess(float direction, bool isInclusive) {
	this->directionLe = direction;
	this->directionLeInclusive = isInclusive;
}

#endif // !CONDITION
