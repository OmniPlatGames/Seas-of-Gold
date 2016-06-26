#pragma once
#include "Common.h"
#include "LoadMap.h"

struct CostTable{
	int indiaBuy;
	int indiaSell;
	int africaBuy;
	int africaSell;
	int englandBuy;
	int englandSell;
	CostTable(int iB = 0, int iS = 0, int aB = 0, int aS = 0, int eB = 0, int eS = 0) : indiaBuy(iB), indiaSell(iS), africaBuy(iB), africaSell(iS), englandBuy(eB), englandSell(eS){};

	int getSellByMap(MapID map){
		switch (map){
		case Map_Africa:
			return africaSell;
		case Map_India:
			return indiaSell;
		case Map_England:
			return englandSell;
		default:
			return 0;
		}
	}

	int getBuyByMap(MapID map){
		switch (map){
		case Map_Africa:
			return africaBuy;
		case Map_India:
			return indiaBuy;
		case Map_England:
			return englandBuy;
		default:
			return 0;
		}
	}
};

class Item
{
public:
	int itemID;
	irrstring itemName;
	irrstring spriteLocation;
	CostTable cost;

public:

	Item();
	Item(int itemID, irrstring itemName, irrstring spriteLocation, CostTable cT);
	~Item();

	//returns ID of the item
	int getItemID();

	//returns item name
	irrstring getItemName();

	//load the sprite image
	void loadSprite(IVideoDriver *driver, v2d pos);

	//load the tool tip (future implementation)
	void loadToolTip(IVideoDriver *driver, v2d pos);

	bool operator == (Item item)
	{
		if (itemID == item.itemID)
		{
			return true;
		}
		return false;
	}

	bool operator != (Item item)
	{
		if (itemID != item.itemID)
		{
			return true;
		}
		return false;
	}

	int getPrice(bool sell, MapID map){
		if (sell)
			return cost.getSellByMap(map);
		else
			return cost.getBuyByMap(map);
	}

};

