#include <irrlicht.h>
#include <iostream>
#include "WorldObject.h"
#include "Graphics.h"
#include "Item.h"


#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

IrrlichtDevice* loadGRender()
{
	
	//
	IrrlichtDevice *device =
		createDevice(video::EDT_DIRECT3D9, dimension2d<u32>(800, 600), 16,
		false, false, false, 0);

	if (!device)
		return nullptr;
	return device;
}

int main()
{
	Item itemTest ("1", 2);
	
	IrrlichtDevice* device = loadGRender();
	
	device->setWindowCaption(L"Seas of Gold");  //Updated JFarley
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	video::E_DRIVER_TYPE driverType = driverChoiceConsole();

	/*guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);*/   //not needed JFarley
	
	//IAnimatedMesh* mesh = smgr->getMesh("sydney.md2");
	IAnimatedMesh* map = smgr->getMesh("Assets/map.3ds");
	if (!map)
	{
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* mapNode = smgr->addAnimatedMeshSceneNode(map);

	if (mapNode)
	{
		mapNode->setMaterialFlag(EMF_LIGHTING, false); 
		mapNode->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);  // alpha blending for 3D objects -- JFarley
		//node->setMD2Animation(scene::EMAT_STAND);
		//node->setMaterialTexture(0, driver->getTexture("textures/sydney.bmp"));  //texture calls are internal to 3ds files -- JFarley
		//node->setMaterialTexture(0, driver->getTexture("textures/map.png"));
	}


	//
	driver->getMaterial2D().TextureLayer[0].BilinearFilter = true;
	driver->getMaterial2D().AntiAliasing = video::EAAM_FULL_BASIC;
	smgr->addCameraSceneNodeFPS(0, 100, 0.01f, -1, NULL, 8);

	while (device->run())
	{

		driver->beginScene(true, true, SColor(255, 100, 101, 140));

		itemTest.loadSprite(driver, v2d(50, 50));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();

		//close game loop with escape key -- JFarley
		if (GetAsyncKeyState(VK_ESCAPE))
			device->closeDevice();
	}

	device->drop();

	return 0;
}