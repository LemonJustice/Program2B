#include <iostream>
#include "LKString.h"

LKString::LKString() {
}

LKString::LKString(const char* userStr) {
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	str[end] = '\0';
}

void LKString::setEqualTo(const LKString& argStr) {
	for (end = 0; argStr.str[end] != '\0'; end++) {
		str[end] = argStr.str[end];
	}
	str[end] = '\0';
}


//An overload used in the read function.
void LKString::setEqualTo(const char* userStr) {
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	str[end] = '\0';
}


bool LKString::read(istream& istrm) {
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
	
	setEqualTo(ch);
	
	return true;
}

void LKString::write(ostream& ostrm) {
	if (ostrm.fail()) {
		cout << "ERROR: Was not able to open and write to file";
		return;
	}
	
	for (int i = 0; i < end; i++) {
		ostrm << str[i];
	}
}


int LKString::compareTo(const LKString& argStr) {
	int i = 0;
	while (true) {
		if (str[i] == '\0' && argStr.str[i] == '\0') {
			return 0;
		}
		else if (str[i] > argStr.str[i] || argStr.str[i] == '\0') {
			return 1;
		}
		else if (str[i] < argStr.str[i] || str[i] == '\0') {
			return -1;
		}
		i++;
	}
}

const char* LKString::c_str() {
	return str;
}
char LKString::at(int index) {
	if (index < end && index >= 0)
		return str[index];
	else
		return '\0';
}
int LKString::length() {
	return end;
}
int LKString::capacity() {
	return cap;
}
