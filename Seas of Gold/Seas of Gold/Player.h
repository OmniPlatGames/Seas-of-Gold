#pragma once

#include "Unit.h"
#include "Ship.h"
#include "Interface.h"

class Player : public Unit
{
private:
	Ship *playerShip;
	//Skills *skillBook
	//Map *worldMap;
	//Mission *currentMission;

	// Current position on the map
	int CurrentPort;
	bool plyrWalk;

	//unused variables, but needed to use player movement control function in IRRLICHT
	triangle3df triout;
	vector3df hitPos;
	bool falling;
	ISceneNode *outfalling;

	void movePlayer(IAnimatedMeshSceneNode* plyrNode, float dt, ISceneCollisionManager* collMan, ITriangleSelector* selector);

public:
	Player() { playerShip = new Ship; }
	~Player() { delete playerShip; }

	void SetCurrentPort(int port);

	int GetCurrentPort();

	//Return Ship pointer
	Ship* getPlayerShip();

	//loads the player
	IAnimatedMeshSceneNode* loadPlayerNode(IrrlichtDevice* device, ISceneManager* smgr);

	//update player
	void updatePlayer(IAnimatedMeshSceneNode* playerNode, float dt, ISceneCollisionManager* collMan, ITriangleSelector* selector);

	//Returns the capacity of ship size
	//int getPlayerShipCrewMax();

	//Returns number of crew members
	//int getPlayerCrewSize();


	//bool playerCanCraft(int craftableID);
	//int getPlayerSkillLevel(int skillID);
	//Misison* getPlayerCurrentMission();
	//void playerAddMision(Mission& vendorMission)
};