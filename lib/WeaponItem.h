#ifndef WEAPITEM_H
#define WEAPITEM_H
#include "Item.h"
using namespace std;

class WeaponItem : public Item
{
public:
	WeaponItem(int lev, string nam, string eff, string desc, int wei, char typ, int att, int num)
		:Item(lev, nam, eff, desc, wei, typ, num), attack_increment(att)
	{

	}
	const int attack_increment; //the number of increment on attack
};

#endif