// Alert Header File
// Author James Wetters

// Includes
#ifndef alertInfo_H
#define alertInfo_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

// Name Space
using namespace std;


class alert
{
private:
	// Data members
	string	countyFipsCode;
	string	startDateAndTime;
	string	endDateAndTime;
	string	warningCode;


public:
	alert();

	// Sets
	void setCountyFipsCode(string change)
	{
		countyFipsCode = change;
	}
	void setStartDateAndTime(string change)
	{
		startDateAndTime = change;
	}
	void setEndDateAndTime(string change)
	{
		endDateAndTime = change;
	}
	void setWarningCode(string change)
	{
		warningCode = change;
	}

	// Gets
	string getCountyFipsCode() const
	{
		return countyFipsCode;
	}
	string getStartDateAndTime() const
	{
		return startDateAndTime;
	}
	string getEndDateAndTime() const
	{
		return endDateAndTime;
	}
	string getWarningCode() const
	{
		return warningCode;
	}
	
	
	// Functions Prototype
	void print();

};
#endif