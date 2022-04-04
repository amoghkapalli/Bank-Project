#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(char Type, string firstName, string lastName, int id){
    type_=Type;
    lastName_=lastName;
    firstName_=firstName;
    id_=id;

}
Transaction::Transaction(char Type, int id, int fundNumber, int amount){
    type_=Type;
    id_=id;
    setAmount(amount);
    fundIndex_=fundNumber;
    //cout<<id_<< " " << fundIndex_<< " " << amount_ << endl;

}
Transaction::Transaction(int id, int fundNumber, char Type){
    type_=Type;
    id_=id;
    fundIndex_=fundNumber;
}
Transaction::Transaction(char Type, int id, int fundNum, int destinationID, int destFundNum, int amount){
    type_=Type;
    id_=id;
    setAmount(amount);
    destinationID_=destinationID;
    fundIndex_ = fundNum;
    destFundIndex_=destFundNum;
    //cout<< "transaction"<<id_ <<" "<< fundIndex_<<" "  << destinationID_<< " "<<destFundIndex_<<" "<< amount_<<endl;
}
Transaction::Transaction(char Type, int id){
    type_=Type;
    id_=id;
}
char Transaction::getType() const {
    return type_;
}

string Transaction::getFirstName() const {
    return firstName_;
}
string Transaction::getLastName() const {
    return lastName_;
}
int Transaction::getID() const {
    return id_;
}
int Transaction::getAmount() const {
    return amount_;
}

int Transaction::getTransfer() const {
    return destinationID_;
}
int Transaction::getdestFundIndex() const{
    return destFundIndex_;
}
int Transaction::getfundIndex() const{
    return fundIndex_;
}
void Transaction::setAmount(int am){
    amount_=am;
}



