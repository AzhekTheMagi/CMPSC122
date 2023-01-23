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
// Sources of Logic or code assistance: wiki entry for "Euclidian Algorithm
// Lines 61 through 76
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: Frac.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2059, Sunday, Jan 20th, 2019
// Time of Last Modification: 1000, Saturday, Jan 26th, 2019
// Description: Class implementations for Fraction class

#include "Frac.h"
#include <iostream>

// Definition of default construtor. Initializes numerator and denominator
// with default values.
Fraction::Fraction() : numerator(1), denominator(1) { }

// Destructor for Fraction class.
Fraction::~Fraction() { }

// Definition of explicit-value constructor.
Fraction::Fraction( int num, int denom )
{
	numerator = num;   // Assigns numerator
	denominator = denom; // Assigns denominator
}

// Definition of explicit-value constructor with only numerator 
Fraction::Fraction( int num )
{
	numerator = num; // Assigns numerator
	denominator = 1; // Assigns '1' to denominator
}

// Sets numerator and denominator values
void Fraction::set( const int &new_num_, const int &new_denom_ )
{
	numerator = new_num_;     // Assigns numerator
	denominator = new_denom_; // Assigns denominator
}

// Get Numerator
int Fraction::getNum() { return ( numerator ); }

// Get Denominator
int Fraction::getDenom() { return ( denominator ); }

// Finds greatest common denominator between two fractions.
// Code adapted from "https://en.wikipedia.org/wiki/Euclidean_algorithm"
int Fraction::gcd( int denom1, int denom2 )
{
	if ( denom1 == 0 )
		return denom2;
    return gcd(( denom2 % denom1 ), denom1 );
}

// Finds lowest common multiple between two fractions.
// Code adapted from "https://en.wikipedia.org/wiki/Euclidean_algorithm"
int Fraction::lcm( int denom1, int denom2 )
{
	int lowest_multiple; // Holds lowest multiple

	lowest_multiple = ( denom1 * denom2 ) / gcd( denom1, denom2 );
	return lowest_multiple;
}

// Adds fractions together
Fraction Fraction::add( Fraction y )
{
	Fraction temp;  // Temporarily holds value of instance
	int numerator1; // Holds numerator multiplied by new lcd
	int numerator2; // Holds numerator multiplied by new lcd
	int new_num;    // Holds calculated numerator
	int lcd;        // Holds lowest common denominator
	int gcd_;       // Holds greatest common divisor

// Initial numerator values
	numerator1 = numerator;
	numerator2 = y.getNum();
// Calculates new lowest common denominator and equivalent numerator
	lcd = lcm( denominator, y.getDenom() );
	numerator1 *= ( lcd / denominator );
	numerator2 *= ( lcd / y.getDenom() );
// Calculates sum of fractions
	new_num = numerator1 + numerator2;
// Simplifies Fractions
	gcd_ = gcd( new_num, lcd );
	new_num /= gcd_;
	lcd /= gcd_;
// Assigns new fraction to a temporary instance so that instance values
// can then be passed to program object.
	temp.set( new_num, lcd );
	return ( temp );
}

// Subtracts fractions together
Fraction Fraction::subtract( Fraction y )
{
	Fraction temp;  // Temporarily holds value of instance
	int numerator1; // Holds numerator multiplied by new lcd
	int numerator2; // Holds numerator multiplied by new lcd
	int new_num;    // Holds calculated numerator
	int lcd;        // Holds lowest common denominator
	int gcd_;       // Holds greatest common divisor

// Initial numerator values
	numerator1 = numerator;
	numerator2 = y.getNum();
// Calculates new lowest common denominator and equivalent numerator
	lcd = lcm(denominator, y.getDenom() );
	numerator1 *= ( lcd / denominator );
	numerator2 *= ( lcd / y.getDenom() );
// Calculates sum of fractions
	new_num = numerator1 - numerator2;
// Simplifies Fractions
	gcd_ = gcd( new_num, lcd );
	new_num /= gcd_;
	lcd /= gcd_;

// Assigns new fraction to a temporary instance so that instance values
// can then be passed to variable.
	temp.set( new_num, lcd );
	return ( temp );
}

// Multiplies two fractions
Fraction Fraction::multiply( Fraction y )
{
	Fraction temp; // Temp holds value of instance
	int new_num;   // Holds newly calculated numerator
	int new_denom; // Holds newly calculated denominator
	int gcd_;      // Holds greatest common divisor

// Calculates multiplication of two fractions
	new_num = numerator * y.getNum();
	new_denom = denominator * y.getDenom();
// Simplifies Fractions
	gcd_ = gcd( new_num, new_denom );
	new_num /= gcd_;
	new_denom /= gcd_;
// Assigns new fraction to a temporary instance so that instance values
// can be passed to variable
    temp.set( new_num, new_denom );
	return ( temp );
}

// Divides two fractions
Fraction Fraction::divide( Fraction y )
{
	Fraction temp; // Temp holds value of instance
	int new_num;   // Holds newly calculated numerator
	int new_denom; // Holds newly calculated denominator
	int gcd_;      // Holds greatest common divisor

	if (( denominator == 0 ) || ( y.getDenom() == 0 ))
		std::cout << "Error denominator contains " << std::endl;
	else
	{
		new_num = numerator * y.getDenom();
		new_denom = denominator * y.getNum();
	}
// Simplifies Fractions
	gcd_ = gcd(new_num, new_denom);
	new_num /= gcd_;
	new_denom /= gcd_;
// Assigns new fraction to a temporary instance so that instance values
// can be passed to variable
	temp.set( new_num, new_denom );
	return ( temp );
}

// Prints fraction
void Fraction::printFraction()
{
	std::cout << numerator << "/" << denominator;
}

// Prints floating double of fraction
void Fraction::printFractionAsFloat()
{
	std::cout << ( numerator / static_cast< double >( denominator ));
}