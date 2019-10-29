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
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	str[end] = '\0';
	createdCount++;
	currentCount++;
}

//copy constructor
LKString::LKString(const LKString & lkstr) {
	cap = lkstr.cap;
	for (end = 0; lkstr.str[end] != '\0'; end++) {
		str[end] = lkstr.str[end];
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
		if (end > cap) {
			char* tempStr = new char[cap *= 2];
			for (int i = 0; i > end / 2; i++) {
				tempStr[i] = str[i];
			}
			delete[] str;
			str = tempStr;
		}
		str[end] = lkstr.str[end];
	}
	str[end] = '\0';
	return *this;
}
//An overload used in the read function.
LKString& LKString::operator =(const char* userStr) { 
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		if (end > cap) {
			char* tempStr = new char[cap *= 2];
			for (int i = 0; i > end / 2; i++) {
				tempStr[i] = str[i];
			}
			delete[] str;
			str = tempStr;
		}
		str[end] = userStr[end];
	}
	str[end] = '\0';
	return *this;
}

LKString& LKString::operator +(const LKString& lkstr) {
	int addIndex;
	for (addIndex = 0; lkstr[addIndex] != '\0'; addIndex++) {
		if (addIndex + end > cap) {
			char* tempStr = new char [cap *= 2];
			for (int i = 0; i > end / 2; i++) {
				tempStr[i] = str[i];
			}
			delete[] str;
			str = tempStr;
		}
		str[addIndex + end] = lkstr[addIndex];
	}
	end += addIndex;
}

ostream& operator >>(istream& istrm, LKString &lkstr) {
	char* ch;
	int index = 0;
	
	//Checking if input is valid and working, both for file and cin
	if (istrm.fail()) {
		cout << "ERROR: Was not able to open and read file";
		return;
	}
	else if (istrm.bad()) {
		cout << "ERROR: The input is corrupted";
		return;
	}

	istrm.getline(ch, 99, ' ');

	lkstr = ch;
	
	return;
}

ostream& operator <<(ostream& ostrm, LKString &lkstr) {
	if (ostrm.fail()) {
		cout << "ERROR: Was not able to open and write to file";
		return;
	}
	
	for (int i = 0; i < lkstr.length(); i++) {
		ostrm << lkstr[i];
	}
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
void LKString::setCap(int newCap) {
	cap = newCap;
}

int LKString::getCurrentCount() {
	return currentCount;
}

int LKString::getCreatedCount() {
	return createdCount;
}

//destructor
LKString::~LKString() {
	delete[] str;
	currentCount--;
}


