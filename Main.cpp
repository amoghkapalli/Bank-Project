#include <iostream>
#include "Bank.h"
#include <string>

int main(int argc, char* argv[]) {
	if(argc !=2){
        cout<<"please only enter one argument"<<endl;
    }
	string fileName=argv[1];
	Bank JollyBank;
	JollyBank.processTransactionFile(fileName);
    JollyBank.processTransactions();
	JollyBank.PrintActions();
}