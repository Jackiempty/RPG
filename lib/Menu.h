#ifndef MENU_H
#define MENU_H
#include "Game.h"
using namespace std;
/*
class Menu
{
public:
        Game* game;
        Menu(Game* thegame)
        {
                game = thegame;
        }
        void Printmenu()
        {
                char point;
                while (true)
                {
                        bool Break = false;
                        system("clear");
                        cout << "    /|    //| |                              "
<< endl; cout << "   //|   // | |     ___       __             " << endl; cout
<< "  // |  //  | |   //___) ) //   ) ) //   / / " << endl; cout << " //  | //
| |  //       //   / / //   / /  " << endl; cout << "//   |//    | | ((____   //
/ / ((___( (   " << endl; cout << endl << "Please press the number to choose
your move" << endl; cout << "1:  " << "Switch player" << endl; cout << "2:  " <<
"Backpack" << endl; cout << "3:  " << "Save" << endl; cout << "4:  " << "Read"
<< endl; cout << "e:  " << "Quit" << endl; point = getchar(); switch(point)
                        {
                        case('1'):
                                SwitchPlayer(game->PlayerList);
                                break;
                        case('2'):
                                game->viewbackpack();
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
                        default:
                                break;
                        }
                        if (Break == true)
                        {
                                break;
                        }
                }
        }

        void SwitchPlayer(vector<NovicePlayer*> &PlayerList)
        {
                NovicePlayer* player1 = PlayerList[0];
                NovicePlayer* player2 = PlayerList[1];
                PlayerList[0] = player2;
                PlayerList[1] = player1;
        }

        void Save()
        {
                cout << "Save" << endl;
        }

        void Read()
        {
                cout << "Read" << endl;
        }
};
*/
#endif
