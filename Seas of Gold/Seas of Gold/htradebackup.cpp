#pragma once

#include "Common.h"
#include "Button.h"
#include "Inventory.h"
#include "Player.h"
#include "Vendor.h"

// Trade Menu Class
//
// Creates and displays a trade menu that allows
// a player and vendor to communicate.
class TradeMenu
{
public:
	// Main constructor
	// Takes in a device and a driver
	TradeMenu(IrrlichtDevice* device,
		irr::video::IVideoDriver* driver);

	// Set the current player object via it's pointer
	void SetPlayer(Player* p);

	// Set the current vendor object via it's pointer
	void SetVendor(Vendor* v);

	// Update everything about the menu
	bool Update(Input* in);

	// Draw everything on the menu
	void Draw(irr::video::IVideoDriver* driver);

private:
	// Update what is contained within the menu.
	void UpdateContents();

private:
	// The background image.
	GraphicsImage background;

	// UI Layout elements
	// I am using buttons with no interaction
	// because it already had the easiest to modify visual interface

	Button BbgL; // Background Column Left
	Button BbgR; // Background Column

	Button BShopTitle; // Title object for the shop
	Button BShipTitle; // Title object for your inventory

	Button BBuyButton; // Button used to buy your currently selected object
	Button BSellButton; // Button used to sell your currently selected object

	Button BamntDisp; // How much you buy are sell display
	Button BamntUp; // Modify your buy and sell display by increasing it
	Button BamntDown; //  Modify your buy and sell display by decreasing it

	Button GoldButton; // Displays how much gold you have
	Button BuySuppliesButton; // Allows you to buy supplies until you reach your max
	Button BuyCrewButton; // Allows you to buy crew until you reach your max
	Button BExit; // Allows you to exit the menu

	irr::gui::IGUIFont* mfont; // Font object
	Player* mPlayer; // Current player pointer
	Vendor* mVendor; // Current vendor pointer

	int SupplyCost; // How much Supply costs
	int CrewCost; // How much Crew Costs

	std::vector<Button> BBuyList; // List of buttons used to select what you want to buy
								  // And it displays what the object is
	std::vector<Button> BBuyListAmnt; // Shows how much of a certain object there is
	std::vector<Button> BSellList; // List of buttons used to select what you want to sell
								   // And it displays what the object is
	std::vector<Button> BSellListAmnt; // Shows how much of a certain object there is

	int ModAmnt; // How much of an object you will sell or buy

	int SelectedItem; // Which item you have selected.
};