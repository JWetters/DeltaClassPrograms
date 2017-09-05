// Transaction Tree Header
// Author James Wetters

#ifndef TRANSACTIONTREE_H
#define TRANSACTIONTREE_H

#include <iostream>
#include <string>
#include <fstream>
#include "binTreeType.h"
#include "transaction.h"

using namespace std;

class TransactionTree
{
private:
	BinTreeType<Transaction> theTransactionTree;

public:
	// Transaction Tree constructor
	TransactionTree();

	// Search Transaction Tree
	bool search(Transaction &tSearch);
};
#endif

