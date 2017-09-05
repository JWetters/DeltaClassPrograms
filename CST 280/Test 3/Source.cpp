// Author James Wetters
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>


#include "binTreeType.h"
#include "dynStack.h"
#include "linkedList.h"

using namespace std;

// Prototypes 



int main()
{
	// Variables
	string temp;

	BinTreeType<string> theTree;
	DynStack<string> theStack;
	LinkedList<string> theList;

	ifstream inFile("allwords.txt");

	// Test File
	if (inFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// Build Tree--------------------------------------------

	// Priming read
	getline(inFile, temp);

	while (!inFile.eof())
	{
		theTree.insertNode(temp);

		// word
		getline(inFile, temp);
		
	}
	
	inFile.close();
	inFile.clear();

	// Search------------------------------------------------
	ifstream inFileSearch("mywords.txt");

	// Test File
	if (inFileSearch.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// Make Stack--------------------------------------------

	// Priming read
	getline(inFileSearch, temp);

	while (!inFileSearch.eof())
	{
		if (theTree.searchNode(temp))
		{
			theStack.push(temp);
		}

		// word
		getline(inFileSearch, temp);

	}

	inFileSearch.close();
	inFileSearch.clear();

	// Make list---------------------------------------------

	while (!theStack.isEmpty())
	{
		theList.insertNode(theStack.pop());
	}


	//reset list
	theList.resetList();

	// Write List--------------------------------------------

	while (!theList.atEnd())
	{
		cout << theList.getNextItem() << endl;
	}


	system("pause");
	return 0;
}
