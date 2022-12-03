#include "JollyBanker.h"
#include <iostream>
#include <fstream>
using namespace std;

JollyBanker::JollyBanker(){

}

JollyBanker::~JollyBanker(){

}

bool JollyBanker::loadTransactions(const char* fileName){
    ifstream infile; //input file stream and read its contents
	infile.open(fileName); //open the file stream
	if (!infile.is_open())
	{
		return false;
	}
	char type_;
    int primaryAccountId_;
    int primaryFundId_;
    int secondaryAccountId_;
    int secondaryFundId_;
    int amount_;
    string firstName_;
    string lastName_;
	while (infile.eof()) //if haven't read to the end of the file
	{
		infile >> type_;
        switch(type_){
            case 'D':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                infile >> amount_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_, amount_));
                break;
            case 'W':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                infile >> amount_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_, amount_));
                break;
            case 'T':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                infile >> secondaryAccountId_;
                infile >> secondaryFundId_;
                infile >> amount_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_, secondaryAccountId_, secondaryFundId_, amount_));
                break;
            case 'A':
                infile >> primaryAccountId_;
                transactionList.push(Transaction(type_, primaryAccountId_));
                break;
            case 'F':
                infile >> primaryAccountId_;
                infile >> primaryFundId_;
                transactionList.push(Transaction(type_, primaryAccountId_, primaryFundId_));
                break;
            case 'O':
                infile >> primaryAccountId_;
                infile >> firstName_;
                infile >> lastName_;
                transactionList.push(Transaction(type_, primaryAccountId_, firstName_, lastName_));
                break;
        }
	}
	infile.close();
	return true;
}
void JollyBanker::handleTransactions(){
    //delete element from queue (dequeue) each Transaction from transactionList -> handle
}
int main(int argc, char* argv[])
{
    JollyBanker JB;
    if(JB.loadTransactions(argv[1])){
        
    }else{
        return 0;
    }
}

