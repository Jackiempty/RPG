#ifndef NPLAYER_H
#define NPLAYER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
// #include <windows.h>
#include <unistd.h>
// #include <conio.h>
#include <stdio.h>
//#include "Item.h"
//#include "WeaponItem.h"
//#include "ArmorItem.h"
#include "ConsumableItem.h"
#include "SwordWeapon.h"
#include "AxeWeapon.h"
#include "TunicArmor.h"
#include "ShieldArmor.h"
//#include "LifePotion.h"
//#include "MagicPotion.h"
using namespace std;

class NovicePlayer
{
public:
	NovicePlayer(); // default constructor, With level = 1, name = ��anonymous��
	NovicePlayer(int); // normal constructor, Initializes level of the player, name = ��anonymous��
	NovicePlayer(int, string); // normal constructor, Initializes level and name of the player
	NovicePlayer(const NovicePlayer&); // Copy constructor
	// Getter/setters of name, level, hp, mp, exp, money
	void setName(string);
	string getName(void) const;
	virtual void setLevel(int); //  Please note that you should also calculate attack, defense, max_hp, max_mp and lvup_exp while calling setLevel() 
	int getLevel(void) const;
	void setHP(int);
	int getHP(void) const;
	void setMP(int);
	int getMP(void) const;
	void setExp(int);
	int getExp(void) const;
	void setMoney(int); //
	int getMoney(void) const; //
	void refresh_level();
	void refresh_exp();

	int getDefense(void) const;
	int getAttack(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getLvupExp(void) const;
	static int getInstanceCount();

	/*
	hp, mp and exp should not greater than max_hp, max_mp and
	lvup_exp, respectively.
	Please also check other limits on data members and validate values within setters.
	For attack, defense, max_hp, max_mp and lvup_exp :
	Should be calculated automatically while initializing and calling setLevel()
	So no general setters for these members
	You can just ignore the procedures while leveling-up, we will deal
	with it in future classes. Or you can deal with it within setExp() if you want.
	*/
	virtual void specialSkill();
	virtual string serialize();
	static NovicePlayer* unserialize(string);

	// here starts the item series functions
	bool equipWeapon(WeaponItem*); // 'w'
	bool equipArmor(ArmorItem*); // 'e'
	bool useConsumable(ConsumableItem*); // 'q'
	void putItem(Item*); 
	Item* takeItem(int); // 'r'
	vector<Item*> Backpack; // backpack, use a interface to show it
	WeaponItem* Weapon; // Weapon's, Armor's pointer, which all point
	ArmorItem* Armor; // to existing objects
//	int backpack_weight;
//	int backpack_weight_limit;
//	int backpack_slot_limit;
//	void countweight(); // used to refresh the current weight of the backpack
	void Viewbackpack(); // 'E', open backpack and the view it
	bool getmove(char);
	// ---------------------------------------------------

private:
	string name; // Name of the player
	int hp; // Current HP of the player, range: [0, max_hp]
	int mp; // Current MP of the player, range: [0, max_mp]
	int exp; // Cumulative experience of the player, >= 0
	         // Will not reset to zero after leveling-up
	

protected:
	int level; // The level of the player, >= 1
	int attack; // Attack of the player
	int defense; // Defense of the player
	int max_hp; // Max HP of the player
	int max_mp; // Max MP of the player
	int lvup_exp; // Experience needed for leveling-up
	int money; // Current amount of money that player carries, >= 0
	static int count;
};

#endif
