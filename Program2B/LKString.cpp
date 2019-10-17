#include <iostream>
#include <fstream>
#include "LKString.h"

LKString::LKString() {
}

LKString::LKString(const char* userStr) {
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	// This extra '\0' is here beacause the for loop quits early
	str[end] = '\0';
}

void LKString::setEqualTo(const LKString& argStr) {
	for (end = 0; argStr.str[end] != '\0'; end++) {
		str[end] = argStr.str[end];
	}
	str[end] = '\0';
}


// An overload used in the read function.
void LKString::setEqualTo(const char* userStr) {
	str = new char[cap];
	for (end = 0; userStr[end] != '\0'; end++) {
		str[end] = userStr[end];
	}
	str[end] = '\0';
}


bool LKString::read(istream& istrm) {
	char ch[99] = {0};
	int index = 0;
	
	// Checking if input is valid and working
	if (istrm.fail()) {
		cout << "ERROR: Was not able to open and read file";
		return false;
	}
	else if (istrm.bad()) {
		cout << "ERROR: The input is corrupted";
		return false;
	}
	
	// While prevents assigning string to a null terminator, space, or null
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

	setEqualTo(ch);
	
	return true;
}

void LKString::write(ostream& ostrm) {
	// Checking if file can be made written to
	if (ostrm.fail()) {
		cout << "ERROR: Was not able to open and write to file";
		exit(1);
	}

	ostrm << str;
}


int LKString::compareTo(const LKString& argStr) {
	int i = 0;
	while (true) {
		// Both strings are the same
		if (str[i] == '\0' && argStr.str[i] == '\0') {
			return 0;
		}
		// The instance calling the function has a string with higher ascii
		else if (str[i] > argStr.str[i] || argStr.str[i] == '\0') {
			return 1;
		}
		// The parameter instance has a string with higher ascii
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
	// Checking bounds to prevent garbage data
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
