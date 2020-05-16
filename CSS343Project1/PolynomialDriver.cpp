// ------------------------------------------------ PolynomialDriver.cpp -------------------------------------------------------
// Stephen Choi CSS 343 C
// Jan 7, 2020
// Jan 17, 2020 - Date of Last Modification
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This file is to test +, -, =, ==, !=, += and -= operators,
// and copy constructor on a doubly-linked circular list with a dummy header
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cassert>
using namespace std;

#include "polynomial.h"

int main()

{
	// ChangeCoeffcient testing
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "ChangeCoefficient Testing #1" << endl;
	Polynomial p1;

	p1.changeCoefficient(23, 4);

	p1.changeCoefficient(1, 5);

	p1.changeCoefficient(-3, 2);

	p1.changeCoefficient(-23, 6);

	p1.changeCoefficient(5, 1);

	// Expected Output: p1 = -23x^6 + x^5 + 23x^4 -3x^2 + 5x
	cout << "Expected Output: ";
	cout << "p1 = -23x^6 + x^5 + 23x^4 -3x^2 + 5x" << endl;
	cout << "Output:          ";
	cout << "p1 = " << p1 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "ChangeCoefficient Testing #2 with newCoefficient as 0 to the existing Term" << endl;
	Polynomial p32;

	p32.changeCoefficient(3, 47);

	p32.changeCoefficient(5, 49);

	p32.changeCoefficient(2, 43);

	cout << "p32 = " << p32 << " ----- Before" << endl;

	p32.changeCoefficient(0, 47);

	cout << "p32.changeCoefficient(0, 47);" << endl;

	cout << "p32 = " << p32 << "         ----- After" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;


	// Degree function test
	assert(p1.degree() == 6);
	assert(p1.degree() != 5);
	// Coefficient function test
	assert(p1.coefficient(6) == -23);
	assert(p1.coefficient(2) == -3);
	assert(p1.coefficient(5) == 1);
	assert(p1.coefficient(4) == 23);
	assert(p1.coefficient(1) == 5);

	Polynomial p2;

	p2.changeCoefficient(24, 4);

	p2.changeCoefficient(1, 5);

	p2.changeCoefficient(4, 2);

	p2.changeCoefficient(23, 6);

	p2.changeCoefficient(8, 1);

	p2.changeCoefficient(-8, 13);

	p2.changeCoefficient(5, 7);

	Polynomial p3;

	// Operator - Test
	p3 = p2 - p1;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for -" << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p1 = " << p1 << endl;
	cout << "p3 = p2 - p1" << endl;
	cout << "Expected Output: ";
	cout << "p3 = -8x^13 + 5x^7 + 46x^6 + x^4 + 7x^2 + 3x" << endl;
	cout << "Output:          ";
	cout << "p3 = " << p3 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	Polynomial p15;

	p15.changeCoefficient(2, 76);

	Polynomial p16;

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for - #2 Subtracting Empty linked list" << endl;
	cout << "p15 = " << p15 << endl;
	cout << "p16 = " << p16 << endl;
	cout << "p15 = p15 - p16" << endl;
	cout << "Expected Output: ";
	cout << "p15 = 2x^76" << endl;
	cout << "Output:          ";
	cout << "p15 = " << p15 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	Polynomial p34;
	p34 = p3 - p2;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for - #3" << endl;
	cout << "p3 = " << p3 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p34 = p3 - p2" << endl;
	cout << "Expected Output: ";
	cout << "p34 = 23x^6 -x^5 -23x^4 + 3x^2 -5x" << endl;
	cout << "Output:          ";
	cout << "p34 = " << p34 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	Polynomial p4;

	p4.changeCoefficient(-23, 6);

	p4.changeCoefficient(1, 5);

	p4.changeCoefficient(-3, 2);

	p4.changeCoefficient(23, 4);

	p4.changeCoefficient(5, 1);

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for ==" << endl;
	cout << "p1 = " << p1 << endl;
	cout << "p4 = " << p4 << endl;

	// Operator == Test
	assert(p1 == p4);
	if (p1 == p4) {
		cout << "p1 == p4 passed assert(p1 == p4) test." << endl;
	}
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	Polynomial p5;
	
	p5.changeCoefficient(-23, 6);

	p5.changeCoefficient(1, 5);

	p5.changeCoefficient(-3, 2);

	p5.changeCoefficient(23, 4);

	p5.changeCoefficient(4, 1);

	//Expected Output: p5 = -23x^6 + x^5 + 23x^4 -3x^2 + 4x
	
	//Operator != test
	assert(p1 != p2);
	assert(p1 != p5);

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for !=" << endl;
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	if (p1 != p2) {
		cout << "p1 != p2 passed assert(p1 != p2) test." << endl;
	}
	
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for != #2" << endl;
	cout << "p1 = " << p1 << endl;
	cout << "p5 = " << p5 << endl;
	
	if (p1 != p2) {
		cout << "p1 != p5 passed assert(p1 != p5) test." << endl;
	}
	
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	Polynomial p6;

	p6.changeCoefficient( 1, 1 );

	p6.changeCoefficient( 4, 4 );

    p6.changeCoefficient( 2.2, 6 );

    p6.changeCoefficient( -3.8, 3 );

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for +" << endl;
	cout << "p6 = " << p6 << endl;
	
	Polynomial p7;

	p7.changeCoefficient(1, 1);

	p7.changeCoefficient(4, 4);

	p7.changeCoefficient(4.2, 6);

	p7.changeCoefficient(-3.8, 5);

	cout << "p7 = " << p7 << endl;

	Polynomial p9 = p6 + p7;

	cout << "Expected Output: ";
	cout << "p9 = 6.6x^6 -3.8x^5 + 8x^4 -3.8x^3 + 2x" << endl;
	cout << "Output:          ";
	cout << "p9 = " << p9 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	Polynomial p35;
	p35 = p3 + p2;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for + #2" << endl;
	cout << "p3 = " << p3 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p35 = p3 + p2" << endl;
	cout << "Expected Output: ";
	cout << "p35 = -16x^13 + 10x^7 + 69x^6 + x^5 + 25x^4 + 11x^2 + 11x" << endl;
	cout << "Output:          ";
	cout << "p35 = " << p35 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for += " << endl;
	cout << "p6 = " << p6 << endl;
	cout << "p7 = " << p7 << endl;
	p6 += p7;
	cout << "p6 += p7" << endl;
	cout << "Expected Output: ";
	cout << "p6 = 6.6x^6 -3.8x^5 + 8x^4 -3.8x^3 + 2x" << endl;
	cout << "Output:          ";
	cout << "p6 = " << p6 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	// Testing for Copy Constructor
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for Copy Constructor" << endl;
	
	Polynomial p8(p1);

	cout << "p8 = " << p8 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	// Testing for -=
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for -=" << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p1 = " << p1 << endl;
	cout << "p2 -= p1" << endl;

	p2 -= p1;
	cout << "Expected Output: ";
	cout << "p2 = -8x^13 + 5x^7 + 46x^6 + x^4 + 7x^2 + 3x" << endl;
	cout << "Output:          ";
	cout << "p2 = " << p2 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	// Testing for -= #2
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Testing for -= #2" << endl;

	Polynomial p12;

	p12.changeCoefficient(2, 3);
	p12.changeCoefficient(5, 1);
	p12.changeCoefficient(6, 4);
	p12.changeCoefficient(8, 6);

	cout << "p12 = " << p12 << endl;

	Polynomial p13;

	p13.changeCoefficient(2, 9);
	p13.changeCoefficient(8, 4);
	p13.changeCoefficient(9, 3);
	p13.changeCoefficient(5, 2);
	
	cout << "p13 = " << p13 << endl;

	cout << "p13 -= p12" << endl;
	cout << "Expected Output: ";
	cout << "p13 = 2x^9 -8x^6 + 2x^4 + 7x^3 + 5x^2 -5x" << endl;
	cout << "Output:          ";
	p13 -= p12;
	cout << "p13 = " << p13 << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;

	p1.~Polynomial();
	p2.~Polynomial();
	p3.~Polynomial();
	p4.~Polynomial();
	p6.~Polynomial();
	p7.~Polynomial();
	p8.~Polynomial();
	p12.~Polynomial();
	p13.~Polynomial();
	p35.~Polynomial();
}