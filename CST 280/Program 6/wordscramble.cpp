// Word Scramble Problem
// Author James

#include "wordscramble.h"

using namespace std;

//************************************************************************
// Constructor
// 
//************************************************************************
WordScrambleProblem::WordScrambleProblem()
{
}


//************************************************************************
// Virtual Word Scramble Problem
// 
// Recives an array of words
// Finds one and returns 1 scrambled and 1 unscrambled
//************************************************************************
void WordScrambleProblem::generateQuestion()
{
	// Initilize
	string original = "monitor", temp, scramble = "";
	unsigned int i, jump;
	int newIndex[100];
	int goodData, select;

	/*
	// Generate 1 random number 0-GoodData
	// Find random trivia question
	select = rand() % goodData;
	// Set random comp words question and answer
	original = compWords[select];
	*/

	// Assign word to temp
	temp = original;

	for (i = 0; i < original.length(); i++)
	{
	// mark all as un modified
	newIndex[i] = -1;
	}

	// Step through word at random 
	for (i = 0; i < original.length(); i++)
	{
		// Find random letter in word
		jump = rand() % original.length();

		// Finds unscrambled letters of the word
		while (newIndex[jump] != -1)
		{
			// Increment letters by 1
			jump++;
			// If the jump is bigger than the number of letters start at 0
			if (jump >= original.length())
			{
				jump = 0;
			}
		}
		// Assign letter to a new spot
		newIndex[jump] = i;
	}

	// Assign letters to their spots in the word
	for (i = 0; i < original.length(); i++)
	{
		scramble += temp[newIndex[i]];
	}
	
	// Set the question and answer in quiz item
	setQuestion(scramble);
	setAnswer(original);
}