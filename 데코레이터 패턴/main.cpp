#include <iostream>
#include <string>
#include <set>
using namespace std;

class Beverage
{
protected:
	string description = "�������";

public:
	virtual string getDescription() 
	{
		return this->description;
	}

	virtual double cost() = 0;

	virtual ~Beverage()
	{

	}
};

class CondimentDecorator : public Beverage
{
public:
	Beverage * beverage;

public:
	virtual double cost() override
	{
		return .1;
	}

	virtual string getDescription() override
	{
		return this->description;
	}

	virtual ~CondimentDecorator()
	{

	}
};

class Espresso : public Beverage
{
public:
	Espresso()
	{
		description = "����������";
	}

	virtual double cost() override
	{
		return 1.99;
	}

	virtual ~Espresso()
	{
		cout << "���������� �Ҹ�" << endl;
	}
};

class HouseBlend : public Beverage
{
public:
	HouseBlend()
	{
		description = "�Ͽ콺 ���� Ŀ��";
	}
	
	virtual double cost() override
	{
		return .89;
	}

	virtual ~HouseBlend()
	{
		cout << "�Ͽ콺 ���� �Ҹ�" << endl;
	}
};

class DarkRoast : public Beverage
{
public:
	DarkRoast()
	{
		description = "��ũ �ν�Ʈ Ŀ��";
	}
	
	virtual double cost() override
	{
		return .89;
	}

	virtual ~DarkRoast()
	{
		cout << "��ũ�ν�Ʈ �Ҹ�" << endl;
	}

};

class Decaf : public Beverage
{
public:
	Decaf()
	{
		description = "Decaf Ŀ��";
	}
	
	virtual double cost() override
	{
		return .89;
	}
};

class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* _beverage)
	{
		this->beverage = _beverage;
	}

	virtual string getDescription()
	{
		return this->beverage->getDescription() + ", ��ī";
	}

	virtual double cost() override
	{
		return beverage->cost() + .20;
	}

	virtual ~Mocha()
	{
		delete beverage;
		cout << "��ī �Ҹ�" << endl;
	}
};

class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* _beverage)
	{
		this->beverage = _beverage;
	}

	virtual string getDescription()
	{
		return this->beverage->getDescription() + ", ����";
	}

	virtual double cost() override
	{
		return beverage->cost() + .20;
	}

	virtual ~Soy()
	{
		delete beverage;
		cout << "���� �Ҹ�" << endl;
	}
};
class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* _beverage)
	{
		this->beverage = _beverage;
	}

	virtual string getDescription()
	{
		return this->beverage->getDescription() + ", ����ũ��";
	}

	virtual double cost() override
	{
		return beverage->cost() + .20;
	}

	virtual ~Whip()
	{
		delete beverage;
		cout << "����ũ�� �Ҹ�" << endl;
	}
};
int main()
{
	//Beverage* beverage = new Espresso();
	//cout << beverage->getDescription() << " $" << beverage->cost() << endl;

	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;
	
	delete beverage2;
	return 0;
}
