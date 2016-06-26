#pragma once
#include "Common.h"


enum MapID
{
	Map_England = 0,
	Map_India = 1,
	Map_Africa = 2
};
const int MAP_COUNT = 3;
struct MapData
{
	irrstring* MapFiles = new irrstring[MAP_COUNT];
	irrstring* MapAssets = new irrstring[MAP_COUNT];
	irrstring* MapMerchants = new irrstring[MAP_COUNT];
	irrstring* MapVendorTable = new irrstring[MAP_COUNT];
	irrstring* MapCraftingTable = new irrstring[MAP_COUNT];
	irrstring* MapColl = new irrstring[MAP_COUNT];
	
	void Initialize()
	{
		MapFiles[Map_England] = "Assets/enmap.x";
		MapAssets[Map_England] = "Assets/trees_en.3ds";
		MapMerchants[Map_England] = "Assets/enMerch.x";
		MapVendorTable[Map_England] = "Assets/vndrTble.x";
		MapCraftingTable[Map_England] = "Assets/crftTble.x";
		MapColl[Map_England] = "Assets/enmapcoll.3ds";

		MapFiles[Map_India] = "Assets/indMap.x";
		MapAssets[Map_India] = "Assets/trees_in.3ds";
		MapMerchants[Map_India] = "Assets/inMerch.x";
		MapVendorTable[Map_India] = "Assets/vndrTble.x";
		MapCraftingTable[Map_India] = "Assets/crftTble.x";
		MapColl[Map_India] = "Assets/coll_in.3ds";

		MapFiles[Map_Africa] = "Assets/afMap.x";
		MapAssets[Map_Africa] = "Assets/trees_af.x";
		MapMerchants[Map_Africa] = "Assets/afMerch.x";
		MapVendorTable[Map_Africa] = "Assets/vndrTble.x";
		MapCraftingTable[Map_Africa] = "Assets/crftTble.x";
		MapColl[Map_Africa] = "Assets/coll_af.3ds";

	}
};

class LoadMap
{
	MapData mapData;
public:
	MapID cMap;
	IAnimatedMeshSceneNode* seasNode;
	IAnimatedMeshSceneNode* foliageNode;
	IAnimatedMeshSceneNode* crfTblNode;
	IAnimatedMeshSceneNode* vndTblNode;
	IAnimatedMeshSceneNode* merchNode;
	IAnimatedMeshSceneNode* rmapNode;
	IMeshSceneNode* CollNode;

	void Load(ISceneManager* smgr, IrrlichtDevice *device, ITriangleSelector* selector, IAnimatedMeshSceneNode* plyrNode, ISceneNodeAnimator* anim, IVideoDriver* driver, int map);
	void Unload();
	void setCollisions(ISceneManager* smgr, ITriangleSelector* selector, IAnimatedMeshSceneNode* plyrNode, ISceneNodeAnimator* anim);

	LoadMap()
	{
		mapData.Initialize();
	}

	~LoadMap();

};