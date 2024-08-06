#include "KnightPlayer.h"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

KnightPlayer::KnightPlayer() : NovicePlayer() {
  attack = 40 + 10 * level;
  defense = 20 + 12 * level;
  max_hp = 150 + 25 * level;
  max_mp = 70 + 10 * level;
  setHP(max_hp);
  setMP(max_mp);
}

KnightPlayer::KnightPlayer(int lev) : NovicePlayer(lev) {
  attack = 40 + 10 * lev;
  defense = 20 + 12 * lev;
  max_hp = 150 + 25 * lev;
  max_mp = 70 + 10 * lev;
  setHP(max_hp);
  setMP(max_mp);
}

KnightPlayer::KnightPlayer(int lev, string nam) : NovicePlayer(lev, nam) {
  attack = 40 + 10 * lev;
  defense = 20 + 12 * lev;
  max_hp = 150 + 25 * lev;
  max_mp = 70 + 10 * lev;
  setHP(max_hp);
  setMP(max_mp);
}

KnightPlayer::KnightPlayer(const KnightPlayer& copy) : NovicePlayer(copy) {
  attack = 40 + 10 * level;
  defense = 20 + 12 * level;
  max_hp = 150 + 25 * level;
  max_mp = 70 + 10 * level;
  setHP(max_hp);
  setMP(max_mp);
}

void KnightPlayer::setLevel(int lev) {
  if (lev <= 0) {
    cout << "Invalid level number, please input a legal level number" << endl
         << "Set level to 1" << endl;
    level = 1;
  } else {
    level = lev;
  }
  attack = 40 + 10 * lev;
  defense = 20 + 12 * lev;
  max_hp = 150 + 25 * lev;
  max_mp = 70 + 10 * lev;
  setExp(ceil(pow(10, log2(level))));
  lvup_exp = ceil(pow(10, log2(level + 1)));
  //	backpack_weight_limit = 35 + 2 * level;
  //	backpack_slot_limit = 10 + level / 4;
  //	Backpack.resize(backpack_slot_limit, nullptr);
  setHP(max_hp);
  setMP(max_mp);
  return;
}

void KnightPlayer::specialSkill()  // heal(): increasing HP (level*10) points by
                                   // decreasing MP (level*5) points
{
  int nowhp = NovicePlayer::getHP();
  int nowmp = NovicePlayer::getMP();
  cout << "Knight's skill activated" << endl;
  if (nowmp - level * 5 < 0) {
    cout << "Not enough MP, skill failed" << endl;
  } else {
    NovicePlayer::setMP(nowmp - level * 5);
    if (nowhp + level * 10 > max_hp) {
      setHP(max_hp);
    } else {
      NovicePlayer::setHP(nowhp + level * 10);
    }
  }
  return;
}

string KnightPlayer::serialize() {
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

NovicePlayer* KnightPlayer::unserialize(string filename) {
  ifstream input(filename, ios::in);
  if (!input) {
    cerr << "File could not be opened" << endl;
    cerr << "008" << endl;
    exit(1);
  }
  vector<string> data(6);
  string buff;
  int j = 0;
  while (!input.eof()) {
    input >> buff;
    istringstream In{buff};
    getline(In.ignore(2, '\n'), data[j], '&');
    j++;
  }
  KnightPlayer* ptr;
  ptr = new KnightPlayer;
  ptr->setLevel(stoi(data[5]));
  ptr->setName(data[0]);
  ptr->setHP(stoi(data[1]));
  ptr->setMP(stoi(data[2]));
  ptr->setExp(stoi(data[3]));
  ptr->setMoney(stoi(data[4]));
  //	cout << "Knight read" << endl;

  return ptr;
}