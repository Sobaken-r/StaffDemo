#pragma once
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"
using namespace std;

class Personal : public Employee, public WorkBaceTime
{
protected:
    int salary;
public:
    Personal() : Employee(), salary(0) {}

    Personal(int id, string name, int salary) : salary{ salary }, Employee{ id, name } {};

    int calcBace(int salary, int wtime);
    int calcBonus();

    void setSalary(int salary);

    int getSalary() const;

    void calc();

    void PrintInfo();
};

class Cleaner : public Personal
{
public:
    Cleaner() : Personal() {};
    Cleaner(int id, string name, int salary) : Personal{ id, name, salary } {};

    void calc() override;

    void PrintInfo() override;

};

class Driver : public Personal
{
public:
    Driver() : Personal() {};
    Driver(int id, string name, int salary) : Personal(id, name, salary) {}

    int calcBonus() override;

    void PrintInfo() override;
};