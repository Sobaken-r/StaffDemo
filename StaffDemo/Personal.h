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

    Personal(int id, string name,float worktime, int salary, string position) : salary{ salary }, Employee{ id, name,worktime, position } {};

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
    Cleaner(int id, string name,float worktime, int salary, string position);

    void calc() override;

    void PrintInfo() const;//поменять

};

class Driver : public Personal
{
public:
    Driver() : Personal() {};
    Driver(int id, string name, float worktime, int salary, string position);

    int calcBonus() override;

    void PrintInfo() const;//поменять
};

