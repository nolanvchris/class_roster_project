#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "student.h"

class Roster {

public:
	Student* classRosterArray[5];

	//Constructors
	Roster();

	//Destructor
	~Roster();

	std::string parse(std::string csvStudent);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void printInvalidEmails();
	void remove(std::string studentID);
	void printAverageDaysInCourse(std::string studentID);
	void printByDegreeProgram(DegreeProgram degreeprogram);

private:

	int studentCount;
	int rosterArraySize;
};

#endif