#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Student.h"
#include "Courses.h"
using namespace std;

// ******************** Class Constructors ********************

// Default constructor for Student object. Sets default values 
Student::Student() {
	this->name = "empty";
	this->age = 00;
	this->studentID = rand();
}

// Overloaded constructor: @Parameters student name and age
Student::Student(string name, int age) {
  // Note: Student ID is generated randomly once class is instantiated 
	this->name = name;
	this->age = age;
	this->studentID = rand(); 
	this->overallGPA = 0.0;
}

// ******************** Setter and Getters ********************

// Sets the student's name
void Student::setName(string name) {
	this->name = name;
}

// Retrives the student's name
string Student::getName() {
	return this->name;
}

// Retrives the student's age 
int Student::getAge() {
	return this->age;
}

// Sets the student's age @Parameter student age
void Student::setAge(int age) {
	this->age = age;
}

// Retrives the student's ID 
int Student::getStudentID() {
	return this->studentID;
}

// Sets the student gpa @Paramter student gpa
void Student::setGPA(double gpa) //TODO: Change the method name 
{
	this->overallGPA = gpa;
}

// Retrives the student's overall GPA 
double Student::GetOverallGPA()
{
	return overallGPA;
}

// ******************** CRUD Functions ********************

// Adds a student to the roster 
void Student::AddStudent(vector<Student>& students) {
	string newName;
	int newAge;

	cout << "** ADD STUDENT **\n" << endl;
	cout << "Enter student's name: " << endl;
	getline(cin, newName);
	cout << endl;

	cout << "Enter student's age: " << endl;
	cin >> newAge;
	cout << endl;

	students.push_back(Student(newName, newAge));
}

// Adds a course in a student's list of courses
void Student::AdditionalCourse(Student& studentInput) {
	Courses coursePlaceHolder;
	coursePlaceHolder.AddCourse();
	studentInput.studentListOfCourses.push_back(coursePlaceHolder);
}

// Prints out a student's information and their list of courses
void Student::PrintStudentCompleteInfo(Student studentInput) {
	cout << endl << endl;
	cout << setw(30) << right << "[ Student ID: " << studentInput.getStudentID() << " ]" << endl;
	cout << setw(30) << right << "Name: " << studentInput.getName() << endl;
	cout << setw(30) << right << "Age: " << studentInput.getAge() << endl;
	cout << endl;

	// If it's empty, it will say it doesn't have any course information
	if (studentInput.studentListOfCourses.size() == 0) {
		cout << setfill('-') << setw(50) << "" << endl;

		cout << setw(23) << left <<
			"This student does not have any course information.\n";
		cout << setfill('-') << setw(50) << "" << endl;
		cout << endl;
	} else {
		// If the courses isn't empty, it will print it out
		cout << "Course Name\t\t" << "CRN\t\t" << "Teacher Name\t\t" << "Units\t\t" << "Class Grade\n\n";
		for (int ii = 0; ii < studentInput.studentListOfCourses.size(); ++ii) {
			cout << studentInput.studentListOfCourses.at(ii).GetCourseName() << "\t\t";
			cout << studentInput.studentListOfCourses.at(ii).GetCRN() << "\t\t";
			cout << studentInput.studentListOfCourses.at(ii).GetTeacher() << "\t\t\t";
			cout << studentInput.studentListOfCourses.at(ii).GetUnits() << "\t\t\t";
			cout << studentInput.studentListOfCourses.at(ii).GetLetterGrade() << "\t\t\t";
			cout << endl;
		}
	}
	cout << endl << endl;
	// Calculates the GPA
	cout << setw(30) << right <<
		"Student GPA is: " << studentInput.GetOverallGPA() << endl;
}

// Prints a roster of all the students @vector student
void Student::PrintRoster(vector<Student> student) {
	cout << "Complete roster:\n";

	for (int i = 0; i < student.size(); i++) {
		cout << "[ Student ID: " << student.at(i).getStudentID() << " ]" << endl;
		cout << "Name: " << student.at(i).getName() << endl;
		cout << "Age: " << student.at(i).getAge() << endl;
		cout << endl;
	}
}

// Calculates student's gpa @Parameter Student object pointer
void Student::CalculateGPA(Student& studentInput) {
	studentInput.setGPA(50.5);
	// Create a placeholder for the grade points
	double gradePoints = 0.0;
	// Number of total units
	double numOfTotalUnits = 0.0;
	// Letter grade placeholder; used for switch case later
	char letterHolder;
	double currentUnits;

	if (studentInput.studentListOfCourses.empty()) {
		studentInput.setGPA(0.0);
	}
	else {
		// Now go grade by grade 
		for (int ii = 0; ii < studentInput.studentListOfCourses.size(); ii++) {
			currentUnits = studentInput.studentListOfCourses.at(ii).GetUnits();
			numOfTotalUnits += currentUnits;

			switch (studentInput.studentListOfCourses.at(ii).GetLetterGrade()) {
			case 'A':
				gradePoints = gradePoints + 4.0 * currentUnits;
				break;
			case 'B':
				gradePoints = gradePoints + 3.0 * currentUnits;
				break;
			case 'C':
				gradePoints = gradePoints + 2.0 * currentUnits;
				break;
			case 'D':
				gradePoints = gradePoints + 1.0 * currentUnits;
				break;
			case 'F':
				gradePoints = gradePoints + 0.0;
				break;
			}
		}
		studentInput.setGPA(gradePoints / numOfTotalUnits);
	}
}

// Removes a student from the roster
void Student::RemoveStudent(vector<Student>& students) {
	int key;

	cout << "-- Remove student --" << endl;
	cout << endl;

	cout << "Enter student's ID to remove: " << endl;
	cin >> key;
	cout << endl;

	for (int i = 0; i < students.size(); i++) {
		if (students.at(i).getStudentID() == key) {
			students.erase(students.begin() + i);
		}
	}

	cout << "SUCCESS! Student has been removed.\n";
	cout << "Returning to main menu\n";
}

// Modifies a student's name and age
void Student::Modify(int key, vector<Student>& rosterInput) {
	// Linear search algorithm 
	cin.ignore();
	for (int i = 0; i < rosterInput.size(); i++) {
		if (rosterInput.at(i).getStudentID() == key) {
			string newName;
			int newAge;

			cout << "Edit name:" << endl;
			getline(cin, newName);
			rosterInput.at(i).setName(newName);

			cout << "Edit age:" << endl;
			cin >> newAge;
			rosterInput.at(i).setAge(newAge);
		}
	}
	cout << "SUCCESS! Student's vital info has been updated!\n";
}



// Prints out what awards a student has based on their overall gpa
void Student::PrintHonors(Student& studentInput) {

	cout << "\nHonors:" << endl;

	if (studentInput.GetOverallGPA() == 4.0) {		//if student has a 4.0 gpa
		cout << "Valedictorian, Presidential List, Summa Cum Laude" << endl;
	}
	else if (studentInput.GetOverallGPA() >= 3.8) {	//if student has a 3.8 and above gpa
		cout << "Presidential List, Summa Cum Laude" << endl;
	}
	else if (studentInput.GetOverallGPA() >= 3.6) {	//if student has a 3.6 and above gpa
		cout << "Presidential List, Magna Cum Laude" << endl;
	}
	else if (studentInput.GetOverallGPA() >= 3.4) { //if student has a 3.4 and above gpa
		cout << "Dean's List, Cum Laude" << endl;
	}
	else {
		cout << "No academic honors" << endl;
	}

	cout << endl;
}
