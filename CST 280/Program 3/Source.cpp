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

// Prototypes
void fileInput(int& goodData, diploma d[]);

// Constant variables
const int MAXARRAY = 10;

int main()
{
	// Initilize arrays
	diploma students[MAXARRAY];

	// Initilize global variables
	int numElems = 0;

	// Input student info
	fileInput(numElems, students);

	// Print all grad documents
	for (int i = 0; i < numElems; i++)
	{
		students[i].print();
	}

	system("pause");
	return 0;
}


//************************************************************************
//	 File Input
//
// Inputs from a text document
//************************************************************************

void fileInput(int& goodData, diploma d[])
{
	// Initilize variables
	goodData = 0;

	// Input
	ifstream inputFile("gradData.txt");

	// Test file, will close if file fails to open
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// Read in loop
	for (int i = 0; !inputFile.eof(); i++)
	{
		// Initilize variables
		string temp;

		// Get College
		getline(inputFile, temp, ',');
		d[i].setCollege(temp);

		// Get Last Name
		getline(inputFile, temp, ',');
		d[i].setLastName(temp);

		// Get First Name
		getline(inputFile, temp, ',');
		d[i].setFirstName(temp);

		// Get Middle Name
		getline(inputFile, temp, ',');
		d[i].setMiddleName(temp);

		// Get Degree
		getline(inputFile, temp, ',');
		d[i].setDegree(temp);

		// Get Month
		getline(inputFile, temp, '/');
		d[i].setMonth(temp);

		// Get Day
		getline(inputFile, temp, '/');
		d[i].setDay(temp);

		// Get Year
		getline(inputFile, temp);
		d[i].setYear(temp);

		goodData = i;
	}

	// Close file
	inputFile.close();
}