// ---------------------------store.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H
#include "movie.h"

class BinTree
{
	//friend ostream& operator<<(ostream& output, BinTree& tree);
	struct Node;

public:

	BinTree();
	BinTree(const BinTree&); // copy constructor
	~BinTree();

	//insert movie, check if empty, retrieve movie, get the root, and inorder methods
	bool insert(Inventory* insertMovie, const int copiesIn);
	bool isEmpty() const;
	void makeEmpty(); 
	bool retrieve(const Inventory& dataItem, Inventory*& dataFound) const;
	void retrieveHelper(Node* curPtr,
	const Inventory& dataItem, Inventory*& dataFound) const;
	void inorderDisplay(Node* current) const;
	Node* getRoot() const;
private:
	
	struct Node
	{
		Inventory* movie; 
		Node* left, * right; 
	};

	Node* root; 

	//helper method for destroy the tree
	void destroyTree(Node*& tree);
};
#endif