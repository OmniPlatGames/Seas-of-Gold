#include "Item.h"

Item::Item()
{
}

Item::Item(int item_ID, irrstring item_Name, irrstring sprite_Location)
{
	itemID = item_ID;
	itemName = item_Name;
	spriteLocation = sprite_Location;
}


Item::~Item()
{
}

//returns ID of the item
int Item::getItemID()
{
	return itemID;
}

//returns item name
irrstring Item::getItemName()
{
	return itemName;
}


void Item::loadSprite(IVideoDriver *driver, v2d pos)
{
	io::path loc = spriteLocation; //spriteName;
	video::ITexture* sprite = driver->getTexture(loc);
	driver->draw2DImage(sprite, position2d<s32>(pos.X, pos.Y), rect<s32>(0, 0, 32, 32), 0, SColor(255, 255, 255, 255), true);
}