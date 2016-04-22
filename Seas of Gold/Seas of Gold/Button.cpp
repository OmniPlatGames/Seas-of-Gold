#include "Button.h"

Button::Button()
{
	m_BackColor = irr::video::SColor(255, 0, 0, 0);
	m_FrontColor = irr::video::SColor(255, 255, 255, 255);

	m_Topleft = v2d(0, 0);
	m_BotRight = v2d(0, 0);

	borderthickness = 1;

	m_backdrop = GraphicsRect(m_Topleft.X,
		m_Topleft.Y,
		m_BotRight.X, 
		m_BotRight.Y);

	m_backdrop.SetColor(m_BackColor);

	m_main = GraphicsRect(m_Topleft.X + borderthickness,
		m_Topleft.Y + borderthickness,
		m_BotRight.X - borderthickness,
		m_BotRight.Y - borderthickness);

	m_main.SetColor(m_FrontColor);

	m_TextColor = irr::video::SColor(255, 0, 0, 0);

	pressed = false;
}

Button::Button(int x1, int y1, int x2, int y2)
{
	m_Topleft = v2d(x1, y1);
	m_BotRight = v2d(x2, y2);


	m_BackColor = irr::video::SColor(255, 0, 0, 0);
	m_FrontColor = irr::video::SColor(255, 255, 255, 255);

	borderthickness = 1;

	m_backdrop = GraphicsRect(x1,
		y1,
		x2,
		y2);

	m_backdrop.SetColor(m_BackColor);

	m_main = GraphicsRect(x1 + borderthickness,
		y1 + borderthickness,
		x2 - borderthickness,
		y2 - borderthickness);

	m_main.SetColor(m_FrontColor);

	m_TextColor = irr::video::SColor(255, 0, 0, 0);

	pressed = false;
}

void Button::SetFont(irr::gui::IGUIFont* font)
{
	m_font = font;
}

void Button::SetColorBack(int R, int G, int B, int A)
{
	m_backdrop.SetColor(R, G, B, A);
}

void Button::SetColorFront(int R, int G, int B, int A)
{
	m_main.SetColor(R, G, B, A);
}

void Button::SetColorText(int R, int G, int B, int A)
{
	m_TextColor = irr::video::SColor(A, R, G, B);
}

irrstring Button::GetText()
{
	return m_text;
}

void Button::SetText(irrstring text)
{
	m_text = text;
}

bool Button::isPressed(Input* in)
{
	if (in->IsMBDown(eInput::LMB))
	{
		v2d mpos = in->GetMousePosition();

		if ((m_Topleft.X < mpos.X) && (m_Topleft.Y < mpos.Y)
			&& (m_BotRight.X > mpos.X) && (m_BotRight.Y > mpos.Y))
		{
			pressed = true;
		}
	}
	else
	{
		if (pressed == true)
		{
			pressed = false;
			return true;
		}
	}

	return false;
}

void Button::Draw(irr::video::IVideoDriver* driver)
{
	m_backdrop.Draw(driver);
	m_main.Draw(driver);


	if ((m_font != NULL) && !m_text.empty())
	{
		m_font->draw(m_text,
			irr::core::rect<s32>(m_Topleft.X, m_Topleft.Y,
				m_BotRight.X, m_BotRight.Y),
			m_TextColor,true,true);
	}
}