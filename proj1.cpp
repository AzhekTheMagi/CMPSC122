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
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2059, Saturday, Jan 6th, 2019
// Time of Last Modification: 1920, Monday, Jan 7th, 2019
// Description: Numbers guessing game. Random number generated and user must try
//              to find the right number.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
int getUsrNumber();
int getNumber( int, int);
void validate( int );
void pcValidation( int, int, int );

int main()
{
	const int MIN_VALUE = 1;   // Low range for number generation
	const int MAX_VALUE = 100; // High range for number generation
    bool menu_exit = false; // Menu exit flag
	char menu_choice;  // Holds user menu choice
	int random_number; // Holds randomly generated number
	
	srand( ( unsigned )time( NULL ) ); //Randomizes seed
	
	cout << "Would you like to (p)lay or watch the (c)omputer play?" << '\n';
	cin >> menu_choice;
	
    do
	{
		random_number = getNumber( MIN_VALUE, MAX_VALUE ); // Assigns random number to be found

		if ( menu_choice == 'p' )
			validate( random_number );
		else if ( menu_choice == 'c' )
			pcValidation( random_number, MIN_VALUE, MAX_VALUE );

		cout << '\n'
			 << "Would you like to (p)lay, watch the (c)omputer play, or (q)uite?"
			 << endl;
		cin >> menu_choice;

		if ( menu_choice == 'q' )
			menu_exit = true;
		
	} while ( !menu_exit );
	
	system( "pause" );
	return 0;
}

//***************************
// Generates random number. *
//***************************
int getNumber( int MIN, int MAX )
{
	int random_Num; // Holds randomly generated number
	
	//Assigns random number from MIN_VALUE to MAX_VALUE
    random_Num = ( rand() % ( MAX - MIN + 1 ) ) + MIN;
	
	return random_Num;
}

//*********************************************************************
// Determines whether user selected int is randomly generated number. *
//*********************************************************************
void validate( int rand_num )
{
	bool found = false; // Number location flag
	int user_number;    // Holds user input number

	while ( !found )
	{
		// Gets user number
		user_number = getUsrNumber();
		// Determines & validates user selected number vs. original random number
		if ( user_number < rand_num )
			cout << "Sorry, your guess is too low, try again." << endl;
		else if ( user_number > rand_num )
			cout << "Sorry, your guess is too high, try again." << endl;
		else
			found = true;
	}

	if ( user_number == rand_num )
		cout << "Congrats, you guessed the correct number, " << rand_num
		     << endl;
}

//*******************************
// Prompts user for int number. *
//*******************************
int getUsrNumber()
{
	int usr_num; // Holds user input

	cout << "Enter your guess in between 1 and 100" << endl;
	cin >> usr_num;

	return usr_num;
}

//**************************************************************************
// Determines whether computer selection is the randomly generated number. *
//**************************************************************************
void pcValidation( int rand_num, int min, int max )
{
	bool found = false; // Number location flag
	int random_num = rand_num; // Assigns Original random number generated
	int min_Range = min;       // Assigns initial minimum range
	int max_Range = max;       // Assigns intial maximum range
	int pc_num;                // Holds computer number choice

	while ( !found )
	{
		// Assigns number selection by computer
		pc_num = getNumber( min_Range, max_Range );
		cout << "The computer's guess is " << pc_num << endl;
		// Determines placement of original generated number vs computer selected number
		if ( pc_num < random_num)
		{
			cout << "Sorry, your guess is too low, try again." << endl;
			min_Range = pc_num;
		}
		else if ( pc_num > random_num)
		{
			cout << "Sorry, your guess is too high" << endl;
			max_Range = pc_num;
		}
		else
			found = true;
	}

	if ( pc_num == random_num )
		cout << "Congrats, you guessed the correct number, " << random_num
		     << endl;
}

/*
Sample Output:
Would you like to (p)lay or watch the (c)omputer play?
p
Enter your guess in between 1 and 100
50
Sorry, your guess is too high, try again.
Enter your guess in between 1 and 100
25
Sorry, your guess is too high, try again.
Enter your guess in between 1 and 100
15
Sorry, your guess is too high, try again.
Enter your guess in between 1 and 100
8
Sorry, your guess is too high, try again.
Enter your guess in between 1 and 100
4
Sorry, your guess is too high, try again.
Enter your guess in between 1 and 100
2
Congrats, you guessed the correct number, 2

Would you like to (p)lay, watch the (c)omputer play, or (q)uite?
c
The computer's guess is 81
Sorry, your guess is too low, try again.
The computer's guess is 84
Sorry, your guess is too low, try again.
The computer's guess is 95
Sorry, your guess is too low, try again.
The computer's guess is 97
Sorry, your guess is too low, try again.
The computer's guess is 98
Congrats, you guessed the correct number, 98

Would you like to (p)lay, watch the (c)omputer play, or (q)uite?
q
Press any key to continue . . .
*/