
#include <iostream>
#include "roster.h"
#include <string>

//Constructor
Roster::Roster()
{
	studentCount = 0;
	rosterArraySize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
}

Roster::~Roster() {}

std::string Roster::parse(std::string csvStudent)
{
	std::string result[9] = {};
	DegreeProgram degreeProgramChoice = DegreeProgram::SECURITY;

	std::string sentence = csvStudent;
	int letterCount = 0;
	int	wordCount = 0;

	while (sentence[letterCount] != '\0')
	{
		if (sentence[letterCount] != ',')
		{
			result[wordCount] += sentence[letterCount];
			letterCount++;
		}
		else if (sentence[letterCount] == ',')
		{
			letterCount++;
			wordCount++;
		}

	}
	//change degreeprogram string into a enum of datatype "DegreeProgram"
	if (result[8] == "SECURITY")
	{
		//this->dp = static_cast<DegreeProgram>(0); //another way to do it
		degreeProgramChoice = DegreeProgram::SECURITY;
	}
	else if (result[8] == "NETWORK")
	{
		degreeProgramChoice = DegreeProgram::NETWORK;
	}
	else if (result[8] == "SOFTWARE")
	{
		degreeProgramChoice = DegreeProgram::SOFTWARE;
	}
	add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stoi(result[6]), stoi(result[7]), degreeProgramChoice);
	return result[0];
}

//contruct new student objects using parsed information 
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	this->classRosterArray[this->studentCount] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	this->studentCount++;
}


void Roster::printAll()
{
	for (int i = 0; i < rosterArraySize; i++)
	{
		classRosterArray[i]->print();
	}
	std::cout << std::endl;
}

void Roster::printInvalidEmails()
{
	int studentCount = 0;
	std::cout << "Displaying invalid emails:" << std::endl << std::endl;

	for (studentCount; studentCount < 5; studentCount++) //Loop through each student email
	{
		std::string studentEmail = classRosterArray[studentCount]->returnEmail();
		int letterCount = 0;
		bool isSpace = false, isPeriod = false, isAtSign = false;
		while (studentEmail[letterCount] != '\0') //Loop through each letter
		{
			if (studentEmail[letterCount] == ' ')
			{
				isSpace = true;
			}
			if (studentEmail[letterCount] == '.')
			{
				isPeriod = true;
			}
			if (studentEmail[letterCount] == '@')
			{
				isAtSign = true;
			}
			letterCount++;
		}
		//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
		if (!isSpace && isPeriod && isAtSign)
		{
			//Email is valid, do not print
		}
		else
		{
			std::cout << studentEmail << " - is invalid" << std::endl; //Email is invalid print
		}

	}
	std::cout << std::endl;
}

void Roster::remove(std::string studentIdRemoval)
{
	//Search the array for a matching studentID. If not found, return the message 'not found'
	bool idIsFound = false;
	for (int i = 0; i < rosterArraySize; i++)
	{
		std::string studentID = classRosterArray[i]->returnStudentID();
		if (studentID == studentIdRemoval)
		{
			idIsFound = true;
		}
	}

	if (!idIsFound)
	{
		std::cout << "The student with the ID: " << studentIdRemoval << " was not found." << std::endl;
	}
	else
	{
		//Overwrite the current array[index] with the array[index] ahead of it. Then show one less index in the print function.
		std::cout << "Removing " << studentIdRemoval << ":" << std::endl << std::endl;
		int shiftLeft = 0;
		for (int j = 0; j < rosterArraySize; j++)
		{

			std::string studentID = classRosterArray[j]->returnStudentID();
			if (studentID == studentIdRemoval)
			{

				this->rosterArraySize = sizeof(classRosterArray) / sizeof(classRosterArray[0]) - 1;
				shiftLeft++;
			}
			classRosterArray[j] = classRosterArray[shiftLeft];
			shiftLeft++;
		}
	}
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
	for (int i = 0; i < rosterArraySize; i++)
	{
		if (studentID == classRosterArray[i]->returnStudentID())
		{
			int avg = classRosterArray[i]->returnAvgDays();
			std::cout << "Student ID: " << studentID << ", average days in course is: " << avg << std::endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	std::string degreeProgramString = "";
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

	std::cout << "Showing Students in degree program: " << degreeProgramString << std::endl << std::endl;
	for (int i = 0; i < rosterArraySize; i++)
	{
		DegreeProgram compareDegreeProgram = classRosterArray[i]->returnDegreeProgram();

		if (degreeprogram == compareDegreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
	std::cout << std::endl;
}