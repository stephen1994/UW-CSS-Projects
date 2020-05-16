// ------------------------------------------------ graphm.cpp -------------------------------------------------------
// Stephen Choi CSS 343 C
// Feb 05, 2020
// Feb 15, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This project is to implement Dijkstra's shortest path algorithm. Your code should be able to read 
// a data file consisting of many lines  and display the cost and path from every node to every other node.  
// Another display routine will output one path in detail.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "graphm.h"
using namespace std;

// --------------------------------GraphM()---------------------------------------
// Description
// GraphM(): Default constructor for the binary search tree
// predonditions: No preconditions 
// postconditions: Create the root and set left, right, data to nullptr
// ----------------------------------------------------------------------------------
GraphM::GraphM() {
	size = 0;
	string s = "";

	for (int i = 0; i < MAXNODES; i++) {
		data[i] = s;
		for (int j = 0; j < MAXNODES; j++){
			C[i][j] = 0;
			T[i][j].visited = false;
			T[i][j].dist = 0;
			T[i][j].path = 0;
		}
	}
}
// end of GraphM

// --------------------------------buildGraph---------------------------------------
// Description
// buildGraph: Function to build up graph node information and adjacency matrix of 
// edges between each node reading from a data file.
// predonditions: infile is not NULL 
// postconditions: Build a graph node and adjacency matrix
// ----------------------------------------------------------------------------------
void GraphM::buildGraph(ifstream& infile) {
	infile >> size;
	string line = "";	
		getline(infile, line);
		
			for (int i = 0; i < size; i++) {
				data[i].setData(infile);
			}
			while (!infile.eof()) {				
				int from, to, cost;
				infile >> from >> to >> cost;
				if (from == 0 && to == 0 && cost == 0) { 
					break; 
				}
				insertEdge(from, to , cost);
			}	
}
// end of buildGraph

// --------------------------------insertEdge---------------------------------------
// Description
// insertEdge: Function to Insert an edge into graph between two given nodes 
// predonditions: from and to are greater or equal than 1 and less or equal than 100  
// postconditions: assign cost to given nodes 
// ----------------------------------------------------------------------------------
bool GraphM::insertEdge(int from, int to, int cost) {
	return	C[from][to] = cost;
}
// end of insertEdge

// --------------------------------removeEdge---------------------------------------
// Description
// removeEdge: Function to Remove an edge between two given nodes
// predonditions: from and to are greater or equal than 1 and less or equal than 100  
// postconditions: remove cost to given nodes by setting cost to 0
// ----------------------------------------------------------------------------------
bool GraphM::removeEdge(int from, int to) {
	return C[from][to] = 0;
}
// end of removeEdge

// --------------------------------findShortestPath---------------------------------------
// Description
// findShortestPath: Function to Find the shortest path between every node to every other node 
//                   in the graph, i.e., TableType T is updated with shortest path information
// predonditions: No Precondition  
// postconditions: Update dist and path 
// ----------------------------------------------------------------------------------
void GraphM::findShortestPath() {
	// set initial distance same as cost 
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			T[i][j].dist = C[i][j];
			T[i][j].path = i;
		}
	}

	//Start at the beginning.
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			if (T[i][j].dist != 0) {
				for (int w = 1; w <= size; w++) {
					if (T[w][i].dist != 0 && ((T[w][j].dist > T[w][i].dist + T[i][j].dist) || T[w][j].dist == 0)) {
						T[w][j].dist = T[w][i].dist + T[i][j].dist;
						T[w][j].path = T[i][j].path;
					}
				}
			}
		}
	}
}
// end of findShortestPath

// --------------------------------displayAll---------------------------------------
// Description
// displayAll: Function to demonstrate that the algorithm works properly using Cout
// predonditions: No preconditions 
// postconditions: cout Graph
// ----------------------------------------------------------------------------------
void GraphM::displayAll() {
	cout << "Description" << "         " << "From node     " << "To node     " << "Dijkstra's     " << "Path" << endl;
	for (int i = 1; i <= size; i++) {
		cout << data[i-1] << endl;
		cout << endl;
		for (int j = 1; j <= size; j++) {
			if (i == j) {    // if from and to are same, do nothing 
				cout;
			}
			else {
				cout << "                      ";
				cout << "    " << i << "         " << j << "         ";
				if (T[i][j].dist == 0) { // if from to is unreachable 
					cout << "----" << endl;

				}
				else {
					cout << T[i][j].dist << "             " << i << " ";
					displayHelper(i, j);
					cout << j << endl;
				}
			}
		}

	}
}
// end of displayAll

// --------------------------------display---------------------------------------
// Description
// display: Function to display the shortest distance with path info between 
//          the fromNode to toNode using Cout
// predonditions: from and to are within range of 0 to 100 
// postconditions: cout the shortest distance between two parameter nodes
// ----------------------------------------------------------------------------------
void GraphM::display(int from, int to) {
	cout << "    " << from << "         " << to << "         ";
	if (T[from][to].dist == 0) { // if from to is unreachable 
		cout << "----" << endl;

	}else{
	cout << T[from][to].dist << "             " << from << " ";
	displayHelper(from, to);
	cout << to << endl;
	
		cout << data[from - 1] << endl;
		cout << endl; 
		displayHelper2(from, to);
		cout << data[to - 1] << endl;
		cout << endl; 
	}
}
// end of display

// --------------------------------displayHelper---------------------------------------
// Description
// displayHelper: Helper function for display and displayAll
// predonditions: from and to are within range of 0 to 100 
// postconditions: cout the path between two parameters
// ----------------------------------------------------------------------------------
void GraphM::displayHelper(int from, int to) {
	if (T[from][to].path == from){
		return;
	}
	else if (T[from][to].path == 0)
	{
		return;
	}
	else {
		int pathNumber = T[from][to].path;
		displayHelper(from, pathNumber);
		cout << pathNumber << " ";
	}
}
// end of displayHelper

// --------------------------------displayHelper2---------------------------------------
// Description
// displayHelper2: Second helper function for display and displayAll
// predonditions: from and to are within range of 0 to 100 
// postconditions: cout the name of the path between two parameters
// ----------------------------------------------------------------------------------
void GraphM::displayHelper2(int from, int to) {
	if (T[from][to].path == from)
	{
		return;
	}
	else if (T[from][to].path == 0)
	{
		return;
	}
	else {
		NodeData pathPlace = data[T[from][to].path-1];
		displayHelper2(from, T[from][to].path);
		cout << pathPlace << endl;
		cout << endl; 
	}
}
// end of displayHelepr2