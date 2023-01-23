/*
 * File: employee.h
 * Employee class definition.
 */

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
using namespace std;

class Employee 
{
public:
  Employee(string theName, float thePayRate);

  string getName() const;
  float getPayRate() const;
  float pay(float hoursWorked) const;
  void setName(const string &n);
  void setPayRate(const float &pay_rate);

protected:
  string name;
  float payRate;
};

/*
 * Employee method definitions.
 */

Employee::Employee(string theName, float thePayRate)
{
  name = theName;
  payRate = thePayRate;
}

void Employee::setPayRate(const float &pay_rate)
{
	payRate = pay_rate;
}

void Employee::setName(const string &n)
{
	name = n;
}

string Employee::getName() const
{
  return name;
}

float Employee::getPayRate() const
{
  return payRate;
}

float Employee::pay(float hoursWorked) const
{
  return hoursWorked * payRate;
}


#endif /* not defined _EMPLOYEE_H */

