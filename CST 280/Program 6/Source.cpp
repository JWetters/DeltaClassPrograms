// Program 6 Main
// This program creates a quiz consiting of math, triva
// and word scramble problems
// Author James Wetters
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "quiz.h"

using namespace std;

// Constants
const int MAXARRAYROWS = 40;
const int MAXARRAYCOLUMS = 2;

// Prototypes
void menu();
void fileInTrivia(string theArray[MAXARRAYROWS][MAXARRAYCOLUMS], int& numElems);
void fileInCompWords(string theArray[MAXARRAYROWS], int& numElems);

int main()
{
	// Get and report system clock time  
	time_t seconds;
	time(&seconds);

	// Set random number generator seed value to system clock 
	srand((unsigned int)seconds);

	// Menu
	menu();

	// Exit
	system("pause");
	return 0;
}

//************************************************************************
//	Menu 
//
// 
//************************************************************************
void menu()
{
	// Initilize variables
	string triviaArray[MAXARRAYROWS][MAXARRAYCOLUMS];
	string compWords[MAXARRAYROWS];
	int triviaGoodData = 0, compWordsGoodData = 0;
	char select = 'n';

	// Get Arrays
	fileInTrivia(triviaArray, triviaGoodData);
	fileInCompWords(compWords, compWordsGoodData);


	do
	{
		// New question HERE	
		cout << "Would you like to continue y or n." << endl;
		cin >> select;

		// If yes do a quiz
		if (select == 'y' || select == 'Y')
		{
			// Run a quiz
			Quiz a;
			a.print();
		}

	// Check to continue
	} while (select == 'y' || select == 'Y');
}

//************************************************************************
//	Trivia File In 
//
// 
//************************************************************************

void fileInTrivia(string theArray[MAXARRAYROWS][MAXARRAYCOLUMS], int& numElems)
{
	// Open File
	ifstream inputFile("trivia.txt");

	// Test File
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// variables
	string temp;
	int i = 0, goodData = 0;

	// Priming read
	getline(inputFile, temp);

	// Read in data file
	while (!inputFile.eof())
	{
		// First Read
		theArray[i][0];

		// Read in secound line
		getline(inputFile, temp);
		theArray[i][1] = temp;
		
		i++;			// Increase goodData by 1

		// Read in first line
		getline(inputFile, temp);
	}

	// Number of good data elems
	goodData = i;

	// Close file
	inputFile.close();
}

//************************************************************************
//	Word Comp File In 
//
// 
//************************************************************************

void fileInCompWords(string theArray[MAXARRAYROWS], int& numElems)
{
	// Open File
	ifstream inputFile("compWords.txt");

	// Test File
	if (inputFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// variables
	string temp;
	int i = 0, goodData = 0;

	// Priming read
	getline(inputFile, temp);

	// Read in data file
	while (!inputFile.eof())
	{
		// First Read
		theArray[i];

		// Read in secound line
		getline(inputFile, temp);
		theArray[i] = temp;

		i++;			// Increase goodData by 1

		// Read in first line
		getline(inputFile, temp);
	}

	// Number of good data elems
	goodData = i;

	// Close file
	inputFile.close();
}
