#ifndef TUNIC_H
#define TUNIC_H
#include "ArmorItem.h"
using namespace std;

class TunicArmor : public ArmorItem
{
public:
	TunicArmor()
		:ArmorItem(0, "(A)Professor's favorite", "defense increases by 30", "No level limitation", 15, 'a', 30, 3)
	{

	}
};
#endif
