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
#include "CraftingMenu.h"
#include"LoadMap.h"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

float direction = 0, zdirection = 0;
vector3df dirLightVector = vector3df(0.0f, 0.0f, 1.0f);
void moveCameraControl(IAnimatedMeshSceneNode*, IrrlichtDevice*, ICameraSceneNode*);
bool menuloop = true;

Input input;

enum eMenuState { None, Main, Trade, Map, Craft };

int main()
{
	int skyR = 30, skyG = 30, skyB = 70;
	int timer = 0;
	SColor sky = SColor(255, skyR, skyG, skyB);
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9, dimension2d<u32>(800, 600), 16, false, true, false, &input);
	if (!device) return 1;
	float plPos_x = 0.0f, plPos_y = 0.0f, plPos_z = 0.0f;
	bool xTest_M = false;
	bool zTest_M = false;
	bool xTest_C = false;
	bool zTest_C = false;
	bool updateCam = true;
	bool menu1 = false;
	LoadMap loadMap;

	device->setWindowCaption(L"Seas of Gold");  //Updated JFarley
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	video::E_DRIVER_TYPE driverType = driverChoiceConsole();
	EffectHandler *effect = new EffectHandler(device, driver->getScreenSize(), false, true);
	E_FILTER_TYPE filterType = (E_FILTER_TYPE)core::clamp<u32>((u32)3 - '1', 0, 4);

	ITexture* merchMess = driver->getTexture("Assets/merchMess.png");
	ITexture* crftMess = driver->getTexture("Assets/crftMess.png");

	// Load the map scene
	loadMap.Load(smgr, device, Map_India);

	IAnimatedMesh* player = smgr->getMesh("Assets/player.x");
	if (!player) { device->drop(); return 1; }
	IAnimatedMeshSceneNode *plyrNode = smgr->addAnimatedMeshSceneNode(player);
	for (int i = 0; i < plyrNode->getMaterialCount(); i++)
	{
		plyrNode->getMaterial(i).NormalizeNormals = true;
	}
	bool plyrWalk = false;
	plyrNode->setPosition(vector3df(5.0f, 0.1f, 5.0f));
	//plyrNode->setDebugDataVisible((scene::E_DEBUG_SCENE_TYPE)(plyrNode->isDebugDataVisible() ^ scene::EDS_BBOX));

	ICameraSceneNode* camera = smgr->addCameraSceneNode(0, plyrNode->getPosition() + vector3df(0, 2, 2), vector3df(0, 0, 100));

	//*******************Collisions*************************
	//unused variables, but needed to use player movement control function in IRRLICHT
	triangle3df triout;
	vector3df hitPos;
	bool falling;
	ISceneNode *outfalling;


	scene::ITriangleSelector* selector = 0;

	if (loadMap.seasNode)
	{
		selector = smgr->createOctreeTriangleSelector(loadMap.seasNode->getMesh(), loadMap.seasNode, 32);

		for (int i = 0; i < loadMap.seasNode->getMaterialCount(); i++)
		{
			loadMap.seasNode->getMaterial(i).NormalizeNormals = true;
		}
		loadMap.seasNode->setTriangleSelector(selector);
	}

	if (selector)
	{
		ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector, plyrNode, vector3df(0.6f, 0.75f, 0.4f), core::vector3df(0.0f, -0.05f, 0.0f), core::vector3df(0.0f, -0.725f, 0.0f));
		//selector->drop();
		plyrNode->addAnimator(anim);
		anim->drop();
	}

	ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();

	//*****************End Collisions section**********************

	////////////// The Sun ////////////
	ILightSceneNode *sun_node;
	SLight sun_data;
	ISceneNode *sun_billboard;
	float sun_angle = 0;
	video::SColorf Diffuse_Night = video::SColorf(0.0f, 0.0f, 0.0f, 1.0f);
	video::SColorf Diffuse_Day = video::SColorf(1.0f, 1.0f, 1.0f, 1.0f);

	sun_node = smgr->addLightSceneNode();
	sun_data.Direction = vector3df(0, 0, 0);
	sun_data.Type = video::ELT_DIRECTIONAL;
	sun_data.AmbientColor = video::SColorf(0.1f, 0.1f, 0.1f, 1);
	sun_data.SpecularColor = video::SColorf(0, 0, 0, 0);
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
	Item* itemCi = new Item("Iron Ore", 1);
	p.getItems()->addItem(itemCi);
	Item* itemCb = new Item("Bronze Ore", 1);
	p.getItems()->addItem(itemCb);

	Vendor vN;
	Item* itemG = new Item("Gold Ore", 1000);
	vN.getItems()->addItem(itemG);
	Vendor vS;
	Item* itemI = new Item("Iron Ore", 1000);
	vS.getItems()->addItem(itemI);
	Vendor vE;
	Item* itemB = new Item("Bronze Ore", 1000);
	vE.getItems()->addItem(itemB);

	// Make the menus
	MainMenu mainMenu(device);

	MapMenu mapMenu(device, driver);
	mapMenu.SetPlayer(&p);

	TradeMenu tradeMenu(device, driver);
	tradeMenu.SetPlayer(&p);
	tradeMenu.SetVendor(&vS);

	CraftingMenu craftMenu(device, driver);
	craftMenu.SetPlayer(&p);

	int state = Main;

	//////////////////////////////////////////////////////////////////////////
	// Initialize timer to compute elapsed time between frames
	//////////////////////////////////////////////////////////////////////////
	__int64 cntsPerSec = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&cntsPerSec);
	float secsPerCnt = 1.0f / (float)cntsPerSec;

	__int64 prevTimeStamp = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTimeStamp);

	while (device->run())
	{
		//for scaling animation by time, not by frame
		__int64 currTimeStamp = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTimeStamp);
		float dt = (currTimeStamp - prevTimeStamp) * secsPerCnt;

		sun_node->setRotation(vector3df(sun_angle, 0.0f, 0.0f));
		sun_angle += dt;
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
		plPos_x = 0.0f;
		plPos_z = 0.0f;

		///// Movement control! ///////////
		bool movetest = false;

		if (GetAsyncKeyState(0x57)) //W key
		{
			plPos_z = -0.05f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plPos_x = -0.05f * (sin((plyrNode->getRotation().Y)*PI / 180));
			movetest = true;
			if (plyrWalk == false)
			{
				plyrNode->setFrameLoop(40, 90);
				plyrNode->setAnimationSpeed(30);
				plyrWalk = true;
			}
		}
		if (GetAsyncKeyState(0x53)) //S key
		{
			plPos_z = 0.05f * (cos((plyrNode->getRotation().Y)*PI / 180));
			plPos_x = 0.05f * (sin((plyrNode->getRotation().Y)*PI / 180));
			movetest = true;
			if (plyrWalk == false)
			{
				plyrNode->setFrameLoop(40, 90);
				plyrNode->setAnimationSpeed(-30);
				plyrWalk = true;
			}
		}
		if (GetAsyncKeyState(0x44)) // D key
		{
			plPos_z = 0.05f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plPos_x = -0.05f * (cos((plyrNode->getRotation().Y)*PI / 180));
			movetest = true;

		}
		if (GetAsyncKeyState(0x41)) // A key
		{
			plPos_z = -0.05f * (sin((plyrNode->getRotation().Y)*PI / 180));
			plPos_x = 0.05f * (cos((plyrNode->getRotation().Y)*PI / 180));
			movetest = true;

		}
		//if(!plyrWalk)
		if (!movetest)
		{
			plyrNode->setFrameLoop(10, 30);
			plyrWalk = false;
		}
		////// End Movement Control ////////////


		vector3df plPos = vector3df(plPos_x, plPos_y, plPos_z);

		//controls player's movement
		plyrNode->setPosition(collMan->getCollisionResultPosition(selector, plyrNode->getPosition(), core::vector3df(0.01f, 0.01f, 0.01f), plPos, triout, hitPos, falling, outfalling, 0.0f, vector3df(0.0f, -0.05f, 0.0f)));
		if (updateCam) moveCameraControl(plyrNode, device, camera);

		//are we in front of the merchant Table?
		if (plyrNode->getPosition().X > 0.0f && plyrNode->getPosition().X < 1.5f) xTest_M = true;
		else xTest_M = false;
		if (plyrNode->getPosition().Z < -2.00f && plyrNode->getPosition().Z > -4.0f) zTest_M = true;
		else zTest_M = false;

		//are we in front of the crafting Table?
		if (plyrNode->getPosition().X > -13.62f && plyrNode->getPosition().X < -13.0f) xTest_C = true;
		else xTest_C = false;
		if (plyrNode->getPosition().Z > -17.14f && plyrNode->getPosition().Z < -15.51f) zTest_C = true;
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
			device->getCursorControl()->setVisible(false);
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

		if (input.IsKeyDown(irr::KEY_KEY_C) && state == None)
		{
			if (state == Craft)
			{
				state = None;
			}
			else
			{
				state = Craft;
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
				break;
			}
			case eMapDest::East:
			{
				state = None;
				itemB = new Item("Bronze Ore", 1000);
				vE.getItems()->addItem(itemB);
				tradeMenu.SetVendor(&vE);
				break;
			}
			case eMapDest::North:
			{
				state = None;
				itemG = new Item("Gold Ore", 1000);
				vN.getItems()->addItem(itemG);
				tradeMenu.SetVendor(&vN);
				break;
			}
			case eMapDest::South:
			{
				state = None;
				itemI = new Item("Iron Ore", 1000);
				vS.getItems()->addItem(itemI);
				tradeMenu.SetVendor(&vS);
				break;
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
		case Craft:
		{
			bool out = craftMenu.Update(&input);
			if (out)
				state = None;
			break;
		}
		default:
		{
			// Do nothing
			break;
		}
		}

		////////////////////////////////////////////////////////

		if (sun_angle > 360) sun_angle = 0;
		if (sun_angle < 180) sun_data.DiffuseColor = Diffuse_Day; else sun_data.DiffuseColor = Diffuse_Night;
		sun_node->setLightData(sun_data);

		sky.setRed(skyR);
		sky.setGreen(skyG);
		sky.setBlue(skyB);
		driver->beginScene(true, true, sky);

		

		smgr->drawAll();

		if (xTest_M && zTest_M)
		{
			driver->draw2DImage(merchMess, vector2d<s32>(300, 300));
			if (GetAsyncKeyState(VK_RETURN))
			{
				/////////////////////////////////////////////

				state = Trade;

				/////////////////////////////////////////////
			}
		}

		if (xTest_C && zTest_C)
		{
			driver->draw2DImage(crftMess, vector2d<s32>(300, 300));
			if (GetAsyncKeyState(VK_RETURN))
			{
				/////////////////////////////////////////////

				state = Craft;

				/////////////////////////////////////////////
			}
		}

		// Draw the menu
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
		case Craft:
		{
			craftMenu.Draw(driver);
			break;
		}
		default:
		{
			// Do nothing
			break;
		}
		}


		driver->endScene();
		
		// Update the prev time stamp to current
		prevTimeStamp = currTimeStamp;


		//close game loop with escape key -- JFarley
		/*if (GetAsyncKeyState(VK_ESCAPE))
		device->closeDevice();*/
	}

	device->drop();

	return 0;
}

void moveCameraControl(IAnimatedMeshSceneNode* playerNode, IrrlichtDevice* device, ICameraSceneNode* camera)
{

	position2d<f32> cursorPos = device->getCursorControl()->getRelativePosition();
	vector3df cameraPos = camera->getAbsolutePosition();
	vector3df playerPos_old;
	float xf, yf, zf;

	float change_x = (cursorPos.X - 0.5) * 256.0f;
	float change_y = (cursorPos.Y - 0.5) * 256.0f;
	direction += change_x;
	zdirection = -90;

	device->getCursorControl()->setPosition(0.5f, 0.5f);

	vector3df playerPos = playerNode->getPosition();

	//if (playerPos != playerPos_old)
	//{
		xf = playerPos.X - cos(direction * PI / 180.0f) * 2.5f;
		yf = playerPos.Y - sin(zdirection * PI / 180.0f) * 2.5f;
		zf = playerPos.Z + sin(direction * PI / 180.0f) * 2.5f;
	//}


	playerPos_old = playerPos;

	camera->setPosition(core::vector3df(xf, yf, zf));
	camera->setTarget(core::vector3df(playerPos.X, playerPos.Y + 2.0f, playerPos.Z));
	playerNode->setRotation(core::vector3df(0, direction - 90, 0));
}