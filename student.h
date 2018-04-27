#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;
class Student
{
	int age, daysInCourse1, daysInCourse2, daysInCourse3;
	string emailAddress, firstName, lastName, studentID;
	Degree Degreetype;
public:
	// Get student information
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int getdaysInCourse1();
	int getdaysInCourse2();
	int getdaysInCourse3();
	Degree getDegreetype();
	// Set student information
	void setstudentID(string);
	void setfirstName(string);
	void setlastName(string);
	void setemailAddress(string);
	void setage(int);
	void setdaysInCourse1(int);
	void setdaysInCourse2(int);
	void setdaysInCourse3(int);
	void setDegreetype(Degree);
	//constructor
	Student(int, int, int, int, string, string, string, string, Degree);
	//destructor
	~Student();
	// extra requirements
	virtual void print();
	virtual Degree getDegreetype();
};
