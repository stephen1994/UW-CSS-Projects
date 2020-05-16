// ---------------------------comedy.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef _COMEDYMOVIE_H_
#define _COMEDYMOVIE_H_
#include "movie.h"


//child of Movie Class
class ComedyMovie : public Movie
{
public:
	//constructor, copy constructor and desctructor
	ComedyMovie();
	ComedyMovie(const ComedyMovie&);
	~ComedyMovie();

	//vurtual methods *child class*
	//every move needs to create a transaction.	
	virtual void display() const;
	virtual void displayHeader() const;
	virtual void setData(istream&);
	virtual void setData2(istream&);
	virtual bool operator==(const Inventory&) const;//static_cast virtual
	virtual bool operator<(const Inventory&) const;//static_cast virtual
	virtual Inventory* create(); 

private:
	const string GENRE;
};
#endif