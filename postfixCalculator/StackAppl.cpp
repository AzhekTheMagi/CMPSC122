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
// Description: Calculates postfix expressions

//File: StackAppl.cpp
// ================
// Class implementation file for postfix expression calculator.

#include "StackAppl.h"

//**************
// Destructor. *
// *************
template <class T>
StackAppl<T>::~StackAppl()
{
	StackNode *nodePtr;  // Pointer to the node.
	StackNode *nextNode; // Pointer to the next node.

	// Position nodePtr to the top of the stack.
	nodePtr = top;

	// Traverse the list to delete each node.
	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

//***********************************************************
// Member function that pushes the argument onto the stack. *
//***********************************************************
template <class T>
void StackAppl<T>::push(T item)
{
	StackNode *newNode = nullptr; // Pointer to a new node.

	// Allocate a new node and store num there.
	newNode = new StackNode;
	newNode->value = item;

	// Makes newNode the first node if there are no nodes in
	// the list.
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else // Inserts newNode before top.
	{
		newNode->next = top;
		top = newNode;
	}
}

//**************************************************************
// Member function that pops the value at the top of the stack *
// off, and copies it into the variable passed as an argument. *
//**************************************************************
template <class T>
void StackAppl<T>::pop(T &item)
{
	StackNode *temp = nullptr; // Temporary pointer.

	// Verifies that stack isn't empty
	if (isEmpty())
		std::cout << "Empty Stack" << endl;
	else // 'pops' value off top of stack
	{
		item = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//*********************************************************************
// Member function returns true if stack is empty or false otherwise. *
//*********************************************************************
template <class T>
bool StackAppl<T>::isEmpty()
{
	bool status; // Flag

	if (!top)
		status = true;
	else
		status = false;

	return status;
}