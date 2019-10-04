#pragma once
#include <istream>
using namespace std;
#ifndef LKSTRING_H
#define LKSTRING_H

class LKString {
public:
	LKString();
	LKString(const char* agrStr);
	int length();
	int capacity();
	char at(int index);
	bool read(istream& istrm);
	void write(ostream& ostrm);
	int compareTo(const LKString& agrStr);
	const char* c_str();
	void setEqualTo(const LKString& argStr);
private:
	const char* str;
	int cap = 20;
	int end = 0;
};

#endif