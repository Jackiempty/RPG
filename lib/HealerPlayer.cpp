#include "HealerPlayer.h"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

HealerPlayer::HealerPlayer() : NovicePlayer() {
  attack = 30 + 8 * level;
  defense = 20 + 7 * level;
  max_hp = 120 + 15 * level;
  max_mp = 100 + 15 * level;
  setHP(max_hp);
  setMP(max_mp);
}

HealerPlayer::HealerPlayer(int lev) : NovicePlayer(lev) {
  attack = 30 + 8 * lev;
  defense = 20 + 7 * lev;
  max_hp = 120 + 15 * lev;
  max_mp = 100 + 15 * lev;
  setHP(max_hp);
  setMP(max_mp);
}

HealerPlayer::HealerPlayer(int lev, string nam) : NovicePlayer(lev, nam) {
  attack = 30 + 8 * lev;
  defense = 20 + 7 * lev;
  max_hp = 120 + 15 * lev;
  max_mp = 100 + 15 * lev;
  setHP(max_hp);
  setMP(max_mp);
}

HealerPlayer::HealerPlayer(const HealerPlayer& copy) : NovicePlayer(copy) {
  attack = 30 + 8 * level;
  defense = 20 + 7 * level;
  max_hp = 120 + 15 * level;
  max_mp = 100 + 15 * level;
  setHP(max_hp);
  setMP(max_mp);
}

void HealerPlayer::setLevel(int lev) {
  if (lev <= 0) {
    cout << "Invalid level number, please input a legal level number" << endl
         << "Set level to 1" << endl;
    level = 1;
  } else {
    level = lev;
  }
  attack = 30 + 8 * lev;
  defense = 20 + 7 * lev;
  max_hp = 120 + 15 * lev;
  max_mp = 100 + 15 * lev;
  setExp(ceil(pow(10, log2(level))));
  lvup_exp = ceil(pow(10, log2(level + 1)));
  //	backpack_weight_limit = 35 + 2 * level;
  //	backpack_slot_limit = 10 + level / 4;
  //	Backpack.resize(backpack_slot_limit, nullptr);
  setHP(max_hp);
  setMP(max_mp);
  return;
}

void HealerPlayer::specialSkill()  // pray(): increasing MP (level*10) points by
                                   // decreasing HP (level*5) points
{
  int nowmp = NovicePlayer::getMP();
  int nowhp = NovicePlayer::getHP();
  cout << "Magician's skill activated" << endl;
  if (nowhp - level * 5 <= 0) {
    cout << "Not enough HP, skill failed" << endl;
  } else {
    NovicePlayer::setHP(nowhp - level * 5);
    if (nowmp + level * 10 > max_mp) {
      setMP(max_mp);
    } else {
      NovicePlayer::setMP(nowmp + level * 10);
    }
  }
  return;
}

string HealerPlayer::serialize() {
  vector<string> data(6);
  // index-> [0]:name, [1]:hp, [2]:mp, [3]:exp, [4]:money, [5]:level
  data[0] = "@#" + getName() + "&*\n";
  data[1] = "@#" + to_string(getHP()) + "&*\n";
  data[2] = "@#" + to_string(getMP()) + "&*\n";
  data[3] = "@#" + to_string(getExp()) + "&*\n";
  data[4] = "@#" + to_string(getMoney()) + "&*\n";
  data[5] = "@#" + to_string(getLevel()) + "&*";
  string ToBeReturn = data[0] + data[1] + data[2] + data[3] + data[4] + data[5];
  return ToBeReturn;
}

NovicePlayer* HealerPlayer::unserialize(string filename) {
  ifstream input(filename, ios::in);
  if (!input) {
    cerr << "File could not be opened" << endl;
    cerr << "007" << endl;
    exit(1);
  }
  vector<string> data(6);
  string buff;
  int j = 0;
  //	cout << "J should be 0: "<< j << endl;
  while (!input.eof()) {
    input >> buff;
    istringstream In{buff};
    getline(In.ignore(2, '\n'), data[j], '&');
    j++;
    //		cout << "J added: " << j << endl;
  }
  HealerPlayer* ptr;
  ptr = new HealerPlayer;
  ptr->setLevel(stoi(data[5]));
  ptr->setName(data[0]);
  ptr->setHP(stoi(data[1]));
  ptr->setMP(stoi(data[2]));
  ptr->setExp(stoi(data[3]));
  ptr->setMoney(stoi(data[4]));
  return ptr;
}