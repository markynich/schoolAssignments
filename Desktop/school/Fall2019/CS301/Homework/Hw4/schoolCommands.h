#ifndef SCHOOLCOMMANDS_H
#define SCHOOLCOMMANDS_H
#include <fstream>
#include <iostream>
#include <string>
#include "schoolSystem.h"

enum Commands {S,A,P,T,F,C,G,O,Q};
class schoolCommands : public schoolSystem
{
  public:
    schoolCommands();
    ~schoolCommands();
    char ComparedTo(char item);
    void clearScreen();
    void readCommand();
    void readCommand(std::string sentence);
    void switchCommand(char item, bool checkC);
    void command_S(); //done
    void command_A(); //done
    void command_P(); //done
    void command_P(int loc);
    void command_T(); //done
    void command_T(int loc);
    void command_F(); //done
    void command_F(int loc);
    void command_C();
    void command_G();
    void command_O();
    void command_Q();
    std::string gradeChange(std::string numTemp,std::string sentence);
    std::string numCheck(std::string numTemp,std::string sentence);
    std::string stringCheck(std::string strTemp, std::string sentence);
    std::string menuOption(std::string menuTemp,std::string sentence);

  private:
    bool charCheck, aCheck, idCheck;
    char read;
    std::string fHolder,lHolder, temp, menuT;
    int calc, idHolder;
    int arrH[6];
};
#endif
