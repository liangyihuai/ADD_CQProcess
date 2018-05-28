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

	//whether the event is satisfied the query condition.
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

	/*bool satisfyConditon() {
		bool result = true;
		if (speedGr != DEFAULT_VALUE && speedLe != DEFAULT_VALUE) {
			if (speedGr == speedLe && speedGrInclusive && speedLeInclusive) {
				result = result && event->speed == speedGr;
			}
			else {
				bool tmp = true;
				if (speedGrInclusive)tmp = event->speed >= speedGr;
				else tmp = event->speed > speedGr;

				if (speedLeInclusive)tmp = tmp || event->speed <= speedLe;
				else tmp = tmp || event->speed < speedLe;

				result = result && tmp;
			}
		}
		else {
			if (speedGr != DEFAULT_VALUE) {
				if (speedGrInclusive) result = result && event->speed >= speedGr;
				else result = result && event->speed > speedGr;
			}
			if (speedLe != DEFAULT_VALUE) {
				if (speedLeInclusive) result = result && event->speed <= speedLe;
				else result = result && event->speed < speedLe;
			}
		}

		if (elevationGr != DEFAULT_VALUE && elevationLe != DEFAULT_VALUE) {
			if (elevationGr == elevationLe && elevationGrInclusive && elevationLeInclusive) {
				result = result && event->elevation == elevationGr;
			}
			else {
				bool tmp = true;
				if (elevationGrInclusive) tmp = event->elevation >= elevationGr;
				else tmp = event->elevation > elevationGr;

				if (elevationLeInclusive) tmp = tmp || event->elevation <= elevationLe;
				else tmp = tmp || event->elevation < elevationLe;

				result = result && tmp;
			}
		}
		else {
			if (elevationGr != DEFAULT_VALUE) {
				if (elevationGrInclusive) result = result && event->elevation >= elevationGr;
				else result = result && event->elevation > elevationGr;
			}
			if (elevationLe != DEFAULT_VALUE) {
				if (elevationLeInclusive)result = result && event->elevation <= elevationLe;
				else result = result && event->elevation < elevationLe;
			}
		}
		
		if (directionGr != DEFAULT_VALUE && directionLe != DEFAULT_VALUE) {
			if (directionGr == directionLe && directionGrInclusive && directionLeInclusive) {
				result = result && event->direction == directionGr;
			}
			else {
				bool tmp = true;
				if (directionGrInclusive) tmp = event->direction >= directionGr;
				else tmp = event->direction > directionGr;

				if (directionLeInclusive) tmp = tmp || event->direction <= directionLe;
				else tmp = tmp || event->direction < directionLe;

				result = result && tmp;
			}
		}
		else {
			if (directionGr != DEFAULT_VALUE) {
				if (directionGrInclusive)result = result && event->direction >= directionGr;
				else result = result && event->direction > directionGr;
			}
			if (directionLe != DEFAULT_VALUE) {
				if (directionLeInclusive) result = result && event->direction <= directionLe;
				else result = result && event->direction < directionLe;
			}
		}
		
		
		return result;
	}
};*/


void Condition::speedGreater(float speed, bool isInclusive=false) {
	this->speedGr = speed;
	this->speedGrInclusive = isInclusive;
}

void Condition::speedLess(float speed, bool isInclusive = false) {
	this->speedLe = speed;
	this->speedLeInclusive = isInclusive;
}


void Condition::elevationGreater(float elevation, bool isInclusive = false) {
	this->elevationGr = elevation;
	this->elevationGrInclusive = isInclusive;
}

void Condition::elevationLess(float elevation, bool isInclusive = false) {
	this->elevationLe = elevation;
	this->elevationLeInclusive = isInclusive;
}

void Condition::directionGreater(float direction, bool isInclusive = false) {
	this->directionGr = direction;
	this->directionGrInclusive = isInclusive;
}

void Condition::directionLess(float direction, bool isInclusive=false) {
	this->directionLe = direction;
	this->directionLeInclusive = isInclusive;
}

#endif // !CONDITION
