#include "TradeMenu.h"

TradeMenu::TradeMenu(IrrlichtDevice* device,
	irr::video::IVideoDriver* driver)
{
	mfont = device->getGUIEnvironment()->getBuiltInFont();

	background = GraphicsImage(10, 10, 790, 590);
	background.SetTexture("Assets/woodTex.png", driver);

	BbgL = Button(50, 50, 390, 500);
	BbgL.SetFont(mfont);
	BbgL.SetText("");

	BbgR = Button(410, 50, 750, 500);
	BbgR.SetFont(mfont);
	BbgR.SetText("");

	BuySuppliesButton = Button(410, 512, 750, 540);
	BuySuppliesButton.SetFont(mfont);
	BuySuppliesButton.SetText("Buy 10 Supplies : Cost 10g : Current X : Max Y");

	BuyCrewButton = Button(410, 552, 750, 580);
	BuyCrewButton.SetFont(mfont);
	BuyCrewButton.SetText("Buy 1 Crew : Cost 100g : Current X : Max Y");

	BExit = Button(750, 10, 790, 50);
	BExit.SetFont(mfont);
	BExit.SetText("x");

	GoldButton = Button(20, 20, 110, 40);
	GoldButton.SetFont(mfont);
	GoldButton.SetText("Gold: X");

	BShopTitle = Button(50, 50, 390, 75);
	BShopTitle.SetFont(mfont);
	BShopTitle.SetText("Shop");

	BShipTitle = Button(410, 50, 750, 75);
	BShipTitle.SetFont(mfont);
	BShipTitle.SetText("Ship");

	BBuyButton = Button(50, 520, 160, 570);
	BBuyButton.SetFont(mfont);
	BBuyButton.SetText("Buy");

	BSellButton = Button(280, 520, 390, 570);
	BSellButton.SetFont(mfont);
	BSellButton.SetText("Sell");

	BamntDisp = Button(200, 530, 230, 560);
	BamntDisp.SetFont(mfont);
	BamntDisp.SetText("1");

	BamntUp = Button(230, 530, 245, 545);
	BamntUp.SetFont(mfont);
	BamntUp.SetText("+");

	BamntDown = Button(230, 545, 245, 560);
	BamntDown.SetFont(mfont);
	BamntDown.SetText("-");

	for (int i = 0; i < 17; i++)
	{
		// Make Left
		Button nBut = Button(75, 75 + (25 * i), 365, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("Empty");
		BBuyList.push_back(nBut);

		// Left Amnt display
		nBut = Button(365, 75 + (25 * i), 390, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("0");
		BBuyListAmnt.push_back(nBut);

		// Make Right
		nBut = Button(435, 75 + (25 * i), 725, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("Empty");
		BSellList.push_back(nBut);

		// Right amnt display
		nBut = Button(725, 75 + (25 * i), 750, 100 + (25 * i));
		nBut.SetFont(mfont);
		nBut.SetText("0");
		BSellListAmnt.push_back(nBut);
	}

	SupplyCost = 10;
	CrewCost = 100;

	ModAmnt = 1;

	SelectedItem = -1;
}

void TradeMenu::SetPlayer(Player* p)
{
	mPlayer = p;
	UpdateContents();
}

void TradeMenu::SetVendor(Vendor* v)
{
	mVendor = v;
	UpdateContents();
}

bool TradeMenu::Update(Input* in)
{
	Ship* curship = mPlayer->getPlayerShip();

	// Update Buy supplies Button
	irrstring str = "Buy 10 Supplies : Cost 10g : Current ";
	str += std::to_string(curship->GetSupplies()).c_str();
	str += " : Max ";
	str += std::to_string(curship->GetSupplyMax()).c_str();
	BuySuppliesButton.SetText(str);

	// Update Buy Crew Button
	str = "Buy 1 Crew : Cost 100g : Current ";
	str += std::to_string(curship->GetCrew()).c_str();
	str += " : Max ";
	str += std::to_string(curship->GetCrewMax()).c_str();
	BuyCrewButton.SetText(str);

	// Update Gold Button
	str = "Gold: ";
	str += std::to_string(mPlayer->getGold()).c_str();
	GoldButton.SetText(str);

	str = "";
	str += std::to_string(ModAmnt).c_str();
	BamntDisp.SetText(str);

	if (BuySuppliesButton.isPressed(in))
	{
		if (curship->GetSupplies() < curship->GetSupplyMax())
		{
			if (mPlayer->getGold() >= SupplyCost)
			{
				mPlayer->RemoveGold(SupplyCost);
				curship->AddSupplies(10);
			}
		}
	}

	if (BuyCrewButton.isPressed(in))
	{
		if (curship->GetCrew() < curship->GetCrewMax())
		{
			if (mPlayer->getGold() >= CrewCost)
			{
				mPlayer->RemoveGold(CrewCost);
				curship->AddCrew(1);
			}
		}
	}

	if (BExit.isPressed(in))
	{
		return true;
	}

	if (BBuyButton.isPressed(in))
	{
		if (SelectedItem < 16 && SelectedItem > -1)
		{
			Inventory* in = mVendor->getItems();
			int amnt = 0;

			for (int i = 0; i < in->items.size(); i++)
			{
				std::string str1 = in->items[i]->getItemName().c_str();
				std::string str2 = BBuyList[SelectedItem].GetText().c_str();
				if (str1 == str2)
				{
					if (ModAmnt * 5 <= mPlayer->getGold())
					{
						if (ModAmnt < in->items[i]->getItemQty())
						{
							Item* item = new Item(in->items[i]->getItemName(), ModAmnt);
							in->items[i]->setItemQty(in->items[i]->getItemQty() - ModAmnt);
							Inventory* pin = mPlayer->getItems();
							pin->addItem(item);

							// Need to implement a valid cost calc.
							mPlayer->RemoveGold(5 * ModAmnt);
						}
						else
						{
							Item* item = new Item(in->items[i]->getItemName(), in->items[i]->getItemQty());
							in->items[i]->setItemQty(0);
							Inventory* pin = mPlayer->getItems();
							pin->addItem(item);

							// Need to implement a valid cost calc.
							mPlayer->RemoveGold(5 * in->items[i]->getItemQty());
						}
					}
					break;
				}
			}
		}
		UpdateContents();
	}

	if (BSellButton.isPressed(in))
	{
		if (SelectedItem >= 16 && SelectedItem > -1)
		{
			Inventory* in = mPlayer->getItems();
			int amnt = 0;

			for (int i = 0; i < in->items.size(); i++)
			{
				std::string str1 = in->items[i]->getItemName().c_str();
				std::string str2 = BSellList[SelectedItem - 16].GetText().c_str();
				if (str1 == str2)
				{
					if (ModAmnt < in->items[i]->getItemQty())
					{
						Item* item = new Item(in->items[i]->getItemName(), ModAmnt);
						in->items[i]->setItemQty(in->items[i]->getItemQty() - ModAmnt);
						Inventory* pin = mVendor->getItems();
						pin->addItem(item);

						// Need to implement a valid cost calc.
						mPlayer->AddGold(5 * ModAmnt);
					}
					else
					{
						Item* item = new Item(in->items[i]->getItemName(), in->items[i]->getItemQty());
						in->items[i]->setItemQty(0);
						Inventory* pin = mVendor->getItems();
						pin->addItem(item);

						// Need to implement a valid cost calc.
						mPlayer->AddGold(5 * in->items[i]->getItemQty());
					}
					break;
				}
			}
		}
		UpdateContents();
	}

	if (BamntUp.isPressed(in))
	{
		ModAmnt++;
	}

	if (BamntDown.isPressed(in))
	{
		ModAmnt--;
		if (ModAmnt < 0)
			ModAmnt = 0;
	}

	for (int i = 0; i < BBuyList.size(); i++)
	{
		if (BBuyList[i].isPressed(in) && BBuyList[i].GetText() != "")
		{
			SelectedItem = i;
			bool selected = false;
			BBuyList[i].SetColorFront(255, 255, 153, 255);
			for (int j = 0; j < BBuyList.size(); j++)
			{
				if (j != i)
				{
					if (BBuyList[j].GetText() != "")
					{
						BBuyList[j].SetColorFront(255, 255, 115, 255);
					}
				}
			}
		}
	}

	for (int i = 0; i < BSellList.size(); i++)
	{
		if (BSellList[i].isPressed(in) && BSellList[i].GetText() != "")
		{
			SelectedItem = 16 + i;
			bool selected = false;
			BSellList[i].SetColorFront(255, 255, 153, 255);
			for (int j = 0; j < BSellList.size(); j++)
			{
				if (j != i)
				{
					if (BSellList[j].GetText() != "")
					{
						BSellList[j].SetColorFront(255, 255, 255, 255);
					}
				}
			}
		}
	}

	//UpdateContents();

	return false;
}

void TradeMenu::Draw(irr::video::IVideoDriver* driver)
{
	background.Draw(driver);
	BbgL.Draw(driver);
	BbgR.Draw(driver);
	BuySuppliesButton.Draw(driver);
	BuyCrewButton.Draw(driver);
	BExit.Draw(driver);
	GoldButton.Draw(driver);

	BShopTitle.Draw(driver);
	BShipTitle.Draw(driver);

	BBuyButton.Draw(driver);
	BSellButton.Draw(driver);

	BamntDisp.Draw(driver);
	BamntUp.Draw(driver);
	BamntDown.Draw(driver);

	for (int i = 0; i < BBuyList.size(); i++)
	{
		BBuyList[i].Draw(driver);
		BBuyListAmnt[i].Draw(driver);
		BSellList[i].Draw(driver);
		BSellListAmnt[i].Draw(driver);
	}
}

void TradeMenu::UpdateContents()
{
	if (mPlayer != NULL)
	{
		Inventory* in = mPlayer->getItems();

		int i = 0;
		if (in != NULL)
		{
			for (i; i < in->items.size(); i++)
			{
				// Update contents
				if (i >= 17)
					break;

				irrstring str = "";
				str += in->items[i]->getItemName().c_str();
				BSellList[i].SetText(str);
				BSellList[i].SetColorFront(255, 255, 255, 255);
				BSellList[i].SetColorBack(0, 0, 0, 255);

				str = "";
				str += std::to_string(in->items[i]->getItemQty()).c_str();
				BSellListAmnt[i].SetText(str);
				BSellListAmnt[i].SetColorFront(255, 255, 255, 255);
				BSellListAmnt[i].SetColorBack(0, 0, 0, 255);
			}
		}

		if (i < 17)
		{
			for (i; i < 17; i++)
			{
				BSellList[i].SetText("");
				BSellList[i].SetColorFront(255, 255, 255, 0);
				BSellList[i].SetColorBack(255, 255, 255, 0);
				BSellListAmnt[i].SetText("");
				BSellListAmnt[i].SetColorFront(255, 255, 255, 0);
				BSellListAmnt[i].SetColorBack(255, 255, 255, 0);
			}
		}
	}
	else
	{
		for (int i = 0; i < 17; i++)
		{
			BSellList[i].SetText("");
			BSellList[i].SetColorFront(255, 255, 255, 0);
			BSellList[i].SetColorBack(255, 255, 255, 0);
			BSellListAmnt[i].SetText("");
			BSellListAmnt[i].SetColorFront(255, 255, 255, 0);
			BSellListAmnt[i].SetColorBack(255, 255, 255, 0);
		}
	}

	if (mVendor != NULL)
	{
		Inventory* in = mVendor->getItems();
		int i = 0;
		if (in != NULL)
		{
			for (i; i < in->items.size(); i++)
			{
				// Update contents
				if (i >= 17)
					break;

				irrstring str = "";
				str += in->items[i]->getItemName().c_str();
				BBuyList[i].SetText(str);
				BBuyList[i].SetColorFront(255, 255, 255, 255);
				BBuyList[i].SetColorBack(0, 0, 0, 255);

				str = "";
				str += std::to_string(in->items[i]->getItemQty()).c_str();
				BBuyListAmnt[i].SetText(str);
				BBuyListAmnt[i].SetColorFront(255, 255, 255, 255);
				BBuyListAmnt[i].SetColorBack(0, 0, 0, 255);
			}
		}	

		if (i < 17)
		{
			for (i; i < 17; i++)
			{
				BBuyList[i].SetText("");
				BBuyList[i].SetColorFront(255, 255, 255, 0);
				BBuyList[i].SetColorBack(255, 255, 255, 0);
				BBuyListAmnt[i].SetText("");
				BBuyListAmnt[i].SetColorFront(255, 255, 255, 0);
				BBuyListAmnt[i].SetColorBack(255, 255, 255, 0);
			}
		}
	}
	else
	{
		for (int i = 0; i < 17; i++)
		{
			BBuyList[i].SetText("");
			BBuyList[i].SetColorFront(255, 255, 255, 0);
			BBuyList[i].SetColorBack(255, 255, 255, 0);
			BBuyListAmnt[i].SetText("");
			BBuyListAmnt[i].SetColorFront(255, 255, 255, 0);
			BBuyListAmnt[i].SetColorBack(255, 255, 255, 0);
		}
	}
}