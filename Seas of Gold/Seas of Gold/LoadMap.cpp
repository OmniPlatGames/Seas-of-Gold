#include "LoadMap.h"

void LoadMap::Load(ISceneManager* smgr, IrrlichtDevice *device, int map)
{
	//Load Merchant
	IAnimatedMesh* merch = smgr->getMesh(mapData.MapMerchants[map].c_str());
	IAnimatedMeshSceneNode* merchNode = smgr->addAnimatedMeshSceneNode(merch);
	for (int i = 0; i < merchNode->getMaterialCount(); i++)
	{
		merchNode->getMaterial(i).NormalizeNormals = true;
	}

	//Load Vendors table
	IAnimatedMesh* vndTbl = smgr->getMesh(mapData.MapVendorTable[map].c_str());
	IAnimatedMeshSceneNode* vndTblNode = smgr->addAnimatedMeshSceneNode(vndTbl);

	//Load Crafting table
	IAnimatedMesh* crfTbl = smgr->getMesh(mapData.MapCraftingTable[map].c_str());
	IAnimatedMeshSceneNode* crfTblNode = smgr->addAnimatedMeshSceneNode(crfTbl);
	
	//Load Map Decor
	IAnimatedMesh* foliage = smgr->getMesh(mapData.MapAssets[map].c_str());
	IAnimatedMeshSceneNode* foliageNode = smgr->addAnimatedMeshSceneNode(foliage);
	for (int i = 0; i < foliageNode->getMaterialCount(); i++)
	{
		foliageNode->getMaterial(i).MaterialType = EMT_TRANSPARENT_ALPHA_CHANNEL;
	}

	//Load map
	IAnimatedMesh* mapFile = smgr->getMesh(mapData.MapFiles[map].c_str());
	seasNode = smgr->addOctreeSceneNode(mapFile, 0, -1, 32, false);

	//set table locations based on which map is loaded
	switch (map)
	{
	case Map_England:	vndTblNode->setPosition(v3d(-17.11, 0, -15.28));
						vndTblNode->setRotation(v3d(0, -90, 0));
						crfTblNode->setPosition(v3d(-13.3, 0, 43.7));
						crfTblNode->setRotation(v3d(0, 90, 0));
						break;
	case Map_Africa:	break;
	case Map_India:		break;
	}

	
}
