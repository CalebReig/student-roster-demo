#include "roster.h"
#include <iostream>

using namespace std;

/*
* Destuctor which will delete the classRosterArray variable.
*/
Roster::~Roster() { 
	delete[] classRosterArray; 
}

/*
* Adds a new Student object pointer to the classRosterArray variable.
*/
void Roster::add(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeprogram) {
	
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = new Student(studentID, firstName, lastName, emailAddress,
		degreeprogram, age, daysInCourse);

	for (int i=0; i < 5; i++) {
		if (classRosterArray[i] == NULL) {
			classRosterArray[i] = student;
			return;
		}
	}
}

/*
* Removes a Student pointer from the classRosterArray variable if the 
* student ID matches.
*/
void Roster::remove(string studentID) {
	cout << "Removing student ID " << studentID << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			string id = classRosterArray[i]->getId();
			if (studentID == id) {
				classRosterArray[i] = NULL;
				cout << endl;
				return;
			}
		}
	}
	cout << "The student with ID " << studentID << " was not found." << endl;
	cout << endl;
}

/*
* Prints all students information contained within the classRosterArray variable.
*/
void Roster::printAll() {
	cout << "Displaying all students:" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

/*
* Prints the average days to finish a course for a student.
*/
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			string id = classRosterArray[i]->getId();
			if (studentID == id) {
				int* daysInCourse = { classRosterArray[i]->getDaysInCourse() };
				int avg = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3;
				cout << "Student ID: " << studentID << ", averages " << avg  << " days in a course." << endl;
				cout << endl;
				return;
			}
		}
	}

}

/*
* Prints emails that meet one of the following criteria:
* 1. Contains a space
* 2. Does not contain a '.'
* 3. Does not contain a '@'
*/
void Roster::printInvalidEmails() {
	cout << "Displaying Invalid Emails: " << endl;
	bool containsAt, containsPt, containsSp;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			containsAt = false;
			containsPt = false;
			containsSp = false;
			string email = classRosterArray[i]->getEmail();
			for (int i = 0; i < email.length(); i++) {
				if (email[i] == '@') { containsAt = true; }
				else if (email[i] == '.') { containsPt = true; }
				else if (email[i] == ' ') { containsSp = true; }
			}
			if (!containsAt | !containsPt | containsSp) {
				cout << classRosterArray[i]->getEmail();
				string reason = "  -  no spaces allowed.";
				if (!containsAt) { reason = "  -  missing an @ symbol."; }
				if (!containsPt) { reason = "  -  missing a period."; }
				cout << reason << endl;
			}
		}
	}
	cout << endl;
}

/*
* Prints students information if the are associated with the matching degree program.
*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << "Showing students in degree program: : " << degreeProgramStrings[(int)degreeProgram] << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}