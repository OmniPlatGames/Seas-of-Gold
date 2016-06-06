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

		Inventory* in = mPlayer->getItems();

		CSOutputItem temp;

		for (int i = 0; i < 17; i++)
		{
			if (SelectedItems[i])
			{
				//items.push_back(in->items[i]);
				for (int j = 0; j < Citems.items.size(); j++)
				{
					if (Citems.items[j].Name == bCraftList[i].GetText())
					{
						temp = Citems.items[j];
						break;
					}
				}
				break;
			}
		}

		Item* nItem = new Item(temp.Name.c_str(), 1);
		in->addItem(nItem);

		for (int i = 0; i < temp.components.size(); i++)
		{
			for (int j = 0; j < in->items.size(); j++)
			{
				if (in->items[j]->getItemName() == temp.components[i].c_str())
				{
					in->items[j]->setItemQty(in->items[j]->getItemQty()
						- temp.amnts[i]);
					if (in->items[j]->getItemQty() <= 0)
					{
						in->items[j]->setItemQty(0);
						in->items.erase(in->items.begin() + j);
					}

					break;
				}
			}
		}

		
		

		/*if (HasIron && HasBronze && (selectedCraft == 0))
		{
			Item* nItem = new Item("Bronze Sword", 1);

			mPlayer->getItems()->addItem(nItem);
		}*/

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

	/*for (int i = 0; i < 17; i++)
	{
		if (bItemList[i].GetText() == "Bronze Ore")
			HasBronze = true;
		if (bItemList[i].GetText() == "Iron Ore")
			HasIron = true;
	}*/

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
					irrstring str = "";
					str = in->items[i]->getItemName().c_str();
					bItemList[i].SetText(str.c_str());
					bItemList[i].SetColorFront(255, 255, 153, 255);
					bItemList[i].SetColorBack(0, 0, 0, 255);

					str = "";
					str = std::to_string(in->items[i]->getItemQty()).c_str();
					bItemListAmnt[i].SetText(str.c_str());
					//bItemListAmnt[i].SetColorText(255, 255, 255, 255);
					bItemListAmnt[i].SetColorFront(255, 255, 153, 255);
					bItemListAmnt[i].SetColorBack(0, 0, 0, 255);
				}
				else
				{
					irrstring str = "";
					str += in->items[i]->getItemName().c_str();
					bItemList[i].SetText(str.c_str());
					bItemList[i].SetColorFront(255, 255, 255, 255);
					bItemList[i].SetColorBack(0, 0, 0, 255);

					str = "";
					str += std::to_string(in->items[i]->getItemQty()).c_str();
					bItemListAmnt[i].SetText(str.c_str());
					//bItemListAmnt[i].SetColorText(255, 255, 255, 255);
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
		else
		{
			bItemList[i].SetText("");
			bItemList[i].SetColorFront(0, 0, 0, 0);
			bItemList[i].SetColorBack(0, 0, 0, 0);

			bItemListAmnt[i].SetText("");
			bItemListAmnt[i].SetColorFront(0, 0, 0, 0);
			bItemListAmnt[i].SetColorBack(0, 0, 0, 0);
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

	CSInputItems csin;

	for (int i = 0; i < 17; i++)
	{
		if (SelectedItems[i])
		{
			for (int j = 0; j < in->items.size(); j++)
			{
				if (in->items[i]->getItemName() == bItemList[i].GetText().c_str())
				{
					csin.AddItem(in->items[i]->getItemName().c_str(), in->items[i]->getItemQty());
					break;
				}

			}
		}
	}

	Citems = CS.Craftables(csin);

	for (int i = 0; i < 17; i++)
	{
		if (i < Citems.items.size())
		{
			irrstring temp = Citems.items[i].Name;
			bCraftList[i].SetText(temp);
		}
		else
		{
			bCraftList[i].SetText("");
		}
	}

	/*if (HasBronze && HasIron)
	{
		bCraftList[0].SetText("Bronze Sword");
	}*/
}