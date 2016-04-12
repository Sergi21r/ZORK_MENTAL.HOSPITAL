#ifndef _EXIT_
#define _EXIT_

#include "World.h"

class Room;

enum directions
{ 
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Exit{
public:
	char name[20];
	char description[200];
	bool closed = false;
	bool door = false;

	Room* org;
	Room* dst;

	directions direction;
};

#endif _EXIT_