#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}


int Inventory::hasItem(int itemID)
{
	for (Item* Item : items)
	{
		if (Item->ID == itemID)
		{
			return Item->quantity;
		}
	}
	return 0;
}

void Inventory::addItem(Item item)
{
	bool hasItem = false;

	for (Item* Item : items)
	{
		if (Item->ID == item.ID)
		{
			Item->quantity += item.quantity;
			hasItem = true;
			break;
		}
	}
	if (hasItem = false)
	{
		items.push_back(&item);
	}
}

void Inventory::removeItem(Item item)
{
	bool hasItem = false;

	for (Item* Item : items)
	{
		if (Item->ID == item.ID)
		{
			Item->quantity -= item.quantity;
			hasItem = true;
			break;
		}
	}
	if (hasItem = false)
	{
		MessageBox(NULL, "Item not in inventory! Fix checks.", NULL, MB_OK);
	}
}