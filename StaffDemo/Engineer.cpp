#include "Engineer.h"

Engineer::Engineer(int id, string name, float worktime, int salary, string position) : Personal(id, name, worktime, salary, position) 
{
	calc();
}

Engineer& Engineer::operator=(const Engineer& other)
{
	if (this != &other) {
		id = other.id;
		name = other.name;
		worktime = other.worktime;
		salary = other.salary;
		position = other.position;
		calc();
	}
	return *this;
}

bool Engineer::addProject(Project* project)
{
	if (currentProject == nullptr) {
		currentProject = project;
		return true;
	}
	return false;
}

void Engineer::removeProject()
{
	currentProject = nullptr;
}

Project* Engineer::getProject() const
{
	return currentProject;
}

int Engineer::calcBudgetPart(float part, int budget)
{
	return budget * part;
}

double Engineer::calcAdditions()
{
	return 0;
}

void Engineer::calc()
{
	double totalBudget = 0.0;
	payment = worktime * salary;
	if (currentProject) {
		payment += currentProject->getProjectBudget() * BASE_BONUS_PERCENT;
	}
}

void Engineer::PrintInfo() const
{
	cout << "\t\t\t\t\t\tID: " << id
		<< "\n\t\t\t\t\t\tName: " << name
		<< "\n\t\t\t\t\t\tWork time: " << worktime
		<< "\n\t\t\t\t\t\tPayout: " << salary
		<< "hour\n\t\t\t\t\t\tPayment: " << payment
		<< "\n\t\t\t\t\t\tPosition: " << position
		<< endl;	
	if (currentProject) {
		cout << "\n\t\t\t\t\t\tCurrent Project:" << endl;
		currentProject->PrintInfo();
	}
	else {
		cout << "\n\t\t\t\t\t\tNo project assigned" << endl;
	}
	cout << "\t\t\t\t\t\t==================" << endl;
}

//=================================================================================================

Programmer::Programmer(int id, string name, float worktime, int salary, string position) : Personal(id, name, worktime, salary, position) 
{
	calc();
}

Programmer& Programmer::operator=(const Programmer& other)
{
	if (this != &other) {
		id = other.id;
		name = other.name;
		worktime = other.worktime;
		salary = other.salary;
		position = other.position;
		calc();
	}
	return *this;
}

bool Programmer::addProject(Project* project)
{
	if (currentProject == nullptr) {
		currentProject = project;
		return true;
	}
	return false;
}

void Programmer::removeProject()
{
	currentProject = nullptr;
}

Project* Programmer::getProject() const
{
	return currentProject;
}

void Programmer::markCodeCompletedEarly(bool completedEarly)
{
	codeCompletedEarly = completedEarly;
}

int Programmer::calcBudgetPart(float part, int budget)
{
	return part * budget;
}

double Programmer::calcAdditions()
{
	return 8000;
}

void Programmer::calc()
{
	payment = worktime * salary;
	if (currentProject) 
	{
		codeCompletedEarly == false ? payment += currentProject->getProjectBudget() * BASE_BONUS_PERCENT : payment += currentProject->getProjectBudget() * BASE_BONUS_PERCENT + calcAdditions();

	}
}

void Programmer::PrintInfo() const
{
	cout << "\t\t\t\t\t\tID: " << id
		<< "\n\t\t\t\t\t\tName: " << name
		<< "\n\t\t\t\t\t\tWork time: " << worktime
		<< "\n\t\t\t\t\t\tPayout: " << salary
		<< "hour\n\t\t\t\t\t\tPayment: " << payment
		<< "\n\t\t\t\t\t\tPosition: " << position
		<< endl;		
	if (currentProject) {
		cout << "\n\t\t\t\t\t\tCurrent Project:" << endl;
		currentProject->PrintInfo();
	}
	else {
		cout << "\n\t\t\t\t\t\tNo project assigned" << endl;
	}
	cout << "\t\t\t\t\t\t==================" << endl;
}

//=================================================================================================

Tester::Tester(int id, string name, float worktime, int salary, string position) : Personal(id, name, worktime, salary, position) 
{
	calc();
}

Tester& Tester::operator=(const Tester& other)
{
	if (this != &other) {
		id = other.id;
		name = other.name;
		worktime = other.worktime;
		payment = other.payment;
		position = other.position;
		calc();
	}
	return *this;
}

bool Tester::addProject(Project* project)
{
	if (currentProject == nullptr) {
		currentProject = project;
		return true;
	}
	return false;
}

void Tester::removeProject()
{
	currentProject = nullptr;
}

Project* Tester::getProject() const
{
	return currentProject;
}

void Tester::addFoundBugs(int count)
{
	if (count > 0) {
		bugsFound += count;
	}
}

void Tester::resetBugCount()
{
	bugsFound = 0;
}

int Tester::calcBudgetPart(float part, int budget)
{
	return 0;
}

double Tester::calcAdditions()
{
	return 0;
}

void Tester::calc()
{
	payment = worktime * salary;
	if (currentProject) {
		payment += currentProject->getProjectBudget() * BASE_BONUS_PERCENT;
	}
	bugsFound > 0 ? payment += bugsFound * BUG_BONUS : payment;
}

void Tester::PrintInfo() const
{
	cout << "\t\t\t\t\t\tID: " << id
		<< "\n\t\t\t\t\t\tName: " << name
		<< "\n\t\t\t\t\t\tWork time: " << worktime
		<< "\n\t\t\t\t\t\tPayout: " << salary
		<< "hour\n\t\t\t\t\t\tPayment: " << payment
		<< "\n\t\t\t\t\t\tPosition: " << position
		<< endl;		
	if (currentProject) {
		cout << "\n\t\t\t\t\t\tCurrent Project:" << endl;
		currentProject->PrintInfo();
	}
	else {
		cout << "\n\t\t\t\t\t\tNo project assigned" << endl;
	}
	cout << "\t\t\t\t\t\t==================" << endl;
}

//=================================================================================================

TeamLeader::TeamLeader(int id, string name, float worktime, int salary, string position) : Personal(id, name, worktime, salary, position) 
{
	calc();
}

bool TeamLeader::addProject(Project* project)
{
	if (currentProject == nullptr) {
		currentProject = project;
		return true;
	}
	return false;
}

void TeamLeader::removeProject()
{
	currentProject = nullptr;
}

Project* TeamLeader::getProject() const
{
	return currentProject;
}

void TeamLeader::addTeamMember(Programmer* programmer)
{
	if (programmer != nullptr) 
	{
		team.push_back(programmer);
		calc();
	}
}

bool TeamLeader::removeTeamMember(Programmer* programmer)
{
	auto it = find(team.begin(), team.end(), programmer);
	if (it != team.end()) {
		team.erase(it);
		calc();
		return true;
	}
	return false;
}

const vector<Programmer*>& TeamLeader::getTeamMembers() const
{
	return team;
}

void TeamLeader::clearTeam()
{
	if (!team.empty()) 
	{
		team.clear();
		calc();
	}
}

void TeamLeader::calc()
{
	payment = worktime * salary + calcHeading();
	if (currentProject) {
		payment += currentProject->getProjectBudget() * BASE_BONUS_PERCENT;
	}

}

int TeamLeader::calcHeading()
{
	double teamBonus = 0;
	if (!team.empty())
	{
		teamBonus = salary * TEAM_BONUS_PERCENT * team.size();
	}
	return teamBonus;
}

void TeamLeader::PrintInfo() const
{
	cout << "\t\t\t\t\t\tID: " << id 
		<< "\n\t\t\t\t\t\tName: " << name 
		<< "\n\t\t\t\t\t\tWork time: " << worktime 
		<< "\n\t\t\t\t\t\tPayment: " << payment 
		<< "\n\t\t\t\t\t\tTeam size: " << team.size() << endl;
	if (currentProject) {
		cout << "\n\t\t\t\t\t\tCurrent Project:" << endl;
		currentProject->PrintInfo();
	}
	else {
		cout << "\n\t\t\t\t\t\tNo project assigned" << endl;
	}
	cout << "\t\t\t\t\t\t==================" << endl;
}
