#include "TradeMenu.h"

TradeMenu::TradeMenu()
{
}

TradeMenu::~TradeMenu()
{
}

//initializes the menu data
void TradeMenu::Initialize(IrrlichtDevice* device, IVideoDriver* driver)
{
	
	//initialize background information
	background = GraphicsImage(10, 10, 790, 500);
	background.SetTexture("Assets/woodTex.png", driver);



}

//updates the menu
void TradeMenu::Update(Input* in)
{

}

//renders the menu on the screen
void TradeMenu::Render(IVideoDriver* driver)
{
	background.Draw(driver);
}
