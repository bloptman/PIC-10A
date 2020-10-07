

#include <iostream>

using namespace std;

int main()

{
	//Defining  the lower and upper bounds of the numbers we need to factorize.

	unsigned int low, high;

	//Defining some variables we will use within some loops later.

	unsigned int i, div;

	//Asking the user to enter the bounds of the numbers we will factorize.

	cout << "Enter a range of numbers to factorize. Enter a lower bound and upper bound separated by a space: ";

	// Getting the values for the lower and upper bounds.

	cin >> low >> high;

	//This loop will be active while within the user specified bounds.
	//Each repetition of the loop will increment the current number being examined by one.

	for (i = low; i <= high; ++i)

	{
		//Displaying the number being examined.

		cout << i << ": ";

		//These variables will be used to determine the factors (if any) of the number.

		const unsigned int d0 = 2;   //Initial value for the divisor.

		unsigned int d = d0; //Setting the general divisor equal to the initial one.

		unsigned int n = 0; //Indexing value used to generate odd numbers later.

		div = i; //Setting the general dividend initially equal to the number being examined.

		//As long as the dividend is greater than the divisor we should do these things to (nearly) completely factor the number.
		//This condition is special in that it will catch the rogue prime 2 and will not result in the number being completely factored.

		while (div > d)

		{

			//If this is true then d must be a factor of i so we should display it.

			if (div % d == 0)

			{
				cout << d << " x ";

				//If d is indeed a factor we should see if it continues to be a factor, so we divide by it again.

				div = div / d;

			}

			//If d is not a factor of i we should change d.
			//Since d is initially at 2, if d is not 2 it must be an odd number, so we change d by adding odd numbers to 2.

			else

			{
				d = d0 + ((2 * n) + 1); // (2n+1) is always odd.
				++n;

			}

			//We need separate conditions for the final factor.

		}

		//If the divisor gets the the point it is the value of the number being examined it must not have any factors, so it is prime.

		if (d == i)

		{
			cout << "prime!\n";

		}

		//The other case would be that the divisor is equal to the divident, meaning that it is the final factor of i (That is, div/d == 1).
		//If this is the case we should output this factor. Since it is the last factor nothing should follow it.

		else

		{
			cout << d << "\n";
		}

	}

	//Makes the console stay on the screen.

	cin.ignore();
	cin.get();

	return 0;

}




