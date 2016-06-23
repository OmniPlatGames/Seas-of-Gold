#include "Inventory.h"


Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

//returns the quantity of item that the entity has
int Inventory::qtyOfItem(int itemID)
{
	//find the item and return the quantity.
	for (InventorySlot* slots : inventory)
	{
		if (slots->item->getItemID() == itemID)
		{
			return slots->qty;
		}
	}
	//If item is not in inventory return 0
	return 0;
}

//adds items to the inventory for an entity
void Inventory::addItem(Item* item, int quantity)
{
	bool hasItem = false;

	//search inventory to see if we already have at least one of the item
	for (InventorySlot* slots : inventory)
	{
		//if we do, add to it's quantity
		if(slots->item->getItemID() == item->getItemID())
		{
			slots->qty += quantity;
			hasItem = true;
			break;
		}
	}
	//if we don't have the item already, create a new inventory slot containing the item
	if (hasItem == false)
	{
		InventorySlot newSlot;
		newSlot.item = item;
		newSlot.qty = quantity;
		inventory.push_back(&newSlot);
	}
}

//removes items from the inventory for an entity
void Inventory::removeItem(Item* item, int quantity)
{
	bool hasItem = false;

	//find the item in the inventory
	for (InventorySlot* slots : inventory)
	{
		//once found, remove the specified quantity
		if (slots->item->getItemID() == item->getItemID())
		{
			slots->qty -= quantity;
			//if no more of the item exists, remove from inventory
			if (slots->qty <= 0)
			{
				delete slots;
			}
			hasItem = true;
			break;
		}
	}

	//if item is not in inventory, then the call to this should have never been made.. throw an error
	if (hasItem == false)
	{
		MessageBox(NULL, "Item not in inventory! Error #1.", NULL, MB_OK);
	}
}