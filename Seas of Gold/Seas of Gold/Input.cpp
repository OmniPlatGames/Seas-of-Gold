#include "Input.h"

Input::Input()
{
	for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
	{
		m_KeyIsDown[i] = false;
	}

	for (int i = 0; i < 2; i++)
	{
		m_MBIsDown[i] = false;
	}
}

bool Input::OnEvent(const irr::SEvent& event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		m_KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
	{
		switch (event.MouseInput.Event)
		{
		case irr::EMIE_LMOUSE_PRESSED_DOWN:
			m_MBIsDown[LMB] = true;
			break;

		case irr::EMIE_LMOUSE_LEFT_UP:
			m_MBIsDown[LMB] = false;
			break;

		case irr::EMIE_RMOUSE_PRESSED_DOWN:
			m_MBIsDown[RMB] = true;
			break;

		case irr::EMIE_RMOUSE_LEFT_UP:
			m_MBIsDown[RMB] = false;
			break;

		case irr::EMIE_MOUSE_MOVED:
			m_MPosition.X = event.MouseInput.X;
			m_MPosition.Y = event.MouseInput.Y;
			
			break;

		default:
			break;
		}
	}

	return false;
}

bool Input::IsKeyDown(irr::EKEY_CODE keyCode) const
{
	return m_KeyIsDown[keyCode];
}

bool Input::IsMBDown(int MB) const
{
	return m_MBIsDown[MB];
}

irr::core::vector2df Input::GetMousePosition() const
{
	return m_MPosition;
}