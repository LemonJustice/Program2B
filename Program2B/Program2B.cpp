// Class Name: KnightsTour
// Author: Liam Kikuchi
// Section: S
// Description: This program uses a self created class that
// stores strings in char arrays to read a file - separating 
// words by spaces and new line characters - then write a
// sorted version from lower to higher ascii values.


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "LKString.h"

using namespace std;

int main()
{
	vector<LKString> myStrings(100);
	ifstream fin;
	ofstream fout;
	fin.open("infile2.txt");
	int word = 0;

	// This is reading the file into the LKStrings within the vector
	for (word = 0; !fin.eof(); word++) {
		myStrings[word].read(fin);
	}
	// word is decremented because the previous for loop
	// goes one step too far
	myStrings.resize(--word);
	fin.close();
	
	bool swapped = true;

	while (swapped) {
		swapped = false;
		for (int strNum = 1; strNum < word; strNum++) {
			// Swap the two strings if the first is larger
			if (myStrings[strNum - 1].compareTo(myStrings[strNum]) == 1) {
				char temp[99] = {0};
				int index;
				// This is done to avoid copying memory address
				for (index = 0; myStrings[strNum].at(index) != '\0'; index++)
					temp[index] = myStrings[strNum].at(index);
				temp[index] = '\0';

				myStrings[strNum].setEqualTo(myStrings[strNum - 1]);
				myStrings[strNum - 1].setEqualTo(temp);

				swapped = true;
			}
			
		}
	}
	fout.open("output.txt");
	for (int strNum = 1; strNum <= word; strNum++) {
		fout << setw(13);
		myStrings[strNum - 1].write(fout);
		if (strNum % 6 == 0)
			fout << endl;
	}
	fout.close();
	cout << "Written data to output.txt" << endl;
	system("pause");
}


// Written data to output.txt
// Press any key to continue . . .