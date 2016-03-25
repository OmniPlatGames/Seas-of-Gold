#pragma once
#include "WorldObject.h"
#include "Inventory.h"

class Unit : public WorldObject
{
	float speed;
	int gold;
	Inventory* items;


public:
	Unit();
	~Unit();

	//return pointer to unit's inventory
	Inventory* getItems();

	//returns current gold
	int getGold();

	//return number of items the unit has of itemID
	int unitHasItem(int itemID);

	//displace unit
	void update(v3d dir, float dt);

	//add or subtract gold (never goes below 0). if i > gold, return difference but do not alter gold.
	int modifyGold(int i);

};

