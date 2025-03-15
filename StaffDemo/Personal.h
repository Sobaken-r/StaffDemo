#pragma once
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"
using namespace std;
class Personal : public Employee, public WorkBaceTime
{
	int salary;
public:
	Personal(int id, string name, int salary) : salary{ salary }, Employee{ id, name } {};

	void setSalary(int salary)
	{
		this->salary = salary;
	}

	int getSalary() const
	{
		return salary;
	}
};

class Cleaner
{
	void calc();
};

class Driver
{
public:

	void calcBonus();
	void calc();
};