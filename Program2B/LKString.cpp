#include <iostream>
#include <cctype>
#include "LKString.h"

static int createdCount = 0;
static int currentCount = 0;

LKString::LKString() {
	str = new char[cap];
	str[0] = '\0';
	createdCount++;
	currentCount++;
}

//string init constructor
LKString::LKString(const char* userStr) {
	for (end = 0; userStr[end] != '\0'; end++) {
		if (end + 1 >= cap)
			cap += 20;
	}

	str = new char[cap];
	*str = { '\0' };

	for (int i = 0; i < end; i++) {
		str[i] = userStr[i];
	}

	str[end] = '\0';
	createdCount++;
	currentCount++;
}

//copy constructor
LKString::LKString(const LKString & lkstr) {
	for (end = 0; lkstr.at(end) != '\0'; end++) {
		if (end + 1 >= cap)
			cap += 20;
	}

	str = new char[cap];
	*str = { '\0' };

	for (int i = 0; i <= end; i++) {
		str[i] = lkstr.at(i);
	}

	str[end] = '\0';
	createdCount++;
	currentCount++;
}

  //___________________ //
 // Operator Overloads //
// ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾//


LKString& LKString::operator =(const LKString& lkstr) {
	if (lkstr == *this)
		return *this;

	for (end = 0; lkstr[end] != '\0'; end++) {}
	cap = 20;
	while (end >= cap) {
		cap += 20;
	}

	delete[] str;
	str = new char[cap];

	for (int i = 0; i < end; i++) {
		str[i] = lkstr.str[i];
	}

	str[end] = '\0';
	return *this;
}
//An overload used in the read function.
LKString& LKString::operator =(const char* userStr) { 
	for (end = 0; userStr[end] != '\0'; end++) {}
	cap = 20;
	while (end >= cap) {
		cap += 20;
	}

	delete[]str;
	str = new char[cap];

	for (int i = 0; i < end; i++) {
		str[i] = userStr[i];
	}

	str[end + 1] = '\0';
	return *this;
}

LKString& LKString::operator +(const LKString& lkstr) {

	//Finds out how long my string is gonna be
		//might need to add 1 or 2 to this length or subtract or two
	int newStrLength = end + lkstr.length();
	while (newStrLength > cap) {
		cap += 20;
	}
	char* tempStr= new char[cap];

	//copies this into it
	int index = 0;
	for (; index < end; index++) {
		tempStr[index] = str[index];
	}

	//copies the second string into it
	for (; index < newStrLength; index++) {
		tempStr[index] = lkstr[index - end];
	}

	delete[] str;
	str = tempStr;
	end = newStrLength;

	return *this;
}

//the issue probably lies here
istream& operator >>(istream& istrm, LKString &lkstr) {
	char ch[100] = {'\0'};
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
	int letter = 0;
	while (gotStr == false && !istrm.eof()) {
		istrm.get(ch[letter]);

		while (ch[letter] != ' ' && ch[letter] != '\n' &&
			(!ispunct(ch[letter]) || ch[letter] == '\'') &&
			letter < 99 && !istrm.eof()) {

			letter++;
			istrm.get(ch[letter]);
		}
		ch[letter] = '\0';
		gotStr = true;

		if (ch[0] == '\0' || ch[0] == '\n' ||
			ch[0] == ' ' || ispunct(ch[0])) {
			
			gotStr = false;
		}
	}
	lkstr = ch + '\0';
	return istrm;
}

ostream& operator <<(ostream& ostrm, LKString &lkstr) {
	if (ostrm.fail()) {
		cout << "ERROR: Was not able to open and write to file";
		return ostrm;
	}
	
	ostrm << lkstr.c_str();

	return ostrm;
}

bool LKString::operator ==(const LKString& lkstr) const  {
	if (compareTo(lkstr) == 0)
		return true;
	else
		return false;
}

bool LKString::operator !=(const LKString& lkstr) const {
	if (compareTo(lkstr) != 0)
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

int LKString::compareTo(const LKString& lkstr) const {
	char LC_str[100];
	for (int i = 0; i < length(); i++) {
		if(this->at(i) >= 97 && this->at(i) <= 122)
			LC_str[i] = this->at(i) - 32;
		else
			LC_str[i] = this->at(i);
	}

	char LC_lkstr[100];
	for (int i = 0; i < lkstr.length(); i++) {
		if (lkstr[i] >= 97 && lkstr[i] <= 122)
			LC_lkstr[i] = lkstr[i] - 32;
		else
			LC_lkstr[i] = lkstr[i];
	}

	int i = 0;
	while (LC_str[i] != '\0' && LC_lkstr[i] != '\0') {
		//If they are equal
		if (LC_str[i] == '\0' && LC_lkstr[i] == '\0') {
			return 0;
		}
		//if *this is bigger than the parameter
		else if (LC_str[i] > LC_lkstr[i] || LC_lkstr[i] == '\0') {
			return 1;
		}
		//if *this is smaller than the parameter
		else if (LC_str[i] < LC_lkstr[i] || LC_str[i] == '\0') {
			return -1;
		}
		i++;
	}
}


  //__________________________ //
 // Public Accessor Functions //
// ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾//


const char* LKString::c_str() const {
	return str;
}

char LKString::at(int index) const  {
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

int LKString::length() const {
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


