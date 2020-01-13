#ifndef SCHOOLSYSTEM_H
#define SCHOOLSYSTEM_H
#include <string>
#include <vector>
#include <fstream>

const int numPrograms = 6;
const int numTests = 4;
const int numFinals = 1;

class schoolSystem
{
  public:
    schoolSystem(); //constructor
    ~schoolSystem(); //deconstructor
    //read or write or create files
    void resetDAT(std::string sentence);
    bool gradeCheck();
    bool fGradeCheck();
    bool readDAT();
    void writeDAT(int size,std::ofstream& out);
    void writeOUT(int size,std::ofstream& out);
    void writeTRN(std::string sentence);
    void insertStud(std::string last, std::string first, int idNum);
    bool findStud(std::string last);
    //setters & getters
    std::string get_fName(int loc);
    std::string get_lName(int loc);
    int get_studID(int loc);
    int get_studLoc();
    int get_progSize();
    int get_testSize();
    int get_finalSize();
    int get_pWeight();
    int get_tWeight();
    int get_fWeight();
    int get_studSize();
    int get_numProg();
    int get_numTest();
    int get_numFinal();
    int get_pAvg(int loc);
    int get_tAvg(int loc);
    int get_pGrade(int loc, int pNum);
    int get_tGrade(int loc, int tNum);
    int get_fExam(int loc);
    int get_fGrade(int loc);
    bool get_endSemester();
    bool get_newSemester();
    void set_fName(int loc, std::string name);
    void set_lName(int loc, std::string name);
    void set_studID(int loc, int idNum);
    bool set_progSize(int size);
    bool set_testSize(int size);
    bool set_finalSize(int size);
    void set_pWeight(int weight);
    void set_tWeight(int weight);
    void set_fWeight(int weight);
    void set_pGrade(int loc, int pNum, int grade);
    void set_tGrade(int loc, int tNum, int grade);
    void set_fExam(int loc, int grade);
    void set_fGrade(int loc, int grade);
    void set_pAvg(int loc, int grade);
    void set_tAvg(int loc, int grade);
    void set_endSemester(bool eCheck);
    void set_newSemester(bool nCheck);
  private:
    struct student{
      std::string fName;
      std::string lName;
      int pGrades[numPrograms];
      int tGrades[numTests];
      int fGrade,fExam, studID;
      int pAvg, tAvg;
    };
    std::vector <student> studV;
    bool check, endSemester, newSemester;
    std::string printSet1;
    std::string printSet2;
    int progSize, testSize, finalSize, studLoc;
    int studSize, pWeight, tWeight, fWeight;
};
#endif
