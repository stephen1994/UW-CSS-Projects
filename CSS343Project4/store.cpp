// ---------------------------store.cpp-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#include "store.h"

// --------------------------------Store()---------------------------------------
// Description
// Store(): Default constructor for Store
// predonditions: No preconditions 
// postconditions: Initialize Store object  
// ----------------------------------------------------------------------------------
Store::Store() : name("")
{
}
//end constructor

// --------------------------------Store()---------------------------------------
// Description
// Store(): Constructor assigning store name
// predonditions: No preconditions 
// postconditions: Initialize Store object and assigns name  
// ----------------------------------------------------------------------------------
Store::Store(string aName) : name(aName) 
{
}
//end constructor

// --------------------------------Store()---------------------------------------
// Description
// Store(): Copy constructor for Store
// predonditions: No preconditions 
// postconditions: Copy the Store object  
// ----------------------------------------------------------------------------------
Store::Store(const Store& rightSide) 
{
}
//end copy constructor

// --------------------------------~Store()---------------------------------------
// Description
// ~Store(): Default destructor for Movie
// predonditions: No preconditions 
// postconditions: Destruct the movie object  
// ----------------------------------------------------------------------------------
Store::~Store() 
{
}
//end destructor

// --------------------------------createCustomers---------------------------------------
// Description
// createCustomers: Function to create new customer object and set data from istream 
//                  and stores in customer list
// predonditions: istream is not NULL 
// postconditions: Craete customer and stores   
// ----------------------------------------------------------------------------------
void Store::createCustomers(istream& readFile) 
{	
	for (;;) 
	{
		Customer* cust = new Customer();
		cust->setData(readFile);

		if (readFile.eof()) 
		{
			delete cust;
			cust = NULL;
			break;
		}
		customerList[cust->getCustomerID()] = *cust;
		delete cust;
		cust = NULL;
	}
}
//end createCustomers

// --------------------------------createInventory---------------------------------------
// Description
// createInventory: Function to create new inventory object and set data from istream 
//                  and stores in inventory list
// predonditions: istream is not NULL 
// postconditions: Craete inventory and stores   
// ----------------------------------------------------------------------------------
void Store::createInventory(istream& readFile) 
{
	char ch = ' ';
	for (;;) 
	{
		readFile >> ch;
		if (readFile.eof()) break;
		Inventory* addedMovie = factory.createMovie(ch, readFile);
		if (addedMovie != NULL) 
		{
			addedMovie->setData(readFile);
			bool inserted = inventoryList[factory.convertToSubscript(ch)]
				.insert(addedMovie, 10);
			if (!inserted) {
				delete addedMovie;
				cout << "Not Inserted" << endl;
			}
		}
		addedMovie = NULL;
		delete addedMovie;
	}
}
//end createInventory

// --------------------------------processTran---------------------------------------
// Description
// processTran: Function to process transactions from istream as well as updating
//              customer history and inventory at the same time 
// predonditions: istream is not NULL 
// postconditions: Process transaction and update corresponding history and inventory     
// ----------------------------------------------------------------------------------
void Store::processTran(istream& readFile) 
{
	char actCh = ' ';
	char movCh = ' ';
	char medCh = ' ';
	int custID = 0;
	bool found = false;
	string mediaType = "";
	char EOL = '\n';
	Inventory* itemLoc = NULL;
	Customer* tempCust = NULL;
	Inventory* tempItem = NULL;

	for (;;) 
	{
		//read the acct char 
		readFile >> actCh;
		if (readFile.eof())
		{
			break;
		}

		//if we hit I, display Inventory
		if (actCh == 'I') 
		{
			displayInventory();
			actCh = ' ';
		}

		//else, reset the char.
		else if (readFile.get() == EOL)
		{
			actCh = ' ';
		}
			
		else 
		{
			Transaction* processedTran = factory.createTransaction(actCh, readFile);

			//as long as processing not null
			if (processedTran != NULL)
			{
				//read the customer id
				readFile >> custID;

				//when you hit the end, break the loop
				if (readFile.eof())
				{
					break;
				}

				//look up customer id
				if (lookUpCustomer(custID)) 
				{ 

					tempCust = &customerList[custID];

					bool isHistory = processedTran->
						setData(mediaType, itemLoc, tempCust);

					if (readFile.get() != EOL && isHistory)
					{
						//read the media type as char
						readFile >> medCh;
						//get the type and assign it
						mediaType = factory.getMediaType(medCh);

						 //if its not empty
						if (mediaType != "") { 

							//continue to reading
							readFile >> movCh;


							tempItem = factory.createMovie(movCh, readFile);

							//if not null
							if (tempItem != NULL)
							{
								tempItem->setData2(readFile);

								found = inventoryList[factory.
									convertToSubscript(movCh)].
									retrieve(*tempItem, itemLoc);

								//if you cannot find it, show error message
								if (found == false)	
								{
									cout << "ERROR: Invalid Movie Request!"
										<< tempItem->getTitle() << endl;
								}
								//and deallocate
								delete tempItem;
								tempItem = NULL;

								bool found2 = processedTran->
									setData(mediaType, itemLoc, tempCust);

								//if both found, then add to the trasaction
								//for spesific customer
								if ((found && found2) && mediaType != "")
								{
									customerList[custID]
										.addTransaction(*processedTran);

								}

								delete processedTran;
								processedTran = NULL;
							}

							//if null
							//show error message
							else {
								cout << "ERROR: " << movCh
									<< " not Found!" << endl;

								if (processedTran != NULL)
									delete processedTran;
								processedTran = NULL;
							}

							delete tempItem;
							tempItem = NULL;

						}
						else 
						{
							string temp;
							getline(readFile, temp, EOL);

							//if invalid , show error message
							cout << "ERROR: Invalid Code " << medCh << endl;

							if (processedTran != NULL)
								delete processedTran;
							processedTran = NULL;
						}
					}
					else 
					{
						if (processedTran != NULL)
							delete processedTran;
						processedTran = NULL;
					}
				}
				else 
				{
					//if you cannot find it, show error message
					cout << "Error: Invalid Customer ID " << custID << endl;

					if (processedTran != NULL)
						delete processedTran;
					processedTran = NULL;

					string temp;
					getline(readFile, temp, EOL);
				}
			}
			else 
			{
				//if invalid, show error message
				cout << "ERROR: Invalid Action Code " << actCh << endl;

				if (processedTran != NULL)
					delete processedTran;
				processedTran = NULL;
			}
		}

		//assign values to null, false and 0
		found = false;
		custID = 0;
		itemLoc = NULL;
		tempCust = NULL;
		tempItem = NULL;
	}
}
//end processTransaction

// --------------------------------displayInventory---------------------------------------
// Description
// displayInventory: Function to displays all Inventory items as well as their history 
// predonditions: No preconditions 
// postconditions: Display the all the inventory history  
// ----------------------------------------------------------------------------------
void Store::displayInventory() const 
{
	if (name != "")
	{
		cout
			<< "--------------------------------------------------------------"
			<< endl;
		cout << "Inventory for " << name << endl;
		cout
			<< "--------------------------------------------------------------"
			<< endl;
	}

	for (int i = 0; i < MAXINVENTORY; i++) 
	{
		if (!inventoryList[i].isEmpty()) 
		{
			inventoryList[i].inorderDisplay(inventoryList[i].getRoot());
			cout << endl;
		}
	}
}
//end displayInventory

// --------------------------------displayCustomerBase---------------------------------------
// Description
// displayInventory: Function to display the customer base stored in the store object 
// predonditions: No preconditions 
// postconditions: Display the customer base  
// ----------------------------------------------------------------------------------
void Store::displayCustomerBase() const 
{
	for (int i = 0; i < MAXCUSTOMERS; i++) 
	{
		if (lookUpCustomer(i)) 
		{
			getCustomer(i).display();
		}
	}
}
//end displayCustomerBase

// --------------------------------lookUpCustomer---------------------------------------
// Description
// lookUpCustomer: Function to locate the customer by IDNumber 
// predonditions: Valid IDNumber 
// postconditions: Locate customer  
// ----------------------------------------------------------------------------------
bool Store::lookUpCustomer(int IDNumber) const 
{
	if (customerList[IDNumber].getCustomerID() == -1) 
	{
		return false;
	}
	else
		return true;
} //end lookupcustomer

// --------------------------------getBusinessName---------------------------------------
// Description
// getBusinessName: Getter Function for the name of the Business 
// predonditions: No precondition 
// postconditions: Return business name  
// ----------------------------------------------------------------------------------
string Store::getBusinessName() const 
{
	return name;
}
//end getBusinessName

// --------------------------------getCustomer---------------------------------------
// Description
// getCustomer: Getter Function for the Customer 
// predonditions: Valid IDNumber 
// postconditions: Return corresponding customer object  
// ----------------------------------------------------------------------------------
Customer Store::getCustomer(const int IDNumber) const
{
	return customerList[IDNumber];
}
//end getCustomer