#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;
#include "Fund.h"
class Account{
    public:
        Account();
        Account(string first, string last, int id);
        ~Account();
        int getID() const;
        string getFirstName();
        string getLastName();
        bool Deposit(int fundNum, int amount);
        bool Withdraw(int fundNum, int amount);
        bool Transfer(int numFund, int transferAmount, Account& toAc, int toFund);
        void printFullHistory();
        void FundHistory(int FundsID);
        string history();
        void recordTransaction(const Transaction &Tran, int fundNum);
	
        
    private:
        int id_;
        string firstN_;
        string lastN_;
        vector<Fund> funds;

};
#endif