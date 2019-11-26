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

	cout << list1 << "\n_________________________________________________\n" 
		<< "^ list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << list2 << "\n_________________________________________________\n"
		<< "^ list2 count from infile2: " << list2.getCount() << endl << endl;
	cout << modList1 << "\n_________________________________________________\n"
		<< "^ modList1 count: " << modList1.getCount() << endl << endl;
	cout << modList2 << "\n_________________________________________________\n"
		<< "^ modList2 count: " << modList2.getCount() << endl << endl;

	cout << "Now using assignment operator \n\n";

	modList1 = list1;
	modList2 = list2;

	cout << list1 << "\n_________________________________________________\n"
		<< "^ list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << list2 << "\n_________________________________________________\n"
		<< "^ list2 count from infile2: " << list2.getCount() << endl << endl;
	cout << modList1 << "\n_________________________________________________\n"
		<< "^ modList1 count after copying list1: " << modList1.getCount() << endl << endl;
	cout << modList2 << "\n_________________________________________________\n"
		<< "^ modList2 count after copying list2: " << modList2.getCount() << endl << endl;

	cout << "Now removing elements in modLists\n\n";

	list2.resetIteration();
	while(list2.hasMore()){
		modList1.remove(list2.next());
	}
	
	list1.resetIteration();
	while(list1.hasMore()){
		modList2.remove(list1.next());
	}

	cout << list1 << "\n_________________________________________________\n"
		<< "^ list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << list2 << "\n_________________________________________________\n"
		<< "^ list2 count from infile2: " << list2.getCount() << endl << endl;
	cout << modList1 << "\n_________________________________________________\n"
		<< "^ modList1 count after removing matching items from list2: " << modList1.getCount() << endl << endl;
	cout << modList2 << "\n_________________________________________________\n"
		<< "^ modList2 count after removing matching items from list1: " << modList2.getCount() << endl << endl;

}


/*

*/