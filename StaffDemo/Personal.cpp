#include "Personal.h"
using namespace std;

int Personal::calcBace(int salary, int wtime)
{
    return salary * wtime;
}

int Personal::calcBonus()
{
    return 50;
}

void Personal::setSalary(int salary)
{
    this->salary = salary;
}

int Personal::getSalary() const
{
    return salary;
}

void Personal::calc()
{
    payment = calcBace(salary, worktime);
}

void Personal::PrintInfo(){}

Cleaner::Cleaner(int id, string name, float worktime, int salary, string position) : Personal{ id, name, worktime, salary, "Cleaner" }
{
    calc();
};

void Cleaner::calc()
{
	payment = calcBace(salary, static_cast<int>(worktime)) + calcBonus();
}

void Cleaner::PrintInfo() const
{
    cout << "\t\t\t\t\t\tID: " << id
        << "\n\t\t\t\t\t\tName: " << name
        << "\n\t\t\t\t\t\tWork time: " << worktime
        << "\n\t\t\t\t\t\tPayout: " << salary
        << "hour\n\t\t\t\t\t\tPayment: " << payment
        << "\n\t\t\t\t\t\tPosition: " << position
        << endl;
}

Driver::Driver(int id, string name, float worktime, int salary, string position) : Personal(id, name, worktime, salary, "Driver")
{
    calc();
}

int Driver::calcBonus()
{
    if (worktime > 40)
        return 100;
    return 0;
}

void Driver::PrintInfo() const
{

    cout << "\t\t\t\t\t\tID: " << id
        << "\n\t\t\t\t\t\tName: " << name
        << "\n\t\t\t\t\t\tWork time: " << worktime
        << "\n\t\t\t\t\t\tPayout: " << salary
        << "hour\n\t\t\t\t\t\tPayment: " << payment
        << "\n\t\t\t\t\t\tPosition: " << position
        << endl;
}
