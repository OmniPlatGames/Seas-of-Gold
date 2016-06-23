#pragma once
#include "Common.h"

class Item
{
private:
	int itemID;
	irrstring itemName;
	irrstring spriteLocation;

public:

	//items should only be created with an ID and a quantity
	Item(int itemID, irrstring itemName, irrstring spriteLocation);
	~Item();

	//returns ID of the item
	int getItemID();

	//returns item name
	irrstring getItemName();

	//load the sprite image
	void loadSprite(IVideoDriver *driver, v2d pos);

	Item& operator = (Item item)
	{
		itemID = item.itemID;
		itemName = item.itemName;
		spriteLocation = item.spriteLocation;
	}

};

