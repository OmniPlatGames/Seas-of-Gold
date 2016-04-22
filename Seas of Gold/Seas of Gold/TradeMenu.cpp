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

	SupplyCost = 10;
	CrewCost = 100;

	ModAmnt = 1;
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

	}

	if (BSellButton.isPressed(in))
	{

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
}