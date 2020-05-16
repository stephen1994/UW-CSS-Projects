// ------------------------------------------------ bintree.h -------------------------------------------------------
// Stephen Choi CSS 343 C
// Jan 20, 2020
// Feb 01, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This program is to create a binary search tree class called BinTree along with some additional functions.
// --------------------------------------------------------------------------------------------------------------------

#include "nodedata.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class BinTree {				
	// --------------------------------operator <<---------------------------------------
	// Description
	// operator <<: Operator to print out the Binary Search Tree.
	// predonditions: Parameters are not NULL
	// postconditions: Returns NodeData of each node in the binary search tree
	// ----------------------------------------------------------------------------------
	friend void operator<<(ostream& output, const BinTree& b);
	//end of operator <<

public:
	// --------------------------------BinTree()---------------------------------------
	// Description
	// BinTree(): Default constructor for the binary search tree
	// predonditions: No preconditions 
	// postconditions: Create the root and set left, right, data to nullptr
	// ----------------------------------------------------------------------------------	
	BinTree();								// constructor
	//end of Default Constructor 

	// --------------------------------BinTree()---------------------------------------
	// Description
	// BinTree(): Copy Constructor for the binary search tree that deep copies
	// predonditions: b is not NULL
	// postconditions: Deep copies the b 
	// ----------------------------------------------------------------------------------
	BinTree(const BinTree& b);				// copy constructor
	//end of Copy Constructor

	// --------------------------------~BinTree()---------------------------------------
	// Description
	// ~BinTree(): Destructor for the BinTree. Takes care of de-allocating all nodes 
	//             in the binary search tree to the system.
	// predonditions: No preconditions
	// postconditions: Delete all the Nodes
	// ----------------------------------------------------------------------------------
	~BinTree();								// destructor, calls makeEmpty	
	//end of Destructor

	// --------------------------------isEmpty---------------------------------------
	// Description
	// isEmpty: function to tell if the BinTree empty or not 
	// predonditions: No preconditions
	// postconditions: Return true if it's empty or false      
	// ----------------------------------------------------------------------------------
	bool isEmpty() const;					// true if tree is empty, otherwise false
	//end of isEmpty

	// --------------------------------makeEmpty---------------------------------------
	// Description
	// : function to empty the BinTree 
	// predonditions: No preconditions
	// postconditions: BinTree is empty                
	// ----------------------------------------------------------------------------------
	void makeEmpty();						// make the tree empty so isEmpty returns true
	//end of makeEmpty

	// --------------------------------operator =---------------------------------------
	// Description
	// operator =: Assignment operator for BinTree
	// predonditions: b is not NULL
	// postconditions: Deep Copies the reference b to *this
	// ----------------------------------------------------------------------------------
	BinTree& operator=(const BinTree& b);
	//end of operator=
	
	// --------------------------------operator ==---------------------------------------
	// Description
	// operator ==: Function to compare this and reference b.
	// predonditions: b is not NULL
	// postconditions: Returns true if they are same, false if not.
	// ----------------------------------------------------------------------------------
	bool operator==(const BinTree& b) const;
	//end of operator==

	// --------------------------------operator !=---------------------------------------
	// Description
	// operator !=: Function to compare this and reference b.
	// predonditions: b is not NULL
	// postconditions: Returns true if they are not same, false if not.
	// ----------------------------------------------------------------------------------
	bool operator!=(const BinTree& b) const;
	//end of operator!=

	// --------------------------------insert---------------------------------------
	// Description
	// insert: function to insert new Node to the binary search tree  
	// predonditions: newData is not NULL
	// postconditions: insert newData in the right place in the binary search tree 
	// ----------------------------------------------------------------------------------
	bool insert(NodeData*);
	//end of insert

	// --------------------------------retrieve---------------------------------------
	// Description
	// retrieve: function to get the NodeData* of a given object in the tree  
	// predonditions: dataR is not NULL
	// postconditions: if the object is found, 
	//                 dataDR will point to the actual object in the tree 
	// ----------------------------------------------------------------------------------
	bool retrieve(const NodeData&, NodeData*&) const;
	//end of retrieve

	// --------------------------------getHeight---------------------------------------
	// Description
	// getHeight: function to find the height of a given value in the tree.   
	// predonditions: data is not NULL, the height of a node at a leaf is 1.
	// postconditions: return height of Node that has NodeData of data, 
	//                 if not found return 0
	// ----------------------------------------------------------------------------------
	int getHeight(NodeData& data);
	//end of getHeight

	// --------------------------------bstreeToArray---------------------------------------
	// Description
	// bstreeToArray: Function to fill an array of NodeData* by using 
	//                an inorder traversal of the tree
	// predonditions: No preconditions
	// postconditions: Fill an array and leaves the tree empty
	// ----------------------------------------------------------------------------------
	void bstreeToArray(NodeData* array[]);
	//end of bstreeToArray

	// --------------------------------arrayToBSTree---------------------------------------
	// Description
	// arrayToBSTree: Function to builds a balanced BinTree from a sorted 
	//                array of NodeData* leaving the array filled with NULLs.  
	// predonditions: No preconditions
	// postconditions: Leaves an array empty    
	// ----------------------------------------------------------------------------------
	void arrayToBSTree(NodeData* array[]);
	//end of arrayToBSTree

	//------------------------- displaySideways ---------------------------------
	// Displays a binary tree as though you are viewing it from the side;
	// hard coded displaying to standard output.
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	// ----------------------------------------------------------------------------------
	void displaySideways() const;			// provided below, displays the tree sideways
	//end of displaySideways

private:
	struct Node {
		NodeData* data;						// pointer to data object
			Node* left;							// left subtree pointer
			Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

// utility functions
	void inorderHelper(Node* root) const;
	//end of inorderHelper

	void sideways(Node*, int) const;			// provided below, helper for displaySideways()
	//end of sideways

	// --------------------------------assignmentHelper---------------------------------------
	// Description
	// : Helper function for the operator =  
	// predonditions: No preconditions
	// postconditions: copy b to *this   
	// ----------------------------------------------------------------------------------
	void assignmentHelper(Node*& root, Node* currentB, const BinTree& b);
	//end of assignmentHelper

	// --------------------------------emptyHelper---------------------------------------
	// Description
	// emptyHelper: Helper function for makeEmpty  
	// predonditions: No preconditions
	// postconditions: Empty the BinTree and deallocate the nodes 
	// ----------------------------------------------------------------------------------
	void emptyHelper(Node*& root);
	//end of emptyHelper

	// --------------------------------insertHelper---------------------------------------
	// Description
	// insertHelper: Helper function for the insert  
	// predonditions: root and newData is not NULL 
	// postconditions: Create a new Node with newData and insert them in the right place 
	// ----------------------------------------------------------------------------------
	bool insertHelper(Node*& root, NodeData* newData);
	//end of insertHelper

	// --------------------------------retrieveHelper---------------------------------------
	// Description
	// retrieveHelper: Helper function for the retrieve  
	// predonditions: No preconditions
	// postconditions: if the object is found,
	//                 dataDR will point to the actual object in the tree
	//                 and return true. If not found, return false
	// ----------------------------------------------------------------------------------
	bool retrieveHelper(Node* root, const NodeData& dataR, NodeData*& dataDR) const;
	//end of retrieveHelper

	// --------------------------------getHeightHelper---------------------------------------
	// Description
	// getHeightHelper: Helper function for the getHeight 
	// predonditions: data is not NULL
	// postconditions: return bigger depth between left hand side and right hand side
	// ----------------------------------------------------------------------------------
	int getHeightHelper(Node* root, NodeData& data);
	//end of getHeightHelper

	// --------------------------------getHeightHelper2---------------------------------------
	// Description
	// getHeightHelper2: Second helper function for the getHeight  
	// predonditions: data is not NULL
	// postconditions: locate the corresponding Node that has data value   
	// ----------------------------------------------------------------------------------
	int getHeightHelper2(Node* root, NodeData& data);
	//end of getHeightHelper2

	// --------------------------------bstreeToArrayHelper---------------------------------------
	// Description
	// bstreeToArrayHelper: Helper function for the bstreeToArray  
	// predonditions: No precondition
	// postconditions: fill an array of NodeData*
	// ----------------------------------------------------------------------------------
	void bstreeToArrayHelper(NodeData* array[], Node* root, int index);
	//end of betreeToArrayHelepr

	// --------------------------------arrayToBSTreeHelepr---------------------------------------
	// Description
	// arrayToBSTreeHelepr: Helper function for the arrayToBSTree  
	// predonditions: No preconditions
	// postconditions: builds a balanced BinTree          
	// ----------------------------------------------------------------------------------
	NodeData* arrayToBSTreeHelper(NodeData* array[], int low, int high);
	//end of arrayToBSTreeHelper

	// --------------------------------isEqual---------------------------------------
	// Description
	// isEqual: function to compare two BinTree from the root if they're equal
	// predonditions: No preconditions
	// postconditions: return true if they're equal otherwise, return false  
	// ----------------------------------------------------------------------------------
	bool isEqual(const Node* root1, const Node* root2)const;
	//end of isEqual
};
#pragma once
