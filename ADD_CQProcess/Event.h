#pragma once

#ifndef EVENT
#define EVENT

#include <iostream>

using namespace std;

class Event {
public:
	long id;
	int eventType;
	string topicName;
	long long time;
	float longitude;
	float latitude;
	float speed;
	float direction;
	float elevation;

	Event() {}

	Event(long id, int eventType, string topicName, long long time,
		float lon, float lat, float speed, float direction, float elevation) {
		this->id = id;
		this->eventType = eventType;
		this->topicName = topicName;
		this->time = time;
		this->longitude = lon;
		this->latitude = lat;
		this->speed = speed;
		this->direction = direction;
		this->elevation = elevation;
	}

	//T must have a copy constructor
	Event(const Event& e) {
		id = e.id;
		eventType = e.eventType;
		topicName = e.topicName;
		time = e.time;
		longitude = e.longitude;
		latitude = e.latitude;
		speed = e.speed;
		direction = e.direction;
		elevation = e.elevation;
	}

	//T must have a trivial assignment operator
	Event& operator=(const Event& e){
		if (this == &e) return *this;
		id = e.id;
		eventType = e.eventType;
		topicName = e.topicName;
		time = e.time;
		longitude = e.longitude;
		latitude = e.latitude;
		speed = e.speed;
		direction = e.direction;
		elevation = e.elevation;
		return *this;
	}

	~Event() {}

	friend ostream& operator<<(ostream&, const Event& e);
};

ostream& operator<< (ostream &os, const Event &e) {
	os << "id:" << e.id
		<< ", time:" << e.time
		<< ",lon:" << e.longitude << ",lat:" << e.latitude
		<< ", elev:" << e.elevation
		<< ", speed:" << e.speed
		<< ",direction:" << e.direction;

	return os;
}

#endif
