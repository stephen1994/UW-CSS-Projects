// ---------------------------store.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef _STORE_H_
#define _STORE_H_
#define MAXCUSTOMERS 10000
#define MAXINVENTORY 53
#include <fstream>
#include <vector>
#include "customer.h"
#include "factory.h"
#include "bintree.h"
using namespace std;

class Store {

public:
	Store(); // constructor
	Store(string); // constructor with name
	Store(const Store&); // copy constructor
	~Store();	//destructor

	void createCustomers(istream&);
	void createInventory(istream&);
	void processTran(istream&);
	void displayInventory() const;
	void displayCustomerBase() const;
	bool lookUpCustomer(int) const;
	string getBusinessName() const;
	Customer getCustomer(const int) const;

private:
	Customer customerList[MAXCUSTOMERS];
	BinTree inventoryList[MAXINVENTORY];
	vector<Transaction> storetranHistory;
	Factory factory;
	string name;
};

#endif