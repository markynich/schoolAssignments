#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio> //for remove function
#include <fstream>
#include "schoolSystem.h"

using namespace std;

  schoolSystem::schoolSystem()
  {
    studSize = 0;
    progSize = 0;
    testSize = 0;
    finalSize = 0;
    pWeight = 0;
    tWeight = 0;
    fWeight = 0;
    printSet1 = "progSize-testSize-numFinals-pWeight-tWeight-fWeight";
    printSet2 = "FirstName-LastName-studentID-prog1-prog2-prog3-prog4-prog5-prog6-progAvg-test1-test2-test3-test4-testAvg-fExam-fGrade";
    if (schoolSystem::readDAT() == false)
      newSemester = true;
    else if (schoolSystem::get_studSize() == 0)
      newSemester = true;
    else if (pWeight == 0 && tWeight == 0 && fWeight == 0)
      newSemester = true;
    else if (schoolSystem::gradeCheck() == true)
      newSemester = true;
    else
    {
      newSemester = false;
      endSemester = false;
    }
  };
  schoolSystem::~schoolSystem() {};
  /*
  Creates Grades.out, should be called at the
  end when done with everything.
  */
  bool schoolSystem::gradeCheck()
  {
    int progCheck = 0,testCheck = 0,finalCheck = 0;
    for (int i = 0; i < progSize;i++)
    {
      check = false;
      for (int j = 0; j < studSize;j++)
      {
        if (studV[j].pGrades[i] != 0)
        {
          check = true;
          j = studSize;
        }
      }
      if (check == true)
        progCheck++;
    }
    for (int i = 0; i < studSize;i++)
    {
      check = false;
      for (int j = 0; j < studSize;j++)
      {
        if (studV[j].pGrades[i] != 0)
        {
          check = true;
          j = studSize;
        }
      }
      if (check == true)
        testCheck++;
    }
    for (int i = 0; i < finalSize;i++)
    {
      check = false;
      for (int j = 0; j < studSize;j++)
      {
        if (studV[j].fExam != 0)
        {
          check = true;
          j = studSize;
        }
      }
      if (check == true)
        finalCheck++;
    }
    bool checkGrade = ((progCheck+testCheck+finalCheck) == 0);
    return checkGrade;
  }
  bool schoolSystem::fGradeCheck()
  {
    check = false;
    for (int j = 0; j < studSize;j++)
    {
      if (studV[j].fGrade != 0)
      {
        check = true;
        j = studSize;
      }
    }
    return check;
  }
  /*
  function to read Grades.dat which should be
  used in the beginning of program to get data
  from file
  */
  bool schoolSystem::readDAT()
  {
    ifstream rFile;
    rFile.open("Grades.dat");
    if (rFile.is_open())
    {
      string line, temp;
      getline(rFile, line);
      getline(rFile, line);
      stringstream ss(line);
      getline(ss, temp, ','); //program amount
      progSize = stoi(temp);
      getline(ss, temp, ','); //test amount
      testSize = stoi(temp);
      getline(ss, temp, ','); //final amount
      finalSize = stoi(temp);
      getline(ss, temp, ','); //prog weight %
      pWeight = stoi(temp);
      getline(ss, temp, ','); //test weight %
      tWeight = stoi(temp);
      getline(ss, temp, ','); //final weight %
      fWeight = stoi(temp);
      getline(rFile, line);
      while ( getline(rFile, line) ) //line by line
      {
        studV.push_back(student());
        stringstream ss2(line);
        getline(ss2, temp, ','); //first name
        studV[studSize].fName = temp;
        //fnList::insertNode(temp.c_str());
        //insert fName to list
        getline(ss2, temp, ','); //last name
        studV[studSize].lName = temp;
        //insert lName to list
        getline(ss2, temp, ','); //student ID
        //insert student ID to list
        studV[studSize].studID = stoi(temp);
        for (int i = 0; i < 6; i++) //program grades
        {
          getline(ss2, temp, ',');
          studV[studSize].pGrades[i] = stoi(temp);
        }
        getline(ss2, temp, ','); //program average
        studV[studSize].pAvg = stoi(temp);
        for (int i = 0; i < 4; i++) //test grades
        {
          getline(ss2, temp, ',');
          studV[studSize].tGrades[i] = stoi(temp);
        }
        getline(ss2, temp, ','); //test average
        studV[studSize].tAvg = stoi(temp);
        getline(ss2, temp, ','); //final exam
        studV[studSize].fExam = stoi(temp);
        getline(ss2, temp, ','); //final grade
        studV[studSize].fGrade = stoi(temp);
        studSize++;
      }
      check = true;
    } //end of if statement
    else
      check = false;
  rFile.close();
  return check;
  } //end of read grades.dat function
  void schoolSystem::writeDAT(int size,ofstream& out)
  {
    out << printSet1 << endl;
    out << progSize << ',' << testSize << ',' << finalSize << ',' << pWeight << ',' << tWeight << ',' << fWeight << endl;
    out << printSet2 << endl;
    for (int i = 0; i < size; i++)
    {
      out << studV[i].fName << ',';
      out << studV[i].lName << ',';
      out << studV[i].studID << ',';
      for (int j = 0; j < numPrograms; j++)
        out << studV[i].pGrades[j] << ',';
      out << studV[i].pAvg << ',';
      for (int f = 0; f < numTests; f++)
        out << studV[i].tGrades[f] << ',';
      out << studV[i].tAvg << ',';
      out << studV[i].fExam << ',';
      out << studV[i].fGrade << endl;
    }
  }
  void schoolSystem::writeOUT(int size,ofstream& out)
  {
    out << "End of Semester Summary" << "\n"
    << "Program Assgn Amount: " << progSize << "\n"
    << "Test Amount: " << testSize << "\n"
    << "Final Amount: " << numFinals << "\n"
    << "Program Weight: " << pWeight << "%\n"
    << "Test Weight: " << tWeight << "%\n"
    << "Final Weight: " << fWeight << "%\n";
    for (int i = 0; i < size; i++)
    {
      out << "-------------------------------------------------------\n";
      out << "Name:" << studV[i].fName << " ";
      out << studV[i].lName << "\n";
      out << "Student ID:" << studV[i].studID << "\n";
      if (progSize > 0)
      {
        out << "Program Assgn grades\n";
        for (int j = 0; j < progSize; j++)
          out << (j+1) << ". " << studV[i].pGrades[j] << "\n";
        out << "Average: " <<  studV[i].pAvg << "\n";
      }
      if (testSize > 0)
      {
      out << "Test grades\n";
        for (int f = 0; f < testSize; f++)
          out << (f+1) << ". " << studV[i].tGrades[f] << "\n";
        out << "Average: " << studV[i].tAvg << "\n";
      }
      if (finalSize > 0)
        out << "Final Exam: " << studV[i].fExam << "\n";
      out << "Final Grade: " << studV[i].fGrade << endl;
    }
  }
  void schoolSystem::writeTRN(string sentence)
  {
    ofstream oFile;
    oFile.open("Grades.trn",std::ios::app);
    if (oFile.is_open())
      oFile << sentence << endl;
    oFile.close();
  }
  void schoolSystem::insertStud(string last, string first, int idNum)
  {
    int location = 0;
    if (studSize == 0)
    {
      studSize++;
      studV.push_back(student());
      studV[location].lName = last;
      studV[location].fName = first;
      studV[location].studID = idNum;
    }
    else
    {
      bool moreToSearch = (location < studSize);
      while (moreToSearch)
      {
        if (studV[location].lName < last)
        {
          location++;
          moreToSearch = (location < studSize);
        }
        else
          moreToSearch = false;
      }
        studV.push_back(student());
        //moving students to add new student
        for (int i = studSize; i > location; i--)
        {
          studV[i].fName = studV[i-1].fName;
          studV[i].lName = studV[i-1].lName;
          studV[i].studID = studV[i-1].studID;
        }
        //adding new student
        studV[location].fName = first;
        studV[location].lName = last;
        studV[location].studID = idNum;
        studSize++;
    } //end of else
  }
  bool schoolSystem::findStud(string last)
  {
    studLoc = 0;
    bool moreToSearch = (studLoc < studSize);
    while (moreToSearch)
    {
      if (studV[studLoc].lName == last)
      {
        moreToSearch = false;
        check = true;
      }
      else
      {
        studLoc++;
        moreToSearch = (studLoc < studSize);
        check = false;
      }
    }
    return check;
  }
  /*
  Setters & Getters
  */
  string schoolSystem::get_fName(int loc) { return studV[loc].fName; }
  string schoolSystem::get_lName(int loc) { return studV[loc].lName; }
  int schoolSystem::get_studID(int loc) { return studV[loc].studID; }
  int schoolSystem::get_studLoc() { return studLoc; }
  int schoolSystem::get_progSize() { return progSize; }
  int schoolSystem::get_testSize() { return testSize; }
  int schoolSystem::get_finalSize() { return finalSize; }
  int schoolSystem::get_pWeight() { return pWeight; }
  int schoolSystem::get_tWeight() { return tWeight; }
  int schoolSystem::get_fWeight() { return fWeight; }
  int schoolSystem::get_studSize() { return studSize; }
  int schoolSystem::get_pAvg(int loc) { return studV[loc].pAvg; }
  int schoolSystem::get_tAvg(int loc) { return studV[loc].tAvg; }
  int schoolSystem::get_pGrade(int loc, int pNum) { return studV[loc].pGrades[pNum]; }
  int schoolSystem::get_tGrade(int loc, int tNum) { return studV[loc].tGrades[tNum]; }
  int schoolSystem::get_fExam(int loc) { return studV[loc].fExam; }
  int schoolSystem::get_fGrade(int loc) { return studV[loc].fGrade; }
  bool schoolSystem::get_endSemester() { return endSemester; }
  bool schoolSystem::get_newSemester(){return newSemester;}
  int schoolSystem::get_numProg(){return numPrograms;}
  int schoolSystem::get_numTest(){return numTests;}
  int schoolSystem::get_numFinal(){return numFinals;}
  void schoolSystem::set_fName(int loc, string name) { studV[loc].fName = name; }
  void schoolSystem::set_lName(int loc, string name) { studV[loc].lName = name; }
  void schoolSystem::set_studID(int loc, int idNum) { studV[loc].studID = idNum; }
  bool schoolSystem::set_progSize(int size)
  {
    if (size <= numPrograms)
    {
      progSize = size;
      check = true;
    }
    else
      check = false;
    return check;
  }
  bool schoolSystem::set_testSize(int size)
  {
    if (size <= numTests)
    {
     testSize = size;
     check = true;
    }
    else
      check = false;
    return check;
  }
  bool schoolSystem::set_finalSize(int size)
  {
    if (size <= numFinals)
    {
      finalSize = size;
      check = true;
    }
    else
      check = false;
    return check;
  }
  void schoolSystem::set_pWeight(int weight) { pWeight = weight; }
  void schoolSystem::set_tWeight(int weight) { tWeight = weight; }
  void schoolSystem::set_fWeight(int weight) { fWeight = weight; }
  void schoolSystem::set_pGrade(int loc, int pNum, int grade) { studV[loc].pGrades[pNum] = grade; }
  void schoolSystem::set_tGrade(int loc, int tNum, int grade) { studV[loc].tGrades[tNum] = grade; }
  void schoolSystem::set_fExam(int loc, int grade) { studV[loc].fExam = grade; }
  void schoolSystem::set_fGrade(int loc, int grade) { studV[loc].fGrade = grade; }
  void schoolSystem::set_pAvg(int loc, int grade) { studV[loc].pAvg = grade; }
  void schoolSystem::set_tAvg(int loc, int grade) { studV[loc].tAvg = grade; }
  void schoolSystem::set_endSemester(bool eCheck){ endSemester = eCheck; }
  void schoolSystem::set_newSemester(bool nCheck){ newSemester = nCheck; }
