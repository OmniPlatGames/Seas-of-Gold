#pragma once

#include "Common.h"
#include "Button.h"
#include "Player.h"

class TradeMenu
{
public:
	TradeMenu(IrrlichtDevice* device,
		irr::video::IVideoDriver* driver);

	void SetPlayer(Player* p);

	bool Update(Input* in);

	void Draw(irr::video::IVideoDriver* driver);
private:
	GraphicsImage background;

	// UI Layout Buttons
	Button BbgL;
	Button BbgR;

	Button BShopTitle;
	Button BShipTitle;

	Button BBuyButton;
	Button BSellButton;

	Button BamntDisp;
	Button BamntUp;
	Button BamntDown;

	Button GoldButton;
	Button BuySuppliesButton;
	Button BuyCrewButton;
	Button BExit;
	irr::gui::IGUIFont* mfont;
	Player* mPlayer;

	int SupplyCost;
	int CrewCost;

	int ModAmnt;
};