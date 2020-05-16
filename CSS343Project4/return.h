// ---------------------------return.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#ifndef _RETURN_H_
#define _RETURN_H_
#include "transaction.h"

class Customer;		//forward declaration
class Return : public Transaction {

public:
	Return();
	Return(const Return&);
	virtual ~Return(); //end destructor
	virtual bool setData(string, Inventory*, Customer*);
	virtual void display() const;
	virtual Transaction* create(); //create new return object
};

#endif
