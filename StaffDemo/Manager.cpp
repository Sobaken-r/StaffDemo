#include "Manager.h"
#include <iostream>


ProjectManager& ProjectManager::operator=(const ProjectManager& other)
{
	if (this != &other) {
		id = other.id;
		name = other.name;
		worktime = other.worktime;
		payment = other.payment;
		position = other.position;
	}
	return *this;
}

bool ProjectManager::addProject(Project* project)
{
	if (!currentProject && project) {
		currentProject = project;
		return true;
	}
	return false;
}

void ProjectManager::removeProject()
{
	currentProject = nullptr;
}

Project* ProjectManager::getProject() const
{
	return currentProject;
}

void ProjectManager::addTeamMember(Employee* employee)
{
	if (employee != nullptr) {
		team.push_back(employee);
	}
}

void ProjectManager::PrintInfo()
{
	calc();
	cout << "\t\t\t\t\t\t===== PROJECT MANAGER =====" << endl;
	cout << "\t\t\t\t\t\tID: " << id
		<< "\n\t\t\t\t\t\tName: " << name
		<< "\n\t\t\t\t\t\tPosition: " << position
		<< "\n\t\t\t\t\t\tWork time: " << worktime << " hours"
		<< "\n\t\t\t\t\t\tHourly rate: " << payment << "$"
		<< "\n\t\t\t\t\t\tTotal salary: " << salary << "$" << endl;

	if (currentProject) {
		cout << "\n\t\t\t\t\t\tCurrent Project:" << endl;
		currentProject->PrintInfo();
	}
	else {
		cout << "\n\t\t\t\t\t\tNo project assigned" << endl;
	}

	cout << "\n\t\t\t\t\t\tTeam members (" << team.size() << "):" << endl;
	for (const auto& member : team) {
		if (member) {
			cout << "\t\t\t\t\t\t - " << member->getName()
				<< " (" << member->getPosition() << ")" << endl;
		}
	}
	cout << "\t\t\t\t\t\t========================" << endl;
}

void ProjectManager::calc()
{
	double totalBudget = 0.0;
	if (currentProject) {
		payment += currentProject->getProjectBudget() * BASE_BONUS_PERCENT;
	}

	salary += totalBudget * BASE_BONUS_PERCENT;

	salary += totalBudget * 0.1;
	if (!team.empty()) {
		salary += TEAM_BONUS_PERCENT;
	}
}

int ProjectManager::calcHeading()
{
	return 3000;
}

//=================================================================================================

bool SeniorManager::addProject(Project* project)
{
	if (!project) return false;

	// Проверка на дубликат
	for (Project* p : allProjects) {
		if (p && p->getProjectID() == project->getProjectID()) {
			return false;
		}
	}

	allProjects.push_back(project);
	return true;
}

bool SeniorManager::removeProject(Project* project)
{
	if (!project) return false;

	for (auto it = allProjects.begin(); it != allProjects.end(); ++it) {
		if (*it == project) {
			allProjects.erase(it);
			return true;
		}
	}
	return false;
}

void SeniorManager::addTeamMember(Employee* member)
{
	if (member) {
		allTeamMembers.push_back(member);
	}
}

void SeniorManager::PrintInfo()
{
	calc();
	cout << "\t\t\t\t\t\t===== SENIOR MANAGER =====" << endl;
	cout << "\t\t\t\t\t\tID: " << id
		<< "\n\t\t\t\t\t\tName: " << name
		<< "\n\t\t\t\t\t\tPosition: " << position
		<< "\n\t\t\t\t\t\tWork time: " << worktime << " hours"
		<< "\n\t\t\t\t\t\tHourly rate: " << payment << "$"
		<< "\n\t\t\t\t\t\tTotal salary: " << salary << "$"
		<< "\n\n\t\t\t\t\t\tManaged Projects (" << allProjects.size() << "):" << endl;

	for (Project* project : allProjects) {
		if (project) {
			cout << "\t\t\t\t\t\t- " << project->getProjectName()
				<< " (Budget: " << project->getProjectBudget() << "$)" << endl;
		}
	}

	cout << "\n\t\t\t\t\t\tTeam Members (" << allTeamMembers.size() << "):" << endl;
	for (Employee* member : allTeamMembers) {
		if (member) {
			cout << "\t\t\t\t\t\t - " << member->getName()
				<< " (" << member->getPosition() << ")" << endl;
		}
	}
	cout << "\t\t\t\t\t\t========================" << endl;
}


void SeniorManager::calc()
{
	salary = worktime * payment;

	// Бонус от всех проектов
	double totalBudget = 0.0;
	for (Project* project : allProjects) {
		if (project) {
			totalBudget += project->getProjectBudget();
		}
	}
	salary += totalBudget * BASE_BONUS_PERCENT;

	// Бонус за команду
	if (!allTeamMembers.empty()) {
		salary += salary * TEAM_BONUS_PERCENT;
	}
}

int SeniorManager::calcHeading()
{
	return 3000;
}
