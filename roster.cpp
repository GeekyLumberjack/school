#include "roster.h"
#include <sstream>
#include <string>
#include <iostream>

int main() {

	Roster classRoster;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Marshall,Holmes,mholm53@wgu.edu,22,14,2,3,SOFTWARE"
	};
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
		string data = studentData[i];
		istringstream inSS(data);
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse1;
		int daysInCourse2;
		int daysInCourse3;
		string studentdegree;
		Degree	studentdegreeType;
		inSS >> studentID >> firstName >> lastName >> emailAddress >> age >> daysInCourse1 >> daysInCourse2 >> daysInCourse3 >> studentdegree;
		if (studentdegree == "NETWORK") {
			studentdegreeType = NETWORKING;
		}
		else if (studentdegree == "SECURITY") {
			studentdegreeType = SECURITY;
		}
		else if (studentdegree == "SOFTWARE") {
			studentdegreeType = SOFTWARE;
		}
		classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, studentdegreeType);

	}
	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
		classRoster.printdaysInCourse(classRoster.classRosterArray[i]->getstudentID());
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	return 0;
}




	void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree Degreetype)
	{
		int courseDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

		for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
			if (classRosterArray[i] == nullptr) {
				if (Degreetype == NETWORKING) {
					classRosterArray[i] = new NetworkStudent(age, daysInCourse1, daysInCourse2, daysInCourse3, studentID, emailAddress, firstName, lastName, Degreetype);
				}
				else if (Degreetype == SECURITY) {
					classRosterArray[i] = new SecurityStudent(age, daysInCourse1, daysInCourse2, daysInCourse3, studentID, emailAddress, firstName, lastName, Degreetype);
				}
				else if (Degreetype == SOFTWARE) {
					classRosterArray[i] = new SoftwareStudent(age, daysInCourse1, daysInCourse2, daysInCourse3, studentID, emailAddress, firstName, lastName, Degreetype);
				}
				else {
					classRosterArray[i] = new Student(age, daysInCourse1, daysInCourse2, daysInCourse3, studentID, emailAddress, firstName, lastName, Degreetype);
				}
				break;
			}
		}
	}

	void Roster::remove(string studentID)
	{
		bool studentRemoved = false;
		for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
			if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID) {
				classRosterArray[i] = nullptr;
				studentRemoved = true;
				break;
			}
		}
		if (studentRemoved == false){
			printf("Error studentID was not found");
		}
	}

	void Roster::printAll()
	{
		for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
			classRosterArray[i]->print();
		}
	}

	void Roster::printdaysInCourse(string studentID)
	{
		float avg = 0;
		int max = 3;
		for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
			if (classRosterArray[i] != nullptr && classRosterArray[i]->getstudentID() == studentID) {
				int daysInCourse1 = classRosterArray[i]->getdaysInCourse1();
				int daysInCourse2 = classRosterArray[i]->getdaysInCourse2();
				int daysInCourse3 = classRosterArray[i]->getdaysInCourse3();
				int avg = daysInCourse1 + daysInCourse2 + daysInCourse3;
					string stuid = classRosterArray[i]->getstudentID();
					int avgdays = (avg / max);
						printf("Student %d's average number of days in the three courses is %d \n", stuid, avgdays);
					break;
				}
			}
		}
	void Roster::printInvalidEmails()
	{
		for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
			string email = classRosterArray[i]->getemailAddress();
			bool goodemail = false;
			bool isValid;
			int found;
			 int found1 = email.find("@");
			 int found2 = email.find(".");
			if (found1 != string::npos && found2 != string::npos) {
					found = email.find(" ");
					if (found == string::npos) {
						isValid = true;
					}
			}
			if (!isValid) {
				printf("%d is not a valid email address \n", email);
			}
		}
	}

	void Roster::printByDegreeProgram(int degreeProgram)
	{
		for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
			if (classRosterArray[i]->getDegreetype() == degreeProgram) {
				classRosterArray[i]->print();
			}
		}
	}
	Roster::~Roster()
	{}
	/*void main() {
		// build class roster
		for (int i = 0; i < sizeof(studentData) / sizeof(studentData[i]); i++) {
			string data = studentData[i];
			istringstream inSS(data);
			int studentID;
			string firstName;
			string lastName;
			string emailAddress;
			int age;
			int daysInCourse1;
			int daysInCourse2;
			int daysInCourse3;
			Degree studentdegree;
			inSS >> studentID >> firstName >> lastName >> emailAddress >> age >> daysInCourse1 >> daysInCourse2 >> daysInCourse3 >> studentdegree;
			if (studentdegree == "NETWORK") {
				studentdegree = NETWORKING;
			}
			else if (studentdegree == "SECURITY") {
				studentdegree = SECURITY;
			}
			else if (studentdegree == "SOFTWARE") {
				studentdegree = SOFTWARE;
			}
			classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, studentdegree);

		}
		classRoster.printAll();
		printf("/n");
		classRoster.printInvalidEmails();
		printf("/n");
		for (int i = 0; i < sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[i]); i++) {
			classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
		}
		printf("\n");
		classRoster.printByDegreeProgram(SOFTWARE);
		printf("\n");
		classRoster.remove("A3");
		classRoster.remove("A3");
		return 0;
	}*/
