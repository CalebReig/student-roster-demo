#pragma once
#define STUDENT_H
#include <string>
#include "degree.h"

class Student {
private:
	std::string Id;
	std::string FirstName;
	std::string LastName;
	std::string Email;
	DegreeProgram degreeProgram;
	int Age;
	int DaysInCourse[3];

public:
	Student(std::string id, std::string firstName, std::string lastName,
		std::string email, DegreeProgram degProgram, int age, int daysInCourse[3]);

	void setId(std::string id);
	std::string getId();

	void setFirstName(std::string firstName);
	std::string getFirstName();

	void setLastName(std::string lastName);
	std::string getLastName();

	void setEmail(std::string email);
	std::string getEmail();

	void setDegreeProgram(DegreeProgram degProgram);
	DegreeProgram getDegreeProgram();

	void setAge(int age);
	int getAge();

	void setDaysInCourse(int daysInCourse[3]);
	int* getDaysInCourse();

	void print();
};

