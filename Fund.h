#ifndef FUND_H
#define FUND_H
#include <vector>
#include<string>
#include<iostream>
#include<sstream>
#include "Transaction.h"
using namespace std;
class Fund
{

    public:
        Fund();
        Fund(string fundName);
        ~Fund();
        bool Add(int amount);
        bool Remove(int amount);
        string getName() const;
        int getValue()const;
        bool setAmount(int amount);
        bool setName(string n);
        void addHistory(string input);
        void displayHistory();
        void printFundHistory() const;
        bool isWithdrawalEnough(int Amount) const;

    private:
        int value_;
        string name_;
        vector<string> history;


};
#endif // FUND_H