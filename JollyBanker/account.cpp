#include<bits/stdc++.h>
#include "account.h"
using namespace std;
Account::Account()
{
     id_ = -1;
     firstName_ = "";
     lastName_ = "";
     totalBalance_ = 0;
     funds.push_back(Fund(0, "Money Market", 0));
     funds.push_back(Fund(1, "Prime Money Market"));
     funds.push_back(Fund(2, "Long-Term Bond"));
     funds.push_back(Fund(3, "Short-Term Bond"));
     funds.push_back(Fund(4, "500 Index Fund"));
     funds.push_back(Fund(5, "Capital Value Fund"));
     funds.push_back(Fund(6, "Growth Equity Fund"));
     funds.push_back(Fund(7, "Growth Index Fund"));
}

Account::Account(int id, string firstName, string lastName)
{
     // this is a pointer that points to current object
     this->id_ = id;
     this->firstName_ = firstName;
     this->lastName_ = lastName;
     totalBalance_ = 0;
     funds.push_back(Fund(0, "Money Market", 0));
     funds.push_back(Fund(1, "Prime Money Market"));
     funds.push_back(Fund(2, "Long-Term Bond"));
     funds.push_back(Fund(3, "Short-Term Bond"));
     funds.push_back(Fund(4, "500 Index Fund"));
     funds.push_back(Fund(5, "Capital Value Fund"));
     funds.push_back(Fund(6, "Growth Equity Fund"));
     funds.push_back(Fund(7, "Growth Index Fund"));
}

Account::~Account(){

}

bool Account::deposit(int amount, int fundId){
     if(amount < 0){
          return false;
     }else{
          int b = funds[fundId].getBalance(); //old balance
          funds[fundId].setBalance(b + amount);
          totalBalance_ += amount;
          return true;
     }
}

bool Account::withDraw(int amount, int fundId){
     // int b = funds[fundId].getBalance(); //old balance
     // funds[fundId].setBalance(b - amount);
     // totalBalance_ -= amount;
     if(amount < 0){
          cerr << "ERROR: Invalid withdraw amount" << endl;
          return false;
     }else{
          // W 1234 0 500
          // amount = 500
          switch(fundId){
               case 0:
                    if(amount > funds[0].getBalance() + funds[1].getBalance()){
                         cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName_ << " " 
                         << lastName_ << " " << funds[0].getName() << endl;
                         return false;
                    }else{
                         if(amount > funds[0].getBalance()){ //fund 0 is not enoungh money to withdraw
                              //ex: amount: 500$, fund 0: 200$, fund 1: 700$
                              amount -= funds[0].getBalance(); //amount = 500 - 200 = 300
                              // account->withDraw(account->getFund(0).getBalance(), 0); //withdraw all money from fund 0 (200$)
                              funds[0].setBalance(0); //withdraw all money from fund 0 (200$)
                              funds[1].setBalance(funds[1].getBalance() - amount); //withdraw 300$ from fund 1
                         }else{
                              funds[0].setBalance(funds[0].getBalance() - amount); //withdraw 500$ from fund 0
                         }
                    }
                    return true;
                    break;
               case 1:
                    if(amount > funds[0].getBalance() + funds[1].getBalance()){
                         cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName_ << " " 
                         << lastName_ << " " << funds[1].getName() << endl;
                         return false;
                    }else{
                         if(amount > funds[1].getBalance()){ 
                              amount -= funds[1].getBalance(); 
                              funds[1].setBalance(0); 
                              funds[0].setBalance(funds[0].getBalance() - amount); 
                         }else{
                              funds[1].setBalance(funds[1].getBalance() - amount); 
                         }
                    }
                    return true;
                    break;
               case 2:
                    if(amount > funds[2].getBalance() + funds[3].getBalance()){
                         cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName_ << " " 
                         << lastName_ << " " << funds[2].getName() << endl;
                         return false;
                    }else{
                         if(amount > funds[2].getBalance()){ 
                              amount -= funds[2].getBalance(); 
                              funds[2].setBalance(0); 
                              funds[3].setBalance(funds[3].getBalance() - amount); 
                         }else{
                              funds[2].setBalance(funds[2].getBalance() - amount); 
                         }
                    }
                    return true;
                    break;
               case 3:
                    if(amount > funds[2].getBalance() + funds[3].getBalance()){
                         cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName_ << " " 
                         << lastName_ << " " << funds[3].getName() << endl;
                         return false;
                    }else{
                         if(amount > funds[3].getBalance()){ 
                              amount -= funds[3].getBalance(); 
                              funds[3].setBalance(0); 
                              funds[2].setBalance(funds[2].getBalance() - amount); 
                         }else{
                              funds[3].setBalance(funds[3].getBalance() - amount); 
                         }
                    }
                    return true;
                    break;
               default:
                    if(amount > funds[fundId].getBalance()){
                         cerr << "ERROR: Not enough funds to withdraw " << amount << " from " << firstName_ << " " 
                         << lastName_ << " "<< funds[fundId].getName() << endl;
                         return false;
                    }else{
                         funds[fundId].setBalance(funds[fundId].getBalance() - amount);
                    }
                    return true;
                    break;
          }
     }
}

void Account::displayHistory(){
     cout << "Transaction History for " << this->firstName_ << " " << this->lastName_ << " by fund." << endl;
     for(int idx = 0; idx <= 7; idx++){
          //find that there is a transaction that related to this fund id
          int found = false; //assume that there is no transaction related to fundId (id)
          for(int i = 0; i < transactions.size(); i++){//traverse through the trasaction list of this account and find the transaction that this fundId = id
               if(transactions[i].getPrimaryFundId() == idx || transactions[i].getSecondaryFundId() == idx){
                    found = true; //if found -> found = true -> break nested loop(loop to find related trans)
                    break;
               }
          }
          //-----------------------
          if(found){
               cout << funds[idx].getName() << ": $" << funds[idx].getBalance() << endl;
               for(int i = 0; i < transactions.size();i++){
                    if(transactions[i].getPrimaryFundId() == idx || transactions[i].getSecondaryFundId() == idx){
                         cout << "  ";
                         transactions[i].display();
                    }
               }
          }
     }
}
void Account::displayHistory(int fundId){
     cout << "Transaction History for " << this->firstName_ << " " << this->lastName_ << this->funds[fundId].getName()
     << ": $" << this->funds[fundId].getBalance() << endl;
     for(int i = 0; i < transactions.size();i++){
          if(transactions[i].getPrimaryFundId() == fundId || transactions[i].getSecondaryFundId() == fundId){
               cout << "  ";
               transactions[i].display();
          }
     }
}
ostream& operator<<(ostream& stream, const Account& rhs){
     stream << rhs.firstName_ << " " << rhs.lastName_ << " Account ID: " << rhs.id_ << endl;
     for(int i = 0; i <= 7; i++){
          stream << "    " << rhs.funds[i].getName() << ": " << rhs.funds[i].getBalance() << endl;
     }
     return stream;
}

int Account::getTotalBalance() const{
     return this->totalBalance_;
}

int Account::getId() const{
     return this->id_;
}

string Account::getFirstName() const{
     return this->firstName_;
}
string Account::getLastName() const{
     return 
     this->lastName_;
}

void Account::displayFunds(){
     cout << this->firstName_ << " " << this->lastName_ << " Account ID: " << this->id_ << endl;
     for(int i = 0; i <=7; i++){
          cout << "    ";
          funds[i].display();
     }
}

Fund Account::getFund(int fundId) const{
     return this->funds[fundId];
}

void Account::addTransaction(Transaction transaction){
     transactions.push_back(transaction);
}

void Account::setId(int idx){
     this->id_ = idx;
}






