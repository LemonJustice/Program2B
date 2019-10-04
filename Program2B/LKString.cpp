#include <iostream>
#include "LKString.h"

LKString::LKString() {

}
LKString::LKString(const char* userStr) {
	str = userStr;
	
	int i = 0;
	for(int i = 0; str[i] != '\0'; i++){}
	end = i;
}

void LKString::setEqualTo(const LKString& argStr) {
	str = argStr.str;
	
	int i = 0;
	for (int i = 0; str[i] != '\0'; i++) {}
	end = i;
}


bool LKString::read(istream& istrm) {

}

void LKString::write(ostream& ostrm) {

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
	return str[index];
}
int LKString::length() {
	return end;
}
int LKString::capacity() {
	return cap;
}
