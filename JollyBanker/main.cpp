#include<bits/stdc++.h>
#include "Account.h"
#include "Fund.h"
#include "Transaction.h"
#include "BSTree.h"
using namespace std;
int main(){
    BSTree accountList;
    Account* account = nullptr;
    Transaction trans('O', 500, "John", "Smith");
    account = new Account(trans.getPrimaryAccountId(), trans.getFirstName(), trans.getLastName());
    accountList.Insert(account);
    trans = Transaction('O', 1001, "Cash", "Johnny");
    account = new Account(trans.getPrimaryAccountId(), trans.getFirstName(), trans.getLastName());
    accountList.Insert(account);
    cout <<"FINAL BALANCES:" << endl;
    accountList.printSt();
    accountList.Display();

}