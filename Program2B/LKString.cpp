#include <iostream>
#include "LKString.h"

LKString::LKString() {
}

//string init constructor
LKString::LKString(const char* userStr) {
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	str[end] = '\0';
}

//copy constructor
LKString::LKString(const LKString & lkstr) {
	delete[] str;
	str = new char[lkstr.end];
	for (end = 0; lkstr.str[end] != '\0'; end++) {
		str[end] = lkstr.str[end];
	}
	str[end] = '\0';
}

  //___________________ //
 // Operator Overloads //
// ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾//


void LKString::operator =(const LKString& lkstr) {
	delete[] str;
	str = new char[lkstr.end];
	for (end = 0; lkstr.str[end] != '\0'; end++) {
		str[end] = lkstr.str[end];
	}
	str[end] = '\0';
}
//An overload used in the read function.
void LKString::operator =(const char* userStr) { 
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	str[end] = '\0';
}

bool operator >>(istream& istrm, LKString &lkstr) {
	char ch[99];
	int index = 0;
	
	//Checking if input is valid and working, both for file and cin
	if (istrm.fail()) {
		cout << "ERROR: Was not able to open and read file";
		return false;
	}
	else if (istrm.bad()) {
		cout << "ERROR: The input is corrupted";
		return false;
	}

	istrm.getline(ch, 99, ' ');
	
	lkstr = ch;
	
	return true;
}

void operator <<(ostream& ostrm, LKString &lkstr) {
	if (ostrm.fail()) {
		cout << "ERROR: Was not able to open and write to file";
		return;
	}
	
	for (int i = 0; i < lkstr.length(); i++) {
		ostrm << lkstr[i];
	}
}

bool LKString::operator ==(const LKString& lkstr) {
	if (compareTo(lkstr) == 0)
		return true;
	else
		return false;
}

bool LKString::operator >(const LKString& lkstr) {
	if (compareTo(lkstr) == 1)
		return true;
	else
		return false;
}

bool LKString::operator <(const LKString& lkstr) {
	if (compareTo(lkstr) == -1)
		return true;
	else
		return false;
}

int LKString::compareTo(const LKString& argStr) {
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

//destructor
LKString::~LKString() {
	delete[] str;
}

