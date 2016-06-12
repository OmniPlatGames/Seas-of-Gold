#pragma once
#include "Common.h"
#include "LoadMap.h"
#include "Input.h"

enum eMenuState
{ 
	None, 
	Main, 
	Trade, 
	Map, 
	Craft 
};

enum InterfaceTypes
{
	Merchant = 0,
	Crafting = 1,
};

const int Interfaces = 2;
const int Menus = 3;

struct InterfaceData
{
	ITexture* InterfaceMessage[Interfaces];

	void Initialize(IVideoDriver *driver)
	{
		InterfaceMessage[Merchant] = driver->getTexture("Assets/merchMess.png");
		InterfaceMessage[Crafting] = driver->getTexture("Assets/crftMess.png");
	}
};

class Interface
{
private:
	InterfaceData interfaceData;
	bool test_M;
	bool test_C;

public:
	Interface(IVideoDriver *driver) { interfaceData.Initialize(driver); };
	~Interface();

	void update(IAnimatedMeshSceneNode* plyrNode, LoadMap loadMap, IVideoDriver* driver, IrrlichtDevice *device, Input input, bool& updateCam, int& state);
	void render(IVideoDriver* driver, int& state);
};
