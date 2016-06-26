#include "MainMenu.h"

MainMenu::MainMenu(IrrlichtDevice* device, IVideoDriver* driver)
{
	/*m_BstartGame = Button(200, 50, 600, 100);

	m_BexitGame = Button(200, 400, 600, 450);

	m_font = device->getGUIEnvironment()->getBuiltInFont();

	m_BstartGame.SetText("Start Game");
	m_BstartGame.SetFont(m_font);

	m_BexitGame.SetText("Exit Game");
	m_BexitGame.SetFont(m_font);*/

	//initialize buy and sell Buttons
	startButtonTex = GraphicsImage(350, 150, 478, 214);
	startButtonTex.SetTexture("Assets/StartGame.png", driver);
	exitButtonTex = GraphicsImage(350, 320, 478, 384);
	exitButtonTex.SetTexture("Assets/ExitGame.png", driver);

	startGame = Button(startButtonTex, device);
	exitGame = Button(exitButtonTex, device);
}

int MainMenu::Update(Input* in, int& frameCount)
{
	if (in->IsMBDown(0) && startGame.isPressed(in, frameCount))
		return eMainSelect::MSstart;

	if (in->IsMBDown(0) && exitGame.isPressed(in, frameCount))
		return eMainSelect::MSexit;
	return 8000;
}

void MainMenu::Draw(irr::video::IVideoDriver* driver)
{
	startGame.Draw(driver);
	exitGame.Draw(driver);
}