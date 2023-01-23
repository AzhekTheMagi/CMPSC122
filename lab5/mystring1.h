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
// File: mystring1.h
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Feb 10, 2019
// Time of Last Modification: 1330, Sunday, Feb 10, 2019
// Description: Dynamically created char array for a string class.

//File: mystring1.h
// ================
// Interface file for user-defined String class.


#ifndef MYSTRING1_H
#define MYSTRING1_H
#include<iostream>
#include <cstring>  // for strlen(), etc.
using namespace std;

#define MAX_STR_LENGTH  200

class String {
public:
    String();
	String(const char *obj);    // a conversion constructor
	String(const String &str); // Copy constructor
	~String();
	
	void append(const char *obj);
	void append(const String &str);

	// Relational operators
	bool operator ==(const String &str) const;
	bool operator ==(const char *obj) const;
	bool operator !=(const String &str) const;
	bool operator !=(const char *obj) const;
	bool operator >(const String &str) const;
	bool operator >(const char *obj) const;
	bool operator <(const String &str) const;
	bool operator <(const char *obj) const;

	bool operator >=(const String &str) const;
	bool operator >=(const char *obj) const;

	String &operator =(const String &str);
	String &operator =(const char *obj);
	String operator +=(const String &str);
	String operator +=(const char *obj);

	void print(ostream &out) const;
	int length() const;


	char operator [](int i) const;  // subscript operator  

private:
	char *myArrayPtr = nullptr;
	int len;
};

ostream & operator<<(ostream &out, const String & r); // overload ostream operator "<<" - External!  


#endif /* not defined _MYSTRING_H */
