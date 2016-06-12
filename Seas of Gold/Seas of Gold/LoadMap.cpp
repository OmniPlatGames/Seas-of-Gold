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
	seasNode->getMaterial(0).MaterialType = EMT_TRANSPARENT_ALPHA_CHANNEL_REF;

	//set table locations based on which map is loaded
	switch (map)
	{
	case Map_England:	vndTblNode->setPosition(v3d(-17.11f, 0, -15.28f));
						vndTblNode->setRotation(v3d(0, -90.0f, 0));
						crfTblNode->setPosition(v3d(-13.3f, 0, 43.7f));
						crfTblNode->setRotation(v3d(0, 90.0f, 0));
						break;
	case Map_India:		vndTblNode->setPosition(v3d(2.0f, 0, -2.5f));
						vndTblNode->setRotation(v3d(0, 65.0f, 0));
						crfTblNode->setPosition(v3d(-14.0f, 0, -16.45f));
						crfTblNode->setRotation(v3d(0, -5.0f, 0));
						break;
	case Map_Africa:	vndTblNode->setPosition(v3d(28.67009f, 0, 38.97609f));
						vndTblNode->setRotation(v3d(0, -45.652f, 0));
						crfTblNode->setPosition(v3d(-24.5f, 0, -27.6f));
						crfTblNode->setRotation(v3d(0, -10.0f, 0));
						break;
	}

	
}
