#include "Unit.h"



class Player : public Unit
{
private:
	//Ship *playerShip;
	//Skills *skillBook
	//Map *worldMap;
	//Mission *currentMission;

public:
	Player(){}
	~Player(){}

	//Return Ship pointer
	//Ship* getPlayerShip();

	//Returns the capacity of ship size
	int getPlayerShipCrewMax();

	//Returns number of crew members
	int getPlayerCrewSize();


	bool playerCanCraft(int craftableID);
	int getPlayerSkillLevel(int skillID);
	//Misison* getPlayerCurrentMission();
	//void playerAddMision(Mission& vendorMission)
};