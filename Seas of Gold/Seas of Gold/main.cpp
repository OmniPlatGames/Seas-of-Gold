#include <irrlicht.h>
#include <iostream>
#include "WorldObject.h"
#include "Graphics.h"
#include "Item.h"
#include "XEffects.h"
#include "Player.h"
#include "MainMenu.h"
#include "MapMenu.h"
#include "TradeMenu.h"
#include "CraftingMenu.h"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

//function prototype
void InitializeVendors(Vendor &northVendor, Vendor& SouthVendor, Vendor& EastVender, ItemDatabase itemDB);

float direction = 0, zdirection = 0;
vector3df dirLightVector = vector3df(0.0f, 0.0f, 1.0f);
void moveCameraControl(IAnimatedMeshSceneNode*, IrrlichtDevice*, ICameraSceneNode*);
bool menuloop = true;

int main()
{
	Input input;
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9, dimension2d<u32>(800, 600), 16, false, true, false, &input);
	device->setWindowCaption(L"Seas of Gold");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	E_DRIVER_TYPE driverType = driverChoiceConsole();
	EffectHandler *effect = new EffectHandler(device, driver->getScreenSize(), false, true);
	E_FILTER_TYPE filterType = (E_FILTER_TYPE)core::clamp<u32>((u32)3 - '1', 0, 4);

	int skyR = 30, skyG = 30, skyB = 70;
	int timer = 0;
	SColor sky = SColor(255, skyR, skyG, skyB);
	float plPos_x = 0.0f, plPos_y = 0.0f, plPos_z = 0.0f;
	bool updateCam = true;
	bool menu1 = false;
	int state = Main;
	int frameCount = 0;
	LoadMap loadMap;
	Player player;
	Interface playerInterface(driver);
	ITriangleSelector* selector = 0;
	ISceneNodeAnimator* anim = 0;
	Vendor southVendor;
	Vendor eastVendor;
	Vendor northVendor;
	//InitializeVendors(northVendor, southVendor, eastVendor, itemD);

	//ItemDatabase* itemD = new ItemDatabase;
	ItemDatabase itemD;
	itemD.Initialize();

	//initialize player's inventory
	player.AddGold(1000);
	player.getInventory()->addItem(itemD.getItem(bronzeOre), 50);
	player.getInventory()->addItem(itemD.getItem(ironOre), 50);
	player.getInventory()->addItem(itemD.getItem(goldOre), 50);

	//initialize south vendor's inventory
	southVendor.getInventory()->addItem(itemD.getItem(bronzeOre), 100);
	southVendor.getInventory()->addItem(itemD.getItem(coalOre), 100);
	southVendor.getInventory()->addItem(itemD.getItem(supplies), 1000);

	//initialize north vendor's inventory
	northVendor.getInventory()->addItem(itemD.getItem(obsidianOre), 50);
	northVendor.getInventory()->addItem(itemD.getItem(supplies), 1000);

	//initialize south vendor's inventory
	eastVendor.getInventory()->addItem(itemD.getItem(goldOre), 100);
	eastVendor.getInventory()->addItem(itemD.getItem(ironOre), 100);
	eastVendor.getInventory()->addItem(itemD.getItem(supplies), 1000);

	//Item item(0, "bronzeOre", "Sprites/ore_Bronze.png");
	//Item item2 = item;
	//Item* item2 = itemD.getItem(3);
	//inventory.addItem(&item, 2);
	//inventory.addItem(&item, 2);
	//inventory.addItem(item2, 2);

	//int test = 0;

	// Load the map scene
	//loadMap.Load(smgr, device, Map_Africa);
	//loadMap.Load(smgr, device, Map_India);
	//loadMap.Load(smgr, device, selector, plyrNode, anim, Map_England);

	IAnimatedMeshSceneNode* plyrNode = player.loadPlayerNode(device, smgr);
	//plyrNode->setDebugDataVisible((scene::E_DEBUG_SCENE_TYPE)(plyrNode->isDebugDataVisible() ^ scene::EDS_BBOX));

	ICameraSceneNode* camera = smgr->addCameraSceneNode(0, plyrNode->getPosition() + vector3df(0, 2, 2), vector3df(0, 0, 100));

	loadMap.Load(smgr, device, selector, plyrNode, anim, driver, Map_Africa);

	//loadMap.setCollisions(smgr, selector, plyrNode, anim);

	if (loadMap.CollNode)
	{
		selector = smgr->createOctreeTriangleSelector(loadMap.CollNode->getMesh(), loadMap.CollNode, 32);
		for (int i = 0; i < loadMap.CollNode->getMaterialCount(); i++)
		{
			loadMap.CollNode->getMaterial(i).NormalizeNormals = true;
		}
		loadMap.CollNode->setTriangleSelector(selector);
	}

	if (selector)
	{
		anim = smgr->createCollisionResponseAnimator(selector, plyrNode, vector3df(0.6f, 0.75f, 0.4f), core::vector3df(0.0f, -0.05f, 0.0f),
			core::vector3df(0.0f, -0.725f, 0.0f));

		plyrNode->addAnimator(anim);
	}

	ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();

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

	//// Make the player
	//player.AddGold(1000);
	//player.SetCurrentPort(eMapDest::South);
	//Item* itemCi = new Item("Iron Ore", 1);
	//player.getItems()->addItem(itemCi);
	//Item* itemCb = new Item("Bronze Ore", 1);
	//player.getItems()->addItem(itemCb);

	//Vendor vN;
	//Item* itemG = new Item("Gold Ore", 1000);
	//vN.getItems()->addItem(itemG);
	//Vendor vS;
	//Item* itemI = new Item("Iron Ore", 1000);
	//vS.getItems()->addItem(itemI);
	//Vendor vE;
	//Item* itemB = new Item("Bronze Ore", 1000);
	//vE.getItems()->addItem(itemB);
	//Vendor northVendor

	//delete &itemD;

	int test99 = 0;


	// Make the menus
	MainMenu mainMenu(device, driver);

	MapMenu mapMenu(device, driver);
	mapMenu.SetPlayer(&player);

	TradeMenu tradeMenu;
	tradeMenu.Initialize(device, driver, &player, &southVendor);
	//TradeMenu tradeMenu(device, driver);
	//tradeMenu.SetPlayer(&player);
	//tradeMenu.SetVendor(&vS);
	//
	CraftingMenu craftMenu(device, driver, &player, itemD);
	//craftMenu.SetPlayer(&player);

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
		frameCount += 1;
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

		player.updatePlayer(plyrNode, dt, collMan, selector);
		playerInterface.update(plyrNode, loadMap, driver, device, input, updateCam, state);

		switch (state)
		{
		case Map:
		{
			int out = mapMenu.Update(&input, frameCount);

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
				//Item* itemB = new Item("Bronze Ore", 1000);
				//vE.getItems()->addItem(itemB);
				tradeMenu.SetVendor(&eastVendor);
				loadMap.Load(smgr, device, selector, plyrNode, anim, driver, Map_India);
				if (loadMap.CollNode)
				{
					selector = smgr->createOctreeTriangleSelector(loadMap.CollNode->getMesh(), loadMap.CollNode, 32);

					for (int i = 0; i < loadMap.CollNode->getMaterialCount(); i++)
					{
						loadMap.CollNode->getMaterial(i).NormalizeNormals = true;
					}
					loadMap.CollNode->setTriangleSelector(selector);
				}

				if (selector)
				{
					anim = smgr->createCollisionResponseAnimator(selector, plyrNode, vector3df(0.6f, 0.75f, 0.4f), core::vector3df(0.0f, -0.05f, 0.0f),
						core::vector3df(0.0f, -0.725f, 0.0f));
					plyrNode->addAnimator(anim);
				}
				collMan = smgr->getSceneCollisionManager();
				break;
			}
			case eMapDest::North:
			{
				state = None;
				//Item *itemG = new Item("Gold Ore", 1000);
				//vN.getItems()->addItem(itemG);
				//tradeMenu.SetVendor(&vN);
				tradeMenu.SetVendor(&northVendor);
				loadMap.Load(smgr, device, selector, plyrNode, anim, driver, Map_England);
				if (loadMap.CollNode)
				{
					selector = smgr->createOctreeTriangleSelector(loadMap.CollNode->getMesh(), loadMap.CollNode, 32);

					for (int i = 0; i < loadMap.CollNode->getMaterialCount(); i++)
					{
						loadMap.CollNode->getMaterial(i).NormalizeNormals = true;
					}
					loadMap.CollNode->setTriangleSelector(selector);
				}

				if (selector)
				{
					anim = smgr->createCollisionResponseAnimator(selector, plyrNode, vector3df(0.6f, 0.75f, 0.4f), core::vector3df(0.0f, -0.05f, 0.0f),
						core::vector3df(0.0f, -0.725f, 0.0f));
					plyrNode->addAnimator(anim);
				}
				collMan = smgr->getSceneCollisionManager();
				break;
			}
			case eMapDest::South:
			{
				state = None;
				//Item *itemI = new Item("Iron Ore", 1000);
				//vS.getItems()->addItem(itemI);
				//tradeMenu.SetVendor(&vS);
				tradeMenu.SetVendor(&southVendor);
				loadMap.Load(smgr, device, selector, plyrNode, anim, driver, Map_Africa);
				if (loadMap.CollNode)
				{
					selector = smgr->createOctreeTriangleSelector(loadMap.CollNode->getMesh(), loadMap.CollNode, 32);

					for (int i = 0; i < loadMap.CollNode->getMaterialCount(); i++)
					{
						loadMap.CollNode->getMaterial(i).NormalizeNormals = true;
					}
					loadMap.CollNode->setTriangleSelector(selector);
				}

				if (selector)
				{
					anim = smgr->createCollisionResponseAnimator(selector, plyrNode, vector3df(0.6f, 0.75f, 0.4f), core::vector3df(0.0f, -0.05f, 0.0f),
						core::vector3df(0.0f, -0.725f, 0.0f));
					plyrNode->addAnimator(anim);
				}
				collMan = smgr->getSceneCollisionManager();
				break;
			}
			default:
				break;
			}

			break;
		}
		case Trade:
		{

			bool out = false;
			out = tradeMenu.Update(&input, frameCount, device);
			if (out)
				state = None;
			break;
		}
		case Main:
		{
			int out = mainMenu.Update(&input, frameCount);

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
				//return 0;
				break;
			}
			default:
				break;
			}

			break;
		}
		case Craft:
		{
			bool out = craftMenu.Update(&input, frameCount, device);
			if (out)
				state = None;
			break;
		}
		default:
			// Do nothing
			break;
		}

		if (updateCam) moveCameraControl(plyrNode, device, camera);

		////////////////////////////////////////////////////////

		if (sun_angle > 360) sun_angle = 0;
		if (sun_angle < 180) sun_data.DiffuseColor = Diffuse_Day; else sun_data.DiffuseColor = Diffuse_Night;
		sun_node->setLightData(sun_data);

		sky.setRed(skyR);
		sky.setGreen(skyG);
		sky.setBlue(skyB);
		driver->beginScene(true, true, sky);

		smgr->drawAll();

		playerInterface.render(driver, state);

		// Draw the menu
		switch (state)
		{
		case Map:
		{
			mapMenu.Draw(driver, device);
			break;
		}
		case Trade:
		{
			tradeMenu.Render(driver, device);
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
			// Do nothing
			break;
		}

		driver->endScene();
		
		// Update the prev time stamp to current
		prevTimeStamp = currTimeStamp;

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

	xf = playerPos.X - cos(direction * PI / 180.0f) * 2.5f;
	yf = playerPos.Y - sin(zdirection * PI / 180.0f) * 2.5f;
	zf = playerPos.Z + sin(direction * PI / 180.0f) * 2.5f;


	playerPos_old = playerPos;

	camera->setPosition(core::vector3df(xf, yf, zf));
	camera->setTarget(core::vector3df(playerPos.X, playerPos.Y + 2.0f, playerPos.Z));
	playerNode->setRotation(core::vector3df(0, direction - 90, 0));
}

void InitializeVendors(Vendor &northVendor, Vendor& SouthVendor, Vendor& EastVender, ItemDatabase itemDB)
{
	//initialize north vendor's inventory


	//initialize south vendor's inventory
	SouthVendor.getInventory()->addItem(itemDB.getItem(bronzeOre), 50);
	//SouthVendor.getItems()->addItem(itemDB.getItem(3), 50);
	SouthVendor.getInventory()->addItem(itemDB.getItem(bronzeAxe), 50);
	SouthVendor.getInventory()->addItem(itemDB.getItem(bronzeHelmet), 50);
	SouthVendor.getInventory()->addItem(itemDB.getItem(bronzePlateLegs), 50);
										 
	//initialize east vendor's inventory

}