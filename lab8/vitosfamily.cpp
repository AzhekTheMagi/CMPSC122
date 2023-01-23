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
// File: vitosfamily.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Mar 3, 2019
// Time of Last Modification: 1330, Saturday, Mar 3, 2019
// Description: Computes optimal distance between Vito and his family

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int relative_size;     // Holds total relatives of Vito.
	int street_number;     // Holds relatives street number.
	int vitos_house;       // Holds mean of vector.
	int test_cases;        // Holds amount of input test cases.
	int sum = 0;           // Holds minimum ideal distance.
	vector<int> relativeV; // Holds everybodys street number.

	cout << "Enter test cases: ";
	cin >> test_cases;
	cin.ignore();

	while (test_cases != 0)
	{
		// User prompt for total addresses to consider.
		cout << "Enter total amount of relatives to consider: ";
		cin >> relative_size;
		cin.ignore();

		// Resizes vector to size of relatives input.
		relativeV.resize(relative_size, 0);

		// Populates vector with street number of each relative.
		cout << "Enter street number:\n";
		for (int i = 0; i < relative_size; i++)
		{
			cin >> street_number;
			relativeV[i] = street_number;
		}

		// Sorts vector from least to greatest for future median calculation.
		sort(relativeV.begin(), relativeV.end());

		// Calculates median aka where Vito's house will be oriented.
		// Even relative size is checked first for median calculation.
		if (relative_size % 2 == 0)
		{
			vitos_house = (relativeV[(relativeV.size() / 2) - 1] +
				relativeV[relativeV.size() / 2]) / 2;
		}
		else
			vitos_house = relativeV[relativeV.size() / 2];

		// Calculates ideal distance between vito and all his relatives.
		for (auto i : relativeV)
			sum += abs(i - vitos_house);

		// Output of ideal distance.
		cout << "Output\n" << sum << endl;

		// Resets sum aka ideal distance. Prep for next test case.
		sum = 0;
		// Acts like a loop counter to exit while loop.
		test_cases--;
	}

	system("pause");
	return 0;
}

/*Sample Output:
Enter test cases: 3
Enter total amount of relatives to consider: 3
Enter street number:
2 2 4
Output
2
Enter total amount of relatives to consider: 4
Enter street number:
3 2 4 6
Output
5
Enter total amount of relatives to consider: 11
Enter street number:
10 2 12 23 10 3 40 20 19 4 10
Output
85
Press any key to continue . . .

*/