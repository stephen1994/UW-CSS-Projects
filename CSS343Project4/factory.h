// ---------------------------factory.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#ifndef _FACTORY_H_
#define _FACTORY_H_
#define MAXITEMS 26
#define CLASSIC 2
#define DRAMA 3
#define COMEDY 5
#define BORROW 1
#define HISTORY 7 
#define RETURN 17
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
class Movie;
class Transaction;
using namespace std;

class Factory {
public:
	
	//Default constructor
	Factory();
	//Default destructor
	~Factory();

	Inventory* createMovie(char, istream&);
	Transaction* createTransaction(char, istream&);
	int convertToSubscript(char);
	string getMediaType(char);

private:
	Inventory* storeInventory[MAXITEMS];
	Transaction* transactionInventory[MAXITEMS];
	string mediaType[MAXITEMS];

	int doHashing(char) const;	//implemented by trans and inventory
	void initInventory();
};

#endif