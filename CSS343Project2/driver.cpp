// ------------------------------------------------ driver.cpp -------------------------------------------------------
// Stephen Choi CSS 343 C
// Jan 20, 2020
// Feb 01, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This program is to test a binary search tree class called BinTree along with some additional functions.
// --------------------------------------------------------------------------------------------------------------------
#include "bintree.h"
#include <fstream>
#include <iostream>
using namespace std;

const int ARRAYSIZE = 100;

//global function prototypes
void buildTree(BinTree&, ifstream&);      
void initArray(NodeData*[]);             // initialize array to NULL

int main() {
	// create file object infile and open it
	// for testing, call your data file something appropriate, e.g., inputdata.txt
	ifstream infile("inputdata2.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	// the NodeData class must have a constructor that takes a string
	NodeData givenchyND("Givenchy");
	NodeData hermesND("Hermes");
	NodeData apND("AP");
	NodeData lvND("LV");
	NodeData ferrariND("Ferrari");
	NodeData cartierND("Cartier");
	NodeData mcLarenND("McLaren");

	BinTree T, T2, dup;
	NodeData* ndArray[ARRAYSIZE];
	initArray(ndArray);
	cout << "Initial data:" << endl << "  ";
	buildTree(T, infile);              // builds and displays initial data
	cout << endl;
	BinTree first(T);                  // test copy constructor
	dup = dup = T;                     // test operator=, self-assignment
	while (!infile.eof()) {
		cout << "Tree Inorder:" << endl << T;             // operator<< does endl
		T.displaySideways();

		// test retrieve 
		NodeData* p;                    // pointer of retrieved object
		bool found;                     // whether or not object was found in tree
		found = T.retrieve(hermesND, p);
		cout << "Retrieve --> Hermes:  " << (found ? "found" : "not found") << endl;
		found = T.retrieve(givenchyND, p);
		cout << "Retrieve --> Givenchy:  " << (found ? "found" : "not found") << endl;
		found = T.retrieve(apND, p);
		cout << "Retrieve --> AP:  " << (found ? "found" : "not found") << endl;

		// test getHeight 
		cout << "Height    --> Hermes:  " << T.getHeight(hermesND) << endl;
		cout << "Height    --> Givenchy:  " << T.getHeight(givenchyND) << endl;
		cout << "Height    --> AP:  " << T.getHeight(apND) << endl;
		cout << "Height    --> LV:  " << T.getHeight(lvND) << endl;
		cout << "Height    --> Ferrari:  " << T.getHeight(ferrariND) << endl;
		cout << "Height    --> McLaren:  " << T.getHeight(mcLarenND) << endl;
		cout << "Height    --> Cartier:  " << T.getHeight(cartierND) << endl;

		// test ==, and != 
		T2 = T;
		cout << "T == T2?     " << (T == T2 ? "equal" : "not equal") << endl;
		cout << "T != first?  " << (T != first ? "not equal" : "equal") << endl;
		cout << "T == dup?    " << (T == dup ? "equal" : "not equal") << endl;
		dup = T;

		// somewhat test bstreeToArray and arrayToBSTree
		T.bstreeToArray(ndArray);
		T.arrayToBSTree(ndArray);
		T.displaySideways();

		T.makeEmpty();                  // empty out the tree
		initArray(ndArray);             // empty out the array

		cout << "---------------------------------------------------------------"
			<< endl;
		cout << "Initial data:" << endl << "  ";
		buildTree(T, infile);
		cout << endl;
	}
	return 0;
}

// --------------------------------buildTree---------------------------------------
// Description
// buildTree: To build a tree, read strings from a line, terminating when "$$" is
//			  encountered. Since there is some work to do before the actual insert that is
//			  specific to the client problem, it's best that building a tree is not a 
//			  member function.
// preconditions: infile is not NULL
// postconditions: Build a tree
// ----------------------------------------------------------------------------------
void buildTree(BinTree& T, ifstream& infile) {
	string s;

	for (;;) {
		infile >> s;
		cout << s << ' ';
		if (s == "$$") break;                // at end of one line
		if (infile.eof()) break;             // no more lines of data
		NodeData* ptr = new NodeData(s);     // NodeData constructor takes string
		bool success = T.insert(ptr);
		if (!success)
			delete ptr;                       // duplicate case, not inserted 
	}
}

//------------------------------- initArray ----------------------------------
// Description
// initArray: initialize the array of NodeData* to NULL pointers
// preconditions: NONE
// postconditions: initialize empty array with size of 100
// ----------------------------------------------------------------------------------
void initArray(NodeData* ndArray[]) {
	for (int i = 0; i < ARRAYSIZE; i++)
		ndArray[i] = NULL;
}
