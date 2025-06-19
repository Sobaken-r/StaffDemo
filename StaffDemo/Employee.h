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
	string position;
public:
	Employee() : id{ 0 }, name{ "Not found" }, worktime{ 0 }, payment{ 0 }, position{ "Not found" } {};
	Employee(int id, string name, float worktime, string position) : id{ id }, name{ name }, worktime{ worktime }, payment{ 0 }, position { position } {};

	void setID(int id);
	void setName(string name);
	void setWorktime(float worktime);
	void setPayment(int payment);
	void setPosition(string position);

	int getID() const;
	string getName() const;
	float getWorktime() const;
	int getPayment() const;
	string getPosition();

	virtual void calc() = 0;
	virtual void PrintInfo() = 0;

};

