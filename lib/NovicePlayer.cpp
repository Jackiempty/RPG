#include "NovicePlayer.h"
using namespace std;

int NovicePlayer::count = 0;

NovicePlayer::NovicePlayer()
{
	count++;
	level = 1;
	name = "anonymous";
	attack = 20 + 5 * level;
	defense = 20 + 5 * level;
	max_hp = 100 + 10 * level;
	max_mp = 40 + 5 * level;
	exp = 0;
	money = 0;
	hp = max_hp;
	mp = max_mp;
//	backpack_weight_limit = 35 + 2 * level;
//	backpack_slot_limit = 10 + level / 4;
	lvup_exp = ceil(pow(10, log2(level + 1)));
//	Backpack = vector<Item*>(backpack_slot_limit);
	for (int i = 0; i < Backpack.size(); i++) 
	{ Backpack[i] = nullptr; }
	Weapon = nullptr;
	Armor = nullptr;
//	backpack_weight = 0;
}

NovicePlayer::NovicePlayer(int lev)
{
	count++;
	if (lev <= 0)
	{
		cout << "Invalid level number, please input a legal level number" << endl
			<< "Set level to 1" << endl;
		level = 1;
	}
	else
	{
		level = lev;
	}
	name = "anonymous";
	attack = 20 + 5 * level;
	defense = 20 + 5 * level;
	max_hp = 100 + 10 * level;
	max_mp = 40 + 5 * level;
	exp = ceil(pow(10, log2(level)));
	money = 0;
	hp = max_hp;
	mp = max_mp;
//	backpack_weight_limit = 35 + 2 * level;
//	backpack_slot_limit = 10 + level / 4;
	lvup_exp = ceil(pow(10, log2(level + 1)));
//	Backpack = vector<Item*>(backpack_slot_limit);
	for (int i = 0; i < Backpack.size(); i++)
	{
		Backpack[i] = nullptr;
	}
	Weapon = nullptr;
	Armor = nullptr;
//	backpack_weight = 0;
}

NovicePlayer::NovicePlayer(int lev, string nam)
{
	count++;
	if (lev <= 0)
	{
		cout << "Invalid level number, please input a legal level number" << endl
			<< "Set level to 1" << endl;
		level = 1;
	}
	else
	{
		level = lev;
	}
	name = nam;
	attack = 20 + 5 * level;
	defense = 20 + 5 * level;
	max_hp = 100 + 10 * level;
	max_mp = 40 + 5 * level;
	exp = ceil(pow(10, log2(level)));;
	money = 0;
	hp = max_hp;
	mp = max_mp;
//	backpack_weight_limit = 35 + 2 * level;
//	backpack_slot_limit = 10 + level / 4;
	lvup_exp = ceil(pow(10, log2(level + 1)));
//	Backpack = vector<Item*>(backpack_slot_limit);
	for (int i = 0; i < Backpack.size(); i++)
	{
		Backpack[i] = nullptr;
	}
	Weapon = nullptr;
	Armor = nullptr;
//	backpack_weight = 0;
}

NovicePlayer::NovicePlayer(const NovicePlayer& copy)
{
	count++;
	level = copy.getLevel();
	name = copy.getName();
	hp = copy.getHP();
	mp = copy.getMP();
	exp = copy.getExp();
	money = copy.getMoney();
	attack = copy.getAttack();
	defense = copy.getDefense();
	max_hp = copy.getMaxHP();
	max_mp = copy.getMaxMP();
	lvup_exp = copy.getLvupExp();
//	backpack_weight_limit = 35 + 2 * level;
//	backpack_slot_limit = 10 + level/4;
//	Backpack = vector<Item*>(copy.backpack_slot_limit);
	for (int i = 0; i < Backpack.size(); i++)
	{
		Backpack[i] = copy.Backpack[i];
	}
	Weapon = copy.Weapon;
	Armor = copy.Armor;
//	backpack_weight = copy.backpack_weight;
}

void NovicePlayer::setName(string nam)
{
	name = nam;
	return;
}

string NovicePlayer::getName(void)const
{
	return name;
}

void NovicePlayer::setLevel(int lev)
{
	if (lev <= 0)
	{
		cout << "Invalid level number, please input a legal level number" << endl
			<< "Set level to 1" << endl;
		level = 1;
	}
	else
	{
		level = lev;
	}
	attack = 20 + 5 * level;
	defense = 20 + 5 * level;
	max_hp = 100 + 10 * level;
	max_mp = 40 + 5 * level;
	lvup_exp = ceil(pow(10, log2(level + 1)));
//	backpack_weight_limit = 35 + 2 * level;
//	backpack_slot_limit = 10 + level / 4;
//	Backpack.resize(backpack_slot_limit, nullptr);
	hp = max_hp;
	mp = max_mp;
	return;
}

int NovicePlayer::getLevel(void) const
{
	return level;
}

void NovicePlayer::setHP(int HP)
{
	if ((HP > max_hp) || (HP < 0))
	{
		cout << "Invalid HP value, please input a legal number" << endl
			 << "Set HP to MaxHP" << endl;
		hp = max_hp;
	}
	else
	{
		hp = HP;
	}
	return;
}

int NovicePlayer::getHP(void) const
{
	return hp;
}

void NovicePlayer::setMP(int MP)
{
	if ((MP > max_hp) || (MP < 0))
	{
		cout << "Invalid MP value, please input a legal number" << endl
			 << "Set MP to MaxMP" << endl;
		mp = max_mp;
	}
	else
	{
		mp = MP;
	}
	return;
}

int NovicePlayer::getMP(void) const
{
	return mp;
}

void NovicePlayer::setExp(int Exp)
{
	if (Exp < 0)
	{
		cout << "Invalid exp number, please input a legal number" << endl
			<< "Set exp to 0" << endl;
		exp = 0;
	}
	else
	{
		exp = Exp;
//		int i = 1;
		/*
		while(true)
		{
			if (Exp >= ceil(pow(10, log2(i + 1))))
			{
				setLevel(i);
				i++;
			}
			else
			{
				break;
			}
		}
		*/
	}
	return;
}

int NovicePlayer::getExp(void) const
{
	return exp;
}

void NovicePlayer::setMoney(int Money)
{
	if (Money < 0)
	{
		cout << "Invalid money value, please input a legal number" << endl
			<< "Set money to 0" << endl;
		money = 0;
	}
	else
	{
		money = Money;
	}
	return;
}

int NovicePlayer::getMoney(void) const
{
	return money;
}

int NovicePlayer::getAttack(void) const
{
	return attack;
}

int NovicePlayer::getDefense(void) const
{
	return defense;
}

int NovicePlayer::getMaxHP(void) const
{
	return max_hp;
}

int NovicePlayer::getMaxMP(void) const
{
	return max_mp;
}

int NovicePlayer::getLvupExp(void) const
{
	return lvup_exp;
}

void NovicePlayer::specialSkill()
{
	// do nothing
	cout << "\"Do Nothing\" skill activated" << endl;
//	sleep(1);
}

string NovicePlayer::serialize()
{
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

NovicePlayer* NovicePlayer::unserialize(string filename)
{
	ifstream input(filename, ios::in);
	if (!input)
	{
		cerr << "File could not be opened" << endl;
		cerr << "009" << endl;
		exit(1);
	}
	vector<string> data(6);
	string buff;
	int j = 0;
	while (!input.eof())
	{
		input >> buff;
		istringstream In{ buff };
		getline(In.ignore(2, '\n'), data[j], '&');
		j++;
	}
	NovicePlayer *ptr;
	ptr = new NovicePlayer;
	ptr->setLevel(stoi(data[5]));
	ptr->setName(data[0]);
	ptr->setHP(stoi(data[1]));
	ptr->setMP(stoi(data[2]));
	ptr->setExp(stoi(data[3]));
	ptr->setMoney(stoi(data[4]));

	return ptr;
}

int NovicePlayer::getInstanceCount()
{
	return count;
}

bool NovicePlayer::equipWeapon(WeaponItem* weapon)
{
	int requirelevel = weapon->level_required;
	if (level >= requirelevel)
	{
		if (Weapon != nullptr)
		{
			putItem(static_cast<Item*>(Weapon));
		}
		Weapon = weapon;
		cout << weapon->name << " equiped-" << endl;
		sleep(1);
//		weapon = nullptr;
//		countweight();
		return true;
	}
	else
	{
		cout << "*You haven't reach the level to use this item*" << endl;
		usleep(500000);
		return false;
	}
}

bool NovicePlayer::equipArmor(ArmorItem* armor)
{
	int requirelevel = armor->level_required;
	if (level >= requirelevel)
	{
		if (Armor != nullptr)
		{
			putItem(static_cast<Item*>(Armor));
		}
		Armor = armor;
		cout << armor->name << " equiped-" << endl;
//		armor = nullptr;
//		countweight();
		return true;
	}
	else
	{
		cout << "*You haven't reach the level to use this item*" << endl;
		usleep(500000);
		return false;
	}
}

bool NovicePlayer::useConsumable(ConsumableItem* conitem)
{
	int requirelevel = conitem->level_required;
	if (level >= requirelevel)
	{
		conitem->use(this);
		cout << conitem->name << " used" << endl;
		for (int i = 0; i < Backpack.size(); i++)
		{
			if (Backpack[i] == conitem)
			{
				Backpack[i] = nullptr;
			}
		}
//		system("pause");
//		countweight();
		usleep(500000);
		return true;
	}
	else
	{
		cout << "*You haven't reach the level to use this item*" << endl;
		usleep(500000);
		return false;
	}
}

void NovicePlayer::putItem(Item* item)
{	
	bool done = false;
	for (int i = 0; i < Backpack.size(); i++)
	{
		if (Backpack[i] == nullptr)
		{				
		Backpack[i] = item;
		done = true;
		break;
		}
	}	
	if (done == false)
	{
		Backpack.push_back(item);
	}	
	cout << item->name << " is put into " << name << "'s backpack" << endl;
	sleep(1);
//	int itemweight = item->weight;
	/*
	if (backpack_weight + itemweight <= backpack_weight_limit)
	{
		for (int i = 0; i < Backpack.size(); i++)
		{
			if (Backpack[i] == nullptr)
			{
				Backpack[i] = item;
				countweight();
				return true;
				break;
			}
		}
		cout << "*Your backpack is full, please try again when it has space*" << endl;
		return false;
	}
	else
	{
		cout << "*Your backpack is too heavy, you can't put this item into the backpack*" << endl;
		usleep(500000);
		return false;
	}
	*/
}

Item* NovicePlayer::takeItem(int index)
{
	Item* theitem = Backpack[index];
	cout << Backpack[index]->name << " is taken from " << name << "'s backpack" << endl;
	sleep(1);
	Backpack[index] = nullptr;
//	countweight();
	return theitem;
}

void NovicePlayer::refresh_level()
{
	int i = 1;
	while (true)
	{
		if (exp >= ceil(pow(10, log2(i))))
		{
			i++;
		}
		else
		{
			setLevel(i - 1);
			break;
		}
	}
}

void NovicePlayer::refresh_exp()
{
	exp = ceil(pow(10, log2(level)));
	return;
}

void NovicePlayer::Viewbackpack()
{
	system("clear");
	cout << name << "'s backpack:  (press Z to switch)" << endl;
	cout << "Level: " << level << endl;
	cout << "Money: " << money << endl;
//	cout << "Current backpack weight: " << backpack_weight << "/" << backpack_weight_limit << endl;
	if (Weapon == nullptr)
	{
		cout << "Total Attack: " << attack << endl;
	}
	else
	{
		cout << "Total Attack: " << attack + Weapon->attack_increment << endl;
	}
	if (Armor == nullptr)
	{
		cout << "Total Defence: " << defense << endl;
	}
	else
	{
		cout << "Total Defence: " << defense + Armor->defense_increment << endl;
	}	
	cout << "HP: " << hp << "/" << max_hp << endl;
	cout << "MP: " << mp << "/" << max_mp << endl;
	cout << "----EQUIPMENTs----" << endl;
	cout << "Weapon: ";
	if (Weapon == nullptr)
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << Weapon->name << "(+" << Weapon->attack_increment << ")" << endl;
	}
	cout << "Armor: ";
	if (Armor == nullptr)
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << Armor->name << "(+" << Armor->defense_increment << ")" << endl;
	}
	cout << "----BACKPACK----" << endl;
	for (int i = 0; i < Backpack.size(); i++)
	{
		if (Backpack[i] != nullptr)
		{
			cout << setw(3) << i + 1 << ": " << Backpack[i]->name << endl;
		}
		else
		{
			cout << setw(3) << i + 1 << ": " << "empty" << endl;
		}
	}		
	return;
}

bool NovicePlayer::getmove(char move)
{
	bool success = false;
	int index;
	ConsumableItem* tempitem = nullptr;
	WeaponItem* tempweapon = nullptr;
	ArmorItem* temparmor = nullptr;
	switch (move)
	{
	case('q'):
		cout << endl;
		cout << "What item do you want to consume?" << endl;
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Please input a number" << endl;
			sleep(1);
			break;
		}
		else if (index > Backpack.size())
		{
			cout << "The backpack slot does not exist" << endl;
			cin.ignore();
			sleep(1);
			break;
		}
		index--;
		if (Backpack[index] == nullptr)
		{
			cout << "This slot is empty" << endl;
			sleep(1);
		}
		else if (Backpack[index]->type == 'c')
		{
//			cout << "Item pointer location: " << Backpack[index] << endl;
//			system("pause");
			tempitem = static_cast<ConsumableItem*>(Backpack[index]);			
			if (useConsumable(tempitem))
			{
				Backpack[index] = nullptr;
			}
		}
		else
		{
			cout << "This is not a consumable item" << endl;
			sleep(1);
		}
		break;
	case('w'):
		cout << endl;
		cout << "What weapon do you want to equip?" << endl;
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Please input a number" << endl;
			sleep(1);
			break;
		}
		else if (index > Backpack.size())
		{
			cout << "The backpack slot does not exist" << endl;
			cin.ignore();
			sleep(1);
			break;
		}
		index--;
		if (Backpack[index] == nullptr)
		{
			cout << "This slot is empty" << endl;
			sleep(1);
		}
		else if (Backpack[index]->type == 'w')
		{
			tempweapon = static_cast<WeaponItem*>(Backpack[index]);		
			if (equipWeapon(tempweapon))
			{
				Backpack[index] = nullptr;
			}
		}
		else
		{
			cout << "This is not a weapon" << endl;
			sleep(1);
		}
		break;
	case('e'):
		cout << endl;
		cout << "What armor do you want to equip?" << endl;
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Please input a number" << endl;
			sleep(1);
			break;
		}
		else if (index > Backpack.size())
		{
			cout << "The backpack slot does not exist" << endl;
			cin.ignore();
			sleep(1);
			break;
		}
		index--;
		if (Backpack[index] == nullptr)
		{
			cout << "This slot is empty" << endl;
			sleep(1);
		}
		else if (Backpack[index]->type == 'a')
		{
			temparmor = static_cast<ArmorItem*>(Backpack[index]);			
			if (equipArmor(temparmor))
			{
				Backpack[index] = nullptr;
			}
		}
		else
		{
			cout << "This is not a weapon" << endl;
			sleep(1);
		}
		break;
	default:
		break;
	}
	return success;
}

/*
void NovicePlayer::countweight()
{
	backpack_weight = 0;
	for (int i = 0; i < Backpack.size(); i++)
	{
		if (Backpack[i] != nullptr)
		{
			backpack_weight = backpack_weight + Backpack[i]->weight;
		}
	}
	return;
}
*/