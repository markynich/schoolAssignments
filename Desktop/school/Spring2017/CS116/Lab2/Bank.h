#include <iomanip>
#include <string>
#include <iostream>
#ifndef	BANK_H
#def	BANK_H

using namespace std;


class Bank 

{ 

public:
    
Bank();

Bank(double checkingAmount, double savingsAmount);


void deposit(double amount, string account);


void withdraw(double amount, string account);    


void transfer(double amount, string account);    


void printBalances() const;


private:    ??????? checking;   // change ?????? with correct data type    ??????? savings; };










#endif