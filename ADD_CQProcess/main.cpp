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
//QueryManager queryManager;
//
//void shared1() {
//	//shared window1
//	CountOperator* cq1 = new CountOperator(1000L, "car1");
//	cq1->setTimeWindow(0, 10000);
//	Condition* condition1 = new Condition();
//	condition1->speedGreater(10);
//	condition1->speedLess(80);
//	condition1->elevationGreater(10);
//	condition1->elevationLess(80);
//	cq1->setCondition(condition1);
//	queryManager.addEventTriggerQuery(cq1->getTopic(), cq1);
//
//	CountOperator* cq2 = new CountOperator(2000L, "car1");
//	cq2->setTimeWindow(0, 30000);
//	Condition* condition2 = new Condition();
//	condition2->speedGreater(30);
//	condition2->speedLess(90);
//	cq2->setCondition(condition2);
//	queryManager.addEventTriggerQuery(cq2->getTopic(), cq2);
//
//	Condition* sharedCon1 = new Condition();
//	sharedCon1->speedGreater(30);
//	sharedCon1->speedLess(80);
//	sharedCon1->elevationGreater(10);
//	sharedCon1->elevationLess(80);
//	SharedWindow<string>* sharedWindow1 = new SharedWindow<string>();
//	sharedWindow1->setQueryCondition(sharedCon1);
//
//	cq1->setSharedWindow(sharedWindow1);
//	cq2->setSharedWindow(sharedWindow1);
//}
//
//void shared2() {
//	CountOperator* cq1 = new CountOperator(100L, "car2");
//	cq1->setTimeWindow(0, 20000);
//	Condition* condition1 = new Condition();
//	condition1->speedGreater(10);
//	condition1->speedLess(80);
//	condition1->elevationGreater(10);
//	condition1->elevationLess(80);
//	cq1->setCondition(condition1);
//	queryManager.addEventTriggerQuery(cq1->getTopic(), cq1);
//
//	CountOperator* cq2 = new CountOperator(200L, "car2");
//	cq2->setTimeWindow(0, 30000);
//	Condition* condition2 = new Condition();
//	condition2->speedGreater(30);
//	condition2->speedLess(90);
//	cq2->setCondition(condition2);
//	queryManager.addEventTriggerQuery(cq2->getTopic(), cq2);
//
//	CountOperator* cq3 = new CountOperator(400L, "car2");
//	cq3->setTimeWindow(0, 130000);
//	Condition* con3 = new Condition();
//	con3->speedGreater(0);
//	con3->speedLess(80);
//	con3->elevationGreater(5);
//	con3->elevationLess(30);
//	cq3->setCondition(con3);
//	queryManager.addEventTriggerQuery(cq3->getTopic(), cq3);
//
//	CountOperator* cq4 = new CountOperator(600L, "car2");
//	cq4->setTimeWindow(0, 20000);
//	Condition* con4 = new Condition();
//	con4->speedGreater(25);
//	con4->speedLess(100);
//	cq4->setCondition(con4);
//	queryManager.addEventTriggerQuery(cq4->getTopic(), cq4);
//
//	CountOperator* cq5 = new CountOperator(150L, "car2");
//	cq5->setTimeWindow(0, 20000);
//	Condition* con5 = new Condition();
//	con5->elevationGreater(0);
//	con5->elevationLess(40);
//	cq5->setCondition(con5);
//	queryManager.addEventTriggerQuery(cq5->getTopic(), cq5);
//
//	
//	CountOperator* cq6 = new CountOperator(400L, "car2");
//	cq6->setTimeWindow(0, 10000);
//	Condition* con6 = new Condition();
//	con6->speedGreater(40);
//	con6->speedLess(80);
//	con6->elevationGreater(10);
//	con6->elevationLess(30);
//	cq6->setCondition(con6);
//	queryManager.addEventTriggerQuery(cq6->getTopic(), cq6);
//
//	Condition* sharedCon1 = new Condition();
//	sharedCon1->speedGreater(40);
//	sharedCon1->speedLess(80);
//	sharedCon1->elevationGreater(10);
//	sharedCon1->elevationLess(30);
//	SharedWindow<string>* sharedWindow1 = new SharedWindow<string>();
//	sharedWindow1->setQueryCondition(sharedCon1);
//
//	cq1->setSharedWindow(sharedWindow1);
//	cq2->setSharedWindow(sharedWindow1);
//	cq3->setSharedWindow(sharedWindow1);
//	cq4->setSharedWindow(sharedWindow1);
//	cq5->setSharedWindow(sharedWindow1);
//	cq6->setSharedWindow(sharedWindow1);
//}
//
//void shared3() {
//	CountOperator* cq1 = new CountOperator(1000L, "car3");
//	cq1->setTimeWindow(0, 20000);
//	Condition* condition1 = new Condition();
//	condition1->speedGreater(0);
//	condition1->speedLess(60);
//	condition1->elevationGreater(50);
//	condition1->elevationLess(100);
//	cq1->setCondition(condition1);
//	queryManager.addEventTriggerQuery(cq1->getTopic(), cq1);
//
//	CountOperator* cq2 = new CountOperator(200L, "car3");
//	cq2->setTimeWindow(0, 30000);
//	Condition* condition2 = new Condition();
//	condition2->speedGreater(25);
//	condition2->speedLess(50);
//	cq2->setCondition(condition2);
//	queryManager.addEventTriggerQuery(cq2->getTopic(), cq2);
//
//	CountOperator* cq3 = new CountOperator(400L, "car3");
//	cq3->setTimeWindow(0, 130000);
//	Condition* con3 = new Condition();
//	con3->speedGreater(15);
//	con3->speedLess(65);
//	con3->elevationGreater(60);
//	con3->elevationLess(90);
//	cq3->setCondition(con3);
//	queryManager.addEventTriggerQuery(cq3->getTopic(), cq3);
//
//	CountOperator* cq4 = new CountOperator(600L, "car3");
//	cq4->setTimeWindow(0, 20000);
//	Condition* con4 = new Condition();
//	con4->speedGreater(30);
//	con4->speedLess(50);
//	con4->elevationGreater(55);
//	con4->elevationLess(95);
//	cq4->setCondition(con4);
//	queryManager.addEventTriggerQuery(cq4->getTopic(), cq4);
//
//	CountOperator* cq5 = new CountOperator(1500L, "car3");
//	cq5->setTimeWindow(0, 200000);
//	Condition* con5 = new Condition();
//	con5->elevationGreater(25);
//	con5->elevationLess(100);
//	cq5->setCondition(con5);
//	queryManager.addEventTriggerQuery(cq5->getTopic(), cq5);
//
//	Condition* sharedCon1 = new Condition();
//	sharedCon1->speedGreater(30);
//	sharedCon1->speedLess(50);
//	sharedCon1->elevationGreater(60);
//	sharedCon1->elevationLess(90);
//	SharedWindow<string>* sharedWindow1 = new SharedWindow<string>();
//	sharedWindow1->setQueryCondition(sharedCon1);
//
//	cq1->setSharedWindow(sharedWindow1);
//	cq2->setSharedWindow(sharedWindow1);
//	cq3->setSharedWindow(sharedWindow1);
//	cq4->setSharedWindow(sharedWindow1);
//	cq5->setSharedWindow(sharedWindow1);
//}
//
//
//void without_shared1() {
//	//shared window1
//	CountOperator* cq1 = new CountOperator(1000L, "car1");
//	cq1->setTimeWindow(0, 10000);
//	Condition* condition1 = new Condition();
//	condition1->speedGreater(10);
//	condition1->speedLess(80);
//	condition1->elevationGreater(10);
//	condition1->elevationLess(80);
//	cq1->setCondition(condition1);
//	queryManager.addEventTriggerQuery(cq1->getTopic(), cq1);
//
//	CountOperator* cq2 = new CountOperator(2000L, "car1");
//	cq2->setTimeWindow(0, 30000);
//	Condition* condition2 = new Condition();
//	condition2->speedGreater(30);
//	condition2->speedLess(90);
//	cq2->setCondition(condition2);
//	queryManager.addEventTriggerQuery(cq2->getTopic(), cq2);
//}
//
//void without_shared2() {
//	CountOperator* cq1 = new CountOperator(100L, "car2");
//	cq1->setTimeWindow(0, 20000);
//	Condition* condition1 = new Condition();
//	condition1->speedGreater(10);
//	condition1->speedLess(80);
//	condition1->elevationGreater(10);
//	condition1->elevationLess(80);
//	cq1->setCondition(condition1);
//	queryManager.addEventTriggerQuery(cq1->getTopic(), cq1);
//
//	CountOperator* cq2 = new CountOperator(200L, "car2");
//	cq2->setTimeWindow(0, 30000);
//	Condition* condition2 = new Condition();
//	condition2->speedGreater(30);
//	condition2->speedLess(90);
//	cq2->setCondition(condition2);
//	queryManager.addEventTriggerQuery(cq2->getTopic(), cq2);
//
//	CountOperator* cq3 = new CountOperator(400L, "car2");
//	cq3->setTimeWindow(0, 130000);
//	Condition* con3 = new Condition();
//	con3->speedGreater(0);
//	con3->speedLess(80);
//	con3->elevationGreater(5);
//	con3->elevationLess(30);
//	cq3->setCondition(con3);
//	queryManager.addEventTriggerQuery(cq3->getTopic(), cq3);
//
//	CountOperator* cq4 = new CountOperator(600L, "car2");
//	cq4->setTimeWindow(0, 20000);
//	Condition* con4 = new Condition();
//	con4->speedGreater(25);
//	con4->speedLess(100);
//	cq4->setCondition(con4);
//	queryManager.addEventTriggerQuery(cq4->getTopic(), cq4);
//
//	CountOperator* cq5 = new CountOperator(150L, "car2");
//	cq5->setTimeWindow(0, 20000);
//	Condition* con5 = new Condition();
//	con5->elevationGreater(0);
//	con5->elevationLess(40);
//	cq5->setCondition(con5);
//	queryManager.addEventTriggerQuery(cq5->getTopic(), cq5);
//
//
//	CountOperator* cq6 = new CountOperator(400L, "car2");
//	cq6->setTimeWindow(0, 10000);
//	Condition* con6 = new Condition();
//	con6->speedGreater(40);
//	con6->speedLess(80);
//	con6->elevationGreater(10);
//	con6->elevationLess(30);
//	cq6->setCondition(con6);
//	queryManager.addEventTriggerQuery(cq6->getTopic(), cq6);
//
//}
//
//void without_shared3() {
//	CountOperator* cq1 = new CountOperator(1000L, "car3");
//	cq1->setTimeWindow(0, 20000);
//	Condition* condition1 = new Condition();
//	condition1->speedGreater(0);
//	condition1->speedLess(60);
//	condition1->elevationGreater(50);
//	condition1->elevationLess(100);
//	cq1->setCondition(condition1);
//	queryManager.addEventTriggerQuery(cq1->getTopic(), cq1);
//
//	CountOperator* cq2 = new CountOperator(200L, "car3");
//	cq2->setTimeWindow(0, 30000);
//	Condition* condition2 = new Condition();
//	condition2->speedGreater(25);
//	condition2->speedLess(50);
//	cq2->setCondition(condition2);
//	queryManager.addEventTriggerQuery(cq2->getTopic(), cq2);
//
//	CountOperator* cq3 = new CountOperator(400L, "car3");
//	cq3->setTimeWindow(0, 130000);
//	Condition* con3 = new Condition();
//	con3->speedGreater(15);
//	con3->speedLess(65);
//	con3->elevationGreater(60);
//	con3->elevationLess(90);
//	cq3->setCondition(con3);
//	queryManager.addEventTriggerQuery(cq3->getTopic(), cq3);
//
//	CountOperator* cq4 = new CountOperator(600L, "car3");
//	cq4->setTimeWindow(0, 20000);
//	Condition* con4 = new Condition();
//	con4->speedGreater(30);
//	con4->speedLess(50);
//	con4->elevationGreater(55);
//	con4->elevationLess(95);
//	cq4->setCondition(con4);
//	queryManager.addEventTriggerQuery(cq4->getTopic(), cq4);
//
//	CountOperator* cq5 = new CountOperator(1500L, "car3");
//	cq5->setTimeWindow(0, 200000);
//	Condition* con5 = new Condition();
//	con5->elevationGreater(25);
//	con5->elevationLess(100);
//	cq5->setCondition(con5);
//	queryManager.addEventTriggerQuery(cq5->getTopic(), cq5);
//}
//
//int main0() {
//	/*for (int i = 0; i < 1; i++) {
//		shared1();
//		shared2();
//		shared3();
//	}*/
//
//	for (int i = 0; i < 10000; i++) {
//		without_shared1();
//		without_shared2();
//		without_shared3();
//	}
//	
//	//shared window2
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
