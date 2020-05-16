// ---------------------------inventory.h-------------------------------------
// Can Tosun and Stephen Choi CSS 343 C
// 03/03/2020
// 03/14/2020 - Date of Last Modification
// ----------------------------------------------------------------------------
// Purpose - This project initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt),
// and then process an arbitrary sequence of commands from a third file(data4commands.txt).
// ----------------------------------------------------------------------------

#ifndef _INVENTORY_H_
#define _INVENTORY_H_
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory {
public:
	Inventory(); //constructor
	Inventory(const Inventory&); //copy constructor

	virtual ~Inventory(); //destructor
	virtual void setData(istream&) = 0; //sets data of inventory itme
	virtual void setData2(istream&) = 0;	//addition information to set
	virtual void display() const = 0;	//display all data
	virtual void displayHeader() const = 0;
	virtual string getTitle() const = 0;	//return the inventory item

	void setMaxStock(const int);
	void increase();
	void decrease();
	int getAmountIn();		//return current stock
	int getAmountOut();		//return current stock
	void setstockSize(int n);

	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;
private:
	int stockSize;
	int maxStock;

};

#endif
