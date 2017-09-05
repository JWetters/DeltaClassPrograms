// Quiz
// Author James Wetters
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "quiz.h"
#include "mathproblem.h"
#include "wordscramble.h"
#include "trivia.h"

using namespace std;

// Constants
const int MAXARRAYROWS = 40;
const int MAXARRAYCOLUMS = 2;

//************************************************************************
// Constructor
// 
// Selects 5 random questions
//************************************************************************

Quiz::Quiz()
{
	// Initilize Variables
	int select = 0;

	for (int i = 0; i < PMAXARRAY; i++)
	{
		// Generate 1 random number 1-3
		select = rand() % 3 + 1;

		switch (select)
		{
		case 1:
			// Math Problem
			// Set pointer to a math problem
			pArray[i] = new MathProblem;
			// Generate a math problem
			pArray[i]->generateQuestion();
			break;

		case 2:
			// Word Scramble Problem
			// Set pointer to a word scramble Problem
			pArray[i] = new WordScrambleProblem;
			// Generate a word scramble problem
			pArray[i]->generateQuestion();
			break;

			//case 3:
		default:
			// Trivia Problem
			// Set pointer to a triva problem
			pArray[i] = new TriviaProblem;
			// Generate a triva problem
			pArray[i]->generateQuestion();
			break;
		}
	}
}


//************************************************************************
// Print quiz//
// 
// Prints all problems with pointers in the 5 question array
//************************************************************************

void Quiz::print()
{
	// Print header
	cout << "Questions" << setw(35) << "Answers" << endl;

	// Print trivia questions
	for (int i = 0; i < PMAXARRAY; ++i)
	{
		// Print problem number
		cout << i + 1 << ".  ";

		// Pint problem
		pArray[i]->print();
	}
}


//************************************************************************
// Quiz deconstructor
//
// 
//************************************************************************
Quiz::~Quiz()
{
	// Loop through pointer array
	for (int i = 0; i < PMAXARRAY; i++)
	{
		// Delete each pointer
		delete pArray[i];
	}
}
