// Problem cpp file
// Author James Wetters

#include "problem.h"

// Constructor
Problem::Problem()
{}

// Paramaterized Constructor
Problem::Problem(int cCode, int cCrit, Date cDate, string cCon)
{
	setProblemCode(cCode);
	setCritLevel(cCrit);
	setDate(cDate);
	setContact(cCon);
}

//-----------------------------------------------------------------
// Overloaded operator < less than
//-----------------------------------------------------------------
bool Problem::operator< (Problem& p)
{
	if (critLevel < p.critLevel)
		return true;

	if (critLevel == p.critLevel && date < p.date)
		return true;

	return false;
}

//-----------------------------------------------------------------
// Overloaded operator == equal to
//-----------------------------------------------------------------
bool Problem::operator== (Problem& p)
{

	if (critLevel == p.critLevel && date == p.date)
	{
		return true;
	}

	return false;
}

//-----------------------------------------------------------------
// Overloaded operator != not equal to
//-----------------------------------------------------------------
bool Problem::operator!= (Problem& p)
{

	if (critLevel != p.critLevel || !(date == p.date))
	{
		return true;
	}

	return false;
}

