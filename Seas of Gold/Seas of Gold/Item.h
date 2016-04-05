#pragma once
#include "Common.h"

class Item
{
private:
	std::string itemID;
	int quantity;
	std::string itemName;
	std::string spriteName;
	//irr::io::path spriteName;

public:

	//items should only be created with an ID and a quantity
	Item(std::string itemID, int quantity);
	~Item();

	//returns ID of the item
	int getItemID();

	//returns quantity of item
	int getItemQty();

	//sets item qty
	void setItemQty(int qty);

	//returns item name
	std::string getItemName();

	//return sprite name
	//std::string getItemSprite();

	//load the sprite image
	void loadSprite(IVideoDriver *driver, v2d pos);

};

