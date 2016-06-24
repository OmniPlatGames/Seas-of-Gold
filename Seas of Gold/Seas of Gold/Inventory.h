#pragma once
#include "ItemDatabase.h"
#include "Common.h"

//holds the item and how may of the item

class Inventory
{
private:
	struct InventorySlot
	{
		Item* item;
		int qty;
	}; 

public:
	std::vector<InventorySlot> inventory;

public:
	Inventory();
	~Inventory();

	//return quantity of item ID
	int qtyOfItem(int itemID);

	//add items to inventory
	void addItem(Item* item, int quantity);

	//remove items inventory
	void removeItem(Item* item, int quantity);
};

