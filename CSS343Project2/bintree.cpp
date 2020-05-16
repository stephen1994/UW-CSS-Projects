// ------------------------------------------------ bintree.cpp -------------------------------------------------------
// Stephen Choi CSS 343 C
// Jan 20, 2020
// Feb 01, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This program is to create a binary search tree class called BinTree along with some additional functions.
// --------------------------------------------------------------------------------------------------------------------

#include "bintree.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// --------------------------------operator <<---------------------------------------
// Description
// operator <<: Operator to print out the Binary Search Tree.
// preconditions: Parameters are not NULL
// postconditions: Returns NodeData of each node in the binary search tree
// ----------------------------------------------------------------------------------
void operator<<(ostream& output, const BinTree& b) {
	BinTree::Node* current = b.root;
	if (current == NULL) {
		cout << "This Binary Search Tree is Empty." << endl;
	}
	else{
		b.inorderHelper(current);
		cout << endl;
	}
}
//end of operator <<

// --------------------------------BinTree()---------------------------------------
// Description
// BinTree(): Default constructor for the binary search tree
// preconditions: No preconditions 
// postconditions: Create the root and set left, right, data to nullptr
// ----------------------------------------------------------------------------------
BinTree::BinTree() {
	root = nullptr;
}
//end of Default Constructor

// --------------------------------BinTree()---------------------------------------
// Description
// BinTree(): Copy Constructor for the binary search tree that deep copies
// preconditions: b is not NULL
// postconditions: Deep copies the b 
// ----------------------------------------------------------------------------------
BinTree::BinTree(const BinTree& b) { 
	root = nullptr;
	delete root;
	operator=(b);
}
//end of Copy Constructor

// --------------------------------~BinTree()---------------------------------------
// Description
// ~BinTree(): Destructor for the BinTree. Takes care of de-allocating all nodes 
//             in the binary search tree to the system.
// preconditions: No preconditions
// postconditions: Delete all the Nodes
// ----------------------------------------------------------------------------------
BinTree::~BinTree() {
	makeEmpty();
	root = nullptr;
}	
//end of Destructor

// --------------------------------isEmpty---------------------------------------
// Description
// isEmpty: function to tell if the BinTree empty or not 
// preconditions: No preconditions
// postconditions: Return true if it's empty or false      
// ----------------------------------------------------------------------------------
bool BinTree::isEmpty() const {
	if (root == nullptr) {
		return true;
	}
	return false;
}
//end of isEmpty

// --------------------------------emptyHelper---------------------------------------
// Description
// emptyHelper: Helper function for makeEmpty  
// preconditions: No preconditions
// postconditions: Empty the BinTree and deallocate the nodes 
// ----------------------------------------------------------------------------------
void BinTree::emptyHelper(Node*& node) {
	if (node == nullptr) {
		return;
	}
	emptyHelper(node->left);
	emptyHelper(node->right);

	delete node;
}
//end of emptyHelepr

// --------------------------------makeEmpty---------------------------------------
// Description
// : function to empty the BinTree 
// preconditions: No preconditions
// postconditions: BinTree is empty                
// ----------------------------------------------------------------------------------
void BinTree::makeEmpty() {
	emptyHelper(root);

	root = nullptr;
	free(root);
}// make the tree empty so isEmpty returns true
////end of makeEmpty

// --------------------------------assignmentHelper---------------------------------------
// Description
// : Helper function for the operator =  
// preconditions: No preconditions
// postconditions: copy b to *this   
// ----------------------------------------------------------------------------------
void BinTree::assignmentHelper(Node*& root, Node* currentB, const BinTree& b) {
	//base case
	if(currentB != nullptr){
		Node* newNode = new Node(); // create new Node
		newNode->data = new NodeData(*currentB->data); // create new NodeData for thr newNode
		root = newNode;
		root->left = nullptr;
		root->right = nullptr;
	}
	if (currentB->left != nullptr) {		
		assignmentHelper(root->left, currentB->left, b);
	}
	if (currentB->right != nullptr) {
		assignmentHelper(root->right, currentB->right, b);
	}
}
//end of assignmentHelper

// --------------------------------operator =---------------------------------------
// Description
// operator =: Assignment operator for BinTree
// preconditions: b is not NULL
// postconditions: Deep Copies the reference b to *this
// ----------------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree& b) {
	// if both of them are empty do nothing 
	if (this->root == nullptr && b.root == nullptr) {
		return *this;
	}
	// if the one that copying from is empty, just empty the one copying to
	else if (b.root->data == nullptr) {
		makeEmpty();
	}

	else if (*this == b) {
		return *this;
	}
	
	else if (b.root != nullptr) {
		// if the root is nullptr, No need to make empty 
		if (root != nullptr) {
			makeEmpty();
		}
		assignmentHelper(root, b.root, b);
		return *this;
	}
}// assign one tree to another
//end of operator=

// --------------------------------isEqual---------------------------------------
// Description
// isEqual: function to compare two BinTree from the root if they're equal
// preconditions: No preconditions
// postconditions: return true if they're equal otherwise, return false  
// ----------------------------------------------------------------------------------
bool BinTree::isEqual(const Node* root1, const Node* root2)const{
	if (root1 == NULL && root2 == NULL) {  
		return true;
	}
	else if (root1 != NULL && root2 == NULL) {
		return false;
	}
	else if (root1 == NULL && root2 != NULL) {
		return false;
	}
	else { 
		if (*root1->data == *root2->data && isEqual(root1->left, root2->left)
			&& isEqual(root1->right, root2->right)) {
			return true;
		}
		else {
			return false;
		}
	}
}
//end of isEqual

// --------------------------------operator ==---------------------------------------
// Description
// operator ==: Function to compare this and reference b.
// preconditions: b is not NULL
// postconditions: Returns true if they are same, false if not.
// ----------------------------------------------------------------------------------
bool BinTree::operator==(const BinTree& b) const {
	return isEqual(root, b.root);
}// equality operator
//end of operator==

// --------------------------------operator !=---------------------------------------
// Description
// operator !=: Function to compare this and reference b.
// preconditions: b is not NULL
// postconditions: Returns true if they are not same, false if not.
// ----------------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree& b) const {
	if (true == isEqual(root, b.root)) {
		return false;
	}
	else {
		return true; 
	}
}// inequality operator
//end of operator!=

// --------------------------------insertHelper---------------------------------------
// Description
// insertHelper: Helper function for the insert  
// preconditions: root and newData is not NULL 
// postconditions: Create a new Node with newData and insert them in the right place 
// ----------------------------------------------------------------------------------
bool BinTree::insertHelper(Node*& root, NodeData* newData) {
	if (newData == nullptr) {
		return false;
	}
	if (root == nullptr) {
		root = new Node();
		root->data = new NodeData(*newData); // create new NodeData for thr newNode
		root->left = nullptr;
		root->right = nullptr;
		return true;
	}
	//when root is not NULL 
	else if (*newData == *(root->data)) { // When they are same do nothing
		return false;
	}
	else if (*newData > *(root->data)) {
			return insertHelper(root->right, newData);
	}
	else if (*newData < *(root->data)) {
			return insertHelper(root->left, newData);
	}
}
//end of insertHelper

// --------------------------------insert---------------------------------------
// Description
// insert: function to insert new Node to the binary search tree  
// preconditions: newData is not NULL
// postconditions: insert newData in the right place in the binary search tree 
// ----------------------------------------------------------------------------------
bool BinTree::insert(NodeData* newData) {
	return insertHelper(root, newData);
}
//end of insert

// --------------------------------retrieve---------------------------------------
// Description
// retrieve: function to get the NodeData* of a given object in the tree  
// preconditions: dataR is not NULL
// postconditions: if the object is found, 
//                 dataDR will point to the actual object in the tree 
// ----------------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData& dataR, NodeData*& dataDR) const {
	return retrieveHelper(root, dataR, dataDR);
}
//end of retrieve

// --------------------------------retrieveHelper---------------------------------------
// Description
// retrieveHelper: Helper function for the retrieve  
// preconditions: No preconditions
// postconditions: if the object is found,
//                 dataDR will point to the actual object in the tree
//                 and return true. If not found, return false
// ----------------------------------------------------------------------------------
bool BinTree::retrieveHelper(Node* root, const NodeData& dataR, NodeData*& dataDR) const {
	if (root == nullptr) {
		return false;
	}
	if (*(root->data) == dataR) {
		dataDR = root->data;
		return true;
	}
	else if (*(root->data) < dataR) {
		retrieveHelper(root->right, dataR, dataDR);
	}else if (*(root->data) > dataR){
		retrieveHelper(root->left, dataR, dataDR);
	}
}
//end of retrieveHelepr

// --------------------------------getHeightHelper---------------------------------------
// Description
// getHeightHelper: Helper function for the getHeight 
// preconditions: data is not NULL
// postconditions: return bigger depth between left hand side and right hand side
// ----------------------------------------------------------------------------------
int BinTree::getHeightHelper(Node* root, NodeData& data) {
	if (root == nullptr) {
		return 0;
	}
	else {
		int lDepth = getHeightHelper(root->left, data);
		int rDepth = getHeightHelper(root->right, data);

		if (lDepth > rDepth) 
			return(lDepth + 1);
		else 
			return(rDepth + 1);
	}
}
//end of getHeightHelepr

// --------------------------------getHeightHelper2---------------------------------------
// Description
// getHeightHelper2: Second helper function for the getHeight  
// preconditions: data is not NULL
// postconditions: locate the corresponding Node that has data value   
// ----------------------------------------------------------------------------------
int BinTree::getHeightHelper2(Node* root, NodeData& data) {
	// when there's nothing or if it's not found
	if (root == nullptr) {
		return 0;
	}
	if (*(root->data) == data) {
		if (root == nullptr) {
			return 0;
		}
		else {
			int lDepth = getHeightHelper(root->left, data);
			int rDepth = getHeightHelper(root->right, data);

			if (lDepth > rDepth)
				return(lDepth + 1);
			else
				return(rDepth + 1);
		}
	}
	else if (*(root->data) < data) {
		getHeightHelper2(root->right, data);
	}
	else if (*(root->data) > data) {
		getHeightHelper2(root->left, data);
	}
}
//end of getHeightHelper2

// --------------------------------getHeight---------------------------------------
// Description
// getHeight: function to find the height of a given value in the tree.   
// preconditions: data is not NULL, the height of a node at a leaf is 1.
// postconditions: return height of Node that has NodeData of data, 
//                 if not found return 0
// ----------------------------------------------------------------------------------
int BinTree::getHeight(NodeData& data) {
	int height = getHeightHelper2(root, data);
	return height;
}
//end of getHeight

// --------------------------------bstreeToArrayHelper---------------------------------------
// Description
// bstreeToArrayHelper: Helper function for the bstreeToArray  
// preconditions: No precondition
// postconditions: fill an array of NodeData*
// ----------------------------------------------------------------------------------
void BinTree::bstreeToArrayHelper(NodeData* array[], Node* root, int index) {
	if (root == nullptr) {
		return;
	}
	bstreeToArrayHelper(array, root->left, index);
	while (array[index] != NULL) {
		index++;
	}
	array[index] = root->data;
	bstreeToArrayHelper(array, root->right, index);
}
//end of bstreeToArrayHelper

// --------------------------------bstreeToArray---------------------------------------
// Description
// bstreeToArray: Function to fill an array of NodeData* by using 
//                an inorder traversal of the tree
// preconditions: No preconditions
// postconditions: Fill an array and leaves the tree empty
// ----------------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* array[]) {
		bstreeToArrayHelper(array, root, 0);
		makeEmpty();

		delete root; 
}
//end of bstreeToArray

// --------------------------------arrayToBSTreeHelepr---------------------------------------
// Description
// arrayToBSTreeHelepr: Helper function for the arrayToBSTree  
// preconditions: No preconditions
// postconditions: builds a balanced BinTree          
// ----------------------------------------------------------------------------------
NodeData* BinTree::arrayToBSTreeHelper(NodeData* array[], int low, int high) {
	if (low > high)
		return NULL;
	int mid = (low + high) / 2;
	insert(array[mid - 1]);
	arrayToBSTreeHelper(array, low, mid - 1);
	arrayToBSTreeHelper(array, mid + 1, high);

	return root->data;
}
//end of arrayToBSTreeHelper

// --------------------------------arrayToBSTree---------------------------------------
// Description
// arrayToBSTree: Function to builds a balanced BinTree from a sorted 
//                array of NodeData* leaving the array filled with NULLs.  
// preconditions: No preconditions
// postconditions: Leaves an array empty    
// ----------------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* array[]) {
	int low = 1; 
	int high = 0;
	// Number of elements 
	while (array[high] != NULL) {
		high++;
	}
	arrayToBSTreeHelper(array, low, high);
}
//end of arrayToBSTree

//------------------------- displaySideways ---------------------------------
// Description
// Displays a binary tree as though you are viewing it from the side
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------------
void BinTree::displaySideways() const {
	sideways(root, 0);
}
//end of displaySideways

//------------------------- inorderHelper ---------------------------------
// Description
// Displays a binary tree as in inorder
// Preconditions: NONE
// Postconditions: print out binary search tree in inorder
// ----------------------------------------------------------------------------------
void BinTree::inorderHelper(Node* root) const {
	if (root == nullptr) {
		return;
	}
	inorderHelper(root->left);

	cout << *(root->data) << " ";

	inorderHelper(root->right);
}
//end of inorderHelper


//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// ----------------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);
		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}
//end of Sideways