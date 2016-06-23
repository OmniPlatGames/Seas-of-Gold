#pragma once
#include "Common.h"

class Item
{
private:
	int itemID;
	irrstring itemName;
	irrstring spriteLocation;

public:

	Item(int itemID, irrstring itemName, irrstring spriteLocation);
	~Item();

	//returns ID of the item
	int getItemID();

	//returns item name
	irrstring getItemName();

	//load the sprite image
	void loadSprite(IVideoDriver *driver, v2d pos);

	//load the tool tip
	void loadToolTip(IVideoDriver *driver, v2d pos);

	Item& operator = (Item item)
	{
		itemID = item.itemID;
		itemName = item.itemName;
		spriteLocation = item.spriteLocation;
	}

};

