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
public:
	void CreateWorld() const;
	void Help()const;

	~World();
private:
	int GetDirection(char operation[]);
	void GetOperation(char ope[], char ope2[]);
	void Go(char operation[]);
	void Look(char operation[]);
	void Open(char operation[]);
	void Close(char operation[]);
};


#endif //_WORLD_H_