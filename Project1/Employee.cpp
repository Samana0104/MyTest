#include "Employee.h"

Employee::Employee(const std::string &_name, SALARY_TYPE _salaryType, Salary _salary, Uint _serviceYear) 
	: name(_name), salaryType(_salaryType), salary(_salary), serviceYear(_serviceYear)
{
}

Salary Employee::GetSalaryPerType(SALARY_TYPE _salaryType, Salary _salary, Uint workHours = 0) const
{
	Uint totalSalary = 0;

	switch (this->salaryType)
	{
	case SALARY_TYPE::ANNUAL_TIME: //  ������ 
		totalSalary = (this->salary / 12);
		break;

	case SALARY_TYPE::MONTHLY_TIME: // ������
		totalSalary = this->salary;
		break;

	case SALARY_TYPE::HOUR_TIME: // �ð���
		if (workHours == 0)
			totalSalary = this->salary * DEFAULT_WORK_HOURS;
		else
			totalSalary = this->salary * workHours;
		break;
	}

	return totalSalary;
}

