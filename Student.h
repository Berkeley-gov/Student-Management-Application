#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Courses.h"
using namespace std;

class Student {
  public:
    // 15 Total public functions for the Student class.
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

    // 2 Constructors
    Student();
    Student(string name, int age);

  protected:
    // 7 Student's member variables
    vector<Courses> studentListOfCourses;
    vector<Student> studentRoster;
    double overallGPA;
    int studentID;
    int age;
    string name;
};

#endif 