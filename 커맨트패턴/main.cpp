#include <iostream>
using namespace std;

class Command
{
public:
	virtual void execute() = 0;
};

class Light
{
public:
	void On()
	{
		cout << "Á¶¸í ÄÑÁü" << endl;
	}

	void Off()
	{

	}
};

class LightOnCommand : public Command
{
private:
	Light* light = nullptr;

public:
	LightOnCommand(Light * _light)
	{
		light = _light;
	}

	void execute() override
	{
		light->On();
	}
};

class SimpleRemoteControl
{
private:
	Command* slot = nullptr;

public:
	SimpleRemoteControl() { }

	void setCommand(Command* _command)
	{
		slot = _command;
	}

	void buttonWasPressed()
	{
		slot->execute();
	}
};

int main()
{
	SimpleRemoteControl remote;
	Light* light = new Light();
	LightOnCommand lightOn(light);

	remote.setCommand(&lightOn);
	remote.buttonWasPressed();
	return 0;
}