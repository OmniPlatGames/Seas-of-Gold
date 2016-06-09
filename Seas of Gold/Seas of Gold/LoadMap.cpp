#include "LoadMap.h"

void LoadMap::Load(ISceneManager* smgr, IrrlichtDevice* device, int map){
	IAnimatedMesh* merch = smgr->getMesh(mapData.MapMerchants[map].c_str());
	IAnimatedMeshSceneNode* merchNode = smgr->addAnimatedMeshSceneNode(merch);

	IAnimatedMesh* foliage = smgr->getMesh(mapData.MapAssets[map].c_str());
	IAnimatedMeshSceneNode* foliageNode = smgr->addAnimatedMeshSceneNode(foliage);

	IAnimatedMesh* mapFile = smgr->getMesh(mapData.MapFiles[1].c_str());
	seasNode = smgr->addOctreeSceneNode(mapFile, 0, -1, 32, false);

	for (int i = 0; i < merchNode->getMaterialCount(); i++)
	{
		merchNode->getMaterial(i).NormalizeNormals = true;
	}

	for (int i = 0; i < foliageNode->getMaterialCount(); i++)
	{
		foliageNode->getMaterial(i).MaterialType = EMT_TRANSPARENT_ALPHA_CHANNEL;
	}
}