// ------------------------------------------------ graphm.h -------------------------------------------------------
// Stephen Choi CSS 343 C
// Feb 05, 2020
// Feb 15, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This project is to implement Dijkstra's shortest path algorithm. Your code should be able to read 
// a data file consisting of many lines  and display the cost and path from every node to every other node.  
// Another display routine will output one path in detail.
// --------------------------------------------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <fstream>
#include "nodedata.h"
using namespace std;

class GraphM {

public:

	// --------------------------------GraphM()---------------------------------------
	// Description
	// GraphM(): Default constructor for GraphM
	// predonditions: No preconditions 
	// postconditions: Initialize 
	// ----------------------------------------------------------------------------------
	GraphM();

	// --------------------------------buildGraph---------------------------------------
	// Description
	// buildGraph: Function to 
	// predonditions: No preconditions 
	// postconditions: 
	// ----------------------------------------------------------------------------------
	void buildGraph(ifstream& infile);

	// --------------------------------insertEdge---------------------------------------
	// Description
	// insertEdge: Function to Insert an edge into graph between two given nodes 
	// predonditions: from and to are greater or equal than 1 and less or equal than 100  
	// postconditions: assign cost to given nodes 
	// ----------------------------------------------------------------------------------
	bool insertEdge(int from, int to, int cost);
	
	// --------------------------------removeEdge---------------------------------------
	// Description
	// removeEdge: Function to Remove an edge between two given nodes
	// predonditions: from and to are greater or equal than 1 and less or equal than 100  
	// postconditions: remove cost to given nodes by setting cost to 0
	// ----------------------------------------------------------------------------------
	bool removeEdge(int from, int to);

	// --------------------------------findShortestPath---------------------------------------
	// Description
	// findShortestPath: Function to Find the shortest path between every node to every other node 
	//                   in the graph, i.e., TableType T is updated with shortest path information
	// predonditions: No Precondition  
	// postconditions: Update dist and path 
	// ----------------------------------------------------------------------------------
	void findShortestPath();

	// --------------------------------displayAll---------------------------------------
	// Description
	// displayAll: Function to demonstrate that the algorithm works properly using Cout
	// predonditions: No preconditions	
	// postconditions: cout Graph
	// ----------------------------------------------------------------------------------
	void displayAll();

	// --------------------------------displayHelper---------------------------------------
	// Description
	// displayHelper: Helper function for display and displayAll
	// predonditions: from and to are within range of 0 to 100 
	// postconditions: cout the path between two parameters
	// ----------------------------------------------------------------------------------
	void displayHelper(int from, int to);

	// --------------------------------displayHelper2---------------------------------------
	// Description
	// displayHelper: Second helper function for display and displayAll
	// predonditions: from and to are within range of 0 to 100 
	// postconditions: cout the name of the path between two parameters
	// ----------------------------------------------------------------------------------
	void displayHelper2(int from, int to);

	// --------------------------------display---------------------------------------
	// Description
	// display: Function to display the shortest distance with path info between 
	//          the fromNode to toNode using Cout
	// predonditions: from and to are within range of 0 to 100 
	// postconditions: cout the shortest distance between two parameter nodes
	// ----------------------------------------------------------------------------------
	void display(int from, int to);

private:
	// --------------------------------TableType---------------------------------------
	// Description
	// TableType: Struct to keep the current shortest distance known at any point in
	//			  the algorithm
	// ----------------------------------------------------------------------------------
	struct TableType {

		bool visited;          // whether node has been visited

		int dist;              // shortest distance from source known so far

		int path;              // previous node in path of min dist

	};

	int static const MAXNODES = 100;

	NodeData data[MAXNODES];              // data for graph nodes

	int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix

	int size;                             // number of nodes in the graph

	TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path

};