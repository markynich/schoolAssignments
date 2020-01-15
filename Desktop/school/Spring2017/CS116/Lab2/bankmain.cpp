#include <iostream>
#include <string>
#include <iomanip>
#include <ctime> 
#include "Account.h"
#include "Bank.h"


using namespace std; 


void printMeFirst(string name, string courseInfo) 
{

cout <<" Program written by: "<< name << endl; 
cout <<" Course info: "<< courseInfo << endl;
time_t now = time(0); //current date/time based on current system
char* dt = ctime(&now); //convert now to string for
cout << " Date: " << dt << endl;

}

int main()
{
    
   printMeFirst("Mark-Nicholas Magsakay", "CS-116 Lab 2 - Sunday 2017 Spring");  // you must call this function 1st
   
   
   Bank myBank;
   cout << "\nInital bank balances: \n";
   myBank.printBalances();   /* set up empty accounts */


   cout << "\nAdding some money to accounts: \n";

   
   cout << "\nAdding $1000 to saving \n";
   cout << "Adding $2000 to checking \n";
   myBank.deposit(1000, "S");  /* deposit $1000 to savings */
   myBank.deposit(2000, "C");  /* deposit $2000 to checking */
   myBank.printBalances();

  
   cout << "\nTaking out $1500 from checking,and moving $200 from";
   cout << " savings to checking.\n";


   myBank.withdraw(1500, "C"); /* withdraw $1500 from checking */
   myBank.transfer(200, "S");  /* transfer $200 from savings */
   myBank.printBalances();


   cout << "\ntrying to withdraw $900 from Savings.\n";
   myBank.withdraw(900,"S");
   myBank.printBalances();

   
   cout << "\ntrying to withdraw $400 from Checking.\n";
   myBank.withdraw(400,"C");
   myBank.printBalances();
   
   
   return 0;
}
