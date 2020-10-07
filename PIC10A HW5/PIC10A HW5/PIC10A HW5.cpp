

// We need to include a nonstandard header file "Tree.h" to have the neat functions the professor has provided us.

#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

int main()

{
	//Defining a bunch of stuff.
	//We will use two StringTree variables to store all of the data we will need to display the names.

	StringTree tree1, tree2;

	string name;

	//This character will tell us when to stop asking for names. Since we need to ask for at least one name it should be initially set to 'y' for "yes."

	char cont = 'y';

	//While the character is 'y' we should continue to ask the user for more names. If it ever isn't set to 'y' we will stop asking for names. 

	while (cont == 'y')

	{
		//Asks the user for a name.

		cout << "Enter a name last, first: ";
		getline(cin, name);

		//Adds the name the user entered into the first StringTree variable.

		tree1.add(name);

		//Asks the user to enter a character depending whether or not they want to continue adding more names.
		//If the user enters the character 'n' the loop will terminate as cont = 'n' != 'y' .

		cout << "More names? y/n: ";
		cin >> cont;

		//Since we are using cin.get to read the user's input we need to clear the buffer as there will be a straggling newline character.

		cin.ignore();

	}

	//Makes an empty line and displays the user's name entries alphabetically by last name.

	cout << "\n";
	cout << "All of the names in alphabetical order are: \n";

	//This loop is active while there are still names in tree1.

	while (tree1.get_first() != "")

	{
		//Displays the first name alphabetically in tree1.

		cout << tree1.get_first() << "\n";

		//Puts the name just displayed into a new StringTree variable, tree2.

		tree2.add(tree1.get_first());

		//Removes the name just displayed from tree1 to make way for the next name alphabetically.

		tree1.remove_first();

	}

	//Makes another empty line and displays only the first names of user's entries in the same order as before (alphabetically by last name).

	cout << "\n";
	cout << "And all of the first names following the same order as above are: \n";

	//We define a new variable to help us index the names the user has entered.

	int n;

	//This loop is active while there are still names in tree2.

	while (tree2.get_first() != "")

	{
		//We initialize n has zero within the loop so it will be zero for each name we need to index.

		n = 0;

		//This loop is active so long as the character within the entered name is not a ','.
		//With this we can locate where the last name ends.

		while (tree2.get_first()[n] != ',' && tree2.get_first()[n + 1] != ' ')

		{
			//While the character of the entered name is not ',' we need to keep looking, so we increment n.

			++n;

		}

		//After we have located the comma, we can extract the first name only.
		//Since there will be a comma followed by a space we need to add to n's final value and make a substring starting at this value and going to the end of the entry.

		cout << tree2.get_first().substr(n + 2) << "\n";

		//Removes the name just displayed from tree1 to make way for the next name alphabetically.

		tree2.remove_first();

	}

	//Makes the console stay on the screen.

	cin.ignore();
	cin.get();

	return 0;

}


