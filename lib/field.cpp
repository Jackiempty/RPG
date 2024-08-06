#include "field.h"

#include <iostream>
#include <string>
using namespace std;

Field::Field(vector<vector<int>> map, int x, int y, int width, int height) {
  map_data = map;
  Height = map.size();
  Width = map[0].size();
  current_position_x = x;
  current_position_y = y;
  vision_width = width;
  vision_height = height;
}

Field::Field(string filename, int x, int y, int width, int height) {
  map_name = filename;
  ifstream input(filename, ios::in);
  if (!input) {
    cerr << "File could not be opened" << endl;
    cerr << "001" << endl;
    exit(1);
  }
  string buff;
  string unit;
  input >> buff;
  istringstream one{buff};
  getline(one, unit, ',');
  Width = stoi(unit);
  getline(one, unit, '\n');
  Height = stoi(unit);
  while (!input.eof()) {
    input >> buff;
    istringstream two{buff};
    vector<int> getWidth = {};
    while (getline(two, unit, ',')) {
      getWidth.push_back(stoi(unit));
    }
    map_data.push_back(getWidth);
  }
  current_position_x = x;
  current_position_y = y;
  vision_width = width;
  vision_height = height;
  //	PrintMap();
}

Field::~Field() {}

bool Field::move(char direction) {
  bool success;
  switch (direction) {
    case ('w'):
      success = moveUp();
      break;
    case ('a'):
      success = moveLeft();
      break;
    case ('s'):
      success = moveDown();
      break;
    case ('d'):
      success = moveRight();
      break;
    default:
      success = false;
      break;
  }
  return success;
}

bool Field::moveUp(void) {
  if (map_data[current_position_y - 1][current_position_x] == 1) {
    return false;
  } else {
    current_position_y--;
    return true;
  }
}

bool Field::moveDown(void) {
  if (map_data[current_position_y + 1][current_position_x] == 1) {
    return false;
  } else {
    current_position_y++;
    return true;
  }
}

bool Field::moveLeft(void) {
  if (map_data[current_position_y][current_position_x - 1] == 1) {
    return false;
  } else {
    current_position_x--;
    return true;
  }
}

bool Field::moveRight(void) {
  if (map_data[current_position_y][current_position_x + 1] == 1) {
    return false;
  } else {
    current_position_x++;
    return true;
  }
}

int Field::getCurrentPositionX(void) const { return current_position_x; }

int Field::getCurrentPositionY(void) const { return current_position_y; }

int Field::getVisionWidth(void) const { return vision_width; }

int Field::getVisionHeight(void) const { return vision_height; }

string Field::getMapName(void) const { return map_name; }

int Field::getMapSymbol(int y, int x) { return map_data[y][x]; }

void Field::setPosition(int y, int x) {
  current_position_x = x;
  current_position_y = y;
  return;
}

void Field::setMapSymbol(int symb, int y, int x) {
  map_data[y][x] = symb;
  return;
}

void Field::setVisionSize(int width, int height) {
  vision_width = width;
  vision_height = height;
  return;
}

void Field::display(void) const {
  cout << endl;
  for (int i = 0; i < vision_height; i++) {
    cout << "  ";
    for (int j = 0; j < vision_width; j++) {
      if (current_position_y - (vision_height / 2) + i < 0 ||
          current_position_y - (vision_height / 2) + i >= Height) {
        cout << "\u001b[30m██\u001b[0m";
      } else {
        if (current_position_x - (vision_width / 2) + j < 0 ||
            current_position_x - (vision_width / 2) + j >= Width) {
          cout << "\u001b[30m██\u001b[0m";
        } else {
          if (current_position_y - (vision_height / 2) + i ==
                  current_position_y &&
              current_position_x - (vision_width / 2) + j ==
                  current_position_x)  // me: green
          {
            cout << "\u001b[32m██\u001b[0m";
          } else {
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                1)  // wall: white
            {
              cout << "\u001b[37m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                0)  // pavement: blue
            {
              cout << "\u001b[34m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                2)  // event: purple
            {
              cout << "\u001b[35m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                5)  // boss: red
            {
              cout << "\u001b[31m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                9)  // teleport: lblue
            {
              cout << "\u001b[36m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                4)  // battle: yellow
            {
              cout << "\u001b[33m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                3)  // box: lyellow
            {
              cout << "\u001b[33;1m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                6)  // shop: lred
            {
              cout << "\u001b[31;1m██\u001b[0m";
            }
            if (map_data[current_position_y - (vision_height / 2) + i]
                        [current_position_x - (vision_width / 2) + j] ==
                7)  // exit: lred
            {
              cout << "\u001b[31;1m██\u001b[0m";
            }
          }
        }
      }
    }
    cout << endl;
  }
  cout << "----------------------------------------------------------------"
       << endl;
  cout << "W:⇧ S:⇩ A:⇦ D:⇨" << endl;
  //	cout << "Map Symbol: " <<
  //map_data[current_position_y][current_position_x] << endl;
  return;
}

void Field::PrintMap() const {
  for (int i = 0; i < Height; i++) {
    for (int j = 0; j < Width; j++) {
      if (map_data[i][j] == 1)  // wall: white
      {
        cout << "\u001b[37m██\u001b[0m";
      }
      if (map_data[i][j] == 0)  // pavement: blue
      {
        cout << "\u001b[34m██\u001b[0m";
      }
      if (map_data[i][j] == 2)  // event: purple
      {
        cout << "\u001b[35m██\u001b[0m";
      }
      if (map_data[i][j] == 4)  // battle: yellow
      {
        cout << "\u001b[33m██\u001b[0m";
      }
      if (map_data[i][j] == 9)  // teleport: lblue
      {
        cout << "\u001b[36m██\u001b[0m";
      }
      if (map_data[i][j] == 5)  // boss: red
      {
        cout << "\u001b[31m██\u001b[0m";
      }
      if (map_data[i][j] == 3)  // box: lyellow
      {
        cout << "\u001b[33;1m██\u001b[0m";
      }
      if (map_data[i][j] == 6)  // shop: lred
      {
        cout << "\u001b[31;1m██\u001b[0m";
      }
      if (map_data[i][j] == 7)  // exit: lred
      {
        cout << "\u001b[31;1m██\u001b[0m";
      }
    }
    cout << endl;
  }
}

void Field::Savemap() {
  ofstream output(map_name, ios::in);
  if (!output) {
    cerr << "File could not be opened" << endl;
    cerr << "002" << endl;
    exit(1);
  }
  output << Width << "," << Height << endl;
  for (int i = 0; i < map_data.size(); i++) {
    for (int j = 0; j < map_data[i].size(); j++) {
      output << map_data[i][j] << ",";
    }
    output << endl;
  }
}

void Field::setmapname(string name) {
  map_name = name;
  return;
}

/*
bool Field::Trigger(NovicePlayer* plyr)
{
        if (map_data[current_position_y][current_position_x] == 2) // event
        {
                system("clear");
                cout << "Level UP !!!" << endl;
                sleep(1);
                cout << "Your level is 100" << endl;
                sleep(1);
                system("clear");
                cout << "You have aquired a sword, a tunic and a lifepotion" <<
endl; Item* weapon1= new SwordWeapon; Item* armor1 = new TunicArmor; Item*
potion1 = new LifePotion; plyr->putItem(weapon1); plyr->putItem(armor1);
                plyr->putItem(potion1);
                plyr->setLevel(100);
                getchar(); // replacement for system("pause")
                return true;
        }
        else if (map_data[current_position_y][current_position_x] == 4) //
battle
        {
                Battle battle(1, 3);
                ZombieMonster monster1;
                GoblinMonster monster2, monster3;
                battle.include(plyr);
                battle.include(&monster1);
                battle.include(&monster2);
                battle.include(&monster3);
                return battle.Fight();
        }
        else if (map_data[current_position_y][current_position_x] == 5) // boss
        {
                Battle battle(1, 1);
                JWMonster monster;
                battle.include(&monster);
                battle.include(plyr);
                return battle.Fight();
        }
        else if (map_data[current_position_y][current_position_x] == 9) //
teleport
        {

        }
        else
        {
                return false;
        }
}
*/

/*
void Field::Story()
{
        system("clear");
        cout << "This is a short demo storyline of JW's CS lesson, HW10\n";
        sleep(10);
        system("clear");
        cout << "In this storyline, you will experience an event and a fight\n";
        sleep(5);
        system("clear");
        cout << "now";
        sleep(2);
        cout << ", let's begin !!!\n";
        sleep(5);
        system("clear");
        return;
}
*/
