#include "Interface.h"

Interface::~Interface()
{
}


void Interface::update(IAnimatedMeshSceneNode* plyrNode, LoadMap loadMap, IVideoDriver* driver, IrrlichtDevice *device, Input input, bool& updateCam, int& state)
{
	test_M = false;
	test_C = false;

	//are we in front of the merchant?
	if (plyrNode->getPosition().getDistanceFrom(loadMap.vndTblNode->getPosition()) <= 2.0f) test_M = true;
	else test_M = false;

	//are we in front of the crafting table?
	if (plyrNode->getPosition().getDistanceFrom(loadMap.crfTblNode->getPosition()) <= 1.5f) test_C = true;
	else test_C = false;

	if (state != None)
	{
		updateCam = false;
		device->getCursorControl()->setVisible(true);
	}
	else
	{
		updateCam = true;
		device->getCursorControl()->setVisible(false);
	}

	if (input.IsKeyDown(irr::KEY_KEY_M) && state == None)
	{
		if (state == Map)
			state = None;
		else
			state = Map;
	}

	if (input.IsKeyDown(irr::KEY_KEY_C) && state == None)
	{
		if (state == Craft)
			state = None;
		else
			state = Craft;
	}

	if (input.IsKeyDown(irr::KEY_ESCAPE) && state == None)
		state = Main;
}

void Interface::render(IVideoDriver* driver, int& state)
{
	if (test_M)
	{
		driver->draw2DImage(interfaceData.InterfaceMessage[Merchant], vector2d<s32>(300, 300));
		if (GetAsyncKeyState(VK_RETURN))
			state = Trade;
	}

	if (test_C)
	{
		driver->draw2DImage(interfaceData.InterfaceMessage[Crafting], vector2d<s32>(300, 300));
		if (GetAsyncKeyState(VK_RETURN))
			state = Craft;
	}
}
