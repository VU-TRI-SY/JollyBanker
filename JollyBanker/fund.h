/*Linh Huynh
CSS 342
Instructor:Professor Dimpsey
Program 5*/

#ifndef FUND_H_
#define FUND_H_
#include <iostream>
#include <string>
using namespace std;
class Fund {

public:
    Fund();
    Fund(int id, string name, int balance); // create fund with id, name and balance(= 0 or != 0)
    Fund(int id, string name); //balance = 0
    int getBalance() const;
    void setBalance(int b);
    string getName() const;
    int getId() const;
private:
    string name_; //id = 0 -> name = "money market"
    int id_; //0->7
    int balance_;
};
#endif

