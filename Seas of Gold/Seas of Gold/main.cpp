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
	
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	video::E_DRIVER_TYPE driverType = driverChoiceConsole();

	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);

	//IAnimatedMesh* mesh = smgr->getMesh("sydney.md2");
	IAnimatedMesh* mesh = smgr->getMesh("textures/map.3ds");
	if (!mesh)
	{
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		//node->setMaterialTexture(0, driver->getTexture("textures/sydney.bmp"));
		//node->setMaterialTexture(0, driver->getTexture("textures/map.png"));
	}
	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

	//
	driver->getMaterial2D().TextureLayer[0].BilinearFilter = true;
	driver->getMaterial2D().AntiAliasing = video::EAAM_FULL_BASIC;
	smgr->addCameraSceneNodeFPS();

	while (device->run())
	{

		driver->beginScene(true, true, SColor(255, 100, 101, 140));

		itemTest.loadSprite(driver, v2d(50, 50));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();
	}

	device->drop();

	return 0;
}