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
// Sources of Logic assistance: http://www.danzig.us/cpp/recursion
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: recursive_pathing.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Mar 24, 2019
// Time of Last Modification: Mar 22, 2019
// Description: Calculates a path through a rectangular matrix like grid

#include <iostream>
#include <cctype>
#include "timer.h"
using namespace std;

// Function Prototype
int findPath(int x_, int y_);

int main()
{
	char menu_exit;   // Loop exit.
	Timer stop_watch; // Timer for algorithm.
	int x = 0, y = 0; // Destination grid coordinates.

	do
	{
		cout << "\nHow many points north of A is B? ";
		cin >> x;
		cout << "\nHow many points east of A is B? ";
		cin >> y;

		stop_watch.start(); // Timer starts.
		
		cout << "\nThere are " << findPath(x, y)
			 << " northeast paths between A and B.\n" << endl;
		
		stop_watch.stop(); // Timer stops.
		stop_watch.show(); // Displays elapsed time.

		cout << "\nEnter y or Y to continue next example or any"
			 << " other letter to exit: ";
		cin >> menu_exit;

	} while (toupper(menu_exit) == 'Y');
	
	cout << endl;

	system("pause");
	return 0;
}

// Function Definitions
/********************************************
* Calculates total number of paths possible *
* in matrix by given coordinates.           *
*********************************************/
int findPath(int x_, int y_)
{
	if (x_ == 0)
		return 1;
	if (y_ == 0)
		return 1;
	return (findPath(x_ - 1, y_) + findPath(x_, y_ - 1));
}

/*Sample Output


How many points north of A is B? 2

How many points east of A is B? 3

There are 10 northeast paths between A and B.

  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Enter y or Y to continue next example or any other letter to exit: y

How many points north of A is B? 12

How many points east of A is B? 14

There are 9657700 northeast paths between A and B.

  Process Timer
  -------------------------------
  Elapsed Time   : 0.229s

Enter y or Y to continue next example or any other letter to exit: y

How many points north of A is B? 16

How many points east of A is B? 16

There are 601080390 northeast paths between A and B.

  Process Timer
  -------------------------------
  Elapsed Time   : 14.115s

Enter y or Y to continue next example or any other letter to exit: n

Press any key to continue . . .
*/