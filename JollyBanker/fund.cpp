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
