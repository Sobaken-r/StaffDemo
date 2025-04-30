#include <iostream>
#include <Windows.h>
#include "Employee.h"
#include "Personal.h"
using namespace std;

int main()
{
    setlocale(0, "");
    Cleaner* cleaner = new Cleaner(1, "Иван Иванов", 15);
    cleaner->setWorkTime(45);
    cleaner->calc();
    cleaner->PrintInfo();


    Driver* driver = new Driver();
    driver->PrintInfo();
}
