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

#include "mystring1.h"
#pragma warning(disable:4996)

//************************************
// Empty/Default string constructor. *
//************************************
String::String()
{
	len = 0;
	myArrayPtr = new char[0];
	myArrayPtr[0] = '\0';
}

//**********************
// String constructor. *
//**********************
String::String(const char *obj)
{
	len = strlen(obj) + 1;
	myArrayPtr = new char[len];
	for (int i = 0; i < len; i++)
		myArrayPtr[i] = obj[i];
}

//********************
// Copy constructor. *
//********************
String::String(const String &str)
{
	len = str.length();
	myArrayPtr = new char[len];
	for (int i = 0; i < len; i++)
		myArrayPtr[i] = str.myArrayPtr[i];
}

//**********************
// Default destructor. *
//**********************
String::~String()
{
	delete[] myArrayPtr;
}


//*******************************************
// Appends an array of char or String Class *
// char array to String.                    *
//*******************************************
void String::append(const char *obj)
{
	len += (strlen(obj));
	strcat(myArrayPtr, obj);
}

void String::append(const String &str)
{
	len += str.length();
	strcat(myArrayPtr, str.myArrayPtr);
}


//**********************************************
// Overloaded '==' operator for string class & *
// char array.                                 *
//**********************************************
bool String::operator ==(const char *obj) const
{
	return strcmp(myArrayPtr, obj) == 0;
}

bool String::operator ==(const String &str) const
{
	return strcmp(myArrayPtr, str.myArrayPtr) == 0;
}

//****************************
// Overloaded '!=' operator. *
//****************************
bool String::operator !=(const char *obj) const
{
	return strcmp(myArrayPtr, obj) != 0;
}

bool String::operator !=(const String &str) const
{
	return strcmp(myArrayPtr, str.myArrayPtr) != 0;
}

//***************************
// Overloaded '>' operator. *
//***************************
bool String::operator >(const char *obj) const
{
	return strcmp(myArrayPtr, obj) > 0;
}

bool String::operator >(const String &str) const
{
	return strcmp(myArrayPtr, str.myArrayPtr) > 0;
}

//***************************
// Overloaded '<' operator. *
//***************************
bool String::operator <(const char *obj) const
{
	return strcmp(myArrayPtr, obj) < 0;
}

bool String::operator <(const String &str) const
{
	return strcmp(myArrayPtr, str.myArrayPtr) < 0;
}

//****************************
// Overloaded '>=' operator. *
//****************************
bool String::operator >=(const char *obj) const
{
	return strcmp(myArrayPtr, obj) >= 0;
}

bool String::operator >=(const String &str) const
{
	return strcmp(myArrayPtr, str.myArrayPtr) >= 0;
}

//*****************************************************
// Overloaded assignment operator for character array *
// to String class array.                             *
//*****************************************************
String &String::operator =(const char *obj)
{
	len = strlen(obj) + 1;
	strcpy(myArrayPtr, obj);
	return *this;
}

//********************************************************
// Overloaded assignment operator for string class array *
// to another string class array.                        *
//********************************************************
String &String::operator =(const String &str)
{
	len = str.length();
    myArrayPtr = new char[len];
	for (int i = 0; i < len; i++)
		myArrayPtr[i] = str.myArrayPtr[i];
	
	return *this;
}

//****************************
// Overloaded '+=' operator. *
//****************************
String String::operator +=(const char *obj)
{
	append(obj);
	return *this;
}

String String::operator +=(const String &str)
{
	append(str);
	return *this;
}

void String::print(ostream &out) const
{
	out << myArrayPtr;
}

int String::length() const
{
	return len;
}

char String::operator [](int i) const
{
	if (i < 0 || i >= len) {
		cerr << "can't access location " << i
			<< " of string \"" << myArrayPtr << "\"" << endl;
		return '\0';
	}
	return myArrayPtr[i];
}

ostream & operator<<(ostream &out, const String & s) // overload ostream operator "<<" - External!
{
	s.print(out);
	return out;
}

/* Sample Output:
Initial values:
str1 holds "" (length = 0)
str2 holds "init2" (length = 6)
str3 holds "init3" (length = 6)

Enter a value for str1 (no spaces): hello

Enter a value for str2 (no spaces): world

Enter a value for str3 (no spaces): web

After assignments...
str1 holds "hello" (length = 6)
str2 holds "world" (length = 6)
str3 holds "web" (length = 4)

Enter which element of str1 to display: 0
Element #0 of str1 is 'h'

Enter which element of str2 to display: 2
Element #2 of str2 is 'r'

Enter which element of str3 to display: 3
Element #3 of str3 is ' '

Enter a value to append to str1 (no spaces): kat

Enter a value to append to str2 (no spaces): wide

Enter a value to append to str3 (no spaces): site

After appending...
str1 holds "hellokat" (length = 9)
str2 holds "worldwide" (length = 10)
str3 holds "website" (length = 8)

Comparing str1 and str2...
"hellokat" is less than "worldwide"

test the = operator, after str1 = str2;
str1 holds "worldwide" (length = 10)
str2 holds "worldwide" (length = 10)

After str1 = str1 + s1:
str1 holds "worldwidekat" (length = 13)
str2 holds "worldwide" (length = 10)

test the copy constructor, after str4(str3);
str3 holds "website" (length = 8)
str4 holds "website" (length = 8)

after appending str3 by str2
str3 holds "websiteworldwide" (length = 18)
str4 holds "website" (length = 8)

str2, str4 are not changed. Type any letter to quit.

*/