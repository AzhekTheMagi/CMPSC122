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
// Sources of Logic assistance: "Starting Out with C++ from Control Structures
// to objects" 8th edition, Chp 18.
// Name: Anthony Vallin
// PSU User ID: aav5195
// File: StackAppl.h
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Feb 24, 2019
// Time of Last Modification: 1330, Saturday, Feb 23, 2019
// Description: Calculates postfix expressions

//File: StackAppl.h
// ================
// Header file for postfix expression calculator.

#ifndef STACKAPPL_H
#define STACKAPPL_H
#include <iostream>

// Stack template
template <class T>
class StackAppl
{
private:
	// Structure for the linked list stack nodes
	struct StackNode
	{
		T value;         // Value in the node
		StackNode *next; // Pointer to the next node
	};
	StackNode *top;      // Pointer to the stack top

public:
	StackAppl() { top = nullptr }; // Default Constructor
	~StackAppl();                  // Destructor

	// Stack operations
	void push(T obj);
	void pop(T &obj);
	bool isEmpty();
};

#endif
