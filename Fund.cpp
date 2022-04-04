#include<iostream>
#include"Fund.h"
#include<string>
Fund::Fund(){
    value_=0;
    name_="";
}
Fund::Fund(string fundName){
	name_ = fundName;
	value_ = 0;
}
Fund::~Fund(){

}
bool Fund::Add(int amount){
    if(amount<0){
		cerr << "ERROR: Could not add negative amount" << endl;
        return false;
    }
    else{
		this->value_+=amount;
        return true;
    }
}
bool Fund::isWithdrawalEnough(int Amount) const {
    return value_ >= Amount;
}
bool Fund::Remove(int amount){
	if(amount>=0){
		value_-=amount;
		return true;
	}
	else{
		cerr << "ERROR: Could not remove negative amount" << endl;
		return false;
	}
}
string Fund::getName() const{
	return name_;
}
int Fund::getValue() const{
	return value_;
}
bool Fund::setAmount(int amount){
	if(amount>=0){
		value_= amount;
		return true;
	}
	else{
		return false;
	}
	
}
bool Fund::setName(string n){
	name_= n;
	return true;
}

void Fund::addHistory(string his){
    history.push_back(his);
}

void Fund::printFundHistory() const {
	cout << name_ << ": $" << value_ << endl;
    for (string i: history) {
        cout << i<< endl;
    }
}