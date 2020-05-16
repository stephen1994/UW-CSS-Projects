// ---------------------------movie.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#ifndef _MOVIE_H_
#define _MOVIE_H_
#include "inventory.h"

using namespace std;

class Movie : public Inventory {

public:
	Movie();	//constructor
	Movie(const Movie& rightSide);
	~Movie();	//destructor

	virtual void display() const;
	virtual void displayHeader() const = 0;
	virtual void setData(istream& readFile);
	virtual void setData2(istream&) = 0;	//addition information to set

	virtual string getTitle() const;	//return the inventory item
	string getDirector(); //returns the director
	int getYear();		//returns the year

	//these must be overridden in order to determin sort orders
	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;

protected:
	string title;		//title of movie
	string director;	//director of movie
	int year;			//year created

};



#endif