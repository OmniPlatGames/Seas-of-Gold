#include "TradeMenu.h"

TradeMenu::TradeMenu(IrrlichtDevice* device,
	irr::video::IVideoDriver* driver)
{
	mfont = device->getGUIEnvironment()->getBuiltInFont();

	background = GraphicsImage(50, 50, 750, 550);
	background.SetTexture("Assets/woodTex.png", driver);

	BuySuppliesButton = Button(200, 60, 600, 110);
	BuySuppliesButton.SetFont(mfont);
	BuySuppliesButton.SetText("Buy 10 Supplies : Cost 10g : Current X : Max Y");

	BuyCrewButton = Button(200, 130, 600, 180);
	BuyCrewButton.SetFont(mfont);
	BuyCrewButton.SetText("Buy 1 Crew : Cost 100g : Current X : Max Y");

	BExit = Button(700, 50, 750, 100);
	BExit.SetFont(mfont);
	BExit.SetText("x");

	GoldButton = Button(50, 50, 150, 100);
	GoldButton.SetFont(mfont);
	GoldButton.SetText("Gold: X");

	SupplyCost = 10;
	CrewCost = 100;
}

void TradeMenu::SetPlayer(Player* p)
{
	mPlayer = p;
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

	return false;
}

void TradeMenu::Draw(irr::video::IVideoDriver* driver)
{
	background.Draw(driver);
	BuySuppliesButton.Draw(driver);
	BuyCrewButton.Draw(driver);
	BExit.Draw(driver);
	GoldButton.Draw(driver);
}