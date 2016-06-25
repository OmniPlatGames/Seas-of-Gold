#pragma once

#include "Common.h"
#include "Player.h"
#include "Input.h"
#include "Graphics.h"
#include "Button.h"
#include "ItemDatabase.h"
//#include "CraftingSystem.h"

class CraftingMenu
{
public:
	CraftingMenu(IrrlichtDevice* device,
		irr::video::IVideoDriver* driver, Player* player,
		ItemDatabase itemDB);

	//void SetPlayer(Player* p);

	bool Update(Input* in, int& frameCount, IrrlichtDevice* device);

	void Draw(irr::video::IVideoDriver* driver);

private:
	GraphicsImage exitButtonTex;
	GraphicsImage craftButtonTex;

	Button exitButton;
	Button craftButton;

	std::vector<Button> playerButtons;
	std::vector<Button> craftableButtons;
	v2d iconPos;
	v2d qtyPos;

	std::vector<InventorySlot> playerSelectedItems;
	std::vector<Item> craftSelectedItems;
	int selectedCraft;

	Player* player;

	irr::gui::IGUIFont* mfont;

	int playerSelectedItemsCount;
	int playerMaxSelectedCount;
	int craftSelectedItemsCount;
	int craftMaxSelectedCount;

	GraphicsImage background;

	void InitializeCraftables(ItemDatabase itemDB);
	Inventory bronzeCraftables;
	Inventory ironCraftables;
	Inventory obsidianCraftables;
	Inventory goldCraftables;

	//ItemDatabase itemDB;

	int incrX;
	int incrY;

	//used inplace of database until data curruption cause can be found TEMPORARY
	//bronze
	Item testBronzeOre;
	Item testBronzeDagger;
	Item testBronzeSword;
	Item testBronzeAxe;
	Item testBronzeHelmet;
	Item testBronzeChest;
	Item testBronzeLegs;
	Item testBronzeBoots;
	//iron
	Item testIronOre;
	Item testIronDagger;
	Item testIronSword;
	Item testIronAxe;
	Item testIronHelmet;
	Item testIronChest;
	Item testIronLegs;
	Item testIronBoots;
	//obsidian
	Item testCoalOre;
	Item testObsidianOre;
	Item testObsidianDagger;
	Item testObsidianSword;
	Item testObsidianAxe;
	Item testObsidianHelmet;
	Item testObsidianChest;
	Item testObsidianLegs;
	Item testObsidianBoots;
	//gold
	Item testGoldOre;
	Item testGoldHelmet;
	Item testGoldChest;
	Item testGoldLegs;
	Item testGoldBoots;
	
	bool testNewClick;

	void InitializeTestVariables();
};
