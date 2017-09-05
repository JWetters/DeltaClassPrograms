// Quiz Item
// Author James Wetters
#ifndef QUIZITEM_H
#define QUIZITEM_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> 
#include <ctime> 

using namespace std;

class QuizItem
{
private:
	// DATA MEMBERS
	string question;
	string answer;

public:
	// SETS
	void setQuestion(string change)
	{
		question = change;
	}

	void setAnswer(string change)
	{
		answer = change;
	}

	// GETS
	string getQuestion() const
	{
		return question;
	}

	string getAnswer() const
	{
		return answer;
	}

	// MEMBER FUNCTIONS
	virtual void generateQuestion() = 0;
	void print();
	
};
#endif 