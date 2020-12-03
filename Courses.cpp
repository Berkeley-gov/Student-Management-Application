#include <iostream>
#include <vector>
#include <string>
#include "Courses.h"
using namespace std;

// ******************** Class Constructors ********************

// Default constructor for Course object
Courses::Courses() {
	this->nameOfCourse = " ";
	this->CRNOfCourse = "NONE";
	this->nameOfTeacher = " ";
	this->classUnits = 0;
	this->classLetterGrade = 'E';
}

// Overloaded constructor. @Parameters course name, course number, teacher name, num of units, and letter grade.
Courses::Courses(string courseName, string CRN, string nameTeacher, double numOfUnits, char studentGrade) {
	this->nameOfCourse = courseName;
	this->CRNOfCourse = CRN;
	this->nameOfTeacher = nameTeacher;
	this->classUnits = numOfUnits;
	this->classLetterGrade = studentGrade;
}

// ******************** Setter and Getters ********************

// Retrives the course's name
string Courses::GetCourseName() {
	return nameOfCourse;
}

// Retrives the course's registeration number 
string Courses::GetCRN() {
	return CRNOfCourse;
}

// Retrives the name of teacher who taught the course
string Courses::GetTeacher(){
	return nameOfTeacher;
}

// Retrives the course's unit count 
double Courses::GetUnits() {
	return classUnits;
}

// Retrives the letter grade the student got for the course
char Courses::GetLetterGrade() {
	return classLetterGrade;
}

// ******************** CRUD Functions ********************

// Adds a course to the a student's list of courses 
void Courses::AddCourse() {
	string courseInput;
	string CRNInput;
	string teacherInput;
	double unitInput;
	char letterInput;

	cin.ignore();
	cout << "Enter name of course:\n";
	getline(cin, courseInput);
	cout << "Enter CRN of course:\n";
	cin >> CRNInput;
	cout << "Enter teacher's name:\n";
	cin.ignore();
	getline(cin, teacherInput);
	cout << "Enter the course's units:\n";
	cin >> unitInput;

	if (unitInput < 0.0 || unitInput > 5.0) {
		do {
			cout << "Your number of units is invalid.\n";
			cout << "Please enter a valid number of units. \n";
			cin >> unitInput;

		} while(unitInput < 0 || unitInput > 5);
	}

	cout << "Enter the letter grade that the student got (A, B, C, D, F):\n";
	cin >> letterInput;

	if (letterInput != 'A' && letterInput != 'B' &&
		letterInput != 'C' && letterInput != 'D' &&
		letterInput != 'F')
		do {
			cout << "Your letter grade input was invalid.\n";
			cout << "Please enter a valid letter grade: \n";
			cin >> letterInput;

		} while(letterInput != 'A' && letterInput != 'B' && letterInput != 'C' && letterInput != 'D' && letterInput != 'F');

		// Assigns all the variables
		this->nameOfCourse = courseInput;
		this->CRNOfCourse = CRNInput;
		this->nameOfTeacher = teacherInput;
		this->classUnits = unitInput;
		this->classLetterGrade = letterInput;
}