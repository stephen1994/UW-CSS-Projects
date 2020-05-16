// ---------------------------drama.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "drama.h"

//========================DramaMovie()===============================
// Description: Default contructor. Child of Movie class
// Preconditions: none
// Postconditions: assigning genre
//==================================================================== 
DramaMovie::DramaMovie() : Movie(), GENRE("DRAMA") {}
//end constructor

//========================DramaMovie()===============================
// Description: Copy contructor.
// Preconditions: none
// Postconditions: copying and assigning variables from right side into this
//==================================================================== 
DramaMovie::DramaMovie(const DramaMovie& rightSide)
{
	title = rightSide.title;
	director = rightSide.director;
	year = rightSide.year;
}
//end copy constructor

//========================~DramaMovie()===============================
// Description: Destructor
// Preconditions: none
// Postconditions: Deallocates dynamically allocated memory
//==================================================================== 
DramaMovie::~DramaMovie() {}
//end destructor

//========================display===============================
// Description: Display movies with variables
// Preconditions: none
// Postconditions: print out classic movies in certain format
//==================================================================== 
void DramaMovie::display() const
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(5) << year << endl;
}
//end display

//========================displayHeader===============================
// Description: Display header so movies can go under it
// Preconditions: none
// Postconditions: print out the header
//==================================================================== 
void DramaMovie::displayHeader() const 
{
	cout << "IN/OUT +TITLE+                *DIRECTOR*         #YEAR#  " <<
		endl;
	cout <<
		"===================================================================="
		<< endl;
}
//end displayHeader

//========================setData===============================
// Description: setting the data and checking commas
// Preconditions: readFile data not null
// Postconditions: Sets the data of a dramaMovie object to the data read in from the 
// istream.
//==================================================================== 
void DramaMovie::setData(istream& readFile) 
{
	//read the stock as string and convert to int
	string stock;

	readFile.get();
	getline(readFile, stock, ',');
	setstockSize(stoi(stock));

	readFile.get();
	getline(readFile, director, ',');

	readFile.get();
	getline(readFile, title, ',');

	//read the file and assign year
	readFile.get();
	readFile >> year;

}
//end setData

//========================setData2===============================
// Description: process transaction data setting. This istream is in a  different format
// Preconditions: readFile data not null
// Postconditions: read the file and assign the values
//==================================================================== 
void DramaMovie::setData2(istream& readFile)
{
	//director and title
	readFile.get();
	getline(readFile, director, ',');

	readFile.get();
	getline(readFile, title, ',');
}
//end setData2

//========================operator=================================
// Description: static_cast operator performs an explicit type conversion
// static_cast down to dramaMovie
// Preconditions: none
// Postconditions: return true if they are same, otherwise return false
//==================================================================== 
bool DramaMovie::operator==(const Inventory& rightSide) const
{	
	const DramaMovie& aDrama = static_cast<const DramaMovie&>(rightSide);

	return (title == aDrama.title && director == aDrama.director);
} 
//end operator==

//========================operator< =================================
// Description: static_cast operator performs an explicit type conversion
// static cast down to ComedyMovie
// Preconditions: none
// Postconditions: return true if left side less than right side,
// otherwise return false
//==================================================================== 
bool DramaMovie::operator<(const Inventory& rightSide) const 
{
	const DramaMovie& aDrama = static_cast<const DramaMovie&>(rightSide);

	if (director < aDrama.director)
	{
		return true;
	}
	else if (director == aDrama.director)
	{
		return (title < aDrama.title);
	}
	else
	{
		return false;
	}
		
}
// end operator <

//========================create=================================
// Description: create a new drama movie into the inventory
// Preconditions: none
// Postconditions: create a new drama movie into the inventory
//==================================================================== 
Inventory* DramaMovie::create()
{
	return new DramaMovie();
}
//end create