#pragma once
#include "LKString.h"
#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node();
	Node(LKString str);

	LKString data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class LinkedList {

};

#endif

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList& dll);
};

#endif