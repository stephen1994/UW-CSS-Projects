// ---------------------------comedy.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "comedy.h"


//========================ComedyMovie()===============================
// Description: Default contructor. Child of Movie class
// Preconditions: none
// Postconditions: assigning genre
//==================================================================== 
ComedyMovie::ComedyMovie() : Movie(), GENRE("COMEDY") {}
//end constructor

//========================ComedyMovie()===============================
// Description: Copy contructor.
// Preconditions: none
// Postconditions: copying and assigning variables from right side into this
//==================================================================== 
ComedyMovie::ComedyMovie(const ComedyMovie& rightSide)
{
	title = rightSide.title;
	year = rightSide.year;
	director = rightSide.director;
} 
//end copy constructor

//========================~ComedyMovie()===============================
// Description: Destructor
// Preconditions: none
// Postconditions: Deallocates dynamically allocated memory
//==================================================================== 
ComedyMovie::~ComedyMovie() {}
//end destructor

//========================display===============================
// Description: Display movies with variables
// Preconditions: none
// Postconditions: print out classic movies in certain format
//==================================================================== 
void ComedyMovie::display() const
{
	//left shift
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
void ComedyMovie::displayHeader() const 
{
	cout << "IN/OUT +TITLE+                *DIRECTOR*         #YEAR#  "
		<< endl;
	cout <<
		"===================================================================="
		<< endl;
}//end displayHeaders

//========================setData===============================
// Description: setting the data and checking commas
// Preconditions: readFile data not null
// Postconditions: Sets the data of a comedyMovie object to the data read in from the 
// istream.
//==================================================================== 
void ComedyMovie::setData(istream& readFile) 
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
// end setData

//========================setData2===============================
// Description: process transaction data setting. This istream is in a  different format
// Preconditions: readFile data not null
// Postconditions: read the file and assign the values
//==================================================================== 
void ComedyMovie::setData2(istream& readFile)
{
	//title and year
	readFile.get();
	getline(readFile, title, ',');

	readFile >> year;

}
//end setData2

//========================operator=================================
// Description: static_cast operator performs an explicit type conversion
// static_cast down to ComedyMovie
// Preconditions: none
// Postconditions: return true if they are same, otherwise return false
//==================================================================== 
bool ComedyMovie::operator==(const Inventory& movieItem) const
{
	const ComedyMovie& aComedy = static_cast<const ComedyMovie&>(movieItem);

	return (title == aComedy.title && year == aComedy.year);
}
//end operator ==

//========================operator< =================================
// Description: static_cast operator performs an explicit type conversion
// static cast down to ComedyMovie
// Preconditions: none
// Postconditions: return true if left side less than right side,
// otherwise return false
//==================================================================== 
bool ComedyMovie::operator<(const Inventory& movieItem) const 
{
	const ComedyMovie& aComedy = static_cast<const ComedyMovie&>(movieItem);

	if (title < aComedy.title)
	{
		return true;
	}
		
	else if (title == aComedy.title)
	{
		return (year < aComedy.year);
	}
	else
	{
		return false;
	}
		
}
//end operator <

//========================create=================================
// Description: create a new comedy movie into the inventory
// Preconditions: none
// Postconditions: create a new comedy movie into the inventory
//==================================================================== 
Inventory* ComedyMovie::create()
{
	return new ComedyMovie();
}
//end create