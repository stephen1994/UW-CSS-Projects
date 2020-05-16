// ---------------------------classic.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#include "classic.h"

//========================ClassicMovie()===============================
// Description: Default contructor. Child of Movie class
// Preconditions: none
// Postconditions: assigning variables to empty strings,0 and genre
//==================================================================== 
ClassicMovie::ClassicMovie() : Movie(), actorFName(""), actorLName(""),
month(0), GENRE("CLASSIC") {}
//end constructor


//========================ClassicMovie()===============================
// Description: Copy contructor.
// Preconditions: none
// Postconditions: copying and assigning variables from right side into this
//==================================================================== 
ClassicMovie::ClassicMovie(const ClassicMovie& rightSide)
{
	director = rightSide.director;
	title = rightSide.title;
	actorFName = rightSide.actorFName;
	actorLName = rightSide.actorLName;
	month = rightSide.month;
	year = rightSide.year;
}
// end copy constructor


//========================~ClassicMovie()===============================
// Description: Destructor
// Preconditions: none
// Postconditions: Deallocates dynamically allocated memory
//==================================================================== 
ClassicMovie::~ClassicMovie() {}
//end destructor


//========================setData===============================
// Description: setting the data and checking commas
// Preconditions: readFile data not null
// Postconditions: Sets the data of a classicMovie object to the data read in from the 
// istream.
//==================================================================== 
void ClassicMovie::setData(istream& readFile)
{
	//read the stock as string and convert to int
	string stock;

	readFile.get();
	getline(readFile, stock, ',');
	setstockSize(stoi(stock)); //string to integer
	readFile.get();
	getline(readFile, director, ',');

	readFile.get();
	getline(readFile, title, ',');

	//read the file and assign variables
	readFile.get();
	readFile >> actorFName >> actorLName; 
	readFile >> month >> year;
}
// end setData


//========================setData2===============================
// Description: process transaction data setting. This istream is in a  different format
// Preconditions: readFile data not null
// Postconditions: read the file and assign the values
//==================================================================== 
void ClassicMovie::setData2(istream& readFile)
{
	readFile >> month;
	readFile >> year;
	readFile >> actorFName;
	readFile >> actorLName;

}
//end setData2


//========================display===============================
// Description: Display movies with variables
// Preconditions: none
// Postconditions: print out classic movies in certain format
//==================================================================== 
void ClassicMovie::display() const
{
	//left shift
	cout << left
		<< setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(3) << month << " "
		<< setw(5) << year << " "
		<< actorFName << " " << actorLName << endl;
}
//end display

//========================displayHeader===============================
// Description: Display header so movies can go under it
// Preconditions: none
// Postconditions: print out the header
//==================================================================== 
void ClassicMovie::displayHeader() const
{
	cout << "IN/OUT +TITLE+                *DIRECTOR*         #MO##YEAR# " <<
		"*ACTOR* " << endl;
	cout <<
		"===================================================================="
		<< endl;
}
//end displayHeader


//========================operator=================================
// Description: static_cast operator performs an explicit type conversion
// Preconditions: none
// Postconditions: return true if they are same, otherwise return false
//==================================================================== 
bool ClassicMovie::operator==(const Inventory& rightSide) const
{
	//cast Inventory down to ClassicMovie
	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>(rightSide);

	return (year == aClassic.year && month == aClassic.month
		&& actorFName == aClassic.actorFName &&
		actorLName == aClassic.actorLName);
}
//end operator ==


//========================operator< =================================
// Description: static_cast operator performs an explicit type conversion
// Preconditions: none
// Postconditions: return true if left side less than right side,
// otherwise return false
//==================================================================== 
bool ClassicMovie::operator<(const Inventory& rightSide) const {
	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>(rightSide);

	if (year < aClassic.year)
		return true;

	else if (year == aClassic.year)
	{
		if (actorFName < aClassic.actorFName)
		{
			return true;
		}
		else if (actorFName == aClassic.actorFName)
		{
			return (actorLName < aClassic.actorLName);
		}
		else
		{
			return false;
		}	
	}
	else
	{
		return false;
	}
		
}
//end operator<


//========================create=================================
// Description: create a new classic movie into the inventory
// Preconditions: none
// Postconditions: create a new classic movie into the inventory
//==================================================================== 
Inventory* ClassicMovie::create()
{
	return new ClassicMovie();
}
//end create