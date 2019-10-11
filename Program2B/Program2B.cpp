// Program2B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "LKString.h"
#include <vector>

using namespace std;

int main()
{
	vector<LKString> myStrings(100);
	ifstream fin;
	fin.open("infile2.txt");
	int word = 0;

	//This is reading the file into the LKStrings within the vector
	for (word = 0; !fin.eof(); word++) {
		myStrings[word].read(fin);
	}
	myStrings.resize(word);
	
	bool swapped = true;

	while (swapped) {
		swapped = false;
		for (int i = 1; i < word; i++) {
			if (myStrings[i - 1].compareTo(myStrings[i]) == -1) {
				const char* temp = myStrings[i - 1].c_str();
				myStrings[i - 1].setEqualTo(myStrings[i]);
				myStrings[i].setEqualTo(temp);

				swapped = true;
			}
			
		}
	}

}
