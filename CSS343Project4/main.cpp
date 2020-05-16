// ---------------------------main.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "store.h"
using namespace std;

//testing the program
int main() {

	//creating a store
	Store movieStop("AMC DVD SHOP");

	//reading the files to right places
	ifstream readFileCustomers("data4customers.txt");
	ifstream readFileMovies("data4movies.txt");
	ifstream readFileTransactions("data4commands.txt");

	//if we cannot read the files, dispaly the error
	if ((!readFileCustomers) || (!readFileMovies) || (!readFileTransactions)) {
		cout << "File Could Not be Opened!" << endl;
		return 1;
	}

	//process the files
	movieStop.createCustomers(readFileCustomers);
	movieStop.createInventory(readFileMovies);
	movieStop.processTran(readFileTransactions);

	return 0;
}
