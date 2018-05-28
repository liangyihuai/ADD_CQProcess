//#include <iostream>
//#include "SharedWindow.h"
//#include "MyType.h"
//using namespace sharedWindow;
//
//int main() {
//
//	EventPtr e1(new Event());
//	cout << e1.use_count() << endl;
//
//	SharedQueue<EventPtr> q;
//	q.push_back(e1);
//	q.push_back(e1);
//
//
//	cout << e1.use_count() << endl;
//
//	cout << "size = " << q.getSize() << endl;
//	q.pop_front();
//	cout << e1.use_count() << endl;
//	q.pop_front();
//	cout << e1.use_count() << endl;
//
//	
//
//	system("pause");
//	return 0;
//}