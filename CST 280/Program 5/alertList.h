// Alert Header File
// Author James Wetters

// Includes
#ifndef alertListInfo_H
#define alertListInfo_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "alert.h"
#include "county.h"
#include "countyList.h"

// Name Space
using namespace std;

// Constants
const int ALERTMAXARRAY = 10;
const int MAXWEATHERARRAYCOL = 2;
const int MAXWEATHERARRAYROW = 25;
const int MAXNATIONALARRYCOL = 2;
const int MAXNATIONALARRYCROW = 10;

class alertList
{

private:
	// Data members
	int numElems = 0;

	// Array of Alerts
	string weatherWarningList[MAXWEATHERARRAYCOL][MAXWEATHERARRAYROW];
	string nationalWarningList[MAXNATIONALARRYCOL][MAXNATIONALARRYCROW];
	alert alerts[ALERTMAXARRAY];

public:
	// Constructors
	alertList();
	
	// Sets
	

	// Gets


	// Functions Prototype
	void inputAlerts();
	void inputWarningList();
	void sort();
	void print();
	void warning(string test);
	string date(string test);
	string writeCountyState(string test);
	string writePopulation(string test);

};
#endif