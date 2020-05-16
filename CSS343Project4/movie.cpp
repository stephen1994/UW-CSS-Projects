// ---------------------------movie.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------


#include "movie.h"

// --------------------------------Movie()---------------------------------------
// Description
// Movie(): Default constructor for Movie
// predonditions: No preconditions 
// postconditions: Initialize Movie object  
// ----------------------------------------------------------------------------------
Movie::Movie() : Inventory(), title(""), director(""), year(0) 
{
}
//end constructor

// --------------------------------Movie()---------------------------------------
// Description
// Movie(): Copy constructor for Movie
// predonditions: No preconditions 
// postconditions: Copy the Movie object  
// ----------------------------------------------------------------------------------
Movie::Movie(const Movie& rightSide) 
{
	title = rightSide.title;
	director = rightSide.director;
	year = rightSide.year;
}
//end copy constructor

// --------------------------------~Movie()---------------------------------------
// Description
// ~Movie(): Default destructor for Movie
// predonditions: No preconditions 
// postconditions: Destruct the movie object  
// ----------------------------------------------------------------------------------
Movie::~Movie() 
{
}
//end destructor

// --------------------------------Display---------------------------------------
// Description
// Display: Function to displays the time, year, month, director, and actor 
//          of the moive object
// predonditions: No preconditions 
// postconditions: Display the movie  
// ----------------------------------------------------------------------------------
void Movie::display() const 
{
	cout << title << " " << director
		<< " "
		<< year
		<< endl;
}
//end display

// --------------------------------setData---------------------------------------
// Description
// setData: Fucntion to setting data for director, title and year for the movie
// predonditions: parameters are not NULL 
// postconditions: Sets the data of a movie object  
// ----------------------------------------------------------------------------------
void Movie::setData(istream& readFile)
{
	readFile.get();
	getline(readFile, director, ',');

	readFile.get();
	getline(readFile, title, ',');

	readFile.get();
	readFile >> year;
} 
//end setData

// --------------------------------displayHeader---------------------------------------
// Description
// displayHeader: Fucntion to display header
// predonditions: No precondition 
// postconditions: No postcondition  
// ----------------------------------------------------------------------------------
void Movie::displayHeader() const
{
	cout << " ****** MOVIE ITEM ***** "
		<< endl;
}	
//end displayHeader

// --------------------------------getTitle---------------------------------------
// Description
// getTitle: Getter function for the movie title
// predonditions: No precondition 
// postconditions: return title of the movie  
// ----------------------------------------------------------------------------------
string Movie::getTitle() const
 {
	return title;
}
//end getTitle

// --------------------------------getDirector---------------------------------------
// Description
// getDirector: Getter function for the movie director
// predonditions: No precondition 
// postconditions: return director of the movie  
// ----------------------------------------------------------------------------------
string Movie::getDirector() 
{
	return director;
} 
//end getDirector

// --------------------------------getYear---------------------------------------
// Description
// getYear: Getter function for the movie year
// predonditions: No precondition 
// postconditions: return year of the movie  
// ----------------------------------------------------------------------------------
int Movie::getYear() 
{
	return year;
}
//end getYear