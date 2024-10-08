#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <memory>
using namespace std;

class Pizza
{
protected:
	string name;
	string dough;
	string sauce;
	vector<string> toppings;

public:
	void prepare()
	{
		cout << "�غ��� : " << name << endl;
		cout << "���츦 ������ ��..." << endl;
		cout << "�ҽ��� �Ѹ��� ��..." << endl;
		cout << "������ �ø��� ��: " << endl;

		for (auto& str : toppings)
			cout << " " << str << endl;
	}


	virtual void bake()
	{
		cout << "175������ 25�� �� ����" << endl;
	}

	virtual void cut()
	{
		cout << "���ڸ� �缱���� �ڸ���" << endl;
	}

	virtual void box()
	{
		cout << "���ڿ� ���� ���" << endl;
	}

	string getName()
	{
		return name;
	}
};

class NYStyleCheesePizza : public Pizza
{
public:
	NYStyleCheesePizza()
	{
		name = "���� ����Ÿ�� �ҽ��� ġ�� ����";
		dough = "�� ũ����Ʈ ����";
		sauce = "�������� �ҽ�";

		toppings.emplace_back("�߰� �� �����Ƴ� ġ��");
	}
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
	ChicagoStyleCheesePizza()
	{
		name = "��ī�� ��Ÿ�� �� �� ġ�� ����";
		dough = "���� �β��� ũ����Ʈ ����";
		sauce = "�÷��丶�� �ҽ�";

		toppings.emplace_back("�߰� ������ ��¥���� ġ��");
	}

	void cut()
	{
		cout << "�׸� ������� ���� �ڸ���" << endl;
	}
};

class PizzaStore
{
protected:
	virtual std::shared_ptr<Pizza> createPizza(string type) = 0;

public:
	std::shared_ptr<Pizza> orderPizza(string type)
	{
		std::shared_ptr<Pizza> pizza;
		pizza = createPizza(type);

		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

};

class NYStylePizzaStore : public PizzaStore
{
public:
	virtual std::shared_ptr<Pizza> createPizza(string type) override
	{
		std::shared_ptr<Pizza> pizza;
		if (type.compare("cheese") == 0)
			pizza = std::make_shared<NYStyleCheesePizza>();
		
		return pizza;
	}
};

class ChicagoStylePizzaStore : public PizzaStore
{
public:
	virtual std::shared_ptr<Pizza> createPizza(string type) override
	{
		std::shared_ptr<Pizza> pizza;
		if (type.compare("cheese") == 0)
			pizza = std::make_shared<ChicagoStyleCheesePizza>();
		
		return pizza;
	}
};

int main()
{
	PizzaStore* nyStore = new NYStylePizzaStore();
	PizzaStore* chicagoStore = new ChicagoStylePizzaStore();

	auto pizza = nyStore->orderPizza("cheese");
	cout << "������ �ֹ��� " << pizza->getName() << endl;

	cout << endl<<"----------------------------" << endl;

	pizza = chicagoStore->orderPizza("cheese");
	cout << "������ �ֹ��� " << pizza->getName() << endl;

	delete nyStore;
	delete chicagoStore;
	return 0;
}