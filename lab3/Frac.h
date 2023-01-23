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
// Sources of Logic assistance: 
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: Frac.h
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Jan 20th, 2019
// Time of Last Modification: 0900, Saturday, Jan 26th, 2019
// Description: Class Fraction declarations for fraction manipulation

#ifndef FRAC_H
#define FRAC_H

class Fraction
{

public:

	Fraction();
	~Fraction();
	Fraction( int num, int denom );
	Fraction( int num );
	void set( const int &new_num_, const int &new_denom_ );
	void printFraction();
	void printFractionAsFloat();
	int getNum();
	int getDenom();
	int gcd( int denom1, int denom2 );
	int lcm( int denom1, int denom2 );
	Fraction add( Fraction y );
	Fraction subtract( Fraction y );
	Fraction multiply( Fraction y );
	Fraction divide( Fraction y );

private:

	int numerator, denominator;

};

#endif