#pragma once
#include "Item.h"

class ItemDatabase
{

private:
	Item* itemDB[];
	//std::vector<Item*> itemDB;

public:
	ItemDatabase();
	~ItemDatabase();

	Item* getItem(int itemID);

};

//allows for readable reference to objects in itemDB
enum
{
	///////////////////
	//bronze items
	///////////////////
	bronzeOre = 0,
	bronzeDagger = 1,
	bronzeSword = 2,
	bronzeHelmet = 3,
	bronzePlateChest = 4,
	bronzePlateLegs = 5,
	bronzeBoots = 6

	///////////////////
	//iron items
	///////////////////

};

