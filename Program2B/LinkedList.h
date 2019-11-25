#pragma once
#include "LKString.h"
#include "Node.h"
#include <ostream>

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
public:
	Node();
	Node(LKString str);

	LKString data;
	Node* next = nullptr;
	Node* prev = nullptr;
};


#endif

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList& dll);

	LinkedList& operator =(const LinkedList& dll);

	bool insert(const LKString& str);
	bool remove(const LKString& str);

	void resetIteration() const;
	LKString& next() const;
	bool hasMore() const;

	int getCount() const;

	~LinkedList();
private:
	Node* head;
	Node* tail;
	mutable Node* it;
	int count = 0;
};

ostream& operator <<(ostream& ostrm, LinkedList& dll);

#endif