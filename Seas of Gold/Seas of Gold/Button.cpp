#include "Button.h"

//should not use.... use parameterized constructor
Button::Button()
{
}

Button::Button(InventorySlot& slot, v2d iconPos, v2d qtyPos, IrrlichtDevice* device)
{
	//initialize variables
	pressed = false;
	selected = false;

	//set rectangle corners for icon
	i_TopLeft = iconPos;
	i_BotRight = v2d(iconPos.X + 32, iconPos.Y + 32);

	//set rectangle corners for qty
	q_TopLeft = qtyPos;
	q_BotRight = v2d(qtyPos.X + 8, qtyPos.Y + 8);

	//initialize selected border area
	borderthickness = 2;
	selectedBorder = GraphicsRect(i_TopLeft.X + borderthickness,
		i_TopLeft.Y + borderthickness,
		i_BotRight.X - borderthickness,
		i_BotRight.Y - borderthickness);
	pressed = false;

	//save the inventory slot data
	iSlot = slot;

	//set up the font for text rendering
	m_font = device->getGUIEnvironment()->getBuiltInFont();
}

Button::Button(GraphicsImage& image, IrrlichtDevice* device)
{
	//initialize variables
	pressed = false;
	selected = false;

	//set rectangle corners for icon
	i_TopLeft = image.GetPosition();
	i_BotRight = v2d(i_TopLeft.X + 128, i_TopLeft.Y + 64);

	//set rectangle corners for qty
	q_TopLeft = v2d(0, 0);
	q_BotRight = v2d(0, 0);

	//initialize selected border area
	borderthickness = 2;
	selectedBorder = GraphicsRect(i_TopLeft.X + borderthickness,
		i_TopLeft.Y + borderthickness,
		i_BotRight.X - borderthickness,
		i_BotRight.Y - borderthickness);
	pressed = false;

	buttonImage = image;
	m_font = device->getGUIEnvironment()->getBuiltInFont();
}

bool Button::isPressed(Input* in, int& frameCount)
{
	/*if (in->IsMBDown(eInput::LMB))
	{
		v2d mpos = in->GetMousePosition();

		if ((i_TopLeft.X < mpos.X) && (i_TopLeft.Y < mpos.Y)
			&& (i_BotRight.X > mpos.X) && (i_BotRight.Y > mpos.Y))
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

	return false;*/
	//if left mouse button is pressed
	v2d mpos = in->GetMousePosition();

	if ((i_TopLeft.X < mpos.X) && (i_TopLeft.Y < mpos.Y)
		&& (i_BotRight.X > mpos.X) && (i_BotRight.Y > mpos.Y)
		&& (frameCount > 60))
	{
		frameCount = 0;
		return true;
	}

	return false;


	/*{
		pressed = true;
		return true;
	}
	else if (pressed == true)
	{
		pressed = false;
		return false;
	}

	return false;*/
}

//used to select an item
void Button::Select(Input* in, int& frameCount, int& selectedItems)
{
	//if mouse is over this icon when clicked, and it's been about  second since last click, toggle selected.
	v2d mpos = in->GetMousePosition();

	if ((i_TopLeft.X < mpos.X) && (i_TopLeft.Y < mpos.Y)
		&& (i_BotRight.X > mpos.X) && (i_BotRight.Y > mpos.Y)
		&& (frameCount > 30))
	{
		frameCount = 0;
		if (!selected)
		{
			selected = true;
			selectedItems += 1;
		}
		else
		{
			selected = false;
			selectedItems -= 1;
		}
	}
}

bool Button::isSelected()
{
	return selected;
}

void Button::Draw(irr::video::IVideoDriver* driver)
{
	//if button is an item (bronze ore, bronze dagger, etc)
	if (q_BotRight.X)
	{
		//render sprite
		iSlot.item.loadSprite(driver, i_TopLeft);
		
		//if selected, draw a rectangle on it
		if (selected)
		{
			driver->draw2DRectangle(video::SColor(100, 255, 255, 0), rect<s32>(i_TopLeft.X, i_TopLeft.Y, i_BotRight.X, i_BotRight.Y), 0);
		}

		//render the qty of the item in the slot
		//char quantity = iSlot.qty;
		std::string s = std::to_string(iSlot.qty);
		stringw test = s.c_str();
		m_font->draw(test, irr::core::rect<s32>(q_TopLeft.X, q_TopLeft.Y, q_BotRight.X, q_BotRight.Y), SColor(255, 255, 0, 0), true, true);
	}
	//if button is a button (buy, sell, craft, etc)
	else
	{
		buttonImage.Draw(driver);
		//if (text.size() > 0)
		//{
			//m_font->draw(text, irr::core::rect<s32>(q_TopLeft.X, q_TopLeft.Y, q_BotRight.X, q_BotRight.Y), SColor(255, 255, 0, 0), true, true);
		//}
	}
}

Item Button::getItem()
{
	return iSlot.item;
}

int Button::getQty()
{
	return iSlot.qty;
}

void Button::setSelected(bool set)
{
	pressed = set;
}

void Button::setText(int intToText)
{
	text = std::to_string(intToText).c_str();

}