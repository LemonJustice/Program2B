// Program2B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "LKString.h"
#include <vector>

using namespace std;

int main()
{
	vector<LKString> myStrings;
	ifstream fin;
	fin.open("infile3.txt");
	int stringCount = 0;

	//This is reading the file into the LKStrings within the vector
	for (stringCount = 0; !fin.eof(); stringCount++) {
		LKString jumbo;
		for (int word = 0; !fin.eof() && word < 5; word++) {
			LKString temp;
			fin >> temp;
			jumbo = jumbo + temp;
		}
		cout << jumbo;
		myStrings.push_back(jumbo);
		system("pause");
	}
	
	bool swapped = true;

	while (swapped) {
		swapped = false;
		for (int i = 1; i < stringCount; i++) {
			if (myStrings[i - 1] > myStrings[i]) {
				const char* temp = myStrings[i - 1].c_str();
				myStrings[i - 1] = myStrings[i];
				myStrings[i] = temp;

				swapped = true;
			}
			
		}
	}
	for (int i = 0; i < stringCount; i++) {
		cout << myStrings[i] << setw(10) << right
			<< myStrings[i].length() << ":" 
			<< myStrings[i].capacity() << endl;
	}
	system("pause");
}