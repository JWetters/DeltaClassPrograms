// This program sorts graphics cards
// Author James Wetters

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 
#include <ctime>
#include "GPU.h"
using namespace std;

// Prototypes
void printMenu();
int deleteMember(graphicsCard theArray[], int size);
void sortAscending(graphicsCard theArray[], int size);
void sortDescending(graphicsCard theArray[], int size);
void randomSort(graphicsCard theArray[], int size);
void printResults(graphicsCard theArray[], int size);


// Constant variables
const int MAXARRAY = 15;

int main()
{
	// Initilize values
	char selection = 'n';
	graphicsCard gpu[MAXARRAY];
	int i = 0;
	int goodData = 0;			//number of objects with good data in the array
	
	// Input
	ifstream inputFile("gpu.txt");
	while (!inputFile.eof())
	{
		// Initilized place holder variables
		int x = 0;		// X holds an int
		string y;		// Y holds a string
		double z = 0;	// Z holds a double

		// Input ID
		inputFile >> x;
		gpu[i].setId(x);

		// Input card name
		inputFile >> y;
		gpu[i].setCardName(y);

		// Input Cores
		inputFile >> x;
		gpu[i].setCores(x);

		// Input Clock
		inputFile >> x;
		gpu[i].setClock(x);

		// Input Memory
		inputFile >> x;
		gpu[i].setMemory(x);

		// Input Fill Rate
		inputFile >> z;
		gpu[i].setFillRate(z);
		
		i++;
	}

	// Number of objects with data
	goodData = i;

	//do while Menu
	do
	{
		// Initilized menue variable
		int option = 6;

		// Menu is printed to screen
		printMenu();

		// User Menus selction
		cin >> option;

		switch (option)
		{
		case 1:
			// Add member
			gpu[goodData].addGraphicsCard(goodData);
			break;

		case 2:
			// Delete member
			goodData = deleteMember(gpu, goodData);
		break;

		case 3:
			// Sort the list in ascending order
			sortAscending(gpu, goodData);
		break;

		case 4:
			// Sort the list in descending order
			sortDescending(gpu, goodData);
			break;
		
		case 5:
			// Random Sort
			randomSort(gpu, goodData);
			break;

		case 6:
			// Leave menu
			break;
		}

		// Prompt user to continue
		cout << "Would you like to continue? Y or N" << endl;
		cin >> selection;
	} while (selection == 'y' || selection == 'Y');

	// Write information to a file
	printResults(gpu, goodData);
	
	system("pause");
	return 0;
}



//************************************************************************
//	 Print Menu
//
// Prints the menu to the screen
//************************************************************************
void printMenu()
{
	cout << "Graphics card database menu. " << endl;
	cout << "To add a graphics card to the database enter 1." << endl;
	cout << "To delete a graphics card to the database enter 2." << endl;
	cout << "To sort the database enter in ascending order of cores 3." << endl;
	cout << "To sort the database enter in descending order of cores 4." << endl;
	cout << "To randomize the graphics card database enter 5." << endl;
	cout << "To exit enter 6." << endl;
}


//************************************************************************
//	Delete member
//
// Deletes member
//************************************************************************
int deleteMember(graphicsCard theArray[], int size)
{
	// Initilize variables
	int id;
	int index = 0;
	int found = -1;		// Assume item will not be found 
	int compare;

	// Propt user for ID# for deletion
	cout << "Enter ID#" << endl;
	// User enters ID of member to be deleted
	cin >> id;

	// Initilize compare
	compare = theArray[0].getId();

	// Step through the array of Graphics cards
	// comparing the ID number of each to find the
	// array index to be moved
	while (index < size && id != compare)
	{
		index++;
		compare = theArray[index].getId();
	}

	// Write over deleted array member with
	// the last item in the array
	if (index < size)
	{
		found = index;
		theArray[found] = theArray[size - 1];            // Move last list item to overwrite target 
		size = size - 1;
	}

	return size;
}

//************************************************************************
//	Sort Ascending 
//
// Sort Graphics card array in ascending order
//************************************************************************
void sortAscending(graphicsCard theArray[], int size)
{
	// Initilize temperary variables
	int end;
	graphicsCard temp;


	for (end = size - 1; end >= 0; end--)
	{
		for (int count = 0; count < end; count++)
		{
			if (theArray[count].getId() > theArray[count + 1].getId())
			{
				// Swap array indexes
				temp = theArray[count];
				theArray[count] = theArray[count + 1];
				theArray[count + 1] = temp;
			}
		}
	}
}


//************************************************************************
//	Sort Descending 
//
// Sort Graphics card array in ascending order
//************************************************************************
void sortDescending(graphicsCard theArray[], int size)
{
	// Initilize temperary variables
	int end;
	graphicsCard temp;

	for (end = size - 1; end >= 0; end--)
	{
		for (int count = 0; count < end; count++)
		{
			if (theArray[count].getId() < theArray[count + 1].getId())
			{
				// Swap array indexes
				temp = theArray[count];
				theArray[count] = theArray[count + 1];
				theArray[count + 1] = temp;
			}
		}
	}
}


//************************************************************************
//	Random Sort
//
// Sort Graphics card array in ascending order
//************************************************************************

void randomSort(graphicsCard theArray[], int size)
{
	// Initilize variables
	graphicsCard temp;
	srand(time(0));		// Seed random number
	// 
	for (int i = 0; i < size; i++)
	{
		// Set random number equal to index
		int index = rand() % size;

		// Swap objects array positions
		temp = theArray[i];
		theArray[i] = theArray[index];
		theArray[index] = temp;
	}
}

//************************************************************************
//	Print Results
//
// Sort Graphics card array in ascending order
//************************************************************************
void printResults(graphicsCard theArray[], int size)
{
	// Initilize file
	ofstream outfile;
	outfile.open("gpu2.txt");

	// Write information to the txt file
	for (int i = 0; i < size; i++)
	{
		outfile << theArray[i].getId() << " ";
		outfile << theArray[i].getCardName() << " ";
		outfile << theArray[i].getCores() << " ";
		outfile << theArray[i].getClock() << " ";
		outfile << theArray[i].getMemory() << " ";
		outfile << theArray[i].getFillRate() << endl;
	}

	// Close file
	outfile.close();
}
