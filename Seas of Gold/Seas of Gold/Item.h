#pragma once
#include "Common.h"

class Item
{
public:
	int itemID;
	irrstring itemName;
	irrstring spriteLocation;

public:

	Item();
	Item(int itemID, irrstring itemName, irrstring spriteLocation);
	~Item();

	//returns ID of the item
	int getItemID();

	//returns item name
	irrstring getItemName();

	//load the sprite image
	void loadSprite(IVideoDriver *driver, v2d pos);

	//load the tool tip (future implementation)
	void loadToolTip(IVideoDriver *driver, v2d pos);

	bool operator == (Item item)
	{
		if (itemID == item.itemID)
		{
			return true;
		}
		return false;
	}

	bool operator != (Item item)
	{
		if (itemID != item.itemID)
		{
			return true;
		}
		return false;
	}

};

