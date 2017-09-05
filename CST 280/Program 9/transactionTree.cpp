// Transaction Tree Source
// Author James Wetters

#include "transactionTree.h"
#include "date2.h"

// Constructor
TransactionTree::TransactionTree()
{
	// Variables
	int goodData = 0, convertedIData;
	double convertedDData;
	string iData, dData, date;

	ifstream inTransFile("transactions.txt");

	// Test File
	if (inTransFile.fail())
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	// Priming read
	getline(inTransFile, iData, ',');

	while (!inTransFile.eof())
	{
		// Convert string to int
		convertedIData = atoi(iData.c_str());

		getline(inTransFile, dData, ',');

		// Convert string to double
		convertedDData = atof(dData.c_str());

		// Read in date
		getline(inTransFile, date);

		// Create date
		Date D(date);

		// Create Transaction
		Transaction T(convertedIData, convertedDData, D);

		// Insert into Problem List
		theTransactionTree.insertNode(T);
		
		// Prime the next line
		getline(inTransFile, iData, ',');
	}

	inTransFile.close();
	inTransFile.clear();
}

//-----------------------------------------------------------------
//	Search
//
// Searches the transaction tree for a customer ID
//
// returns a copy of the original transaction and a bool
//-----------------------------------------------------------------
bool TransactionTree::search(Transaction &tSearch)
{
	if (theTransactionTree.searchNode(tSearch))
	{
		//cout << tSearch.getTransactionAmount() << endl;
		return true;
	}
	return false;
}
