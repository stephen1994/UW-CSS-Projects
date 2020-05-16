// ------------------------------------------------ graphl.h -------------------------------------------------------
// Stephen Choi CSS 343 C
// Feb 05, 2020
// Feb 14, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This project is to display the graph information and implement depth-first search
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <fstream>
#include "nodedata.h"
using namespace std;

class GraphL {
public:
	// --------------------------------GraphL()---------------------------------------
	// Description
	// GraphL(): Default constructor for GraphL
	// predonditions: No preconditions 
	// postconditions: Initialize 
	// ----------------------------------------------------------------------------------
	GraphL();

	// --------------------------------~GraphL()---------------------------------------
	// Description
	// ~GraphL(): Default destructor for GraphL
	// predonditions: No preconditions 
	// postconditions: 
	// ----------------------------------------------------------------------------------
	~GraphL();
	
	// --------------------------------buildGraph---------------------------------------
	// Description
	// buildGraph: Function to build up graph node information and adjacency list of 
	// edges between each node reading from a data file.
	// predonditions: infile is not NULL 
	// postconditions: Build a graph node and adjacency list
	// ----------------------------------------------------------------------------------
	void buildGraph(ifstream& infile);

	// --------------------------------displayGraph---------------------------------------
	// Description
	// displayGraph: Function to Displays each node information and edge in the graph
	// predonditions: No preconditions 
	// postconditions: 
	// ----------------------------------------------------------------------------------
	void displayGraph();

	// --------------------------------depthFirstSearch---------------------------------------
	// Description
	// depthFirstSearch: Function to Makes a depth-first search and displays each node
	// in depth-first order 
	// predonditions: No preconditions 
	// postconditions: 
	// ----------------------------------------------------------------------------------
	void depthFirstSearch();

	// --------------------------------depthFirstSearchHelper-------------------------------------- -
	// Description
	// depthFirstSearchHelper: Helper Function for depthFirstSearch
	// predonditions: i is not NULL  
	// postconditions: cout DFS 
	// ----------------------------------------------------------------------------------
	void depthFirstSearchHelper(int i);

private:

	struct EdgeNode;      // forward reference for the compiler

	struct GraphNode {    // structs used for simplicity, use classes if desired

		EdgeNode* edgeHead; // head of the list of edges

		NodeData* data;     // data information about each node

		bool visited;

	};



	struct EdgeNode {

		int adjGraphNode;  // subscript of the adjacent graph node

		EdgeNode* nextEdge;

	};

	const int static MAXNODES = 100;
	// array of GraphNodes
	GraphNode* L[100];

	int size;

	// --------------------------------insertEdge---------------------------------------
	// Description
	// insertEdge: Function to Makes a depth-first search and displays each node
	//					in depth-first order 
	// predonditions: from and to are greater or equal than 1 and less or equal than 100  
	// postconditions: Create new EdgeNode and assign value 
	// ----------------------------------------------------------------------------------
	void insertEdge(int from, int to);

	// --------------------------------deleteEdgeNode---------------------------------------
	// Description
	// deleteEdgeNode: delete linked list of EdgeNode 
	// predonditions: No preconditions 
	// postconditions: deallocate each EdgeNode
	// ----------------------------------------------------------------------------------
	void deleteEdgeNode(EdgeNode* edgeHead);

};