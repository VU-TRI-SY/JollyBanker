/*Linh Huynh
CSS 342
Instructor:Professor Dimpsey
Program 5*/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include <vector>
#include "Transaction.h"
using namespace std;

class Account {
public:
    Account();
    Account(int id, string firstName, string lastName);
    void deposit(int amount, int fundId);
    void withDraw(int amount, int fundId);
    void displayHistory(); //display all transactions
    void displayHistory(int fundId);  //display all transactions with fundId passed
    friend ostream& operator<<(ostream& stream, const Account& rhs);//need output operators
private:
    string firstName_;
    string lastName_;
    int id_;
    int totalBalance_;
    vector<Transaction> transactions;
    vector<Fund> funds;
};
#endif