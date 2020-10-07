#include<string>
#include<iostream>

#include "Tree.h"

using namespace std;

// You can IGNORE EVERYTHING in this file. Just make sure it is part of your project!

/** At the creation of the StringTree, create a new root node with empty string*/
StringTree::StringTree() : root(new StringNode(""))
{}

/** The destructor - recursively deletes the tree's subtrees */
StringTree::~StringTree()
{
	root->delete_tree();
	root = nullptr;
}

StringNode::StringNode(const string& word) : left(nullptr), right(nullptr)
{
	this->word = word;
}

/** Either add at the beginning or pass on to the nodes for placement */
void StringTree::add(const string& word)
{
	// If the root has an empty string, make its word the input
	if ((this->root)->word == "")
	{
		(this->root)->word = word;
	}
	// Otherwise, recursively call the addNode
	else
	{
		(this->root)->addNode(this->root, word);
	}
}

void StringNode::addNode(StringNode* root, const string& word)
{
	// If the input is smaller, move left
	if (root->word > word)
	{
		// If the left is not null, recurse upon the left node
		if (root->left != nullptr)
		{
			addNode(root->left, word);
			return;
		}
		// If the left is null, add it on
		else
		{
			root->left = new StringNode(word);
			return;
		}
	}

	// If the input is bigger, move right
	else if (root->word < word)
	{
		// If the right is not null, recurse upon the right node
		if (root->right != nullptr)
		{
			addNode(root->right, word);
			return;
		}
		// If the right is null, add it on
		else
		{
			root->right = new StringNode(word);
			return;
		}
	}
	// Do nothing if already on the tree
	else
		return;
}

/** If the left subtree is not null, delete it. Then, if the
right subtree is not null, delete it. Finally, delete the node
itself */
void StringNode::delete_tree()
{
	if (this->left != nullptr)
	{
		left->delete_tree();
		left = nullptr;
	}

	if (this->right != nullptr)
	{
		right->delete_tree();
		right = nullptr;
	}

	delete this;
}

string StringTree::get_first() const
{
	// Begin at the root and keep moving left
	StringNode* temp = root;

	while (temp->left != nullptr)
		temp = temp->left;

	return temp->word;
}

string StringTree::get_last() const
{
	// Begin at the root and keep moving left
	StringNode* temp = root;

	while (temp->right != nullptr)
		temp = temp->right;

	return temp->word;
}

void StringTree::remove_first()
{
	StringNode* current = root;

	// If we cannot go left
	if (current->left == nullptr)
	{
		// Check if there is a right-side
		// If not, we're at the root
		if (current->right == nullptr)
			// So nothing has happened
			if (current->word == "")
				return;
		// So we clear the root string 
			else
			{
				current->word = "";
			}
		// If so, we restructure the tree and remove the root
		else
		{
			root = current->right;
			delete current;
			return;
		}
	}
	// So we can go left
	else
	{
		// Keep moving left but don't go too far
		while ((current->left)->left != nullptr)
			current = current->left;

		// If the left's right is empty, kill it
		if (current->left->right == nullptr)
		{
			delete current->left;
			current->left = nullptr;
		}
		// If it has a left right, restructure the tree
		else
		{
			StringNode* temp = current->left->right;
			delete current->left;
			current->left = temp;
		}
		return;
	}

}

void StringTree::remove_last()
{
	StringNode* current = root;

	// If we cannot go right
	if (current->right == nullptr)
	{
		// Check if there is a left-side
		// If not, we're at the root
		if (current->left == nullptr)
			// So nothing has happened
			if (current->word == "")
				return;
		// So we clear the root string 
			else
			{
				current->word = "";
			}
		// If so, we restructure the tree and remove the root
		else
		{
			root = current->left;
			delete current;
			return;
		}
	}
	// So we can go right
	else
	{
		// Keep moving right but don't go too far
		while ((current->right)->right != nullptr)
			current = current->right;

		// If the right's left is empty, kill it
		if (current->right->left == nullptr)
		{
			delete current->right;
			current->right = nullptr;
		}
		// If it has a right left, restructure the tree
		else
		{
			StringNode* temp = current->right->left;
			delete current->right;
			current->right = temp;
		}
		return;
	}
}