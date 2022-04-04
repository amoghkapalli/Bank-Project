#include "Account.h"
#include "Fund.h"
#include <iostream>
#include <string>
using namespace std;
Account::Account()
{
	firstN_ = "";
	lastN_ = "";
	id_ = -1;
	funds.push_back(Fund("Money Market"));
	funds.push_back(Fund("Prime Money Market"));
	funds.push_back(Fund("Long-Term Bond"));
	funds.push_back(Fund("Short-Term Bond"));
	funds.push_back(Fund("500 Index Fund"));
	funds.push_back(Fund("Capital Value Fund"));
	funds.push_back(Fund("Growth Equity Fund"));
	funds.push_back(Fund("Growth Index Fund"));

}
Account::Account(string first, string last, int id) {
    this->id_ = id;
    this->firstN_ = first;
    this->lastN_ = last;
    funds.push_back(Fund("Money Market"));
    funds.push_back(Fund("Prime Money Market"));
    funds.push_back(Fund("Long-Term Bond"));
    funds.push_back(Fund("Short-Term Bond"));
    funds.push_back(Fund( "500 Index Fund"));
    funds.push_back(Fund("Capital Value Fund"));
    funds.push_back(Fund("Growth Equity Fund"));
	funds.push_back(Fund("Growth Index Fund"));

    
}
Account::~Account() = default;
int Account::getID() const{ 
    return id_; 
}
string Account::getFirstName() {
    return firstN_;
}
string Account::getLastName() {
    return lastN_;
}

bool Account::Deposit(int fundNum, int amount){
    string depositHistory = "D " + to_string(id_) + " " + to_string(fundNum) + " " + to_string(amount);
    if(fundNum>=0 && fundNum<=9 && amount>=0){
        funds[fundNum].Add(amount);
        funds[fundNum].addHistory(depositHistory);
        return true;
    }
    return false;
}
bool Account::Withdraw(int fundNum, int amount){
    string withdrawHistory = "W " + to_string(id_) + " " + to_string(fundNum) + " " + to_string(amount);
    if (funds[fundNum].isWithdrawalEnough(amount)) {
        funds[fundNum].Remove(amount);
        funds[fundNum].addHistory(withdrawHistory);
        return true;
    } else if (fundNum >= 0 && fundNum <= 3) {
        if (fundNum == 0) {
            if (funds[fundNum].getValue() + funds[1].getValue() >= amount) {
                int Leftover = abs(funds[fundNum].getValue()-amount);
                funds[0].Remove(funds[0].getValue());
                funds[1].Remove(Leftover);
                string withdrawHistoryTransfer = "W " + to_string(id_) + to_string(fundNum) + " " + to_string(amount);   
                string withdrawHistoryTransfer2 = "W " + to_string(id_) + to_string(fundNum+1) + " " + to_string(Leftover);                           
                funds[fundNum].addHistory(withdrawHistory);
                funds[1].addHistory(withdrawHistoryTransfer2);
                //Check = true;
                return true;
            }
        } else if (fundNum == 1) {
            if (funds[fundNum].getValue() + funds[0].getValue() >= amount) {
                int Leftover = abs(funds[fundNum].getValue()-amount);
                funds[fundNum].Remove(funds[fundNum].getValue());
                funds[0].Remove(Leftover);
                string withdrawHistoryTransfer = "W " + to_string(id_) + to_string(fundNum) + " " + to_string(amount);   
                string withdrawHistoryTransfer2 = "W " + to_string(id_) + to_string(fundNum-1) + " " + to_string(Leftover);                           
                funds[fundNum].addHistory(withdrawHistory);
                funds[0].addHistory(withdrawHistoryTransfer2);
                //Check = true;
                return true;
            }
        } else if (fundNum == 2) {
            if (funds[fundNum].getValue() + funds[3].getValue() >= amount) {
                int Leftover = abs(funds[fundNum].getValue()-amount);
                funds[2].Remove(funds[0].getValue());
                funds[3].Remove(Leftover);
                string withdrawHistoryTransfer = "W " + to_string(id_) + to_string(fundNum) + " " + to_string(amount);   
                string withdrawHistoryTransfer2 = "W " + to_string(id_) + to_string(fundNum+1) + " " + to_string(Leftover);                           
                funds[fundNum].addHistory(withdrawHistory);
                funds[3].addHistory(withdrawHistoryTransfer2);
                //Check = true;
                return true;
            }
        } else if (fundNum == 3) {
            if (funds[fundNum].getValue() + funds[2].getValue() >= amount) {
                int Leftover = abs(funds[fundNum].getValue()-amount);
                funds[fundNum].Remove(funds[fundNum].getValue());
                funds[2].Remove(Leftover);
                string withdrawHistoryTransfer = "W " + to_string(id_) + to_string(fundNum) + " " + to_string(amount);   
                string withdrawHistoryTransfer2 = "W " + to_string(id_) + to_string(fundNum-1) + " " + to_string(Leftover);                           
                funds[fundNum].addHistory(withdrawHistory);
                funds[2].addHistory(withdrawHistoryTransfer2);
                //Check = true;
                return true;
            }
        }
        else{
            cout << "ERROR: Insufficient fund to withdraw $" << amount << ". This is even with combined funds" << endl;
            return false;
        }
    }
    return false;
}
bool Account::Transfer(int fund, int amount, Account& toAc, int destFund){
    if ((fund < 0 || fund > 9) || (destFund < 0 || destFund > 9))
	{
		cerr << "ERROR: Transfer cannot be made, invalid fund ID inputted" << endl;
		return false;
	}
    if(amount<0){
        cerr<<"ERROR: Invalid Amount entered. Need to enter a positive transfer amount."<<endl;
        return false;
    }
    string transferHistory = "T " + to_string(id_) + " " + to_string(fund) + " " + to_string(amount) + " " +
		to_string(toAc.getID()) + " " + to_string(destFund);
    if(funds[fund].getValue()>=amount){
        funds[fund].Remove(amount);
        toAc.funds[destFund].Add(amount);
        funds[fund].addHistory(transferHistory);
        toAc.funds[destFund].addHistory(transferHistory);
        return true;
    }
    else{
        cerr << "ERROR: Transfer cannot be made, not enough money in account to transfer" << endl;
        return false;
    }
}
void Account::printFullHistory() {
    cout << "Transaction History for: " << firstN_ << " " << lastN_ << " by fund." <<endl;
    for(int i=0; i < funds.size(); i++){
        funds[i].printFundHistory();
    }
    
}
void Account::FundHistory(int numFund) 
{
	cout << "Transaction History for: " << firstN_<< " " << lastN_ << " " << funds[numFund].getName() << endl;
	//cout << funds[numFund].getName() << ": $" << funds[numFund].getAmount() << endl;
	funds[numFund].printFundHistory();
}


