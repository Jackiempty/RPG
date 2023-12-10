#ifndef AXE_H
#define AXE_H
#include "WeaponItem.h"
using namespace std;

class AxeWeapon : public WeaponItem
{
public:
	AxeWeapon()
		:WeaponItem(1, "(W)previous exam", "Attack increases by 70", "Level-Limitation: 10", 20, 'w', 70, 2)
	{

	}
};
#endif
