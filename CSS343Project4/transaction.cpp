// ---------------------------transaction.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "transaction.h"

// --------------------------------Transaction()---------------------------------------
// Description
// Transaction(): Default constructor for Transaction
// predonditions: No preconditions 
// postconditions: Initialize each variable of Transaction object   
// ----------------------------------------------------------------------------------
Transaction::Transaction() :
	transType("Transaction"), mediaType(""), anItem(NULL)
{
}
//end constructor

// --------------------------------Transaction()---------------------------------------
// Description
// Transaction(): Copy constructor for Transaction
// predonditions: No preconditions 
// postconditions: Copy each variable of Transaction object   
// ----------------------------------------------------------------------------------
Transaction::Transaction(const Transaction& rightSide)
{
	transType = rightSide.transType;
	mediaType = rightSide.mediaType;
	anItem = rightSide.anItem;
}
//end copy constructor

// --------------------------------~Transaction()---------------------------------------
// Description
// ~Transaction(): Default destructor for Transaction
// predonditions: No preconditions 
// postconditions: Destruct the Transaction object   
// ----------------------------------------------------------------------------------
Transaction::~Transaction() 
{
}
//end destructor

// --------------------------------setData---------------------------------------
// Description
// setData: Fucntion to setting data for mediaType, anItem for the transaction
// predonditions: parameters are not NULL 
// postconditions: Sets the data of a transaction object  
// ----------------------------------------------------------------------------------
bool Transaction::setData(string media, Inventory* item,
	Customer* aCustomer) 
{
	mediaType = media;
	anItem = item;
	return true;
}	
//end setData

// --------------------------------Display---------------------------------------
// Description
// Display: Function to displays media type and transaction type 
// predonditions: No preconditions 
// postconditions: Display the transaction  
// ----------------------------------------------------------------------------------
void Transaction::display() const 
{
	cout << mediaType << " " << transType << ": ";
}
//end display

// --------------------------------Create---------------------------------------
// Description
// Create: Function to create transaction object for factory 
// predonditions: No preconditions 
// postconditions: Create new transaction object  
// ----------------------------------------------------------------------------------
Transaction* Transaction::create()
{
	return new Transaction();
}
//end create

// --------------------------------getMediaType---------------------------------------
// Description
// getMediaType: Getter function for the media type
// predonditions: No precondition 
// postconditions: return MediaType of the transaction  
// ----------------------------------------------------------------------------------
string Transaction::getMediaType() 
{
	return mediaType;
}
//end getMediaType

// --------------------------------getTransactionType---------------------------------------
// Description
// getTransactionType: Getter function for the transaction type
// predonditions: No precondition 
// postconditions: return TransactionType of the transaction  
// ----------------------------------------------------------------------------------
string Transaction::getTransactionType() 
{
	return transType;
}
//end getTransactionType

// --------------------------------getTitle---------------------------------------
// Description
// getTransactionType: Getter function for the title
// predonditions: No precondition 
// postconditions: return title of the transaction  
// ----------------------------------------------------------------------------------
Inventory* Transaction::getTitle() const 
{
	return anItem;
}
//end getTitle
