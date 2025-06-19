#pragma once
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"
#include "Project.h"
#include "Engineer.h"
#include <vector>
using namespace std;

class ProjectManager : public Employee, public Project
{
protected:
	vector<Employee*> team;
	const double TEAM_BONUS_PERCENT = 0.2;
	const double BASE_BONUS_PERCENT = 0.05;
	int salary = 0;
	Project* currentProject = nullptr;
public:
	ProjectManager() {};
	ProjectManager(int id, string name,float worktime, const string position) : Employee(id, name, worktime, position) {};
	ProjectManager& operator=(const ProjectManager& other);

	bool addProject(Project* project);
	void removeProject();
	Project* getProject() const;

	void addTeamMember(Employee* employee);

	void PrintInfo();
	void calc();
	int calcHeading();
};

class SeniorManager : public Employee, public Project
{
protected:
	vector<Employee*> allTeamMembers;
	const double TEAM_BONUS_PERCENT = 0.3;
	const double BASE_BONUS_PERCENT = 0.3;
	int salary = 0;
	vector<Project*> allProjects;
public:
	SeniorManager() {};
	SeniorManager(int id, string name, float worktime, const string position) : Employee(id, name, worktime, position) {};

	bool addProject(Project* allProjects);
	bool removeProject(Project* project);

	void addTeamMember(Employee* member);

	void PrintInfo();
	void calc();
	int calcHeading();
};

