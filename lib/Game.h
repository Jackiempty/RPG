#ifndef GAME_H
#define GAME_H
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Battle.h"
#include "field.h"
// #include "Menu.h"
#include "GoblinMonster.h"
#include "HealerPlayer.h"
#include "JWMonster.h"
#include "KnightPlayer.h"
#include "ZombieMonster.h"
// #include "SwordWeapon.h"
// #include "AxeWeapon.h"
// #include "TunicArmor.h"
// #include "ShieldArmor.h"
// #include "LifePotion.h"
// #include "MagicPotion.h"
using namespace std;

class Game {
 public:
  vector<NovicePlayer*> PlayerList;
  vector<Field*> Maps;
  Field* CurrentMap;
  int stage;
  bool main;
  bool quit;
  //	Menu* menu;
  //	vector <Item*> Backpack;
  //	vector<vector<Item*>> Backpacks;
  //	vector<vector<Item*>> Boxes;
  Game();
  void Run();
  // game functions
  bool Trigger();
  void teleport();
  void viewbackpack();  // 'Z' to switch backpack
  void openbox();
  void PrintMap();  // 'M' to open the current map
  void Shop();
  void resetmap();
  // menu series functions
  void Menu(bool&);
  void SwitchPlayer();
  void Save();
  void Read();
  void Main(bool&, bool&);
  // event series functions
  void story();
};

#endif
