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
	LKString str1("Hello");
	LKString str2("hello");
	LKString str3("Test");
	LKString str4("DoesItWork?");

	LinkedList dll;

	dll.insert(str1);
	dll.insert(str2);
	dll.insert(str3);
	dll.insert(str4);

	cout << dll;
}

/*

*/