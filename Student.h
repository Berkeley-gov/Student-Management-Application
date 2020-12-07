#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Courses.h"
using namespace std;

class Student {
public:
	// Public functions
	void CalculateGPA(Student& studentInput);
	void PrintRoster(vector<Student> student);
	void PrintStudentCompleteInfo(Student studentInput);
	void AddStudent(vector<Student>& students);
	void RemoveStudent(vector<Student>& students);
	void Modify(int key, vector <Student>& studentRoster);
	void setName(string name);
	void setAge(int age);
	void setGPA(double gpa);
	int getStudentID();
	double GetOverallGPA();
	string getName();
	int getAge();
	void AdditionalCourse(Student& studentInput);
	void PrintHonors(Student& studentInput);

	// Constructors for Student Class
	Student(string name, int age);
	Student();

protected:
	// Student's member variables
	vector<Courses> studentListOfCourses;
	vector<Student> studentRoster;
	double overallGPA;
	int studentID;
	string key;
	string name;
	int age;
};

#endif 