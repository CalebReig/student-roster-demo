#pragma once
#define ROSTER_H
#include "student.h"
#include "degree.h"


class Roster {
public:
	~Roster();
	Student* classRosterArray[5];
	void add(std::string studentID, std::string firstName, std::string lastName,
		std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

