#pragma once
#include "student.h"
#include <iostream>
#include <string>
class SecurityStudent { 
	Degree Degreetype;
public:
	Degree getDegreetype();
	void setDegreetype(Degree);
	virtual Degree getDegreetype();
	//using Student::Student;
};