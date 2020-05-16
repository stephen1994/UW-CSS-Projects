// ---------------------------factory.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#include "factory.h"

// --------------------------------Factory()---------------------------------------
// Description
// Factory(): Default constructor for Factory
// predonditions: No preconditions 
// postconditions: Initialize Factory 
// ----------------------------------------------------------------------------------
Factory::Factory() 
{
	initInventory();
	storeInventory[CLASSIC] = new ClassicMovie();
	storeInventory[DRAMA] = new DramaMovie();
	storeInventory[COMEDY] = new ComedyMovie();

	transactionInventory[BORROW] = new Borrow();
	transactionInventory[HISTORY] = new History();
	transactionInventory[RETURN] = new Return();

	mediaType[DRAMA] = "DVD";
}
//end constructor


// --------------------------------~Factory()---------------------------------------
// Description
// ~Factory(): Default destructor for Factory
// predonditions: No preconditions 
// postconditions: Destruct store & transaction inventory 
// ----------------------------------------------------------------------------------
Factory::~Factory() 
{
	for (int i = 0; i < MAXITEMS; i++) 
	{
		if (storeInventory[i] != NULL) 
		{
			delete storeInventory[i];
			storeInventory[i] = NULL;
		}

		if (transactionInventory[i] != NULL) 
		{
			delete transactionInventory[i];
			transactionInventory[i] = NULL;
		}
	}
} 
//end destructor

// --------------------------------createMovie---------------------------------------
// Description
// createMovie: Creates movie object to corresponding array location
// predonditions: istream is not NULL 
// postconditions: create movie object 
// ----------------------------------------------------------------------------------
Inventory* Factory::createMovie(char ch, istream& readFile) 
{
	string temp;

	int subscript = doHashing(ch);	//return the proper index for type
	if (storeInventory[subscript] == NULL)	//throw away invalid data
	{
		getline(readFile, temp, '\n');
		return NULL;
	}
	else 
	{
		return storeInventory[subscript]->create();
	}//end if
}
//end createMovie

// --------------------------------createTransaction---------------------------------------
// Description
// createTransaction: Creates transaction object to corresponding array location
// predonditions: istream is not NULL 
// postconditions: create transaction object 
// ----------------------------------------------------------------------------------
Transaction* Factory::createTransaction(char ch, istream& readFile) 
{
	string temp;

	int subscript = doHashing(ch);
	if (transactionInventory[subscript] == NULL)
	{
		getline(readFile, temp, '\n');
		return NULL;
	}
	else
		return transactionInventory[subscript]->create();
}	
//end createTransaction

// --------------------------------convertToSubscript---------------------------------------
// Description
// convertToSubscript: function to take char and call doHashing function to convert it to subscript
// predonditions: istream is not NULL 
// postconditions: create transaction object 
// ----------------------------------------------------------------------------------
int Factory::convertToSubscript(char ch) 
{
	return doHashing(ch);
}
//end convertToSubscript

// --------------------------------getMediaType---------------------------------------
// Description
// getMediaType: function to get media type from ch
// predonditions: ch is not NULL 
// postconditions: return media type 
// ----------------------------------------------------------------------------------
string Factory::getMediaType(char ch)
{
	return mediaType[doHashing(ch)];
}
//end getMediaType

// --------------------------------doHashing---------------------------------------
// Description
// doHashing: function to doHashing ch 
// predonditions: ch is capital letter and not NULL 
// postconditions: return media type 
// ----------------------------------------------------------------------------------
int Factory::doHashing(char ch) const 
{
	//hashing char using ASCII 
	if (ch < 'a')
	{
		return ch - 'A';
	}
		
	else
	{
		return 0;
	}
}
//end doHashing

// --------------------------------initInventory---------------------------------------
// Description
// initInventory: function to initialize Inventory
// predonditions: No precondition 
// postconditions: initialize inventory  
// ----------------------------------------------------------------------------------
void Factory::initInventory() 
{
	for (int i = 0; i < MAXITEMS; i++) 
	{
		storeInventory[i] = NULL;
		transactionInventory[i] = NULL;
		mediaType[i] = "";
	}
}
//end initInventory