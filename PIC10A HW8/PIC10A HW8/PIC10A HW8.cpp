#include <iostream>
#include <iomanip> //Need to include iomanip to setprecision later.

using namespace std;

/* This function returns the maximum of a and 1.
@param a input double
return a if a>1 or 1 if it is not */

double getmax(double a){

	if (a > 1)
		return a;

	else
		return 1;

}

/* This function computes the midpoint of l and r
@param l first input double
@param r second input double
return mid the average of l and r */

double getmid(double l, double r){

	double mid = (l + r) / 2;

	return mid;


}

/* This function raises a number x to the integer power x
@param x input double
@param n input int
return ans x raised to the power n */

double mypow(double x, int n){

	double ans = x;

	for (int i = 1; i < n; ++i)
		ans *= x;

	return ans;

}

/* This function computes the value of the functiion x^n - a
@param x input double
@param n input int
@param a input double
return fn_x the value of the function at point x, raised to the power n, minus a. */

double funcval(double x, int n, double a){

	double fn_x = mypow(x, n) - a;

	return fn_x;
}

/* This function outputs a string literal reporting the value of our approximate solution l after m steps to 9 decimal places.
@param m input int
@param l input double */

void valreport(int m, double l){

	cout << setprecision(9) << fixed;
	cout << "Approximation with " << m << " steps: " << l << "\n";


}

/* This function outputs a string literal reporting the final value of our approximate solution (or lack thereof) to 9 decimal places.
@param m input int
@param l input double */

void finalval(int m, double l){

	if (m > 50)
		cout << "Failed to find a solution." << "\n:";

	else
		cout << "x is " << l << "\n";

}

/* This function outputs a string literal reporting the final value of our approximate solution (or lack thereof).
@param m input int
@param l input double */

/* This function changes the values of l or r depending on the product of fnl and fnm.
@param fnl input double
@param fnm input double
@param &l input reference double
@param &r input reference double
@param m input double  */

void change(double fnl, double fnm, double &l, double &r, double m){

	double val = fnl*fnm;

	if (val < 0)
		r = m;

	else
		l = m;
}

int main()

{
	//Defining the variables for n (the root we will be finding) and a (the number we will be finding the roots of).

	int n;

	double a;

	//Describing the purpose of the program.

	cout << "This program finds a positive value of x that satisfies x^n - a = 0 for an integer n > 0 and a floating point a > 0." << "\n";

	//Getting the value of n.

	cout << "Please enter a value for n: ";
	cin >> n;

	//Getting the value of a.

	cout << "Please enter a value for a: ";
	cin >> a;

	//Defining the variable for the number of steps we have taken in our approximation.

	int m = 0;

	//Defining the rest of our variables.

	double l = 0, r = getmax(a), fn_l = funcval(l, n, a), tol = 1e-10; //fn_l does not need to be initialized but we will do it anyway.
	double mid, fn_mid;

	// While m<= 5 and r-l > tol and fn_l != 0 we want to do this:

	while (m <= 50 && (r - l)> tol && fn_l != 0)

	{
		//Finds the midpoint of l and r and assigns it to mid.

		mid = getmid(l, r);

		//Computes the function at l and mid respectively.

		fn_l = funcval(l, n, a);
		fn_mid = funcval(mid, n, a);

		//Depending on the product of fn_l and fn_mid changes l or r.

		change(fn_l, fn_mid, l, r, mid);

		//Reports the value of our approximate solution l after m steps to 9 decimal places.

		valreport(m, l);

		//Increments m.

		++m;

		//We need to check fn_l again incase fn_mid was equal to zero.

		fn_l = funcval(l, n, a);

	}


	//Prints the final solution (or lack thereof).

	finalval(m, l);

	//Makes the console stay on the screen.

	cin.ignore();
	cin.get();

	return 0;
}






