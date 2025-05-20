#include "Employee.h"

void Employee::setID(int id)
{
    this->id = id;
}

void Employee::setName(string name)
{
    this->name = name;
}

void Employee::setWorktime(float worktime)
{
    this->worktime = worktime;
}

void Employee::setPayment(int payment)
{
    this->payment = payment;
}

const int Employee::getID()
{
    return id;
}

const string Employee::getName()
{
    return name;
}

const float Employee::getWorktime()
{
    return worktime;
}

const int Employee::getPayment()
{
    return payment;
}

void Employee::setWorkTime(float worktime)
{
    this->worktime = worktime;
}

const float Employee::getWorkTime()
{
    return worktime;
}