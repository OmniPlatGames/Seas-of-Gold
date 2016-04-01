#include "Unit.h"

Unit::Unit()
{
}


Unit::~Unit()
{
}


Inventory* Unit::getItems()
{
	return items;
}

int Unit::getGold()
{
	return gold;
}

int Unit::unitHasItem(int itemID)
{
	return items->hasItem(itemID);
}


void Unit::update(v3d dir, float dt)
{
	
	v3d direction = dir.normalize();
	v3d* currentLocation = getLocation();

	setLocation(*currentLocation + (direction * speed * dt));
}

int Unit::modifyGold(int i)
{
	if (i < gold)
	{
		gold += i;
		return 0;
	}
	else
	{
		return (gold - i);
	}
}