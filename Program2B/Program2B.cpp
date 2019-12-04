// Class Name: LKString: Program 7: Template
// Author: Liam Kikuchi
// Section: S
// Description: The same as the previous list class,
// but modified to make lists of different data
// types. In addition to the string list, it makes
// a int and double list.

// Main is a test to make sure the template works.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "LinkedList.h"

using namespace std;

template<typename T>
void changer(LinkedList<T> dll);
int main()
{
	LinkedList<LKString> list1, list2, modList1, modList2;
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

	cout << "list1 count from infile1: ";
	cout << list1.getCount() << endl << endl;

	cout << "list2 count from infile2: ";
	cout << list2.getCount() << endl << endl;

	cout << "modList1 count: " << modList1.getCount() << endl << endl;
	cout << "modList2 count: " << modList2.getCount() << endl << endl;

	cout << "Now using assignment operator \n\n";

	modList1 = list1;
	modList2 = list2;

	cout << "list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << "list2 count from infile2: " << list2.getCount() << endl << endl;
	cout << "modList1 count after copying list1: " 
		<< modList1.getCount() << endl << endl;
	cout << "modList2 count after copying list2: " 
		<< modList2.getCount() << endl << endl;

	cout << "Now removing elements in modLists\n\n";

	list2.resetIteration();
	while(list2.hasMore()){
		modList1.remove(list2.next());
	}
	
	list1.resetIteration();
	while(list1.hasMore()){
		LKString test(list1.next());
		modList2.remove(test);
	}

	cout << "list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << "list2 count from infile2: " << list2.getCount() << endl << endl;
	cout << "modList1 count after removing matching items from list2: " 
		<< modList1.getCount() << endl << endl;
	cout << "modList2 count after removing matching items from list1: " 
		<< modList2.getCount() << endl << endl;

	cout << "----------Now calling the changer function-----------\n" 
		<< "--------In the order of modList1 then modList2----------\n\n";
	
	cout << "list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << "list2 count from infile2: " << list2.getCount() << endl << endl;
	changer(modList1);
	cout << "modList1 count after calling changer(): "
		<< modList1.getCount() << endl << endl;
	changer(modList2);
	cout << "modList2 count after calling changer(): "
		<< modList2.getCount() << endl << endl;

	ofstream fout;
	fout.open("outfile1.txt");
	modList1.resetIteration();
	while (modList1.hasMore())
		fout << modList1.next() << " ";
	fout.close();

	fout.open("outfile2.txt");
	modList2.resetIteration();
	while (modList2.hasMore()) {
		fout << modList2.next() << " ";
	}
	fout.close();

	cout << "trying other types of lists!\n\n";

	LinkedList<int> intList;
	for (int i = 20; i > 0; i -= 2)
		intList.insert(i);

	for (int i = 25; i > 0; i -= 5)
		intList.insert(i);

	cout << "intlist: " << intList << "  size:" << intList.getCount() << endl << endl;

	LinkedList<double> dblList;
	for (double i = 10.9; i > 0; i -= .57)
		dblList.insert(i);

	cout << "dblList: " << dblList << "  size:" << dblList.getCount() << endl << endl;
}

template<typename T>
void changer(LinkedList<T> dll) {
	dll.insert("ZIP");
	dll.insert("ZAP");
	cout << "This size of the list within changer(): " << dll.getCount()
		<< endl << endl;
} 


/*

*/