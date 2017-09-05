// County Header File
// Author James Wetters

// Includes
#ifndef countyInfo_H
#define countyInfo_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

// Name Space
using namespace std;

class County
{

private:
	// Data members
	string fips;
	string population;
	string county;

public:
	// Constructor
	County();

	// Sets
	void setFips(string change)
	{
		fips = change;
	}
	void setPopulation(string change)
	{
		population = change;
	}
	void setCounty(string change)
	{
		county = change;
	}
	
	// Gets
	string getFips() const
	{
		return fips;
	}
	string getPopulation() const
	{
		return population;
	}
	string getCounty() const
	{
		return county;
	}

	// Functions Prototype

};
#endif