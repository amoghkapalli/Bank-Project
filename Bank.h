#ifndef BANK_H
#define BANK_H
#include "Transaction.h"
#include "binary_search_tree.h"
#include <vector>
#include <queue>
#include <fstream>
#include <string>

using namespace std;
class Bank {
    public:
        Bank();
        void processTransactionFile(const string &fileName);
        void displayAllBankBalances();
        void processTransactions();
        void PrintActions();

    private:
        BinarySearchTree accounts;
        queue <Transaction> TransactionList;
};
#endif