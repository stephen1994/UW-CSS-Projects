// ---------------------------transaction.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_
#include "movie.h"

class Customer;
class Transaction {
public:
	Transaction(); // constructor
	Transaction(const Transaction&); //copy constructor
	virtual ~Transaction(); // destructor

	virtual bool setData(string media, Inventory* item, Customer* aCustomer);	// setData
	virtual void display() const;// display
	virtual Transaction* create();

	string getMediaType();//get media type
	string getTransactionType();	// transaction type
	Inventory* getTitle() const;	//pointer to Inventory Item

protected:
	string transType;
	string mediaType;
	Inventory* anItem;
};
#endif
