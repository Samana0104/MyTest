#include <iostream>
using namespace std;

class Observer
{
private:
public:
	virtual void onNotify(const Entity& entity, Event event) = 0;
	virtual ~Observer();
};

class Achievements : public Observer
{
private:
	void unlock(Achievements achievement)
	{

	}

public:
	virtual void onNotify(const Entity& entity, Event event)
	{
		switch (event)
		{
		case EVENTR_ENTITY_FELL:
			if (entity.isHero() && heroIsOnBridge)
			{
				unlock(ACHIEVEMENT_FELL_OFF_BRIDGE);
			}
			break;
		}
	}
};