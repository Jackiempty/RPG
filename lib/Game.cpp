#include "Game.h"
using namespace std;

Game::Game()
{
	KnightPlayer* shujinnkou = new KnightPlayer(1, "You");
	HealerPlayer* waifu = new HealerPlayer(1, "Your_inner_peace");
	PlayerList.push_back(shujinnkou);
	PlayerList.push_back(waifu);
//	menu = new Menu(this);
	Field* map1 = new Field("map1.txt", 1, 1, 30, 15);
	Field* map2 = new Field("map2.txt", 1, 1, 30, 15);
	Field* map3 = new Field("map3.txt", 1, 1, 30, 15);
	map1->setmapname("map01.txt");
	map2->setmapname("map02.txt");
	map3->setmapname("map03.txt");
	Maps.push_back(map1);
	Maps.push_back(map2);
	Maps.push_back(map3);
	CurrentMap = map1;
	stage = 0;
	story();
	/*
	Backpacks.push_back(shujinnkou->Backpack);
	Backpacks.push_back(waifu->Backpack);
	AxeWeapon* Axe = new AxeWeapon();
	ShieldArmor* Shield = new ShieldArmor();
	vector <Item*> box1;
	vector <Item*> box2;
	box1.push_back(Axe);
	box2.push_back(Shield);
	Boxes.push_back(box1);
	Boxes.push_back(box2);
	*/
}

void Game::Run()
{
	//	cout << CurrentMap << endl;
	//	CurrentMap->PrintMap();
	//	system("pause");
	// initscr();
	system("stty -icanon");
	main = true;
    quit = false;
	while (true)
	{
		while (main == true)
		{
			Main(main, quit);
		}
		if (quit == true)
		{
			break;
		}
		// sleep(1);
		system("clear");
		CurrentMap->display();
		char move;
		move = getchar();
		switch (move)
		{
		case('e'):
			Menu(main); // 以後改成像DQ那樣(大改 ==)[✔]
			break;
		}
		CurrentMap->move(move);
		Trigger(); // 這裡也是，不再是以玩家為主體[✔]
		
	}
	// endwin();
	system("clear");
	cout << "GAME OVER" << endl;
	return;
}

bool Game::Trigger()
{
	if (CurrentMap->getMapSymbol(CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX()) == 2) // event
	{
		system("clear");
		cout << "sophomore: This is all what I can help you...., go! " << endl;
		cout << "Level UP !!!" << endl;
		sleep(1);
		cout << "Your level is 100" << endl;
		sleep(1);
		system("clear");
		//		cout << "stop?" << endl;
		PlayerList[0]->setLevel(100);
		PlayerList[1]->setLevel(100);
		PlayerList[0]->refresh_exp();
		PlayerList[1]->refresh_exp();
		//		cout << "Here?" << endl;
		CurrentMap->setMapSymbol(0, CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX());
		system("pause");
		return true;
	}
	else if (CurrentMap->getMapSymbol(CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX()) == 4) // battle
	{
		Battle battle(1, 2);
		ZombieMonster monster1;
		GoblinMonster monster2;
		battle.include(PlayerList[0]);
		battle.include(&monster1);
		battle.include(&monster2);
		CurrentMap->setMapSymbol(0, CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX());
		if (battle.Fight() == true)
		{
			cout << "6 credits aquired, CS left...." << endl;
			system("pause");
			PlayerList[0]->setExp(PlayerList[0]->getExp() + monster1.exp + monster2.exp);
			PlayerList[0]->setMoney(PlayerList[0]->getMoney() + monster1.money + monster2.money);
			PlayerList[1]->setExp(PlayerList[1]->getExp() + monster1.exp + monster2.exp);
			PlayerList[1]->setMoney(PlayerList[1]->getMoney() + monster1.money + monster2.money);
			PlayerList[0]->refresh_level();
			PlayerList[0]->refresh_level();
			return true;
		}
		else if (battle.Fight() == false)
		{
			cout << "You failed your exam..." << endl;
			cout << "Try harder in CS final!" << endl;
			system("pause");
			return false;
		}

	}
	else if (CurrentMap->getMapSymbol(CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX()) == 5) // boss
	{
		Battle battle(1, 1);
		JWMonster monster;
		battle.include(&monster);
		battle.include(PlayerList[0]);
		CurrentMap->setMapSymbol(0, CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX());
		if (battle.Fight() == true)
		{
			cout << "3 credits aquired, CS cleared!" << endl;
			system("pause");
			PlayerList[0]->setExp(PlayerList[0]->getExp() + monster.exp);
			PlayerList[0]->setMoney(PlayerList[0]->getMoney() + monster.money);
			PlayerList[1]->setExp(PlayerList[1]->getExp() + monster.exp);
			PlayerList[1]->setMoney(PlayerList[1]->getMoney() + monster.money);
			PlayerList[0]->refresh_level();
			PlayerList[0]->refresh_level();
			CurrentMap->setMapSymbol(7, 38, 38);
			return true;
		}
		else if (battle.Fight() == false)
		{
			cout << "You failed all your exam..." << endl;
			cout << "You are such a piece of shit" << endl;
			system("pause");
			return false;
		}
	}
	else if (CurrentMap->getMapSymbol(CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX()) == 9) // teleport 
	{
		teleport();
		return true;
	}
	else if (CurrentMap->getMapSymbol(CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX()) == 3) // box
	{
		//		viewbox();
		openbox();
		CurrentMap->setMapSymbol(0, CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX());
		return true;
	}
	else if (CurrentMap->getMapSymbol(CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX()) == 6) // shop
	{
		Shop();
		return true;
	}
	else if (CurrentMap->getMapSymbol(CurrentMap->getCurrentPositionY(), CurrentMap->getCurrentPositionX()) == 7) // end
	{
		cout << "You have passed the final exam, and cleared this game, hope you had a good time" << endl;
		sleep(1);
		cout << "Thank you for your playing!" << endl;
		quit = true;
	}
	else
	{
		return false;
	}
}

void Game::viewbackpack()
{
	int index = 0;
	NovicePlayer* tmp_plyr = PlayerList[index];
	while (true)
	{	
		/*
		tmp_plyr = PlayerList[index];
		system("clear");
//		cout << PlayerList[index] << endl;
		cout << tmp_plyr->getName() << "'s backpack:  (press Z to switch)" << endl << endl;
//		cout << "Current backpack weight: " << tmp_plyr->backpack_weight << "/" << tmp_plyr->backpack_weight_limit << endl;
		if (tmp_plyr->Weapon == nullptr)
		{
			cout << "Total Attack: " << tmp_plyr->getAttack() << endl;
		}
		else
		{
			cout << "Total Attack: " << tmp_plyr->getAttack() + tmp_plyr->Weapon->attack_increment << endl;
		}
		if (tmp_plyr->Armor == nullptr)
		{
			cout << "Total Defence: " << tmp_plyr->getDefense() << endl;
		}
		else
		{
			cout << "Total Defence: " << tmp_plyr->getDefense() + tmp_plyr->Armor->defense_increment << endl;
		}
		cout << "HP: " << tmp_plyr->getHP() << "/" << tmp_plyr->getMaxHP() << endl;
		cout << "MP: " << tmp_plyr->getMP() << "/" << tmp_plyr->getMaxMP() << endl;
		cout << "----EQUIPMENTs----" << endl;
		cout << "Weapon: ";
		if (tmp_plyr->Weapon == nullptr)
		{
			cout << "empty" << endl;
		}
		else
		{
			cout << tmp_plyr->Weapon->name << "(+" << tmp_plyr->Weapon->attack_increment << ")" << endl;
		}
		cout << "Armor: ";
		if (tmp_plyr->Armor == nullptr)
		{
			cout << "empty" << endl;
		}
		else
		{
			cout << tmp_plyr->Armor->name << "(+" << tmp_plyr->Armor->defense_increment << ")" << endl;
		}
		cout << "----BACKPACK----" << endl;
		for (int i = 0; i < tmp_plyr->Backpack.size(); i++)
		{
			if (tmp_plyr->Backpack[i] != nullptr)
			{
				cout << setw(3) << i + 1 << ": " << tmp_plyr->Backpack[i]->name << endl;
			}
			else
			{
				cout << setw(3) << i + 1 << ": " << "empty" << endl;
			}
		}
		*/
		tmp_plyr = PlayerList[index];
		tmp_plyr->Viewbackpack();
		char move;
		move = getchar();
		if (move == '2')
		{
			break;
		}						
		if (move == 'z')
		{
			switch (index)
			{
			case(0):
				index = 1;
				break;
			case(1):
				index = 0;
				break;
			default:
				break;
			}
		}
		if (move == 'r')
		{
			cout << endl;
			int choice;
			cout << "What item do you want to give to the other player?" << endl;
			cin >> choice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Please input a number" << endl;
				sleep(1);
				break;
			}
			else if (choice > tmp_plyr->Backpack.size())
			{
				cout << "The backpack slot does not exist" << endl;
				cin.ignore();
				sleep(1);
				break;
			}
			choice--;
			switch (index)
			{
			case(0):
				PlayerList[1]->putItem(tmp_plyr->takeItem(choice));
				break;
			case(1):
				PlayerList[0]->putItem(tmp_plyr->takeItem(choice));
				break;
			default:
				break;
			}
		}
		tmp_plyr->getmove(move);		
	}
	return;
}

void Game::openbox()
{
	if (CurrentMap->getMapName() == "map01.txt")
	{
		system("clear");
		cout << "TA's cover, previous exam, red bull aquired" << endl;
		cout << "You also got 1000 dollar to buy whatever you want" << endl;
		ShieldArmor* shield = new ShieldArmor;
		AxeWeapon* axe = new AxeWeapon;
		LifePotion* life = new LifePotion;
		PlayerList[0]->putItem(shield);
		PlayerList[0]->putItem(axe);
		PlayerList[0]->putItem(life);
		PlayerList[0]->setMoney(1000);
		system("pause");
	}
	else if (CurrentMap->getMapName() == "map02.txt")
	{
		if (CurrentMap->getCurrentPositionY() == 1 && CurrentMap->getCurrentPositionX() == 1)
		{
			//CurrentMap = Maps[0];
		}
		else if (CurrentMap->getCurrentPositionY() == 10 && CurrentMap->getCurrentPositionX() == 10)
		{
			//CurrentMap = Maps[2];
		}
	}
	else if (CurrentMap->getMapName() == "map03.txt")
	{
		//CurrentMap = Maps[1];
	}
	return;
}

void Game::teleport()
{
	if (CurrentMap->getMapName() == "map01.txt")
	{
		CurrentMap = Maps[1];
//		cout << "stage: " << stage << endl;
//		system("pause");
		if (stage == 1)
		{
			story();
		}
	}
	else if (CurrentMap->getMapName() == "map02.txt")
	{
		if (CurrentMap->getCurrentPositionY() == 1 && CurrentMap->getCurrentPositionX() == 1)
		{
			CurrentMap = Maps[0];
		}
		else if (CurrentMap->getCurrentPositionY() == 10 && CurrentMap->getCurrentPositionX() == 10)
		{
			CurrentMap = Maps[2];
//			cout << "stage: " << stage << endl;
//			system("pause");
			if (stage == 2)
			{
				story();
			}
		}
	}
	else if (CurrentMap->getMapName() == "map03.txt")
	{
		CurrentMap = Maps[1];

	}
	return;
}

void Game::PrintMap()
{
	CurrentMap->PrintMap();
	return;
}

void Game::Shop()
{
	int who = 0;
	NovicePlayer* tmp_plyr = PlayerList[who];
	while (true)
	{
		tmp_plyr = PlayerList[who];
		int money = tmp_plyr->getMoney();
		system("clear");
		cout << "It is " << tmp_plyr->getName() << " buying (press Z to switch)" << endl;
		cout << "Money: " << money << endl;
		cout << "------------------SHOP-----------------" << endl;
		cout << "1: (C)red bull $20" << endl;
		cout << "2: (C)late night snack $30" << endl;
		cout << "3: (W)stay up late $20" << endl;
		cout << "4: (W)previous exam $30" << endl;
		cout << "5: (A)TA's cover $20" << endl;
		cout << "6: (A)Professor's favorite $30" << endl;
		char index;
		cout << "What item do you want to buy? (input 0 to quit)" << endl;
		index = getchar();
		while (true)
		{
			if (cin.fail())
			{
				cout << "Please input a valid number" << endl;
				index = getchar();
				cin.clear();
				cin.ignore();
			}
			else if (index != '1' && index != '2' && index != '0' && index != 'z')
			{
				cout << "Please input a valid number" << endl;
				index = getchar();
			}
			else
			{
				break;
			}
		}	
		if (index == '0')
		{
			break;
		}
		if (index == '1')
		{
			if (money >= 20)
			{
				tmp_plyr->setMoney(money - 20);
				cout << "You bought a red bull" << endl;
				LifePotion* potion1 = new LifePotion;
				tmp_plyr->putItem(potion1);
			}
			else
			{
				cout << "Your money is not enough, please come next time" << endl;
				sleep(1);
			}	
		}
		if (index == '2')
		{
			if (money >= 30) 
			{
				tmp_plyr->setMoney(money - 30);
				cout << "You bought a late night snack" << endl;
				MagicPotion* potion2 = new MagicPotion;
				tmp_plyr->putItem(potion2);
			}
			else
			{
				cout << "Your money is not enough, please come next time" << endl;
				sleep(1);
			}
		}
		if (index == '3')
		{
			if (money >= 20)
			{
				tmp_plyr->setMoney(money - 30);
				cout << "You bought a stay up late" << endl;
				MagicPotion* potion2 = new MagicPotion;
				tmp_plyr->putItem(potion2);
			}
			else
			{
				cout << "Your money is not enough, please come next time" << endl;
				sleep(1);
			}
		}
		if (index == '4')
		{
			if (money >= 30)
			{
				tmp_plyr->setMoney(money - 30);
				cout << "You bought a previous exam" << endl;
				MagicPotion* potion2 = new MagicPotion;
				tmp_plyr->putItem(potion2);
			}
			else
			{
				cout << "Your money is not enough, please come next time" << endl;
				sleep(1);
			}
		}
		if (index == '5')
		{
			if (money >= 20)
			{
				tmp_plyr->setMoney(money - 30);
				cout << "You bought a TA's cover" << endl;
				MagicPotion* potion2 = new MagicPotion;
				tmp_plyr->putItem(potion2);
			}
			else
			{
				cout << "Your money is not enough, please come next time" << endl;
				sleep(1);
			}
		}
		if (index == '6')
		{
			if (money >= 30)
			{
				tmp_plyr->setMoney(money - 30);
				cout << "You bought a Professor's favorite" << endl;
				MagicPotion* potion2 = new MagicPotion;
				tmp_plyr->putItem(potion2);
			}
			else
			{
				cout << "Your money is not enough, please come next time" << endl;
				sleep(1);
			}
		}
		if (index == 'z')
		{
			switch (who)
			{
			case(0):
				who = 1;
				break;
			case(1):
				who = 0;
				break;
			default:
				break;
			}
		}
	}	
}

void Game::Menu(bool &main)
{
	char point;
	while (true)
	{
		bool Break = false;
		system("clear");
		cout << "    /|    //| |                              " << endl;
		cout << "   //|   // | |     ___       __             " << endl;
		cout << "  // |  //  | |   //___) ) //   ) ) //   / / " << endl;
		cout << " //  | //   | |  //       //   / / //   / /  " << endl;
		cout << "//   |//    | | ((____   //   / / ((___( (   " << endl;
		cout << endl << "Please press the number to choose your move" << endl;
		cout << "1:  " << "Switch player (" << PlayerList[0]->getName() << ")" << endl;
		cout << "2:  " << "Backpack" << endl;
		cout << "3:  " << "Save" << endl;
		cout << "4:  " << "Read" << endl;
		cout << "M:  " << "Map" << endl;
		cout << "E:  " << "Go Back" << endl;
		cout << "Q:  " << "Quit" << endl;
		point = getchar();
		switch (point)
		{
		case('1'):
			SwitchPlayer();
			break;
		case('2'):
			viewbackpack();
			break;
		case('3'):
			Save();
			break;
		case('4'):
			Read();
			break;
		case('e'):
			Break = true;
			break;
		case('m'):
			while (true)
			{
				system("clear");
				PrintMap();
				if (getchar() == 'm')
				{
					break;
				}
			}
			break;
		case('q'):
			main = true;
			Break = true;
			break;
		default:
			break;
		}
		if (Break == true)
		{
			break;
		}
	}
	return;
}

void Game::SwitchPlayer()
{
	NovicePlayer* player1 = PlayerList[0];
	NovicePlayer* player2 = PlayerList[1];
	PlayerList[0] = player2;
	PlayerList[1] = player1;
	return;
}

void Game::Save()
{
	ofstream out1("player1.txt", ios::out);
	if (!out1)
	{
		cerr << "File could not open" << endl;
		cerr << "003" << endl;
		exit(1);
	}
	ofstream out2("player2.txt", ios::out);
	if (!out2)
	{
		cerr << "File could not open" << endl;
		cerr << "004" << endl;
		exit(1);
	}
	ofstream out3("general.txt", ios::out);
	if (!out3)
	{
		cerr << "File could not open" << endl;
		cerr << "005" << endl;
		exit(1);
	}
	out1 << PlayerList[0]->serialize(); // save in player@.txt
	out2 << PlayerList[1]->serialize();
	for (int i = 0; i < Maps.size(); i++)
	{
		Maps[i]->Savemap();  // use map name as file, save map info
	}
	//-----------------------general.txt-----------------------
	if (PlayerList[0]->getName() == "shujinnkou")
	{
		out3 << 0 << endl;
	}
	else
	{
		out3 << 1 << endl;
	}
	out3 << stage << endl;
	if (CurrentMap->getMapName() == "map01.txt")
	{
		out3 << 1 << endl;
	}
	else if (CurrentMap->getMapName() == "map02.txt")
	{
		out3 << 2 << endl;
	}
	else if (CurrentMap->getMapName() == "map03.txt")
	{
		out3 << 3 << endl;
	}
	out3 << CurrentMap->getCurrentPositionY() << " " << CurrentMap->getCurrentPositionX() << endl;
//	out3 << "shujinnkou:\n";
	for (int i = 0; i < PlayerList[0]->Backpack.size(); i++)
	{
		if (PlayerList[0]->Backpack[i] != nullptr)
		{
			switch (PlayerList[0]->Backpack[i]->number)
			{
			case(1):
				out3 << 1;
				break;
			case(2):
				out3 << 2;
				break;
			case(3):
				out3 << 3;
				break;
			case(4):
				out3 << 4;
				break;
			case(5):
				out3 << 5;
				break;
			case(6):
				out3 << 6;
				break;
			default:
				break;
			}
			out3 << ",";
		}
		
	}
	out3 << endl;
//	out3 << "waifu:\n";
	for (int i = 0; i < PlayerList[1]->Backpack.size(); i++)
	{
		if (PlayerList[1]->Backpack[i] != nullptr)
		{
			switch (PlayerList[1]->Backpack[i]->number)
			{
			case(1):
				out3 << 1;
				break;
			case(2):
				out3 << 2;
				break;
			case(3):
				out3 << 3;
				break;
			case(4):
				out3 << 4;
				break;
			case(5):
				out3 << 5;
				break;
			case(6):
				out3 << 6;
				break;
			default:
				break;
			}
		}
	}
	cout << "Saved" << endl;
	sleep(1);
	return;
}

void Game::Read()
{
	
	ifstream input("general.txt", ios::in);
	if (!input)
	{
		cerr << "File could not be opened" << endl;
		cerr << "006" << endl;
		exit(1);
	}
	string buff;
	input >> buff;
	if (buff == "nono")
	{
		system("clear");
		cout << "There is no saved file yet" << endl;
		stage = 1;
	//	cout << "New game starts..." << endl;
		system("pause");
		return;
	}
	if (stoi(buff) == 0)
	{
		PlayerList[0] = KnightPlayer::unserialize("player1.txt");
		PlayerList[1] = HealerPlayer::unserialize("player2.txt");
	}
	else if (stoi(buff) == 1)
	{
		PlayerList[1] = KnightPlayer::unserialize("player1.txt");
		PlayerList[0] = HealerPlayer::unserialize("player2.txt");
	}
	input >> buff; // stage
//	cout << "stage: " << buff << endl;
	stage = stoi(buff);
	input >> buff; // current map
	CurrentMap = Maps[stoi(buff) - 1];
//	cout << "map: " << CurrentMap->getMapName() << endl;
	string Y, X;
	input >> Y >> X; // current position
//	cout << "Current position: " << Y << ", " << X << endl;
	CurrentMap->setPosition(stoi(Y), stoi(X));
	buff = "";
	input >> buff; // player1's items
	istringstream one{ buff };
	string unit;
	vector<int> item;
	while (getline(one, unit, ','))
	{
		item.push_back(stoi(unit));
	}
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i] == 1)
		{
			SwordWeapon* i1 = new SwordWeapon;
			PlayerList[0]->Backpack.push_back(i1);
		}
		if (item[i] == 2)
		{
			AxeWeapon* i2 = new AxeWeapon;
			PlayerList[0]->Backpack.push_back(i2);
		}
		if (item[i] == 3)
		{
			TunicArmor* i3 = new TunicArmor;
			PlayerList[0]->Backpack.push_back(i3);
		}
		if (item[i] == 4)
		{
			ShieldArmor* i4 = new ShieldArmor;
			PlayerList[0]->Backpack.push_back(i4);
		}
		if (item[i] == 5)
		{
			LifePotion* i5 = new LifePotion;
			PlayerList[0]->Backpack.push_back(i5);
		}
		if (item[i] == 6)
		{
			MagicPotion* i6 = new MagicPotion;
			PlayerList[0]->Backpack.push_back(i6);
		}
	}
	item = {};
	buff = "";
	unit = "";
	input >> buff; // player2's items
	istringstream two{ buff };
	while (getline(two, unit, ','))
	{
		item.push_back(stoi(unit));
	}
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i] == 1)
		{
			SwordWeapon* i1 = new SwordWeapon;
			PlayerList[1]->Backpack.push_back(i1);
		}
		if (item[i] == 2)
		{
			AxeWeapon* i2 = new AxeWeapon;
			PlayerList[1]->Backpack.push_back(i2);
		}
		if (item[i] == 3)
		{
			TunicArmor* i3 = new TunicArmor;
			PlayerList[1]->Backpack.push_back(i3);
		}
		if (item[i] == 4)
		{
			ShieldArmor* i4 = new ShieldArmor;
			PlayerList[1]->Backpack.push_back(i4);
		}
		if (item[i] == 5)
		{
			LifePotion* i5 = new LifePotion;
			PlayerList[1]->Backpack.push_back(i5);
		}
		if (item[i] == 6)
		{
			MagicPotion* i6 = new MagicPotion;
			PlayerList[1]->Backpack.push_back(i6);
		}					
	}
	*Maps[0] = Field("map01.txt", 1, 1, 30, 15); // open old maps
	*Maps[1] = Field("map02.txt", 1, 1, 30, 15);
	*Maps[2] = Field("map03.txt", 1, 1, 30, 15);
	cout << "Loading game....." << endl;
	sleep(2);
}

void Game::Main(bool &main, bool &quit)
{
	char move;
	while (true)
	{
		system("clear");
		cout << " _______           _          _____               " << endl;
		cout << "|__   __|         | |        |  __ \\              " << endl;
		cout << "   | |_ __ _   _  | |_ ___   | |__) |_ _ ___ ___  " << endl;
		cout << "   | | '__| | | | | __/ _ \\  |  ___/ _` / __/ __| " << endl;
		cout << "   | | |  | |_| | | || (_) | | |  | (_| \\__ \\__ \\ " << endl;
		cout << "   |_|_|   \\__, |  \\__\\___/  |_|   \\__,_|___/___/ " << endl;
		cout << "            __/ |                                 " << endl;
		cout << "           |___/                                  " << endl << endl;
		cout << "   Please press the number to choose your move    " << endl;
		cout << "                    1: Start                      " << endl;
		cout << "                    2: Reset                      " << endl;
		cout << "                    3: Quit                       " << endl;
		move = getchar();
		// cerr << "char: " << move << endl;
		if (move == '1')
		{
			while (true)
			{
				system("clear");
				char choice;
				cout << "1: " << "Continue" << endl;
				cout << "2: " << "New Game" << endl;
				cout << "3: " << "Go Back " << endl;
				choice = getchar();
				if (choice == '1')
				{
					Read();
					main = false;
					break;
				}
				else if (choice == '2')
				{
					stage = 1;
					for (int i = 0; i < PlayerList.size(); i++)
					{
						PlayerList[i]->Backpack = {};
						PlayerList[i]->setLevel(1);
						PlayerList[i]->setMoney(0);
						PlayerList[i]->refresh_level();
						PlayerList[i]->Armor = nullptr;
						PlayerList[i]->Weapon = nullptr;
						CurrentMap = Maps[0];
						CurrentMap->setPosition(1, 1);
						*Maps[0] = Field("map1.txt", 1, 1, 30, 15);
						*Maps[1] = Field("map2.txt", 1, 1, 30, 15);
						*Maps[2] = Field("map3.txt", 1, 1, 30, 15);
						Maps[0]->setmapname("map01.txt");
						Maps[1]->setmapname("map02.txt");
						Maps[2]->setmapname("map03.txt");
					}
					main = false;
					break;
				}
				else if (choice == '3')
				{
					break;
				}
				quit = false;
				break;
			}
			if (main == false)
			{
				break;
			}
		}
		if (move == '2')
		{
			ofstream out("general.txt", ios::out);
			if (!out)
			{
				cerr << "error" << endl;
				exit(1);
				break;
			}
			cout << "Game reset, saved file deleted..." << endl;
			sleep(1);
			out << "nono";
			resetmap();
		}
		if (move == '3')
		{	
			cout << "Are you sure you wanna quit? (If you didn't save, you will lose your progress)" << endl;
			cout << "Press \"1\" to confirm" << endl;
			char choice = getchar();
			if (choice == '1')
			{
				quit = true;
				main = false;
				break;
			}
		}
	}
}

void Game::resetmap()  // reset map00@.txt file to original
{
	ifstream input1("map1.txt", ios::in);
	if (!input1)
	{
		cerr << "error" << endl;
		exit(1);
	}
	ofstream output1("map01.txt", ios::out);
	if (!output1)
	{
		cerr << "error" << endl;
		exit(1);
	}
	string buff;
	while (!input1.eof())
	{
		input1 >> buff;
		output1 << buff << endl;
	}
	ifstream input2("map2.txt", ios::in);
	if (!input2)
	{
		cerr << "error" << endl;
		exit(1);
	}
	ofstream output2("map02.txt", ios::out);
	if (!output2)
	{
		cerr << "error" << endl;
		exit(1);
	}
	while (!input2.eof())
	{
		input2 >> buff;
		output2 << buff << endl;
	}
	ifstream input3("map3.txt", ios::in);
	if (!input3)
	{
		cerr << "error" << endl;
		exit(1);
	}
	ofstream output3("map03.txt", ios::out);
	if (!output3)
	{
		cerr << "error" << endl;
		exit(1);
	}
	while (!input3.eof())
	{
		input3 >> buff;
		output3 << buff << endl;
	}
	return;
}

void Game::story()
{
	if (stage == 0)
	{
	//	cout << "This is a story of you trying the pass the final exams which are all hard as hell... " << endl;
	//	sleep(5);
	//	cout << "Try to clear all the challenges on the way to your lovely summer vocation!" << endl;
	//	sleep(5);	
	}
	else if (stage == 1)
	{
		system("clear");
	//	cout << "This is the maze of the professors' inner mind, once you go through it, you realize what professors are thinking" << endl;
	//	sleep(3);
		stage++;
	}	
	else if (stage == 2)
	{
		system("clear");
	//	cout << "This is your final step to pass all the exams, with all the assistance I gave you" << endl
	//		 << "you will sure overcome all the challenges!" << endl;
	//	sleep(3);
	}
	return;
}
	
/*
void Game::viewbox()
{
	if (CurrentMap->getMapName() == "map1.txt")
	{
		while (true)
		{
			system("clear");
			for (int i = 0; i < Boxes[0].size(); i++)
			{
 				if (Boxes[0][i] != nullptr)
				{
					cout << setw(3) << i + 1 << ": " << Boxes[0][i]->name << endl;
				}
				else
				{
					cout << setw(3) << i + 1 << ": " << "empty" << endl;
				}
			}
			char move;
			move = getchar();
			if (move == 'e')
			{
				break;
			}
		}		
	}
	
	else if (CurrentMap->getMapName() == "map2.txt")
	{
		if (CurrentMap->getCurrentPositionY() == 1 && CurrentMap->getCurrentPositionX() == 1)
		{
			
		}
		else if (CurrentMap->getCurrentPositionY() == 10 && CurrentMap->getCurrentPositionX() == 10)
		{
			
		}
	}
    
	else if (CurrentMap->getMapName() == "map3.txt")
	{
		while (true)
		{
			system("clear");
			for (int i = 0; i < Boxes[1].size(); i++)
			{
				if (Boxes[1][i] != nullptr)
				{
					cout << setw(3) << i + 1 << ": " << Boxes[1][i]->name << endl;
				}
				else
				{
					cout << setw(3) << i + 1 << ": " << "empty" << endl;
				}
			}
			char move;
			move = getchar();
			if (move == 'e')
			{
				break;
			}
		}
	}	
	return;
}
*/