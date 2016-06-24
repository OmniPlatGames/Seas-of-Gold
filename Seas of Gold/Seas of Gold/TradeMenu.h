#pragma once

#include "Common.h"
#include "Button.h"
#include "Graphics.h"
#include "Player.h"
#include "Vendor.h"

// Trade Menu Class
//
// Creates and displays a trade menu that allows
// a player and vendor to communicate.
class TradeMenu
{
private:
	GraphicsImage background;
	IGUIFont* font;

	Vendor vendor;
	Player player;

public:
	TradeMenu();
	~TradeMenu();

	//initializes the menu data
	void Initialize(IrrlichtDevice* device, IVideoDriver* driver, Player& Plyr, Vendor& Vndr);

	//sets vendor for new location
	void SetVendor(Vendor& vndr);

	//updates the menu
	bool Update(Input* in);

	//Renders the menu on the screen
	void Render(IVideoDriver* driver);
};