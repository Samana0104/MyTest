#pragma once
#include "Employee.h"

// 사원 클래스
class Employee_1 : public Employee
{
public:
	Employee_1(const std::string& _name, SALARY_TYPE _salaryType, Uint _salary, Uint _serviceYear)
		: Employee(_name, _salaryType, _salary, _serviceYear)
	{ }

	virtual Salary GetPay(Uint workHours = 0) const override
	{
		Salary mySalary = this->salary + this->serviceYear;

		return this->GetSalaryPerType(this->salaryType, mySalary, workHours);
	}

	virtual void ShowInfo() const override
	{
		
	}

private:

};

