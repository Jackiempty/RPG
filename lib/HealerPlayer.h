#ifndef HPLAYER_H
#define HPLAYER_H
#include <iostream>
#include <string>

#include "NovicePlayer.h"
using namespace std;

class HealerPlayer : public NovicePlayer {
 public:
  HealerPlayer();
  HealerPlayer(int);
  HealerPlayer(int, string);
  HealerPlayer(const HealerPlayer&);
  virtual void setLevel(int);
  virtual void specialSkill();
  virtual string serialize();
  static NovicePlayer* unserialize(string);
};

#endif
