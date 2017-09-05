// Transaction Header
// Author James Wetters
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

#include "date2.h"

using namespace std;


class Transaction
{
private:
	// Variables
	int customerID;
	double transactionAmount;
	Date date;

public:
	// Gets
	int getCustomerID()
	{
		return customerID;
	}
	double getTransactionAmount()
	{
		return transactionAmount;
	}
	Date getDate()
	{
		return date;
	}

	// Sets
	void setCustomerID(int change)
	{
		customerID = change;
	}
	void setTransactionAmount(double change)
	{
		transactionAmount = change;
	}
	void setDate(Date change)
	{
		date = change;
	}

	// Problem constructor
	Transaction();
	// Problem paramaterized constructor
	Transaction(int tCustId, double tAmount, Date tDate);

	// Problem Overloaded Operators
	bool Transaction::operator< (Transaction& p);
	bool Transaction::operator== (Transaction& p);
	//Transaction Transaction::operator=(Transaction t);

	double tax();
};
#endif