// Transaction Source
// Author James Wetters

#include "transaction.h"

// Constructor
Transaction::Transaction()
{}

// Paramaterized Constructor
Transaction::Transaction(int tCustId, double tAmount, Date tDate)
{
	setCustomerID(tCustId);
	setTransactionAmount(tAmount);
	setDate(tDate);
}

//-----------------------------------------------------------------
//	Tax
//
// Returns a double for the amount of tax on the transaction
//-----------------------------------------------------------------
double Transaction::tax()
{
	return (transactionAmount * .06);
}

//-----------------------------------------------------------------
// Overloaded operator < less than
//-----------------------------------------------------------------
bool Transaction::operator< (Transaction& t)
{
	if (customerID < t.customerID)
		return true;
	if (customerID == t.customerID && date < t.date)
		return true;
	return false;
}
//-----------------------------------------------------------------
// Overloaded operator == equal to
//-----------------------------------------------------------------
bool Transaction::operator== (Transaction& t)
{
	if (customerID == t.customerID && date == t.date)
	{
		return true;
	}
	return false;
}

//Transaction Transaction::operator=(Transaction t)
//{
//	setCustomerID(t.getCustomerID());
//	setTransactionAmount(t.getTransactionAmount());
//	setDate(t.getDate());

//	return *this;
//}

