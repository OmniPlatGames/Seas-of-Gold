#pragma once

#include "Graphics.h"
#include "Input.h"
#include "Inventory.h"

class Button
{
public:
	Button();
	Button(InventorySlot& slot, v2d iconPos, v2d qtyPos, IrrlichtDevice* device);
	Button(GraphicsImage& image, IrrlichtDevice* device);

	bool isPressed(Input* in, int& frameCount);
	void Select(Input* in, int& frameCount, int& selectedItems);
	bool isSelected();

	void Draw(irr::video::IVideoDriver* driver);

	void setText(int);

	Item getItem();
	int getQty();

	void setSelected(bool set);

private:

	v2d i_TopLeft;
	v2d i_BotRight;

	v2d q_TopLeft;
	v2d q_BotRight;

	stringw text;

	GraphicsRect selectedBorder;

	InventorySlot iSlot;

	IGUIFont* m_font;

	ITexture* icon;

	bool press;
	bool pressed;
	bool selected;

	int borderthickness;

	//used only for graphicsImage constructor and related draw
	GraphicsImage buttonImage;


};