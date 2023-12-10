#ifndef KPLAYER_H
#define KPLAYER_H

#include <iostream>
#include <string>
#include "NovicePlayer.h"
using namespace std;

class KnightPlayer : public NovicePlayer
{
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	virtual void setLevel(int);
//	void heal(void);
	virtual void specialSkill();
	virtual string serialize();
	static NovicePlayer *unserialize(string);
};

#endif
