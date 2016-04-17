#include <irrlicht.h>
#include <iostream>
#include "WorldObject.h"
#include "Graphics.h"
#include "Item.h"
#include "XEffects.h"


#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


float direction=0, zdirection=0;
vector3df dirLightVector = vector3df(0.0f, 0.0f, 1.0f);
void moveCameraControl(IAnimatedMeshSceneNode*, IrrlichtDevice*, ICameraSceneNode*);

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
	int skyR = 30, skyG = 30, skyB = 70;
	int timer = 0;
	SColor sky = SColor(255, skyR, skyG, skyB);
	IrrlichtDevice* device = loadGRender();
	float plPos_x = -6.0f, plPos_y = 0.0f, plPos_z = -5.0f;


	
	device->setWindowCaption(L"Seas of Gold");  //Updated JFarley
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	video::E_DRIVER_TYPE driverType = driverChoiceConsole();
	EffectHandler *effect = new EffectHandler(device, driver->getScreenSize(), false, true);
	E_FILTER_TYPE filterType = (E_FILTER_TYPE)core::clamp<u32>((u32)3 - '1', 0, 4);


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
	mHutNode->getMaterial(0).Lighting = false;

	IAnimatedMesh* cHut = smgr->getMesh("Assets/cHut.x");
	if (!cHut) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *cHutNode = smgr->addAnimatedMeshSceneNode(cHut);

	IAnimatedMesh* dHut = smgr->getMesh("Assets/dHut.x");
	if (!dHut) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *dHutNode = smgr->addAnimatedMeshSceneNode(dHut);

	IAnimatedMesh* merch = smgr->getMesh("Assets/merch.x");
	if (!merch) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *merchNode = smgr->addAnimatedMeshSceneNode(merch);

	IAnimatedMesh* player = smgr->getMesh("Assets/player.x");
	if (!player) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *plyrNode = smgr->addAnimatedMeshSceneNode(player);
	plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));

	ICameraSceneNode* camera = smgr->addCameraSceneNode(0, plyrNode->getPosition() + vector3df(0, 2, 2), plyrNode->getPosition() + vector3df(0, 2, 0));

	
	////////////// The Sun ////////////
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
	/////////// End ////////////

	//------- candleLight -----//
	ILightSceneNode *candleLight = smgr->addLightSceneNode();
	SLight candleLight_data;

	candleLight_data.Type = video::ELT_POINT;
	candleLight_data.DiffuseColor = SColorf(1.0f, 0.546f, 0.016f, 1.0f);
	candleLight_data.SpecularColor = video::SColorf(0, 0, 0, 0);
	candleLight->setPosition(vector3df(2.43467f, 1.55795f, -3.94657));
	candleLight_data.Radius = 1.5f;
	candleLight->setLightData(candleLight_data);
	//------- end -----//

	
	while (device->run())
	{
		sun_node->setRotation(vector3df(sun_angle, 0.0f, 0.0f));
		sun_angle += 0.01f;
		if ((sun_angle > 0 && sun_angle < 109) || (sun_angle>350))
		{
			timer++;
			if (timer > 10)
			{
				if (skyR < 100) skyR += 1;
				if (skyG < 100) skyG += 1;
				if (skyB < 140) skyB += 1;
				timer = 0;
			}
		}
		if (sun_angle > 170 && sun_angle < 330)
		{
			timer++;
			if (timer > 10)
			{
				if (skyR > 0) skyR -= 1;
				if (skyG > 0) skyG -= 1;
				if (skyB > 40) skyB -= 1;
				timer = 0;
			}
		}

		if (GetAsyncKeyState(0x57))
		{
			plPos_z -= 0.01f * (cos((plyrNode->getRotation().Y)*PI/180));
			plPos_x -= 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
			
		}
		if (GetAsyncKeyState(0x53))
		{
			plPos_z += 0.01f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plPos_x += 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
		}
		if (GetAsyncKeyState(0x44))
		{
			plPos_z += 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plPos_x -= 0.01f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
		}
		if (GetAsyncKeyState(0x41))
		{
			plPos_z -= 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plPos_x += 0.01f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
		}


		moveCameraControl(plyrNode, device, camera);

		if (sun_angle > 360) sun_angle = 0;
		if (sun_angle < 180) sun_data.DiffuseColor = Diffuse_Day; else sun_data.DiffuseColor = Diffuse_Night;
		sun_node->setLightData(sun_data);

		sky.setRed(skyR);
		sky.setGreen(skyG);
		sky.setBlue(skyB);
		driver->beginScene(true, true, sky);
		//itemTest.loadSprite(driver, v2d(50, 50));
		
		smgr->drawAll();
		//guienv->drawAll();

		driver->endScene();
		

		//close game loop with escape key -- JFarley
		if (GetAsyncKeyState(VK_ESCAPE))
			device->closeDevice();
	}

	device->drop();

	return 0;
}

void moveCameraControl(IAnimatedMeshSceneNode* playerNode, IrrlichtDevice* device, ICameraSceneNode* camera)
{
	//IrrlichtDevice* device = loadGRender();

	position2d<f32> cursorPos = device->getCursorControl()->getRelativePosition();
	//ICameraSceneNode* camera = device->getSceneManager()->getActiveCamera();
	vector3df cameraPos = camera->getAbsolutePosition();

	float change_x = (cursorPos.X - 0.5) * 256.0f;
	float change_y = (cursorPos.Y - 0.5) * 256.0f;
	direction += change_x;
	zdirection = -90;

	device->getCursorControl()->setPosition(0.5f, 0.5f);

	vector3df playerPos = playerNode->getPosition();

	float xf = playerPos.X - cos(direction * PI / 180.0f) * 2.5f;
	float yf = playerPos.Y - sin(zdirection * PI / 180.0f) * 2.5f;
	float zf = playerPos.Z + sin(direction * PI / 180.0f) * 2.5f;

	camera->setPosition(core::vector3df(xf, yf, zf));
	camera->setTarget(core::vector3df(playerPos.X, playerPos.Y + 2.0f, playerPos.Z));
	playerNode->setRotation(core::vector3df(0, direction-90, 0));
}