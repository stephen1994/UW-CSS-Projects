// ---------------------------comedy.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "movie.h"
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

//created from text file
class Customer
{
public:
	//constructor,constructor with istream(reading), copy constructor and desctructor
	Customer();
	Customer(istream&);
	Customer(const Customer&);
	virtual ~Customer();

	void setData(istream& readFile); //set the data
	void displayCustomerHistory() const; //display customer history
	void addTransaction(Transaction); //add transaction to specific customer
	virtual void display() const;

	//getters
	int getCustomerID() const;
	string getFirstName() const;
	string getLastName() const;

	//comparison operator overloads
	virtual bool operator==(const Customer& rightSide) const; 
	virtual bool operator!=(const Customer& rightSide) const; 

private:

	//every customer has id number, first and last name
	int id;
	string firstName;
	string lastName;
	vector<Transaction> tranHistory; //customer trasaction history.
};
#endif
