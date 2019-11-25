// Class Name: LKString: Program 5: Lists 
// Author: Liam Kikuchi
// Section: S
// Description:

#include <iostream>
#include <iomanip>
#include <fstream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList list1, list2, modList1, modList2;
	LKString input;

	ifstream file1;
	file1.open("infile1.txt");

	while (!file1.eof()) {
		file1 >> input;
		if (input == "a") {
			int i = 0;
		}
		list1.insert(input);
	}
	file1.close();

	ifstream file2;
	file2.open("infile2.txt");
	while (!file2.eof()) {
		file2 >> input;
		list2.insert(input);
	}
	file2.close();

	cout << list1 << "| count: " << list1.getCount() << endl;
	cout << list2 << "| count: " << list2.getCount() << endl;
	cout << modList1 << "| count: " << modList1.getCount() << endl;
	cout << modList2 << "| count: " << modList2.getCount() << endl;
}

/*

*/