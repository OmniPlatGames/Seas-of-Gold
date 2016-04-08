#include "Item.h"



Item::Item(std::string ItemID, int Quantity)
{
	itemID = ItemID;
	quantity = Quantity;

	int testID;
	bool test = false;

	std::ifstream data("book1.csv");
	std::string cell;
	
	while (data.good())
	{
		getline(data, cell, ',');
		if (cell == itemID)
		{
			getline(data, cell, ',');
			itemName = cell;
			getline(data, cell, ',');
			spriteName = std::string(cell, 0, cell.length()-2);
			test = true;
			break;
		}
	}

	if (!test)
	{
		MessageBox(NULL, "Item not in file! Error #3.", NULL, MB_OK);
	}
}


Item::~Item()
{
}

//returns ID of the item
int Item::getItemID()
{
	return 0;
}

//returns quantity of item
int Item::getItemQty()
{
	return quantity;
}

void Item::setItemQty(int qty)
{
	quantity = qty;
}

//returns item name
std::string Item::getItemName()
{
	return itemName;
}

/*/return sprite name
/*std::string irr::io::path Item::getItemSprite()
{
	return spriteName;
}*/

void Item::loadSprite(IVideoDriver *driver, v2d pos)
{
	io::path test = "../Seas of Gold/Sprites/Ore_Bronze.png"; //spriteName;
	video::ITexture* sprite = driver->getTexture(test);
	driver->draw2DImage(sprite, core::position2d<s32>(pos.X, pos.Y), core::rect<s32>(0, 0, 61, 61), 0, video::SColor(255, 255, 255, 255), true);
}