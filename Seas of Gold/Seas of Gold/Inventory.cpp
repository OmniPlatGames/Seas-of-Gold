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
		if (Item->getItemID() == itemID)
		{
			return Item->getItemQty();
		}
	}
	return 0;
}

void Inventory::addItem(Item* item)
{
	bool hasItem = false;

	for (Item* Item : items)
	{
		//if (Item->getItemID() == item->getItemID())
		if(Item->getItemName() == item->getItemName())
		{
			Item->setItemQty(Item->getItemQty() + item->getItemQty());
			hasItem = true;
			break;
		}
	}
	if (hasItem == false)
	{
		items.push_back(item);
	}
}

void Inventory::removeItem(Item item)
{
	bool hasItem = false;

	for (Item* Item : items)
	{
		//if (Item->getItemID() == item.getItemID())
		if (Item->getItemName() == item.getItemName())
		{
			Item->setItemQty(Item->getItemQty() + item.getItemQty());
			hasItem = true;
			break;
		}
	}
	if (hasItem == false)
	{
		MessageBox(NULL, "Item not in inventory! Error #1.", NULL, MB_OK);
	}
}