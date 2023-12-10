#include <iostream>
#include <string>
#include "Battle.h"
using namespace std;

Battle::Battle(int nP, int nM)
{
	nPlyr = nP;
	nMon = nM;
}

void Battle::Print()
{
	NovicePlayer *tmp_player;
	BaseMonster *tmp_monster;
	vector <NovicePlayer*> PlayerList = {};
	vector <BaseMonster*>MonsterList = {};
	// divide type
	for (int i = 0; i < ActionList.size(); i++)
	{
		if (ActionList[i].type == 'p')
		{
			PlayerList.push_back(static_cast<NovicePlayer*>(ActionList[i].instance));						
		}
		else if (ActionList[i].type == 'm')
		{
			MonsterList.push_back(static_cast<BaseMonster*>(ActionList[i].instance));		
		}	
	}
	// players' names, hp, mp
	
	for (int i = 0; i < PlayerList.size(); i++)
	{
		tmp_player = PlayerList[i];				
		string pname = tmp_player->getName();					
		cout << "\u001b[33m";
		cout << setw(26) << left << pname;
		cout << "\u001b[0m";
	}
	cout << endl;
	usleep(500000);
	for (int i = 0; i < PlayerList.size(); i++)
	{
		tmp_player = PlayerList[i];
		int totalhp = tmp_player->getMaxHP();
		int nowhp = tmp_player->getHP();
		int unit = (totalhp / 10);
		cout << "HP(" << setw(3) << nowhp << "/" << setw(3) << totalhp << ")               ";
	}
	cout << endl;
//	sleep(1);
	for (int i = 0; i < PlayerList.size(); i++)
	{
		tmp_player = PlayerList[i];
		int totalhp = tmp_player->getMaxHP();
		int nowhp = tmp_player->getHP();
		int unit = (totalhp / 10);
		for (int i = 0; i <= 9; i++) // print hp
		{
			if (nowhp > unit*i)
			{
				cout << "\u001b[31m��\u001b[0m";
			}
			else
			{
				cout << "\u001b[37m��\u001b[0m";
			}
		}
		cout << "      ";
	}
	usleep(500000);
	cout << endl;
	for (int i = 0; i < PlayerList.size(); i++)
	{
		tmp_player = PlayerList[i];
		int totalmp = tmp_player->getMaxMP();
		int nowmp = tmp_player->getMP();
		int unit = (totalmp / 10);
		cout << "MP(" << setw(3) << nowmp << "/" << setw(3) << totalmp << ")               ";
	}
//	sleep(1);
	cout << endl;
	for (int i = 0; i < PlayerList.size(); i++)
	{
		tmp_player = PlayerList[i];
		int totalmp = tmp_player->getMaxMP();
		int nowmp = tmp_player->getMP();
		int unit = (totalmp / 10);
		for (int i = 0; i <= 9; i++) // print mp
		{
			if (nowmp > unit*i)
			{
				cout << "\u001b[34m��\u001b[0m";
			}
			else
			{
				cout << "\u001b[37m��\u001b[0m";
			}
		}
		cout << "      ";
	}
	cout << endl;
	cout << "---------------------------------------------------------------------";
	cout << endl;
	usleep(500000);
	// monsters' names, hp, mp
	for (int i = 0; i < MonsterList.size(); i++)
	{
		tmp_monster = MonsterList[i];				
		string mname = tmp_monster->name;	
		cout << "\u001b[32m";
		cout << setw(26) << left << mname;
		cout << "\u001b[0m";
	}
	cout << endl;
	usleep(500000);
	for (int i = 0; i < MonsterList.size(); i++)
	{
		tmp_monster = MonsterList[i];
		int totalhp = tmp_monster->max_hp;
		int nowhp = tmp_monster->getHP();
		int unit = (totalhp / 10);
		cout << "HP(" << setw(3) << nowhp << "/" << setw(3) << totalhp << ")               ";
	}
	cout << endl;
//	sleep(1);
	for (int i = 0; i < MonsterList.size(); i++)
	{
		tmp_monster = MonsterList[i];
		int totalhp = tmp_monster->max_hp;
		int nowhp = tmp_monster->getHP();
		int unit = (totalhp / 10);
		for (int i = 0; i <= 9; i++) // print hp
		{
			if (nowhp > unit*i)
			{
				cout << "\u001b[31m��\u001b[0m";
			}
			else
			{
				cout << "\u001b[37m��\u001b[0m";
			}
		}
		cout << "      ";
	}
	usleep(500000);
	cout << endl;
	for (int i = 0; i < MonsterList.size(); i++)
	{
		tmp_monster = MonsterList[i];
		int totalmp = tmp_monster->max_mp;
		int nowmp = tmp_monster->getMP();
		int unit = (totalmp / 10);
		cout << "MP(" << setw(3) << nowmp << "/" << setw(3) << totalmp << ")               ";
	}
//	sleep(1);
	cout << endl;
	for (int i = 0; i < MonsterList.size(); i++)
	{
		tmp_monster = MonsterList[i];
		int totalmp = tmp_monster->max_mp;
		int nowmp = tmp_monster->getMP();
		int unit = (totalmp / 10);
		for (int i = 0; i <= 9; i++) // print mp
		{
			if (nowmp > unit*i)
			{
				cout << "\u001b[34m��\u001b[0m";
			}
			else
			{
				cout << "\u001b[37m��\u001b[0m";
			}
		}
		cout << "      ";
	}
	usleep(500000);
	cout << endl;
}

bool Battle::Fight()
{
	vector<Character*>AttackOrder = {};
	NovicePlayer *tmp_player;
	BaseMonster *tmp_monster;
	vector <NovicePlayer*> PlayerList = {};
	vector <BaseMonster*>MonsterList = {};
	// divide type
	for (int i = 0; i < ActionList.size(); i++)
	{
		if (ActionList[i].type == 'p')
		{
			PlayerList.push_back(static_cast<NovicePlayer*>(ActionList[i].instance));
			AttackOrder.push_back(&ActionList[i]);
		}
		
	}
	for (int i = 0; i < ActionList.size(); i++)
	{
		if (ActionList[i].type == 'm')
		{
			MonsterList.push_back(static_cast<BaseMonster*>(ActionList[i].instance));
			AttackOrder.push_back(&ActionList[i]);
		}
	}
	int roundcount = 0;
	while (true)  // (not all members of one side is dead)
	{	
		system("clear");
		roundcount++;
		cout << "Round " << roundcount << " ��" << endl;
		sleep(2);
		for (int i = 0; i < AttackOrder.size(); i++)
		{
			Update();
			Print();
			int atk;
			vector<ConsumableItem*> Items;
			if (AttackOrder[i]->alive == true)
			{
				switch (AttackOrder[i]->type)
				{
				case('p'):
					tmp_player = static_cast<NovicePlayer*>(AttackOrder[i]->instance);
					cout << tmp_player->getName() << "'s turn" << endl;
					sleep(1);
					cout << "Please make your move" << endl;
					cout << "1. Attack    2. Special skill  3.Use item" << endl;
					for (int i = 0; i < tmp_player->Backpack.size(); i++)
					{
						if (tmp_player->Backpack[i] != nullptr)
						{
							if (tmp_player->Backpack[i]->type == 'c')
							{
								Items.push_back(static_cast<ConsumableItem*>(tmp_player->Backpack[i]));
							}
						}
					}
					cout << "The items you have: " << endl;
					for (int i = 0; i < Items.size(); i++)
					{
						cout << i + 1 << ": " << Items[i]->name << endl;
					}
					int movechoice;
					while (true)
					{
						cin >> movechoice;
						if (cin.fail() || (movechoice != 1 && movechoice != 2 && movechoice != 3))
						{
							cin.clear();
							cin.ignore(100, '\n');
							cout << "Please input number \"1\", \"2\" or \"3\" " << endl;
						}
						else if (movechoice == 3 && Items.size() == 0)
						{
							cout << "There's no item to be used, please make another choice" << endl;
						}
						else
						{
							break;
						}
					}
					if (movechoice == 1)
					{
						cout << "Please choose a monster to attack, by entering the number of the monster" << endl;
						for (int j = 0; j < MonsterList.size(); j++)
						{
							cout << j + 1 << ". " << MonsterList[j]->name << "  ";
						}
						cout << endl;
						int choice;
						while (true)
						{
							cin >> choice;
							if (cin.fail() || choice < 1 || choice > MonsterList.size())
							{
								cin.clear();
								cin.ignore(100, '\n');
								cout << "Please input number of the monsters" << endl;
							}
							else
							{
								break;
							}
						}
						choice--;
						if (tmp_player->Weapon == nullptr)
						{
							atk = tmp_player->getAttack();
						}
						else
						{
							atk = tmp_player->getAttack() + tmp_player->Weapon->attack_increment;
						}
						if (atk < MonsterList[choice]->getHP() + MonsterList[choice]->defense)
						{
							cout << MonsterList[choice]->name << " is attacked" << endl;
							sleep(1);
							int nowmhp = MonsterList[choice]->getHP();
							if (atk <= MonsterList[choice]->defense)
							{
								cout << "Player didn't break the defence of the monster" << endl;
								sleep(1);
							}
							else
							{
								MonsterList[choice]->setHP(nowmhp - atk + MonsterList[choice]->defense);
							}
						}
						else
						{
							cout << MonsterList[choice]->name << " is attacked, and killed" << endl;
							sleep(1);
							MonsterList[choice]->setHP(0);

						}
					}
					else if (movechoice == 2)
					{
						cout << "Use SpecialSkill !" << endl;
						tmp_player->specialSkill();
						sleep(1);
					}
					else if (movechoice == 3)
					{
						if (Items.size() == 0)
						{
							cout << "You don't have any consumable item" << endl;
						}
						else
						{
							cout << "Please choose the item you want to consume" << endl;
							for (int i = 0; i < Items.size(); i++)
							{
								cout << i + 1 << ": " << Items[i]->name << endl;
							}
							int index;
							while (true)
							{
								cin >> index;
								if (cin.fail())
								{
									cin.clear();
									cin.ignore();
									cout << "Please input a number" << endl;
								}
								else if (index > Items.size() || index < 1)
								{
									cout << "Please input a valid number" << endl;
									cin.ignore();
								}
								else
								{
									break;
								}
							}
							index--;
							tmp_player->useConsumable(Items[index]);

						}
					}
					break;
				case('m'):
					tmp_monster = static_cast<BaseMonster*>(AttackOrder[i]->instance);
					cout << tmp_monster->name << "'s turn" << endl;
					sleep(1);
					srand(time(NULL));
					int atkchoice = rand() % PlayerList.size();
					atk = tmp_monster->attack;
					int plyrdefense;
					if (PlayerList[atkchoice]->Armor == nullptr)
					{
						plyrdefense = PlayerList[atkchoice]->getDefense();
					}
					else
					{
						plyrdefense = PlayerList[atkchoice]->getDefense() + PlayerList[atkchoice]->Armor->defense_increment;
					}
					if (atk < PlayerList[atkchoice]->getHP() + plyrdefense)
					{
						cout << PlayerList[atkchoice]->getName() << " is attacked" << endl;
						sleep(1);
						int nowmhp = PlayerList[atkchoice]->getHP();
						if (atk <= plyrdefense)
						{
							cout << "Monster's attack didn't break the player's defense" << endl;
							sleep(1);
						}
						else
						{
							PlayerList[atkchoice]->setHP(nowmhp - atk + plyrdefense);
						}						
					}
					else
					{
						cout << PlayerList[atkchoice]->getName() << " is attacked, and killed" << endl;
						sleep(1);
						PlayerList[atkchoice]->setHP(0);
					}
					break;
				}
			}
			system("clear");
			Update();
			bool plyrlive = 0, monlive = 0;
			for (int i = 0; i < ActionList.size(); i++)
			{
				if (ActionList[i].type == 'p')
				{
					if (ActionList[i].alive == 1)
					{
						plyrlive = 1;
					}
				}
				else if (ActionList[i].type == 'm')
				{
					if (ActionList[i].alive == 1)
					{
						monlive = 1;
					}
				}
			}
			if (plyrlive == 0 || monlive == 0)
			{
				break;
			}
		}
		Update();
		bool plyrlive = 0, monlive = 0;
		for (int i = 0; i < ActionList.size(); i++)
		{
			if (ActionList[i].type == 'p')
			{
				if (ActionList[i].alive == 1)
				{
					plyrlive = 1;
				}
			}
			else if (ActionList[i].type == 'm')
			{
				if (ActionList[i].alive == 1)
				{
					monlive = 1;
				}
			}
		}
		if (plyrlive == 0 || monlive == 0)
		{
			if (plyrlive == 0)
			{
				cout << "Players' all defeated" << endl;
				system("pause");
			//	system("clear");
				cout << "Monsters' win" << endl;
				sleep(2);
			//	system("clear");
				cout << "---------------------GAME OVER------------------------";
				sleep(2);
				return false;
			}
			if (monlive == 0)
			{
				cout << "Monsters' all defeated" << endl;
				system("pause");
			//	system("clear");
				cout << "Players' win" << endl;
				sleep(2);
			//	system("clear");
			//	cout << "---------------------GAME OVER------------------------";
			//	sleep(2);
				return true;
			}
			break;
		}
	}
}

void Battle::Update()
{
	vector<Character>AttackOrder = {};
	NovicePlayer *tmp_player;
	BaseMonster *tmp_monster;
	// divide type
	for (int i = 0; i < ActionList.size(); i++)
	{
		if (ActionList[i].type == 'p')
		{
			tmp_player = static_cast<NovicePlayer*>(ActionList[i].instance);
			if (tmp_player->getHP() == 0)
			{
				ActionList[i].alive = false;
			}
			else
			{
				ActionList[i].alive = true;
			}
		}
		else if (ActionList[i].type == 'm')
		{
			tmp_monster = static_cast<BaseMonster*>(ActionList[i].instance);
			if (tmp_monster->getHP() == 0)
			{
				ActionList[i].alive = false;
			}
			else
			{
				ActionList[i].alive = true;
			}
		}
	}
}

void Battle::include(NovicePlayer* playerptr)
{
	Character assign;
	assign.type = 'p';
	assign.alive = 1;
	assign.instance = playerptr;
	ActionList.push_back(assign);
	return;
}

void Battle::include(BaseMonster* monsterptr)
{
	Character assign;
	assign.type = 'm';
	assign.alive = 1;
	assign.instance = monsterptr;
	ActionList.push_back(assign);
	return;
}
