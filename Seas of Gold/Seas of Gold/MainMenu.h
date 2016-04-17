#pragma once
#include "Button.h"

enum eMainSelect {MSstart,MSexit};

class MainMenu
{
public:
	MainMenu(IrrlichtDevice* device);

	// Returns an int based on your selection
	int Update(Input* in);

	void Draw(irr::video::IVideoDriver* driver);

private:
	Button m_BstartGame;
	Button m_BexitGame;

	gui::IGUIFont* m_font;
};