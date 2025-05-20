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

void Personal::PrintInfo()
{
    cout << "ID: " << id << "\nName: " << name << "\nWork time: " << worktime << "\nPayment: " << payment << endl;
}

void Cleaner::calc()
{
	payment = calcBace(salary, static_cast<int>(worktime)) + calcBonus();
}

void Cleaner::PrintInfo()
{
    cout << "Cleaner info" << endl;
    Personal::PrintInfo();
}

int Driver::calcBonus()
{
    if (worktime > 40)
        return 100;
    return 0;
}

void Driver::PrintInfo()
{
    cout << "Driver info" << endl;
    Personal::PrintInfo();
}
