#include "ItemDatabase.h"

//initialize all the items in the game here for easy reference throughout the rest of the program
ItemDatabase::ItemDatabase()
{
}


ItemDatabase::~ItemDatabase()
{
	//delete[] &itemDB;

	delete itemDB[0];
	delete itemDB[1];
	delete itemDB[2];
	delete itemDB[3];
	delete itemDB[4];
	delete itemDB[5];
	delete itemDB[6];
	delete itemDB[7];
	//delete[]  itemDB;
}

void ItemDatabase::Initialize()
{
	///////////////////
	// Bronze Items
	///////////////////
	itemDB[0] = new Item(0, "Bronze Ore", "Sprites/Ore_Bronze.png");
	itemDB[1] = new Item(1, "Bronze Dagger", "Sprites/Bronze_dagger.png");
	itemDB[2] = new Item(2, "Bronze Sword", "Sprites/Bronze_Sword.png");
	itemDB[3] = new Item(3, "Bronze Axe", "Sprites/Bronze_Axe.png");
	itemDB[4] = new Item(4, "Bronze Helmet", "Sprites/Bronze_helmet.png");
	itemDB[5] = new Item(5, "Bronze Plate Chest", "Sprites/Bronze_Chest.png");
	itemDB[6] = new Item(6, "Bronze Plate Legs", "Sprites/Bronze_LegPlates.png");
	itemDB[7] = new Item(7, "Bronze Boots", "Sprites/Bronze_Boots.png");

	///////////////////
	// Iron Items
	///////////////////
}

Item* ItemDatabase::getItem(int itemID)
{
	return itemDB[itemID];

}