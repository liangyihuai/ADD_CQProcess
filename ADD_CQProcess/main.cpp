#include <iostream>
#include "QueryManager.h"
#include "Event.h"
#include "Query.h"
#include "IncomingManager.h"
#include "CountOperator.h"
#include "Condition.h"
#include "MyType.h"

#include <vector>


int main() {
	QueryManager queryManager;

	CountOperator cq1(1L, "car1");
	cq1.setTimeWindow(0, 10000);
	Condition condition1;
	condition1.speedGreater(10);
	condition1.speedLess(80);
	condition1.elevationGreater(10);
	condition1.elevationLess(80);
	cq1.setCondition(&condition1);
	queryManager.addEventTriggerQuery(cq1.getTopic(), &cq1);

	CountOperator cq2(2L, "car1");
	cq2.setTimeWindow(0, 3000);
	Condition condition2;
	condition2.speedGreater(30);
	condition2.speedLess(90);
	cq2.setCondition(&condition2);
	queryManager.addEventTriggerQuery(cq2.getTopic(), &cq2);

	Condition sharedCon1;
	sharedCon1.speedGreater(30);
	sharedCon1.speedLess(80);
	sharedCon1.elevationGreater(10);
	sharedCon1.elevationLess(80);
	SharedWindow<string> sharedWindow1;
	sharedWindow1.setQueryCondition(&sharedCon1);

	cq1.setSharedWindow(&sharedWindow1);
	cq2.setSharedWindow(&sharedWindow1);

	startGenerateEvent();

	IncomingManager* incomingManager = new IncomingManager();
	incomingManager->outputEvents();

	system("pause");
	return 0;
}


