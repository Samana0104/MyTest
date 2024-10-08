#include <iostream>
#include <string>
#include <set>
using namespace std;

class Beverage
{
protected:
	string description = "제목없음";

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
		description = "에스프레소";
	}

	virtual double cost() override
	{
		return 1.99;
	}

	virtual ~Espresso()
	{
		cout << "에스프레스 소멸" << endl;
	}
};

class HouseBlend : public Beverage
{
public:
	HouseBlend()
	{
		description = "하우스 블렌드 커피";
	}
	
	virtual double cost() override
	{
		return .89;
	}

	virtual ~HouseBlend()
	{
		cout << "하우스 블렌드 소멸" << endl;
	}
};

class DarkRoast : public Beverage
{
public:
	DarkRoast()
	{
		description = "다크 로스트 커피";
	}
	
	virtual double cost() override
	{
		return .89;
	}

	virtual ~DarkRoast()
	{
		cout << "다크로스트 소멸" << endl;
	}

};

class Decaf : public Beverage
{
public:
	Decaf()
	{
		description = "Decaf 커피";
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
		return this->beverage->getDescription() + ", 모카";
	}

	virtual double cost() override
	{
		return beverage->cost() + .20;
	}

	virtual ~Mocha()
	{
		delete beverage;
		cout << "모카 소멸" << endl;
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
		return this->beverage->getDescription() + ", 두유";
	}

	virtual double cost() override
	{
		return beverage->cost() + .20;
	}

	virtual ~Soy()
	{
		delete beverage;
		cout << "두유 소멸" << endl;
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
		return this->beverage->getDescription() + ", 휘핑크림";
	}

	virtual double cost() override
	{
		return beverage->cost() + .20;
	}

	virtual ~Whip()
	{
		delete beverage;
		cout << "휘핑크림 소멸" << endl;
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
