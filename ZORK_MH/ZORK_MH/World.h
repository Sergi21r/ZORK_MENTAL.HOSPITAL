#ifndef _WORLD_H_
#define _WORLD_H_
#include "Player.h"
#include "Room.h"
#include "Exit.h"

using namespace std;

class World
{
public:
	Room* rooms = nullptr;
	Player* player = nullptr;
	Exit* exits = nullptr;

	World();

	void CreateWorld() const;
	void Help()const;
	void Movement()const;

	~World();
};


#endif //_WORLD_H_