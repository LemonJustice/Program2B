#pragma once
#include "LKString.h"
#include <ostream>
using namespace std;

template <typename T>
class Node {
public:
	Node() {
		next = nullptr;
		prev = nullptr;
	}

	Node(T t) {
		data = t;
	}

	T data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList& dll);

	LinkedList& operator =(const LinkedList& dll);

	bool insert(const T& str);
	bool remove(const T& str);

	void resetIteration() const;
	T& next() const;
	T& prev() const;
	bool hasMore() const;

	int getCount() const;

	~LinkedList();
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	mutable Node<T>* it = nullptr;
	int count = 0;
};

template <typename T>
ostream& operator <<(ostream& ostrm, LinkedList<T>& dll);

#endif

template <typename T>
LinkedList<T>::LinkedList() {
	count = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& dll) {
	//reset count
	count = 0;
	dll.resetIteration(); //reassurance for now
	while (dll.hasMore()) {
		//handles case of head
		if (count == 0) {
			head = new Node<T>(dll.next());
			it = head;
		}
		else {
			//literally every other case
			it->next = new Node<T>(dll.next());
			it = it->next;
		}
		count++;
	}
	tail = it;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& dll) {
	count = 0;
	dll.resetIteration(); //reassurance for now
	while (dll.hasMore()) {
		if (count == 0) {
			head = new Node<T>(dll.next());
			it = head;
		}
		else {
			it->next = new Node<T>(dll.next());
			it->next->prev = it;
			it = it->next;
		}
		count++;
	}
	tail = it;
	dll.resetIteration();
	return *this;
}

template <typename T>
ostream& operator <<(ostream& ostrm, LinkedList<T>& dll) {
	dll.resetIteration();
	if (ostrm.fail()) {
		ostrm << "The output seems to be corrupted!" << endl;
		return ostrm;
	}

	while (dll.hasMore()) {
		T temp(dll.next());
		ostrm << temp << " ";
	}
	dll.resetIteration();
	return ostrm;
} 

template <typename T>
bool LinkedList<T>::insert(const T& str) {
	Node<T>* insertNode = new Node<T>(str);

	//Check to make sure it isn't empty
	if (head == nullptr) {
		head = insertNode;
		head->prev = nullptr;
		it = head;
		tail = head;

		count++;
		return true;
	}
	T nextStr(next());
	while (hasMore()) {
		if (str == nextStr) {
			//Already has value, so exit
			resetIteration();
			return false;
		}
		else if (str < head->data) {

			//Placing at front of the list
			head->prev = insertNode;
			insertNode->next = head;
			head = insertNode;
			head->prev = nullptr;

			count++;
			resetIteration();
			return true;
		}
		else if (str < nextStr) {

			//Perhaps my next function hinders me
				//It iterates the it pointer, but comparison is done with previous string
				//Therefore, step back twice for real previous value?
			Node<T>* prevNode = it->prev->prev;

			//Stepping back prev for better comprehension
			it = it->prev;

			//Linked insertNode with prevNode
			prevNode->next = insertNode;
			insertNode->prev = prevNode;

			//Finishing the other side of the insert
			insertNode->next = it;
			it->prev = insertNode;

			count++;
			resetIteration();
			return true;
		}
		nextStr = next();
	}

	//Has to be at the end of list
	if (str != tail->data) {
		tail->next = insertNode;
		insertNode->prev = tail;
		tail = insertNode;
		tail->next = nullptr;

		count++;
		resetIteration();
		return true;
	}
	//Loop until the data in the next node is greater than the new data
	resetIteration();
	return false;
}

template <typename T>
bool LinkedList<T>::remove(const T& str) {
	//Check to make sure it isn't empty
	if (head == nullptr) {
		return false;
	}
	if (str == head->data) {
		head = head->next;
		delete head->prev;
		head->prev = nullptr;

		count--;
		resetIteration();
		return true;
	}
	else if (str == tail->data) {
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;

		count--;
		resetIteration();
		return true;
	}
	while (hasMore()) {
		if (str == next()) {
			//Step back twice for real previous value?
			Node<T>* prevNode = (it->prev->prev);
			//Keep "it" at the incremented value

			//Linking the remaining nodes
			prevNode->next = it;
			it->prev = prevNode;

			count--;
			resetIteration();
			return true;
		}
	}
	resetIteration();
	return false;
}

//ITERATION HELPERS

template <typename T>
void LinkedList<T>::resetIteration() const {
	if (head != nullptr)
		it = head;
}

template <typename T>
T& LinkedList<T>::next() const {
	T* temp = new T(it->data);
	it = it->next;
	return *temp;
}

template <typename T>
T& LinkedList<T>::prev() const {
	T* temp = new T(it->data);
	it = it->prev;
	return *temp;
}

template <typename T>
bool LinkedList<T>::hasMore() const {
	//Ensures that list isn't empty before checking for more values
	if (it != nullptr) //JUST CHANGED THIS
		return true;
	return false;
}

//PUBLIC ACCESSORS 

template <typename T>
int LinkedList<T>::getCount() const {
	return count;
}

template <typename T>
LinkedList<T>::~LinkedList() {

}