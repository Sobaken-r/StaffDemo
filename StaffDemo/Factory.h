#include "Personal.h";
#include "Engineer.h"
#include "Project.h"
#include "Manager.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>	
class Factory
{
private:
	static const int MAX_PROJECTS = 10;
	int projectCount = 0;
	Project projects[MAX_PROJECTS];
	//-----------------------------------
	static const int MAX_ENGINEERS = 10;
	int engineerCount = 0;
	Engineer engineers[MAX_ENGINEERS];
	//-----------------------------------
	static const int MAX_PROGRAMMER = 10;
	int programmerCount = 0;
	Programmer progremmers[MAX_PROGRAMMER];
	//-----------------------------------
	static const int MAX_TESTERS = 10;
	int testerCount = 0;
	Tester testers[MAX_TESTERS];
	//-----------------------------------
	static const int MAX_TEAMLEADER = 5;
	int teamLedersCount = 0;
	TeamLeader teamLeders[MAX_TEAMLEADER];
	//-----------------------------------
	static const int MAX_PROJECTMANAGER = 5;
	int projectManagersCount = 0;
	ProjectManager projectManagers[MAX_PROJECTMANAGER];
	//-----------------------------------

	SeniorManager seniorManager;

	vector<Cleaner> cleaners;
	vector<Driver> drivers;
public:

	Factory();

	//вывод всех проектов
	void PrintAllProject();

	//выдать проекты и команду
	void giveProject();
	void giveTeam();

	//вывод всех сотрудников
	void PrintAllEmployee();

	//вывод сотрудников по роекту
	void PrintEmployeesByProject(int projectID);

	//Поиск сотрудников по имени и профе
	void SearchEmployeeByName(const string& name, int professionOption);

	//поиск по имени
	void FindBySalarySimple(double salary, bool findGreater);

	//сохранение проекта
	void SaveToFileSimple(const string& filename);

	//-------------------------------------------------------Project
	void СreateProject(int projectID, const string& projectName, double budget);
	void PrintAllProjects() const;
	bool RemoveProject(int projectID);
	//-------------------------------------------------------Engineer
	void CreateEngineer(int id, const string& name, int workTime, double paymentRate, const string& position);
	bool AssignEngineerToProject(int engineerID, int projectID);
	//-------------------------------------------------------Programmer
	void CreateProgrammer(int id, const string& name, int workTime, double paymentRate, const string& position);
	bool AssignProgrammerToProject(int engineerID, int projectID);
	//-------------------------------------------------------Tester
	void CreateTester(int id, const string& name, int workTime, double paymentRate, const string& position);
	bool AssignTesterToProject(int testerID, int projectID);
	//-------------------------------------------------------TeamLeader
	void CreateTeamLeader(int id, const string& name, int workTime, double paymentRate, const string& position);
	bool AssignTeamLeaderToProject(int leaderID, int projectID);
	//-------------------------------------------------------ProjectManager
	void CreateProjectManager(int id, string name, float worktime, const string position);
	bool AssignProjectManagerToProject(int pmID, int projectID);
	bool AddEmployeeToProjectManager(int pmID, Employee* employee);
	//-------------------------------------------------------SeniorManager
	void CreateSeniorManager(int id, string name, float worktime, const string position);
	void AssignAllProjectsToSeniorManager();
	void AddAllEmployeesToSeniorManager(const string& employeeType);
};
