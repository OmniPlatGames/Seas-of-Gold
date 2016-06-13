#include "LoadMap.h"

LoadMap::~LoadMap()
{
	/*seasNode->drop();
	foliageNode->drop();
	crfTblNode->drop();
	vndTblNode->drop();
	merchNode->drop();
	CollNode->drop();*/
}
bool loaded = false;
void LoadMap::Load(ISceneManager* smgr, IrrlichtDevice *device, ITriangleSelector* selector, IAnimatedMeshSceneNode* plyrNode, ISceneNodeAnimator* anim, int map)
{
	
	if(rmapNode)
		Unload();

	//Load Merchant
	IAnimatedMesh* merch = smgr->getMesh(mapData.MapMerchants[map].c_str());
	merchNode = smgr->addAnimatedMeshSceneNode(merch);
	for (int i = 0; i < merchNode->getMaterialCount(); i++)
	{
		merchNode->getMaterial(i).NormalizeNormals = true;
	}

	//Load Vendors table
	IAnimatedMesh* vndTbl = smgr->getMesh(mapData.MapVendorTable[map].c_str());
	vndTblNode = smgr->addAnimatedMeshSceneNode(vndTbl);

	//Load Crafting table
	IAnimatedMesh* crfTbl = smgr->getMesh(mapData.MapCraftingTable[map].c_str());
	crfTblNode = smgr->addAnimatedMeshSceneNode(crfTbl);
	for (int i = 0; i < crfTblNode->getMaterialCount(); i++)
	{
		crfTblNode->getMaterial(i).NormalizeNormals = true;
	}
	
	//Load Map Decor
	IAnimatedMesh* foliage = smgr->getMesh(mapData.MapAssets[map].c_str());
	foliageNode = smgr->addAnimatedMeshSceneNode(foliage);
	for (int i = 0; i < foliageNode->getMaterialCount(); i++)
	{
		foliageNode->getMaterial(i).MaterialType = EMT_TRANSPARENT_ALPHA_CHANNEL;
	}

	//Load rendered map
	IAnimatedMesh* rmap = smgr->getMesh(mapData.MapFiles[map].c_str());
	rmapNode = smgr->addAnimatedMeshSceneNode(rmap);
	for (int i = 0; i < rmapNode->getMaterialCount(); i++)
	{
		rmapNode->getMaterial(i).NormalizeNormals = true;
	}
	//IAnimatedMesh* mapFile = smgr->getMesh(mapData.MapFiles[map].c_str());
	////seasNode = smgr->addOctreeSceneNode(mapFile, 0, -1, 32, false);
	//seasNode = smgr->addAnimatedMeshSceneNode(mapFile);

	//load collision map
	IMesh* CollMapFile = smgr->getMesh(mapData.MapColl[map].c_str());
	CollNode = smgr->addOctreeSceneNode(CollMapFile, 0, -1, 32, false);
	CollNode->setVisible(false);
	
	for (int i = 0; i < CollNode->getMaterialCount(); i++)
	{
		CollNode->getMaterial(i).NormalizeNormals = true;
	}
	CollNode->getMaterial(0).MaterialType = EMT_TRANSPARENT_ALPHA_CHANNEL;

	//set table locations based on which map is loaded
	switch (map)
	{
	case Map_England:	vndTblNode->setPosition(v3d(-17.11f, 0, -15.28f));
						vndTblNode->setRotation(v3d(0, -90.0f, 0));
						crfTblNode->setPosition(v3d(-13.3f, 0, 42.5f));
						crfTblNode->setRotation(v3d(0, 0, 0));
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

	setCollisions(smgr, selector, plyrNode, anim);
	
	loaded = true;
}

void LoadMap::Unload()
{
	rmapNode->~IAnimatedMeshSceneNode();
	foliageNode->~IAnimatedMeshSceneNode();
	crfTblNode->~IAnimatedMeshSceneNode();
	vndTblNode->~IAnimatedMeshSceneNode();
	merchNode->~IAnimatedMeshSceneNode();	
	//bandaid fix until better way found -Allen
	CollNode->setPosition(v3d(100.0f, -1000.0f, 100.0f));
}

void LoadMap::setCollisions(ISceneManager* smgr, ITriangleSelector* selector, IAnimatedMeshSceneNode* plyrNode, ISceneNodeAnimator* anim)
{

	/*if (CollNode)
	{
		selector = smgr->createOctreeTriangleSelector(CollNode->getMesh(), CollNode, 32);

		for (int i = 0; i < CollNode->getMaterialCount(); i++)
		{
			CollNode->getMaterial(i).NormalizeNormals = true;
		}
		CollNode->setTriangleSelector(selector);
	}

	if (selector)
	{
		anim = smgr->createCollisionResponseAnimator(selector, plyrNode, v3d(0.6f, 0.75f, 0.4f), v3d(0.0f, -0.05f, 0.0f),
			v3d(0.0f, -0.725f, 0.0f));
		plyrNode->addAnimator(anim);
	}*/
}
