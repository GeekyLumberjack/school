#include <string>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster {
public:
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysIncourse1, int daysIncourse2, int daysIncourse3, Degree degreeProgram);
	void printAll();
	void printByDegreeProgram(int degreeProgram);
	void printdaysInCourse(string studentID);
	void printInvalidEmails();
	void remove(string studentID);
	~Roster();
	Student *classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

};
