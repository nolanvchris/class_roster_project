#include "student.h"

//Constructor
Student::Student()
{
	studentID = "-1";
	firstName = "NULL";
	lastName = "NULL";
	emailAddress = "NULL";
	age = -1;
	degreeprogram = DegreeProgram::SOFTWARE;
}

//Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->numDaysComplete[0] = { daysInCourse1 };
	this->numDaysComplete[1] = { daysInCourse2 };
	this->numDaysComplete[2] = { daysInCourse3 };
	this->degreeprogram = degreeprogram;
	setDegreeProgramString(this->degreeprogram);
}

//Getters
void Student::getStudentID() { std::cout << this->studentID; }
void Student::getFirstName() { std::cout << this->firstName; }
void Student::getLastName() { std::cout << this->lastName; }
void Student::getEmailAddress() { std::cout << this->emailAddress; }
void Student::getAge() { std::cout << this->age; }
void Student::getNumDaysComplete() { std::cout << "{" << this->numDaysComplete[0] << ", " << this->numDaysComplete[1] << ", " << this->numDaysComplete[2] << "}"; }
void Student::getDegreeProgram() { std::cout << this->degreeProgramString; }

//Return Values
std::string Student::returnEmail() { return this->emailAddress; }
std::string Student::returnStudentID() { return this->studentID; }
DegreeProgram Student::returnDegreeProgram() { return this->degreeprogram; }
std::string Student::returnDegreeProgramString(DegreeProgram degreeprogram)
{
	if (degreeprogram == DegreeProgram::SECURITY)
	{
		degreeProgramString = "SECURITY";
	}
	else if (degreeprogram == DegreeProgram::NETWORK)
	{
		degreeProgramString = "NETWORK";
	}
	else if (degreeprogram == DegreeProgram::SOFTWARE)
	{
		degreeProgramString = "SOFTWARE";
	}
	return degreeProgramString;
}

//Setters
void Student::setStudentID(std::string studentID) { this->studentID = studentID; }
void Student::setFirstName(std::string firstName) { this->firstName = firstName; }
void Student::setLastName(std::string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setNumDaysComplete(int numDaysComplete[3])
{
	this->numDaysComplete[0] = numDaysComplete[0];
	this->numDaysComplete[1] = numDaysComplete[1];
	this->numDaysComplete[2] = numDaysComplete[2];
}

void Student::setDegreeProgram(DegreeProgram degreeprogram)
{
	this->degreeprogram = degreeprogram;
	setDegreeProgramString(this->degreeprogram);
}

void Student::setDegreeProgramString(DegreeProgram degreeprogram)
{
	if (this->degreeprogram == DegreeProgram::SECURITY)
	{
		this->degreeProgramString = "SECURITY";
	}
	else if (this->degreeprogram == DegreeProgram::NETWORK)
	{
		this->degreeProgramString = "NETWORK";
	}
	else if (this->degreeprogram == DegreeProgram::SOFTWARE)
	{
		this->degreeProgramString = "SOFTWARE";
	}
}

void Student::print()
{
	//Print one student at a time
	std::cout << this->studentID << "\t First Name: " << this->firstName << "\t Last Name: " << this->lastName << "\t Age: " << this->age << "\t daysInCourse: ";
	getNumDaysComplete();
	std::cout << "\t Degree Program: " << this->degreeProgramString << std::endl;
}

float Student::returnAvgDays()
{
	float avg = 0, sum = 0, denom = 0;

	for (int i = 0; i < 3; i++)
	{
		sum += this->numDaysComplete[i];
		denom++;
	}
	avg = sum / denom;

	return round(avg);
}