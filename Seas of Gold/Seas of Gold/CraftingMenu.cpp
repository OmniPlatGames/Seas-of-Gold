#include "CraftingMenu.h"

CraftingMenu::CraftingMenu(IrrlichtDevice* device,
	irr::video::IVideoDriver* driver)
{
	background = GraphicsImage(10, 10, 790, 590);
	background.SetTexture("Assets/hut.png", driver);

	mfont = device->getGUIEnvironment()->getBuiltInFont();

	LeftPannel = Button(50, 50, 390, 500);
	LeftPannel.SetFont(mfont);
	LeftPannel.SetText("");

	RightPannel = Button(410, 50, 750, 500);
	RightPannel.SetFont(mfont);
	RightPannel.SetText("");

	ExitButton = Button(750, 10, 790, 50);
	ExitButton.SetFont(mfont);
	ExitButton.SetText("x");

	LeftTitle = Button(50, 50, 390, 75);
	LeftTitle.SetFont(mfont);
	LeftTitle.SetText("Items");

	RightTitle = Button(410, 50, 750, 75);
	RightTitle.SetFont(mfont);
	RightTitle.SetText("Craftable");

	CraftButton = Button(350, 520, 450, 580);
	CraftButton.SetFont(mfont);
	CraftButton.SetText("Craft");


	for (int i = 0; i < 17; i++)
	{
		// Make Left
		Button nBut = Button(75, 75 + (25 * i), 365, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("");
		bItemList.push_back(nBut);

		// Left Amnt display
		nBut = Button(365, 75 + (25 * i), 390, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("");
		bItemListAmnt.push_back(nBut);

		// Make Right
		nBut = Button(435, 75 + (25 * i), 725, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("");
		bCraftList.push_back(nBut);

		// Right amnt display
		nBut = Button(725, 75 + (25 * i), 750, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("");
		bCraftListAmnt.push_back(nBut);
	}

	selectedCraft = -1;

	for (int i = 0; i < 17; i++)
	{
		SelectedItems[i] = false;
	}

	HasIron = false;
	HasBronze = true;
}

void CraftingMenu::SetPlayer(Player* p)
{
	mPlayer = p;
}

bool CraftingMenu::Update(Input* in)
{
	if (CraftButton.isPressed(in))
	{
		std::vector<Item*> items;

		Inventory* in = mPlayer->getItems();

		for (int i = 0; i < 17; i++)
		{
			if (SelectedItems[i])
			{
				items.push_back(in->items[i]);
			}
		}


		if (HasIron && HasBronze && (selectedCraft == 0))
		{
			Item* nItem = new Item("Bronze Sword", 1);

			mPlayer->getItems()->addItem(nItem);
		}

		for (int i = 0; i < 17; i++)
		{
			SelectedItems[i] = false;
		}

		selectedCraft = -1;
	}

	if (ExitButton.isPressed(in))
	{
		return true;
	}

	for (int i = 0; i < 17; i++)
	{
		if (bItemList[i].isPressed(in) && (bItemList[i].GetText() != ""))
		{
			SelectedItems[i] = !SelectedItems[i];
			break;
		}

		if (bCraftList[i].isPressed(in) && (bCraftList[i].GetText() != ""))
		{
			if (selectedCraft == i)
			{
				selectedCraft = -1;
				break;
			}
			else
			{
				selectedCraft = i;
				break;
			}
		}
	}

	for (int i = 0; i < 17; i++)
	{
		if (bItemList[i].GetText() == "Bronze Ore")
			HasBronze = true;
		if (bItemList[i].GetText() == "Iron Ore")
			HasIron = true;
	}

	UpdateContents();

	return false;
}

void CraftingMenu::Draw(irr::video::IVideoDriver* driver)
{
	LeftPannel.Draw(driver);
	RightPannel.Draw(driver);

	LeftTitle.Draw(driver);
	RightTitle.Draw(driver);

	for (int i = 0; i < 17; i++)
	{
		bItemList[i].Draw(driver);
		bItemListAmnt[i].Draw(driver);
		bCraftList[i].Draw(driver);
		bCraftListAmnt[i].Draw(driver);
	}

	ExitButton.Draw(driver);

	CraftButton.Draw(driver);
}

void CraftingMenu::UpdateContents()
{
	Inventory* in = mPlayer->getItems();

	for (int i = 0; i < 17; i++)
	{
		if (in->items.size() > i)
		{
			if (in->items[i]->getItemName() != "")
			{
				if (SelectedItems[i])
				{
					std::string str = in->items[i]->getItemName();
					bItemList[i].SetText(str.c_str());
					bItemList[i].SetColorFront(255, 255, 153, 255);
					bItemList[i].SetColorBack(0, 0, 0, 255);

					str = in->items[i]->getItemQty();
					bItemListAmnt[i].SetText(str.c_str());
					bItemListAmnt[i].SetColorFront(255, 255, 153, 255);
					bItemListAmnt[i].SetColorBack(0, 0, 0, 255);
				}
				else
				{
					std::string str = in->items[i]->getItemName();
					bItemList[i].SetText(str.c_str());
					bItemList[i].SetColorFront(255, 255, 255, 255);
					bItemList[i].SetColorBack(0, 0, 0, 255);

					str = in->items[i]->getItemQty();
					bItemListAmnt[i].SetText(str.c_str());
					bItemListAmnt[i].SetColorFront(255, 255, 255, 255);
					bItemListAmnt[i].SetColorBack(0, 0, 0, 255);
				}
			}
			else
			{
				bItemList[i].SetText("");
				bItemList[i].SetColorFront(0, 0, 0, 0);
				bItemList[i].SetColorBack(0, 0, 0, 0);

				bItemListAmnt[i].SetText("");
				bItemListAmnt[i].SetColorFront(0, 0, 0, 0);
				bItemListAmnt[i].SetColorBack(0, 0, 0, 0);
			}

		}
		
		if (bCraftList[i].GetText() != "")
		{
			if (selectedCraft == i)
			{
				// Get craftable objects and put it in.
				bCraftList[i].SetColorFront(255, 255, 153, 255);
				bCraftList[i].SetColorBack(0, 0, 0, 255);
			}
			else
			{
				// Get craftable object and put it in. 
				bCraftList[i].SetColorFront(255, 255, 255, 255);
				bCraftList[i].SetColorBack(0, 0, 0, 255);
			}
		}
		else
		{
			bCraftList[i].SetText("");
			bCraftList[i].SetColorFront(0, 0, 0, 0);
			bCraftList[i].SetColorBack(0, 0, 0, 0);

			bCraftListAmnt[i].SetText("");
			bCraftListAmnt[i].SetColorFront(0, 0, 0, 0);
			bCraftListAmnt[i].SetColorBack(0, 0, 0, 0);
		}

	}

	if (HasBronze && HasIron)
	{
		bCraftList[0].SetText("Bronze Sword");
	}
}