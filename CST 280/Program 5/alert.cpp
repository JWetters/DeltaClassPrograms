#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include "alert.h"

// Default Constructor
alert::alert()
{
}

//************************************************************************
//	Print 
//
// 
//************************************************************************

void alert::print()
{
	cout << warningCode << " " << countyFipsCode << endl;
	cout << startDateAndTime << " - " << endDateAndTime << endl;
	cout << "Population Impact: " << endl;
}

