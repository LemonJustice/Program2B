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

	LKString& operator =(const LKString& argStr);
	LKString& operator =(const char* argStr);
	LKString& operator +(const LKString& lkstr);
	bool operator ==(const LKString& lkstr) const;
	bool operator >(const LKString& lkstr) const;
	bool operator <(const LKString& lkstr) const;
	char operator [](int index);
	char operator [](int index) const;

	const char* c_str();
	int length();
	int capacity();
	char at(int index);
	int getCurrentCount();
	int getCreatedCount();

	~LKString();
private:
	
	int compareTo(const LKString& agrStr) const;

	int cap = 20;
	char* str;
	int end = 0;
};
ostream& operator >>(istream& istrm, LKString& lkstr);
ostream& operator <<(ostream& ostrm, LKString& lkstr);

#endif