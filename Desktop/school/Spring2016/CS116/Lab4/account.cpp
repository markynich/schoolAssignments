#include <iostream>
#include "account.h" 

using namespace std;

Account::Account()
{
	balance = 0.00; //initiates account balance to 0 dollars.
}
//uses bal to give balance an amount that will equal bal

Account::Account(double bal)
{
	balance = bal;
}
//allows the account to deposit which is inherited to add the amount into it.

void Account::deposit(double amount)
{
	balance = balance + amount;
}
/*
allows the account to withdraw which is inherited that allows to take out
the amount from the account. However, if the account has less than the amount,
it will not be taking the amount from the account balance and instead, give a
penalty.
*/
void Account::withdraw(double amount)
{
	if(amount > balance)
	{
		balance = balance - penalty; 
	}
	if(amount <=balance)
	{
		balance = balance - amount;
	}
}
/*
Allows to get the balance and make sure it is inside the account balance
and then it is used to help print out the balance so that the user
may see the balance.
*/
double Account::getBalance() const
{
	return balance;
}
void Checking::printBalances() const 
{
	cout << getBalance();
}
void Savings::printBalances() const 
{
	cout << getBalance();
}
