// Quiz
// Author James Wetters
#ifndef QUIZ_H
#define QUIZ_H
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>

#include "quizItem.h"

using namespace std;

// Initilize constants
const int PMAXARRAY = 5;

class Quiz
{
private:
	// DATA MEMBERS
	QuizItem *pArray[PMAXARRAY];

public:
	Quiz();
	~Quiz();

	// MEMBER FUNCTIONS
	void print();
};
#endif 