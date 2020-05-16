// ---------------------------history.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#ifndef _HISTORY_H_
#define _HISTORY_H_
#include "transaction.h"

class Customer;
class History : public Transaction {
public:
	History(); //constructor 
	History(const History& rightSide); //copy constructor 
	~History(); //destructor

	virtual bool setData(string, Inventory*, Customer*);
	virtual Transaction* create();

};


#endif