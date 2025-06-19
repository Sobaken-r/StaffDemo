#pragma once
#include "Employee.h"
#include "Personal.h"
#include "Project.h"
#include <vector>
class Engineer : public Personal, public Project, public ProjectBudget
{
private:
	const double BASE_BONUS_PERCENT = 0.05;
	Project* currentProject = nullptr;
public:
	Engineer() {};
	Engineer(int id, string name,float worktime, int salary, string position);
	Engineer& operator=(const Engineer& other);

	bool addProject(Project* project);
	void removeProject();
	Project* getProject() const;

	int calcBudgetPart(float part, int budget) override;
	double calcAdditions() override;
	void calc();

	void PrintInfo() const;
};

class Programmer : public Personal, public ProjectBudget
{
private:
	const double BASE_BONUS_PERCENT = 0.05;
	bool codeCompletedEarly = false;
	Project* currentProject = nullptr;
public:
	Programmer() : Personal() {};
	Programmer(int id, string name, float worktime, int salary, string position);
	Programmer& operator=(const Programmer& other);

	bool addProject(Project* project);
	void removeProject();
	Project* getProject() const;

	void markCodeCompletedEarly(bool completedEarly);
	int calcBudgetPart(float part, int budget) override;
	double calcAdditions() override;
	void calc();

	void PrintInfo() const;
};

class Tester : public Personal, public ProjectBudget
{
private:
	int bugsFound = 0;
	const double BASE_BONUS_PERCENT = 0.05;
	const double BUG_BONUS = 50.0;
	Project* currentProject = nullptr;
public:
	Tester() : Personal() {};
	Tester(int id, string name, float worktime, int salary, string position);
	Tester& operator=(const Tester& other);

	bool addProject(Project* project);
	void removeProject();
	Project* getProject() const;	

	void addFoundBugs(int count);
	void resetBugCount();

	int calcBudgetPart(float part, int budget) override;
	double calcAdditions() override;
	void calc();

	void PrintInfo() const;
};


class TeamLeader : public Personal, public Heading
{
private:
	const double TEAM_BONUS_PERCENT = 2;
	const double BASE_BONUS_PERCENT = 0.05;
	Project* currentProject = nullptr;
	vector<Programmer*> team;
public:
	TeamLeader() : Personal() {};
	TeamLeader(int id, string name,float worktime, int salary, string position);

	bool addProject(Project* project);
	void removeProject();
	Project* getProject() const;


	void addTeamMember(Programmer* programmer);
	const vector<Programmer*>& getTeamMembers() const;

	void calc();
	int calcHeading();

	void PrintInfo() const;
};