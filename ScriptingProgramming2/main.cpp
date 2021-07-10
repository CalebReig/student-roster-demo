#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

Student* parseData(string data);

/*
* This program will parse a comma seperated value list of students and save the information
* in an array. This information will be displayed and manipulated with the oputput shown in the command prompt.
*/
int main() {

	cout << "C867-Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001165112" << endl;
	cout << "Name: Caleb Reigada" << endl;
	cout << endl;


	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Caleb,Reigada,creigad@wgu.edu,24,30,49,44,COMPSCI" };

	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

	Roster* classRoster = new Roster();
	for (int i = 0; i < 5; i++) {
		Student student = *parseData(studentData[i]);
		string id = student.getId();
		string firstName = student.getFirstName();
		string lastName = student.getLastName();
		string email = student.getEmail();
		int age = student.getAge();
		int* daysInCourse = { student.getDaysInCourse() };
		DegreeProgram degreeProgram = student.getDegreeProgram();

		classRoster->add(id, firstName, lastName, email, age, daysInCourse[0], daysInCourse[1], daysInCourse[2], degreeProgram);
	}

	classRoster->printAll();
	classRoster->printInvalidEmails();

	for (Student* student : classRoster->classRosterArray) {
		classRoster->printAverageDaysInCourse(student->getId());
	}

	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");

	return 0;
}

/*
* Parses the student information and transforms it into a Student object.
*/
Student* parseData(string data) {

	int rhs = data.find(',');
	string id = data.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = data.find(',', lhs);
	string firstName = data.substr(lhs, rhs-lhs);

	lhs = rhs + 1;
	rhs = data.find(',', lhs);
	string lastName = data.substr(lhs, rhs-lhs);

	lhs = rhs + 1;
	rhs = data.find(',', lhs);
	string email = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(',', lhs);
	int age = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(',', lhs);
	int timeInCourse1 = stoi(data.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = data.find(',', lhs);
	int timeInCourse2 = stoi(data.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = data.find(',', lhs);
	int timeInCourse3 = stoi(data.substr(lhs, rhs - lhs));

	int daysInCourse[] = { timeInCourse1, timeInCourse2, timeInCourse3 };

	lhs = rhs + 1;
	rhs = data.find(',', lhs);
	string program = data.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::SECURITY;
	if (program == "NETWORK") { degreeProgram = DegreeProgram::NETWORK; }
	if (program == "SOFTWARE") { degreeProgram = DegreeProgram::SOFTWARE; }

	return new Student(id, firstName, lastName, email, degreeProgram, age, daysInCourse);
}