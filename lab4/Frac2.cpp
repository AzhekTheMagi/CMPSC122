/********************************************************************\
* Academic Integrity Affidavit:                                      *
* I certify that, this program code is my work.  Others may have     *
* assisted me with planning and concepts, but the code was written,  *
* solely, by me.                                                     *
* I understand that submitting code which is totally or partially    *
* the product of other individuals is a violation of the Academic    *
* Integrity Policy and accepted ethical precepts. Falsified          *
* execution results are also results of improper activities. Such    *
* violations may result in zero credit for the assignment, reduced   *
* credit for the assignment, or course failure.                      *
\********************************************************************/
// Sources of Logic assistance: "C++ From Control Structures through
// Objects" Chp.14 Operator Overloading Templates
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: Frac2.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Feb 02, 2019
// Time of Last Modification: 0900, Saturday, Feb 02, 2019
// Description: Class Fraction declarations with overloaded operators

#include "Frac2.h"
#include <iostream>

//***********************
// Default Constructor. *
//***********************
Fraction::Fraction() : numerator(1), denominator(1) { }

//******************************
// Explicit Value Constructor. *
//******************************
Fraction::Fraction( int x, int y )
{
	numerator = x;
	denominator = y;
	simplify();
}

//**********************
// Default Destructor. *
//**********************
Fraction::~Fraction() { }

//*************************************
// Overloaded '+' operator for class. *
//*************************************
Fraction Fraction::operator+( Fraction right )
{
	Fraction sum;                          // Holds added fraction.
	int numerator1 = this->numerator;      // Holds numerator for 1st fraction.
	int numerator2 = right.getNumerator(); // Holds numerator for 2nd fraction.

// Calculates a common denominator for each fraction.
	sum.denominator = calculateLCD( this->denominator, right.getDenominator());
// Calculates new numerator value based on common divisor for both fractions.
	numerator1 *= ( sum.getDenominator() / this->denominator );
	numerator2 *= ( sum.getDenominator() / right.getDenominator() );
// Adds numerators & simplifies fraction if needed.
	sum.numerator = numerator1 + numerator2;
	sum.simplify();
	return sum;
}

//*************************************
// Overloaded '-' operator for class. *
//*************************************
Fraction Fraction::operator-( Fraction right )
{
	Fraction subtraction;                  // Holds subtracted fraction.
	int numerator1 = this->numerator;      // Holds numerator for 1st fraction.
	int numerator2 = right.getNumerator(); // Holds numerator for 2nd fraction.

// Calculates a common denominator for each fraction.
	subtraction.denominator = calculateLCD(this->denominator, right.getDenominator());
// Calculates new numerator values based on comon divisor for both fractions.
	numerator1 *= (subtraction.getDenominator() / this->denominator);
	numerator2 *= (subtraction.getDenominator() / right.getDenominator());
// Subtracts numerators & simplifies fraction if needed.
	subtraction.numerator = numerator1 - numerator2;
	subtraction.simplify();
	return subtraction;
}

//*************************************
// Overloaded '=' operator for class. *
//*************************************
const Fraction Fraction::operator=( const Fraction &right )
{
	numerator = right.getNumerator();
	denominator = right.getDenominator();

// Returns the value of the dereferenced pointer 'this'.
	return *this;
}

//*************************************
// Overloaded '*' operator for class. *
//*************************************
Fraction Fraction::operator*( Fraction right )
{
	Fraction multiplication; // Holds multiplied fraction.

// Multiplies both fractions with each other.
	multiplication.numerator = this->numerator * right.getNumerator();
	multiplication.denominator = this->denominator * right.getDenominator();

// Simplifies multiplied fraction if needed. 
	multiplication.simplify();
	return multiplication;
}

//*************************************
// Overloaded '/' operator for class. *
//*************************************
Fraction Fraction::operator/(Fraction right)
{
	Fraction division; // Holds divided fraction.

// Divides both fractions with each other.
	division.numerator = this->numerator / right.getNumerator();
	division.denominator = this->denominator / right.getDenominator();

// Simplifies divided fraction if needed. 
	division.simplify();
	return division;
}

//**************************************
// Overloaded "<<" operator for class. *
//**************************************
std::ostream &operator<<( std::ostream &strm, const Fraction fraction1 )
{
// Fractions with '1' in denominator will display only numerator.
	if ( fraction1.getDenominator() == 1 )
		strm << fraction1.getNumerator();
	else
		strm << fraction1.getNumerator() << "/" << fraction1.getDenominator();
	return strm;
}

//*************************************
// Overloaded '>' operator for class. *
//*************************************
bool Fraction::operator>( const Fraction &right )
{
	bool status;    // Flag.
	int numerator1; // Holds left side numerator.
	int numerator2; // Holds right side numerator.
	int lcd;        // Holds lowest common divisor.

// Calculates lowest common divisor.
	lcd = calculateLCD( this->denominator, right.getDenominator() );
// Assigns left side fraction to numerator1 & right side 
// fraction to numerator2.
	numerator1 = this->numerator;
	numerator2 = right.getNumerator();
// Calculates numerators based on new common divisor.
	numerator1 *= ( lcd / this->denominator );
	numerator2 *= ( lcd / right.denominator );
// Evaluates to true if left side fraction larger than
// rightside fraction.
	if ( numerator1 > numerator2 )
		status = true;
	else
		status = false;
	return status;
}

//*************************************
// Overloaded '<' operator for class. *
//*************************************
bool Fraction::operator<(const Fraction &right)
{
	bool status;    // Flag.
	int numerator1; // Holds left side numerator.
	int numerator2; // Holds right side numerator.
	int lcd;        // Holds lowest common divisor.

// Calculates lowest common divisor
	lcd = calculateLCD( this->denominator, right.getDenominator() );
// Assigns left side fraction to numerator1 & right side 
// fraction to numerator2.
	numerator1 = this->numerator;
	numerator2 = right.getNumerator();
// Calculates numerators based on new common divisor
	numerator1 *= ( lcd / this->denominator );
	numerator2 *= ( lcd / right.denominator );
// Evaluates to true if left side fraction smaller than
// right fraction.
	if ( numerator1 < numerator2 )
		status = true;
	else
		status = false;
	return status;
}

//**************************************************************
// Calculates lowest common denominator between two fractions. *
//**************************************************************
int Fraction::calculateLCD( const int &y1, const int &y2 )
{
	int lcd;               // Lowest Common divisor.
	int denominator1 = y1; // Holds left side fraction denominator.
	int denominator2 = y2; // Holds right side fraction denominator.

// Calculates lowest common denominator.
	lcd = (denominator1 * denominator2) / gcd(denominator1, denominator2);
	return lcd;
}

//************************
// Gets Numerator value. *
//************************
int Fraction::getNumerator() const
{
	return numerator;
}

//**************************
// Gets Denominator value. *
//**************************
int Fraction::getDenominator() const
{
	return denominator;
}

//************************************************************************
// Findest lowest common multiple between two fractions.                 *
// Code adapted from "https://en.wikipedia.org/wiki/Euclidean_algorithm" *
//************************************************************************
int Fraction::gcd( int x, int y )
{
	if ( x == 0 )
		return y;
	return gcd(( y % x ), x );
}

//************************
// Simplifies fractions. *
//************************
void Fraction::simplify()
{
	int original_numerator = numerator;

	numerator /= gcd( numerator, denominator );
	denominator /= gcd( original_numerator, denominator );
}