#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

using namespace std;

class Transaction {


    public:
        //opening account
        Transaction(char Type, string lastName, string firstName, int id_);
        //deposit and withdraw
        Transaction(char Type, int id, int fundNumber, int amount);
        //transfer
        Transaction(char Type, int id, int fundNum, int amount, int destinationID, int destFundNum);
        //history of all funds
        Transaction(char Type, int ID);
        //history of one fund
        Transaction(int id, int fundNumber, char Type);
        char getType() const;
        string getFirstName() const;
        string getLastName() const;
        int getID() const;
        int getAmount() const;
        int getfundIndex() const;
        int getdestFundIndex() const;
        int getTransfer() const;
        void setAmount(int amount);
        
        

    private:
        char type_;
        int id_;
        int amount_;
        int destinationID_;
        string lastName_;
        string firstName_;
        int fundIndex_;
        int destFundIndex_;
};

#endif