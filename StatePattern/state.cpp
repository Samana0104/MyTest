#include <iostream>
using namespace std;

enum State
{
	STANDING,
	JUMPING,
	DUCKING,
	DIVING
};

class Heroine
{

};

class Input
{
};

class HeroineState
{
public:
	virtual ~HeroineState() {}
	virtual void handleInput(Heroine& heroine, Input input) {}
	virtual void update(Heroine& heroine) {}
};

class DuckingState : public HeroineState
{
public:
	DuckingState() : chargeTime(0) {}

	virtual void handleInput()(Heroine& heroine, Input input)
	{
		if (input == State::RE)
	}

private:
	int chargeTime;
};