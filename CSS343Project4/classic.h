// ---------------------------classic.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef _CLASSICMOVIE_H_
#define _CLASSICMOVIE_H_
#include <string>
#include "movie.h"


//child of Movie Class
class ClassicMovie : public Movie
{
public:

	//constructor, copy constructor and desctructor
	ClassicMovie();
	ClassicMovie(const ClassicMovie& rightSide);
	~ClassicMovie();

	//vurtual methods *child class*
	//every move needs to create a transaction.	
	virtual void setData2(istream& readFile);
	virtual void displayHeader() const;
	virtual bool operator==(const Inventory& rightSide) const; //static_cast virtual
	virtual bool operator<(const Inventory& rightSide) const; //static_cast virtual
	virtual Inventory* create();

	void setData(istream& readFile);
	void display() const;

private:

	//private vars for read the and set the data
	string actorFName, actorLName;
	int month;
	const string GENRE;
};
#endif