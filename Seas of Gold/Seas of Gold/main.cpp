#include <irrlicht.h>
#include <iostream>
#include "WorldObject.h"
#include "Graphics.h"
#include "Item.h"


#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

vector3df dirLightVector = vector3df(0.0f, 0.0f, 1.0f);

IrrlichtDevice* loadGRender()
{
	
	//
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9, dimension2d<u32>(800, 600), 16, false, true, false, 0);


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
	IAnimatedMesh* map = smgr->getMesh("Assets/map.x");
	if (!map) { device->drop(); return 1; }
	IAnimatedMeshSceneNode* mapNode = smgr->addAnimatedMeshSceneNode(map);

	if (mapNode)
	{
		//mapNode->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);  // alpha blending for 3D objects -- JFarley
	}

	IAnimatedMesh* mHut = smgr->getMesh("Assets/mHut.x");
	if (!mHut) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *mHutNode = smgr->addAnimatedMeshSceneNode(mHut);
	mHutNode->addShadowVolumeSceneNode();
	mHutNode->setMaterialFlag(video::EMF_NORMALIZE_NORMALS, true);

	IAnimatedMesh* cHut = smgr->getMesh("Assets/cHut.x");
	if (!cHut) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *cHutNode = smgr->addAnimatedMeshSceneNode(cHut);

	IAnimatedMesh* dHut = smgr->getMesh("Assets/dHut.x");
	if (!dHut) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *dHutNode = smgr->addAnimatedMeshSceneNode(dHut);

	//////////// The Sun ////////////
	ILightSceneNode *sun_node;
	SLight sun_data;
	ISceneNode *sun_billboard;
	float sun_angle=0;
	video::SColorf Diffuse_Night = video::SColorf(0.0f, 0.0f, 0.0f, 1.0f);
	video::SColorf Diffuse_Day = video::SColorf(1.0f, 1.0f, 1.0f, 1.0f);

	sun_node = smgr->addLightSceneNode();
	sun_data.Direction = vector3df(0, 0, 0);
	sun_data.Type = video::ELT_DIRECTIONAL;
	sun_data.AmbientColor = video::SColorf(0.1f, 0.1f, 0.1f, 1);
	sun_data.SpecularColor = video::SColorf(0,0,0,0);
	sun_data.DiffuseColor = Diffuse_Day;
	sun_data.CastShadows = true;
	sun_node->setLightData(sun_data);
	sun_node->setPosition(vector3df(0, 0, 0));
	sun_node->setRotation(vector3df(0, 0, 0));

	sun_billboard = smgr->addBillboardSceneNode(sun_node, core::dimension2d<f32>(60, 60));
	if (sun_billboard)
	{
		sun_billboard->setPosition(vector3df(0, 0, -100));
		sun_billboard->setMaterialFlag(video::EMF_LIGHTING, false);
		sun_billboard->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
		sun_billboard->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
		sun_billboard->setMaterialTexture(0, driver->getTexture("Assets/particlewhite.bmp"));
	}
	///////// End ////////////

	scene::ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS(0, 100, 0.01f, -1, NULL, 8);
	camera->setNearValue(0.001);
	
	while (device->run())
	{
		sun_node->setRotation(vector3df(sun_angle, 0.0f, 0.0f));
		if (GetAsyncKeyState(0x53)) sun_angle += 0.3f;
		if (sun_angle > 306) sun_angle = 0;
		if (sun_angle < 180) sun_data.DiffuseColor = Diffuse_Day; else sun_data.DiffuseColor = Diffuse_Night;
		sun_node->setLightData(sun_data);
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