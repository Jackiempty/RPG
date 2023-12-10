#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Battle.h"
using namespace std;

#ifndef Field_H
#define Field_H
class Field {
public:
	Field(vector<vector<int>>, int, int, int, int);
	//The first parameter is the map data
	//The second and third parameter are the current place(x, y) of player
	//The forth and fifth parameter are the(width, height) of vision
	Field(string, int, int, int, int);
	//Similar to first one, but the first parameter is name of file that stores map data
	~Field();

	bool move(char);
	//Move player to next position, the parameter is the direction
	//The return value indicates whether this move is legal or not
	bool moveUp(void);
	bool moveDown(void);
	bool moveLeft(void);
	bool moveRight(void);
	//The same as move(char), move player to next position
	//But the direction is determined


//These methods get the information of the map
	int getCurrentPositionX(void) const;
	int getCurrentPositionY(void) const;
	int getVisionWidth(void) const;
	int getVisionHeight(void) const;
	string getMapName(void) const;
	int getMapSymbol(int, int);
	//Parameter is the position(y, x)
	void setPosition(int, int);
	//Set the position of player, prameters are position(x, y)
	void setMapSymbol(int, int, int);
	//Set the symbol on a specific position
	//The first parameter is symbol, the rest are position(x, y)
	void setVisionSize(int, int);
	//Set the size of vision, parameters are(width, height)
	void display(void) const;
	//Displaying the map
	void PrintMap() const;
	void Savemap();
/*==============================================

Please add more methods according to your own features

==============================================*/

//	bool Trigger(NovicePlayer*);
//	void Story();
	void setmapname(string);

private:
	vector<vector<int>> map_data;
	//The actual map data with symbols and items
	//This is a double dimension array of integers

	int current_position_x;
	int current_position_y;
	//Current position of player
	//This can be used to display the map(player is always on the center)

	string map_name;
	//The name of this map

	int vision_width;
	int vision_height;
	//The width and height of vision

	int Height;
	int Width;
/*==============================================

Please add more data members you want!

==============================================*/
};
#endif