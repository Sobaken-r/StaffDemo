#pragma once
#include "Employee.h"
#include "Personal.h"

class Enginer : public Personal, public WorkBaceTime
{
public:
	Enginer() : Personal(){};
	Enginer(int id, string name, int salary) : Personal(id, name, salary) {};

	void calcBudgetPart();
	void calc();
};

class Programmer : public Personal, public WorkBaceTime
{
public:
	Programmer() : Personal() {};
	Programmer(int id, string name, int salary) : Personal(id, name, salary) {};

	void calcProAddition();
};

class Tester : public Personal, public WorkBaceTime
{
public:
	Tester() : Personal() {};
	Tester(int id, string name, int salary) : Personal(id, name, salary) {};

	void calcProAddition();
};

class TeamLeader
{
public:
	void cakcHeads();
	void calc();
};