#include <irrlicht.h>
#include <iostream>
#include "WorldObject.h"
#include "Graphics.h"
#include "Item.h"
#include "XEffects.h"
#include "Input.h"
#include "MapMenu.h"
#include "TradeMenu.h"
#include "Player.h"
#include "MainMenu.h"


#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif


float direction=0, zdirection=0;
vector3df dirLightVector = vector3df(0.0f, 0.0f, 1.0f);
void moveCameraControl(IAnimatedMeshSceneNode*, IrrlichtDevice*, ICameraSceneNode*);
bool menuloop = true;

Input input;

enum eMenuState{None,Main,Trade,Map};

IrrlichtDevice* loadGRender()
{
	
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9, dimension2d<u32>(800, 600), 16, false, true, false, &input);


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
	bool xTest_M = false;
	bool zTest_M = false;
	bool xTest_C = false;
	bool zTest_C = false;
	bool updateCam = true;
	bool menu1 = false;


	
	device->setWindowCaption(L"Seas of Gold");  //Updated JFarley
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	video::E_DRIVER_TYPE driverType = driverChoiceConsole();
	EffectHandler *effect = new EffectHandler(device, driver->getScreenSize(), false, true);
	E_FILTER_TYPE filterType = (E_FILTER_TYPE)core::clamp<u32>((u32)3 - '1', 0, 4);


	/*guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);*/  //not needed JFarley

	ITexture* merchMess = driver->getTexture("Assets/merchMess.png");
	ITexture* crftMess = driver->getTexture("Assets/crftMess.png");


	
	//IAnimatedMesh* mesh = smgr->getMesh("sydney.md2");
	IAnimatedMesh* map = smgr->getMesh("Assets/map.x");
	if (!map) { device->drop(); return 1; }
	IAnimatedMeshSceneNode* mapNode = smgr->addAnimatedMeshSceneNode(map);

	IAnimatedMesh* mHut = smgr->getMesh("Assets/mHut.x");
	if (!mHut) { device->drop(); return 2; }
	IAnimatedMeshSceneNode *mHutNode = smgr->addAnimatedMeshSceneNode(mHut);
	mHutNode->getMaterial(0).Lighting = false;

	IAnimatedMesh* cHut = smgr->getMesh("Assets/cHut.x");
	if (!cHut) { device->drop(); return 3; }
	IAnimatedMeshSceneNode *cHutNode = smgr->addAnimatedMeshSceneNode(cHut);

	IAnimatedMesh* dHut = smgr->getMesh("Assets/dHut.x");
	if (!dHut) { device->drop(); return 4; }
	IAnimatedMeshSceneNode *dHutNode = smgr->addAnimatedMeshSceneNode(dHut);

	IAnimatedMesh* merch = smgr->getMesh("Assets/merch.x");
	if (!merch) { device->drop(); return 5; }
	IAnimatedMeshSceneNode *merchNode = smgr->addAnimatedMeshSceneNode(merch);
	for (int i = 0; i < merchNode->getMaterialCount(); i++)
	{
		merchNode->getMaterial(i).NormalizeNormals = true;
	}

	IAnimatedMesh* player = smgr->getMesh("Assets/player.x");
	if (!player) { device->drop(); return 5; }
	IAnimatedMeshSceneNode *plyrNode = smgr->addAnimatedMeshSceneNode(player);
	bool plyrWalk = false;
	plyrNode->setFrameLoop(0, 20);
	plyrNode->setAnimationSpeed(30);
	for (int i = 0; i < plyrNode->getMaterialCount(); i++)
	{
		plyrNode->getMaterial(i).NormalizeNormals=true;
	}
	plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));


	ICameraSceneNode* camera = smgr->addCameraSceneNode(0, plyrNode->getPosition() + vector3df(0, 2, 2), plyrNode->getPosition() + vector3df(0, 2, 0));
	camera->setNearValue(0.5);
	camera->setFarValue(500);
	

	
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

	// Make the player
	Player p;
	p.AddGold(1000);
	p.SetCurrentPort(eMapDest::South);

	Vendor v;

	// Make the menus
	MainMenu mainMenu(device);

	MapMenu mapMenu(device, driver);
	mapMenu.SetPlayer(&p);

	TradeMenu tradeMenu(device,driver);
	tradeMenu.SetPlayer(&p);
	
	int state = Main;

	while (device->run())
	{
		
		///// Movement control! ///////////
		if (GetAsyncKeyState(0x57)) //W key
		{
			plPos_z -= 0.01f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plPos_x -= 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
			if (plyrWalk == false)
			{
				plyrNode->setFrameLoop(40, 90);
				plyrNode->setAnimationSpeed(30);
				plyrWalk = true;
			}

		}
		else if (GetAsyncKeyState(0x53)) //S key
		{
			plPos_z += 0.01f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plPos_x += 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
			if (plyrWalk == false)
			{
				plyrNode->setFrameLoop(40, 90);
				plyrNode->setAnimationSpeed(-30);
				plyrWalk = true;
			}
		}
		else if (GetAsyncKeyState(0x44)) // D key
		{
			plPos_z += 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plPos_x -= 0.01f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
		}
		else if (GetAsyncKeyState(0x41)) // A key
		{
			plPos_z -= 0.01f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plPos_x += 0.01f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plyrNode->setPosition(vector3df(plPos_x, plPos_y, plPos_z));
		}
		else
		{
			plyrNode->setFrameLoop(10, 30);
			plyrWalk = false;
		}
		////// End Movement Control ////////////

		// tests to see if we are using 3rd person camera
		if(updateCam) moveCameraControl(plyrNode, device, camera);


		// are we standing in front of the merchant table??
		if (plyrNode->getPosition().X > 0.96f && plyrNode->getPosition().X < 1.41f) xTest_M = true;
		else xTest_M = false;
		if (plyrNode->getPosition().Z < -2.66f && plyrNode->getPosition().Z > -3.32f) zTest_M = true;
		else zTest_M = false;

		// are we standing in front of the crafting table??
		if (plyrNode->getPosition().X > -13.62f && plyrNode->getPosition().X < -13.0) xTest_C = true;
		else xTest_C = false;
		if (plyrNode->getPosition().Z < -15.51f && plyrNode->getPosition().Z > -17.14) zTest_C = true;
		else zTest_C = false;


		////////////////////////////////////////////////////////
		if (state != None)
		{
			updateCam = false;
			device->getCursorControl()->setVisible(true);
		}
		else
		{
			updateCam = true;
		}

		if (input.IsKeyDown(irr::KEY_KEY_M) && state == None)
		{
			if (state == Map)
			{
				state = None;
			}
			else
			{
				state = Map;
			}
		}

		if (input.IsKeyDown(irr::KEY_ESCAPE) && state == None)
		{
			state = Main;
		}



		switch (state)
		{
		case Map:
		{
			int out = mapMenu.Update(&input);

			switch (out)
			{
			case eMapDest::Exit:
			{
				state = None;
			}
			default:
			{
				break;
			}
			}

			break;
		}
		case Trade:
		{
			bool out = tradeMenu.Update(&input);
			if (out)
				state = None;
			break;
		}
		case Main:
		{
			int out = mainMenu.Update(&input);
			
			switch (out)
			{
			case MSstart:
			{
				state = None;
				break;
			}
			case MSexit:
			{
				device->closeDevice();
				break;
			}
			default:
			{
				break;
			}
			}

			break;
		}
		default:
		{
			// Do nothing
			break;
		}
		}

		////////////////////////////////////////////////////////

		////// sky control /////////
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
		if (sun_angle > 360) sun_angle = 0;
		if (sun_angle < 180) sun_data.DiffuseColor = Diffuse_Day; else sun_data.DiffuseColor = Diffuse_Night;
		sun_node->setLightData(sun_data);

		sky.setRed(skyR);
		sky.setGreen(skyG);
		sky.setBlue(skyB);
		driver->beginScene(true, true, sky);
		/////// end sky control ////////
		
		smgr->drawAll();

		//// display message and menu at merchant ///////
		if (xTest_M && zTest_M)
		{
			driver->draw2DImage(merchMess, vector2d<s32>(300, 300));
			if (GetAsyncKeyState(VK_RETURN))
			{
				// Draw the menu
				state = Trade;
			}
		}

		//// display message and menu at crafting station ///////
		if (xTest_C && zTest_C)
		{
			driver->draw2DImage(crftMess, vector2d<s32>(300, 300));
			if (GetAsyncKeyState(VK_RETURN))
			{
				// Draw the menu
				state = Trade;
			}
		}
		
		
		switch (state)
		{
			case Map:
			{
				mapMenu.Draw(driver);
				break;
			}
			case Trade:
			{
				tradeMenu.Draw(driver);
				break;
			}
			case Main:
			{
				mainMenu.Draw(driver);
				break;
			}
			default:
			{
				// Do nothing
				break;
			}
		}


		driver->endScene();
		

	}

	device->drop();

	return 0;
}

void moveCameraControl(IAnimatedMeshSceneNode* playerNode, IrrlichtDevice* device, ICameraSceneNode* camera)
{
	
	position2d<f32> cursorPos = device->getCursorControl()->getRelativePosition();
	vector3df cameraPos = camera->getAbsolutePosition();

	float change_x = (cursorPos.X - 0.5) * 256.0f;
	float change_y = (cursorPos.Y - 0.5) * 256.0f;
	direction += change_x;
	zdirection = -90;

	device->getCursorControl()->setPosition(0.5f, 0.5f);
	device->getCursorControl()->setVisible(false);

	vector3df playerPos = playerNode->getPosition();

	float xf = playerPos.X - cos(direction * PI / 180.0f) * 2.5f;
	float yf = playerPos.Y - sin(zdirection * PI / 180.0f) * 2.5f;
	float zf = playerPos.Z + sin(direction * PI / 180.0f) * 2.5f;

	camera->setPosition(core::vector3df(xf, yf, zf));
	camera->setTarget(core::vector3df(playerPos.X, playerPos.Y + 2.0f, playerPos.Z));
	playerNode->setRotation(core::vector3df(0, direction-90, 0));
}