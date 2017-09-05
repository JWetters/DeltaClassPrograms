// This program manages a list of computer problems and sorts
// each problem based on criticality
// Author James Wetters

#include <iostream>
#include <string>
#include <iomanip>

#include "ProblemList.h"

using namespace std;

int main()
{
	// Create problem lists
	ProblemList problems("problems.txt");
	ProblemList newProblems("newProblems.txt");
	ProblemList solvedProblems("resolvedProblems.txt");

	// Add new problems to the list
	problems += newProblems;
	// Delete old problems from the list
	problems -= solvedProblems;

	// Write top 25 problems
	problems.writeTop(25);
	// Write bottome 25 problems
	problems.writeBottom(25);

	system("pause");
	return 0;
}