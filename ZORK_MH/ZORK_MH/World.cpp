#include "World.h"
#include<string.h>
#include<stdio.h>
#define NUM_ROOMS 9
#define NUM_EXITS 16

World::World() //CONSTRUCTOR, memory reserve
{

	rooms = new Room[NUM_ROOMS];
	exits = new Exit[NUM_EXITS];
	player = new Player;
	//player->position = rooms + 0;//player location
}

void World::CreateWorld() const
{
	/*--------------------------------------------------CREATION ROOMS--------------------------------------------------*/

	strcpy_s((rooms[0]).name, "Office");
	strcpy_s((rooms[0]).description, "This is the place where you spend a lot of time of the day.");

	strcpy_s((rooms[1]).name, "Corridor 1");
	strcpy_s((rooms[1]).description, "This is the corridor that connects with office, cell 1, cell 2 and the other corridor.");

	strcpy_s((rooms[2]).name, "Cell 1");
	strcpy_s((rooms[2]).description, "One of the 3 cells, only have lived here 3 people since was created.");

	strcpy_s((rooms[3]).name, "Cell 2");
	strcpy_s((rooms[3]).description, "One of the 3 cells, It is famous for having the most crazy inmates.");

	strcpy_s((rooms[4]).name, "Corridor 2");
	strcpy_s((rooms[4]).description, "This is the corridor that connects with corridor 1, cell 3, infirmary and the WC.");

	strcpy_s((rooms[5]).name, "Cell 3");
	strcpy_s((rooms[5]).description, "One of the 3 cells, now nobody lives because the last inmate escaped from there.");

	strcpy_s((rooms[6]).name, "Infirmary");
	strcpy_s((rooms[6]).description, "This is the infirmary of the hospital, there is the a doctor 24h at your disposition.");

	strcpy_s((rooms[7]).name, "WC");
	strcpy_s((rooms[7]).description, "The WC of the hospital, there are only a toilet, a washbasin, a mirror and some paper.");

	strcpy_s((rooms[8]).name, "Secret Room");
	strcpy_s((rooms[8]).description, "This is a secret room, it was the way to escape that used the last inmate of cell 3.");


	/*--------------------------------------------------CREATION ROOMS--------------------------------------------------*/

	//FROM OFFICE TO CORRIDOR 1

	strcpy_s(exits[0].name, "Simple way");
	strcpy_s(exits[0].description, "It is a room connector");
	exits[0].org = (rooms + 0);
	exits[0].dst = (rooms + 1);
	exits[0].direction = NORTH;

	//FROM CORRIDOR 1 TO OFFICE

	strcpy_s(exits[1].name, "Simple way");
	strcpy_s(exits[1].description, "Your own office");
	exits[1].org = (rooms + 1);
	exits[1].dst = (rooms + 0);
	exits[1].direction = SOUTH;

	//FROM CORRIDOR 1 TO CELL 1

	strcpy_s(exits[2].name, "Very little corridor way");
	strcpy_s(exits[2].description, "The first cell of the hospital");
	exits[2].org = (rooms + 1);
	exits[2].dst = (rooms + 2);
	exits[2].direction = WEST;

	//FROM CORRIDOR 1 TO CELL 2

	strcpy_s(exits[3].name, "Very little corridor way");
	strcpy_s(exits[3].description, "The second cell of the hospital");
	exits[3].org = (rooms + 1);
	exits[3].dst = (rooms + 3);
	exits[3].direction = EAST;

	//FROM CELL 1 TO CORRIDOR 1

	strcpy_s(exits[4].name, "Very little corridor way");
	strcpy_s(exits[4].description, "It is a room connector");
	exits[4].org = (rooms + 2);
	exits[4].dst = (rooms + 1);
	exits[4].direction = EAST;

	//FROM CELL 2 TO CORRIDOR 1

	strcpy_s(exits[5].name, "Very little corridor way");
	strcpy_s(exits[5].description, "It is a room connector");
	exits[5].org = (rooms + 3);
	exits[5].dst = (rooms + 1);
	exits[5].direction = WEST;

	//FROM CORRIDOR 1 TO CORRIDOR 2

	strcpy_s(exits[6].name, "Simple way");
	strcpy_s(exits[6].description, "It is a room connector");
	exits[6].org = (rooms + 1);
	exits[6].dst = (rooms + 4);
	exits[6].direction = NORTH;

	//FROM CORRIDOR 2 TO CORRIDOR 1

	strcpy_s(exits[7].name, "Simple way");
	strcpy_s(exits[7].description, "It is a room connector");
	exits[7].org = (rooms + 4);
	exits[7].dst = (rooms + 1);
	exits[7].direction = SOUTH;

	//FROM CORRIDOR 2 TO CELL 3

	strcpy_s(exits[8].name, "Very little corridor way");
	strcpy_s(exits[8].description, "Its is one of the 3 cells of the hospital");
	exits[8].org = (rooms + 4);
	exits[8].dst = (rooms + 5);
	exits[8].direction = WEST;

	//FROM CORRIDOR 2 TO INFIRMARY
	
	strcpy_s(exits[9].name, "Very little corridor way");
	strcpy_s(exits[9].description, "Only one at the hospital");
	exits[9].org = (rooms + 4);
	exits[9].dst = (rooms + 6);
	exits[9].direction = EAST;

	//FROM CORRIDOR 2 TO WC

	strcpy_s(exits[10].name, "Simple way");
	strcpy_s(exits[10].description, "Only for workers");
	exits[10].org = (rooms + 4);
	exits[10].dst = (rooms + 7);
	exits[10].direction = NORTH;

	//FROM CELL 3 TO CORRIDOR 2

	strcpy_s(exits[11].name, "Very little corridor way");
	strcpy_s(exits[11].description, "It is a room connector");
	exits[11].org = (rooms + 5);
	exits[11].dst = (rooms + 4);
	exits[11].direction = EAST;

	//FROM INFIRMARY TO CORRIDOR 2

	strcpy_s(exits[12].name, "Very little corridor way");
	strcpy_s(exits[12].description, "It is a room connector");
	exits[12].org = (rooms + 6);
	exits[12].dst = (rooms + 4);
	exits[12].direction = WEST;

	//FROM WC TO CORRIDOR 2

	strcpy_s(exits[13].name, "Simple way");
	strcpy_s(exits[13].description, "It is a room connector");
	exits[13].org = (rooms + 7);
	exits[13].dst = (rooms + 4);
	exits[13].direction = SOUTH;

	//FROM CELL 3 TO SECRET ROOM

	strcpy_s(exits[14].name, "Trap door way");
	strcpy_s(exits[14].description, "This is a secret door behind the bed to go secret room");
	exits[14].org = (rooms + 5);
	exits[14].dst = (rooms + 8);
	exits[14].direction = WEST;
	exits[14].door = true;
	exits[14].closed = true;

	//FROM SECRET ROOM TO CELL 3

	strcpy_s(exits[15].name, "Trap door way");
	strcpy_s(exits[15].description, "This is a door to access another time to the hospital");
	exits[15].org = (rooms + 8);
	exits[15].dst = (rooms + 5);
	exits[15].direction = EAST;

}

void World::Help() const
{
	printf("---------------WELCOME TO THE MENTAL HOSPITAL ZORK---------------\n");
	printf("You are the doctor of this hospital and you work very hard every journal day.\n");
	printf("In this moment you are in your office but the electricity of the hospital\n");
	printf("crashes, lights go out and doors are open\n");
	printf("Now you listen a lot of noises and the inmates walking around the hospital,\n");
	printf("you are a bit scared about the situation\n\n");
	printf("OBJECIVE: Try to escape from the hospital. NOTE: Emergency escape is locked,\n");
	printf("you have to find a secret way for escape\n\n");
	printf("-------------------MOVEMENTS AND INTERACTIONS:-------------------\n");
	printf("NORTH/SOUTH/EAST/WEST , N/S/E/W , Go North/Go South/Go East/Go West\n");
	printf("Look and then a movement for a description of the location\n");
	printf("Open door/close door to open or close it\n");
	printf("Help to re-establish this message\n");
	printf("Quit to quit/finish the game\n");
}


World::~World() //DESTRUCTOR, free memory
{
	delete[]player;
	delete[]exits;
	delete[]rooms;
}

