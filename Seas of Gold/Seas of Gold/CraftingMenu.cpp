#include "CraftingMenu.h"

CraftingMenu::CraftingMenu(IrrlichtDevice* device,
	irr::video::IVideoDriver* driver, Player* p,  ItemDatabase itemDB)
{
	itemDB.Initialize();

	player = p;

	background = GraphicsImage(10, 10, 790, 500);
	background.SetTexture("Assets/craftmenu.png", driver);

	exitButtonTex = GraphicsImage(720, 36, 752, 68);
	exitButtonTex.SetTexture("Assets/X.png", driver);

	craftButtonTex = GraphicsImage(350, 480, 478, 544);
	craftButtonTex.SetTexture("Assets/craft.png", driver);

	exitButton = Button(exitButtonTex, device);
	craftButton = Button(craftButtonTex, device);

	mfont = device->getGUIEnvironment()->getBuiltInFont();

	playerSelectedItemsCount = 0;
	playerMaxSelectedCount = 2;
	craftSelectedItemsCount = 0;
	craftMaxSelectedCount = 1;

	playerButtons.clear();
	craftableButtons.clear();
	playerSelectedItems.clear();
	craftSelectedItems.clear();

	bool testNewClick = true;

	incrX = 0;
	incrY = 0;
	InventorySlot iSlot;

	//setup the player's inventory
	for (int i = 0; i < player->getInventory()->getSize(); i++)
	{
		//get positions the icons need to be at
		incrX = i;
		if (incrX > 8)
		{
			incrX = 0;
			incrY += 1;
		}
		iconPos = v2d(66 + (incrX * 40), 109 + (incrY * 40));
		qtyPos = v2d(90 + (incrX * 40), 133 + (incrY * 40));

		//create the button and draw it
		playerButtons.push_back(Button(player->getInventory()->getItem(i), iconPos, qtyPos, device));

	}

	//set up craftables
	InitializeCraftables(itemDB);

	//temp
	InitializeTestVariables();
	
}


bool CraftingMenu::Update(Input* in, int& frameCount, IrrlichtDevice* device)
{
	//if left mouse button is pressed, and we haven't reach max selected items, find out if an icon was clicked
	//player items
	if (in->IsMBDown(0) && (playerSelectedItemsCount < playerMaxSelectedCount))
	{
		for (int i = 0; i < playerButtons.size(); i++)
		{
			playerButtons[i].Select(in, frameCount, playerSelectedItemsCount);
			testNewClick = true;
		}
	}
	//craft items
	if (in->IsMBDown(0) && (craftSelectedItemsCount < craftMaxSelectedCount))
	{
		for (int i = 0; i < craftableButtons.size(); i++)
		{
			craftableButtons[i].Select(in, frameCount, craftSelectedItemsCount);
			testNewClick = true;
		}
	}

	//if left mouse button is pressed, but we reached our max selected items, only find out if a selected icon was clicked
	if (in->IsMBDown(0) && (playerSelectedItemsCount >= playerMaxSelectedCount))
	{
		for (int i = 0; i < playerButtons.size(); i++)
		{
			if (playerButtons[i].isSelected())
			{
				playerButtons[i].Select(in, frameCount, playerSelectedItemsCount);
				testNewClick = true;
			}
		}
	}
	//craft items
	if (in->IsMBDown(0) && (craftSelectedItemsCount >= craftMaxSelectedCount))
	{
		for (int i = 0; i < craftableButtons.size(); i++)
		{
			if (craftableButtons[i].isSelected())
			{
				craftableButtons[i].Select(in, frameCount, craftSelectedItemsCount);
				testNewClick = true;
			}
		}
	}

	//reset selected items vector, player side
	playerSelectedItems.clear();
	for (int i = 0; i < player->getInventory()->getSize(); i++)
	{
		if (playerButtons[i].isSelected())
		{
			InventorySlot newSlot;
			newSlot.item = playerButtons[i].getItem();
			newSlot.qty = playerButtons[i].getQty();
			playerSelectedItems.push_back(newSlot);
		}
	}

	//reset selected items vector, crafted side
	craftSelectedItems.clear();
	if (craftableButtons.size() > 0)
	{
		for (int i = 0; i < craftableButtons.size(); i++)
		{
			if (craftableButtons[i].isSelected())
			{
				craftSelectedItems.push_back(craftableButtons[i].getItem());
			}
		}
	}

	//find if a raw goods are selected, if yes, then draw blueprints, if not, clear blueprint
	if (playerSelectedItems.size() == 0)
	{
		craftSelectedItemsCount = 0;
		craftableButtons.clear();

	}
	if (playerSelectedItems.size() == 1)
	{
		if (playerSelectedItems[0].item == testBronzeOre && testNewClick)
		{
			for (int i = 0; i < bronzeCraftables.getSize(); i++)
			{
				//get positions the icons need to be at
				incrX = i;
				if (incrX > 8)
				{
					incrX = 0;
					incrY += 1;
				}
				iconPos = v2d(430 + (incrX * 40), 109 + (incrY * 40));
				qtyPos = v2d(454 + (incrX * 40), 133 + (incrY * 40));

				//create the button and draw it
				craftableButtons.push_back(Button(bronzeCraftables.getItem(i), iconPos, qtyPos, device));
				testNewClick = false;

			}
		}
		else if (playerSelectedItems[0].item == testIronOre && testNewClick)
		{
			for (int i = 0; i < ironCraftables.getSize(); i++)
			{
				//get positions the icons need to be at
				incrX = i;
				if (incrX > 8)
				{
					incrX = 0;
					incrY += 1;
				}
				iconPos = v2d(430 + (incrX * 40), 109 + (incrY * 40));
				qtyPos = v2d(454 + (incrX * 40), 133 + (incrY * 40));

				//create the button and draw it
				craftableButtons.push_back(Button(ironCraftables.getItem(i), iconPos, qtyPos, device));
				testNewClick = false;
			}
		}
		else if (playerSelectedItems[0].item == testGoldOre && testNewClick)
		{
			for (int i = 0; i < goldCraftables.getSize(); i++)
			{
				//get positions the icons need to be at
				incrX = i;
				if (incrX > 8)
				{
					incrX = 0;
					incrY += 1;
				}
				iconPos = v2d(430 + (incrX * 40), 109 + (incrY * 40));
				qtyPos = v2d(454 + (incrX * 40), 133 + (incrY * 40));

				//create the button and draw it
				craftableButtons.push_back(Button(goldCraftables.getItem(i), iconPos, qtyPos, device));
				testNewClick = false;
			}
		}

	}
	else if (playerSelectedItems.size() == 2)
	{
		if ((playerSelectedItems[0].item != testBronzeOre) || (playerSelectedItems[1].item != testBronzeOre)
			|| (playerSelectedItems[0].item != testIronOre) || (playerSelectedItems[1].item != testIronOre)
			|| (playerSelectedItems[0].item != testObsidianOre) || (playerSelectedItems[1].item != testObsidianOre))
		{
			craftableButtons.clear();
			craftSelectedItemsCount = 0;
		}

		//TODO
		/*if ((playerSelectedItems[0].item == itemDB.getItem(coalOre) || playerSelectedItems[0].item == testObsidianOre) &&
			(playerSelectedItems[1].item == testObsidianOre || playerSelectedItems[1].item == itemDB.getItem(coalOre)))
		{
			for (int i = 0; i < obsidianCraftables.getSize(); i++)
			{

			}
		}*/
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//   BEGIN CRAFTING MEHEM!
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//craft items (economics needed)
	if(in->IsMBDown(0) && craftButton.isPressed(in, frameCount))
	{
		for (int i = 0; i < craftableButtons.size(); i++)
		{
			if (craftableButtons[i].isSelected())
			{
				//craft daggers (cost 2 ore)
				if ((craftableButtons[i].getItem() == testBronzeDagger)
					|| (craftableButtons[i].getItem() == testIronDagger)
					&& playerSelectedItems[0].qty >= 2)
				{
					for (int j = 0; j < player->getInventory()->getSize(); j++)
					{
						if (player->getInventory()->getItem(j) == playerSelectedItems[0])
						{
							player->getInventory()->removeItem(playerSelectedItems[0].item, 2);
							player->getInventory()->addItem(craftableButtons[i].getItem(), 1);
						}
					}
				}
				//craft axes (Future add: add wood requirement) (cost 2 ore)
				if ((craftableButtons[i].getItem() == testBronzeAxe)
					|| (craftableButtons[i].getItem() == testIronAxe)
					&& playerSelectedItems[0].qty >= 2)
				{
					for (int j = 0; j < player->getInventory()->getSize(); j++)
					{
						if (player->getInventory()->getItem(j) == playerSelectedItems[0])
						{
							player->getInventory()->removeItem(playerSelectedItems[0].item, 2);
							player->getInventory()->addItem(craftableButtons[i].getItem(), 1);
						}
					}
				}
				//craft swords (cost 5 ore)
				if ((craftableButtons[i].getItem() == testBronzeSword)
					|| (craftableButtons[i].getItem() == testIronSword)
					&& playerSelectedItems[0].qty >= 5)
				{
					for (int j = 0; j < player->getInventory()->getSize(); j++)
					{
						if (player->getInventory()->getItem(j) == playerSelectedItems[0])
						{
							player->getInventory()->removeItem(playerSelectedItems[0].item, 5);
							player->getInventory()->addItem(craftableButtons[i].getItem(), 1);
						}
					}
				}
				//craft helmets (cost 3 ore)
				if ((craftableButtons[i].getItem() == testBronzeHelmet)
					|| (craftableButtons[i].getItem() == testIronHelmet)
					|| (craftableButtons[i].getItem() == testGoldHelmet)
					&& playerSelectedItems[0].qty >= 2)
				{
					for (int j = 0; j < player->getInventory()->getSize(); j++)
					{
						if (player->getInventory()->getItem(j) == playerSelectedItems[0])
						{
							player->getInventory()->removeItem(playerSelectedItems[0].item, 3);
							player->getInventory()->addItem(craftableButtons[i].getItem(), 1);
						}
					}
				}
				//craft chestplates (cost 10 ore)
				if ((craftableButtons[i].getItem() == testBronzeChest)
					|| (craftableButtons[i].getItem() == testIronChest)
					|| (craftableButtons[i].getItem() == testGoldChest)
					&& playerSelectedItems[0].qty >= 2)
				{
					for (int j = 0; j < player->getInventory()->getSize(); j++)
					{
						if (player->getInventory()->getItem(j) == playerSelectedItems[0])
						{
							player->getInventory()->removeItem(playerSelectedItems[0].item, 10);
							player->getInventory()->addItem(craftableButtons[i].getItem(), 1);
						}
					}
				}
				//craft legPlates (cost 7 ore)
				if ((craftableButtons[i].getItem() == testBronzeLegs)
					|| (craftableButtons[i].getItem() == testIronLegs)
					|| (craftableButtons[i].getItem() == testGoldLegs)
					&& playerSelectedItems[0].qty >= 2)
				{
					for (int j = 0; j < player->getInventory()->getSize(); j++)
					{
						if (player->getInventory()->getItem(j) == playerSelectedItems[0])
						{
							player->getInventory()->removeItem(playerSelectedItems[0].item, 7);
							player->getInventory()->addItem(craftableButtons[i].getItem(), 1);
						}
					}
				}
				//craft boots (costs 1 ore)
				if ((craftableButtons[i].getItem() == testBronzeBoots)
					|| (craftableButtons[i].getItem() == testIronBoots)
					|| (craftableButtons[i].getItem() == testGoldBoots)
					&& playerSelectedItems[0].qty >= 2)
				{
					for (int j = 0; j < player->getInventory()->getSize(); j++)
					{
						if (player->getInventory()->getItem(j) == playerSelectedItems[0])
						{
							player->getInventory()->removeItem(playerSelectedItems[0].item, 1);
							player->getInventory()->addItem(craftableButtons[i].getItem(), 1);
						}
					}
				}

				craftableButtons.clear();
				//refresh player buttons after items are crafted
				craftSelectedItemsCount = 0;
				playerSelectedItemsCount = 0;
				playerButtons.clear();
				for (int i = 0; i < player->getInventory()->getSize(); i++)
				{
					//get positions the icons need to be at
					incrX = i;
					if (incrX > 8)
					{
						incrX = 0;
						incrY += 1;
					}
					iconPos = v2d(66 + (incrX * 40), 109 + (incrY * 40));
					qtyPos = v2d(90 + (incrX * 40), 133 + (incrY * 40));

					//create the button and draw it
					playerButtons.push_back(Button(player->getInventory()->getItem(i), iconPos, qtyPos, device));

				}
			}
		}//end for loop for craftable buttons
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//   END CRAFTING MEHEM!
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (in->IsMBDown(0) && exitButton.isPressed(in, frameCount))
	{
		return true;
	}

	return false;
}

void CraftingMenu::Draw(irr::video::IVideoDriver* driver)
{
	background.Draw(driver);
	exitButton.Draw(driver);
	craftButton.Draw(driver);

	for (int i = 0; i < playerButtons.size(); i++)
	{
		playerButtons[i].Draw(driver);
	}

	for (int i = 0; i < craftableButtons.size(); i++)
	{
		craftableButtons[i].Draw(driver);
	}
}

void CraftingMenu::InitializeCraftables(ItemDatabase itemDB)
{
	//use qty to indicate number of ore required 
	//set up bronze craftable items
	bronzeCraftables.addItem(itemDB.getItem(bronzeDagger), 2);
	bronzeCraftables.addItem(itemDB.getItem(bronzeAxe), 2);
	bronzeCraftables.addItem(itemDB.getItem(bronzeSword), 5);
	bronzeCraftables.addItem(itemDB.getItem(bronzeHelmet), 3);
	bronzeCraftables.addItem(itemDB.getItem(bronzeChest), 10);
	bronzeCraftables.addItem(itemDB.getItem(bronzePlateLegs), 7);
	bronzeCraftables.addItem(itemDB.getItem(bronzeBoots), 1);

	//set up iron craftable items
	ironCraftables.addItem(itemDB.getItem(ironDagger), 2);
	ironCraftables.addItem(itemDB.getItem(ironAxe), 2);
	ironCraftables.addItem(itemDB.getItem(ironSword), 5);
	ironCraftables.addItem(itemDB.getItem(ironHelmet), 3);
	ironCraftables.addItem(itemDB.getItem(ironChest), 10);
	ironCraftables.addItem(itemDB.getItem(ironPlateLegs),71);
	ironCraftables.addItem(itemDB.getItem(ironBoots), 1);

	//set up obsidion craftable items
	obsidianCraftables.addItem(itemDB.getItem(obsidianDagger), 2);
	obsidianCraftables.addItem(itemDB.getItem(obsidianAxe), 2);
	obsidianCraftables.addItem(itemDB.getItem(obsidianSword), 5);
	obsidianCraftables.addItem(itemDB.getItem(obsidianHelmet), 3);
	obsidianCraftables.addItem(itemDB.getItem(obsidianChest), 10);
	obsidianCraftables.addItem(itemDB.getItem(obsidianPlateLegs), 7);
	obsidianCraftables.addItem(itemDB.getItem(obsidianBoots), 1);

	//set up gold craftable items
	goldCraftables.addItem(itemDB.getItem(goldHelmet), 3);
	goldCraftables.addItem(itemDB.getItem(goldChest), 10);
	goldCraftables.addItem(itemDB.getItem(goldPlateLegs), 7);
	goldCraftables.addItem(itemDB.getItem(goldBoots), 1);
}

void CraftingMenu::InitializeTestVariables()
{
	//////////////////
	//Bronze Items
	//////////////////
	testBronzeOre = Item(0, "Bronze Ore", "Sprites/Ore_Bronze.png", CostTable(238, 119, 214, 107, 286, 143));
	testBronzeDagger = Item(1, "Bronze Dagger", "Sprites/Bronze_dagger.png", CostTable(476, 238, 428, 214, 571, 286));
	testBronzeSword = Item(2, "Bronze Sword", "Sprites/Bronze_Sword.png", CostTable(952, 476, 857, 428, 1142, 571));
	testBronzeAxe = Item(3, "Bronze Axe", "Sprites/Bronze_Axe.png", CostTable(1190, 595, 1071, 536, 1428, 714));
	testBronzeHelmet = Item(4, "Bronze Helmet", "Sprites/Bronze_helmet.png", CostTable(595, 297, 536, 268, 714, 357));
	testBronzeChest = Item(5, "Bronze Chest", "Sprites/Bronze_Chest.png", CostTable(1666, 833, 1499, 750, 1999, 1000));
	testBronzeLegs = Item(6, "Bronze Plate Legs", "Sprites/Bronze_LegPlates.png", CostTable(595, 297, 536, 268, 714, 357));
	testBronzeBoots = Item(7, "Bronze Boots", "Sprites/Bronze_Boots.png", CostTable(714, 357, 643, 321, 857, 428));

	//////////////////
	//Iron Items
	//////////////////
	testIronOre = Item(8, "Iron Ore", "Sprites/Ore_Iron.png", CostTable(124, 62, 112, 56, 149, 74));
	testIronDagger = Item(9, "Iron Dagger", "Sprites/Iron_dagger.png", CostTable(248, 124, 223, 112, 298, 149));
	testIronSword = Item(10, "Iron Sword", "Sprites/Iron_Sword.png", CostTable(496, 248, 446, 223, 595, 298));
	testIronAxe = Item(11, "Iron Axe", "Sprites/Iron_Axe.png", CostTable(620, 310, 558, 279, 744, 372));
	testIronHelmet = Item(12, "Iron Helmet", "Sprites/Iron_helmet.png", CostTable(310, 155, 279, 140, 372, 186));
	testIronChest = Item(13, "Iron Chest", "Sprites/Iron_Chest.png", CostTable(868, 434, 781, 391, 1042, 521));
	testIronLegs = Item(14, "Iron Plate Legs", "Sprites/Iron_LegPlates.png", CostTable(310, 155, 279, 140, 372, 186));
	testIronBoots = Item(15, "Iron Boots", "Sprites/Iron_Boots.png", CostTable(372, 186, 335, 167, 446, 223));

	//////////////////
	//Obsidian Items
	//////////////////
	testCoalOre = Item(16, "Coal Ore", "Sprites/Ore_Coal.png", CostTable(53, 26, 48, 24, 64, 32));
	testObsidianOre = Item(17, "Obsidian Ore", "Sprites/Ore_Obsidian.png", CostTable(738, 369, 664, 332, 886, 443));
	testObsidianDagger = Item(18, "Obsidian Dagger", "Sprites/Obsidian_dagger.png", CostTable(1476, 738, 1328, 664, 1771, 886));
	testObsidianSword = Item(19, "Obsidian Sword", "Sprites/Obsidian_Sword.png", CostTable(2952, 1476, 2657, 1328, 3542, 1771));
	testObsidianAxe = Item(20, "Obsidian Axe", "Sprites/Obsidian_Axe.png", CostTable(3690, 1845, 3321, 1661, 4428, 2214));
	testObsidianHelmet = Item(21, "Obsidian Helmet", "Sprites/Obsidian_helmet.png", CostTable(1845, 922, 1661, 830, 2214, 1107));
	testObsidianChest = Item(22, "Obsidian Chest", "Sprites/Obsidian_Chest.png", CostTable(5166, 2583, 4649, 2325, 6199, 3100));
	testObsidianLegs = Item(23, "Obsidian Plate Legs", "Sprites/Obsidian_LegPlates.png", CostTable(1845, 922, 1661, 830, 2214, 1107));
	testObsidianBoots = Item(24, "Obsidian Boots", "Sprites/Obsidian_Boots.png", CostTable(2214, 1107, 1993, 996, 2657, 1328));

	//////////////////
	//Gold Items
	//////////////////
	testGoldOre = Item(25, "Gold Ore", "Sprites/Ore_Gold.png", CostTable(418, 209, 376, 188, 502, 251));
	testGoldHelmet = Item(26, "Gold Helmet", "Sprites/Gold_helmet.png", CostTable(1045, 522, 941, 470, 1254, 627));
	testGoldChest = Item(27, "Gold Chest", "Sprites/Gold_Chest.png", CostTable(2926, 1463, 2633, 1317, 3511, 1756));
	testGoldLegs = Item(28, "Gold Plate Legs", "Sprites/Gold_LegPlates.png", CostTable(1045, 522, 941, 470, 1254, 627));
	testGoldBoots = Item(29, "Gold Boots", "Sprites/Gold_Boots.png", CostTable(1254, 627, 1129, 564, 1505, 752));
}