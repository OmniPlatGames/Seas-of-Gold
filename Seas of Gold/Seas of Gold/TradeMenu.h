#pragma once

#include "Common.h"
#include "Button.h"
#include "Inventory.h"
#include "Player.h"
#include "Vendor.h"

class TradeMenu
{
public:
	TradeMenu(IrrlichtDevice* device,
		irr::video::IVideoDriver* driver);

	void SetPlayer(Player* p);
	void SetVendor(Vendor* v);

	bool Update(Input* in);

	void Draw(irr::video::IVideoDriver* driver);

private:
	void UpdateContents();

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
	Vendor* mVendor;

	int SupplyCost;
	int CrewCost;

	std::vector<Button> BBuyList;
	std::vector<Button> BBuyListAmnt;
	std::vector<Button> BSellList;
	std::vector<Button> BSellListAmnt;

	int ModAmnt;

	int SelectedItem;
};