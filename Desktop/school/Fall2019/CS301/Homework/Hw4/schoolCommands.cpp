#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio> //for remove function
#include <stdlib.h> //for exit function
#include <fstream>
#include "schoolCommands.h"

using namespace std;

schoolCommands::schoolCommands(){}
schoolCommands::~schoolCommands(){}
char schoolCommands::ComparedTo(char item)
{
  switch (item)
  {
    case 'S': case 's':
      charCheck = true;
      return 'S';
    case 'A': case 'a':
      charCheck = true;
      return 'A';
    case 'P': case 'p':
      charCheck = true;
      return 'P';
    case 'T': case 't':
      charCheck = true;
      return 'T';
    case 'F': case 'f':
      charCheck = true;
      return 'F';
    case 'C': case 'c':
      charCheck = true;
      return 'C';
    case 'G': case 'g':
      charCheck = true;
      return 'G';
    case 'O': case 'o':
      charCheck = true;
      return 'O';
    case 'Q': case 'q':
      charCheck = true;
      return 'Q';
    default:
      return 'E';
  }
}
void schoolCommands::clearScreen(){ cout << "\033[2J\033[1;1H"; }
void schoolCommands::readCommand()
{
  charCheck = false;
  schoolCommands::clearScreen();
  while (charCheck != true)
  {
  cout << "------Use characters to enter input------\n"
  << "Here are your list of option:\n"
  << "S. Create a new semester\n"
  << "A. Add a new student\n"
  << "P. Record program grade for all students\n"
  << "T. Record test grade for all students\n"
  << "F. Record final exam for all students\n"
  << "C. Change grade for a specific student\n"
  << "G. Calculate the final grade for all students\n"
  << "O. print out the final transcript onto Grades.out\n"
  << "Q. Quit & save current semester\nUser Input: ";
  cin.get(read);
  cin.ignore(); //clear buffer
  if ( schoolCommands::ComparedTo(read) == 'E')
    {
      schoolCommands::clearScreen();
      cout << "\n------Error, not an option. Try again------\n";
      cout << read << endl;
    }
  }
  schoolCommands::switchCommand(read,charCheck);
}
void schoolCommands::readCommand(std::string sentence)
{
  charCheck = false;
  schoolCommands::clearScreen();
  cout << "\n\n";
  cout << sentence << "\n\n";
  while (charCheck != true)
  {
  cout << "------Use characters to enter input------\n"
  << "Here are your list of option:\n"
  << "S. Create a new semester\n"
  << "A. Add a new student\n"
  << "P. Record program grade for all students\n"
  << "T. Record test grade for all students\n"
  << "F. Record final exam for all students\n"
  << "C. Change grade for a specific student\n"
  << "G. Calculate the final grade for all students\n"
  << "O. print out the final transcript onto Grades.out\n"
  << "Q. Quit & save current semester\nUser Input: ";
  cin.get(read);
  cin.ignore(); //clear buffer
  if ( schoolCommands::ComparedTo(read) == 'E')
    {
      schoolCommands::clearScreen();
      cout << "\n------Error, not an option. Try again------\n";
      cout << read << endl;
    }
  }
  schoolCommands::switchCommand(read,charCheck);
}
void schoolCommands::switchCommand(char item,bool checkC)
{
  if (checkC == true)
  {
    switch (item)
    {
      case 'S': case 's':
        schoolCommands::command_S();
        break;
      case 'A': case 'a':
        schoolCommands::command_A();
        break;
      case 'P': case 'p':
        schoolCommands::command_P();
        break;
      case 'T': case 't':
        schoolCommands::command_T();
        break;
      case 'F': case 'f':
        schoolCommands::command_F();
        break;
      case 'C': case 'c':
        schoolCommands::command_C();
        break;
      case 'G': case 'g':
        schoolCommands::command_G();
        break;
      case 'O': case 'o':
        schoolCommands::command_O();
        break;
      case 'Q': case 'q':
        schoolCommands::command_Q();
        break;
    default:
      cout << "Error at switchCommands\n";
    }
  }
}
//need to add delete file function
//change whiles to do while
void schoolCommands::command_S()
{
  string sentSemester;
  if (schoolSystem::fGradeCheck() == true )
    schoolCommands::readCommand("Error! Semester has ended, please exit program to check final transcript\nBefore starting a new semester");
  if (schoolSystem::get_newSemester() == true)
  {
    schoolCommands::clearScreen();
    cout << "\n\n\nThis command will delete the old data: Grades.dat & Grades.out\n\n\n";
    bool menuCheck = false;
    while (menuCheck == false)
    {
      cout << "Would you like to continue? [y/Y]Yes or [q/Q]Quit: ";
      cin >> menuT;
      cin.ignore();
      if (menuT == "Q" || menuT == "q")
        schoolCommands::readCommand();
      else if (menuT == "Y" || menuT == "y")
      {
        menuCheck = true;
        remove("Grades.dat");
        remove("Grades.out");
        remove("Grades.trn");
      }
      else
        cout << "Error! Please enter only [y/Y] or [q/Q]!\n";
    }
    schoolCommands::clearScreen();
    cout << "--------- Starting a new Semester! ---------\n";
    cout << "-------- Older data will now be deleted --------\n";
    cout << "Let's first enter the relative weights of Programs, Tests, and Finals\n\n";
    do {
      arrH[0] = stoi(schoolCommands::numCheck(temp, "Please enter the weight for program assignments: "));
      arrH[1] = stoi(schoolCommands::numCheck(temp, "Please enter the weight for tests: "));
      arrH[2] = stoi(schoolCommands::numCheck(temp, "Please enter the weight for program Final: "));
      arrH[3] = arrH[0] + arrH[1] + arrH[2];
      if (arrH[3] != 100)
        cout << "the sum of the weights should be 100%\n";
      } while (arrH[3] != 100);
      schoolSystem::set_pWeight(arrH[0]);
      schoolSystem::set_tWeight(arrH[1]);
      schoolSystem::set_fWeight(arrH[2]);
      schoolCommands::clearScreen();
    cout << "Let's now enter the amount of Programs, Tests , and Finals students will take\n\n";
    if (arrH[0] > 0)
    {
    do {
      arrH[0] = stoi(schoolCommands::numCheck(temp,"Please enter the amount for program assignments(0-6): "));
      if (arrH[0] > schoolSystem::get_numProg() || arrH[0] < 0)
        cout << "Error, please enter correct amount\n";
    } while (arrH[0] > schoolSystem::get_numProg() || arrH[0] < 0);
    schoolSystem::set_progSize(arrH[0]);
    }
    if (arrH[1] > 0)
    {
    do {
      arrH[1] = stoi(schoolCommands::numCheck(temp,"Please enter the amount for tests(0-4): "));
      if (arrH[1] > schoolSystem::get_numTest() || arrH[1] < 0)
        cout << "Error, please enter correct amount\n";
    } while (arrH[1] > schoolSystem::get_numTest() || arrH[1] < 0);
    schoolSystem::set_testSize(arrH[1]);
    }
    if (arrH[2] > 0)
    {
    do {
      arrH[2] = stoi(schoolCommands::numCheck(temp,"Please enter the amount for finals(0-1): "));
      if (arrH[2] > schoolSystem::get_numFinal() || arrH[2] < 0)
        cout << "Error, please enter correct amount\n";
    } while (arrH[2] > schoolSystem::get_numFinal() || arrH[2] < 0);
    schoolSystem::set_finalSize(arrH[2]);
    }
    sentSemester = "New Semester has started. Weights and Amounts of programs, tests, and finals as been recorded";
    schoolSystem::writeTRN(sentSemester);
    schoolCommands::readCommand();
  }
  else
    schoolCommands::readCommand("Error! cannot start a new semester until final transcripts are printed");
  schoolSystem::set_endSemester(false);
}
/*
  Add student: firstN,lastN,studID
  check studID; call insertStud
  can only add during new semester
*/
//change while to do while
void schoolCommands::command_A()
{
  string sentA;
  if (schoolSystem::fGradeCheck() == true )
    schoolCommands::readCommand("Error! Semester has ended, need to start new semester");
  if (schoolSystem::get_newSemester() == true )
  {
    aCheck = false;
    schoolCommands::clearScreen();
    cout << "----------Adding a new student----------\n";
    cout << "Students can only be added during a new semester\n";
    for (int i = 0; i < schoolSystem::get_studSize();i++)
      cout << schoolSystem::get_fName(i) << " " << schoolSystem::get_lName(i) << " " << schoolSystem::get_studID(i) << endl;
  //First Name
      fHolder = schoolCommands::stringCheck(temp,"Enter first name: ");
      lHolder = schoolCommands::stringCheck(temp,"Enter last name: ");
  //student ID
  while (aCheck == false)
  {
    idCheck = false;
    while (idCheck == false)
    {
       menuT = schoolCommands::numCheck(temp,"Enter student ID(from 0 - 9999): ");
        idHolder = stoi(menuT);
      if (idHolder > 9999)
        cout << "Error, ID is greater than 9999\n";
      else
        idCheck = true;
    }
      if (schoolSystem::get_studSize() == 0)
      {
        schoolSystem::insertStud(lHolder,fHolder,idHolder);
        aCheck = true;
      }
      else
      {
      //check if student has the identical student ID
        for (int i = 0; i < schoolSystem::get_studSize();i++)
        {
          if (schoolSystem::get_studID(i) == idHolder)
          {
            i = schoolSystem::get_studSize();
            cout << "student already has this ID: " << idHolder << endl;
            idCheck = false;
          }
        }
      if (idCheck != false)
      {
        schoolSystem::insertStud(lHolder,fHolder,idHolder);
        aCheck = true;
      }
    }
  }
    sentA = "New Student Added. " + fHolder + " " + lHolder + " ID:" + to_string(idHolder);
    schoolSystem::writeTRN(sentA);
    schoolCommands::readCommand();
  }
  else
  {
    string errorComA = "Error! Semester has started, cannot add more students\nStudents can only be added before the first grade";
    schoolCommands::readCommand("Error! Semester has started, cannot add more students");
  }
}
/*
add program grades to students
need specific program input
*/
//needs revising
void schoolCommands::command_P()
{
  string sentP;
  if (schoolSystem::fGradeCheck() == true)
    schoolCommands::readCommand("Error! Semester has ended, need to start new semester");
  if (schoolSystem::get_studSize() > 0 && schoolSystem::get_progSize() > 0 )
  {
    schoolCommands::clearScreen();
    for (int i = 0; i < schoolSystem::get_progSize();i++)
    {
      aCheck = false;
      for (int j = 0; j < schoolSystem::get_studSize();j++)
      {
        if (schoolSystem::get_pGrade(j,i) != 0)
        {
          aCheck = true;
          j = schoolSystem::get_studSize();
        }
      }
        if (aCheck == true)
        cout << "Program " << (i+1) << " is done grading\n";
      else
        cout << "Program " << (i+1) << " is not done grading\n";
    }
    cout << "\n\n";
    aCheck = false;
    while (aCheck == false)
    {
      menuT = schoolCommands::menuOption(temp,"Select Program Assignment would you like to grade or [Q/q] to quit: ");
      if (menuT == "Q" || menuT == "q")
        schoolCommands::readCommand();
      arrH[0] = stoi(menuT);
      if (arrH[0] <= schoolSystem::get_progSize() && arrH[0] > 0)
      {
        for (int i = 0; i < schoolSystem::get_studSize();i++)
        {
          cout << "For " << schoolSystem::get_fName(i) << " " << schoolSystem::get_lName(i) << " " << schoolSystem::get_studID(i) << endl;
          do
          {
            string strAssgn = "Enter grade for assignment #" + to_string(arrH[0]) + ": ";
            arrH[1] = stoi(schoolCommands::gradeChange(temp,strAssgn));
          }
          while (arrH[1] > 100 || arrH[1] < 0);
          schoolSystem::set_pGrade(i,(arrH[0]-1),arrH[1]);
          sentP = schoolSystem::get_fName(i) + " " + schoolSystem::get_lName(i) + " ID:" + to_string(schoolSystem::get_studID(i)) + " Program #" + to_string(arrH[0]) + " grade: " + to_string(arrH[1]);
          schoolSystem::writeTRN(sentP);
        }
        aCheck = true;
      }
      else
        cout << "Error! Please Enter a correct assignment #\n";
    }
    schoolCommands::readCommand();
}
  else
    schoolCommands::readCommand("Error! there are no students or assignments this semester");
}
/*
add test grades to students
need specific test input
*/
//needs revising
void schoolCommands::command_T()
{
  string sentT;
  if (schoolSystem::fGradeCheck() == true )
    schoolCommands::readCommand("Error! Semester has ended, need to start new semester");
  if (schoolSystem::get_studSize() > 0 && schoolSystem::get_testSize() > 0 )
  {
    schoolCommands::clearScreen();
    for (int i = 0; i < schoolSystem::get_testSize();i++)
    {
      aCheck = false;
      for (int j = 0; j < schoolSystem::get_studSize();j++)
      {
        if (schoolSystem::get_tGrade(j,i) != 0)
        {
          aCheck = true;
          j = schoolSystem::get_studSize();
        }
      }
        if (aCheck == true)
        cout << "Test " << (i+1) << " is done grading\n";
      else
        cout << "Test " << (i+1) << " is not done grading\n";
    }
    cout << "\n\n";
    aCheck = false;
    while (aCheck == false)
    {
      menuT = schoolCommands::menuOption(temp,"Select Test would you like to grade or [Q/q] to quit: ");
      if (menuT == "Q" || menuT == "q")
        schoolCommands::readCommand();
      arrH[0] = stoi(menuT);
      if (arrH[0] <= schoolSystem::get_testSize() && arrH[0] > 0)
      {
        for (int i = 0; i < schoolSystem::get_studSize();i++)
        {
          cout << "For " << schoolSystem::get_fName(i) << " " << schoolSystem::get_lName(i) << " " << schoolSystem::get_studID(i) << endl;
          do
          {
            string strAssgn1 = "Enter grade for Test #" + to_string(arrH[0]) + ": ";
            arrH[1] = stoi(schoolCommands::gradeChange(temp,strAssgn1));
          }
          while (arrH[1] > 100 || arrH[1] < 0);
          schoolSystem::set_tGrade(i,(arrH[0]-1),arrH[1]);
          sentT = schoolSystem::get_fName(i) + " " + schoolSystem::get_lName(i) + " ID:" + to_string(schoolSystem::get_studID(i)) + " Test #" + to_string(arrH[0]) + " grade: " + to_string(arrH[1]);
          schoolSystem::writeTRN(sentT);
        }
        aCheck = true;
      }
      else if (arrH[0] == 'Q' || arrH[0] == 'q')
        aCheck = true;
      else
        cout << "Error! Please Enter a correct Test #\n";
    }
    schoolCommands::readCommand();
  }
  else
    schoolCommands::readCommand("Error! There are no students or tests this semester");
}
/*
add final exam grades to students
*/
void schoolCommands::command_F()
{
  string sentF;
  if (schoolSystem::fGradeCheck() == true )
    schoolCommands::readCommand("Error! Semester has ended, need to start new semester");
  if (schoolSystem::get_studSize() > 0 && schoolSystem::get_finalSize() > 0 )
  {
    schoolCommands::clearScreen();
    aCheck = false;
    for (int j = 0; j < schoolSystem::get_finalSize();j++)
    {
      if (schoolSystem::get_fExam(j) != 0)
      {
        aCheck = true;
        j = schoolSystem::get_finalSize();
      }
    }
    if (aCheck == true)
      cout << "Final Exam is done grading\n\n\n";
    else
      cout << "Final Exam is not done grading\n\n\n";
    aCheck = false;
    while (aCheck == false)
    {
      cout << "Would you like to grade the final now [Y/y]yes or [Q/q] to quit: ";
      cin >> menuT;
      cin.ignore();
      if (menuT == "Q" || menuT == "q")
        schoolCommands::readCommand();
      else if (menuT == "Y" || menuT == "y")
      {
        for (int i = 0; i < schoolSystem::get_studSize();i++)
        {
          cout << "For " << schoolSystem::get_fName(i) << " " << schoolSystem::get_lName(i) << " " << schoolSystem::get_studID(i) << endl;
          arrH[1] = stoi(schoolCommands::gradeChange(temp,"Enter grade for Final: "));
          schoolSystem::set_fExam(i,arrH[1]);
          sentF = schoolSystem::get_fName(i) + " " + schoolSystem::get_lName(i) + " ID:" + to_string(schoolSystem::get_studID(i)) + " Final" + " grade: " + to_string(arrH[1]);
          schoolSystem::writeTRN(sentF);
        }
        aCheck = true;
      }
      else
        cout << "Error! Please enter a correct option\n";
    }
    schoolCommands::readCommand();
  }
  else
    schoolCommands::readCommand("Error! there are no finals to grade in this semester");
}
/*
change specific students grade
*/
void schoolCommands::command_C()
{
  string sentC;
  if (schoolSystem::fGradeCheck() == true )
    schoolCommands::readCommand("Error! Semester has ended, need to start new semester");
  if (schoolSystem::get_studSize() > 0 && (schoolSystem::get_progSize() > 0 || schoolSystem::get_testSize() > 0 || schoolSystem::get_finalSize() > 0) )
  {
    schoolCommands::clearScreen();
    cout << "Please select a student you like to modify his/her grade\n\n";
    for (int i = 0; i < schoolSystem::get_studSize(); i++)
      cout << (i+1) << ". " << schoolSystem::get_fName(i) << " " << schoolSystem::get_lName(i) << " " << schoolSystem::get_studID(i) << endl;
    do {
      string senS = "Enter an option from [1-" + to_string(schoolSystem::get_studSize()) + "] or [Q/q] to quit: ";
      menuT = schoolCommands::menuOption(temp,senS);
      if (menuT == "Q" || menuT == "q")
        schoolCommands::readCommand();
      arrH[0] = stoi(menuT);
      if (arrH[0] > schoolSystem::get_studSize() || arrH[0] < 0)
        cout << "Error! Option is not available\n";
    } while( arrH[0] > schoolSystem::get_studSize() || arrH[0] < 0);
    schoolCommands::clearScreen();
    cout << "Please Select an option below\n"
         << "1. Change a program grade\n"
         << "2. Change a test grade\n"
         << "3. Change a final grade\n"
         << "-------------------------------\n";
    do {
    arrH[1] = stoi(schoolCommands::numCheck(temp,"Please make a selection: "));
    } while (arrH[1] > 3 || arrH[1] < 0);
  switch(arrH[1])
  {
      case 1:
      if (schoolSystem::get_progSize() > 0)
      {
        string strP = "Which Program would you like to change grade [1-" + to_string(schoolSystem::get_progSize()) + "]: ";
        do {
        arrH[2] = stoi(schoolCommands::numCheck(temp,strP));
        if (arrH[2] > schoolSystem::get_progSize() || arrH[2] < 0)
          cout << "Error! Input must be within selection\n";
        } while (arrH[2] > schoolSystem::get_progSize() || arrH[2] < 0);
        schoolSystem::set_pGrade((arrH[0]-1),(arrH[2]-1),stoi(schoolCommands::gradeChange(temp,"Enter the grade: ")));
        sentC = schoolSystem::get_fName((arrH[0]-1)) + " " + schoolSystem::get_lName((arrH[0]-1)) + " ID:" + to_string(schoolSystem::get_studID((arrH[0]-1))) + " Program #" + to_string((arrH[2])) + " grade: " + to_string(schoolSystem::get_pGrade((arrH[0]-1),(arrH[2]-1)));
        schoolSystem::writeTRN(sentC);
      }
      else
        cout << "Error! No programs this semester\n";
      break;
      case 2:
      if (schoolSystem::get_testSize() > 0)
      {
        string strP = "Which Test would you like to change grade [1-" + to_string(schoolSystem::get_testSize()) + "]: ";
        do {
          arrH[2] = stoi(schoolCommands::numCheck(temp,strP));
          if (arrH[2] > schoolSystem::get_testSize() || arrH[2] < 0)
            cout << "Error! Input must be within selection\n";
        } while (arrH[2] > schoolSystem::get_testSize() || arrH[2] < 0);
        schoolSystem::set_tGrade((arrH[0]-1),(arrH[2]-1),stoi(schoolCommands::gradeChange(temp,"Enter the grade: ")));
        sentC = schoolSystem::get_fName((arrH[0]-1)) + " " + schoolSystem::get_lName((arrH[0]-1)) + " ID:" + to_string(schoolSystem::get_studID((arrH[0]-1))) + " Test #" + to_string((arrH[2])) + " grade: " + to_string(schoolSystem::get_tGrade((arrH[0]-1),(arrH[2]-1)));
        schoolSystem::writeTRN(sentC);
      }
      else
        cout << "Error! No tests this semester\n";
      break;
      case 3:
      if (schoolSystem::get_finalSize() > 0)
      {
        string strP = "Enter new grade for Final: ";
        arrH[2] = stoi(schoolCommands::gradeChange(temp,strP));
        schoolSystem::set_fExam((arrH[0]-1),arrH[2]);
        sentC = schoolSystem::get_fName((arrH[0]-1)) + " " + schoolSystem::get_lName((arrH[0]-1)) + " ID:" + to_string(schoolSystem::get_studID((arrH[0]-1))) + " Final" + " grade: " + to_string(schoolSystem::get_fExam((arrH[0]-1)));
        schoolSystem::writeTRN(sentC);
      }
      else
        cout << "Error! No finals this semester\n";
      break;

  }
    schoolCommands::readCommand();
  }
  else
    schoolCommands::readCommand("Error! No students, programs, tests, or finals to modify this semester");
}
/*
calculate final grade
check if all progs,tests,& final exams are done.
before calucating
*/
void schoolCommands::command_G()
{
  string sentG;
  if (schoolSystem::fGradeCheck() == true )
    schoolCommands::readCommand("Error! Semester has ended, need to start new semester");
  int progCheck = 0,testCheck = 0,finalCheck = 0;
  if (schoolSystem::get_studSize() > 0)
  {
    for (int i = 0; i < schoolSystem::get_progSize();i++)
    {
      aCheck = false;
      for (int j = 0; j < schoolSystem::get_studSize();j++)
      {
        if (schoolSystem::get_pGrade(j,i) != 0)
        {
          aCheck = true;
          j = schoolSystem::get_studSize();
        }
      }
      if (aCheck == true)
        progCheck++;
    }
    if (progCheck != schoolSystem::get_progSize())
      schoolCommands::readCommand("Error! Not all programs have been graded");
    for (int i = 0; i < schoolSystem::get_testSize();i++)
    {
      aCheck = false;
      for (int j = 0; j < schoolSystem::get_studSize();j++)
      {
        if (schoolSystem::get_tGrade(j,i) != 0)
        {
          aCheck = true;
          j = schoolSystem::get_studSize();
        }
      }
      if (aCheck == true)
        testCheck++;
    }
    if (testCheck != schoolSystem::get_testSize())
      schoolCommands::readCommand("Error! Not all tests have been graded");
    for (int i = 0; i < schoolSystem::get_finalSize();i++)
    {
      aCheck = false;
      for (int j = 0; j < schoolSystem::get_studSize();j++)
      {
        if (schoolSystem::get_fExam(j) != 0)
        {
          aCheck = true;
          j = schoolSystem::get_studSize();
        }
      }
      if (aCheck == true)
        finalCheck++;
    }
    if (finalCheck != schoolSystem::get_finalSize())
      schoolCommands::readCommand("Error! The Final has not been graded");
    else
    {
      for (int i = 0; i < schoolSystem::get_studSize();i++)
      {
        int tempNumP = 0,tempNumT = 0, tempNumF = 0;
        if (schoolSystem::get_progSize() > 0)
        {
        for (int j = 0; j < schoolSystem::get_progSize();j++)
          tempNumP += schoolSystem::get_pGrade(i,j);
        tempNumP = (tempNumP/schoolSystem::get_progSize());
        schoolSystem::set_pAvg(i,tempNumP);
        tempNumP = (tempNumP*schoolSystem::get_pWeight()/100);
        }
        if (schoolSystem::get_testSize() > 0)
        {
        for (int f = 0; f < schoolSystem::get_testSize();f++)
          tempNumT += schoolSystem::get_tGrade(i,f);
        tempNumT = (tempNumT/schoolSystem::get_testSize());
        schoolSystem::set_tAvg(i,tempNumT);
        tempNumT = (tempNumT*schoolSystem::get_tWeight()/100);
        }
        if (schoolSystem::get_finalSize() > 0)
          tempNumF = (schoolSystem::get_fExam(i)*schoolSystem::get_fWeight()/100);

        schoolSystem::set_fGrade(i,(tempNumP+tempNumT+tempNumF));
        sentG = schoolSystem::get_fName(i) + " " + schoolSystem::get_lName(i) + " ID:" + to_string(schoolSystem::get_studID(i)) + " Final Grade: " + to_string(schoolSystem::get_fGrade(i)) + " pAvg: " + to_string(schoolSystem::get_pAvg(i)) + " tAvg: " + to_string(schoolSystem::get_tAvg(i));
        schoolSystem::writeTRN(sentG);
      }
      //schoolSystem::set_endSemester(true);
    }
    schoolCommands::readCommand("Final Grades have been submitted into the system");
  }
  else
    schoolCommands::readCommand("Error! There are no students this semester");
}
/*
end semester, print transcript into grades.out
*/
void schoolCommands::command_O()
{
  string sentO;
  if (schoolSystem::fGradeCheck() == true)
  {
  sentO = "Semester Transcript has been made, semester is over";
  schoolSystem::writeTRN(sentO);
  ofstream oFile;
  oFile.open("Grades.out");
  if (oFile.is_open())
    schoolSystem::writeOUT(schoolSystem::get_studSize(),oFile);
  else
    cout << "File could not be written\n";
  oFile.close();
  schoolSystem::set_endSemester(true);
  schoolCommands::readCommand("Semester Summary has been printed into Grades.out\nGrades.dat has been deleted");
  }
  else
    schoolCommands::readCommand("Final Grades have not been submitted yet");
}
/*
  exit program function
*/
//grades do not print correctly, only prints pointer values
void schoolCommands::command_Q()
{
  string sentQ;
  sentQ = "Exiting Program";
  schoolSystem::writeTRN(sentQ);
  ofstream oFile;
  if (schoolSystem::get_endSemester() == true)
    remove("Grades.dat");
  else
  {
    oFile.open("Grades.dat");
    if (oFile.is_open())
      schoolSystem::writeDAT(schoolSystem::get_studSize(),oFile);
      else
      cout << "File has not been written\n";
  }
  oFile.close();
  exit (0);
}
string schoolCommands::gradeChange(string numTemp,string sentence)
{
  do {
    cout << sentence;
    cin >> numTemp;
    cin.ignore();
    if (numTemp.find_first_not_of("0123456789") != string::npos)
      cout << "Error! Input must be numbers only!\n";
    else if (stoi(numTemp) < 0 || stoi(numTemp) > 100)
      cout << "Error! Input must be within 0-100\n";
  } while (numTemp.find_first_not_of("0123456789") != string::npos || stoi(numTemp) > 100 || stoi(numTemp) < 0);
  return numTemp;
}
string schoolCommands::numCheck(string numTemp,string sentence)
{
  do {
    cout << sentence;
    cin >> numTemp;
    cin.ignore();
    if (numTemp.find_first_not_of("0123456789") != string::npos)
      cout << "Error! Input must be numbers only!\n";
  } while (numTemp.find_first_not_of("0123456789") != string::npos);
  return numTemp;
}
string schoolCommands::stringCheck(string strTemp, string sentence)
{
  do {
    cout << sentence;
    cin >> strTemp;
    cin.ignore();
    if (strTemp.find_first_of("0123456789") != string::npos)
      cout << "Error! Input cannot have numbers!\n";
  } while (strTemp.find_first_of("0123456789") != string::npos);
  return strTemp;
}
string schoolCommands::menuOption(string menuTemp,string sentence)
{
  bool menuCheck = false;
  while (menuCheck == false)
  {
    cout << sentence;
    cin >> menuTemp;
    cin.ignore();
    if (menuTemp == "Q" || menuTemp == "q")
      menuCheck = true;
    else if (menuTemp.find_first_not_of("0123456789") != string::npos)
      cout << "Error! Not within the menu selection!\n";
    else
      menuCheck = true;
  }
  return menuTemp;
}
