// ProblemList Header
// Author James Wetters

#ifndef PROBLEMLIST_H
#define PROBLEMLIST_H

#include <iostream>
#include <string>
#include <fstream>
#include "orderLinkedList.h"
#include "problem.h"

using namespace std;

// Constants
const int MAXPARRAY = 30;

class ProblemList
{
private:
	OrderLinkedList<Problem> theProblemList;
	int problemID[MAXPARRAY];
	string problemName[MAXPARRAY];

public:
	// Problem List constructor
	ProblemList();
	// Problem List paramaterized constructor
	ProblemList(string theTextFileName);

	// Problem List Overloaded Oporators
	ProblemList ProblemList::operator+=(ProblemList pL);
	ProblemList ProblemList::operator-=(ProblemList pL);

	// Input Problem codes and descriptions
	void inputProblemListCodes();

	// Write the problem code description
	void ProblemList::writeProblemCode(int probNum);

	// Write Problem List
	void ProblemList::writeTop(int num);
	// Write Problem List
	void ProblemList::writeBottom(int num);

};
#endif

