/*Linh Huynh
CSS 342
Instructor:Professor Dimpsey
Program 5*/
// -> create BSTree -> stores accounts
// -> create Queue -> stores all transactions lining up in queue and waiting for being handled
#ifndef JOLLYBANKER_H_
#define JOLLYBANKER_H_
#include <iostream>
#include <queue>
#include "Account.h"
#include "Fund.h"
#include "Transaction.h"
#include "BSTree.h"

class JollyBanker {
public:
    JollyBanker();
    ~JollyBanker(); // not use Dynamic allocate -> can remove destructor
    bool loadTransactions(const char* fileName);//read all transactions from text file, 
                            //return true if load succesfully, otherwise return false
    void handleTransactions(); //dequeue(delete a transaction from Queue) -> handle ->
                               //load to history transactions of accounts related
    void Display();//display all accounts after transactions handled
private:
    queue<Transaction> transactionList;
    BSTree accountList; //banker's account list
    //vector<Transaction> failTransactions; ?????? store failed transactions that cannot be stored in related account 
    //yes, because we want to keep track transaction by using vector of fundname. 
    // all actions in account and fund will be printed out
    //error messages should be printed out to cerr which is an object stores the messages
};
#endif