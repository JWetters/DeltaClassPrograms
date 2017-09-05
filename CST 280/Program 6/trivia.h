// Word Scramble Problem
// Author James Wetters
#ifndef TRIVIAPROBLEM_H
#define TRIVIAPROBLEM_H
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include "quizItem.h"

using namespace std;

// Constants
const int MAXARRAY = 10;

class TriviaProblem : public QuizItem
{
private:
	// DATA MEMBERS
	string triviaQuestion, triviaAnswer;

public:
	// SETS
	void setTriviaQuestion(string change)
	{
		triviaQuestion = change;
	}

	void setTriviaAnswer(string change)
	{
		triviaAnswer = change;
	}

	// GETS
	string getTriviaQuestion() const
	{
		return triviaQuestion;
	}

	string getTriviaAnswer() const
	{
		return triviaAnswer;
	}

	// MEMBER FUNCTIONS
	TriviaProblem();
	void generateQuestion();

};
#endif