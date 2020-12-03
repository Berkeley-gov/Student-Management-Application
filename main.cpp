#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Courses.h"
#include "Student.h"
using namespace std;

int main() {
	vector <Student> Students;
	Student currentStudent;

	int idInput;
	bool studentFound = false;
	int foundIndex;
	char menuInput;

	std::cout << "DATABASE MENU\n";
	std::cout << "A - Add Student\n";
	std::cout << "C - Add Additional Course for Student\n";
	std::cout << "I - Print Student Info\n";
	std::cout << "M - Modify student's name and age\n";
	std::cout << "P - Print Student Roster\n";
	std::cout << "G - Print Student's GPA\n";
	std::cout << "R - Remove Student\n";
	std::cout << "H - Print student's honors\n";
	std::cout << "Q - Quit\n";
	cin >> menuInput;

	while (menuInput != 'Q') {
		if (menuInput == 'A' || menuInput == 'C' ||
			menuInput == 'I' || menuInput == 'M' ||
			menuInput == 'P' || menuInput == 'G' ||
			menuInput == 'R' || menuInput == 'H' ||
			menuInput == 'a' ||
			menuInput == 'c' || menuInput == 'i' ||
			menuInput == 'm' || menuInput == 'h' ||
			menuInput == 'p' || menuInput == 'g' ||
			menuInput == 'r') {

			std::cout << "You have entered a valid input\n";

			// now do a switch case to bring up the proper functionA
			switch (menuInput) {
        case 'A': // user has decided to add a user
        case 'a':
          currentStudent.AddStudent(Students);
          std::cout << "Student ID is: " << Students.back().getStudentID() << endl;
          break;
        case 'C':
        case 'c':
          std::cout << "Enter student ID: \n";
				while (!(cin >> idInput)) {
					cout << "A number was not entered. Please enter an id:" << endl;
					cin.clear();
					cin.ignore(123, '\n');
					cin >> idInput;
					break;
				}

				// now look for the name in the student roster
				for (int ii = 0; ii < Students.size(); ++ii) {
					if (Students.at(ii).getStudentID() == idInput) {
						studentFound = true;
						foundIndex = ii;
					}

				}

				if (studentFound == true) {
					std::cout << "Student was found.\n";
					currentStudent.AdditionalCourse(Students.at(foundIndex));
				}
				else {
					std::cout << "Student was not found\n";
				}

				break;

			case 'G':
			case 'g':
				cout << "Enter Student ID:\n";
				while (!(cin >> idInput))
				{
					cout << "A number was not entered. Please enter an id:" << endl;
					cin.clear();
					cin.ignore(123, '\n');
					cin >> idInput;
					break;
				}

				// now look for the name in the student roster
				for (int ii = 0; ii < Students.size(); ++ii)
				{
					if (Students.at(ii).getStudentID() == idInput)
					{
						studentFound = true;
						foundIndex = ii;
					}

				}

				if (studentFound == true)
				{
					std::cout << "Student was found.\n";
					currentStudent.CalculateGPA(Students.at(foundIndex));
					std::cout << "GPA is " <<
						Students.at(foundIndex).GetOverallGPA() << endl;
				}
				else
				{
					std::cout << "Student was not found\n";
				}

				break;

			case 'I':
			case 'i':
				std::cout << "Enter the student ID whose info you wish to see.\n";

				while (!(cin >> idInput))
				{
					cout << "A number was not entered. Please enter an id:" << endl;
					cin.clear();
					cin.ignore(123, '\n');
					cin >> idInput;
					break;
				}

				// now look for the name in the student roster
				for (int ii = 0; ii < Students.size(); ++ii)
				{
					if (Students.at(ii).getStudentID() == idInput)
					{
						studentFound = true;
						foundIndex = ii;
					}

				}

				if (studentFound == true) {
					std::cout << "Student was found.\n";
					// calculate GPA; to be used in the info page
					currentStudent.CalculateGPA(Students.at(foundIndex));
					currentStudent.PrintStudentCompleteInfo(Students.at(foundIndex));
				}
				else {
					std::cout << "Student was not found\n";
				}
				break;

			case 'M':
			case 'm':
				cin.ignore();
				std::cout << "Enter the id you wish to modify:\n";
				while (!(cin >> idInput)) {
					cout << "A number was not entered. Please enter an id:" << endl;
					cin.clear();
					cin.ignore(123, '\n');
					cin >> idInput;
					break;
				}

				currentStudent.Modify(idInput, Students);
				break;

			case 'P':
			case 'p':
				currentStudent.PrintRoster(Students);
				break;

			case 'R':
			case 'r':
				currentStudent.RemoveStudent(Students);
				break;

			case 'H':
			case 'h':
				cin.ignore();
				cout << "Enter the id you wish to view their honors:\n";

				while (!(cin >> idInput)) {
					cout << "A number was not entered. Please enter an id:" << endl;
					cin.clear();
					cin.ignore(123, '\n');
					cin >> idInput;
					break;
				}
				// now look for the name in the student roster
				for (int ii = 0; ii < Students.size(); ++ii) {
					if (Students.at(ii).getStudentID() == idInput) {
						studentFound = true;
						foundIndex = ii;
					}

				}

				if (studentFound == true)	{
					cout << "Student was found.\n";
					// calculate GPA; to be used in the info page
					currentStudent.CalculateGPA(Students.at(foundIndex));
					currentStudent.PrintHonors(Students.at(foundIndex));
				}
				else {
					cout << "Student was not found\n";
				}
				break;
			}

			cout << "DATABASE MENU\n";
			cout << "A - Add Student\n";
			cout << "C - Add Additional Course for Student\n";
			cout << "I - Print Student Info\n";
			cout << "M - Modify student's name and age\n";
			cout << "P - Print Student Roster\n";
			cout << "G - Print Student's GPA\n";
			cout << "R - Remove Student\n";
			cout << "H - Print student's honors\n";
			cout << "Q - Quit\n";
			cin >> menuInput;
		}
		else {
			cout << "Your input is not valid. Try again.\n";
			cout << "Enter another input: ";
			cin >> menuInput;
			continue;
		}
	}

	cout << "You have exited the database. Bye.\n";
}