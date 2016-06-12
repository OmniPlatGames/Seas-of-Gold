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

//loads the player and sets initial position
IAnimatedMeshSceneNode* Player::loadPlayerNode(IrrlichtDevice* device, ISceneManager* smgr) 
{
	IAnimatedMesh* player = smgr->getMesh("Assets/player.x");
	if (!player) { device->drop(); return NULL; }
	IAnimatedMeshSceneNode *plyrNode = smgr->addAnimatedMeshSceneNode(player);
	for (int i = 0; i < plyrNode->getMaterialCount(); i++)
	{
		plyrNode->getMaterial(i).NormalizeNormals = true;
	}
	plyrNode->setPosition(vector3df(5.0f, 0.1f, 5.0f));

	return plyrNode;
}

//update player information, including position and table activation
void Player::updatePlayer(IAnimatedMeshSceneNode* plyrNode, float dt, ISceneCollisionManager* collMan, ITriangleSelector* selector)
{
	movePlayer(plyrNode, dt, collMan, selector);

}

void Player::movePlayer(IAnimatedMeshSceneNode* plyrNode, float dt, ISceneCollisionManager* collMan, ITriangleSelector* selector)
{
	float plPos_x = 0.0f;
	float plPos_y = 0.0f;
	float plPos_z = 0.0f;

	///// Movement control! ///////////
	bool movetest = false;

	if (GetAsyncKeyState(0x57)) //W key move forward
	{
		plPos_z = -(dt * 10) * (cos((plyrNode->getRotation().Y)*PI / 180));
		plPos_x = -(dt * 10) * (sin((plyrNode->getRotation().Y)*PI / 180));
		movetest = true;
		if (!plyrWalk)
		{
			plyrNode->setFrameLoop(40, 90);
			plyrNode->setAnimationSpeed(30);
			plyrWalk = true;
		}
	}
	if (GetAsyncKeyState(0x53)) //S key move backwards
	{
		plPos_z = dt * (cos((plyrNode->getRotation().Y)*PI / 180));
		plPos_x = dt * (sin((plyrNode->getRotation().Y)*PI / 180));
		movetest = true;
		if (!plyrWalk)
		{
			plyrNode->setFrameLoop(40, 90);
			plyrNode->setAnimationSpeed(-30);
			plyrWalk = true;
		}
	}
	if (GetAsyncKeyState(0x44)) // D key strafe right
	{
		plPos_z = dt * (sin((plyrNode->getRotation().Y)*PI / 180));
		plPos_x = -dt * (cos((plyrNode->getRotation().Y)*PI / 180));
		movetest = true;

	}
	if (GetAsyncKeyState(0x41)) // A key strafe left
	{
		plPos_z = -dt * (sin((plyrNode->getRotation().Y)*PI / 180));
		plPos_x = dt * (cos((plyrNode->getRotation().Y)*PI / 180));
		movetest = true;

	}
	//if(!plyrWalk)
	if (!movetest)
	{
		plyrNode->setFrameLoop(10, 30);
		plyrWalk = false;
	}

	vector3df plPos = vector3df(plPos_x, plPos_y, plPos_z);

	//controls player's movement
	plyrNode->setPosition(collMan->getCollisionResultPosition(selector, plyrNode->getPosition(), core::vector3df(0.01f, 0.01f, 0.01f), plPos, triout, hitPos, falling, outfalling, 0.0f, vector3df(0.0f, -0.05f, 0.0f)));

	////// End Movement Control ////////////
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

