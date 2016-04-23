#pragma once

#include "Graphics.h"
#include "Input.h"

class Button
{
public:
	Button();
	Button(int x1, int y1, int x2, int y2);

	void SetFont(irr::gui::IGUIFont* font);

	void SetColorBack(int R, int G, int B, int A);
	void SetColorFront(int R, int G, int B, int A);
	void SetColorText(int R, int G, int B, int A);

	irrstring GetText();

	void SetText(irrstring text);

	bool isPressed(Input* in);

	void Draw(irr::video::IVideoDriver* driver);
private:
	irr::video::SColor m_BackColor;
	irr::video::SColor m_FrontColor;
	irr::video::SColor m_TextColor;

	GraphicsRect m_backdrop;
	GraphicsRect m_main;

	v2d m_Topleft;
	v2d m_BotRight;

	irr::gui::IGUIFont* m_font;

	irrstring m_text;

	bool pressed;

	int borderthickness;
};