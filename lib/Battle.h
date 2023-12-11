#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
// #include <windows.h>
#include <unistd.h>
// #include <conio.h>
#include <stdio.h>
#include "KnightPlayer.h"
#include "HealerPlayer.h"
#include "GoblinMonster.h"
#include "ZombieMonster.h"
#include "JWMonster.h"
#include "SwordWeapon.h"
#include "AxeWeapon.h"
#include "TunicArmor.h"
#include "ShieldArmor.h"
#include "LifePotion.h"
#include "MagicPotion.h"

using namespace std;

struct Character {
	char type; // monster or player?
	bool alive; // alive or dead?
	void *instance; // pointer to instance
};

class Battle
{
public:
	Battle(int, int);
	bool Fight();
	void include(NovicePlayer*);
	void include(BaseMonster*);
private:
	void Print();
	void Update();
	vector<Character> ActionList = {};
	int nPlyr;
	int nMon;
};

#endif

