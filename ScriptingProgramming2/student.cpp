#include "student.h"
#include "degree.h"
#include <iostream>

using namespace std;

/*
* Constructor for the Student class.
*/
Student::Student(string id, string firstName, string lastName, string email, 
				DegreeProgram degProgram, int age, int daysInCourse[3]) {
	Id = id;
	FirstName = firstName;
	LastName = lastName;
	Email = email;
	degreeProgram = degProgram;
	Age = age;  
	for (int i = 0; i < 3; i++) {
		DaysInCourse[i] = daysInCourse[i];
	}
};

/*
* Sets the Id variable
*/
void Student::setId(string id) { Id = id; }

/*
* Returns the Id variable
*/
string Student::getId() { return Id; }

/*
* Sets the firstName variable
*/
void Student::setFirstName(string firstName) { FirstName = firstName; }

/*
* Returns the firstName variable
*/
string Student::getFirstName() { return FirstName; }

/*
* Sets the lastName variable
*/
void Student::setLastName(string lastName) { LastName = lastName; }

/*
* Returns the lastName variable
*/
string Student::getLastName() { return LastName; }

/*
* Sets the email variable
*/
void Student::setEmail(string email) { Email = email; }

/*
* Returns the email variable
*/
string Student::getEmail() { return Email; }

/*
* Sets the degreeProgram variable
*/
void Student::setDegreeProgram(DegreeProgram degProgram) { degreeProgram = degProgram; }

/*
* returns the degreeProgram variable
*/
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

/*
* Sets the age variable
*/
void Student::setAge(int age) { Age = age; }

/*
* Sets the age variable
*/
int Student::getAge() { return Age; }

/*
* Sets the daysInCourse variable
*/
void Student::setDaysInCourse(int daysInCourse[3]) {
	for (int i = 0; i < 3; i++) {
		DaysInCourse[i] = daysInCourse[i];
	}
}

/*
* Returns the daysInCourse variable
*/
int* Student::getDaysInCourse() { 
	return  DaysInCourse;
}

/*
* Prints the student's information
*/
void Student::print() {
	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << "ID: " <<  (string)Id << "\t";
	cout << "First Name: " << (string)FirstName << "\t";
	cout << "Last Name: " << (string)LastName << "\t";
	cout << "Email: " << (string)Email << "\t";
	cout << "Age: " << (int)Age << "\t";
	cout << "Days in Course: {";
	for (int i = 0; i < 3; i++) {
		cout << (int)DaysInCourse[i];
		if (i < 2) { cout << ", "; }
	}
	cout << "}\t";
	cout << "Degree Program: " << degreeProgramStrings[(int)degreeProgram] << endl;
}
