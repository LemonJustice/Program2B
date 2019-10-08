#include <iostream>
#include "LKString.h"

LKString::LKString() {
}

LKString::LKString(const char* userStr) {
	int i = 0;
	for (i = 0; userStr[i] != '\0'; i++) {
	}
	end = i;
	str = new char[end, 0];
	for (int i = 0; i < end; i++) {
		str[i] = userStr[i];
	}
}

void LKString::setEqualTo(const LKString& argStr) {
	delete[] str;
	int i = 0;
	for (i = 0; argStr.str[i] != '\0'; i++) {
	}
	end = i;
	str = new char[end, 0];
	for (int i = 0; i < end; i++) {
		str[i] = argStr.str[i];
	}
}


bool LKString::read(istream& istrm) {
	char ch[99];
	int index = 0;
	
	//Checking if input is valid and working, both for file and cin
	if (istrm.fail()) {
		cout << "ERROR: Was not able to open and read file";
		exit(1);
	}
	else if (istrm.bad()) {
		cout << "ERROR: The input is corrupted";
		exit(1);
	}

	while (!istrm.eof()) {
		ch[index] = istrm.get();
		index++;
	}
	
	setEqualTo(ch);
}

void LKString::write(ostream& ostrm) {
	if (ostrm.fail()) {
		cout << "ERROR: Was not able to open and write to file";
		exit(1);
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
