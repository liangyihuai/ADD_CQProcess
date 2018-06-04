#pragma once

#ifndef SHARED_WINDOW
#define SHARED_WINDOW

#include <map>
#include <list>
#include <queue>
#include "MyType.h"
#include "Query.h"
#include "Condition.h"

namespace shared {
	//custom queue
	template <class T>
	class Node {
	public:
		Node() {}
		Node(T data) : data(data) {}
		Node<T> * next = nullptr;
		T  data = nullptr;

		int use_count = 0; // indicate how many end_pointers point to the node.
	};

	template <class T>
	class SharedQueue {
	private:
		Node<T> * head = nullptr;//the first node
		Node<T> * tail = nullptr;//the last node
		int size = 0;//the size of the node
	public:
		Node<T> * getHead()const { return this->head; }//get the first node

		Node<T>* getTail()const { return this->tail; }//get the last node

		void push_back(T data) {//insert data next to the tail.
			Node<T> * newNode = new Node<T>(data);
			size++;
			if (!head) {
				tail = head = newNode;
				return;
			}
			else {
				tail->next = newNode;
				tail = tail->next;
			}
		}

		T pop_front() {//remove the first node and return its data.
			T result = nullptr;
			if (head == nullptr) {
				cout << "the queue is empty!" << endl;
				throw 1;
			}
			else if (head == tail) {
				result = head->data;
				tail->data = nullptr;
				tail = head = nullptr;
			}
			else {
				Node<T> * curr = head;
				head = head->next;
				curr->data = nullptr;
				curr->next = nullptr;
				result = curr->data;
				delete curr;
				curr = nullptr;
			}
			size--;
			return result;
		}

		Node<T>* front() {//get the first node
			if (head == nullptr) {
				cout << "the queue is empty!" << endl;
				throw 1;
			}
			return head;
		}

		Node<T>* back() {//get the last node
			if (head == nullptr) {
				cout << "the queue is empty!" << endl;
				throw 1;
			}
			return tail;
		}

		int getSize() {//the size of the queue
			return this->size;
		}
	};
}

using namespace shared;

template <class T> // type of query name
class SharedWindow {
private:
	//store queryID and associated endPointers of the query.
	//Each query has one endPointers. endPointer points to 
	//the oldest node of shared window standing for the query.
	map<T, Node<EventPtr>*> queryID_event_map;

	//store shared events.
	SharedQueue<EventPtr> events;

	//the query condition of the shared window. Indicating the events will store 
	//in this shared window if they meet the qury condition.
	Condition *queryCondition = nullptr;

	//store query ID of empty endPointers.
	//Over new event arriving, these empty pointers will point to the new-arriving event.
	list<string> emptyPointers;

public:
	void addEvent(EventPtr event);

	void addQuery(T queryID);

	bool pop_front(T queryID);

	void setQueryCondition(Condition * con) { this->queryCondition = con; }

	Condition* getQueryCondition() {
		if (!queryCondition) {
			cout << "the queryCondition is nullptr" << endl;
			throw 1;
		}
		return this->queryCondition; 
	}

	//get the first event of the specified query.
	EventPtr front(T queryID);

	//get the last event of the specified query.
	EventPtr back();

	int size() { return events.getSize(); }

	//inner class
	class Iterator {
	private:
		Node<EventPtr> *currPtr;
	public:
		Iterator() {}
		Iterator(Node<EventPtr> *head):currPtr(head) {}

		EventPtr getData() const {
            return currPtr->data;
        }



        Node<EventPtr>* operator->() const {
            return currPtr;
        }

		Iterator& operator++() {
            currPtr = currPtr->next;
            return *this;
        }
        
		bool operator==(const Iterator &arg) const {
             return arg.currPtr == this->currPtr;
		}

        bool operator!=(const Iterator &arg) const {
             return arg.currPtr != this->currPtr;
		}
	};


	Iterator begin(T queryID) {
		Node<EventPtr>* headNode = this->queryID_event_map[queryID];
		return Iterator(headNode);
	}

	Iterator end() const {
		const Node<EventPtr> * last = events.getTail();
		if (!last) return Iterator(nullptr);
		return Iterator(last->next);
	}

};

template <class T>
void SharedWindow<T>::addEvent(EventPtr event) {
	this->events.push_back(event);

	//set the endPointer, which is null, points to the current event node.
	Node<EventPtr>* lastNode = events.back();
	while (!emptyPointers.empty()) {
		string queryID = emptyPointers.front();
		this->queryID_event_map[queryID] = lastNode;
		lastNode->use_count++;
		emptyPointers.pop_front();
	}

	//only one data in the window, i.e. it's empty before insert the current event.
	if (events.getHead()->data == event) {
		for (auto iter = queryID_event_map.begin(); iter != queryID_event_map.end(); iter++) {
			queryID_event_map[iter->first] = events.getHead();//set endPointers
			events.getHead()->use_count++;
		}
	}
	
	//cout << "shared window size: " << events.getSize() << endl;
}

template <class T>
bool SharedWindow<T>::pop_front(T queryID) {

	Node<EventPtr>* endPointer = this->queryID_event_map[queryID];
	
	if (!endPointer) return false;

	//the endPointer is pointing to the olding node. As for the node, only one 
	//endPointer, so move forward the endPointer and pop out the first node.
	if (endPointer->use_count == 1 && endPointer == events.getHead()) {
		endPointer = endPointer->next;
		queryID_event_map[queryID] = endPointer;
		if (endPointer) endPointer->use_count++;
		events.pop_front();
	}
	else {
		endPointer->use_count--;
		endPointer = endPointer->next;
		queryID_event_map[queryID] = endPointer;
		if (endPointer)endPointer->use_count++;
	}
	//collect the empty endPointer.
	if (!endPointer)this->emptyPointers.push_back(queryID);
	return true;
}



template <class T>
void SharedWindow<T>::addQuery(T queryID) {
	this->queryID_event_map[queryID] = nullptr;
}

template <class T>
EventPtr SharedWindow<T>::front(T topicID) {
	if (!queryID_event_map[topicID])return nullptr;
	return this->queryID_event_map[topicID]->data;
}

template <class T>
EventPtr SharedWindow<T>::back() {
	if (!events.getTail())return nullptr;
	return events.getTail()->data;
}

#endif // !SHARED_WINDOW


