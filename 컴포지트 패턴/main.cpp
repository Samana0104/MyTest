#include <iostream>
#include <exception>
#include <vector>
#include <string>
using namespace std;

class MenuComponent
{
public:
	virtual void add(MenuComponent& menuComponent)
	{
		throw exception();
	}

	virtual void remove(MenuComponent& menuComponent)
	{
		throw exception();
	}

	virtual MenuComponent& getChild(int i)
	{
		throw exception();
	}
	
	virtual string& getName()
	{
		throw exception();
	}

	virtual string& getDescription()
	{
		throw exception();
	}

	virtual double getPrice()
	{
		throw exception();
	}

	virtual bool isVegetarian()
	{
		throw exception();
	}

	virtual void print()
	{
		throw exception();
	}
};

class MenuItem : public MenuComponent
{
private:
	string name;
	string description;
	bool vegetarian;
	double price;

	MenuItem(string _name, string _description, bool _vegetarian, double _price)
	{
		name = _name;
		description = _description;
		vegetarian = _vegetarian;
		price = _price;
	}
	
	virtual string& getName() override
	{
		return name;
	}

	virtual string& getDescription() override
	{
		return description;
	}

	virtual double getPrice() override
	{
		return price;
	}

	virtual bool isVegetarian() override
	{
		return vegetarian;
	}

	virtual void print()
	{
		cout << " " << getName();

		if (isVegetarian())
		{
			cout << "(v)";
		}

		cout << ", " << getPrice() << endl;
		cout << "		-- " << getDescription() << endl;
	}
};

class Menu : public MenuComponent
{
private:
	vector<MenuComponent> menuComponents;
	string name;
	string description;

public:
	Menu(string _name, string _description)
	{
		name = _name;
		description = _description;
	}

	virtual void add(MenuComponent& _menuComponent) override
	{
		menuComponents.push_back(_menuComponent);
	}

	virtual void remove(MenuComponent& _menuComponent) override
	{
		// 오버로딩 안되어있어서 안될지도?
		menuComponents.erase(find(menuComponents.begin(), menuComponents.end(), _menuComponent));
	}

	virtual MenuComponent& getChild(int i) override
	{
		return menuComponents.at(i);
	}

	virtual string& getName() override
	{
		return name;
	}
	
	virtual string& getDescription() override
	{
		return description;
	}

	virtual void print() override
	{
		cout << "\n" << getName();
		cout << ", " << getDescription() << endl;
		cout << "-------------------------------------------";


		for (MenuComponent& menuComponent : menuComponents)
		{
			menuComponent.print();
		}
	}
};
