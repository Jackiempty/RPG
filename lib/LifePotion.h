#ifndef LIFE_H
#define LIFE_H
#include "ConsumableItem.h"
#include "NovicePlayer.h"
using namespace std;

class LifePotion : public ConsumableItem
{
public:
	LifePotion()
		:ConsumableItem(0, "(C)red bull", "HP increases by 50", "No level limitation", 3, 'c', 5)
	{

	}
	virtual void use(NovicePlayer* plyr)
	{
		int hpnow = plyr->getHP();
		int hpmax = plyr->getMaxHP();
		if (hpnow + 50 >= hpmax)
		{
			plyr->setHP(hpmax);
		}
		else if (hpnow + 50 < hpmax)
		{
			plyr->setHP(hpnow + 50);
		}
		return;
	}
};
#endif
