#pragma once
#include "Item.h"

class ItemDatabase
{

public:
	Item itemDB[103];
	//std::vector<Item*> itemDB;

public:
	ItemDatabase();
	~ItemDatabase();

	void Initialize();

	Item getItem(int itemID);

};

//allows for readable reference to objects in itemDB
enum
{
	//Bronze Items
	bronzeOre,
	bronzeDagger,
	bronzeSword,
	bronzeAxe,
	bronzeHelmet,
	bronzeChest,
	bronzePlateLegs,
	bronzeBoots,

	//Iron Items
	ironOre,
	ironDagger,
	ironSword,
	ironAxe,
	ironHelmet,
	ironChest,
	ironPlateLegs,
	ironBoots,

	//Obsidian Items
	coalOre,
	obsidianOre,
	obsidianDagger,
	obsidianSword,
	obsidianAxe,
	obsidianHelmet,
	obsidianChest,
	obsidianPlateLegs,
	obsidianBoots,

	//Gold Items
	goldOre,
	goldHelmet,
	goldChest,
	goldPlateLegs,
	goldBoots,

	//Leather Items
	bearLeatherBoots,
	bearLeatherChest,
	bearLeatherLeggings,
	boarLeatherBoots,
	boarLeatherChest,
	boarLeatherLeggings,
	leopardLeatherBoots,
	leopardLeatherChest,
	leopardLeatherLeggings,

	//Cloth Items
	clothExcellent,
	clothFine,
	clothSimple,
	clothTorn,

	//Food Items
	bread,
	cookedBearMeat,
	cookedBoarMeat,
	cookedEgg,
	cookedLeopardMeat,
	pasta,
	scrambledEgg,
	unknownSoup,

	//Jewelry Items
	silverOre,
	diamondEarrings,
	diamondNecklace,
	diamondRing,
	emeraldEarrings,
	emeraldRing,
	garnetEarrings,
	garnetNecklace,
	garnetRing,
	pearlEarrings,
	pearlNecklace,
	pearlRing,
	rubyEarrings,
	rubyNecklace,
	rubyRing,
	sapphireEarrings,
	sapphireNecklace,
	sapphireRing,
	pearlEmerald,
	pearlGarnet,

	//Ingrediant Items
	ingrediantBasil,
	ingrediantBearMeat,
	ingrediantBoarMeat,
	ingrediantButter,
	ingrediantEgg,
	ingrediantFlour,
	ingrediantLeopardMeat,
	ingrediantLettuce,
	ingrediantMilk,
	ingrediantPepper,
	ingrediantSalt,
	ingrediantTomato,
	ingrediantWater,

	//Jewelry Material Items
	jewelDiamond,
	jewelEmerald,
	jewelGarnet,
	jewelPearl,
	jewelRuby,
	jewelSapphire,

	//Wood Items
	woodAsh,
	woodCherry,
	woodMahogan,
	woodMaple,
	woodOak,
	woodWalnut,

	//Alchemy Ingrediant Items
	sandOre,
	alcSaltWater,

	//Silver Items
	silverHelmet,
	silverChest,
	silverPlateLegs,
	silverBoots,

	//ship suplies
	supplies
};