#pragma once
class WorkBaceTime
{
public:
	virtual int calcBace(int salary, int wtime) = 0;
	virtual int calcBonus() = 0;
};

class Heading
{
public:
	virtual int calcHeading() = 0;
};

class ProjectBudget
{
public:
	virtual int calcBudgetPart(float part, int budget) = 0;
	virtual double calcAdditions() = 0;
};