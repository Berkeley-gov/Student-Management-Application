#ifndef COURSES_H
#define COURSES_H
#include <string>

using namespace std;

class Courses {
public:
	// Public member functions
	void AddCourse();
	string GetCourseName();
	string GetCRN();
	string GetTeacher();
	double GetUnits();
	char GetLetterGrade();

	// Courses Constructors 
	Courses();
	Courses(string courseName, string CRN, string nameTeacher, double classUnits, char studentGrade);

private:
	// Data members for each course object
	string nameOfCourse;
	string CRNOfCourse;
	string nameOfTeacher;
	double classUnits;
	char classLetterGrade;
};

#endif 