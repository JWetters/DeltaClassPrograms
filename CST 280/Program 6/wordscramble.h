// Word Scramble Problem
// Author James Wetters
#ifndef WORDSCRAMBLEPROBLEM_H
#define WORDSCRAMBLEPROBLEM_H
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include "quizItem.h"

using namespace std;

class WordScrambleProblem : public QuizItem
{
private:
	// DATA MEMBERS
	string original;
	
public:
	// SETS
	void setWord(string change)
	{
		original = change;
	}

	// GETS
	string getWord() const
	{
		return original;
	}

	// MEMBER FUNCTIONS
	WordScrambleProblem();
	void generateQuestion();
	
};
#endif 