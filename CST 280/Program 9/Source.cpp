// This Program is designed to find customer transactions
// and print out customer name, ID, date, amount, and tax
// Author James Wetters

#include <iostream>
#include <ostream>
#include <string>

#include "transactionTree.h"
#include "binTreeType.h"
#include "transaction.h"
#include "nameId.h"

using namespace std;

// Prototypes 
void menu();

int main()
{
	menu();

	system("pause");
	return 0;
}


void menu()
{
	// Initilize data structures
	TransactionTree theTree;
	NameID names;

	// Initilize variables
	int day, month, year;
	int id;
	double money;
	string custName;
	char select = 'N';

	// Menu
	do{
		cout << "Please enter day 'xx'" << endl;
		cin >> day;

		cout << "Please enter month 'xx'" << endl;
		cin >> month;

		cout << "Please enter year 'xxxx' " << endl;
		cin >> year;

		cout << "Please enter id 'xxxxx' " << endl;
		cin >> id;

		// Create Temp Date
		Date searchDate(month, day, year);

		// Create Temp Transaction
		Transaction trans;

		// Set date and id to tep Transaction
		trans.setDate(searchDate);
		trans.setCustomerID(id);

		
		//theTree.search(trans);
		// Search for the temp transaction and copy original to temp if found
		if (theTree.search(trans))
		{
			// Write Report to screen
			// Find name
			cout << names.findName(id) << "(Customer " << id << ")" << endl;
			cout << trans.getDate() << endl;
			cout << trans.getTransactionAmount() << "(Tax: $" << trans.tax() <<")" << endl;
		}
		else {
			// If ID or Date are not found transaction is not found
			cout << "Transaction Not Found" << endl;
		}

		// User enters to continue or exit
		cout << "To continue enter 'y' or 'Y' " << endl;
		cin >> select;

	} while (select == 'Y' || select == 'y');
}


