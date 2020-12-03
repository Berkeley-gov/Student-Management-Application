#ifndef COURSES_H
#define COURSES_H
#include <string>

using namespace std;

class Courses {
  public:
    // 8 Public member functions
    Courses();
    Courses(string courseName, string CRN, string nameTeacher, double classUnits, char studentGrade);
    void AddCourse();
    string GetCourseName();
    string GetCRN();
    string GetTeacher();
    double GetUnits();
    char GetLetterGrade();

  private:
    // 5 Private data members for each course object
    string nameOfCourse;
    string CRNOfCourse;
    string nameOfTeacher;
    double classUnits;
    char classLetterGrade;
};

#endif 