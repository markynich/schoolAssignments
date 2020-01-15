#ifndef ACCOUNT_H
#define ACCOUNT_H

/*
A constant variable that will take out a certain amount if
the amount that is requested to be taken out of the balance exceeds
the amount the balance has inside already.
*/
const int penalty = 5;
/*
A class that sets up the member functions and accounts to be used
in other classes and functions. Also, has the balance that will be used
and inherited by other classes.
*/
class Account
{
public:
   Account();
   Account(double bal);
   void deposit(double amount);  // need to implement member function program
   void withdraw(double amount);
   double getBalance() const;

private:
   double balance;
};
/*
These classes inherit the class Account which allows them to deposit
and withdraw from the balance and be able to print the balance out
when needed. It will also clarify which amount will go in which account.
*/
class Checking : public Account 
{
public:
	Checking(){};
	void printBalances() const;
};

class Savings : public Account 
{
public:
	Savings(){};
	void printBalances() const; 
};

#endif // ACCOUNT_H

