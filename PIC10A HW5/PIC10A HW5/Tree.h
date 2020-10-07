#include<string>

using namespace std;

#ifndef _StringSort_
#define _StringSort_

/* You can IGNORE EVERYTHING FROM HERE --> */

class StringNode {
public:
	/** At the creation of a new node, make left and right null and set the word */
	StringNode(const string& word);

	/**With this function, the input word is compared against the word at the current
	node and moved left or right accordingly

	@param root is the pointer to the current node
	@param word is the word that was entered by the user
	*/
	void addNode(StringNode* node, const string& word);

private:
	// Stores a word
	string word;

	// Stores a left/right node pointer
	StringNode* left;
	StringNode* right;

	// The StringTree class can access private member data
	friend class StringTree;

	// Used to delete the tree when the destructor is called
	void delete_tree();
};

/* <-- ... down to here! */

/* You should PAY ATTENTION to the class below, though! */

class StringTree {
public:
	// Creates an empty tree
	StringTree();

	StringTree(const StringTree&) = delete;

	// Will add the new word, unless it is already there
	void add(const string& word);

	// Will return the first word (alphabetically) or "" if nothing stored 
	string get_first() const;

	// Will return the last word (alphabetically) or "" if nothing stored
	string get_last() const;

	/** Will remove the first word (alphabetically) or do nothing if nothing stored */
	void remove_first();

	/** Will remove the last word (alphabetically) or do nothing if nothing stored */
	void remove_last();

	/** Deletes the tree. You can safely ignore this.
	It is called a destructor.*/
	~StringTree();

	// You can IGNORE the private section below
private:
	// A pointer to the root of the tree
	StringNode* root;

};

#endif