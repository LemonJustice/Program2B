#pragma once
#include "LKString.h"

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