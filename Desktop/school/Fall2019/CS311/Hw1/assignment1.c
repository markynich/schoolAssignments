#include <stdio.h>
#include <stdlib.h>

enum LetterGrade {F, D, C, B, A};

//returns the average of all grades as a double
double getArrayAverage(double *p, double size)
{
  double sum = 0;
  for (int i = 0; i < size; i++){ sum += *(p+i); } //get sum of all values
  double avg = sum / size; //get average
  return avg;
}

//converts letter grade to integer value of the letter grade
int convertCharToLetterGrade(char grade)
{
  switch (grade)
  {
    case 'A': case 'a':
      return 4;
    case 'B': case 'b':
      return 3;
    case 'C': case 'c':
      return 2;
    case 'D': case 'd':
      return 1;
    case 'F': case 'f':
      return 0;
    default:
      printf("Warning... Invalid Character... Recording an F.\n");
      fflush(stdout); //flush out because of \n
      return 0;
  }
}
//converts double into char specifically exam avg to Letter Grade
char getLetterGradeFromAverage(double avg)
{
  if (avg >= 90)
    return 'A';
  else if (avg >= 80)
    return 'B';
  else if (avg >= 70)
    return 'C';
  else if (avg >= 60)
    return 'D';
  else
    return 'F';
}
/*
Start of Main
*/
int main(int argc, char *argv[])
{
  char firstName[20]; //assuming name is less than 20 characters
  printf("Please enter your first name: ");
  scanf("%s", firstName); //read user input
  while ((getchar()) != '\n'); //flush unneeded data
  char lastName[20]; //assuming name is less than 20 characters
  printf("Please enter your last name: ");
  scanf("%s", lastName);  //read user input
  while ((getchar()) != '\n');  //flush unneeded data
  int numPrevCourses;
  printf("Enter number of previous courses: ");
  scanf("%d", &numPrevCourses);
  while ((getchar()) != '\n'); //flush unneeded data
  int arraySize = numPrevCourses + 1; //increase array size by 1 for extra letter grade
  double* letterArr; //pointer for array of letter grades
  letterArr = calloc(arraySize,sizeof(double)); //allocate size
  double letterSize = 0; //counter for size of array
  /*
  Populate Array for letter grades
  */
  for (int courseIx = 0; courseIx < numPrevCourses; courseIx++)
  {
    int printIx = courseIx + 1; //for course output to start at 1
    printf("Enter letter grade for course %d as a letter: ", printIx);
    char gradeInput;
    gradeInput = getchar();
    while ((getchar()) != '\n');
    *(letterArr+courseIx) = convertCharToLetterGrade(gradeInput);//insert data
    letterSize++;
  }
  int numExams;
  printf("Enter number of exams this semester: ");
  scanf("%d", &numExams);
  while ((getchar()) != '\n'); //flush unneeded data
  double* gradeArr; //pointer for array of exam grades
  gradeArr = calloc(numExams, sizeof(double) ); //allocate size
  double gradeSize = 0;
  /*
  Populate Array for exam grades
  */
  for (int examIx = 0; examIx < numExams; examIx++)
  {
    int printIx = examIx + 1;
    printf("Enter grade for exam %d as as integer: ", printIx);
    double dTemp;
    scanf("%lf", &dTemp);
    while ((getchar()) != '\n'); //flush unneeded data
    *(gradeArr+examIx) = dTemp; //insert data
    gradeSize++;
  }
  printf("Grade Report For %s %s\n", firstName,lastName);
  fflush(stdout); //flush out because of \n
  double examAverage = getArrayAverage(gradeArr,gradeSize);
  printf("your exam average is: %lf\n", examAverage);
  fflush(stdout); //flush out because of \n
  char newAddition = getLetterGradeFromAverage(examAverage);
  int letterInt = letterSize++;
  *(letterArr+letterInt) = convertCharToLetterGrade(newAddition);
  double gpa = getArrayAverage(letterArr, letterSize);
  printf("Your latest GPA is: %lf \n", gpa);
  fflush(stdout); //flush out because of \n
return 0;
}
