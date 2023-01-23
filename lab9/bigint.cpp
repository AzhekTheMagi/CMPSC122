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
// File: bigint.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Mar 17, 2019
// Time of Last Modification: 0930, Sunday, Mar 17, 2019
// Description: Calculates large integers

//cmpsc122 Assignment 6 
//Modified from textbook Larry Nyhoff,  ADTs, Data Structures, and Problem Solving 
//with C++, 2nd ed., Prentice-Hall, 2005.

/*-- BigInt.cpp-------------------------------------------------------------
                This file implements BigInt member functions.
--------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;

#include "BigInt.h"

//--- Definition of read()
void BigInt::read(istream & in)
{
  static bool instruct = true;
  if (instruct)
  {
     cout << "Enter " << DIGITS_PER_BLOCK << "-digit blocks, separated by "
            "spaces.\nEnter a negative integer in last block to signal "
            "the end of input.\n\n";
    instruct = false;
  }
  short int block;
  const short int MAX_BLOCK = (short) pow(10.0, DIGITS_PER_BLOCK) - 1;
  for (;;)
  {
    in >> block;
    if (block < 0) return;

    if (block > MAX_BLOCK)
      cerr << "Illegal block -- " << block << " -- ignoring\n";
    else
      myList.push_back(block);
  }
}

//--- Definition of display()
void BigInt::display(ostream & out) const
{ 
   int blockCount = 0;
   const int BLOCKS_PER_LINE = 20;   // number of blocks to display per line

   for (list<short int>::const_iterator it = myList.begin(); ; )
   {
      out << setfill('0'); 
      if (blockCount == 0)
         out << setfill(' '); 
 
      if (it == myList.end())
         return;

      out << setw(3) << *it;
      blockCount++ ;

      it++;
      if (it != myList.end())
      {
         out << ',';
         if (blockCount > 0 && blockCount % BLOCKS_PER_LINE == 0)
            out << endl;
      }
   }
}

//--- Definition of operator+()
BigInt BigInt::operator+(BigInt addend2)
{
   BigInt sum;
   short int first,                  // a block of 1st addend (this object)
             second,                 // a block of 2nd addend (addend2)
             result,                 // a block in their sum
             carry = 0;              // the carry in adding two blocks

   list<short int>::reverse_iterator // to iterate right to left
      it1 = myList.rbegin(),         //   through 1st list, and
      it2 = addend2.myList.rbegin(); //   through 2nd list

   while (it1 != myList.rend() || it2 != addend2.myList.rend())
   {
      if (it1 != myList.rend())
      { 
         first = *it1;
         it1++ ;
      }
      else
         first = 0;
      if (it2 != addend2.myList.rend())
      {
         second = *it2;
         it2++ ;
      }
      else
         second = 0;

      short int temp = first + second + carry;
      result = temp % 1000;
      carry = temp / 1000;
      sum.myList.push_front(result);
   }

   if (carry > 0)
      sum.myList.push_front(carry);

   return sum;
}

/***********************
* Subtration operator. *
************************/
BigInt BigInt::operator-(BigInt subend2)
{
	BigInt difference;
	short int first,                  // a block of 1st subend (this object)
		      second,                 // a block of 2nd subend (subend2)
		      result,                 // a block in their difference
		      carry = 0;              // the carry in subtracting two blocks

	list<short int>::reverse_iterator  // to iterate right to left
		it1 = myList.rbegin(),         // through 1st list, and
		it2 = subend2.myList.rbegin(); // through 2nd list

	while (it1 != myList.rend() || it2 != subend2.myList.rend())
	{
		if (it1 != myList.rend())
		{
			first = *it1;
			it1++;
		}
		else
			first = 0;
		if (it2 != subend2.myList.rend())
		{
			second = *it2;
			it2++;
		}
		else
			second = 0;

		short int temp = first - second + carry;

		if (temp < 0)
		{
			result = temp + 1000;
			carry = -1;
		}
		else
		{
			result = temp % 1000;
			carry = temp / 1000;
		}

		difference.myList.push_front(result);
	}

	if (carry > 0)
		difference.myList.push_front(carry);

	return difference;
}

/*************
* > operator *
**************/
bool BigInt::operator>(const BigInt &rhs)
{
	bool flag = false; // Greater than flag.
	auto it1 = myList.begin();     // list<short int>::iterator
	auto it2 = rhs.myList.begin(); // list<short int>::iterator

	if (myList.size() > rhs.myList.size())
		flag = true;
	else
	{
		while (it1 != myList.end() || it2 != rhs.myList.end())
		{
			if (*it1 > *it2)
				flag = true;
			it1++;
			it2++;
		}
	}

	return flag;
}

/*Sample Output
----
Enter a big integer:
Enter 3-digit blocks, separated by spaces.
Enter a negative integer in last block to signal the end of input.

453 213 345 -1
Enter another big integer:
892 -1
The sum of
		453,213,345 + 892
is
		453,214,237

The bigger number of
		453,213,345
and
		892
is
		453,213,345

The subtraction of
		453,213,345 - 892
is
		453,212,453

Add more integers (Y or N)? y
Enter a big integer:
347 965 434 213 -1
Enter another big integer:
298 432 678 984 -1
The sum of
		347,965,434,213 + 298,432,678,984
is
		646,398,113,197

The bigger number of
		347,965,434,213
and
		298,432,678,984
is
		347,965,434,213

The subtraction of
		347,965,434,213 - 298,432,678,984
is
		 49,532,755,229

Add more integers (Y or N)? n
Press any key to continue . . .
*/
