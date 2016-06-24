#pragma once
#include "Item.h"

class ItemDatabase
{

public:
	Item itemDB[8];
	//std::vector<Item*> itemDB;

public:
	ItemDatabase();
	~ItemDatabase();

	void Initialize();

	Item getItem(int itemID);

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
	bronzeAxe = 3,
	bronzeHelmet = 4,
	bronzePlateChest = 5,
	bronzePlateLegs = 6,
	bronzeBoots = 7

	///////////////////
	//iron items
	///////////////////

};

