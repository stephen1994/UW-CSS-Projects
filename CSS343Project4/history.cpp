// ---------------------------history.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "history.h"
#include "customer.h"

// --------------------------------History()---------------------------------------
// Description
// History(): Default constructor for History
// predonditions: No preconditions 
// postconditions: Initialize History 
// ----------------------------------------------------------------------------------
History::History() : Transaction() 
{
	transType = "History";
}
//end constructor

// --------------------------------History()---------------------------------------
// Description
// History(): Copy constructor for History
// predonditions: rightSide is not NULL 
// postconditions: Copy the History object
// ----------------------------------------------------------------------------------
History::History(const History& rightSide) 
{
	transType = rightSide.transType;
	mediaType = rightSide.mediaType;
	anItem = rightSide.anItem;
}
//end copy constructor

// --------------------------------~History()---------------------------------------
// Description
// ~History(): Default destructor for History
// predonditions: No preconditions 
// postconditions: Destruct History 
// ----------------------------------------------------------------------------------
History::~History() 
{
}
// end destructor

// --------------------------------setData---------------------------------------
// Description
// setData: Fucntion to setting data for history item
// predonditions: parameters are not NULL 
// postconditions: Sets the data of a history object  
// ----------------------------------------------------------------------------------
bool History::setData(string media, Inventory* item, Customer* aCustomer) 
{
	aCustomer->displayCustomerHistory();
	return false;
}
//end setData

// --------------------------------create---------------------------------------
// Description
// create: Fucntion to create history object
// predonditions: No precondition 
// postconditions:  Creates new history object
// ----------------------------------------------------------------------------------
Transaction* History::create() 
{
	return new History();
}
//end create