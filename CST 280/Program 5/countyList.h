// County Header File
// Author James Wetters

// Includes
#ifndef countyListInfo_H
#define countyListInfo_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "county.h"

// Name Space
using namespace std;

// Constants
const int MAXCOUNTYARRAY = 3300;


class CountyList
{

private:
	// Data members
	County allCounties[MAXCOUNTYARRAY];
	int numElems;

public:
	// Constructors
	CountyList();

	// Sets
	void setNumElems(int change)
	{
		numElems = change;
	}

	// Gets
	int getNumElems() const
	{
		return numElems;
	}

	// Functions Prototype
	void inputCountyFips();
	void inputCounty();

};
#endif