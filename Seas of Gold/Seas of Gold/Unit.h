#pragma once

#include "WorldObject.h"
#include "Inventory.h"

class Unit : public WorldObject
{
	float fSpeed;
	int iGold;
	Inventory* inventory;


public:
	Unit();
	~Unit();

	//return pointer to unit's inventory
	inline Inventory* getInventory(){ return inventory; };

	//returns current gold
	int getGold() { return iGold; };

	//return number of items the unit has of itemID
	inline int unitHasItem(int itemID){ return inventory->qtyOfItem(itemID); };

	//displace unit
	void update(v3d dir, float dt);

	//add or subtract gold (never goes below 0). if i > gold, return difference but do not alter gold.
	int modifyGold(int i);

	void AddGold(int amnt);

	void RemoveGold(int amnt);
};

