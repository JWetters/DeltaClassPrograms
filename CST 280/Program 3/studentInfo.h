// This reads in student data and writes deplomas
// Author James Wetters

#ifndef studentInfo_H
#define studentInfo_H
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

class diploma
{
private:
	// Data members
	string	college;
	string	firstName;
	string	middleName;
	string	lastName;
	string	degree;
	string	day;
	string	month;
	string	year;


public:
	// Constructor
	diploma();

	// Gets
	string getCollege() const
	{ return college; }
	string getFirstName() const
	{ return firstName; }
	string getMiddleName() const
	{ return middleName; }
	string getLastName() const
	{ return lastName; }
	string getDegree() const
	{ return degree; }
	string getDay() const
	{ return day; }
	string getMonth() const
	{ return month; }
	string getYear() const
	{ return year; }

	// Sets
	void setCollege(string change)
	{ college = change; }
	void setFirstName(string change)
	{ firstName = change; }
	void setMiddleName(string change)
	{ middleName = change; }
	void setLastName(string change)
	{ lastName = change; }
	void setDegree(string change)
	{ degree = change; }
	void setDay(string change)
	{ day = change; }
	void setMonth(string change)
	{ month = change; }
	void setYear(string change)
	{ year = change; }

	// Functions
	string dayToWords(string d);
	string monthToWords(string m);
	string yearToWords(string y);
	string degreeToName(string deg);
	string num1To9(int value);
	string num10To19(int value);
	string selectMonth(int value);
	int stringToInt(string convert);
	int findSetWidth(int lineSize);
	void print();
};
#endif