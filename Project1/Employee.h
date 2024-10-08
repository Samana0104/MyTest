#pragma once

#include <string>

enum class SALARY_TYPE
{
	HOUR_TIME,
	MONTHLY_TIME,
	ANNUAL_TIME
};

typedef unsigned int Salary;
typedef unsigned int Uint;

const int DEFAULT_WORK_HOURS = 8;

class Employee
{
public:
	Employee(const std::string &_name, SALARY_TYPE _salaryType, Salary _salary, Uint _serviceYear);
	virtual Salary GetPay(Uint workHours) const = 0;
	virtual void ShowInfo() const = 0;
		
protected:
	Uint salary;
	Uint serviceYear;
	std::string name;
	SALARY_TYPE salaryType;

	Salary GetSalaryPerType(SALARY_TYPE _salaryType, Salary _salary, Uint workHours) const;
};

