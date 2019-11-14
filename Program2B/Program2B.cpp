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
	for (; !fin.eof(); stringCount++) {
		LKString jumbo;
		for (int word = 0; !fin.eof() && word < 5; word++) {
			LKString temp;
			fin >> temp;
			jumbo = jumbo + temp;
		}
		myStrings.push_back(jumbo);
	}
	
	bool swapped = true;

	while (swapped) {
		swapped = false;
		for (int i = 1; i < stringCount; i++) {
			if (myStrings[i - 1] > myStrings[i]) {
				LKString temp = myStrings[i - 1].c_str();
				myStrings[i - 1] = myStrings[i];
				myStrings[i] = temp;

				swapped = true;
			}
			
		}
	}
	cout << endl;
	for (int i = 0; i < stringCount; i++) {
		cout << setw(100) << left << myStrings[i]
			<< myStrings[i].length() << ":" 
			<< myStrings[i].capacity() << endl;
	}
	cout << endl << "Total amount of strings constructed: " << myStrings[0].getCreatedCount()
		<< endl << "Amount of strings currently alive: " << myStrings[0].getCurrentCount()
		<< endl << endl;

	system("pause");
}

/*

Ibegantocomparethe                                                                                  18:20
Ifeltwasimpossible.Or                                                                               21:40
Theyseemedamazinglybusy.I                                                                           25:40
andrulesinhisbody?                                                                                  18:20
anironcladorasteam                                                                                  18:20
asaman'sbrainsits                                                                                   17:20
askmyselfforthefirst                                                                                20:40
begantoaskmyselfwhat                                                                                20:40
didaMartiansitwithin                                                                                20:40
each,ruling,directing,using,much                                                                    32:40
enginewouldseemtoan                                                                                 19:20
intelligentloweranimal.ThisIsMyAmazinglyLongStringToMakeYourExtractionOperatorWorkCorrectly.        92:100
intelligentmechanisms?Suchathing                                                                    32:40
theycouldbe.Werethey                                                                                20:40
thingstohumanmachines,to                                                                            24:40
timeinmylifehow                                                                                     15:20

Total amount of strings constructed: 201
Amount of strings currently alive: 16

Press any key to continue . . .
*/