#include "TradeMenu.h"

TradeMenu::TradeMenu()
{
	playerButtons.empty();
	vendorButtons.empty();
}

TradeMenu::~TradeMenu()
{
}

//initializes the menu data
void TradeMenu::Initialize(IrrlichtDevice* device, IVideoDriver* driver, Player* plyr, Vendor* vndr)
{

	player = plyr;
	vendor = vndr;
	m_font = device->getGUIEnvironment()->getBuiltInFont();

	
	//initialize background information
	background = GraphicsImage(10, 10, 790, 500);
	background.SetTexture("Assets/trademenu.png", driver);

	//initialize buy and sell and exit Buttons
	buyButtonTex = GraphicsImage(160, 485, 288, 549); // 160, 485;
	buyButtonTex.SetTexture("Assets/Buy.png", driver);
	sellButtonTex = GraphicsImage(530, 485, 658, 549); // 530, 485;
	sellButtonTex.SetTexture("Assets/Sell.png", driver);
	exitButtonTex = GraphicsImage(720, 36, 752, 68);
	exitButtonTex.SetTexture("Assets/x.png", driver);
	goldButtonTex = GraphicsImage(43, 37, 75, 69);
	goldButtonTex.SetTexture("Sprites/coins.png", driver);


	buyButton = Button(buyButtonTex, device);
	sellButton = Button(sellButtonTex, device);
	exitButton = Button(exitButtonTex, device);
	goldButton = Button(goldButtonTex, device);
	goldButton.setText(player->getGold());

	//set up font
	//font = device->getGUIEnvironment()->getBuiltInFont();

	selectedItems = 0;
	maxSelected = 1;

	int incrX = 0;
	int incrY = 0;
	InventorySlot iSlot;

	//setup the player's inventory
	for (int i = 0; i < player->getInventory()->getSize(); i++)
	{
		//get positions the icons need to be at
		incrX = i;
		if (incrX > 8)
		{
			incrX = 0;
			incrY += 1;
		}
		iconPos = v2d(66 + (incrX * 40), 109 + (incrY * 40));
		qtyPos = v2d(90 + (incrX * 40), 133 + (incrY * 40));

		//create the button and draw it
		playerButtons.push_back(Button(player->getInventory()->getItem(i), iconPos, qtyPos, device));

	}

	//reset incrementors
	incrX = 0;
	incrY = 0;

	//draw the vendors's inventory
	for (int i = 0; i < vendor->getInventory()->getSize(); i++)
	{
		//get positions the icons need to be at
		incrX = i;
		if (incrX > 8)
		{
			incrX = 0;
			incrY += 1;
		}
		iconPos = v2d(430 + (incrX * 40), 109 + (incrY * 40));
		qtyPos = v2d(454 + (incrX * 40), 133 + (incrY * 40));

		//create the button and draw it
		vendorButtons.push_back(Button(vendor->getInventory()->getItem(i), iconPos, qtyPos, device));

	}

}

void TradeMenu::SetVendor(Vendor* vndr)
{
	vendor = vndr;
}

//updates the menu
bool TradeMenu::Update(Input* in, int& frameCount, IrrlichtDevice* device)
{
	//get player gold and set the text
	goldButton.setText(player->getGold());

	//if left mouse button is pressed, and we haven't reach max selected items, find out if an icon was clicked
	if (in->IsMBDown(0) && (selectedItems < maxSelected))
	{
		for (int i = 0; i < playerButtons.size(); i++)
		{
			playerButtons[i].Select(in, frameCount, selectedItems);
		}
		for (int i = 0; i < vendorButtons.size(); i++)
		{
			vendorButtons[i].Select(in, frameCount, selectedItems);
		}
	}
	//if left mouse button is pressed, but we reached our max selected items, only find out if a selected icon was clicked
	else if(in->IsMBDown(0) && (selectedItems >= maxSelected))
	{
		for (int i = 0; i < playerButtons.size(); i++)
		{
			if (playerButtons[i].isSelected())
			{
				playerButtons[i].Select(in, frameCount, selectedItems);
			}
		}
		for (int i = 0; i < vendorButtons.size(); i++)
		{
			if (vendorButtons[i].isSelected())
			{
				vendorButtons[i].Select(in, frameCount, selectedItems);
			}
		}
	}

	//if buy button is pressed, see if a vendor item is selected. If it is, transfer from vendor to player inventory
	if (in->IsMBDown(0) && buyButton.isPressed(in, frameCount))
	{

		for (int i = 0; i < vendorButtons.size(); i++)
		{
			if (vendorButtons[i].isSelected() == true)
			{
				Item item = vendorButtons[i].getItem();
				player->getInventory()->addItem(item, 1);
				vendor->getInventory()->removeItem(item, 1);
				//reset inventory buttons for display
				int incrX = 0;
				int incrY = 0;
				playerButtons.clear();
				vendorButtons.clear();
				selectedItems -= 1;
				for (int i = 0; i < player->getInventory()->getSize(); i++)
				{
					//get positions the icons need to be at
					incrX = i;
					if (incrX > 8)
					{
						incrX = 0;
						incrY += 1;
					}
					iconPos = v2d(66 + (incrX * 40), 109 + (incrY * 40));
					qtyPos = v2d(90 + (incrX * 40), 133 + (incrY * 40));

					//create the button and draw it
					playerButtons.push_back(Button(player->getInventory()->getItem(i), iconPos, qtyPos, device));

				}

				//reset incrementors
				incrX = 0;
				incrY = 0;

				//draw the vendors's inventory
				for (int i = 0; i < vendor->getInventory()->getSize(); i++)
				{
					//get positions the icons need to be at
					incrX = i;
					if (incrX > 8)
					{
						incrX = 0;
						incrY += 1;
					}
					iconPos = v2d(430 + (incrX * 40), 109 + (incrY * 40));
					qtyPos = v2d(454 + (incrX * 40), 133 + (incrY * 40));

					//create the button and draw it
					vendorButtons.push_back(Button(vendor->getInventory()->getItem(i), iconPos, qtyPos, device));

				}
				//no need to search through rest of items
				break;
			}
		}
	}
	//if sell button is pressed, see if a player item is selected. If it is, transfer from player to vendor inventory
	else if (in->IsMBDown(0) && sellButton.isPressed(in, frameCount))
	{
		for (int i = 0; i < playerButtons.size(); i++)
		{
			if (playerButtons[i].isSelected() == true)
			{
				Item item = playerButtons[i].getItem();
				//get current last item information

				vendor->getInventory()->addItem(item, 1);
				player->getInventory()->removeItem(item, 1);

				//reset inventory buttons for display
				int incrX = 0;
				int incrY = 0;
				playerButtons.clear();
				vendorButtons.clear();
				selectedItems -= 1;
				for (int i = 0; i < player->getInventory()->getSize(); i++)
				{
					//get positions the icons need to be at
					incrX = i;
					if (incrX > 8)
					{
						incrX = 0;
						incrY += 1;
					}
					iconPos = v2d(66 + (incrX * 40), 109 + (incrY * 40));
					qtyPos = v2d(90 + (incrX * 40), 133 + (incrY * 40));

					//create the button and draw it
					playerButtons.push_back(Button(player->getInventory()->getItem(i), iconPos, qtyPos, device));

				}

				//reset incrementors
				incrX = 0;
				incrY = 0;

				//draw the vendors's inventory
				for (int i = 0; i < vendor->getInventory()->getSize(); i++)
				{
					//get positions the icons need to be at
					incrX = i;
					if (incrX > 8)
					{
						incrX = 0;
						incrY += 1;
					}
					iconPos = v2d(430 + (incrX * 40), 109 + (incrY * 40));
					qtyPos = v2d(454 + (incrX * 40), 133 + (incrY * 40));

					//create the button and draw it
					vendorButtons.push_back(Button(vendor->getInventory()->getItem(i), iconPos, qtyPos, device));

				}
				//sellButton.setSelected(false);
				int test = 1;
				break;
			}
		}
	}

	if (in->IsMBDown(0) && exitButton.isPressed(in, frameCount))
	{
		return true;
	}
	return false;
}

//renders the menu on the screen
void TradeMenu::Render(IVideoDriver* driver, IrrlichtDevice* device)
{
	//playerButtons.clear();
	//vendorButtons.clear();

	//draw the background image
	background.Draw(driver);

	//draw buy and sell buttons
	buyButton.Draw(driver);
	sellButton.Draw(driver);
	exitButton.Draw(driver);
	goldButton.Draw(driver);

	//draw the player's inventory
	for (int i = 0; i < player->getInventory()->getSize(); i++)
	{
		playerButtons[i].Draw(driver);
	}

	//draw the vendors's inventory
	for (int i = 0; i < vendor->getInventory()->getSize(); i++)
	{
		vendorButtons[i].Draw(driver);
	}

	//draw player's gold
	m_font->draw(std::to_string(player->getGold()).c_str(), irr::core::rect<s32>(43, 37, 75, 69), SColor(255, 255, 255, 255), true, true);
}
