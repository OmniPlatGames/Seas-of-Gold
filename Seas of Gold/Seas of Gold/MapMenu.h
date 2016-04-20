#pragma once

#include "Common.h"
#include "Button.h"
#include "Player.h"


enum eMapDest{noDest,North,South,East,Exit};

class MapMenu
{
public:
	MapMenu(IrrlichtDevice* device,
		irr::video::IVideoDriver* driver);
	bool SetPlayer(Player* p);
	int Update(Input* in);
	void Draw(irr::video::IVideoDriver* driver);
private:
	GraphicsImage background;
	Button BDestN;
	Button BDestS;
	Button BDestE;
	Button BExit;
	Button SuppliesButton;
	Player* mPlayer;
	irr::gui::IGUIFont* mfont;

	int CostN;
	int CostS;
	int CostE;
};