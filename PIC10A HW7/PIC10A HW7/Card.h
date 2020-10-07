#ifndef __CARD__
#define __CARD__

#include<string>
#include<sstream>

using namespace std;

class Card{
public:
	/**
	Constructor: takes two inputs. The first input is a string, one of "Clubs", "Diamonds", "Hearts", or "Spades".
	The second input is the face as a string: "A", "2", "3", ... "9", "10", "J", "Q", "K".
	*/
	Card(const string &suitType, const string &face) : suit(suitType), face(face) {}

	/**
	Member function: returns the card as a string, for example "10[Diamonds]"
	*/
	string display() const { return face + "[" + suit + "]"; }

private:
	string suit, face;

};


/**
Function converts a size_t integer to a string.

For example,

string s = num_to_string(809);

sets s to "809"

@param n the number
@return the number as a string
*/
string num_to_string(size_t n)
{
	ostringstream o;
	o << n;

	return o.str();
}


/**
Function converts a single numeric digit as a character to an unsigned int value.

For example, it is possible to set x to 1 by:

unsigned int x = char_to_num('1');

@param c the character
@return the value
*/
unsigned char_to_num(char c)
{
	if (c < '0' || c > '9')
		throw runtime_error("Invalid input to char_to_num");

	return c - '0';
}


#endif