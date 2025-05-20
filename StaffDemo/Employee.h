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
	Employee(int id, string name) : id{ id }, name{ name }, worktime{ 0 }, payment{ 0 } {};

	void setID(int id);
	void setName(string name);
	void setWorktime(float worktime);
	void setPayment(int payment);

	const int getID();
	const string getName();
	const float getWorktime();
	const int getPayment();

	void setWorkTime(float worktime);
	const float getWorkTime();

	virtual void calc() = 0;
	virtual void PrintInfo() = 0;

	virtual ~Employee() {}
};

