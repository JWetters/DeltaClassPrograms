#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include "alertList.h"
#include "alert.h"
#include "countyList.h"
#include "county.h"

// Default Constructor
alertList::alertList()
{
	// Reads in alerts to array
	inputAlerts();
	// Reads data in to the warning list
	inputWarningList();
	// Reads data in to the county
	// Reads data in to the popCounty
	CountyList countyArray;
}



//************************************************************************
//	Input File 
//
// Pre: Objects come in as an array, alerts come in as a text file
// Post: 
//************************************************************************

// Input Alerts
void alertList::inputAlerts()
{
	// Open File
	ifstream inputFile("alerts.txt");

	// Test File
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// variables
	string temp;

	// Priming read
	getline(inputFile, temp, ',');

	// Read in data file
	while (!inputFile.eof())
	{
		// Firts Read
		alerts[numElems].setCountyFipsCode(temp);

		// Read in secound line
		getline(inputFile, temp, ',');
		alerts[numElems].setStartDateAndTime(temp);

		// Read in third line
		getline(inputFile, temp, ',');
		alerts[numElems].setEndDateAndTime(temp);

		// Read in forth line
		getline(inputFile, temp);
		alerts[numElems].setWarningCode(temp);

		numElems++;			// Increase goodData by 1

		// Read in first line
		getline(inputFile, temp, ',');

	}

	// Close file
	inputFile.close();
}

//************************************************************************
//	Input Warning List File 
//
// Pre: Objects come in as an array, alerts come in as a text file
// Post: 
//************************************************************************

// Input Warnings
void alertList::inputWarningList()
{
	// Open File
	ifstream inputFile("warningList.txt");

	// Test File
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// variables
	string temp;

	// skip 3 lines
	getline(inputFile, temp);
	getline(inputFile, temp);
	getline(inputFile, temp);

	// Read in weather warnings
	for (int i = 0; i < 23; i++)
	{
		// Initilize variables
		string subTemp;

		// Substring the last 2 characters
		getline(inputFile, temp, ' ');
		// Assign characters to a temp string
		subTemp = temp.substr(1, 2);
		// Assign string to the warning list
		weatherWarningList[0][i] = subTemp;
		
		// Get next line for processing
		getline(inputFile, temp);
		weatherWarningList[1][i] = temp;

	}

	// Skip 8 lines
	for (int i = 0; i < 8; i++)
	{
		getline(inputFile, temp);
	}

	// Read in security warning
	for (int i = 0; i < 5; i++)
	{
		// Read until space
		getline(inputFile, temp, ' ');
		// Assign color code to col 0
		nationalWarningList[0][i] = temp;

		// Read until end of the line
		getline(inputFile, temp);
		// Assign warning message to col 1
		nationalWarningList[1][i] = temp;
	}

	// Close file
	inputFile.close();
}


//************************************************************************
//	Sort 
//
// Pre: Objects come in as an array 
// Post: Objects sorted based on security
// warnings first than weather warnings in the order of severity; warnings,
// watches, and advisories. Objects leave sorted based on serverity.
//************************************************************************

void alertList::sort()
{

}


//************************************************************************
//	Print 
//
// Pre: 
// Post:
//************************************************************************

void alertList::print()
{
	// Write each warning
	for (int i = 0; i < numElems; i++)
	{
		// Print Warning
		warning(alerts[i].getWarningCode());
		
		// Print City and state
		cout << "County, State" << endl;

		// Print start date
		cout << alerts[i].getStartDateAndTime() << " - ";

		// Print end date
		cout << alerts[i].getEndDateAndTime() << endl;

		// Print population impact
		cout << "Population Impact: xxx,xxx" << "\n" << endl;
		

	}
}

//************************************************************************
//	Warning 
//
// Pre: waring string comes in
// Post: warning writen to console comes out
//************************************************************************
void alertList::warning(string test)
{
	// Initilize variables
	string temp;
	bool found = false;
	int search = 0;

	// Test for security warning
	for (int i = 0; i < 5; i++)
	{
		if (test == nationalWarningList[0][i])
		{
			cout << nationalWarningList[1][i] << " ";
			found = true;
		}
	
	}

	// If found equals true then leave the fuction
	// otherwise find the weather advisery and severity
	if (found)
	{
		return;
	}
	else
	{
		//Initilize
		string compare;
		compare = test.substr(1, 2);
		// Test for weather warning
		for (int search = 0; search < 23; search++)
		{
			if (compare == weatherWarningList[0][search])
			{
				cout << weatherWarningList[1][search] << " ";
			}
		}

		compare = test.substr(0, 1);
		string W = "W", A = "A", Y = "Y";

		// Find severity
		if (compare == W)
		{
			cout << "Warning for ";
		}
		else if (compare == A)
		{
			cout << "Watch for ";
		}
		else
		{
			cout << "Advisory for ";
		}
	}
}

//************************************************************************
//	Format Date 
//
// Pre: 
// Post:
//************************************************************************

string alertListdate(string test)
{
	return test;
}


//************************************************************************
//	Write County and State 
//
// Pre: 
// Post:
//************************************************************************

string alertList::writeCountyState(string test)
{
	return test;
}

//************************************************************************
//	Write County and State 
//
// Pre: 
// Post:
//************************************************************************

string alertList::writePopulation(string test)
{
	return test;
}