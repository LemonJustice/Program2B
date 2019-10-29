#include <iostream>
#include "LKString.h"

static int createdCount = 0;
static int currentCount = 0;

LKString::LKString() {
	createdCount++;
	currentCount++;
}

//string init constructor
LKString::LKString(const char* userStr) {
	for (end = 1; userStr[end-1] != '\0'; end++) {
		if (end >= cap)
			cap += 20;
	}
	str = new char[cap];
	*str = { '\0' };
	for (int i = 0; i <= end; i++) {
		str[i] = userStr[i];
	}
	str[end] = '\0';
	createdCount++;
	currentCount++;
}

//copy constructor
LKString::LKString(const LKString & lkstr) {
	for (end = 1; lkstr[end -1] != '\0'; end++) {
		if (end >= cap)
			cap += 20;
	}
	str = new char[cap];
	*str = { '\0' };
	for (int i = 0; i <= end; i++) {
		str[i] = lkstr[i];
	}
	str[end] = '\0';
	createdCount++;
	currentCount++;
}

  //___________________ //
 // Operator Overloads //
// ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾//


LKString& LKString::operator =(const LKString& lkstr) {
	delete[] str;
	str = new char[lkstr.end];
	for (end = 0; lkstr.str[end] != '\0'; end++) {
		str[end] = lkstr.str[end];
	}
	str[end] = '\0';
	return *this;
}
//An overload used in the read function.
LKString& LKString::operator =(const char* userStr) { 
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	str[end] = '\0';
	return *this;
}

LKString& LKString::operator +(const LKString& lkstr) {
	int addEnd;
	for (addEnd = 1; lkstr[addEnd - 1] != '\0'; addEnd++) {
		if (end + addEnd >= cap)
			cap += 20;
	}
	str = new char[cap];
	*str = { '\0' };
	for (int i = 0; i <= end + addEnd; i++) {
		str[end] = lkstr[end + addEnd];
	}
	str[end] = '\0';
	return *this;
}

istream& operator >>(istream& istrm, LKString &lkstr) {
	char ch[99] = {'\0'};
	int index = 0;
	
	//Checking if input is valid and working, both for file and cin
	if (istrm.fail()) {
		cout << "ERROR: Was not able to open and read file";
		return istrm;
	}
	else if (istrm.bad()) {
		cout << "ERROR: The input is corrupted";
		return istrm;
	}

	bool gotStr = 0;
	while (gotStr == false && !istrm.eof()) {
		int letter = 0;
		istrm.get(ch[letter]);
		while (ch[letter] != ' ' && ch[letter] != '\n' && letter < 98) {
			letter++;
			istrm.get(ch[letter]);
		}
		// Removes the space after the string ends
		ch[letter] = '\0';
		gotStr = true;

		if (ch[0] == '\0' || ch[0] == '\n')
			gotStr = false;
	}

	lkstr = ch;
	
	return istrm;
}

ostream& operator <<(ostream& ostrm, LKString &lkstr) {
	if (ostrm.fail()) {
		cout << "ERROR: Was not able to open and write to file";
		return ostrm;
	}
	
	for (int i = 0; i < lkstr.length(); i++) {
		ostrm << lkstr[i];
	}
	return ostrm;
}

bool LKString::operator ==(const LKString& lkstr) const  {
	if (compareTo(lkstr) == 0)
		return true;
	else
		return false;
}

bool LKString::operator >(const LKString& lkstr) const {
	if (compareTo(lkstr) == 1)
		return true;
	else
		return false;
}

bool LKString::operator <(const LKString& lkstr) const {
	if (compareTo(lkstr) == -1)
		return true;
	else
		return false;
}

int LKString::compareTo(const LKString& argStr) const {
	int i = 0;
	while (true) {
		//If they are equal
		if (str[i] == '\0' && argStr.str[i] == '\0') {
			return 0;
		}
		//if *this is bigger than the parameter
		else if (str[i] > argStr.str[i] || argStr.str[i] == '\0') {
			return 1;
		}
		//if *this is smaller than the parameter
		else if (str[i] < argStr.str[i] || str[i] == '\0') {
			return -1;
		}
		i++;
	}
}


  //__________________________ //
 // Public Accessor Functions //
// ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾//


const char* LKString::c_str() {
	return str;
}

char LKString::at(int index) {
	if (index < end && index >= 0)
		return str[index];
	else
		return '\0';
}

char LKString::/*Operator []*/operator [](int index) {
	return str[index];
}
char LKString::/*Const Operator []*/operator [](int index) const {
	return str[index];
}

int LKString::length() {
	return end;
}

int LKString::capacity() {
	return cap;
}

int LKString::getCurrentCount() {
	return currentCount;
}

int LKString::getCreatedCount() {
	return createdCount;
}

//destructor
LKString::~LKString() {
	currentCount--;
	delete[] str;
}


