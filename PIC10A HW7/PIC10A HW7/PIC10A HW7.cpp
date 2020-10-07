#include<iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Card.h"


using namespace std;

int main()

{
	// Rules of the game explained.

	cout << "This is a card game of Six-Hundred where you work to a target hand value.\n";

	cout << "Each round, the target value increases by 5, starting at 25, ending at 50.\n";

	cout << "Cards 2-10 are worth their value; J, Q, and K are worth 10; and A is worth 11.\n";

	cout << "If you go over the target value in a given round, the game is over and you earn -600 points.\n";

	cout << "If you reach the target exactly, you earn 100 points. ";

	cout << "Your points in a given round are otherwise 100 - 20*difference where difference is how far off you are from the target. Scores can be negative! ";

	cout << "The best possible score is 600." << endl << endl;

	/*---------------------------------------------------------------------------------------------------------------------------*/
	//Properly seeding the rand function for later.

	srand(time(nullptr));

	//Defining some variables for later.

	char cont; //Xcode didn't like me defining this later, so I defined it here so the code would compile.

	int rscore; //Score of the round.

	int score = 0; //Total score overall. Initially it must be zero.

	//Loops through all of the things that must be done each round.
	//Loop is active for the duration of the game.

	for (int round = 0; round < 6; ++round)

	{
		//Making vectors of cards that will function as the round's deck and hand.

		vector <Card> deck, hand;

		//How the deck is actually constructed.

		vector <string> suit{ "Spades", "Clubs", "Diamonds", "Hearts" };
		vector <string> face{ "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

		for (size_t i = 0; i <= 12; ++i)

			for (size_t j = 0; j <= 3; ++j)

			{
			//Makes a card with a particular suit and face value.

			Card c(suit[j], face[i]);

			//Adds the card to the deck.

			deck.push_back(c);
			}

		int tval = 25 + (round * 5); //Target value per round.

		int handval = 0; //Current value of the hand. Initally it must be zero.

		int cval, diff; //Value of the current card drawn and the difference between the target value and the hand value.

		int i = 0; //Counter variable I need for later.

		do

		{
			//Selecting a random card position from within the virtual deck of cards.

			int cpos = rand() % deck.size();

			//Adds the randomly selected card to the player's hand.

			hand.push_back(deck[cpos]);

			//Removes that card from the deck so it cannot be selected again during the round.

			deck.erase(begin(deck) + (cpos - 1));

			//Makes a string of the selected card so its value can be determined.

			string cstring = hand[i].display();

			//The information of the card's value can be found from the first character of cstring.

			char cchar = cstring[0];

			//Using ASCII values to identify characters.

			if (cchar > 49 && cchar < 58) //If the character is 2-9 we can use a provided function to get the cards value.

				cval = char_to_num(cchar);

			else if (cchar == 65) //If the character is an A then it's an Ace so its value is 11.

				cval = 11;

			else //In any other case the value must be 10.

				cval = 10;

			handval += cval; //Getting the current value of the player's hand.

			//The process of outputting the cards in the player's hand.

			cout << "Hand: ";

			//Outputs all of the cards but the last with spaces separating them.

			for (size_t k = 0; k < i; ++k)

				cout << hand[k].display() << " ";

			//Outputs the last card in the hand without a spacgjgfj]ple after it, but instead a newline character.

			cout << hand[i].display() << "\n";
		
			//Increments the counting variable so next time it knows there are more cards in the hand.

			i = ++i;

			//Outputs the target value of the round and the current value of the player's hand.

			cout << "Target : " << tval << "." << "Your total hand value: " << handval << "\n";

			//Calculates the difference between the target value and the player's hand.
			//Depending on the value we proceed differently.

			diff = tval - handval;

			//If the difference is less than zero it means the hand value is greater than the target value so the player loses.

			if (diff < 0)

			{

				//For their lose, we insult them by deducing 600 points.

				score -= 600;

				//We then leave the do loop because we don't want to contine with the game.

				break ;

			}

			//If the difference is not less than zero the game continues so we need to ask if the player if he or she wants to keep being dealt cards.

			cout << "Deal more? [y/n]: ";

			cin >> cont;

			//Should they say yes, the do loop repeats.

		} while (cont == 'y');

		//If the player lost they do not get a round score and the game is over so we also need to leave the for loop.

		if (diff < 0)

		{
			//Need the newline character for proper formatting.

			cout << "\n";
			break;
		}

		//Calculates the player's score for the round.

		rscore = 100 - (20 * diff);

		//Adds the round score to the player's overall game score.

		score += rscore;

		//Tells the player what their overall game score currently is.

		cout << "Your score right now is: " << score << "\n" << "\n";

		//Removes all cards from the current deck and hand in preparation for the next round.

		for (size_t i = 0; i < deck.size(); ++i)
			deck.erase(deck.begin() + i);

		for (size_t i = 0; i < hand.size(); ++i)
			hand.erase(hand.begin() + i);

	}

	//GAME OVER!!!!!!
	//Displays the player's final overall game score.

	cout << "Game over. Your total score is: " << score << "\n";

	cin.ignore();
	cin.get();

	return 0;
}


