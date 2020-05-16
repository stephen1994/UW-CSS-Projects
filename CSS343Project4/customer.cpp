// ---------------------------customer.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "customer.h"


//========================Customer()===============================
// Description: Default contructor.
// Preconditions: none                              
// Postconditions: reserving set size of vector and assigning the variables
//==================================================================== 
Customer::Customer() : id(-1), firstName(""), lastName("")
{
	tranHistory.reserve(5);
}
//end constructor


//========================Customer() constructor ==========================
// Description: Istream setting data constructor.
// Preconditions: file is not empty and valid                             
// Postconditions: setting the data
//==================================================================== 
Customer::Customer(istream& readFile)
 {
	setData(readFile);
}
//end constructor


//========================Customer() copy constructor ==========================
// Description: copy right side to into this one(new customer)
// Preconditions: file is not empty and valid                             
// Postconditions: copying the data
//==================================================================== 
Customer::Customer(const Customer& rightSide) 
{
	id = rightSide.id;
	firstName = rightSide.firstName;
	lastName = rightSide.lastName;
}
 //end copy Constructor

//========================Customer() destructor ==========================
// Description: Destructor for the customer
// Preconditions: No precondition                             
// Postconditions: destruct the customer object
//==================================================================== 
Customer::~Customer() 
{
}
//end destructor


//========================setData==========================
// Description: setting the data to customer from reading the file
// Preconditions: file must be valid                            
// Postconditions: getting the data from file and set it to variables
//==================================================================== 
void Customer::setData(istream& readFile)
 {
	//get the id
	readFile >> id;

	if (readFile.eof())
	{
		return;
	}

	//get the lastname
	readFile.get();
	readFile >> lastName;

	//get the firstname
	readFile.get();
	readFile >> firstName;
}
//end setData

//========================display Customer History=======================
// Description: displaying customer history
// Preconditions: none                          
// Postconditions: outputs the history vector for specified customer
//==================================================================== 
void Customer::displayCustomerHistory() const 
{
	//customer id name lastname
	cout << " **** Customer: " << id << " " << lastName << ", " << firstName
		<< endl;

	int size = tranHistory.size();

	if (size > 0)
	{
		//display the transaction history
		for (int i = 0; i < size; i++)
		{
			tranHistory[i].display();
			tranHistory[i].getTitle()->display();
		}
		cout << endl;
	}
	else
	{
		//otherwise print out error message
		cout << "No Transactions for Customer" << endl;
	}
		
	cout << endl;
}
 //end displayCustomerHistory


//========================add transaction =======================
// Description: adding a transaction to the customer's history
// Preconditions: none                          
// Postconditions: adding a transaction to the customer's history
//==================================================================== 
void Customer::addTransaction(Transaction trans)
 {
	tranHistory.push_back(trans);
}
//end addTransaction


//========================display================================
// Description
// display: Function to call displayCustomerHistory
// predonditions: No preconditions 
// postconditions: Display the customer history  
// ==================================================================== 
void Customer::display() const
 {
	displayCustomerHistory();
}
//end display

//all getters in one description
//========================getters implementation ==========================
// Description: accesing the private data under control
// Preconditions: none                        
// Postconditions: return the value of customerid, firstname and lastname
//==================================================================== 
int Customer::getCustomerID() const { return id; }
string Customer::getFirstName() const { return firstName; }
string Customer::getLastName() const { return lastName; }
//end getters

//========================Comparison operator == ==========================
// Description: testing left side and right side is equal or not
// Preconditions: none                        
// Postconditions: return true if equal, false otherwise
//==================================================================== 
bool Customer::operator==(const Customer& rightSide) const 
{
	return (id == rightSide.id);
}
 //end operator==


//========================Comparison operator != ==========================
// Description: testing left side and right side is equal or not
// Preconditions: none                        
// Postconditions: return true if not equal, false otherwise
//==================================================================== 
bool Customer::operator!=(const Customer& rightSide) const
 {
	return (id != rightSide.id);
}
//end operator!=