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

    int calcBace(int salary, int wtime) override
    {
        return salary * wtime;
    }
    virtual int calcBonus() override
    {
        return 0;
    }
    void setSalary(int salary)
    {
        this->salary = salary;
    }

    int getSalary() const
    {
        return salary;
    }

    void calc() override
    {
        payment = calcBace(salary, static_cast<int>(worktime));
    }

    void PrintInfo() override
    {
        cout << "ID: " << id << "\nName: " << name << "\nWork time: " << worktime << "\nPayment: " << payment << endl;
    }
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