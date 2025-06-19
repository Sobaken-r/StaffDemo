#include "Project.h"

void Project::setProjectID(int id)
{
	this->idProject = id;
}

void Project::setProjectName(string name)
{
	this->nameProject = name;
}

void Project::setProjectBudget(float budget)
{
	this->budgetProject = budget;
}

int Project::getProjectID() const
{
	return idProject;
}

string Project::getProjectName() const
{
	return nameProject;
}

float Project::getProjectBudget() const
{
	return budgetProject;
}

void Project::PrintInfo() const
{
	cout << "\t\t\t\t\t\tId: " << idProject 
		<< "\n\t\t\t\t\t\tName Project: " << nameProject 
		<< "\n\t\t\t\t\t\tBudget: " << budgetProject 
		<< endl;
}
