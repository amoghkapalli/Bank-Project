#include "Bank.h"
#include "Account.h"
#include <sstream>
#include<iostream>
#include <fstream>
#include <queue>
using namespace std;
Bank::Bank(){

}

void Bank::processTransactionFile(const string &fileName) {
    ifstream in_file(fileName);
    string String;

    while (getline(in_file, String)) {
        istringstream chars(String);
        char entryAction;
        chars >> entryAction;

        if (entryAction == 'O') {
            string lastName;
            string firstName;
            int id;
            chars>>id>> lastName>>firstName;
            Transaction Temp(entryAction, lastName, firstName, id);
            TransactionList.push(Temp);

        } else if (entryAction == 'D' || entryAction == 'W') {
            int id;
            int fundNum;
            int val;
            chars >> id >> fundNum>> val;
            Transaction Temp(entryAction, id, fundNum, val);
            TransactionList.push(Temp);

        } else if (entryAction == 'T') {
            int ID, Amount, DestinationID;
            int fundIndex, destFundIndex;
            chars >> ID >> fundIndex  >> DestinationID>>destFundIndex >> Amount;
            //cout<< ID <<" "<< fundIndex<<" "  << DestinationID<< " "<<destFundIndex<<" "<< Amount<<endl;
            Transaction Temp(entryAction, ID, fundIndex, DestinationID, destFundIndex, Amount);
            TransactionList.push(Temp);

        } else if (entryAction == 'A') {
            int id;
            chars >> id;
            Transaction Temp(entryAction, id);
            TransactionList.push(Temp);

        } else if(entryAction=='F'){
            int id;
            int fundIndex;
            chars >> id >>fundIndex;
            Transaction Temp(id, fundIndex, entryAction);
            TransactionList.push(Temp);
        }
        else {
            cout << "Invalid Transaction Type!" << endl;
        }
    }
}
void Bank::displayAllBankBalances(){
    cout << "\nFINAL BALANCES:" << endl;
    accounts.Display();
}
void Bank::processTransactions() {
    while (!TransactionList.empty()){
        Transaction first=TransactionList.front();
        if (first.getType() == 'O') {
            if (accounts.Contains(first.getID())) {
                cerr << "ERROR: Account " << first.getID() <<" is already open. Transaction refused." << endl;
            }
            else{
                Account* start = new Account(first.getLastName(), first.getFirstName(), first.getID());
                accounts.Insert(first.getID(), start);
            }
        }
        else if (first.getType() == 'D') {
            Account *dep;
            int depositID=first.getID();
            int fundIndex = first.getfundIndex();
            int amt=first.getAmount();
            if(accounts.Retreieve(depositID, dep)){
                dep->Deposit(fundIndex, amt);
            }
            else
			{
				cerr << "ERROR: Transaction refused. Account doesnt exist" << endl;
			}
        }
        else if (first.getType() == 'T') {
            Account* fromAccount;
			Account* toAccount;
			int fromAcID, fromFund, amt, toAcID, toFund;
			fromAcID = first.getID();
			fromFund = first.getfundIndex();
			toAcID = first.getTransfer();
			toFund = first.getdestFundIndex();
			amt = first.getAmount();
            if (accounts.Contains(toAcID) && accounts.Contains(fromAcID))
			{
                accounts.Retreieve(fromAcID, fromAccount);
                accounts.Retreieve(toAcID, toAccount);
                if (fromAccount->Transfer(fromFund, amt, *toAccount, toFund)){

                }
                else{
                    cerr<<"Transfer could not be completed. Not enough funds in Account " << fromAcID << "to withdraw " <<amt <<endl;
                }
            }
        }
        else if (first.getType() == 'W')
		{
			Account* start; //= nullptr;
			int acID = first.getID();
			int fundIndex = first.getfundIndex();
			int amt = first.getAmount();

			if (accounts.Retreieve(acID, start))
			{
				start->Withdraw(fundIndex, amt);
			}
			else
			{
				cerr << "ERROR: Withdraw cannot be made. Account doesnt exist" << endl;
			}
		}
        else if (first.getType() == 'A')
		{
			Account* start;
			int acID = first.getID();

    		if (accounts.Retreieve(acID, start)){					
                cout << endl;
				start->printFullHistory();
				cout << endl;
			}
		}
        else if (first.getType() == 'F')
		{
			Account* start;
			int acID = first.getID();
            int index=first.getfundIndex();
            
    		if (accounts.Retreieve(acID, start)){					
                cout << endl;
				start->FundHistory(index);
				cout << endl;
			}
		}

        TransactionList.pop();
    }
}
void Bank::PrintActions()
{
	///cout << endl;
	cout << "FINAL BALANCES:" << endl;
	accounts.Display();
}