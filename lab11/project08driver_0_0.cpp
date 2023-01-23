
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
// Sources of Logic assistance: Module 11 
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: project08driver_0_0.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Mar 31, 2019
// Time of Last Modification: Mar 31, 2019
// Description: Calculates algorithm execution times

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "timer.h"
using namespace std;

// Algorithm #1 aka blue function. Code provided by CMPSC 122
// professor.

int Max_Subsequence_Sum_BLUE(const vector<int> &A, const int N)
{
	int This_Sum = 0, Max_Sum = 0;

	for (int i = 0; i < N; i++)
	{
		This_Sum = 0;
		for (int j = i; j < N; j++)
		{
			This_Sum += A[j];
			if (This_Sum > Max_Sum)
			{
				Max_Sum = This_Sum;
			}
		}
	}
	return Max_Sum;
}

// Algorithm #2 aka Green Function. Code provided by CMPSC 122
// professor. 

int Max_Subsequence_Sum_GREEN(const vector<int> &A, const int N)
{
	int This_Sum = 0, Max_Sum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			This_Sum = 0;
			for (int k = i; k <= j; k++)
			{
				This_Sum += A[k];
			}
			if (This_Sum > Max_Sum)
			{
				Max_Sum = This_Sum;
			}
		}
	}
	return Max_Sum;
}

// Algorithm #3 aka Red Function. Code provided by CMPSC 122
// professor.

int Max_Subsequence_Sum_RED(const vector<int> &A, const int N)
{
	int This_Sum = 0, Max_Sum = 0;

	for (int Seq_End = 0; Seq_End < N; Seq_End++)
	{
		This_Sum += A[Seq_End];

		if (This_Sum > Max_Sum)
		{
			Max_Sum = This_Sum;
		}
		else if (This_Sum < 0)
		{
			This_Sum = 0;
		}
	}
	return Max_Sum;
}

// Print '*'
void printStar()
{
	cout << "\n*********************************\n";
}

int main( )
{
	int Size = 64;      // Initial size of vector.
	int iterations = 6; // Loop counter for desired algorithm iterations.
	Timer T_red[6];     // Holds red function algorithm run times.
	Timer T_blue[6];    // Holds blue function algorithm run times.
	Timer T_green[6];   // Holds green function algorithm run times.
	vector<int> myVector(Size); // Vector for evaluating algorithms.
	vector<int> red_sum(6);     // Max Subsequence sum for red function.
	vector<int> blue_sum(6);    // Max Subsequence sum for blue function.
	vector<int> green_sum(6);   // Max Subsequence sum for green function.

	srand((unsigned)time(0));

	for (int i = 0; i < iterations; i++)
	{
		// Populates vector with random numbers from 1 to 49.
		for (auto &I : myVector)
			I = rand() % 100 - 50;

		// Algorithm #1 aka blue function start & stop time.
		T_blue[i].start();
		blue_sum[i] = Max_Subsequence_Sum_BLUE(myVector, Size);
		T_blue[i].stop();

		// Algorithm #2 aka green function start & stop time.
		T_green[i].start();
		green_sum[i] = Max_Subsequence_Sum_GREEN(myVector, Size);
		T_green[i].stop();

		// Algorithm #3 aka red function start & stop time.
		T_red[i].start();
		red_sum[i] = Max_Subsequence_Sum_RED(myVector, Size);
		T_red[i].stop();

		// Resizes vector in order to increase input size for 
		// algorithm calculation. 
		Size *= 2;
		myVector.resize(Size);
	}

	// Algorithm #1 aka blue function results.
	for (int i = 0; i < iterations; i++)
	{
		cout << "\nMaximum contiguous Blue Function subsequence sum: "
			<< blue_sum[i] << endl;
		T_blue[i].show();
	}

	printStar();

	// Algorithm #2 aka green function results.
	for (int i = 0; i < iterations; i++)
	{
		cout << "\nMaximum contiguous green Function subsequence sum: "
			<< green_sum[i] << endl;
		T_green[i].show();
	}
	
	printStar();

	// Algorithm #1 aka red function results.
	for (int i = 0; i < iterations; i++)
	{
		cout << "\nMaximum contiguous red Function subsequence sum: "
			<< red_sum[i] << endl;
		T_red[i].show();
	}

	system("pause");
	return 0;
}

/* Sample Output:

Maximum contiguous Blue Function subsequence sum: 300
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Maximum contiguous Blue Function subsequence sum: 587
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Maximum contiguous Blue Function subsequence sum: 301
  Process Timer
  -------------------------------
  Elapsed Time   : 0.005s

Maximum contiguous Blue Function subsequence sum: 401
  Process Timer
  -------------------------------
  Elapsed Time   : 0.02s

Maximum contiguous Blue Function subsequence sum: 1079
  Process Timer
  -------------------------------
  Elapsed Time   : 0.077s

Maximum contiguous Blue Function subsequence sum: 584
  Process Timer
  -------------------------------
  Elapsed Time   : 0.309s

*********************************

Maximum contiguous green Function subsequence sum: 300
  Process Timer
  -------------------------------
  Elapsed Time   : 0.008s

Maximum contiguous green Function subsequence sum: 587
  Process Timer
  -------------------------------
  Elapsed Time   : 0.06s

Maximum contiguous green Function subsequence sum: 301
  Process Timer
  -------------------------------
  Elapsed Time   : 0.456s

Maximum contiguous green Function subsequence sum: 401
  Process Timer
  -------------------------------
  Elapsed Time   : 3.612s

Maximum contiguous green Function subsequence sum: 1079
  Process Timer
  -------------------------------
  Elapsed Time   : 28.262s

Maximum contiguous green Function subsequence sum: 584
  Process Timer
  -------------------------------
  Elapsed Time   : 228.457s

*********************************

Maximum contiguous red Function subsequence sum: 300
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Maximum contiguous red Function subsequence sum: 587
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Maximum contiguous red Function subsequence sum: 301
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Maximum contiguous red Function subsequence sum: 401
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Maximum contiguous red Function subsequence sum: 1079
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s

Maximum contiguous red Function subsequence sum: 584
  Process Timer
  -------------------------------
  Elapsed Time   : 0.001s
Press any key to continue . . .
*/