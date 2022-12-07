#include "transaction.h"
Transaction::Transaction(){
	type_ = ' ';
	primaryAccountId_ = 0;
	primaryFundId_ = 0;
	secondaryAccountId_ = 0;
	secondaryFundId_ = 0;
	amount_ = 0;
	firstName_ = " ";
	lastName_ = " ";
	error_ = false;
}

Transaction::Transaction(char type, int primaryAccountId, int primaryFundId, int amount)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = primaryFundId;
	this->amount_ = amount;
}

Transaction::Transaction(char type, int primaryAccountId, int primaryFundId, int secondaryAccountId, int secondaryFundId, int amount)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = primaryFundId;
	this->secondaryAccountId_ = secondaryAccountId;
	this->secondaryFundId_ = secondaryFundId;
	this->amount_ = amount;
}

Transaction::Transaction(char type, int primaryAccountId)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
}

Transaction::Transaction(char type, int primaryAccountId, int primaryFundId)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = primaryFundId;
}

Transaction::Transaction(char type, int primaryAccountId, string firstName, string lastName)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->firstName_ = firstName;
	this->lastName_ = lastName;
}

Transaction::Transaction(const Transaction& src){
	this->type_ = src.type_;
	this->primaryAccountId_ = src.primaryAccountId_;
	this->primaryFundId_ = src.primaryFundId_;
	this->secondaryAccountId_ = src.secondaryAccountId_;
	this->secondaryFundId_ = src.secondaryFundId_;
	this->amount_ = src.amount_;
	this->firstName_ = src.firstName_;
	this->lastName_ = src.lastName_;
	this->error_ = src.error_;
}

Transaction Transaction::operator=(const Transaction& src){
	Transaction res;
	res.type_ = src.type_;
	res.primaryAccountId_ = src.primaryAccountId_;
	res.primaryFundId_ = src.primaryFundId_;
	res.secondaryAccountId_ = src.secondaryAccountId_;
	res.secondaryFundId_ = src.secondaryFundId_;
	res.amount_ = src.amount_;
	res.firstName_ = src.firstName_;
	res.lastName_ = src.lastName_;
	res.error_ = src.error_;
	return res;
}




int Transaction::getType() const{
	return type_;
}
int Transaction::getPrimaryAccountId() const{
	return primaryAccountId_;
}
int Transaction::getPrimaryFundId() const{
	return primaryFundId_;
}
int Transaction::getSecondaryAccountId() const{
	return secondaryAccountId_;
}
int Transaction::getSecondaryFundId() const{
	return secondaryFundId_;
}
int Transaction::getAmount() const{
	return amount_;
}
string Transaction::getFirstName() const{
	return firstName_;
}
string Transaction::getLastName() const{
	return lastName_;
}
bool Transaction::getError() const{
	return error_;
}

void Transaction::display(){
	if(this->type_ == 'D' || this->type_ == 'W'){
		cout << this->type_ << " " << this-> primaryAccountId_ << " " << this->primaryFundId_ << " " << this->amount_;
	}

	if(this->type_ == 'T'){
		cout << this->type_ << " " << this-> primaryAccountId_ << " " << this->primaryFundId_ << " " << this->secondaryAccountId_ << " " << this->secondaryFundId_ << " " << this->amount_;
	}

	if(this->type_ == 'A'){
		cout << this->type_ << " " << this->primaryAccountId_;
	}

	if(this->type_ == 'F'){
		cout << this->type_ << " " << this-> primaryAccountId_ << " " << this->primaryFundId_;
	}

	if(this->type_ == 'O'){
		cout << this->type_ << " " << this->primaryAccountId_ << " " << this->firstName_ << " " << this->lastName_;
	}

	if(this->error_){
		cout << " (Failed)" << endl;
	}else{
		cout << endl;
	}

}

void Transaction::setError(bool error){
	this->error_ = error;
}
