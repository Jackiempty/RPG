#ifndef MAGIC_H
#define MAGIC_H
#include "ConsumableItem.h"
#include "NovicePlayer.h"
using namespace std;

class MagicPotion : public ConsumableItem {
 public:
  MagicPotion()
      : ConsumableItem(1, "(C)late night snack", "MP increases by 50",
                       "Level-Limitation: 5", 5, 'c', 6) {}
  virtual void use(NovicePlayer* plyr) {
    int mpnow = plyr->getMP();
    int mpmax = plyr->getMaxMP();
    if (mpnow + 50 >= mpmax) {
      plyr->setMP(mpmax);
    } else if (mpnow + 50 < mpmax) {
      plyr->setMP(mpnow + 50);
    }
    return;
  }
};
#endif
