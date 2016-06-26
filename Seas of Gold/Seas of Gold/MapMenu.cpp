#include "MapMenu.h"

MapMenu::MapMenu(IrrlichtDevice* device, irr::video::IVideoDriver* driver)
{


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

	supplyButtonTex = GraphicsImage(43, 37, 75, 69);
	supplyButtonTex.SetTexture("Sprites/crate.png", driver);


	northButton = Button(northButtonTex, device);
	southButton = Button(southButtonTex, device);
	eastButton = Button(eastButtonTex, device);
	supplyButton = Button(supplyButtonTex, device);

	exitButton = Button(exitButtonTex, device);

	m_font = device->getGUIEnvironment()->getBuiltInFont();
}

bool MapMenu::SetPlayer(Player* p)
{
	player = p;

	return false;
}

int MapMenu::Update(Input* in, int& frameCount)
{
	Ship* curship = player->getPlayerShip();

	//get player supplies
	for (int i = 0; i < player->getInventory()->getSize(); i++)
	{
		if (player->getInventory()->getItem(i).item == Item(supplies, "Ship Supplies", "Assets/crate.png"))
		{
			playerSupplies = player->getInventory()->getItem(i).qty;
			break;
		}
	}

	if (in->IsMBDown(0) && northButton.isPressed(in, frameCount))
	{
		if (player->GetCurrentPort() != eMapDest::North)
		{
			int curSup = curship->GetSupplies();
			if (curSup < CostN)
			{
				// Not enough supplies
			}
			else
			{
				curship->RemoveSupplies(CostN);
				player->SetCurrentPort(eMapDest::North);
				return eMapDest::North;
			}
		}
	}
	if (in->IsMBDown(0) && southButton.isPressed(in, frameCount))
	{
		if (player->GetCurrentPort() != eMapDest::South)
		{
			int curSup = curship->GetSupplies();
			if (curSup < CostS)
			{
				// Not enough supplies
			}
			else
			{
				curship->RemoveSupplies(CostS);
				player->SetCurrentPort(eMapDest::South);
				return eMapDest::South;
			}
		}
	}
	if (in->IsMBDown(0) && eastButton.isPressed(in, frameCount))
	{
		if (player->GetCurrentPort() != eMapDest::East)
		{
			int curSup = curship->GetSupplies();
			if (curSup < CostE)
			{
				// Not enough supplies
			}
			else
			{
				curship->RemoveSupplies(CostE);
				player->SetCurrentPort(eMapDest::East);
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

void MapMenu::Draw(IVideoDriver* driver, IrrlichtDevice* device)
{
	background.Draw(driver);
	northButton.Draw(driver);
	eastButton.Draw(driver);
	southButton.Draw(driver);
	exitButton.Draw(driver);
	supplyButton.Draw(driver);

	//draw player's supplies
	m_font = device->getGUIEnvironment()->getBuiltInFont();
	m_font->draw(std::to_string(playerSupplies).c_str(), irr::core::rect<s32>(43, 37, 75, 69), SColor(255, 255, 255, 255), true, true);
}
