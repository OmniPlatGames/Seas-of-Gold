#pragma once

#include "Common.h"
#include "Button.h"
#include "Player.h"

// Enum that allows for map Destination variables
enum eMapDest{noDest,North,South,East,Exit};

// Map Menu Class
// Allows you to Select where you want to go and reduce supply based on that choice.
class MapMenu
{
public:
	// Defualt contructor
	// Takes in a device and driver
	MapMenu(IrrlichtDevice* device,
		irr::video::IVideoDriver* driver);

	// Set the current player you want to move.
	bool SetPlayer(Player* p);

	// Update the map and output a eMapDest variable based on what you choose
	int Update(Input* in, int& frameCount);

	// Draw this menu
	void Draw(IVideoDriver* driver, IrrlichtDevice* device);
private:
	GraphicsImage background; // The background image
	GraphicsImage northButtonTex;
	GraphicsImage southButtonTex;
	GraphicsImage eastButtonTex;
	GraphicsImage exitButtonTex;
	GraphicsImage supplyButtonTex;

	Button northButton;
	Button southButton;
	Button eastButton;
	Button exitButton;
	Button supplyButton;

	IGUIFont* m_font;

	int playerSupplies;

	Button BExit; // Button that closes the menu
	Button SuppliesButton; // Button that shows how much supply you have

	Player* player; // Pointer to the current player.
	irr::gui::IGUIFont* mfont; // Current font

	int CostN; // How much it costs to go to the north
	int CostS; // How much it costs to go to the south
	int CostE; // How much it costs to go to the east
};