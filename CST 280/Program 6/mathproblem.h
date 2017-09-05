// Word Scramble
// Author James Wetters
#ifndef MATHPROBLEM_H
#define MATHPROBLEM_H
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include "quizItem.h"

using namespace std;

class MathProblem : public QuizItem
{
private:
	// DATA MEMBERS
	int firstNum, secoundNum;

public:
	// SETS
	void setFirstNum(int change)
	{
		firstNum = change;
	}

	void setSecondNum(int change)
	{
		secoundNum = change;
	}

	// GETS
	int getFirstNum() const
	{
		return firstNum;
	}

	int getSecondNum() const
	{
		return secoundNum;
	}

	// MEMBER FUNCTIONS
	MathProblem();
	void generateQuestion();
	void addition();
	void multiplication();
};
#endif 