#include <iostream>
#include <string>
#include <iomanip>
#include <ctime> 
#include <cstdlib>
#include "account.h"
#include "printMeFirst.h" 

using namespace std; 
   
void transfer(Checking &checking, Savings &savings, double amount, string account)
{
    if(account == "S") //initiates savings account
   {
      checking.deposit(amount); //adds an amount into checking
      savings.withdraw(amount); //takes an amount from savings
      }
   if(account == "C") //initiates checking account
   {
      checking.withdraw(amount); //takes an amount from checking
      savings.deposit(amount);   //adds an amount into savings
      }  
   }

int main() //start of main function
{

/*
The four integars below are made to access all three classes
for the main function so that it is used to add and withdraw 
amounts into the accounts.
*/
Account myBank; 
Savings S;
Checking C;

printMeFirst("Mark-Nicholas Magsakay", "CS116-02 Friday - Lab 4"); //prints out name and info 

/*
S.printBalances and C.printBalances sets up the
empty accounts.
*/
cout << "\nInital bank balances: \n";
S.printBalances();
C.printBalances();

cout << "\nAdding some money to accounts: \n"; // a print out for the user to know what is happening

cout << "\nAdding $1000 to saving \n";
cout << "Adding $2000 to checking \n";
/* deposit $1000 to savings */
S.deposit(1000);
/* deposit $2000 to checking */
C.deposit(2000);
/*
prints out the accounts to show the amounts were added into
savings and checking.
*/
S.printBalances();
C.printBalances();

cout << "\nTaking out $1500 from checking,and moving $200 from";
cout << " savings to checking.\n";

C.withdraw(1500); /* withdraw $1500 from checking */
transfer(C,S,200,"S"); /* transfer $200 from savings */
S.printBalances();
C.printBalances();

cout << "\nTrying to withdraw $900 from Savings.\n";
S.withdraw(900); //withdraw $900 from savings
S.printBalances();
C.printBalances();

cout << "\nTrying to withdraw $400 from Checking.\n";
C.withdraw(400); //withdraw $400 from checking
S.printBalances();
C.printBalances();

return 0;
}


