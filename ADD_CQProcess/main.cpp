//#include <iostream>
//#include "QueryManager.h"
//#include "Event.h"
//#include "Query.h"
//#include "IncomingManager.h"
//#include "CountOperator.h"
//#include "Condition.h"
//#include "MyType.h"
//
//#include <vector>
//
//
//int main1() {
//	QueryManager queryManager;
//
//	CountOperator cq1(2L, "car1");
//	cq1.setEventWindow(0, 20);
//	Condition condition1;
//	condition1.speedGreater(40, false);
//	condition1.speedLess(50, true);
//	cq1.setCondition(&condition1);
//	queryManager.addEventTriggerQuery(cq1.getTopic(), &cq1);
//
//	CountOperator cq2(2L, "car1");
//	cq2.setTimeWindow(0, 6000);
//	Condition condition2;
//	condition2.elevationGreater(60, false);
//	cq2.setCondition(&condition2);
//	queryManager.addEventTriggerQuery(cq2.getTopic(), &cq2);
//
//	startGenerateEvent();
//
//	IncomingManager* incomingManager = new IncomingManager();
//	incomingManager->outputEvents();
//
//	system("pause");
//	return 0;
//}
//
//
