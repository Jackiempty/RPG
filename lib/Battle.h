#ifndef BATTLE_H
#define BATTLE_H

#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
// #include <windows.h>
#include <unistd.h>
// #include <conio.h>
#include <stdio.h>

#include "AxeWeapon.h"
#include "GoblinMonster.h"
#include "HealerPlayer.h"
#include "JWMonster.h"
#include "KnightPlayer.h"
#include "LifePotion.h"
#include "MagicPotion.h"
#include "ShieldArmor.h"
#include "SwordWeapon.h"
#include "TunicArmor.h"
#include "ZombieMonster.h"

using namespace std;

struct Character {
  char type;       // monster or player?
  bool alive;      // alive or dead?
  void *instance;  // pointer to instance
};

class Battle {
 public:
  Battle(int, int);
  bool Fight();
  void include(NovicePlayer *);
  void include(BaseMonster *);

 private:
  void Print();
  void Update();
  vector<Character> ActionList = {};
  int nPlyr;
  int nMon;
};

#endif
