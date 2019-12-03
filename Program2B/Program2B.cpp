// Class Name: LKString: Program 4: Lists 
// Author: Liam Kikuchi
// Section: S
// Description: The class uses a previously made string class
// to store strings obtained from file. These strings are put
// into a list and ordered alphabetically. There are two
// lists, one for each file, which are used to make two other
// lists that lack words found within the opposite list.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "LinkedList.h"

using namespace std;


void changer(LinkedList dll);
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
		<< "^ list1 count from infile1: ";
	cout << list1.getCount() << endl << endl;

	cout << list2 << "\n_________________________________________________\n"
		<< "^ list2 count from infile2: ";
	cout << list2.getCount() << endl << endl;

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
		<< "^ modList1 count after copying list1: " 
		<< modList1.getCount() << endl << endl;
	cout << modList2 << "\n_________________________________________________\n"
		<< "^ modList2 count after copying list2: " 
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

	cout << list1 << "\n_________________________________________________\n"
		<< "^ list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << list2 << "\n_________________________________________________\n"
		<< "^ list2 count from infile2: " << list2.getCount() << endl << endl;
	cout << modList1 << "\n_________________________________________________\n"
		<< "^ modList1 count after removing matching items from list2: " 
		<< modList1.getCount() << endl << endl;
	cout << modList2 << "\n_________________________________________________\n"
		<< "^ modList2 count after removing matching items from list1: " 
		<< modList2.getCount() << endl << endl;

	cout << "----------Now calling the changer function-----------\n" 
		<< "--------In the order of modList1 then modList2----------\n\n";
	
	cout << list1 << "\n_________________________________________________\n"
		<< "^ list1 count from infile1: " << list1.getCount() << endl << endl;
	cout << list2 << "\n_________________________________________________\n"
		<< "^ list2 count from infile2: " << list2.getCount() << endl << endl;
	changer(modList1);
	cout << modList1 << "\n_________________________________________________\n"
		<< "^ modList1 count after calling changer(): "
		<< modList1.getCount() << endl << endl;
	changer(modList2);
	cout << modList2 << "\n_________________________________________________\n"
		<< "^ modList2 count after calling changer(): "
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

}

void changer(LinkedList dll) {
	dll.insert("ZIP");
	dll.insert("ZAP");
	cout << "This size of the list within changer(): " << dll.getCount() << endl;
}


/*

*/