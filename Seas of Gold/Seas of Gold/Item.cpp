#include "Item.h"



Item::Item(int item_ID, irrstring item_Name, irrstring sprite_Location)
{
	item_ID = itemID;
	item_Name = itemName;
	sprite_Location = spriteLocation;
}


Item::~Item()
{
}

//returns ID of the item
int Item::getItemID()
{
	return 0;
}

//returns item name
irrstring Item::getItemName()
{
	return itemName;
}


void Item::loadSprite(IVideoDriver *driver, v2d pos)
{
	io::path test = spriteLocation; //spriteName;
	video::ITexture* sprite = driver->getTexture(test);
	driver->draw2DImage(sprite, core::position2d<s32>(pos.X, pos.Y), core::rect<s32>(0, 0, 61, 61), 0, video::SColor(255, 255, 255, 255), true);
}