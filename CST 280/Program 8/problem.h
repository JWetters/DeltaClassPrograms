// Problem Header
// Author James Wetters

#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <string>

using namespace std;
#include "date2.h"

class Problem
{
private:
	// Variables
	int problemCode;
	int critLevel;
	Date date;
	string contact;

public:
	// Gets
	int getProblemCode()
	{
		return problemCode;
	}
	int getCritLevel()
	{
		return critLevel;
	}
	Date getDate()
	{
		return date;
	}
	string getContact()
	{
		return contact;
	}

	// Sets
	void setProblemCode(int change)
	{
		problemCode = change;
	}

	void setCritLevel(int change)
	{
		critLevel = change;
	}

	void setDate(Date change)
	{
		date = change;
	}

	void setContact(string change)
	{
		contact = change;
	}

	// Problem constructor
	Problem();
	// Problem paramaterized constructor
	Problem(int cCode, int cCrit, Date cDate, string cCon);

	// Problem Overloaded Operators
	bool Problem::operator< (Problem& p);
	bool Problem::operator== (Problem& p);
	bool Problem::operator!= (Problem& p);

	
};
#endif


