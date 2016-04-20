#include "MapMenu.h"

MapMenu::MapMenu(IrrlichtDevice* device, irr::video::IVideoDriver* driver)
{
	background = GraphicsImage(0, 0, 800, 600);
	background.SetTexture("Assets/Dani-Map.png", driver);

	mfont = device->getGUIEnvironment()->getBuiltInFont();

	BDestN = Button(240, 250, 340, 300);
	BDestN.SetFont(mfont);
	BDestN.SetText("Northtown : 100 Supplies");

	BDestS = Button(350, 520, 450, 570);
	BDestS.SetFont(mfont);
	BDestS.SetText("Southtown : 50 Supplies");

	BDestE = Button(600, 420, 700, 470);
	BDestE.SetFont(mfont);
	BDestE.SetText("Easttown : 10 Supplies");

	BExit = Button(750, 0, 800, 50);
	BExit.SetFont(mfont);
	BExit.SetText("x");

	SuppliesButton = Button(0, 0, 100, 50);
	SuppliesButton.SetFont(mfont);
	SuppliesButton.SetText("Supplies: X");

	CostN = 100;
	CostS = 50;
	CostE = 10;
}

bool MapMenu::SetPlayer(Player* p)
{
	mPlayer = p;

	return false;
}

int MapMenu::Update(Input* in)
{
	// Show your current port
	switch (mPlayer->GetCurrentPort())
	{
	case eMapDest::North:
	{
		BDestN.SetColorFront(255, 255, 153, 255);
		BDestS.SetColorFront(255, 255, 255, 255);
		BDestE.SetColorFront(255, 255, 255, 255);
		break;
	}
	case eMapDest::South:
	{
		BDestS.SetColorFront(255, 255, 153, 255);
		BDestN.SetColorFront(255, 255, 255, 255);
		BDestE.SetColorFront(255, 255, 255, 255);
		break;
	}
	case eMapDest::East:
	{
		BDestE.SetColorFront(255, 255, 153, 255);
		BDestS.SetColorFront(255, 255, 255, 255);
		BDestN.SetColorFront(255, 255, 255, 255);
		break;
	}
	default:
	{
		BDestE.SetColorFront(255, 255, 255, 255);
		BDestS.SetColorFront(255, 255, 255, 255);
		BDestN.SetColorFront(255, 255, 255, 255);
		break;
	}
	}

	Ship* curship = mPlayer->getPlayerShip();

	// Update Supply Button
	irrstring str = "Supplies: ";
	str += std::to_string(curship->GetSupplies()).c_str();
	SuppliesButton.SetText(str);

	if (BDestN.isPressed(in))
	{
		if (mPlayer->GetCurrentPort() != eMapDest::North)
		{
			int curSup = curship->GetSupplies();
			if (curSup < CostN)
			{
				// Not enough supplies
			}
			else
			{
				curship->RemoveSupplies(CostN);
				mPlayer->SetCurrentPort(eMapDest::North);
				return eMapDest::North;
			}
		}
	}
	if (BDestE.isPressed(in))
	{
		if (mPlayer->GetCurrentPort() != eMapDest::East)
		{
			int curSup = curship->GetSupplies();
			if (curSup < CostE)
			{
				// Not enough supplies
			}
			else
			{
				curship->RemoveSupplies(CostE);
				mPlayer->SetCurrentPort(eMapDest::East);
				return eMapDest::East;
			}
		}
	}
	if (BDestS.isPressed(in))
	{
		if (mPlayer->GetCurrentPort() != eMapDest::South)
		{
			int curSup = curship->GetSupplies();
			if (curSup < CostS)
			{
				// Not enough supplies
			}
			else
			{
				curship->RemoveSupplies(CostS);
				mPlayer->SetCurrentPort(eMapDest::South);
				return eMapDest::South;
			}
		}
	}
	if (BExit.isPressed(in))
	{
		return eMapDest::Exit;
	}

	return eMapDest::noDest;
}

void MapMenu::Draw(irr::video::IVideoDriver* driver)
{
	background.Draw(driver);
	BDestN.Draw(driver);
	BDestE.Draw(driver);
	BDestS.Draw(driver);
	BExit.Draw(driver);
	SuppliesButton.Draw(driver);
}