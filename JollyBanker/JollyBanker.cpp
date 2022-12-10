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
    // cout << infile.eof() << endl;
	while (!infile.eof()) //if haven't read to the end of the file
	{
		infile >> type_;
        // cout << type_ << endl;
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
    Account *account = nullptr;
    Account *account2 = nullptr;
    int amount;
    int fundId;
    bool f1, f2;
    Transaction trans2;
    while(!transactionList.empty()){
        Transaction trans = transactionList.front(); //copy first element of queue to trans
        transactionList.pop(); //delete first element of queue
        switch(trans.getType()){
            case 'D':
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    //found account
                    amount = trans.getAmount();
                    if(amount < 0){
                        cerr << "ERROR: Invalid deposit amount" << endl;
                        trans.setError(true);
                    }else{
                        account->deposit(amount, trans.getPrimaryFundId());
                    }
                    account->addTransaction(trans);
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found." << endl;
                }
                break;
            case 'W':
                //withdraw
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    //found account
                    // variable 'account' is the account that we must handle with
                    amount = trans.getAmount(); //amount to withdraw

                    if(amount < 0){
                        cerr << "ERROR: Invalid withdraw amount" << endl;
                        trans.setError(true);
                    }else{
                        // W 1234 0 500
                        // amount = 500
                        trans2 = trans;
                        trans2.setPrimaryFundId(-1); //-1 means trans is invalid
                        if(!account->withDraw(amount, trans.getPrimaryFundId(), trans2)){
                            //withdraw failed
                            trans.setError(true);
                        }else{
                            if(trans2.getPrimaryFundId() != -1){
                                //transfer from other fund
                                trans.setAmount(amount-trans2.getAmount()); //update amount of trans 1
                                account->addTransaction(trans2);
                            }
                        }
                    }
                    account->addTransaction(trans);
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Withdraw refused." << endl;
                }
                break;
            case 'T':
                f1 = true;
                f2 = true;
                if(!accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Transferal refused." << endl;
                    f1 = false;
                    trans.setError(true);
                }
                if(!accountList.Retrieve(trans.getSecondaryAccountId(), account2)){
                    cerr << "ERROR: Account " << trans.getSecondaryAccountId() << " not found. Transferal refused." << endl;
                    f2 = false;
                    trans.setError(true);
                }

                if(!f1 && f2){ //f1 false, f2 true
                    account2->addTransaction(trans);
                }

                if(f1 && !f2){
                    account->addTransaction(trans);
                }

                if(f1 && f2){
                    //transfer from account1 to account2
                    amount = trans.getAmount();
                    trans2 = trans;
                    trans2.setPrimaryFundId(-1);
                    if(trans.getPrimaryAccountId() == trans.getSecondaryAccountId()){//transfer on itself
                        if(!account->withDraw(amount, trans.getPrimaryFundId(), trans2)){ //if withdraw fail -> update err of trans
                            trans.setError(true);
                        }else{
                            if(!account2->deposit(amount, trans.getSecondaryFundId())){ // deposit fail -> update err of trans
                                trans.setError(true);
                            }
                        }
                        if(trans2.getPrimaryFundId() != -1){
                            trans.setAmount(amount-trans2.getAmount()); //update amount of trans 1
                            account->addTransaction(trans2);
                        }
                        account->addTransaction(trans);

                    }else{
                        if(!account->withDraw(amount, trans.getPrimaryFundId(), trans2)){ //if withdraw fail -> update err of trans
                            trans.setError(true);
                        }else{
                            if(!account2->deposit(amount, trans.getSecondaryFundId())){ // deposit fail -> update err of trans
                                trans.setError(true);
                            }
                        }
                        
                        if(trans2.getPrimaryFundId() != -1){
                            trans.setAmount(amount-trans2.getAmount()); //update amount of trans 1
                            //add transaction to both account sequentially
                            account->addTransaction(trans);
                            account->addTransaction(trans2);
                            account2->addTransaction(trans);
                            account2->addTransaction(trans2);
                        }else{
                            account->addTransaction(trans);
                            account2->addTransaction(trans);
                        }
                    }
                }
                break;
            case 'A':   
                //add account
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    account->displayHistory();
                    cout << endl;
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Display refused." << endl;
                }
                break;
            case 'F':
                //display by fund id
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    account->displayHistory(trans.getPrimaryFundId());
                    cout << endl;
                }else{
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " not found. Display refused." << endl;
                }
                break;
            case 'O':
                if(accountList.Retrieve(trans.getPrimaryAccountId(), account)){
                    cerr << "ERROR: Account " << trans.getPrimaryAccountId() << " is already open. Transaction refused." << endl;
                }else{
                    if(trans.getPrimaryAccountId() < 0){
                        cerr << "ERROR: Invalid account id" << endl;
                    }else{
                        account = new Account(trans.getPrimaryAccountId(), trans.getFirstName(), trans.getLastName());
                        accountList.Insert(account);

                    }
                }
                break;
        }
    }
}


void JollyBanker::Display(){
    cout << "FINAL BALANCES:" << endl;
    accountList.Display();
    return;
}
int main(int argc, char* argv[])
{
    JollyBanker JB;
    if(JB.loadTransactions(argv[1])){
        JB.handleTransactions();
        JB.Display();
    }else{
        return 0;
    }
}

