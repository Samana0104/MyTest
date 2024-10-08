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
		cout << "준비중 : " << name << endl;
		cout << "도우를 돌리는 중..." << endl;
		cout << "소스를 뿌리는 중..." << endl;
		cout << "토핑을 올리는 중: " << endl;

		for (auto& str : toppings)
			cout << " " << str << endl;
	}


	virtual void bake()
	{
		cout << "175도에서 25분 간 굽기" << endl;
	}

	virtual void cut()
	{
		cout << "피자를 사선으로 자르기" << endl;
	}

	virtual void box()
	{
		cout << "상자에 피자 담기" << endl;
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
		name = "뉴욕 스ㅡ타일 소스와 치즈 피자";
		dough = "신 크러스트 도우";
		sauce = "마리나라 소스";

		toppings.emplace_back("잘게 썬 레지아노 치즈");
	}
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
	ChicagoStyleCheesePizza()
	{
		name = "시카고 스타일 딥 디쉬 치즈 피자";
		dough = "아주 두꺼운 크러스트 도우";
		sauce = "플럼토마토 소스";

		toppings.emplace_back("잘게 조각낸 모짜렐라 치즈");
	}

	void cut()
	{
		cout << "네모난 모양으로 피자 자르기" << endl;
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
	cout << "에단이 주문한 " << pizza->getName() << endl;

	cout << endl<<"----------------------------" << endl;

	pizza = chicagoStore->orderPizza("cheese");
	cout << "조엘이 주문한 " << pizza->getName() << endl;

	delete nyStore;
	delete chicagoStore;
	return 0;
}