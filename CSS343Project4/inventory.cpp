// ---------------------------inventory.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#include "inventory.h"

// --------------------------------Inventory()---------------------------------------
// Description
// Inventory(): Default constructor for Inventory
// predonditions: No preconditions 
// postconditions: Initialize Inventory object  
// ----------------------------------------------------------------------------------
Inventory::Inventory() : stockSize(-1), maxStock(0) 
{
}
//end constructor

// --------------------------------Inventory()---------------------------------------
// Description
// Inventory(): Copy constructor for Inventory
// predonditions: rightSide is not NULL 
// postconditions: Copy the Inventory object
// ---------------------------------------------------------------------------------- 
Inventory::Inventory(const Inventory& rightSide)
{
}
//end copy constructor

// --------------------------------~Inventory()---------------------------------------
// Description
// ~Inventory(): Default destructor for Inventory
// predonditions: No preconditions 
// postconditions: Destruct Inventory 
// ----------------------------------------------------------------------------------
Inventory::~Inventory() 
{
} 
//end destructor

// --------------------------------setMaxStock---------------------------------------
// Description
// setMaxStock: Function to set the maximum copies of the inventory item
// predonditions: maxCopies is equal or greater than 0  
// postconditions: set maxCopies of inventory
// ---------------------------------------------------------------------------------- 
void Inventory::setMaxStock(const int maxCopies)
{
	maxStock = maxCopies;

	if (stockSize < 0)
		stockSize = maxCopies;
}
//end setMaxStock

// --------------------------------increase---------------------------------------
// Description
// increase: Function to increase the stock number of inventory
// predonditions: No precondition  
// postconditions: Increment stock number
// ---------------------------------------------------------------------------------- 
void Inventory::increase()
{
	if (stockSize != maxStock)
		stockSize++;
}
//end increase

// --------------------------------decrease---------------------------------------
// Description
// decrease: Function to decrease the stock number of inventory
// predonditions: No precondition  
// postconditions: decrement stock number
// ---------------------------------------------------------------------------------- 
void Inventory::decrease() 
{
	if (stockSize != 0)
		stockSize--;
}
//end decrease

// --------------------------------getAmountIn---------------------------------------
// Description
// getAmountIn: Getter Function for the stock number
// predonditions: No precondition  
// postconditions: Return current stock number of the Inventory
// ---------------------------------------------------------------------------------- 
int Inventory::getAmountIn()
{
	return stockSize;
}
//end getAmountIn

// --------------------------------getAmountOut---------------------------------------
// Description
// getAmountOut: Getter Function for the borrowed number
// predonditions: No precondition  
// postconditions: Return current number of the Inventory that is borrowed 
// ---------------------------------------------------------------------------------- 
int Inventory::getAmountOut() 
{
	return maxStock - stockSize;
}
//end getAmountOut

// --------------------------------setstockSize---------------------------------------
// Description
// setstockSize: Setter Function for the stock number
// predonditions: n is eqaul or greater than 0   
// postconditions: set stockSize
// ---------------------------------------------------------------------------------- 
void Inventory::setstockSize(int n)
{
	stockSize = n;
}
//end setStcokNumber
