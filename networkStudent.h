#pragma once
#include "student.h"
class NetworkStudent {
	Degree Degreetype = NETWORKING;
public:
	virtual Degree getDegreetype();
	//using Student::Student;
};
