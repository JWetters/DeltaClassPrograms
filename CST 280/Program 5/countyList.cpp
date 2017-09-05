// CountyList Source File
// Author James Wetters

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "countyList.h"

// Namespace
using namespace std;


CountyList::CountyList()
{
	inputCountyFips();
	inputCounty();
}

//************************************************************************
//	Input Fips and Pop
//
// Pre: 
// Post:
//************************************************************************

void CountyList::inputCountyFips()
{
	ifstream inputFile("popCounty.txt");

	// Test File
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// variables
	string temp;
	numElems = 0;
	// Prime
	getline(inputFile, temp, ',');

	while (!inputFile.eof())
	{
		// Set fips
		allCounties[numElems].setFips(temp);

		// Get population and set it
		getline(inputFile, temp);
		allCounties[numElems].setPopulation(temp);

		// Get next fips
		getline(inputFile, temp, ',');
		numElems++;
	}

	inputFile.close();
}

//************************************************************************
//	Input County 
//
// Pre: 
// Post:
//************************************************************************

void CountyList::inputCounty()
{
	// Input County Name
	ifstream inputFile("fipsCounty.txt");

	// Test File
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}
	
	// Initilize variables
	string temp;
	int countyNum = 0;

	// Prime
	getline(inputFile, temp, ' ');

	// Read in fips codes check and set countys
	while (!inputFile.eof())
	{
		bool found = false;
		int count = 0;
		// Set fips
		// look for fips code
		while (!found && count < numElems)
		{
			// test for fips code
			if (temp == allCounties[count].getFips())
			{
				// If fips code found set county name
				getline(inputFile, temp);
				allCounties[countyNum].setCounty(temp);

				// If found set to true
				found = true;
			}

			// Check next fips code
			count++;
		}

		// If not found get next line
		if (found == false)
		{
			getline(inputFile, temp);
		}

		// Get next fips
		getline(inputFile, temp, ' ');

		// Reset
		count = 0;
		found = false;
	}

	inputFile.close();
}