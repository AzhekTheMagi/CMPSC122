/*
 * File: sort.cpp
 * Tests various sort algorithms
 */

#include <iostream>
#include <vector>
using namespace std;

const int ARRAY_SIZE = 8;
const int LOWER_BOUND = 0;

// Function Prototype
void display(int x[]);
void display(int x[], int mid);
void hybrid(int x[], int start, int end, int cutoff);
void swap(int &a, int &b);
int split (int x[], int start, int end);

void merge(int array[], int low, int mid, int high)
{
	vector<int>temp(high + 1);
	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high)
	{
		if (array[i] <= array[j])
		{
			temp[k++] = array[i++];
		}
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= high)
		temp[k++] = array[j++];
	k--;
	while (k >= 0)
	{
		array[k + low] = temp[k];
		k--;
	}
}

void mergeHelper(int x[], int lo, int hi)
{
	int mid;
	if (lo < hi)
	{
		mid = (lo + hi) / 2;
		mergeHelper(x, lo, mid);
		mergeHelper(x, mid + 1, hi);
		merge(x, lo, mid, hi);
	}
}

void mergesort(int x[], int n)
{
	mergeHelper(x, 0, n - 1);
}

// Function templates

////////
// Quicksort Algo.
////////
template <typename T>
void quickHelper(T x[], int first, int last)
{
	if (first < last)
	{
		int pi = split(x, first, last);
		quickHelper(x, first, pi - 1);
		quickHelper(x, pi + 1, last);
	}
}

////////
// Quicksort Algo starter function.
///////
template <typename T>
void QuickSort(T x[], int n)
{
	quickHelper(x, 0, n - 1);
}

int main()
{
	int x[ARRAY_SIZE] = { 4,2,9,7,8,5,1,3 };

	display(x);
	mergesort(x, ARRAY_SIZE);

/*	hybrid(x, 0, ARRAY_SIZE - 1, LOWER_BOUND);
	QuickSort(x, ARRAY_SIZE);
*/
	display(x);
	system("pause");
	return 0;
}

// Function Definitions
////////
// Displays array contents.
////////
void display(int x[])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
		cout << x[i] << ' ';
	cout << endl;
}

void display(int x[], int mid)
{
	for (int i = 0; i < mid; i++)
		cout << x[i] << ' ';
}


////////
// Swaps two values.
////////
void swap(int &a, int &b)
{
	int hold = a;
	a = b;
	b = hold;
}

////////
// Finds pivot position.
////////
int split (int x[], int start, int end)
{
	int i = start + 1;
	int piv = x[start]; //make the first element as pivot element.
	
	// Rearrange the array by putting elements which are less than pivot
	// on one side and which are greater that on other.
	for (int j = start + 1; j <= end; j++)
	{
		if (x[j] < piv)
		{
			swap (x[i], x[j]);
			i += 1;
		}
	}

	swap (x[start], x[i - 1]); //put the pivot element in its proper place.
	return i - 1;              //return the position of the pivot
}

////////
// Hybrid Quicksort that incorporates Selection sort.
// Code taken from https://www.isid.ac.in/~deepayan/ICP2017/projects/Anirban_Ray/report.html
////////
void hybrid(int x[], int start, int end, int cutoff)
{
	if (start < end) 
	{
		// applying partition algorithm only when array size is more than cutoff
		if ((end - start + 1) > cutoff)
		{
			int key = split(x, start, end);
			hybrid(x, start, key, cutoff);
			hybrid(x, (key + 1), end, cutoff);
		}
	}
}