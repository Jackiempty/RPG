#ifndef CONITEM_H
#define CONITEM_H
#include "Item.h"
class NovicePlayer;
// #include "NovicePlayer.h"
using namespace std;

class ConsumableItem : public Item {
 public:
  ConsumableItem(int lev, string nam, string eff, string desc, int wei,
                 char typ, int num)
      : Item(lev, nam, eff, desc, wei, typ, num) {}
  virtual void use(NovicePlayer*) {
    cout << "use consumable item" << endl;
    //		usleep(500000);
    return;
  }
};

#endif
