// Word Scramble Problem
// Author James Wetters

#include "trivia.h"

using namespace std;

//************************************************************************
// Constructor
// 
//************************************************************************
TriviaProblem::TriviaProblem()
{
}

//************************************************************************
// Virtual Generate Question Trivia Problem
// 
// Recives a 2d array of triva questions and answers
// Sends 1 trivia question back and 1 answer
//************************************************************************

void TriviaProblem::generateQuestion()
{
	// Initilize
	string  triviaQuestion, triviaAnswer;
	int goodData, select;

	/*
	// Generate 1 random number 0-GoodData
	// Find random trivia question
	select = rand() % goodData;
	// Set random trivia question and answer
	triviaQuestion = trivia[select][0]; 
	triviaAnswer = trivia[select][1];
	*/

	// Place holder
	triviaQuestion = "What continent has the fewest flowering plants ?";
	triviaAnswer = "Antarctica";

	// Set question and answer
	setQuestion(triviaQuestion);
	setAnswer(triviaAnswer);
}