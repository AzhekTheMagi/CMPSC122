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
// Sources of Logic assistance: Module 13 discussion board
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: proj13.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Apr 14, 2019
// Time of Last Modification: Apr 13, 2019
// Description:

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
unsigned Hash1(const string &key, const int h_size);
unsigned Hash2(const string &key, const int h_size);

int main()
{
	// Code provided by instructor.
	cout << Hash1("hello", 64) << endl;
	cout << Hash1("world", 64) << endl;
	cout << Hash1("you", 64) << endl;
	cout << Hash1("me", 64) << endl;
	cout << Hash1("his", 64) << endl;
	cout << Hash1("her", 64) << endl;
	cout << Hash1("asdas", 64) << endl;
	cout << Hash1("rguehg", 64) << endl << endl;
	cout << Hash2("hello", 71) << endl;
	cout << Hash2("world", 71) << endl;
	cout << Hash2("you", 71) << endl;
	cout << Hash2("me", 71) << endl;
	cout << Hash2("his", 71) << endl;
	cout << Hash2("her", 71) << endl;
	cout << Hash2("asdas", 71) << endl;
	cout << Hash2("rguehg", 71) << endl;

	system("pause");
	return 0;
}
// Code provided by instructor.
unsigned Hash1(const string & key, const int h_size)
{
	unsigned int value = 0;

	for (int i = 0; i < key.length(); i++)
		value = (value + key[i]) * 16;

	return value % h_size;
}

// Code provided by instructor.
unsigned Hash2(const string & key, const int h_size)
{
	unsigned int value = 0;

	for (int i = 0; i < key.length(); i++)
		value = (value + key[i]) * 31;

	return value % h_size;
}
/*HW Questions:
1. f(x) = ( x[n-1] * y ) % m;
2. No, it does not use a prime number as its hash table size. There
   are more collisions with non-prime numbers. There were 6 collisions
   during hash1 (h_size = 64) run. Hash tables become inefficient as 
   you increase collisions. 
3. Yes, a prime number was used for the hash table size. There is less
   chance for a collision. In hash2's run there were no collisions.
   Average 'lookup' cost decreases with less collisions. 
*/
/*Sample Output:
48
0
16
16
48
32
48
48

7
29
5
31
66
25
43
39
Press any key to continue . . .
*/