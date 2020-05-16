// ------------------------------------------------ graphl.cpp -------------------------------------------------------
// Stephen Choi CSS 343 C
// Feb 05, 2020
// Feb 14, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This project is to display the graph information and implement depth-first search
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "graphl.h"
using namespace std;

// --------------------------------GraphL()---------------------------------------
	// Description
	// GraphL(): Default constructor for GraphL
	// predonditions: No preconditions 
	// postconditions: Initialize 
	// ----------------------------------------------------------------------------------
GraphL::GraphL() {
	size = 0;
	for (int i = 1; i < MAXNODES; i++) {
		L[i] = new GraphNode();		 
		L[i]->visited = false;
	}
}
//end of GraphL

// --------------------------------~GraphL()---------------------------------------
// Description
// ~GraphL(): Default destructor for GraphL
// predonditions: No preconditions 
// postconditions: 
// ----------------------------------------------------------------------------------

GraphL::~GraphL() {
	for (int i = 1; i <= size; i++) {
		delete L[i]->data;
		EdgeNode* cur = L[i]->edgeHead;
		deleteEdgeNode(cur);
	}
	for (int i = 1; i < MAXNODES; i++) {	
		delete L[i];
	}
}
//end of ~GraphL

// --------------------------------deleteEdgeNode---------------------------------------
// Description
// deleteEdgeNode: delete linked list of EdgeNode 
// predonditions: No preconditions 
// postconditions: deallocate each EdgeNode
// ----------------------------------------------------------------------------------
void GraphL::deleteEdgeNode(EdgeNode* edgeHead) {
	if (edgeHead == nullptr) {
		return;
	}
	deleteEdgeNode(edgeHead->nextEdge);
	delete(edgeHead);
}
// end of deleteEdgeNode

// --------------------------------buildGraph---------------------------------------
// Description
// buildGraph: Function to build up graph node information and adjacency list of 
// edges between each node reading from a data file.
// predonditions: infile is not NULL 
// postconditions: Build a graph node and adjacency list
// ----------------------------------------------------------------------------------
void GraphL::buildGraph(ifstream& infile) {
	infile >> size; 
	string line = "";
		getline(infile, line);
			for (int i = 1; i <= size; i++) {
				getline(infile, line);
				L[i]->data = new NodeData(line);
			}
			while (!infile.eof()) {
				int from, to;
				infile >> from >> to;
					if (from == 0 && to == 0) {
						break;
					}
				insertEdge(from, to);
			}	
}
// end of buildGraph

// --------------------------------displayGraph---------------------------------------
// Description
// displayGraph: Function to Displays each node information and edge in the graph
// predonditions: No preconditions 
// postconditions: cout each edge 
// ----------------------------------------------------------------------------------
void GraphL::displayGraph() {
	cout << endl;
	cout << "Graph:" << endl;
	for (int i = 1; i <= size; i++) {
		cout << "Node " << i << "         " << *(L[i]->data) << endl;
		cout << endl; 
		if (L[i]->edgeHead != nullptr) {
			EdgeNode* cur = L[i]->edgeHead;
			while (cur != nullptr) {
				cout << "   edge " << i << "  " << cur->adjGraphNode << endl; 
				cur = cur->nextEdge;
			}
		}
	}
}
// end of displayGraph


// --------------------------------depthFirstSearch---------------------------------------
// Description
// depthFirstSearch: Function to Makes a depth-first search and displays each node
//					in depth-first order 
// predonditions: No preconditions  
// postconditions: cout DFS 
// ----------------------------------------------------------------------------------
void GraphL::depthFirstSearch() {
	cout << "Depth-fisrt ordering:";  

	for (int i = 1; i <= size; ++i) {
		if (!L[i]->visited)	{
			depthFirstSearchHelper(i);
		}
	}
	cout << endl;
}
// end of depthFirstSearch

// --------------------------------depthFirstSearchHelper---------------------------------------
// Description
// depthFirstSearchHelper: Helper Function for depthFirstSearch
// predonditions: i is not NULL  
// postconditions: cout DFS 
// ----------------------------------------------------------------------------------
void GraphL::depthFirstSearchHelper(int i) {
	cout << "  " << i;
	EdgeNode* cur = L[i]->edgeHead; 
	L[i]->visited = true;

	while (cur != nullptr) {
		if (!L[cur->adjGraphNode]->visited) {
			depthFirstSearchHelper(cur->adjGraphNode);
		}
		cur = cur->nextEdge;    
	}	
}
// end of depthFirstSearchHelper

// --------------------------------insertEdge---------------------------------------
// Description
// insertEdge: Function to Makes a depth-first search and displays each node
//					in depth-first order 
// predonditions: from and to are greater or equal than 1 and less or equal than 100  
// postconditions: Create new EdgeNode and assign value 
// ----------------------------------------------------------------------------------
void GraphL::insertEdge(int from, int to) {
	if (L[from]->edgeHead == nullptr) {
		EdgeNode* newNode = new EdgeNode();
		newNode->adjGraphNode = to;
		L[from]->edgeHead = newNode;
	}
	else {
		EdgeNode* newNode = new EdgeNode();
		newNode->adjGraphNode = to;
		newNode->nextEdge = L[from]->edgeHead;
		L[from]->edgeHead = newNode;
	}
}
// end of insertEdge