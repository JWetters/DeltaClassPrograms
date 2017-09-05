// Problem List cpp
// Author James Wetters

#include "ProblemList.h"


// Constructor
ProblemList::ProblemList()
{}

// Paramaterized Constructor
ProblemList::ProblemList(string theTextFileName)
{
	// Open File
	ifstream inputFile(theTextFileName.c_str());

	// Test File
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// variables
	int pCTempInt, critTempInt;
	string pCTemp, critTemp, dTemp, contTemp;

	// Priming read
	getline(inputFile, pCTemp, ',');

	// Read in data file
	while (!inputFile.eof())
	{
		// Read in data
		getline(inputFile, critTemp, ',');
		getline(inputFile, dTemp, ',');
		getline(inputFile, contTemp);

		// Convert string to int
		pCTempInt = atoi(pCTemp.c_str());
		critTempInt = atoi(critTemp.c_str());

		// Create Temp Problem Object
		Problem p(pCTempInt, critTempInt, dTemp, contTemp);

		// Insert into Problem List
		theProblemList.insertNode(p);

		// Prime the next line
		getline(inputFile, pCTemp, ',');
	}


	// Close file
	inputFile.close();
	inputFile.clear();

	// List Of Problems
	inputProblemListCodes();

}

//-----------------------------------------------------------------
//	Operator +=
//
// Sets += operator to add problem lists together
//-----------------------------------------------------------------
ProblemList ProblemList::operator+=(ProblemList pL)
{
	pL.theProblemList.resetList();

	while (!pL.theProblemList.atEnd())
	{
		Problem temp = pL.theProblemList.getNextItem();

		theProblemList.insertNode(temp);
	}

	return *this;
}

//-----------------------------------------------------------------
//	Operator -=
//
// Sets -= operator to subtract problem lists from each other
//-----------------------------------------------------------------
ProblemList ProblemList::operator-=(ProblemList pL)
{
	pL.theProblemList.resetList();

	while (!pL.theProblemList.atEnd())
	{
		Problem temp = pL.theProblemList.getNextItem();

		theProblemList.deleteNode(temp);
	}
	return *this;
}

//-----------------------------------------------------------------
//	Input Problem List Codes
//
// Reads in problem list codes and descriptions and sets them to 
// parallel arrays
//-----------------------------------------------------------------
void ProblemList::inputProblemListCodes()
{
	// Open File
	ifstream inFile("problemsList.txt");

	// Test File
	
	if (inFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}
	
	// variables
	int iDTemp, numElems = 0;
	string desTemp, iDStrTemp;

	// Priming read
	getline(inFile, iDStrTemp, '-');

	// Read in data file
	while (!inFile.eof())
	{
		// Convert id from string to int
		iDTemp = atoi(iDStrTemp.c_str());

		// Set iD to a spot in the array
		problemID[numElems] = iDTemp;

		// Get the description
		getline(inFile, desTemp);

		problemName[numElems] = desTemp;

		numElems++;

		// Get next line
		getline(inFile, iDStrTemp, '-');
	}


	// Close file
	inFile.close();
	inFile.clear();
}

//-----------------------------------------------------------------
//	Write Problem Code
//
// Recives a problem number as an int 
// 
// Writes problem description
//-----------------------------------------------------------------
void ProblemList::writeProblemCode(int probNum)
{
	// Initilize variables
	int index = 0;
	bool found = false;

	// While id not found and not greater than the array search
	while (found != true && index < MAXPARRAY)
	{
		// If prolem is found get out
		if (problemID[index] == probNum)
		{
			found = true;
		}

		index++;
	}

	// If problem is found write the problem description
	if (found == true)
	{
		cout << problemName[index] << "\n";
	}

}

//-----------------------------------------------------------------
//	Write Top
//
// Recives the number of objects to display 
// 
// Writes number of objects from the top
//-----------------------------------------------------------------
void ProblemList::writeTop(int num)
{
	// Write header
	cout << "Priorty" << "   " << "Submitted" << "  " << "By" << "                     "
		<< "Description" << endl;

	// Reset the problem list from the beginning
	theProblemList.resetList();

	// Write number of objects
	for (int i = 0; i < num; i++)
	{
		// Initilize variables
		Problem p = theProblemList.getNextItem();
		int probNumCode = p.getProblemCode();

		// Write the object
		cout << p.getCritLevel() << "         " << p.getDate() <<
			"  " << p.getContact() << "         ";
		// Write the problem description
		writeProblemCode(probNumCode);
	}

}

//-----------------------------------------------------------------
//	Write Bottom
//
// Recives the number of objects to display 
// 
// Writes number of objects from the bottom
//-----------------------------------------------------------------
void ProblemList::writeBottom(int num)
{
	// Initilize variables
	int numFromEnd;
	numFromEnd = theProblemList.getLength() - num;

	// Write header
	cout << "Priorty" << "   " << "Submitted" << "  " << "By" << "                     "
		<< "Description" << endl;

	// Reset the problem list from the beginning
	theProblemList.resetList();

	// Count back from the end
	for (int i = 0; i < numFromEnd; i++)
	{
		Problem p = theProblemList.getNextItem();
	}

	// Write number of objects
	for (int i = 0; i < num; i++)
	{
		// Initilize variables
		Problem p = theProblemList.getNextItem();
		int probNumCode = p.getProblemCode();

		// Write the object
		cout << p.getCritLevel() << "         " << p.getDate() <<
			"  " << p.getContact() << "         ";
		// Write the problem description
		writeProblemCode(probNumCode);
	}


}