#pragma once
#include "Item.h"
#include "Common.h"


class Inventory
{
private:
	std::vector<Item*> items;

public:
	Inventory();
	~Inventory();

	//return quantity of item ID
	int hasItem(int itemID);

	//add item to inventory
	void addItem(Item item);

	//remove item to inventory
	void removeItem(Item item);
};

