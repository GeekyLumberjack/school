#include "student.h"

int Student::getage()
{
	return age;
}

int Student::getdaysInCourse1()
{
	return daysInCourse1;
}

int Student::getdaysInCourse2()
{
	return daysInCourse2;
}

int Student::getdaysInCourse3()
{
	return daysInCourse3;
}

string Student::getemailAddress()
{
	return emailAddress;
}

string Student::getfirstName()
{
	return firstName;
}

string Student::getlastName()
{
	return lastName;
}

string Student::getstudentID()
{
	return studentID;
}

Degree Student::getDegreetype()
{
	return Degree();
}

void Student::setage(int age)
{
	int Age = age;
}

void Student::setdaysInCourse1(int daysInCourse1)
{
	daysInCourse1 = daysInCourse1;
}

void Student::setdaysInCourse2(int daysInCourse2)
{
	daysInCourse2 = daysInCourse2;
}

void Student::setdaysInCourse3(int daysInCourse3)
{
	daysInCourse3 = daysInCourse3;
}

void Student::setemailAddress(string emailAddress)
{
	emailAddress = emailAddress;
}

void Student::setfirstName(string firstName)
{
	firstName = firstName;
}

void Student::setlastName(string lastName)
{
	lastName = lastName;
}

void Student::setstudentID(string studentID)
{
	studentID = studentID;
}

void Student::setDegreetype(Degree Degreetype)
{
	Degreetype = Degreetype;
}

Student::Student(int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string studentID, string emailAddress, string firstName, string lastName, Degree Degreetype)
{
	setage(age);
	setstudentID(studentID);
	setemailAddress(emailAddress);
	setfirstName(firstName);
	setlastName(lastName);
	setDegreetype(Degreetype);
	setdaysInCourse1(daysInCourse1);
	setdaysInCourse2(daysInCourse2);
	setdaysInCourse3(daysInCourse3);
	setDegreetype(Degreetype);
}

void Student::print()
{
	daysInCourse1 = getdaysInCourse1();
	daysInCourse2 = getdaysInCourse2();
	daysInCourse3 = getdaysInCourse3();
	printf("%d",getstudentID());
	printf("First Name: %d ", getfirstName());
	printf("Last Name: %d ", getlastName());
	printf("Email: %d ", getemailAddress());
	printf("Age: %d ", getage());
	printf("daysInCourse: {%d, %d, %d}", daysInCourse1, daysInCourse2, daysInCourse3);

	printf("Degree Program: %d", getDegreetype());
	switch (getDegreetype()) {
	case 0: printf("Security");
		break;
	case 1: printf("Networking");
		break;
	case 2: printf("Software");
		break;
	case 4: printf("Other");
		break;
	}
}

Degree Student::getDegreetype()
{
	return OTHER;
}

Student::~Student()
{
}
