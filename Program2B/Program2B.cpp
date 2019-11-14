// Class Name: LKString: Program 2B
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
		cout << setw(13);
		myStrings[strNum - 1].write(fout);
		cout << myStrings[strNum - 1].c_str();
		if (strNum % 6 == 0) {
			fout << endl;
			cout << endl;
		}
	}
	fout.close();
	cout << endl << "Written data to output.txt" << endl;
	system("pause");
}


//Program output

/*          I            I            I      Martian           Or         Such
         They         Were            a            a            a            a
    amazingly           an           an          and      animal.           as
          ask          ask          be.        began        began        body?
        brain        busy.      compare        could          did   directing,
        each,       engine         felt        first          for          his
          how        human  impossible.           in           in  intelligent
  intelligent     ironclad         life        lower    machines,        man's
  mechanisms?         much           my       myself       myself           or
        rules      ruling,         seem       seemed          sit         sits
        steam          the          the         they         they        thing
       things         time           to           to           to           to
           to       using,          was         what       within        would

Written data to output.txt
Press any key to continue . . .*/