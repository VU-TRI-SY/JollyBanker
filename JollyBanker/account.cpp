#include "account.h"

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

void Account::deposit(int amount, int fundId){
     int b = funds[fundId].getBalance(); //old balance
     funds[fundId].setBalance(b + amount);
     totalBalance_ += amount;
}

void Account::withDraw(int amount, int fundId){
     int b = funds[fundId].getBalance(); //old balance
     funds[fundId].setBalance(b - amount);
     totalBalance_ -= amount;
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
