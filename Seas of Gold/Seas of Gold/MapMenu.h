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
	int Update(Input* in);

	// Draw this menu
	void Draw(irr::video::IVideoDriver* driver);
private:
	GraphicsImage background; // The background image

	Button BDestN; // Button that allows you to select the norther town
				   // Also displays the town and shows how much it is to travel there
	Button BDestS; // Button that allows you to select the southern town
				   // Also displays the town and shows how much it is to travel there
	Button BDestE; // Button that allows you to select the eastern town
				   // Also displays the town and shows how much it is to travel there
	Button BExit; // Button that closes the menu
	Button SuppliesButton; // Button that shows how much supply you have

	Player* mPlayer; // Pointer to the current player.
	irr::gui::IGUIFont* mfont; // Current font

	int CostN; // How much it costs to go to the north
	int CostS; // How much it costs to go to the south
	int CostE; // How much it costs to go to the east
};