#include "Factory.h"
#include <iostream>
using namespace std;
Factory::Factory() 
{
	СreateProject(101, "AI Implementation", 120000);
	СreateProject(102, "Game Engine", 150000);
	СreateProject(103, "Website Redesign", 80000);

	CreateEngineer(1, "Egor", 180, 200, "Engineer");
	CreateEngineer(2, "Ivan", 180, 200, "Engineer");
	CreateEngineer(3, "Maria", 180, 200, "Engineer");

	CreateProgrammer(1, "Giovanni", 150, 180, "Junior Programmer");
	CreateProgrammer(2, "Django", 200, 230, "Middle Programmer");
	CreateProgrammer(3, "Zack", 150, 180, "Junior Programmer");
	CreateProgrammer(4, "Victor", 200, 230, "Middle Programmer");
	CreateProgrammer(5, "Ivan", 200, 300, "Senior Programmer");
	CreateProgrammer(6, "Orion", 200, 300, "Senior Programmer");

	CreateTester(1, "Anna", 150, 180, "Junior Tester");
	CreateTester(2, "Bella", 200, 230, "Middle Tester");
	CreateTester(3, "Carol", 150, 180, "Junior Tester");
	CreateTester(4, "Diana", 200, 230, "Middle Tester");
	CreateTester(5, "Eva", 200, 300, "Senior Tester");
	CreateTester(6, "Fiona", 200, 300, "Senior Tester");

	CreateTeamLeader(1, "Victor", 200, 250, "Team Leader");
	CreateTeamLeader(2, "Diana", 200, 250, "Team Leader");
	CreateTeamLeader(3, "Giovanni", 200, 250, "Team Leader");

	CreateProjectManager(1, "Victor", 200, "Senior PM");
	CreateProjectManager(2, "Diana", 200, "Lead PM");
	CreateProjectManager(3, "Diana", 200, "Technical PM");

	CreateSeniorManager(1, "John", 200, "CEO");

	cleaners.emplace_back(1, "Egor", 100, 75, "Cleaner");
	cleaners.emplace_back(2, "Maria", 100, 75, "Cleaner");
	cleaners.emplace_back(3, "Ivan", 100, 75, "Cleaner");

	drivers.emplace_back(1, "Egor", 120, 100, "Driver");
	drivers.emplace_back(2, "Ivan", 120, 100, "Driver");

	seniorManager.setID(1);
	seniorManager.setName("Roman");
	seniorManager.setWorktime(200);
}

void Factory::PrintAllProject()
{
	for (int i = 0; i < projectCount; i++) 
	{
		projects[i].PrintInfo();
		cout << endl;
	}
}

void Factory::giveProject()
{
	for (int i = 0; i < 5; ++i) {
		int projectIndex = i % 3;
		engineers[i].addProject(&projects[projectIndex]);
	}
	for (int i = 0; i < 6; ++i) {
		int projectIndex = i % 3;
		progremmers[i].addProject(&projects[projectIndex]);
	}
	for (int i = 0; i < 6; ++i) {
		int projectIndex = i % 3;
		testers[i].addProject(&projects[projectIndex]);
	}
	for (int i = 0; i < 5; ++i)
	{
		if (i < 3)
		{
			teamLeders[i].addProject(&projects[i]);
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (i < 3)
		{
			projectManagers[i].addProject(&projects[i]);
		}
	}
	seniorManager.addProject(&projects[0]);
	seniorManager.addProject(&projects[1]);
	seniorManager.addProject(&projects[2]);
}

void Factory::giveTeam()
{
	for (Programmer& programmer : progremmers) {
		if (programmer.getProject() != nullptr) {
			for (TeamLeader& leader : teamLeders) {
				if (leader.getProject() != nullptr &&
					leader.getProject()->getProjectID() == programmer.getProject()->getProjectID()) {
					leader.addTeamMember(&programmer);
					break;
				}
			}
		}
	}
	for (Programmer& prog : progremmers) {
		if (prog.getProject()) {
			for (ProjectManager& projectManager : projectManagers) {
				if (projectManager.getProject() &&
					projectManager.getProject()->getProjectID() == prog.getProject()->getProjectID()) {
					projectManager.addTeamMember(&prog);
					break;
				}
			}
		}
	}
	for (Tester& tester : testers) {
		if (tester.getProject()) {
			for (ProjectManager& projectManager : projectManagers) {
				if (projectManager.getProject() &&
					projectManager.getProject()->getProjectID() == tester.getProject()->getProjectID()) {
					projectManager.addTeamMember(&tester);
					break;
				}
			}
		}
	}
	for (int i = 0; i < testerCount; ++i)
	{
		seniorManager.addTeamMember(&testers[i]);
	}
	for (int i = 0; i < programmerCount; ++i)
	{
		seniorManager.addTeamMember(&progremmers[i]);
	}
	for (int i = 0; i < projectManagersCount; ++i)
	{
		seniorManager.addTeamMember(&projectManagers[i]);
	}
}

void Factory::PrintAllEmployee()
{
	giveProject();
	giveTeam();
	std::cout << "\t\t\t\t----------------Cleaner-----------------" << endl;
	for (Cleaner& cleaner : cleaners)
	{
		cleaner.PrintInfo();
		std::cout << endl;
	}
	std::cout << "\t\t\t\t----------------Driver-----------------" << endl;
	for (Driver& driver : drivers)
	{
		driver.PrintInfo();
		std::cout << endl;
	}
	std::cout << "\t\t\t\t----------------Engineer-----------------" << endl;
	for (int i = 0; i < engineerCount; ++i) {
		engineers[i].PrintInfo();
		std::cout << std::endl;
	}
	std::cout << "\t\t\t\t----------------Programmer-----------------" << endl;
	for (int i = 0; i < programmerCount; ++i)
	{
		progremmers[i].PrintInfo();
		std::cout << endl;
	}
	std::cout << "\t\t\t\t----------------Tester-----------------" << endl;
	for (int i = 0; i < testerCount; ++i) {
		testers[i].PrintInfo();
		std::cout << endl;
	}
	std::cout << "\t\t\t\t--------------TeamLeader-----------------" << endl;

	for (int i = 0; i < teamLedersCount; ++i) {
		teamLeders[i].PrintInfo();
		std::cout << "\t\t\t\t\t\tTeam members:" << endl;
		for (Programmer* member : teamLeders[i].getTeamMembers()) {
			std::cout << "\t\t\t\t\t\t  - " << member->getName() << " (ID: " << member->getID() << ")" << endl;
		}
		std::cout << "\t\t\t\t\t\t---------------------" << endl;
	}
	std::cout << "\t\t\t\t--------------ProjectManager-----------------" << endl;
	for (int i = 0; i < projectManagersCount; ++i) {
		projectManagers[i].PrintInfo();
		std::cout << endl;
	}
	seniorManager.PrintInfo();
}

void Factory::PrintEmployeesByProject(int projectID)
{
	giveProject();
	giveTeam();
	bool projectFound = false;

	// Проверяем существование проекта
	for (const Project& project : projects) {
		if (project.getProjectID() == projectID) {
			projectFound = true;
			break;
		}
	}

	if (!projectFound) {
		std::cout << "Проект с идентификатором " << projectID << " не найдено!" << endl;
		return;
	}

	std::cout << "===== Employees working on project ID " << projectID << " =====" << endl;

	// Поиск инженеров
	std::cout << "\n\t\t\t\tEngineers:" << endl;
	for (const Engineer& eng : engineers) {
		if (eng.getProject() && eng.getProject()->getProjectID() == projectID) {
			eng.PrintInfo();
			std::cout << endl;
		}
	}

	// Поиск программистов
	std::cout << "\n\t\t\t\tProgrammers:" << endl;
	for (const Programmer& prog : progremmers) {
		if (prog.getProject() && prog.getProject()->getProjectID() == projectID) {
			prog.PrintInfo();
			std::cout << endl;
		}
	}
	// Поиск тестеров
	std::cout << "\n\t\t\t\tTesters:" << endl;
	for (const Tester& tester : testers) {
		if (tester.getProject() && tester.getProject()->getProjectID() == projectID) {
			tester.PrintInfo();
			std::cout << endl;
		}
	}
	// Поиск тимлидов
	std::cout << "\n\t\t\t\tTeam Leaders:" << endl;
	for (const TeamLeader& leader : teamLeders) {
		if (leader.getProject() && leader.getProject()->getProjectID() == projectID) {
			leader.PrintInfo();
			std::cout << endl;
		}
	}
}

void Factory::SearchEmployeeByName(const string& name, int professionOption)
{
	giveProject();
	giveTeam();
	bool found = false;
	std::cout << "===== Employees with name \"" << name << "\" =====" << endl;
	switch (professionOption)
	{
	case 1://Cleaner
		for (const Cleaner& employee : cleaners) {
			if (employee.getName() == name) {
				employee.PrintInfo();
				found = true;
			}
		}
		break;
	case 2://Driver
		for (const Driver& employee : drivers) {
			if (employee.getName() == name) {
				employee.PrintInfo();
				found = true;
			}
		}
		break;
	case 3:// Engineer
		for (const Engineer& employee : engineers) {
			if (employee.getName() == name) {
				employee.PrintInfo();
				found = true;
			}
		}
		break;
	case 4:
		for (const Programmer& employee : progremmers) {
			if (employee.getName() == name) {
				employee.PrintInfo();
				found = true;
			}
		}
		break;
	case 5:
		for (const Tester& employee : testers) {
			if (employee.getName() == name) {
				employee.PrintInfo();
				found = true;
			}
		}
		break;
	case 6:
		for (const TeamLeader& employee : teamLeders) {
			if (employee.getName() == name) {
				employee.PrintInfo();
				found = true;
			}
		}
		break;
	case 7:
		for (ProjectManager& employee : projectManagers) {
			if (employee.getName() == name) {
				employee.PrintInfo();
				found = true;
			}
		}
		break;
	case 8:
		if (seniorManager.getName() == name) {
			seniorManager.PrintInfo();
			found = true;
		}
		break;
	default:
		break;
	}
}

void Factory::FindBySalarySimple(double salary, bool greater_than)
{
	giveProject();
	bool found = false;
	auto checkSalary = [&](Cleaner& emp)
	{
		emp.calc();
		int currentSalary = emp.getPayment();
		bool condition = greater_than ? (currentSalary > salary) : (currentSalary < salary);

		if (condition) {
			emp.PrintInfo();
			return true;
		}
		return false;
	};
	auto checkSalaryD = [&](Driver& emp)
	{
		emp.calc();
		int currentSalary = emp.getPayment();
		bool condition = greater_than ? (currentSalary > salary) : (currentSalary < salary);

		if (condition) {
			emp.PrintInfo();
			return true;
		}
		return false;
	};
	auto checkSalaryP = [&](Programmer& emp)
		{
			emp.calc();
			int currentSalary = emp.getPayment();
			bool condition = greater_than ? (currentSalary > salary) : (currentSalary < salary);

			if (condition) {
				emp.PrintInfo();
				return true;
			}
			return false;
		};
	auto checkSalaryT = [&](Tester& emp)
		{
			emp.calc();
			int currentSalary = emp.getPayment();
			bool condition = greater_than ? (currentSalary > salary) : (currentSalary < salary);

			if (condition) {
				emp.PrintInfo();
				return true;
			}
			return false;
		};
	auto checkSalaryE = [&](Engineer& emp)
		{
			emp.calc();
			int currentSalary = emp.getPayment();
			bool condition = greater_than ? (currentSalary > salary) : (currentSalary < salary);

			if (condition) {
				emp.PrintInfo();
				return true;
			}
			return false;
		};
	for (Cleaner& cleaner : cleaners) found |= checkSalary(cleaner);
	for (Driver& driver : drivers) found |= checkSalaryD(driver);
	for (int i = 0; i < testerCount; i++) found |= checkSalaryT(testers[i]);
	for (int i = 0; i < engineerCount; i++) found |= checkSalaryE(engineers[i]);
	for (int i = 0; i < programmerCount; i++) found |= checkSalaryP(progremmers[i]);

	if (!found) 
	{
		std::cout << "No employees found." << endl;
	}
}

void Factory::SaveToFileSimple(const string& filename)
{
	ofstream outFile(filename);
	if (!outFile.is_open()) {
		cout << "Error: Cannot open file!" << endl;
		return;
	}


	outFile << "\n[Project]\n";
	for (int i = 0; i < projectCount; i++)
	{
		outFile << projects[i].getProjectID() << "," << projects[i].getProjectName() << "," << projects[i].getProjectBudget() << endl;
	}

	outFile << "=== Employee Data ===" << endl;

	outFile << "\n[Cleaners]\n";
	for (const auto& cleaner : cleaners) 
	{
		outFile << cleaner.getID() << ","<< cleaner.getName() << ","<< cleaner.getPayment() << ","<< cleaner.getWorktime() << "," << cleaner.getSalary() << "," << endl;
	}

	outFile << "\n[Drivers]\n";
	for (const auto& driver : drivers) 
	{
		outFile << driver.getID() << "," << driver.getName() << ","<< driver.getPayment() << "," << driver.getWorktime() << "," << driver.getSalary() << endl;
	}

	outFile << "\n[Engineer]\n";
	for (int i = 0; i < engineerCount; i++) 
	{
		outFile << engineers[i].getID() << "," << engineers[i].getName() << "," << engineers[i].getPayment() << "," << engineers->getWorktime() << "," << engineers->getSalary() << endl;
	}
	for (int i = 0; i < engineerCount; i++)
	{
		outFile << "Engineer," << engineers[i].getID() << "," << engineers[i].getProject()->getProjectID() << "\n";
	}

	outFile << "\n[Programmer]\n";
	for (int i = 0; i < programmerCount; i++)
	{
		outFile << progremmers[i].getID() << "," << progremmers[i].getName() << "," << progremmers[i].getPayment() << "," << progremmers->getWorktime() << "," << progremmers->getSalary() << endl;
	}
	for (int i = 0; i < programmerCount; i++) 
	{
		outFile << "Programmer," << progremmers[i].getID() << "," << progremmers[i].getProject()->getProjectID() << "\n";
	}

	outFile << "\n[Testers]\n";
	for (int i = 0; i < testerCount; i++) 
	{
		outFile << testers[i].getID() << ","<< testers[i].getName() << ","<< testers[i].getPayment() << "," << testers->getWorktime() << "," << testers->getSalary() << endl;
	}
	for (int i = 0; i < testerCount; i++) 
	{
		outFile << "Tester," << testers[i].getID() << "," << testers[i].getProject()->getProjectID() << "\n";
	}

	outFile << "\n[TeamLeader]\n";
	for (int i = 0; i < teamLedersCount; i++) 
	{
		outFile << teamLeders[i].getID() << "," << teamLeders[i].getName() << "," << teamLeders[i].getPayment() << "," << teamLeders->getWorktime() << "," << teamLeders->getSalary() << endl;
	}
	for (int i = 0; i < teamLedersCount; i++) 
	{
		outFile << "TeamLeader," << teamLeders[i].getID() << "," << teamLeders[i].getProject()->getProjectID() << "\n";
	}

	outFile << "\n[ProjectManager]\n";
	for (int i = 0; i < projectManagersCount; i++) 
	{
		outFile << projectManagers[i].getID() << "," << projectManagers[i].getName() << "," << projectManagers[i].getPayment() << "," << projectManagers->getWorktime() << endl;
	}
	for (int i = 0; i < projectManagersCount; i++) 
	{
		outFile << "ProjectManager," << projectManagers[i].getID() << ","<< projectManagers[i].getProject()->getProjectID() << "\n";
	}

	outFile << "\n[SeniorManager]\n";
		outFile << seniorManager.getID() << "," << seniorManager.getName() << "," << seniorManager.getPayment() << "," << seniorManager.getWorktime() << endl;
	outFile.close();
	std::cout << "Data saved to " << filename << endl;
}

void Factory::СreateProject(int projectID, const string& projectName, double budget)
{
	if (projectCount >= MAX_PROJECTS) {
		cout << "Error: Maximum number of projects (" << MAX_PROJECTS << ") reached!" << endl;
		return;
	}

	for (int i = 0; i < projectCount; ++i) {
		if (projects[i].getProjectID() == projectID) {
			cout << "Error: Проект с идентификатором " << projectID << " already exists!" << endl;
			return;
		}
	}

	projects[projectCount++] = Project(projectID, projectName, budget);
}

void Factory::PrintAllProjects() const
{
	if (projectCount == 0) {
		cout << "No projects available." << endl;
		return;
	}

	cout << "===== List of All Projects (" << projectCount << ") =====" << endl;
	for (int i = 0; i < projectCount; ++i) {
		cout << "Project ID: " << projects[i].getProjectID() << endl;
		cout << "Name: " << projects[i].getProjectName() << endl;
		cout << "Budget: $" << projects[i].getProjectBudget() << endl;
		cout << "-----------------------------" << endl;
	}
}

bool Factory::RemoveProject(int projectID)
{
	int index = -1;

	for (int i = 0; i < projectCount; ++i) {
		if (projects[i].getProjectID() == projectID) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Проект с идентификатором " << projectID << " не найдено." << endl;
		return false;
	}

	for (auto& engineer : engineers) {
		if (engineer.getProject() && engineer.getProject()->getProjectID() == projectID) {
			engineer.removeProject();
		}
	}

	for (int i = index; i < projectCount - 1; ++i) {
		projects[i] = projects[i + 1];
	}

	projectCount--;
	cout << "Проект с идентификатором " << projectID << " removed successfully." << endl;
	return true;
}

void Factory::CreateEngineer(int id, const string& name, int workTime, double salary, const string& position)
{
	if (engineerCount >= MAX_ENGINEERS) {
		cout << "Error: Maximum number of engineers (" << MAX_ENGINEERS << ") reached!" << endl;
		return;
	}

	for (int i = 0; i < engineerCount; ++i) {
		if (engineers[i].getID() == id) {
			cout << "Error: Engineer with ID " << id << " already exists!" << endl;
			return;
		}
	}

	engineers[engineerCount++] = Engineer(id, name, workTime, salary, position);
}

bool Factory::AssignEngineerToProject(int engineerID, int projectID)
{
	Engineer* engineer = nullptr;
	int engineerIndex = -1;

	for (int i = 0; i < engineerCount; ++i) {
		if (engineers[i].getID() == engineerID) {
			engineer = &engineers[i];
			engineerIndex = i;
			break;
		}
	}

	if (!engineer) {
		cout << "Error: Инженер с идентификатором " << engineerID << " не найдено." << endl;
		return false;
	}

	Project* project = nullptr;
	for (int i = 0; i < projectCount; ++i) {
		if (projects[i].getProjectID() == projectID) {
			project = &projects[i];
			break;
		}
	}

	if (!project) {
		cout << "Error: Проект с идентификатором " << projectID << " не найдено." << endl;
		return false;
	}

	Project* currentProject = engineer->getProject();
	if (currentProject && currentProject->getProjectID() == projectID) 
	{
		cout << "Инженер уже назначен на этот проект." << endl;
		return true;
	}

	if (currentProject) {
		cout << "Удаление инженера из проекта: "<< currentProject->getProjectName() << endl;
		engineer->removeProject();
	}

	if (!engineer->addProject(project)) {
		cout << "Error: Не удалось назначить инженера для проекта." << endl;
		return false;
	}

	cout << "Инженер " << engineer->getName() << " назначен для проекта " << project->getProjectName() << endl;

	return true;
}

void Factory::CreateProgrammer(int id, const string& name, int workTime, double salary, const string& position)
{
	if (programmerCount >= MAX_PROGRAMMER) {
		cout << "Error: Maximum number of Programmers (" << MAX_PROGRAMMER << ") reached!" << endl;
		return;
	}

	for (int i = 0; i < programmerCount; ++i) {
		if (engineers[i].getID() == id) {
			cout << "Error: Programmer with ID " << id << " already exists!" << endl;
			return;
		}
	}

	progremmers[programmerCount++] = Programmer(id, name, workTime, salary, position);
}

bool Factory::AssignProgrammerToProject(int programmerID, int projectID)
{
	Programmer* programmer = nullptr;
	int programmerIndex = -1;

	for (int i = 0; i < programmerCount; ++i) {
		if (progremmers[i].getID() == programmerID) {
			programmer = &progremmers[i];
			programmerIndex = i;
			break;
		}
	}

	if (!programmer) {
		cout << "Error: Программатор с идентификатором " << programmerID << " не найдено." << endl;
		return false;
	}

	Project* project = nullptr;
	for (int i = 0; i < projectCount; ++i) {
		if (projects[i].getProjectID() == projectID) {
			project = &projects[i];
			break;
		}
	}

	if (!project) {
		cout << "Error: Проект с идентификатором " << projectID << " не найдено." << endl;
		return false;
	}

	if (programmer->getProject() && programmer->getProject()->getProjectID() == projectID) {
		cout << "Info: Программист уже назначен для этого проекта." << endl;
		return true;
	}

	if (programmer->getProject()) {
		int oldProjectID = programmer->getProject()->getProjectID();
		programmer->removeProject();

		for (int i = 0; i < teamLedersCount; ++i) {
			if (teamLeders[i].getProject() &&
				teamLeders[i].getProject()->getProjectID() == oldProjectID) {
				teamLeders[i].removeTeamMember(programmer);
			}
		}
	}

	programmer->addProject(project);

	for (int i = 0; i < teamLedersCount; ++i) {
		if (teamLeders[i].getProject() &&
			teamLeders[i].getProject()->getProjectID() == projectID) {
			teamLeders[i].addTeamMember(programmer);
			break;
		}
	}

	cout << "Программист " << programmer->getName() << " назначен для проекта " << project->getProjectName() << endl;

	return true;
}

void Factory::CreateTester(int id, const string& name, int workTime, double paymentRate, const string& position)
{
	if (testerCount >= MAX_TESTERS) {
		cout << "Error: Maximum number of Testers (" << MAX_TESTERS << ") reached!" << endl;
		return;
	}

	for (int i = 0; i < testerCount; ++i) {
		if (testers[i].getID() == id) {
			cout << "Error: Tester with ID " << id << " already exists!" << endl;
			return;
		}
	}

	new (&testers[testerCount++])  Tester(id, name, workTime, paymentRate, position);
}

bool Factory::AssignTesterToProject(int testerID, int projectID)
{
	Tester* tester = nullptr;
    int testerIndex = -1;

    for (int i = 0; i < testerCount; ++i) 
	{
        if (testers[i].getID() == testerID) 
		{
            tester = &testers[i];
            testerIndex = i;
            break;
        }
    }

    if (!tester) 
	{
		cout << "Error: Тестировщик с идентификатором" << testerID << " не найдено." << endl;
        return false;
    }

    Project* project = nullptr;
    for (int i = 0; i < projectCount; ++i) 
	{
        if (projects[i].getProjectID() == projectID) 
		{
            project = &projects[i];
            break;
        }
    }

    if (!project) 
	{
		cout << "Error: Проект с идентификатором " << projectID << " не найдено." << endl;
        return false;
    }

    if (tester->getProject() && tester->getProject()->getProjectID() == projectID) 
	{
        cout << "Тестировщик уже назначен для этого проекта." << endl;
        return true;
    }

    if (tester->getProject()) 
	{
        tester->removeProject();
    }

    tester->addProject(project);
    
    cout << "Тестировщик " << tester->getName() << " назначен для проекта " << project->getProjectName() << endl;
    
    return true;
}

void Factory::CreateTeamLeader(int id, const string& name, int workTime, double paymentRate, const string& position)
{
	if (teamLedersCount >= MAX_TEAMLEADER) {
		cout << "Error: Maximum number of Team Leaders (" << MAX_TEAMLEADER << ") reached!" << endl;
		return;
	}

	for (int i = 0; i < teamLedersCount; ++i) {
		if (teamLeders[i].getID() == id) {
			cout << "Error: Team Leader with ID " << id << " already exists!" << endl;
			return;
		}
	}

	new (&teamLeders[teamLedersCount++]) TeamLeader(id, name, workTime, paymentRate, position);
}

bool Factory::AssignTeamLeaderToProject(int leaderID, int projectID)
{
	TeamLeader* leader = nullptr;
	int leaderIndex = -1;

	for (int i = 0; i < teamLedersCount; ++i)
	{
		if (teamLeders[i].getID() == leaderID) 
		{
			leader = &teamLeders[i];
			leaderIndex = i;
			break;
		}
	}

	if (!leader) {
		cout << "Error: Руководитель группы с удостоверением личности " << leaderID << " не найдено." << endl;
		return false;
	}

	Project* project = nullptr;
	for (int i = 0; i < projectCount; ++i) 
	{
		if (projects[i].getProjectID() == projectID) 
		{
			project = &projects[i];
			break;
		}
	}

	if (!project) {
		cout << "Error: Проект с идентификатором " << projectID << " не найдено." << endl;
		return false;
	}

	if (leader->getProject() && leader->getProject()->getProjectID() == projectID) {
		cout << "Руководитель группы уже назначен для этого проекта." << endl;
		return true;
	}

	if (leader->getProject()) {
		leader->clearTeam();
		leader->removeProject();
	}

	leader->addProject(project);

	for (int i = 0; i < programmerCount; ++i) {
		if (progremmers[i].getProject() &&
			progremmers[i].getProject()->getProjectID() == projectID) {
			leader->addTeamMember(&progremmers[i]);
		}
	}

	cout << "Руководитель группы " << leader->getName() << " назначен для проекта " << project->getProjectName() << endl;

	return true;
}

void Factory::CreateProjectManager(int id, string name, float worktime, const string position)
{
	if (projectManagersCount >= MAX_PROJECTMANAGER) {
		cout << "Error: Maximum number of Project Managers (" << MAX_PROJECTMANAGER << ") reached!" << endl;
		return;
	}
	for (int i = 0; i < projectManagersCount; ++i) {
		if (projectManagers[i].getID() == id) {
			cout << "Error: Project Manager with ID " << id << " already exists!" << endl;
			return;
		}
	}
	new (&projectManagers[projectManagersCount++]) ProjectManager(id, name, worktime, position);
}

bool Factory::AssignProjectManagerToProject(int pmID, int projectID)
{
	ProjectManager* pm = nullptr;
	for (int i = 0; i < projectManagersCount; ++i) 
	{
		if (projectManagers[i].getID() == pmID)
		{
			pm = &projectManagers[i];
			break;
		}
	}

	if (!pm) 
	{
		cout << "Error: Руководитель проекта с удостоверением личности " << pmID << " не найдено." << endl;
		return false;
	}

	Project* project = nullptr;
	for (int i = 0; i < projectCount; ++i) 
	{
		if (projects[i].getProjectID() == projectID) 
		{
			project = &projects[i];
			break;
		}
	}

	if (!project) 
	{
		cout << "Error: Проект с идентификатором " << projectID << " не найдено." << endl;
		return false;
	}

	Project* currentProject = pm->getProject();
	if (currentProject && currentProject->getProjectID() == projectID) 
	{
		cout << "Руководитель проекта уже назначен для этого проекта." << endl;
		return true;
	}

	if (currentProject) 
	{
		cout << "Удаление менеджера проекта из текущего проекта: "
			<< currentProject->getProjectName() << endl;
		pm->removeProject();
	}

	if (!pm->addProject(project)) 
	{
		cout << "Error: Не удалось назначить руководителя проекта для project." << endl;
		return false;
	}

	int teamMembersAdded = 0;
	for (int i = 0; i < programmerCount; ++i)
	{
		if (progremmers[i].getProject() &&
			progremmers[i].getProject()->getProjectID() == projectID) 
		{
			pm->addTeamMember(&progremmers[i]);
			teamMembersAdded++;
		}
	}
	for (int i = 0; i < testerCount; ++i) {
		if (testers[i].getProject() &&
			testers[i].getProject()->getProjectID() == projectID) {
			pm->addTeamMember(&testers[i]);
			teamMembersAdded++;
		}
	}

	cout << "Менеджер проекта " << pm->getName()<< " назначен для проекта " << project->getProjectName()<< " с " << teamMembersAdded << " члены команды" << endl;

	return true;
}

bool Factory::AddEmployeeToProjectManager(int pmID, Employee* employee)
{
	ProjectManager* pm = nullptr;

	for (int i = 0; i < projectManagersCount; ++i) {
		if (projectManagers[i].getID() == pmID) {
			pm = &projectManagers[i];
			break;
		}
	}

	if (!pm) {
		cout << "Руководитель проекта с удостоверением личности " << pmID << " не найдено." << endl;
		return false;
	}

	if (!employee) {
		cout << "Error: Неверный указатель сотрудника!" << endl;
		return false;
	}

	pm->addTeamMember(employee);
	cout << employee->getName() << " добавлено в Менеджер проекта "<< pm->getName() << "команда" << endl;
	return true;
}

void Factory::CreateSeniorManager(int id, string name, float worktime, const string position)
{
	seniorManager.setID(id);
	seniorManager.setName(name);
	seniorManager.setWorktime(worktime);
	seniorManager.setPosition(position);
}

void Factory::AssignAllProjectsToSeniorManager()
{
	for (int i = 0; i < projectCount; ++i) {
		seniorManager.addProject(&projects[i]);
	}
	cout << "All " << projectCount << " projects assigned to Senior Manager" << endl;
}

void Factory::AddAllEmployeesToSeniorManager(const string& employeeType)
{
	int added = 0;

	if (employeeType == "programmers") {
		for (int i = 0; i < engineerCount; ++i) {
			seniorManager.addTeamMember(&engineers[i]);
			added++;
		}
	}

	if (employeeType == "programmers") {
		for (int i = 0; i < programmerCount; ++i) {
			seniorManager.addTeamMember(&progremmers[i]);
			added++;
		}
	}
	else if (employeeType == "testers") {
		for (int i = 0; i < testerCount; ++i) {
			seniorManager.addTeamMember(&testers[i]);
			added++;
		}
	}
	cout << "Added " << added << " " << employeeType << " to Senior Manager team" << endl;
}

