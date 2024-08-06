#ifndef JWMONSTER_H
#define JWMONSTER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "BaseMonster.h"
using namespace std;

class JWMonster : public BaseMonster {
 public:
  JWMonster() : BaseMonster("CS:JWMaster", 120, 100, 42, 175, 250, 100) {}

  ~JWMonster() {}
  virtual string serialize() {
    vector<string> data(2);
    // index: [0]:hp, [1]:mp
    data[0] = "@#" + to_string(getHP()) + "&*";
    data[1] = "@#" + to_string(getMP()) + "&*";
    string ToBeReturn = data[0] + data[1];
    return ToBeReturn;
  }
  static BaseMonster* unserialize(string code) {
    istringstream In{code};
    vector<string> data(2);
    getline(In.ignore(2, '\n'), data[0], '&');
    getline(In.ignore(3, '\n'), data[1], '&');
    BaseMonster* ptr;
    ptr = new JWMonster;
    ptr->setHP(stoi(data[0]));
    ptr->setMP(stoi(data[1]));
    return ptr;
  }
};
#endif
