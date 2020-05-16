// ---------------------------borrow.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "borrow.h"

//========================Borrow()===============================
// Description: Default COnstructor
// Preconditions: None
// Postconditions: Creates a borrow transaction
//==================================================================== 
Borrow::Borrow() : Transaction()
{
	transType = "Borrow";
} 
//end constructor

//========================Borrow(const Borrow& rightSide)============================
// Description: Copy Constructor
// Preconditions: none
// Postconditions: Copies the rightside into this	
//==================================================================== 
Borrow::Borrow(const Borrow& rightSide) {
	transType = rightSide.transType;
	mediaType = rightSide.mediaType;
	anItem = rightSide.anItem;
} 
//end copy constructor

//========================~Borrow()===============================
// Description: Desctructor
// Preconditions: none
// Postconditions: destroy the borrow transaction
// (Left,Root,Right)
//==================================================================== 
Borrow::~Borrow() {}
//end destructor

//========================setData===============================
// Description: This function sets the data, let it borrow and decrease the
// copies from inverntory
// Preconditions: item not null
// Postconditions: return true after set the data and decrease the copies
//==================================================================== 

bool Borrow::setData(string media, Inventory* item, Customer* aCustomer) 
{
	//as long as item not null, assign to type
	//if it is not empty then and decrease from
	//inventory -1.
	if (item != NULL) 
	{
		mediaType = media;
		anItem = item;

		if (mediaType != "")
		{
			anItem->decrease();
		}

	}
	return true;
}
//end setData

//========================display()===============================
// Description: Display the mediaType and transType	
// Preconditions: none
// Postconditions: prints the type
//==================================================================== 
void Borrow::display() const
{
	cout << mediaType << " " << transType << " ";
}
//end display

//========================create===============================
// Description: Creating new transaction under borrow	
// Preconditions: none
// Postconditions: Creating new transaction under borrow
//==================================================================== 
Transaction* Borrow::create()
{
	//every move, creates new transaction under borrow
	return new Borrow();
}
//end create