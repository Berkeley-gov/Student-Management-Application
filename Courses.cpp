#include <iostream>
#include <vector>
#include <string>
#include "Courses.h"
using namespace std;

// Courses default constructor 
Courses::Courses() {
	this->nameOfCourse = " ";
	this->CRNOfCourse = "NONE";
	this->nameOfTeacher = " ";
	this->classUnits = 0;
	this->classLetterGrade = 'E';
}

// Overloaded constructor @Parameters 3 string, 1 double and 1 Char
Courses::Courses(string courseName, string CRN, string nameTeacher, double numOfUnits, char studentGrade) {
	this->nameOfCourse = courseName;
	this->CRNOfCourse = CRN;
	this->nameOfTeacher = nameTeacher;
	this->classUnits = numOfUnits;
	this->classLetterGrade = studentGrade;
}

// Adds a course to the student's list of courses 
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

		} while(letterInput != 'A' && letterInput != 'B' &&
			letterInput != 'C' && letterInput != 'D' &&
			letterInput != 'F');

		// Assign all the variables
		this->nameOfCourse = courseInput;
		this->CRNOfCourse = CRNInput;
		this->nameOfTeacher = teacherInput;
		this->classUnits = unitInput;
		this->classLetterGrade = letterInput;
}

// Retrives the name of the course
string Courses::GetCourseName() {
	return nameOfCourse;
}

// Retrives the course registeration number
string Courses::GetCRN() {
	return CRNOfCourse;
}

// Retrives the courses teacher who is teaching the course
string Courses::GetTeacher() {
	return nameOfTeacher;
}

// Retrives the number of units for a course
double Courses::GetUnits() {
	return classUnits;
}

// Retrives the letter grade achieved for the course
char Courses::GetLetterGrade() {
	return classLetterGrade;
}