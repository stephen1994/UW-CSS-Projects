// ------------------------------------------------ ownDriver.cpp -------------------------------------------------------
// Stephen Choi CSS 343 C
// Feb 14, 2020
// Feb 15, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This code tests the basic functionality of the classes to perform
// Dijkstra's algorihms and depth-first search for CSS 343 Lab 3.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "graphl.h"
#include "graphm.h"
using namespace std;

int main() {
	
	// part 1
	ifstream infile1("fastfood.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	//for each graph, find the shortest path from every node to all other nodes
	for (;;){
		GraphM G;
		G.buildGraph(infile1);
		if (infile1.eof())
			break;
		G.findShortestPath();
		G.displayAll();              // display shortest distance, path to cout
		G.display(3, 1);
		G.display(1, 2);
		G.display(1, 4);
		G.display(1, 10);             
		G.display(3, 4);
		G.display(8, 4);
	}
	
	// part 2 
	ifstream infile2("fastfood2.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	//for each graph, find the depth-first search ordering
	for (;;) {
		GraphL G;
		G.buildGraph(infile2);
		if (infile2.eof())
			break;
		G.displayGraph();
		G.depthFirstSearch();    // find and display depth-first ordering to cout
	}
	
	cout << endl;
	return 0;
}
