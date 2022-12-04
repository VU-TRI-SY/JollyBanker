#include "JollyBanker.h"
#include <iostream>
#include <fstream>
using namespace std;

JollyBanker::JollyBanker(){

}

JollyBanker::~JollyBanker(){

}

bool JollyBanker::loadTransactions(const char* fileName){
    ifstream infile; //input file stream and read its contents
	infile.open(fileName); //open the file stream
	if (!infile.is_open())
	{
		return false;
	}
	char type_;
    int primaryAccountId_;
    int primaryFundId_;
    int secondaryAccountId_;
    int secondaryFundId_;
    int amount_;
    string firstName_;
    string lastName_;
	while (infile.eof()) //if haven't read to the end of the file
	{
		infile >> type_;
        switch(type_){
            case 'D':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                infile >> amount_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_, amount_));
                break;
            case 'W':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                infile >> amount_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_, amount_));
                break;
            case 'T':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                infile >> secondaryAccountId_;
                infile >> secondaryFundId_;
                infile >> amount_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_, secondaryAccountId_, secondaryFundId_, amount_));
                break;
            case 'A':
                infile >> primaryAccountId_;
                transactionList.push(Transaction(type_, primaryAccountId_));
                break;
            case 'F':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_));
                break;
            case 'O':
                infile >> primaryAccountId_;
                infile >> firstName_;
                infile >> lastName_;
                transactionList.push(Transaction(type_, primaryAccountId_, firstName_, lastName_));
                break;
        }
	}
	infile.close();
	return true;
}
void JollyBanker::handleTransactions(){
    Account *account;
    Account *account2;
    int amount;
    while(!transactionList.empty()){
        Transaction trans = transactionList.front(); //copy first element of queue to trans
        transactionList.pop(); //delete first element of queue
        /// trans is the transaction that we must handle
        switch(trans.getType()){
            case 'D':
                //deposit
                //1. check if account exists -> findAccount
                //2. if account exists, deposit
                //3. if account doesn't exist, create account
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    //found account
                    amount = trans.getAmount();
                    if(amount < 0){
                        cerr << "ERROR: Invalid deposit amount" << endl;
                    }else{
                        account->deposit(amount, trans.getPrimaryFundId());
                    }
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Deposit refused." << endl;
                }
                break;
            case 'W':
                //withdraw
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    //found account
                    amount = trans.getAmount();
                    if(amount < 0){
                        cerr << "ERROR: Invalid withdraw amount" << endl;
                    }else{
                        
                    }
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Withdraw refused." << endl;
                }
                break;
            case 'T':
                //transfer
                bool f1 = true;
                bool f2 = true;
                if(!accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Transferal refused." << endl;
                    f1 = false;
                }
                if(!accountList.Retrieve(trans.getSecondaryAccountId(), account2)){
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Transferal refused." << endl;
                    f2 = false;
                }

                if(f1 && f2){
                    //TODO
                }
                break;
            case 'A':   
                //add account
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    account->displayHistory();
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Display refused." << endl;
                }
                break;
            case 'F':
                //display by fund id
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    account->displayHistory(trans.getPrimaryFundId());
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Display refused." << endl;
                }
                break;
            case 'O':
                //open account
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " is already open. Transaction refused." << endl;
                }else{
                    account = new Account(trans.getPrimaryAccountId(), trans.getFirstName(), trans.getLastName());
                    accountList.Insert(account);
                }
                break;
        }
    }
}

void JollyBanker::Display(){
    cout << "FINAL BALANCES:" << endl;
    cout << accountList;
}
int main(int argc, char* argv[])
{
    JollyBanker JB;
    if(JB.loadTransactions(argv[1])){
        
    }else{
        return 0;
    }
}

