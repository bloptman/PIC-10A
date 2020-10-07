#include <iostream>

using namespace std;

//This program will convert numbers (within the appropriate range)from base 10 to base 2 or vice versa.

int main()

{
	// Defining a bunch variables...

	int numin;
	int p4, p3, p2, p1, p0;
	int binout;
	int diff;

	//Getting an appropriate numberical input (a base 10 number) from the user.

	cout << "Enter a base 10 integer from 0 to 31: ";
	cin >> numin;

	// The good stuff. This part of the code will break the inputed number into the appropriate powers of 2.

	p4 = numin / 16;
	diff = numin - (16 * p4);

	p3 = diff / 8;
	diff = diff - (8 * p3);

	p2 = diff / 4;
	diff = diff - (4 * p2);

	p1 = diff / 2;
	diff = diff - (2 * p1);

	p0 = diff / 1;

	// This will print the base 10 number in base 2 to the screen.

	binout = (p4 * 10000) + (p3 * 1000) + (p2 * 100) + (p1 * 10) + (p0 * 1);

	cout << "You entered a value of " << numin << " in base 10. In base 2, that number is " << binout << ".\n";

	// The remainder of the code basically repeats what has already been done above. The only difference that this time we use powers of 10 instead of powers of 2.

	//Defining some more variables...

	int binin;
	int q4, q3, q2, q1, q0;
	int numout;
	int difff;

	//Getting an appropriate numberical input (a base 2 number) from the user.

	cout << "Now give me a base 2 integer from 0 to 11111: ";
	cin >> binin;

	//Converting the inputted number into the appropriate powers of 10.

	q4 = binin / 10000;
	difff = binin - (10000 * q4);

	q3 = difff / 1000;
	difff = difff - (1000 * q3);

	q2 = difff / 100;
	difff = difff - (100 * q2);

	q1 = difff / 10;
	difff = difff - (10 * q1);

	q0 = difff / 1;

	numout = (16 * q4) + (8 * q3) + (4 * q2) + (2 * q1) + (1 * q0);

	// Printing the base 2 number in base 10.

	cout << "You entered a value of " << binin << " in base 2. In base 10, that number is " << numout << ".";

	// Makes the console stay on the screen.

	cin.ignore();
	cin.get();

	return 0;

}