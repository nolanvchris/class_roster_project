
#include <iostream>
#include <string>

#include "roster.h"
//#include "student.h"

int main()
{
    const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                         "A5,Nolan,Christensen,nolankhris@gmail.com,29,31,42,34,SOFTWARE" };

    Roster classRoster;

    //create a copy of studentData string and parse the data
    std::string sd;
    std::string studentID[(end(studentData) - begin(studentData))];
    for (int i = 0; i < (end(studentData) - begin(studentData)); i++)
    {
        sd = studentData[i];
        studentID[i] = classRoster.parse(sd);
    }

    //Print out of application the course title, the programming language used, your WGU student ID, and your name.
    std::cout << "C867-Scripting & Programming: Applications" << std::endl;
    std::cout << "Language: C++" << std::endl;
    std::cout << "Student ID: 010524411" << std::endl;
    std::cout << "Name: Nolan Christensen" << std::endl << std::endl;

    //Pseudo code requirements completed
    std::cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for (int i = 0; i < (end(studentData) - begin(studentData)); i++)
    {
        classRoster.printAverageDaysInCourse(studentID[i]);
    }
    std::cout << std::endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}