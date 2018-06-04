#pragma once

#ifndef CONDITION
#define CONDITION

#include "MyType.h"

const float DEFAULT_VALUE = -9999999.0;

class Condition {
private:
	friend ostream& operator<<(ostream&, const Condition& c);

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
	
	float lon_region1 = DEFAULT_VALUE;//longitude
	float lat_region1 = DEFAULT_VALUE;//latitude
	float lon_region2 = DEFAULT_VALUE;//longitude
	float lat_region2 = DEFAULT_VALUE;//latitude

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

	Condition* rectangleRegion(float lon1, float lat1, float lon2, float lat2);

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

		if (lon_region1 != DEFAULT_VALUE && lon_region2 != DEFAULT_VALUE) {
			if (event->longitude >= lon_region1 && event->latitude >= lat_region1
				&& event->longitude <= lon_region2 && event->latitude <= lat_region2) {
				result = result && true;
			}
			else result = result && false;
		}
		
		return result;
	}

	Condition* setSpeedCondition(float down, float up, bool downInclusive, bool upInclusive);
	Condition* setElevationCondition(float down, float up, bool downInclusive, bool upInclusive);
	Condition* setDirectionCondition(float down, float up, bool downInclusive, bool upInclusive);
};

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

Condition* Condition::rectangleRegion(float lon1, float lat1, float lon2, float lat2) {
	this->lon_region1 = lon1;
	this->lat_region1 = lat1;
	this->lon_region2 = lon2;
	this->lat_region2 = lat2;
	return this;
}

Condition* Condition::setSpeedCondition(float down, float up, bool downInclusive = false, bool upInclusive = false) {
	this->speedGreater(down, downInclusive);
	this->speedLess(up, downInclusive);
	return this;
}

Condition* Condition::setElevationCondition(float down, float up, bool downInclusive = false, bool upInclusive = false) {
	this->elevationGreater(down, downInclusive);
	this->elevationLess(up, upInclusive);
	return this;
}

Condition* Condition::setDirectionCondition(float down, float up, bool downInclusive = false, bool upInclusive = false) {
	this->directionGreater(down, downInclusive);
	this->directionLess(up, upInclusive);
	return this;
}

ostream& operator<< (ostream &os, const Condition &c) {
	os << "query_condition: ";
	if (c.lon_region1 != DEFAULT_VALUE && c.lon_region2 != DEFAULT_VALUE) {
		os << "region:[(" << c.lon_region1 <<", " << c.lat_region1 << "), (" << c.lon_region2 << ", " << c.lat_region2<<")], ";
	}
	if (c.speedLe != DEFAULT_VALUE && c.speedGr != DEFAULT_VALUE) {
		os << c.speedGr <<"<speed< " << c.speedLe << ", ";
	}

	if (c.elevationLe != DEFAULT_VALUE && c.elevationGr != DEFAULT_VALUE) {
		os << c.elevationGr << "<elevation< " << c.elevationLe << ", ";
	}
	if (c.directionLe != DEFAULT_VALUE && c.directionGr != DEFAULT_VALUE) {
		os << c.directionGr << "<direction< " << c.directionLe << ", ";
	}

	return os;
}

#endif // !CONDITION


