#pragma once
#include <iostream>
using namespace std;

class Employee
{
protected:
	int id;
	string name;
	float worktime;
	int payment;
public:
	Employee() : id{ 0 }, name{ "Not found" }, worktime{ 0 }, payment{ 0 } {};
	Employee(int id, const string name) : id{ id }, name{ name }, worktime{ 0 }, payment{ 0 } {};

	void setWorkTime(float worktime) { this->worktime = worktime; }
	const float getWorkTime() { return  worktime; }

	virtual void calc() = 0;
	virtual void PrintInfo() = 0;

	virtual ~Employee() {}
};

