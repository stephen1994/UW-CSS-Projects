// ---------------------------borrow.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef _BORROW_H_
#define _BORROW_H_
#include "transaction.h"

//child of Transaction class
class Borrow : public Transaction
{

public:

	//constructor, copy constructor and desctructor
	Borrow();
	Borrow(const Borrow&);
	~Borrow(); //end destructor

	//vurtual methods *child class*
	//every move needs to create a transaction.
	virtual bool setData(string, Inventory*, Customer*);
	virtual void display() const;
	virtual Transaction* create();

};
#endif