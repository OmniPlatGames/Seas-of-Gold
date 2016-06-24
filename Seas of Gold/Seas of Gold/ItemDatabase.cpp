#include "ItemDatabase.h"

//initialize all the items in the game here for easy reference throughout the rest of the program
ItemDatabase::ItemDatabase()
{
}


ItemDatabase::~ItemDatabase()
{

}

void ItemDatabase::Initialize()
{
	///////////////////
	// Bronze Items
	///////////////////
	itemDB[0] = Item(0, "Bronze Ore", "Sprites/Ore_Bronze.png");
	itemDB[1] = Item(1, "Bronze Dagger", "Sprites/Bronze_dagger.png");
	itemDB[2] = Item(2, "Bronze Sword", "Sprites/Bronze_Sword.png");
	itemDB[3] = Item(3, "Bronze Axe", "Sprites/Bronze_Axe.png");
	itemDB[4] = Item(4, "Bronze Helmet", "Sprites/Bronze_helmet.png");
	itemDB[5] = Item(5, "Bronze Plate Chest", "Sprites/Bronze_Chest.png");
	itemDB[6] = Item(6, "Bronze Plate Legs", "Sprites/Bronze_LegPlates.png");
	itemDB[7] = Item(7, "Bronze Boots", "Sprites/Bronze_Boots.png");

	///////////////////
	// Iron Items
	///////////////////
}

Item ItemDatabase::getItem(int itemID)
{
	return itemDB[itemID];

}