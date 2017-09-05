// Quiz Item 
// Author James Wetters
#include "quizItem.h"

//************************************************************************
// Constructor
// 
//************************************************************************

void QuizItem::print()
{
	cout << setw(20) << left << question;
	cout << setw(20) << right << answer << endl;
}
