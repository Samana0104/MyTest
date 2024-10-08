#include <iostream>
using namespace std;

class FlyBehavior
{
protected:
	FlyBehavior() { }
public:
	virtual void Fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
	virtual void Fly() override
	{
		cout << "����" << endl;
	}
};

class FlyNoWay : public FlyBehavior
{
public:
	virtual void Fly() override
	{
		cout << "������" << endl;
	}
};

class QuackBehavior 
{
protected:
	QuackBehavior() { }
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
	virtual void quack() override
	{
		cout << "��" << endl;
	}
};

class MuteQuack : public QuackBehavior
{
public:
	virtual void quack() override
	{
		cout << "<< ���� >>" << endl;
	}
};

class Squeak : public QuackBehavior
{
public:
	virtual void quack() override
	{
		cout << "��" << endl;
	}
};

class Duck
{
protected:
	FlyBehavior* flyBehavior;
	QuackBehavior * quackBehavior;
	
	Duck(FlyBehavior * _flyBehavior, QuackBehavior * _quackBehavior) : 
		flyBehavior(_flyBehavior), quackBehavior(_quackBehavior)
	{ }
public:
	virtual void display() const = 0;

	void performFly()
	{
		this->flyBehavior->Fly();
	}

	void performQuack()
	{
		this->quackBehavior->quack();
	}
};

class MyDuck : public Duck
{
public:
	explicit MyDuck() : Duck(new FlyWithWings(), new Quack())
	{
	}

	virtual void display() const
	{
		cout << "������" << endl;
	}
};
int main()
{
	MyDuck A;
	Duck& ref = A;
	
	ref.display();
	ref.performFly();
	ref.performQuack();
	return 0;
}