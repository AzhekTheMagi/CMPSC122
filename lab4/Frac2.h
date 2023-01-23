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
// File: Frac2.h
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Feb 02, 2019
// Time of Last Modification: 0900, Saturday, Feb 02, 2019
// Description: Class Fraction declarations with overloaded operators

#ifndef FRAC2_H
#define FRAC2_H

#include<iostream>

class Fraction; // Forward Declaration
std::ostream &operator<<( std::ostream &strm, const Fraction fraction1 );

class Fraction
{
public:

	Fraction();
	Fraction( int x, int y );
	~Fraction();
	const Fraction operator=(const Fraction &right);
	Fraction operator+( Fraction right );
	Fraction operator-( Fraction right );
	Fraction operator*( Fraction right );
	Fraction operator/( Fraction right );
	bool operator>( const Fraction &right );
	bool operator<( const Fraction &right );
	int calculateLCD( const int &y1, const int &y2 );
	int getNumerator() const;
	int getDenominator() const;
	int gcd( int x, int y );

private:

	int numerator;
	int denominator;
	void simplify();
};

#endif