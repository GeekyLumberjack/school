#pragma once
#include "student.h"
#include "degree.h"
class SoftwareStudent : public Student {
	Degree Degreetype = SOFTWARE;
public:
	virtual Degree getDegreetype();
	//using Student::Student;
};