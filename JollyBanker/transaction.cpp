#include "transaction.h"
Transaction::Transaction(){
	type_ = ' ';
	primaryAccountId_ = -1;
	primaryFundId_ = -1;
	secondaryAccountId_ = -1;
	secondaryFundId_ = -1;
	amount_ = 0;
	firstName_ = "";
	lastName_ = "";
	error_ = false;
}

Transaction::Transaction(char type, int primaryAccountId, int primaryFundId, int amount)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = primaryFundId;
	this->secondaryAccountId_ = -1;
	this->secondaryFundId_ = -1;
	this->amount_ = amount;
	this->firstName_ = "";
	this->lastName_ = "";
	error_ = false;
}

Transaction::Transaction(char type, int primaryAccountId, int primaryFundId, int secondaryAccountId, int secondaryFundId, int amount)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = primaryFundId;
	this->secondaryAccountId_ = secondaryAccountId;
	this->secondaryFundId_ = secondaryFundId;
	this->amount_ = amount;
	this->firstName_ = "";
	this->lastName_ = "";
	error_ = false;
}

Transaction::Transaction(char type, int primaryAccountId)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = -1;
	this->secondaryAccountId_ = -1;
	this->secondaryFundId_ = -1;
	this->amount_ = -1;
	this->firstName_ = "";
	this->lastName_ = "";
	error_ = false;
}

Transaction::Transaction(char type, int primaryAccountId, int primaryFundId)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = primaryFundId;
	this->secondaryAccountId_ = -1;
	this->secondaryFundId_ = -1;
	this->amount_ = -1;
	this->firstName_ = "";
	this->lastName_ = "";
	error_ = false;
}

Transaction::Transaction(char type, int primaryAccountId, string firstName, string lastName)
{
	this->type_ = type;
	this->primaryAccountId_ = primaryAccountId;
	this->primaryFundId_ = -1;
	this->secondaryAccountId_ = -1;
	this->secondaryFundId_ = -1;
	this->amount_ = -1;
	this->firstName_ = firstName;
	this->lastName_ = lastName;
	error_ = false;
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

Transaction& Transaction::operator=(const Transaction& src){
	if(this != &src){
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
	return *this;
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

void Transaction::setPrimaryFundId(int fundId){
	this->primaryFundId_ = fundId;
}

void Transaction::setAmount(int amount){
	this->amount_ = amount;
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
