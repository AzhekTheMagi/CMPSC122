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
// Sources of Logic assistance: Assignment 2 instructions line 38 thru 47
// "Starting Out with C++ from Control Structures to Objects" line 88 thru 103
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: mystring.h
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2059, Sunday, Jan 20th, 2019
// Time of Last Modification: 2053, Tuesday, Jan 15th, 2019
// Description: Function declarations for testing c-strings

#ifndef MYSTRING_H
#define MYSTRING_H

// Function Prototypes
int mystrlen(const char *my_string);
int mystrcmp(const char *s1, const char *s2);
char *mystrcpy(char *s1, const char *s2);
char *mystrcat(char *s1, const char *s2);

// Function Definitions

//*********************************************************
// Counts number of characters in string. Code taken from *
// Assignment 2 instructions.                             *
//*********************************************************
int mystrlen( const char *my_string )
{
	const char *mystring_end = my_string; 

// Determines string length
	while ( *mystring_end != '\0' )
		mystring_end++;

	return ( mystring_end - my_string );
}

//***********************************************
// Returns whether character strings are equal. *
//***********************************************
int mystrcmp( const char *s1, const char *s2 )
{
	bool exit_loop = false; // Loop exit counter
	int counter = 0;        // Counter

// Determines whether either char array is filled with only ""
	if ( s1[ counter ] == 0 && s2[ counter ] != 0 )
		counter--;
	else if ( s2[ counter ] == 0 && s1[ counter ] != 0 )
		counter++;
// Determines whether char arrays are equal
	else
	{
		while ( !exit_loop && *s1 != '\0' && *s2 != '\0' )
		{
			if (  *s1 > *s2 )
		    {
			    counter++;
			    exit_loop = true;
		    }
		    else if ( *s1 < *s2 )
		    {
			    counter--;
			    exit_loop = true;
		    }
		    s1++;
		    s2++;
		}
	}

	return counter;
}

//*****************************************************
// Copies string from one character array to another. *
//*****************************************************
char *mystrcpy( char *s1, const char *s2 )
{
	int counter = 0; // Loop counter 

// Copies char array from second onto first
	while ( *( s2 + counter ) != '\0' )
	{
		*( s1 + counter ) = *(s2 + counter );
		counter++;
	}

// Places null at end
	*( s1 + counter ) = '\0';

	return s1;
}

//*************************************************
// Concatenates two char arrays with one another. *
//*************************************************
char *mystrcat( char *s1, const char *s2 )
{
	int counter = 0; // Loop Counter

// Determines size of first char array
	while ( *s1 != '\0' )
		s1++;
// Concatenates second char array to end of first
	while ( *s2 != '\0' )
	{
		*( s1 + counter ) = *( s2 + counter );
		counter++;
	}

	return s1;
}

#endif