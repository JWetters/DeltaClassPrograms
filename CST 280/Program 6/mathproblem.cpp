// Math Problem
// Author James Wetters
#define _CRT_SECURE_NO_WARNINGS

#include "mathproblem.h"

using namespace std;

//************************************************************************
// Constructor
// 
//************************************************************************
MathProblem::MathProblem()
{
}

//************************************************************************
// Virtual Generate Question Math Problem
// 
// Randomly selects an addition or multiplication problem
// Sends back problem in the form of a question and answer
//************************************************************************
void MathProblem::generateQuestion()
{
	int select;
	// Generate 1 random number 1-3
	select = rand() % 2;
	
	// If select == 1 then do addition problem otherwise do multiplication problem
	if (select == 1)
	{
		addition();
	}
	else
	{
		multiplication();
	}

}


//************************************************************************
// Addition
// 
// Creates an addition problem
//************************************************************************
void MathProblem::addition()
{
	// Initilize Variables
	string temp1, temp2, tempQuestion, tempAnswer;
	int answer;

	// Generate 1 random number 100-999
	 setFirstNum( rand() % 899 + 100);

	 // Generate 1 random number 100-999
	 setSecondNum(rand() % 899 + 100);

	 // Question
	 char numstr1[10], numstr2[10];
	 _itoa(getFirstNum(), numstr1, 10);
	 _itoa(getSecondNum(), numstr2, 10);
	 temp1 = numstr1;
	 temp2 = numstr2;

	 // Create question
	 tempQuestion = "Calculate " + temp1 + " + " + temp2;

	 // Set question
	 setQuestion(tempQuestion);

	 // Calculate answer
	 answer = getFirstNum() + getSecondNum();

	 // Set answer to temp string
	 _itoa(answer, numstr1, 10);
	 tempAnswer = numstr1;

	 // Set answer
	 setAnswer(tempAnswer);
}

//************************************************************************
// Multiplication
// 
// Creates a multiplication problem
//************************************************************************
void MathProblem::multiplication()
{
	// Initilize Variables
	string temp1, temp2, tempQuestion, tempAnswer;
	int answer;

	// Generate 1 random number 100-999
	setFirstNum(rand() % 89 + 10);

	// Generate 1 random number 100-999
	setSecondNum(rand() % 89 + 10);

	// Question
	char numstr1[10], numstr2[10];
	_itoa(getFirstNum(), numstr1, 10);
	_itoa(getSecondNum(), numstr2, 10);
	temp1 = numstr1;
	temp2 = numstr2;

	// Create question
	tempQuestion = "Calculate " + temp1 + " * " + temp2;

	// Set question
	setQuestion(tempQuestion);
	
	// Calculate answer
	answer = getFirstNum() * getSecondNum();

	// Set answer to temp string
	_itoa(answer, numstr1, 10);
	tempAnswer = numstr1;

	// Set answer
	setAnswer(tempAnswer);
}