#include "Personal.h"
using namespace std;

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
