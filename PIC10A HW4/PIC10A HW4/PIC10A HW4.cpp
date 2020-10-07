
//Need to include some new libraries, namely cmath and iomanip to use the natural log function and the line manipulators.

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()

{
	//Defining the strings for the left and right columns as well as some constants determined empirically from our model.

	string lcol, rcol;

	const double a = .12; //Volts
	const double b = 2.8e9; // cm^2/A
	const int c = -60; //Unitless

	//Defining the variables for our user determined current densities.

	double j1, j2, j3; // A/cm^2

	//Asking the user to enter labels for the left and right sides of the table.

	cout << "Enter left label: ";

	getline(cin, lcol);

	cout << "Enter right label: ";

	getline(cin, rcol);

	//Asking the user to input the aforementioned current densities.

	cout << "Enter three current densities in the range of 0 to 0.07 A/cm^2 separated by spaces: ";
	cin >> j1 >> j2 >> j3;

	//Defining three variables for the yet-to-be  calculated voltages. 

	double v1, v2, v3;

	//The equations we will use to calculate each voltage value for each respective current density.
	//All of these values should have the units of Volts.

	v1 = a*(log((b*j1) - c));
	v2 = a*(log((b*j2) - c));
	v3 = a*(log((b*j3) - c));

	char p = 124; //ASCII value for the "pipe" character. 

	//Displaying the fruit of our labor.

	cout << "Here is your table:\n\n";

	//Header, prints the left and right labels separated by pipe character.

	cout << lcol << p << rcol << "\n";

	//Separator line, prints a line of hyphens the length  of the header line separated by a pipe character.

	cout << setfill('-') << setw(lcol.size() + 1) << p << setw(rcol.size() + 1) << "\n";

	// Makes all of the calculated voltages have three decimal places, including ending zeros.

	cout << fixed << setprecision(3);

	//First line, prints the values of j1 and v1 so that it is right and left justified respectively. The two values are separated by a pipe character.

	cout << right << setfill(' ') << setw(lcol.size()) << j1;
	cout << p << left << setw(rcol.size()) << v1 << "\n";

	//Second line, prints the values of j2 and v2 so that it is right and left justified respectively. The two values are separated by a pipe character.

	cout << right << setfill(' ') << setw(lcol.size()) << j2;
	cout << p << left << setw(rcol.size()) << v2 << "\n";

	//Third line, prints the values of j3 and v3 so that it is right and left justified respectively. The two values are separated by a pipe character.

	cout << right << setfill(' ') << setw(lcol.size()) << j3;
	cout << p << left << setw(rcol.size()) << v3 << "\n";

	//Makes the console say on the screen.

	cin.ignore();
	cin.get();

	return 0;
}