#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
// #include "NovicePlayer.h"
// #include "OrcPlayer.h"
// #include "KnightPlayer.h"
// #include "MagicianPlayer.h"
using namespace std;

class Item {
 public:
  Item(int lev, string nam, string eff, string desc, int wei, char typ, int num)
      : level_required(lev),
        name(nam),
        effects(eff),
        description(desc),
        weight(wei),
        type(typ),
        number(num) {
    //	cout << name << " generated" << endl;
  }
  const int level_required;  // level limit of equip/use this item
  const string name;         // the name of this item
  const string effects;      // a short description of its effect
  const string description;  // a short description of this item
  const int weight;          // the weight of the item
  const char
      type;  // ¡§w¡¨ for weapons, ¡§a¡¨ for armors, ¡§c¡¨ for consumables
  const int number;
};

#endif
