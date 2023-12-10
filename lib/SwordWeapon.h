#ifndef SWORD_H
#define SWORD_H
#include "WeaponItem.h"
using namespace std;

class SwordWeapon : public WeaponItem
{
public:
	SwordWeapon()
		:WeaponItem(0, "(W)stay up late", "Attack increases by 30", "No level limitation", 10, 'w', 30, 1)
	{

	}
};
#endif
