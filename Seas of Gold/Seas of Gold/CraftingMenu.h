#pragma once

#include "Common.h"
#include "Player.h"
#include "Input.h"
#include "Graphics.h"
#include "Button.h"

class CraftingMenu
{
public:
	CraftingMenu(IrrlichtDevice* device,
		irr::video::IVideoDriver* driver);

	void SetPlayer(Player* p);

	bool Update(Input* in);

	void Draw(irr::video::IVideoDriver* driver);

private:
	void UpdateContents();

private:
	Button RightPannel;
	Button LeftPannel;
	Button LeftTitle;
	Button RightTitle;

	Button ExitButton;

	Button CraftButton;

	std::vector<Button> bItemList;
	std::vector<Button> bItemListAmnt;
	std::vector<Button> bCraftList;
	std::vector<Button> bCraftListAmnt;

	bool SelectedItems[17];
	int selectedCraft;

	Player* mPlayer;
	irr::gui::IGUIFont* mfont;

	GraphicsImage background;
};