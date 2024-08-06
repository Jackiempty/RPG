#ifndef ARMITEM_H
#define ARMITEM_H
#include "Item.h"

class ArmorItem : public Item {
 public:
  ArmorItem(int lev, string nam, string eff, string desc, int wei, char typ,
            int def, int num)
      : Item(lev, nam, eff, desc, wei, typ, num), defense_increment(def) {}
  const int defense_increment;  // the number of increment on defense
};

#endif
