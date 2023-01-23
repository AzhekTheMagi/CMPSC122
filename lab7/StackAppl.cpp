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
// File: StackAppl.cpp
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Feb 24, 2019
// Time of Last Modification: 1330, Saturday, Feb 23, 2019
// Description: Evaluates postfix(RPN) expressions

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>
using namespace std;

// Function prototypes
bool status();

int main()
{
	int lhs, rhs;       // Holds temporary int for operator calculations.
	int temp;           // Temporarily holds converted char int.
	string token;       // Holds postfix expression.
	stack<int> mystack; // Operand stack.

	
	do
	{
		cout << "Please enter the RPN expression to be evaluated:\n";
		getline(cin, token);

		for (size_t i = 0; i < token.length(); i++)
		{
			// Pushes onto stack if digit
			if (isdigit(token[i]))
			{
				temp = token[i] - '0'; // Converts char digit to int.
				mystack.push(temp);    // Pushes converted char digit onto stack.
				cout << "Token = " << temp << " Push " << temp << endl;
			}
			// Assumes char is an operator
			else if (!isspace(token[i]))
			{
				// Pops two numbers off the stack & temporarily 
				// assigns them for operator calculations.
				lhs = mystack.top();
				mystack.pop();
				rhs = mystack.top();
				mystack.pop();

				cout << "Token = " << token[i] << " Pop " << lhs << " Pop " << rhs;
				
				switch (token[i])
				{
					case '+': mystack.push(lhs + rhs);
						cout << " Push " << mystack.top() << endl;
						break;
					case '-': mystack.push(rhs - lhs);
						cout << " Push " << mystack.top() << endl;
						break;
					case '*': mystack.push(rhs * lhs);
						cout << " Push " << mystack.top() << endl;
						break;
					case '/': mystack.push(rhs / lhs);
						cout << " Push " << mystack.top() << endl;
						break;
					default: cout << "Incorrect operator used!\n";
				}
			}
		}

		cout << "Token = Pop " << mystack.top() << endl;

	} while (!status());

	system("pause");
	return 0;
}

bool status()
{
	bool exit_program; // Exit flag.
	char usr_choice;

	cout << "Type 'Y' or 'y' to continue or type any other letter to quit: ";
	cin >> usr_choice;
	cin.ignore();

	if (toupper(usr_choice) == 'Y')
		exit_program = false;
	else
		exit_program = true;

	return exit_program;
}

/*Output sample:
Please enter the RPN expression to be evaluated:
9 2 1 + / 4 *
Token = 9 Push 9
Token = 2 Push 2
Token = 1 Push 1
Token = + Pop 1 Pop 2 Push 3
Token = / Pop 3 Pop 9 Push 3
Token = 4 Push 4
Token = * Pop 4 Pop 3 Push 12
Token = Pop 12
Type 'Y' or 'y' to continue or type any other letter to quit: y
Please enter the RPN expression to be evaluated:
2 3 4 + *
Token = 2 Push 2
Token = 3 Push 3
Token = 4 Push 4
Token = + Pop 4 Pop 3 Push 7
Token = * Pop 7 Pop 2 Push 14
Token = Pop 14
Type 'Y' or 'y' to continue or type any other letter to quit: n
Press any key to continue . . .


*/