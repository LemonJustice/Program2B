// Program2B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	LKString testStr("hello");

	cout << "Testing testStr.at() function\n"; // testStr.at(0) should return 'h'
	for (int i = -1; i < 10; i++) {          // purposely testing out of bounds
		cout << i << ":" << testStr.at(i) << ' '
			<< static_cast<int>(testStr.at(i)) << endl;
	}
	cout << testStr.c_str() << endl;
	cout << endl << endl;
}
