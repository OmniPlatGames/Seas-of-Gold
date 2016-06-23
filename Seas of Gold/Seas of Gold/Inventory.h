#pragma once
#include "Item.h"
#include "Common.h"

//holds the item and how may of the item
struct items
{
	Item* item;
	int qty;
};


class Inventory
{

public:
	std::vector<Item*> inventory;

public:
	Inventory();
	~Inventory();

	//return quantity of item ID
	int hasItem(int itemID);

	//add item to inventory
	void addItem(Item* item);

	//remove item to inventory
	void removeItem(Item item);
};

