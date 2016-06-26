#pragma once
#include "Button.h"

enum eMainSelect {MSstart,MSexit};

class MainMenu
{
public:
	MainMenu(IrrlichtDevice* device, IVideoDriver* driver);

	// Returns an int based on your selection
	int Update(Input* in, int& frameCount);

	void Draw(irr::video::IVideoDriver* driver);

private:
	Button startGame;
	Button exitGame;

	GraphicsImage startButtonTex;
	GraphicsImage exitButtonTex;

	gui::IGUIFont* m_font;
};