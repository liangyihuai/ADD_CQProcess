//#pragma once
//
//#ifndef QUERY_CONDITION
//#define QUERY_CONDITION
//#include "Query.h"
//#include "Event.h"
//#include "MyType.h"
//
//class QueryCondition {
//private:
//	
//public:
//
//	bool speedGreater(float speed, bool isInclusive, EventPtr eventPtr);
//
//	bool speedLess(float speed, bool isInclusive, EventPtr eventPtr);
//
//	bool elevationGreater(float elevation, bool isInclusive, EventPtr eventPtr);
//
//	bool elevationLess(float elevation, bool isInclusive, EventPtr eventPtr);
//
//	bool directionInterval(float start, float end, EventPtr eventPtr);
//
//	bool locationCircle(float longitude, float latitude, float radius);
//
//	bool locationSquare(float longitude, float latitude, float sideLen);
//
//	bool movingDisplacement(float startLon, float startLat, float endLon,
//								float endLat, float min, float max);
//
//};
//#endif // !QUERY_CONDITION
//
//bool QueryCondition::speedGreater(float speed, bool isInclusive, EventPtr event) {
//	if (isInclusive) {
//		return event->speed >= speed;
//	}
//	else {
//		return event->speed > speed;
//	}
//}
//
//bool QueryCondition::speedLess(float speed, bool isInclusive, EventPtr event) {
//	if (isInclusive) {
//		return event->speed <= speed;
//	}
//	else {
//		return event->speed < speed;
//	}
//}
//
//
//bool QueryCondition::elevationGreater(float elevation, bool isInclusive, EventPtr event) {
//	if (isInclusive) return event->elevation >= elevation;
//	else return event->elevation > elevation;
//}
//
//bool QueryCondition::elevationLess(float elevation, bool isInclusive, EventPtr event) {
//	if (isInclusive) return event->elevation <= elevation;
//	else return event->elevation < elevation;
//}
//
//bool QueryCondition::directionInterval(float start, float end, EventPtr event) {
//	return event->direction >= start && event->direction <= end;
//}
//
////bool QueryCondition::locationCircle(float longitude, float latitude, float radius) {
////
////}
////
////bool QueryCondition::locationSquare(float longitude, float latitude, float sideLen) {
////
////}
////
////bool QueryCondition::movingDisplacement(float startLon, float startLat, float endLon,
////	float endLat, float min, float max) {
////
////}
//
