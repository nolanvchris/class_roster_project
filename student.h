
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
#include <iostream>

class Student {
public:
	//constructors
	Student();
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	//Getters
	void getStudentID();
	void getFirstName();
	void getLastName();
	void getEmailAddress();
	void getAge();
	void getNumDaysComplete();
	void getDegreeProgram();

	//Setters
	void setStudentID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setNumDaysComplete(int numDaysComplete[3]);
	void setDegreeProgram(DegreeProgram degreeprogram);
	void setDegreeProgramString(DegreeProgram degreeprogram); //for cout display on "get" functions

	//Return Values
	std::string returnEmail();
	std::string returnStudentID();
	float returnAvgDays();
	DegreeProgram returnDegreeProgram();
	std::string returnDegreeProgramString(DegreeProgram degreeprogram);

	void print();

private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int numDaysComplete[3] = {};
	DegreeProgram degreeprogram;
	std::string degreeProgramString; //String representation of enum type "DegreeProgram" to display "get" functions
};

#endif
