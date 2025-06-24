#include <iostream>
#include <Windows.h>
#include <cstring>
#include <conio.h>
#include <vector>
#include "Personal.h";
#include "Engineer.h"
#include "Project.h"
#include "Manager.h"
#include "Factory.h"
using namespace std;

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    setlocale(0, "");
    //управление меню
    Factory company;
    char get_button;
    int index_button = 0;
    int professionOption;
    char pauseManu;

    //поиск по зп
    int SalarySearch;
    int MoreLess;

    //Перевод сотрудника на другой проект
    int IDTransferOfEmployees;
    int CurrentPosition;
    int IDProject;

    //поиск проекта
    int IDFound;
    string NameFound;

    //Создание нового проекта
    int IdCreate;
    string NameCreateProject;
    float BudgetCreate;

    //Создание персонала
    int IdCreatePerson;
    string NameCreatePerson;
    float WorkTimeCreatePerson;
    int PaymentCreatePerson;
    string PositionCreatePerson;

    //Файлы
    string nameFile;
    while (true) {
        while (true) {
            std::cout << "\x1B[2J\x1B[H";
            string main_menu[8] = {
                "Вывод всех сотрудников",
                "Вывод сотрудников задействованых на определенном проекте",
                "Поиск сотрудников",
                "Поиск сотрудников по зп (больше/меньше)",
                "Создание нового проекта",
                "Добавление сотрудника",
                "Перевод сотрудника",
                "Сохранить текущее состояние данных в файл"
            };
            int menu_size = sizeof(main_menu) / sizeof(main_menu[0]);
            for (int i = 0; i < menu_size; i++)
            {
                if (i == index_button)
                {
                    setColor(10);
                }
                else
                {
                    setColor(7);
                }
                std::cout << "\t\t\t" << main_menu[i] << endl;
            }

            get_button = _getch();
            if (get_button == 'w' || get_button == 'W')
            {
                index_button--;
                if (index_button < 0)
                {
                    index_button = menu_size - 1;
                }
            }
            else if (get_button == 's' || get_button == 'S')
            {
                index_button++;
                if (index_button >= menu_size)
                {
                    index_button = 0;
                }
            }
            else if (get_button == 'e' || get_button == 'E')
            {
                break;
            }
        }
        switch (index_button)
        {
        case 0:
            system("cls");
            std::cout << "\t\t\t\t\t\tВывод всех сотрудников" << endl;
            company.PrintAllEmployee();
            pauseManu = _getch();
            break;
        case 1:
            system("cls");
            company.PrintAllProject();
            std::cout << "\t\t\t\t\t\tВведите ID проекта: ";
            std::cin >> IDFound;
            company.PrintEmployeesByProject(IDFound);
            pauseManu = _getch();
            break;
        case 2:
            system("cls");
            std::cout << "\t\t\t\t\t\tВ какой должности: ";
            std::cin >> professionOption;
            std::cout << "\t\t\t\t\t\tПоиск сотрудников по имени: ";
            std::cin >> NameFound;
            company.SearchEmployeeByName(NameFound, professionOption);
            pauseManu = _getch();
            break;
        case 3:
            system("cls");
            std::cout << "\t\t\t\t\t\tПоиск сотрудников по зп (больше/меньше): ";
            std::cout << "\t\t\t\t\t\tВведите зп/ч: ";
            std::cin >> SalarySearch;
            std::cout << "\t\t\t\t\t\tБольше/меньше(1/2): ";
            std::cin >> MoreLess;
            company.FindBySalarySimple(SalarySearch, MoreLess == 1);
            pauseManu = _getch();
            break;
        case 4:
            system("cls");
            std::cout << "\t\t\t\t\t\tСоздание нового проекта" << endl;
            std::cout << "\t\t\t\t\t\tВведите Id: ";
            std::cin >> IdCreate;
            std::cout << "\t\t\t\t\t\tВведите имя проекта: ";
            std::cin >> NameCreateProject;
            std::cout << "\t\t\t\t\t\tВведите стоимость проекта: ";
            std::cin >> BudgetCreate;
            company.СreateProject(IdCreate, NameCreateProject, BudgetCreate);
            company.PrintAllProjects();
            pauseManu = _getch();
            break;
        case 5:
            system("cls");
            std::cout << "\t\t\t\t\t\tСоздание персонала" << endl;
            std::cout << "\t\t\t\t\t\tВведите Id сотрудника: ";
            std::cin >> IdCreatePerson;
            std::cout << "\t\t\t\t\t\tВведите имя сотрудника: ";
            std::cin >> NameCreatePerson;
            std::cout << "\t\t\t\t\t\tВведите отработаные часы: ";
            std::cin >> WorkTimeCreatePerson;
            std::cout << "\t\t\t\t\t\tВведите ставку в час: ";
            std::cin >> PaymentCreatePerson;
            std::cout << "\t\t\t\t\t\tВведите занимаемую должность: ";
            std::cin >> PositionCreatePerson;
            company.CreateEngineer(IdCreatePerson, NameCreatePerson, WorkTimeCreatePerson, PaymentCreatePerson, PositionCreatePerson);
            company.PrintAllEmployee();
            pauseManu = _getch();
            break;
        case 6:
            system("cls");
            std::cout << "\t\t\t\t\t\tПеревод сотрудника на другой проект" << endl;
            std::cout << "\t\t\t\t\t\tEngineer(1), Programmer(2), Tester(3), TeamLeader(4), ProjectManager(5)" << endl;
            std::cout << "\t\t\t\t\t\tВведите занимаемую должность: "; 
            std::cin >> CurrentPosition;
            std::cout << "\t\t\t\t\t\tВведите ID сотрудника: ";
            std::cin >> IDTransferOfEmployees;
            std::cout << "\t\t\t\t\t\tВведите ID проекта: ";
            std::cin >> IDProject;
            switch (CurrentPosition)
            {
            case 1:
                company.AssignEngineerToProject(IDTransferOfEmployees, IDProject);
                break;
            case 2:
                company.AssignProgrammerToProject(IDTransferOfEmployees, IDProject);
                break;
            case 3:
                company.AssignTesterToProject(IDTransferOfEmployees, IDProject);
                break;
            case 4:
                company.AssignTeamLeaderToProject(IDTransferOfEmployees, IDProject);
                break;
            case 5:
                company.AssignProjectManagerToProject(IDTransferOfEmployees, IDProject);
                break;
            default:
                std::cout << "ERROR" << endl;
                break;
            }
            pauseManu = _getch();
            break;
        case 7:
            system("cls");
            std::cout << "\t\t\t\t\t\tСохранить текущее состояние данных в файл" << endl;
            std::cout << "\t\t\t\t\t\tНазовите файл: ";
            std::cin >> nameFile;
            company.SaveToFileSimple(nameFile);
            pauseManu = _getch();
            break;
        default:
            std::cout << "ERROR" << endl;
            pauseManu = _getch();
            break;
        }
    }

}