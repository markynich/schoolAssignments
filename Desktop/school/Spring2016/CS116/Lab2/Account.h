#include <iomanip>
#include <string>
#include <iostream>
#ifndef	ACCOUNT_H
#def	ACCOUNT_H

using namespace std;


class Account

{

public:

   Account();
	{
	
		deposit();
		withdraw();
			
	}
   Account(double bal);
   {
   
   
   
   }

   void deposit(double amount);   // need to implement member function program
	{
	
	double depositAmount = amount + get
	
	}


   void withdraw(double amount);
   	{
   	
   	double withdrawAmount = amount + get
   	
   	}

   double getBalance() const;
   	{
   		return balance;
   	}
	
 

private:

   double balance;

};

#endif	ACCOUNT_H