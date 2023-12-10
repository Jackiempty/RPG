#ifndef HPLAYER_H
#define HPLAYER_H
#include "NovicePlayer.h"
#include <iostream>
#include <string>
using namespace std;

class HealerPlayer : public NovicePlayer
{
public:
	HealerPlayer();
	HealerPlayer(int);
	HealerPlayer(int, string);
	HealerPlayer(const HealerPlayer&);
	virtual void setLevel(int);
	virtual void specialSkill();
	virtual string serialize();
	static NovicePlayer* unserialize(string);
};

#endif
