#include "TradeMenu.h"

TradeMenu::TradeMenu()
{
}

TradeMenu::~TradeMenu()
{
}

//initializes the menu data
void TradeMenu::Initialize(IrrlichtDevice* device, IVideoDriver* driver, Player& plyr, Vendor& vndr)
{
	
	//initialize background information
	background = GraphicsImage(10, 10, 790, 500);
	background.SetTexture("Assets/trademenu.png", driver);

	font = device->getGUIEnvironment()->getBuiltInFont();

	player = plyr;
	vendor = vndr;	

}

void TradeMenu::SetVendor(Vendor& vndr)
{
	vendor = vndr;
}

//updates the menu
bool TradeMenu::Update(Input* in)
{
	return false;
}

//renders the menu on the screen
void TradeMenu::Render(IVideoDriver* driver)
{
	int incrX = 0;
	int incrY = 0;
	InventorySlot iSlot;

	//draw the background image
	background.Draw(driver);

	//draw the player's inventory
	for (int i = 0; i < player.getInventory()->getSize(); i++)
	{
		//get the item in the inventory slot
		iSlot = player.getInventory()->getItem(i);

		//render the item in the slot
		incrX = i;
		if (incrX > 8)
		{
			incrX = 0;
			incrY += 1;
		}
		v2d pos = v2d(66 + (incrX * 40), 109 + (incrY * 40));

		iSlot.item.loadSprite(driver, pos);

		//render the qty of the item in the slot
		pos = v2d(90+(incrX*40), 133+(incrY*40));
		char quantity = iSlot.qty;
		font->draw(stringw(quantity), rect<s32>(pos.X, pos.Y, pos.X + 8, pos.Y + 8), SColor(255, 0, 0, 255), false, false, 0);
	}

	//draw the vendors's inventory
	for (int i = 0; i < vendor.getInventory()->getSize(); i++)
	{
		//get the item in the inventory slot
		iSlot = vendor.getInventory()->getItem(i);

		/*//render the item in the slot
		incrX = i;
		if (incrX > 8)
		{
			incrX = 0;
			incrY += 1;
		}
		v2d pos = v2d(430 + (incrX * 40), 109 + (incrY * 40));

		iSlot.item.loadSprite(driver, pos);

		//render the qty of the item in the slot
		pos = v2d(454 + (incrX * 40), 133 + (incrY * 40));
		char test = iSlot.qty;

		font->draw(stringw(test), rect<s32>(pos.X, pos.Y, pos.X + 8, pos.Y + 8), SColor(255, 0, 0, 255), false, false, 0);*/



	}

	int test = 0;
}
