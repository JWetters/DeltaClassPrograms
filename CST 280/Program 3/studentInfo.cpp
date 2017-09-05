// This reads in student data and writes deplomas
// Author James Wetters

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "studentInfo.h"

using namespace std;

//************************************************************************
//	Constructor 
//
// Initilizes object member variables when called
//************************************************************************

diploma::diploma()
{}




//************************************************************************
//	 Day Number to Words
//
// Recives a string for day
// Converts day number and sends back day in words as a string
//************************************************************************

string diploma::dayToWords(string d)
{
	// Initilize variables
	string temp;
	// Get day as a number
	int num;

	// Convert string number to int number
	num = stringToInt(d);

	if (num < 10)
	{
		temp = num1To9(num);
	}
	else if (num < 20)
	{
		temp = num10To19(num);
	}
	else if (num == 20)
	{
		temp = "twentieth";
	}
	else if (num < 30)
	{
		num = num - 20;
		temp = "twenty-" + num1To9(num);
	}
	else if (num == 30)
	{
		temp = "thirtieth";
	}
	else
	{
		temp = "thirty-first";
	}

	return temp;
}


//************************************************************************
//	Month number to month name 
//
// 
//************************************************************************

string diploma::monthToWords(string m)
{
	// Initilize variables
	string temp;

	// Get day as a number
	int num;

	// Find month number
	num = stringToInt(m);

	// Assign month name
	temp = selectMonth(num);

	return temp;
}


//************************************************************************
//	Month number to month name 
//
// Recivies a string for the number of years
// Sends a year back in words as a string
//************************************************************************

string diploma::yearToWords(string y)
{
	// Initilize variables
	string temp;
	// Get day as a number
	int num;

	// Convert string number to int number
	num = stringToInt(y);

	// Find the value
	if (num < 20)
	{
		temp = num10To19(num);		// Assigne converted value
	}
	else if (num == 20)
	{
		temp = "twentieth";
	}
	else if (num < 30)
	{
		num = num - 20;
		temp = "twenty-" + num1To9(num);
	}

	return temp;
}


//************************************************************************
//	Degree Abreviation to name 
//
// Recives a degree abriviation as a string
// Sends a degree name in words as a string
//************************************************************************

string diploma::degreeToName(string deg)
{
	// Initilize variables
	string temp;
	string AS = "A.S.", BA = "B.A.", BS = "B.S.", PHARMD = "Pharm.D.";
	string AAS = "A.A.S.", MS = "M.S.";

	// Find Degree
	if (deg.compare(AS) != 1)				// Compare abreviations
	{
		temp = "Associate of Science";		// Assigne degree in words
	}
	else if (deg.compare(BA) != 1)
	{
		temp = "Bachelor of Arts";
	}
	else if (deg.compare(BS) != 1)
	{
		temp = "Bachelor of Science";
	}
	else if (deg.compare(PHARMD) != 1)
	{
		temp = "Doctor of Pharmacy";
	}
	else if (deg.compare(AAS) != 1)
	{
		temp = "Associate of Applied Science";
	}
	else
	{
		temp = "Master of Science";
	}

	return temp;
}



//************************************************************************
//	Numbers 1 to 9 
//
// Recivies an int value 
// Sends back the number converted to a string in words
//************************************************************************

string diploma::num1To9(int value)
{
	string line;
	switch (value)
	{
	case 1:
		line = "first";
		break;

	case 2:
		line = "second";
		break;

	case 3:
		line = "third";
		break;

	case 4:
		line = "fourth";
		break;

	case 5:
		line = "fifth";
		break;

	case 6:
		line = "sixth";
		break;

	case 7:
		line = "seventh";
		break;

	case 8:
		line = "eighth";
		break;

	case 9:
		line = "ninieth";
	}

	return line;
}


//************************************************************************
//	Numbers 10 to 19 
//
// Recivies an int value 
// Sends back the number converted to a string in words
//************************************************************************

string diploma::num10To19(int value)
{
	string line;
	switch (value)
	{
	case 10:
		line = "tenth";
		break;

	case 11:
		line = "eleventh";
		break;

	case 12:
		line = "twelfth";
		break;

	case 13:
		line = "thirteenth";
		break;

	case 14:
		line = "fourteenth";
		break;

	case 15:
		line = "fifteenth";
		break;

	case 16:
		line = "sixteenth";
		break;

	case 17:
		line = "seventeenth";
		break;

	case 18:
		line = "eighteenth";
		break;

	case 19:
		line = "nineteenth";
	}

	return line;
}

//************************************************************************
//	Numbers 10 to 19 
//
// Recivies an int value
// Sends a string of the name of a month
//************************************************************************

string diploma::selectMonth(int value)
{
	string line;
	switch (value)
	{
	case 1:
		line = "January";
		break;

	case 2:
		line = "Febuary";
		break;

	case 3:
		line = "March";
		break;

	case 4:
		line = "April";
		break;

	case 5:
		line = "May";
		break;

	case 6:
		line = "June";
		break;

	case 7:
		line = "July";
		break;

	case 8:
		line = "August";
		break;

	case 9:
		line = "September";
		break;

	case 10:
		line = "October";
		break;

	case 11:
		line = "November";
		break;

	case 12:
		line = "December";
	}

	return line;
}

//************************************************************************
//	cstrings to int 
//
// Recivies a string line 
// Converts to a number to send back
//************************************************************************

int diploma::stringToInt(string convert)
{
	// Convert string to cstring to number
	int number = atoi(convert.c_str());

	return number;
}


//************************************************************************
//	 Find Line Start
//
// Recivies an int and sends the gap size back
//************************************************************************

int diploma::findSetWidth(int lineSize)
{
	// Initilize variables
	int gap = 0;
	const int LINE_WIDTH = 60;

	// Fine starting width
	gap = (LINE_WIDTH - lineSize) / 2;

	return gap + lineSize;
}


//************************************************************************
//	Print 
//
// Uses variables in the object and manipulates them with object
// fuctions into strings
//************************************************************************

void diploma::print()
{
	// Initilize variables
	int length, startingWidth;

	// Write College
	length = college.length();
	startingWidth = findSetWidth(length);
	cout << setw(startingWidth) << college << endl;

	// Write Secound Line
	string line2 = "has conferred upon";			// Assign words to string
													// variable
	length = line2.length();						// Find Length of string
	startingWidth = findSetWidth(length);			// Find Start to print
	cout << setw(startingWidth) << line2 << endl;	// Print line

	// Write First Middle and Last Name
	string line3 = "";
	line3 = firstName + " " + middleName + " " + lastName;
	length = line3.length();
	startingWidth = findSetWidth(length);
	cout << setw(startingWidth) << line3 << endl;

	// Write Forth Line
	string line4 = "the degree of";
	length = line4.length();
	startingWidth = findSetWidth(length);
	cout << setw(startingWidth) << line4 << endl;

	// Write Degree
	string line5 = degreeToName(degree);
	length = line5.length();
	startingWidth = findSetWidth(length);
	cout << setw(startingWidth) << line5 << endl;\

	// Write Sixth Line
	string line6 = "with all right and privileges thereto pertaining";
	length = line6.length();
	startingWidth = findSetWidth(length);
	cout << setw(startingWidth) << line6 << endl;

	// Write Day and Month
	string line7 = "on this ";
	line7 = line7 + dayToWords(day) + " day of " + monthToWords(month);
	length = line7.length();
	startingWidth = findSetWidth(length);
	cout << setw(startingWidth) << line7 << endl;

	// Write Year
	string line8 = "in the year two-thousand " + yearToWords(year);
	length = line8.length();
	startingWidth = findSetWidth(length);
	cout << setw(startingWidth) << line8 << endl;
	cout << endl;
}
