#pragma once

#ifndef SHARED_WINDOW
#define SHARED_WINDOW

#include <map>
#include <list>
#include <queue>
#include "MyType.h"
#include "Query.h"
#include "Condition.h"

namespace sharedWindow {
	template <class T>
	class Node {
	public:
		Node() {}
		Node(T data) : data(data) {}
		Node<T> * next = nullptr;
		T  data = nullptr;

		int use_count = 0; // how many end_pointers point to the node.
	};

	template <class T>
	class SharedQueue {
	private:
		Node<T> * head = nullptr;
		Node<T> * tail = nullptr;
		int size = 0;
	public:
		Node<T> * getHead() { return this->head; }

		Node<T>* getTail() { return this->tail; }

		void push_back(T data) {
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

		T pop_front() {
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

		T front() {
			if (head == nullptr) {
				cout << "the queue is empty!" << endl;
				throw 1;
			}
			return head->data;
		}

		T back() {
			if (head == nullptr) {
				cout << "the queue is empty!" << endl;
				throw 1;
			}
			return tail->data;
		}

		int getSize() {
			return this->size;
		}
	};
}

using namespace sharedWindow;

template <class T> // type of query name
class SharedWindow {
public:

	void addEvent(EventPtr event);

	void addQuery(T queryID);

	bool pop_front(T queryID);

	void setQueryCondition(Condition * con) { this->queryCondition = con; }

	Condition* getQueryCondition() { return this->queryCondition; }

	EventPtr front(T topicID);

	EventPtr back();

private:
	map<T, Node<EventPtr>*> topicName_event_map;

	SharedQueue<EventPtr> events;

	Condition *queryCondition;

	bool pop_front(Node<EventPtr>* endPointer);
};

template <class T>
void SharedWindow<T>::addEvent(EventPtr event) {
	if (!events.getHead()) {
		for (auto iter = topicName_event_map.begin(); iter != topicName_event_map.end(); iter++) {
			topicName_event_map[iter->first] = event;
		}
	}
	this->events.push_back(event);
}

template <class T>
bool SharedWindow<T>::pop_front(T queryID) {
	Node<EventPtr>* endPointer = this->topicName_event_map[queryID];
	return pop_front(endPointer);
}

template <class T>
bool SharedWindow<T>::pop_front(Node<EventPtr>* endPointer) {
	if (!endPointer) return false;

	if (endPointer->use_count == 1 && endPointer == events.getHead()) {
		endPointer = endPointer->next;
		if(endPointer) endPointer->use_count++;
		events.pop_front();
	}
	else{
		endPointer->use_count--;
		endPointer = endPointer->next;
		if(endPointer)endPointer->use_count++;
	}
	return true;
}


template <class T>
void SharedWindow<T>::addQuery(T queryID) {
	this->topicName_event_map[queryID] = nullptr;
}

template <class T>
EventPtr SharedWindow<T>::front(T topicID) {
	if (!topicName_event_map[topicID])return nullptr;
	return this->topicName_event_map[topicID]->data;
}

template <class T>
EventPtr SharedWindow<T>::back() {
	if (!events.getTail)return nullptr;
	return events.getTail()->data;
}

#endif // !SHARED_WINDOW


