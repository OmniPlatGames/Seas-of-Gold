#pragma once

#include "Unit.h"
#include "Ship.h"


class Player : public Unit
{
private:
	Ship *playerShip;
	//Skills *skillBook
	//Map *worldMap;
	//Mission *currentMission;

	// Current position on the map
	int CurrentPort;

public:
	Player() { playerShip = new Ship; }
	~Player() { delete playerShip; }

	void SetCurrentPort(int port);

	int GetCurrentPort();

	//Return Ship pointer
	Ship* getPlayerShip();

	//Returns the capacity of ship size
	//int getPlayerShipCrewMax();

	//Returns number of crew members
	//int getPlayerCrewSize();


	//bool playerCanCraft(int craftableID);
	//int getPlayerSkillLevel(int skillID);
	//Misison* getPlayerCurrentMission();
	//void playerAddMision(Mission& vendorMission)
};