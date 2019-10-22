#pragma once
#include <istream>
using namespace std;
#ifndef LKSTRING_H
#define LKSTRING_H

class LKString {
public:
	LKString();
	LKString(const char* agrStr);
	LKString(const LKString & lkstr);

	void operator =(const LKString& argStr);
	void operator =(const char* argStr);
	bool operator ==(const LKString& lkstr);
	bool operator >(const LKString& lkstr);
	bool operator <(const LKString& lkstr);
	char operator [](int index);
	char operator [](int index) const;

	const char* c_str();
	int length();
	int capacity();
	char at(int index);

	~LKString();
private:
	int compareTo(const LKString& agrStr);

	int cap = 20;
	char* str;
	int end = 0;
};

ostream& operator << (ostream& ostr, const LKString lkstr);
istream& operator >> (istream& istr, const LKString lkstr);

#endif