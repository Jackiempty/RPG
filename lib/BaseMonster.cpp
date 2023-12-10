#include <iostream>
#include <string>
#include "BaseMonster.h"
using namespace std;

int BaseMonster::count = 0;

int BaseMonster::getInstanceCount()
{
	return count;
}

BaseMonster::BaseMonster(string nam, int atk, int def, int Exp, int Money, int MaxHP, int MaxMP)
	:name(nam), attack(atk), defense(def), exp(Exp), money(Money), max_hp(MaxHP), max_mp(MaxMP)
{
	count++;
	hp = max_hp;
	mp = max_mp;
}

BaseMonster::~BaseMonster()
{
	count--;
}

void BaseMonster::setHP(int HP)
{
	if ((HP > max_hp) || (HP < 0))
	{
		cout << "Invalid HP value, please input a legal number" << endl
			<< "Set HP to MaxHP" << endl;
		hp = max_hp;
	}
	else
	{
		hp = HP;
	}
	return;
}

int BaseMonster::getHP() const
{
	return hp;
}

void BaseMonster::setMP(int MP)
{
	if ((MP > max_hp) || (MP < 0))
	{
		cout << "Invalid MP value, please input a legal number" << endl
			<< "Set MP to MaxMP" << endl;
		mp = max_mp;
	}
	else
	{
		mp = MP;
	}
	return;
}

int BaseMonster::getMP() const
{
	return mp;
}