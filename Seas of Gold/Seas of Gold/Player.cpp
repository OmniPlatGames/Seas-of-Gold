#include "Player.h"

void Player::SetCurrentPort(int port)
{
	CurrentPort = port;
}

int Player::GetCurrentPort()
{
	return CurrentPort;
}

Ship* Player::getPlayerShip()
{
	return playerShip;
}

/*int Player::getPlayerShipCrewMax()
{
	return Ship::getCapacity();
}*/

/*int Player::getPlayerCrewSize()
{
	return Ship::getCrewSize();
}*/

/*bool Player::playerCanCraft(int craftableID)
{
	return Skills:canCraft(craftableID);
}*/

/*int Player::getPlayerSkillLevel(int skillID)
{
	return Skills::getSkillLevel(skillID);
}*/

/*Mission Player::*getPlayerCurrentMission()
{
	return currentMission;
}*/

