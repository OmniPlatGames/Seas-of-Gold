#pragma once

#include "Common.h"

struct CSInputItems
{
	std::vector<irrstring> itemNames;
	std::vector<int> amnts;

	void AddItem(irrstring Name, int Amnt);
};

struct CSOutputItem
{
	irrstring Name;
	std::vector<irrstring> components;
	std::vector<int> amnts;
};

struct CSOutputItems
{
	std::vector<CSOutputItem> items;

	void AddItem(irrstring Name, std::vector<irrstring> Icomponents, std::vector<int> Amnt);
};


struct CraftableItem
{
	irrstring itemName;
	std::vector<irrstring> components;
	std::vector<int> amnts;
};

class CraftingSystem
{
public:
	CraftingSystem();
	CSOutputItems Craftables(CSInputItems ii);
private:
	std::vector<CraftableItem> CraftableItems;
};
