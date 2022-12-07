#include "fund.h"

Fund::Fund()
{
	id_ = -1;
	name_ = "";
	balance_ = 0;
}

Fund::Fund(int id, string name, int balance)
{
	this->id_ = id;
	this->name_ = name;
	this->balance_ = balance;
}

Fund::Fund(int id, string name)
{
	this->id_ = id;
	this->name_ = name;
    this->balance_ = 0;
}

Fund::Fund(const Fund&F){
	this->id_ = F.id_;
	this->name_ = F.name_;
	this->balance_ = F.balance_;
}

Fund& Fund::operator=(const Fund& rhs){
	if(this != &rhs){
		this->id_ = rhs.id_;
		this->name_ = rhs.name_;
		this->balance_ = rhs.balance_;
	}
	return *this;
}

int Fund::getBalance() const{
	return this->balance_;
}

void Fund::setBalance(int b){
	this->balance_ = b;
}

string Fund::getName() const{
	return this->name_;
}

int Fund::getId() const{
	return this->id_;
}

void Fund::display(){
	cout << this->name_ << ": $" << this->balance_ << endl;
}
