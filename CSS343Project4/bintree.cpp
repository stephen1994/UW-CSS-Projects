// ---------------------------bintree.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#include "bintree.h"

//========================Default-Constructor=========================
// Description: Creates a BinTree object with a null root.
// Preconditions:  None.	
// Postconditions: This BinTree object has been instantiated, and
//				root points to nullptr 		  
//==================================================================== 
BinTree::BinTree() : root(NULL) {}
//end constructor


//========================Copy-Constructor============================
// Description: Copies rightside BinTree object into this.
// Preconditions:  none
// Postconditions: none
//====================================================================
BinTree::BinTree(const BinTree& rightSide) {}
//end copy constructor


//========================Destructor==================================
// Cleans up and deallocates all dynamic memory. 
// Preconditions: root is not null
// Postconditions: This BinTree memory has been deallocated.
//====================================================================
BinTree::~BinTree() 
{
	if (root != NULL)
		makeEmpty();
}
//end destructor

//========================insert======================================
// Description: Inserts the given/taken movie to the tree. No duplicate allowed.
// Avoid duplicates and create a binary search tree.

// Preconditions: root points to NULL  
// Postconditions: Returns true if data is inserted in tree.
//		   If the data is in the tree, then return false;
//====================================================================
bool BinTree::insert(Inventory* insertMovie, const int copiesIn)
{
	Node* ptr = new Node();
	ptr->movie = insertMovie; 
	ptr->movie->setMaxStock(copiesIn);

	//insertMovie = NULL;
	ptr->left = ptr->right = NULL;

	if (isEmpty())
	{
		root = ptr; //Empty, set as root
	}

	else
	{
		Node* current = root;
		bool inserted = false;

		while (!inserted)
		{
			//no dublicate allowed
			if (*ptr->movie == *current->movie)
			{
				delete ptr;
				ptr = NULL;
				return false;
			}

			//if less than current movie, insert left
			else if (*ptr->movie < *current->movie)
			{
				if (current->left == NULL)
				{
					current->left = ptr;
					inserted = true;
				}
				else
				{
					current = current->left;
				}
					
			}

			//otherwise insert right
			else
			{
				if (current->right == NULL)
				{
					current->right = ptr;
					inserted = true;
				}
				else
				{
					current = current->right;
				}					
			}
		}
	}
	return true;
} 
//end insert

//========================isEmpty==================================
// Description: Checks if the BinTree is empty 
// Preconditions: root points to NULL
// Postconditions: returns True if the tree is empty
//====================================================================
bool BinTree::isEmpty() const
{
	return (root == NULL);
} 
//end isEmpty

//========================makeEmpty===================================
// Descrioption: Deallocates this BinTree and sets its root to NULL
//				 isEmpty() would then return true.
// Preconditions:  root points to NULL
// Postconditions: All memory has been deallocated, root is NULL.
//==================================================================== 
void BinTree::makeEmpty()
{
	destroyTree(root);
} 
//end makeEmpty

//========================destroyTree=============================
// Description: Deletes the nodes recursively and delete node and left-right

// Preconditions: root is not NULL.	 
// Postconditions: Empty the tree
//==================================================================== 
void BinTree::destroyTree(Node*& tree)
{
	if (tree != NULL)
	{
		destroyTree(tree->left); //destroy left
		destroyTree(tree->right); //destroy right
		delete tree->movie; //delete NodeData
		tree->movie = NULL;
		delete tree; //Delete Node
		tree = NULL;
	}
} 
//end destroyTree

//========================retrieve==================================== 
// Description: Finds the provided object in this tree. Returns NULL if the item
// is not found.
// 
// Preconditions: call retrieveHelper
// Postconditions: Returns true if the data found,
//	 		return false otherwise 		 
//==================================================================== 
bool BinTree::retrieve(const Inventory& dataItem, Inventory*& dataFound) const
{
	retrieveHelper(root, dataItem, dataFound);

	if (dataFound != NULL)
		return true;
	else
		return false;
} 
// end retireve

//========================retrieveHelper==============================
// Description: A helper method for retrieve. It recursively finds the provided
// object in this tree. Returns NULL if the item is not found.
// 
// Preconditions: The node is not NULL
// Postconditions: Find the data and Returns true if the data found,
//	 			return false otherwise.	 		 
//====================================================================	
void BinTree::retrieveHelper(Node* curPtr, const Inventory& dataItem,Inventory*& dataFound) const
{
	//iff current point is null and data is null
	if (curPtr == NULL) 
		dataFound = NULL;

	//if found, then assign it 
	else if (dataItem == *curPtr->movie)
		dataFound = curPtr->movie;

	//otherwise check recursivly every child
	else if (dataItem < *curPtr->movie)
		retrieveHelper(curPtr->left, dataItem, dataFound);

	else
		retrieveHelper(curPtr->right, dataItem, dataFound);
}
//end retrieveHelper

//========================inorderDisplay===============================
// Description: A helper method that recursively prints the tree in-order traversal	
// Preconditions: root is not NULL.
// Postconditions: Memorize the tree in-order traversal
// (Left,Root,Right)
//==================================================================== 
void BinTree::inorderDisplay(Node* current) const
{
	//if at the root, then show root
	if (current == root)
	{
		current->movie->displayHeader();
	}

	//if not null, go ascending order(in order) recursively
	if (current != NULL) 
	{
		inorderDisplay(current->left);

		cout << right << setw(2) << current->movie->getAmountIn() << "  " <<
			left << setw(3) << current->movie->getAmountOut() << " ";
		current->movie->display();

		inorderDisplay(current->right);
	}
}
//end inorderDisplay

//========================getRoot===============================
// Description : Show the root.
// Preconditions: root is not NULL.
// Postconditions: Get the root.
//==================================================================== 
BinTree::Node* BinTree::getRoot() const 
{
	return this->root;
}
//end getRoot
