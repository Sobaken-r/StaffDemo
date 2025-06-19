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

void Employee::setPosition(string position)
{
    this->position = position;
}

int Employee::getID() const
{
    return id;
}

string Employee::getName() const
{
    return name;
}

float Employee::getWorktime() const
{
    return worktime;
}

int Employee::getPayment() const
{
    return payment;
}

string Employee::getPosition()
{
    return position;
}