#include "MainMenu.h"

MainMenu::MainMenu(IrrlichtDevice* device)
{
	m_BstartGame = Button(200, 50, 600, 100);

	m_BexitGame = Button(200, 400, 600, 450);

	m_font = device->getGUIEnvironment()->getBuiltInFont();

	m_BstartGame.SetText("Start Game");
	m_BstartGame.SetFont(m_font);

	m_BexitGame.SetText("Exit Game");
	m_BexitGame.SetFont(m_font);
}

int MainMenu::Update(Input* in)
{
	if (m_BstartGame.isPressed(in))
		return eMainSelect::MSstart;

	if (m_BexitGame.isPressed(in))
		return eMainSelect::MSexit;
}

void MainMenu::Draw(irr::video::IVideoDriver* driver)
{
	m_BstartGame.Draw(driver);
	m_BexitGame.Draw(driver);
}