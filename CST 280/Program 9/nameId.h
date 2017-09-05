// NameID Header
// Author James Wetters
#ifndef NAMEID_H
#define NAMEID_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Const
const int MAXCUSTOMERARRAY = 10010;

class NameID
{
private:
	// Variables
	int	ID[MAXCUSTOMERARRAY];
	string	name[MAXCUSTOMERARRAY];
	int		goodData;

public:

	// Problem constructor
	NameID();

	// Search names by customer ID
	string findName(int custID);
};
#endif