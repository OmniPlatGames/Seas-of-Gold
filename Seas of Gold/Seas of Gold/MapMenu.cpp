#include "MapMenu.h"

MapMenu::MapMenu(IrrlichtDevice* device, irr::video::IVideoDriver* driver)
{
	/*background = GraphicsImage(0, 0, 800, 600);
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
	SuppliesButton.SetText("Supplies: X");*/

	CostN = 100;
	CostS = 50;
	CostE = 10;

	background = GraphicsImage(0, 0, 800, 600);
	background.SetTexture("Assets/Dani-Map.png", driver);

	//initialize buy and sell Buttons
	northButtonTex = GraphicsImage(240, 250, 368, 314);
	northButtonTex.SetTexture("Assets/NorthTown.png", driver);
	southButtonTex = GraphicsImage(350, 520, 478, 584);
	southButtonTex.SetTexture("Assets/SouthTown.png", driver);
	eastButtonTex = GraphicsImage(600, 420, 728, 484);
	eastButtonTex.SetTexture("Assets/EastTown.png", driver);

	exitButtonTex = GraphicsImage(720, 36, 752, 68);
	exitButtonTex.SetTexture("Assets/x.png", driver);

	northButton = Button(northButtonTex, device);
	southButton = Button(southButtonTex, device);
	eastButton = Button(eastButtonTex, device);

	exitButton = Button(exitButtonTex, device);


}

bool MapMenu::SetPlayer(Player* p)
{
	mPlayer = p;

	return false;
}

int MapMenu::Update(Input* in, int& frameCount)
{
	/*// Show your current port
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
	}*/

	Ship* curship = mPlayer->getPlayerShip();

	// Update Supply Button
	//irrstring str = "Supplies: ";
	//str += std::to_string(curship->GetSupplies()).c_str();
	//SuppliesButton.SetText(str);

	if (in->IsMBDown(0) && northButton.isPressed(in, frameCount))
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
	if (in->IsMBDown(0) && southButton.isPressed(in, frameCount))
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
	if (in->IsMBDown(0) && eastButton.isPressed(in, frameCount))
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
	if (in->IsMBDown(0) && exitButton.isPressed(in, frameCount))
	{
		return eMapDest::Exit;
	}

	return eMapDest::noDest;
}

void MapMenu::Draw(IVideoDriver* driver)
{
	background.Draw(driver);
	northButton.Draw(driver);
	eastButton.Draw(driver);
	southButton.Draw(driver);
	exitButton.Draw(driver);
	//SuppliesButton.Draw(driver);
}