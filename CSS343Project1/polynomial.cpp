// ------------------------------------------------ polynomial.cpp -------------------------------------------------------
// Stephen Choi CSS 343 C
// Jan 7, 2020
// Jan 17, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This Program is to exercise dynamic memory allocation, pointer operations,
// and copy constructor design through designing a doubly-linked circular list with a 
// dummy header.
// --------------------------------------------------------------------------------------------------------------------


#include "polynomial.h"
#include <iostream>
#include <string>
using namespace std;

// --------------------------------operator <<---------------------------------------
// Description
// operator <<: Operator to print out polynomial circular doubly linked list.
// predonditions: Parameters are not NULL
// postconditions: Returns each term of Polynomial excluding dummy header
// ----------------------------------------------------------------------------------
std::ostream& operator<<(ostream& output, const Polynomial& p) {
	Polynomial::Term* current = p.head;
		
	current = current->next;
	    output << current->coeff << "x^" << current->power;
	for (int i = 0; i < p.size - 1; i++) {
		current = current->next;
		
		// ex) "x"
		if (current->coeff == 1 && current->power == 1 && current->coeff > 0) {
			output << " + " << "x";
		}// ex) "-x"
		else if (current->coeff == -1 && current->power == 1 && current->coeff < 0) {
			output << " - " << "x";
		}
		// ex) "3x"
		else if (current->power == 1 && current->coeff > 0) {
			output << " + " << current->coeff << "x";
		}// ex) "-3x"
		else if(current->power == 1 && current->coeff < 0){
			output << " " << current->coeff << "x";
		}// ex) "x^3"
		else if (current->coeff == 1 && current->power > 0) {
			output << " + " << "x^" << current->power;
		}// ex) "-x^3"
		else if (current->coeff == -1 && current->power > 0) {
			output << " -" << "x^" << current->power;
		}
		else if (current->coeff < 0) {
			output << " " << current->coeff << "x^" << current->power;
		}
		else if (current->coeff > 0) {
			output << " + " << current->coeff << "x^" << current->power;
		}
	}
	return output;
}
//end of operator <<

// --------------------------------Polynomial()---------------------------------------
// Description
// Polynomial(): Default constructor for the circular doubly linked list
// predonditions: No preconditions 
// postconditions: Initialize dummy header that's linked to itself and size as zero
// ----------------------------------------------------------------------------------
Polynomial::Polynomial() {
	size = 0;
	
	Term* temp = new Term;
	temp->coeff = 0.0;
	temp->power = 0;
	head = temp;
	head->prev = head;
	head->next = head;
}
//end of default constructor

// --------------------------------Polynomial()---------------------------------------
// Description
// Polynomial(): Copy Constructor for the circular doubly linked list that deep copies
// predonditions: p is not NULL
// postconditions: Deep copies the p 
// ----------------------------------------------------------------------------------
Polynomial::Polynomial(const Polynomial& p) {
	Term* temp = new Term;
	temp->coeff = 0.0;
	temp->power = 0;
	head = temp;
	head->prev = head;
	head->next = head;
	size = 0;
	
	Term* currentp = p.head->next;
	if (p.head->next == nullptr) {
		return;
	}
	else {
		for (int i = 0; i < p.size; i++) {
			Term* newNode = new Term;
			//assign values for newNode
			newNode->coeff = currentp->coeff;
			newNode->power = currentp->power;

			changeCoefficient(currentp->coeff, currentp->power);
		
			currentp = currentp->next;	
		}	
	}
}
//end of copy constructor

// --------------------------------~Polynomial()---------------------------------------
// Description
// ~Polynomial(): Destructor for the Polynomial.
//                Takes care of de-allocating all link nodes to the system.
// predonditions: No preconditions
// postconditions: Delete all the Terms
// ----------------------------------------------------------------------------------
Polynomial::~Polynomial()
{
	if (head != nullptr) {
		Term* current = head->next;
		Term* current2 = current;

		while (current2 != head)
		{
			current2 = current2->next;
			remove(current);
			current = current2;
		}
		delete head;
		head = nullptr;
	}
}
//end of destructor


// --------------------------------degree-----------------------------------------
// Description
// degree: function to return the degree of the polynomial 
// predonditions: No preconditions
// postconditions: Returns degree of the polynomial
// ----------------------------------------------------------------------------------
int Polynomial::degree() const {
	return head->next->power;
} 
//end of degree

// --------------------------------coefficient---------------------------------------
// Description
// coefficient: function to return coefficient to the corresponding power
// predonditions: No preconditions
// postconditions: Returns coefficient of the term that matchtes to the power
// ----------------------------------------------------------------------------------
double Polynomial::coefficient(const int power) const {
	Term* current = head->next;
	for (int i = 0; i < size; i++) {
		if (current->power == power) {
			return current->coeff;
		}
		current = current->next;
	}
	// if not found, return
	return 0;
}
//end of coefficient

// --------------------------------changeCoefficient---------------------------------------
// Description
// changeCoefficient: function to replace coefficient to corresponding power 
// predonditions: No preconditions
// postconditions: if size is zero, create new Term. Call remove function if 
//                 newCoefficient is zero. Call insert function if there's no 
//                 matching power in the Polynomial.
// ----------------------------------------------------------------------------------
bool Polynomial::changeCoefficient(const double newCoefficient, const int power) {
	Term* current = head;
	Term* current1 = head->next;
	bool found = false;
	if (size == 0) {
		
		Term* newNode = new Term;
		newNode->coeff = newCoefficient;
		newNode->power = power;
		
		head->next = newNode;
		newNode->prev = head;
		newNode->next = head;
		head->prev = newNode;
		size++;
		found = true;
		return found;
	}
	else {
		for(int i = 0; i <= size; i++) {
			if (current->power == power) {
				current->coeff = newCoefficient;
				//if newCoefficient is zero, Call remove funtion
				if (newCoefficient == 0)
				{
					remove(current);
				}

				found = true;
				return found;
			}
			current = current->next;
		}
		// current is now at dummy head

		if (found == false) {
			while (current1->power > power) {
				current1 = current1->next;
			}
			
			insert(current1, newCoefficient, power);
			found = true;
			return found;
		}
	}
}
//end of changeCoefficient

// --------------------------------operator +---------------------------------------
// Description
// operator +: Function to create new Polynomial that has plus value of *this and
//             reference.
// predonditions: p is not NULL
// postconditions: Return Polynomial that's not NULL and has + value of this and
//                 reference p.
// ----------------------------------------------------------------------------------
Polynomial Polynomial::operator+(const Polynomial& p) const {
	Polynomial temp;
	Term* current = head ->next;
	Term* currentp = p.head ->next;
	
	//copy this to temp 
	for (int i = 0; i < size; i++) {
		temp.changeCoefficient(current->coeff, current->power);
		current = current->next;
	}
	
	//after for loop, current is at the dummy head

	//copy over p to temp 
	for (int j = 0; j < p.size; j++) {
		temp.changeCoefficient(currentp->coeff, currentp->power);
		currentp = currentp->next;
	}
	
	Term* cur = head->next;
	Term* currento = p.head->next;
	//add up coefficient of two polynomial that they share same power
	for (int j = 0; j < size; j++) {
		for (int i = 0; i <= p.size; i++) {
			if (cur->power == currento->power) {
				temp.changeCoefficient(cur->coeff + currento->coeff, cur->power);
			}
			currento = currento->next;
		}
		cur = cur->next;
	}
	return temp;
}
//end of operator +

// --------------------------------operator - ---------------------------------------
// Description
// operator -: Function to create new Polynomial that has minus value of *this and
//             reference.
// predonditions: p is not NULL
// postconditions: Return Polynomial that's not NULL and has - value of this and
//                 reference p.
// ----------------------------------------------------------------------------------
Polynomial Polynomial::operator-(const Polynomial& p) const {
	Polynomial temp;
	Term* current = head->next;
	Term* currentp = p.head->next;

	//copy over (-)p to temp 
	for (int j = 0; j < p.size; j++) {
		temp.changeCoefficient(- currentp->coeff, currentp->power);
		currentp = currentp->next;
	}


	//copy this to temp 
	for (int i = 0; i < size; i++) {
		temp.changeCoefficient(current->coeff, current->power);
		current = current->next;
	}

	Term* cur = head->next;
	Term* currento = p.head->next;
	//subtract coefficient of two polynomial that they share same power
	for (int j = 0; j < size; j++) {
		for (int i = 0; i <= p.size; i++) {
			if (cur->power == currento->power) {
				temp.changeCoefficient(cur->coeff - currento->coeff, cur->power);
			}
			currento = currento->next;
		}
		cur = cur->next;
	}
	
	return temp;
}
//end of operator -

// --------------------------------operator ==---------------------------------------
// Description
// operator ==: Function to compare this and reference p.
// predonditions: p is not NULL
// postconditions: Returns true if they are same, false if not.
// ----------------------------------------------------------------------------------
bool Polynomial::operator==(const Polynomial& p) const {
	//Both currents are at the first node
	Term* current = head->next;
	Term* currentp = p.head->next;
	int checker = 0;
	
	// check if their sizes are the same
	if (size == p.size) {
		for (int i = 0; i < size; i++) {
			if (current->power == currentp->power && current->coeff == currentp->coeff) {
				current = current->next;
				currentp = currentp->next;
				checker++; //increment the checker if they are same 
			}
		}
		if (checker == size) {
			return true;
		}
	}
	return false;
}
//end of operator ==

// --------------------------------operator !=---------------------------------------
// Description
// operator !=: Function to compare this and reference p.
// predonditions: p is not NULL
// postconditions: Returns true if they are not same, false if not.
// ----------------------------------------------------------------------------------
bool Polynomial::operator!=(const Polynomial& p) const {
	//Both currents are at the first node
	Term* current = head->next;
	Term* currentp = p.head->next;
	int checker = 0;

	// check if their sizes are the same
	if (size == p.size) {
		for (int i = 0; i < size; i++) {
			if (current->power == currentp->power && current->coeff == currentp->coeff) {
				current = current->next;
				currentp = currentp->next;
				checker++; //increment the checker if they are same 
			}
		}
		if (checker == size) {
			return false;
		}
	}
	return true;
}
//end of operator !=

// --------------------------------operator =---------------------------------------
// Description
// operator =: Assignment operator for Polynomial
// predonditions: p is not NULL
// postconditions: Deep Copies the reference p to *this
// ----------------------------------------------------------------------------------
Polynomial& Polynomial::operator=(const Polynomial& p) {
	Term* currentp = p.head->next;
	
		for (int i = 0; i < p.size; i++) {
			Term* newNode = new Term;
			//assign values for newNode
			newNode->coeff = currentp->coeff;
			newNode->power = currentp->power;

			changeCoefficient(currentp->coeff, currentp->power);

			currentp = currentp->next;

			//remove(newNode);
		}
	return *this;
}
//end of operator =

// --------------------------------operator +=---------------------------------------
// Description
// operator +=: Operator to add value of p to *this 
// predonditions: p is not NULL
// postconditions: Return *this that has plus value of *this and reference p
// ----------------------------------------------------------------------------------
Polynomial& Polynomial::operator+=(const Polynomial& p) {
	Term* current = head->next;
	Term* cur = head->next;
	Term* curo = head->next;

	Term* currentp = p.head->next;
	Term* currento = p.head->next;
	

	Polynomial temp(*this);
	Term* tempCurrent = temp.head->next;

	Polynomial temp2(*this);
	Term* tempCurrent2 = temp2.head->next;
	Term* tempCurrent3 = temp2.head->next;
	

	for (int j = 0; j < p.size; j++) {
		changeCoefficient(currentp->coeff, currentp->power);
		currentp = currentp->next;
	}

	for (int j = 0; j < p.size; j++) {
		changeCoefficient(tempCurrent->coeff, tempCurrent->power);
		tempCurrent = tempCurrent->next;
	}
	
	//add up coefficient of two polynomial that they share same power
	for (int j = 0; j < size; j++) {
		for (int i = 0; i <= p.size; i++) {
			if (tempCurrent2->power == currento->power) {
				tempCurrent2->coeff += currento->coeff;
			}
			currento = currento->next;
		}
		tempCurrent2 = tempCurrent2->next;
	}

	for (int j = 0; j < size; j++) {
		for (int i = 0; i <= temp2.size; i++) {
			if (tempCurrent3->power == curo->power) {
				changeCoefficient(tempCurrent3->coeff, tempCurrent3->power);
			}
			tempCurrent3 = tempCurrent3->next;
		}
		curo = curo->next;
	}
	return *this;
}
//end of operator +=

// --------------------------------operator -=---------------------------------------
// Description
// operator -=: Operator to subtract value of p from *this
// predonditions: p is not NULL 
// postconditions: Return *this that has value that subtracted by reference p
// ----------------------------------------------------------------------------------
Polynomial& Polynomial::operator-=(const Polynomial& p) {
	Term* current = head->next;
	Term* cur = head->next;
	Term* curo = head->next;

	Term* currentp = p.head->next;
	Term* currento = p.head->next;


	Polynomial temp(*this);
	Term* tempCurrent = temp.head->next;

	Polynomial temp2(*this);
	Term* tempCurrent2 = temp2.head->next;
	Term* tempCurrent3 = temp2.head->next;


	for (int j = 0; j < p.size; j++) {
		changeCoefficient(-currentp->coeff, currentp->power);
		currentp = currentp->next;
	}

	for (int j = 0; j < p.size; j++) {
		changeCoefficient(tempCurrent->coeff, tempCurrent->power);
		tempCurrent = tempCurrent->next;
	}

	////add up coefficient of two polynomial that they share same power
	for (int j = 0; j < size; j++) {
		for (int i = 0; i <= p.size; i++) {
			if (tempCurrent2->power == currento->power) {
				tempCurrent2->coeff -= currento->coeff;
			}
			currento = currento->next;
		}
		tempCurrent2 = tempCurrent2->next;
	}

	for (int j = 0; j < size; j++) {
		for (int i = 0; i <= temp2.size; i++) {
			if (tempCurrent3->power == curo->power) {
				curo->coeff = tempCurrent3->coeff;
			}
			tempCurrent3 = tempCurrent3->next;
		}
		curo = curo->next;
	}
	return *this;
}
//end of operator -=

// --------------------------------insert---------------------------------------
// Description
// insert: Function to insert a new Term node with newCoefficient and power just before
//         the existing Term pointed by the pos pointer.
// predonditions: pos is not NULL, newCoefficient is not 0 
// postconditions: insert Term with newCoefficient, power value to right before the pos
// ----------------------------------------------------------------------------------
bool Polynomial::insert(Term* pos, const double newCoefficient, const int power) {
	Term* newNode = new Term;
	Term* prevNode = pos->prev;

	newNode->coeff = newCoefficient;
	newNode->power = power;

	// Link the newNode to prevNode and pos Node
	prevNode->next = newNode;
	pos->prev = newNode;
	newNode->next = pos;
	newNode->prev = prevNode;
	size++;

	return true;
}
//end of insert

// --------------------------------remove---------------------------------------
// Description
// remove: Function to delete the existing Term node pointed by pos pointer.
//         It will be used by destructor and operator = 
// predonditions: pos is not NULL 
// postconditions: Remove the Term pos
// ----------------------------------------------------------------------------------
bool Polynomial::remove(Term* pos) {
	Term* prevNode = pos->prev;
	Term* nextNode = pos->next;

	prevNode->next = nullptr;
	prevNode->next = nextNode;
	nextNode->prev = nullptr;
	nextNode->prev = prevNode;
	pos->next = nullptr;
	pos->prev = nullptr;
	
	delete (pos);
	pos = nullptr;
	size--;

	return true;
}
//end of remove
