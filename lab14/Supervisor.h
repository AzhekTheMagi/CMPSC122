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
// File: Supervisor.h
// Course: CMPSC122 Spring Semester 2019
// Due Time: 2159, Sunday, Apr 20, 2019
// Time of Last Modification: Apr 19, 2019
// Description: Supervisor drived class. Used for attributes unique
// to supervisor employee

#ifndef _SUPERVISOR_H
#define _SUPERVISOR_H

#include <string>
#include "employee.h"
#include "manager.h"
using std::string;

class Supervisor : public Employee
{
public:
	Supervisor(string thename_, 
		       float thePayRate_, 
		       string theDepartment_);

	void setDept(const string &theDepartment_);
	string getDept() const;
	float pay(float hrs_worked) const;

protected:
	string department;
};

////
//Supervisor Definitions.
////

///////
// Default constructor for Supervisor derived class.
//////
Supervisor::Supervisor(string thename_,
	                   float thePayRate_,
	                   string theDepartment_)
	: Employee(thename_, thePayRate_)
{
	department = theDepartment_;
}

//////
// Sets department mutator.
//////
void Supervisor::setDept(const string &theDepartment_)
{
	department = theDepartment_;
}

/////
// Gets department name accessor.
/////
string Supervisor::getDept() const
{
	return department;
}

//////
// Supervisor salary is fixed. Hours worked does not
// impact pay.
//////
float Supervisor::pay(float hrs_worked) const
{
	return (payRate);
}

#endif

/*Sample Output
For Employee:
Name: John
Pay: 1000
Changing the Employee's name...
New Name: Doug

For Manager:
Name: Matthew
Salaried: 1
Pay: 1200
Changing the Manager's salaried status...
New Pay: 48000

For Supervisor:
Name: Denise
Pay: 780
Dept: Accounting
Changing the Supervisor's pay rate...
New Pay: 900
Press any key to continue . . .
*/