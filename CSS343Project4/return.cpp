// ---------------------------return.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "return.h"

// --------------------------------Return()---------------------------------------
// Description
// Return(): Default constructor for Return
// predonditions: No preconditions 
// postconditions: Initialize Return object  
// ----------------------------------------------------------------------------------
Return::Return() : Transaction()
{
	transType = "Return";
}
//end constructor

// --------------------------------Return()---------------------------------------
// Description
// Return(): Copy constructor for Return
// predonditions: No preconditions 
// postconditions: Copy the Return object  
// ----------------------------------------------------------------------------------
Return::Return(const Return& rightSide)
{
	mediaType = rightSide.mediaType;
	transType = rightSide.transType;
	anItem = rightSide.anItem;
}
//end copy constructor

// --------------------------------~Return()---------------------------------------
// Description
// ~Return(): Default destructor for Return
// predonditions: No preconditions 
// postconditions: Destruct Return object  
// ----------------------------------------------------------------------------------
Return::~Return() 
{
}
//end destructor


// --------------------------------setData---------------------------------------
// Description
// setData: Fucntion to setting data for Return object
// predonditions: parameters are not NULL 
// postconditions: Sets the data of a return object  
// ----------------------------------------------------------------------------------
bool Return::setData(string media, Inventory* item, Customer* aCustomer) 
{
	if (item != NULL) 
	{
		mediaType = media;
		anItem = item;

		if (mediaType != "")
			anItem->increase();
	}
	return true;
}
//end setData

// --------------------------------Display---------------------------------------
// Description
// Display: Function to displays the mediaType and transType of the movie object
// predonditions: No preconditions 
// postconditions: Display the mediaType and transType  
// ----------------------------------------------------------------------------------
void Return::display() const 
{
	cout << mediaType << " " << transType << " ";
}
//end display

// --------------------------------Create---------------------------------------
// Description
// Create: Function to create return object for factory 
// predonditions: No preconditions 
// postconditions: Create new return object  
// ----------------------------------------------------------------------------------
Transaction* Return::create() 
{
	return new Return();
}
//create new return object