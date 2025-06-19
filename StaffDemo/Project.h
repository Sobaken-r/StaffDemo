#pragma once
#include <iostream>
using namespace std;
class Project
{
protected:
	int idProject;
	string nameProject;
	float budgetProject;
public:
	Project() : idProject{ 0 }, nameProject{ "Not found" }, budgetProject{ 0 } {};
	Project(int id, string name, float budget) : idProject{ id }, nameProject{ name }, budgetProject{ budget } {};

	void setProjectID(int id);
	void setProjectName(string name);
	void setProjectBudget(float budget);

	int getProjectID() const;
	string getProjectName() const;
	float getProjectBudget() const;

	void PrintInfo() const;
};
