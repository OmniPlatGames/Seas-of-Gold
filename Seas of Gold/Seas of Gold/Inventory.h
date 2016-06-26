#pragma once
#include "ItemDatabase.h"
#include "Common.h"



//holds the item and how may of the item
struct InventorySlot
{
	Item item;
	int qty;

	bool operator == (InventorySlot test)
	{
		if (test.item.getItemID() == item.getItemID())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Inventory
{
public:
	std::vector<InventorySlot> inventory;

public:
	Inventory();
	~Inventory();

	//return quantity of item ID
	int qtyOfItem(int itemID);

	//add items to inventory
	void addItem(Item item, int quantity);

	//remove items inventory
	void removeItem(Item item, int quantity);

	//get number of slots in the inventory
	int getSize();

	//get item and it's qty from the inventory
	InventorySlot getItem(int itemSlot);
};

