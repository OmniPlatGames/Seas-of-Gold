#pragma once
#include "Common.h"
enum MapID
{
	Map_England = 0,
	Map_India = 1
};
const int MAP_COUNT = 2;
struct MapData
{
	irrstring* MapFiles = new irrstring[MAP_COUNT];
	irrstring* MapAssets = new irrstring[MAP_COUNT];
	irrstring* MapMerchants = new irrstring[MAP_COUNT];
	void Initialize(){
		MapFiles[Map_England] = "Assets/map.3ds";
		MapAssets[Map_England] = "Assets/trees_en.3ds";
		MapMerchants[Map_England] = "Assets/enMerch.x";

		MapFiles[Map_India] = "Assets/indMap.3ds";
		MapMerchants[Map_India] = "Assets/inMerch.x";
		MapAssets[Map_India] = "Assets/trees_en.3ds";
	}
};

class LoadMap
{
	MapData mapData;
public:
	IMeshSceneNode* seasNode;
<<<<<<< HEAD
	void england(ISceneManager* smgr, IrrlichtDevice *device);
	void india(ISceneManager* smgr, IrrlichtDevice *device);
	void africa(ISceneManager* smgr, IrrlichtDevice *device);
=======
	void Load(ISceneManager* smgr, IrrlichtDevice *device, int map);
	LoadMap()
	{
		mapData.Initialize();
	}
>>>>>>> refs/remotes/OmniPlatGames/master
};