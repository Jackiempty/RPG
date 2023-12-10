#ifndef SHIELD_H
#define SHIELD_H
#include "ArmorItem.h"
using namespace std;

class ShieldArmor : public ArmorItem
{
public:
	ShieldArmor()
		:ArmorItem(1, "(A)TA's cover", "Defense increases by 60", "Level_Limitation: 10", 30, 'a', 60, 4)
	{

	}
};
#endif
