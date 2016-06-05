#include "LoadMap.h"

void LoadMap::england(ISceneManager* smgr, IrrlichtDevice *device)
{
	IAnimatedMesh* merch = smgr->getMesh("Assets/enMerch.x");
	IAnimatedMeshSceneNode *merchNode = smgr->addAnimatedMeshSceneNode(merch);
	for (int i = 0; i < merchNode->getMaterialCount(); i++)
	{
		merchNode->getMaterial(i).NormalizeNormals = true;
	}

	IAnimatedMesh* trees = smgr->getMesh("Assets/trees_en.3ds");
	IAnimatedMeshSceneNode* treesNode = smgr->addAnimatedMeshSceneNode(trees);
	for (int i = 0; i < treesNode->getMaterialCount(); i++)
	{
		treesNode->getMaterial(i).MaterialType = EMT_TRANSPARENT_ALPHA_CHANNEL;
	}

	IAnimatedMesh* enmap = smgr->getMesh("Assets/map.3ds");
	seasNode = smgr->addOctreeSceneNode(enmap, 0, -1, 32, false);
}

void LoadMap::india(ISceneManager* smgr, IrrlichtDevice *device)
{
	IAnimatedMesh* inmap = smgr->getMesh("Assets/indMap.3ds");
	seasNode = smgr->addOctreeSceneNode(inmap, 0, -1, 32, false);

	IAnimatedMesh* inMerch = smgr->getMesh("Assets/inMerch.x");
	IAnimatedMeshSceneNode *merchNode = smgr->addAnimatedMeshSceneNode(inMerch);
	for (int i = 0; i < merchNode->getMaterialCount(); i++)
	{
		merchNode->getMaterial(i).NormalizeNormals = true;
	}
}
