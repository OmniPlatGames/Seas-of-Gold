#include "ItemDatabase.h"

//initialize all the items in the game here for easy reference throughout the rest of the program
ItemDatabase::ItemDatabase()
{
}


ItemDatabase::~ItemDatabase()
{

}

void ItemDatabase::Initialize()
{
	//////////////////
	//Bronze Items
	//////////////////
	itemDB[0] = Item(0, "Bronze Ore", "Sprites/Ore_Bronze.png", CostTable(238, 119, 214, 107, 286, 143));
	itemDB[1] = Item(1, "Bronze Dagger", "Sprites/Bronze_dagger.png", CostTable(476, 238, 428, 214, 571, 286));
	itemDB[2] = Item(2, "Bronze Sword", "Sprites/Bronze_Sword.png", CostTable(952, 476, 857, 428, 1142, 571));
	itemDB[3] = Item(3, "Bronze Axe", "Sprites/Bronze_Axe.png", CostTable(1190, 595, 1071, 536, 1428, 714));
	itemDB[4] = Item(4, "Bronze Helmet", "Sprites/Bronze_helmet.png", CostTable(595, 297, 536, 268, 714, 357));
	itemDB[5] = Item(5, "Bronze Chest", "Sprites/Bronze_Chest.png", CostTable(1666, 833, 1499, 750, 1999, 1000));
	itemDB[6] = Item(6, "Bronze Plate Legs", "Sprites/Bronze_LegPlates.png", CostTable(595, 297,536,268,714,357));
	itemDB[7] = Item(7, "Bronze Boots", "Sprites/Bronze_Boots.png", CostTable(714,357,643,321,857,428));

	//////////////////
	//Iron Items
	//////////////////
	itemDB[8] = Item(8, "Iron Ore", "Sprites/Ore_Iron.png", CostTable(124,62,112,56,149,74));
	itemDB[9] = Item(9, "Iron Dagger", "Sprites/Iron_dagger.png", CostTable(248,124,223,112,298,149));
	itemDB[10] = Item(10, "Iron Sword", "Sprites/Iron_Sword.png", CostTable(496,248,446,223,595,298));
	itemDB[11] = Item(11, "Iron Axe", "Sprites/Iron_Axe.png", CostTable(620,310,558,279,744,372));
	itemDB[12] = Item(12, "Iron Helmet", "Sprites/Iron_helmet.png", CostTable(310,155,279,140,372,186));
	itemDB[13] = Item(13, "Iron Chest", "Sprites/Iron_Chest.png", CostTable(868,434,781,391,1042,521));
	itemDB[14] = Item(14, "Iron Plate Legs", "Sprites/Iron_LegPlates.png", CostTable(310,155,279,140,372,186));
	itemDB[15] = Item(15, "Iron Boots", "Sprites/Iron_Boots.png", CostTable(372,186,335,167,446,223));

	//////////////////
	//Obsidian Items
	//////////////////
	itemDB[16] = Item(16, "Coal Ore", "Sprites/Ore_Coal.png", CostTable(53,26,48,24,64,32));
	itemDB[17] = Item(17, "Obsidian Ore", "Sprites/Ore_Obsidian.png", CostTable(738,369,664,332,886,443));
	itemDB[18] = Item(18, "Obsidian Dagger", "Sprites/Obsidian_dagger.png", CostTable(1476,738,1328,664,1771,886));
	itemDB[19] = Item(19, "Obsidian Sword", "Sprites/Obsidian_Sword.png", CostTable(2952,1476,2657,1328,3542,1771));
	itemDB[20] = Item(20, "Obsidian Axe", "Sprites/Obsidian_Axe.png", CostTable(3690,1845,3321,1661,4428,2214));
	itemDB[21] = Item(21, "Obsidian Helmet", "Sprites/Obsidian_helmet.png", CostTable(1845,922,1661,830,2214,1107));
	itemDB[22] = Item(22, "Obsidian Chest", "Sprites/Obsidian_Chest.png", CostTable(5166,2583,4649,2325,6199,3100));
	itemDB[23] = Item(23, "Obsidian Plate Legs", "Sprites/Obsidian_LegPlates.png", CostTable(1845,922,1661,830,2214,1107));
	itemDB[24] = Item(24, "Obsidian Boots", "Sprites/Obsidian_Boots.png", CostTable(2214,1107,1993,996,2657,1328));

	//////////////////
	//Gold Items
	//////////////////
	itemDB[25] = Item(25, "Gold Ore", "Sprites/Ore_Gold.png", CostTable(418,209,376,188,502,251));
	itemDB[26] = Item(26, "Gold Helmet", "Sprites/Gold_helmet.png", CostTable(1045,522,941,470,1254,627));
	itemDB[27] = Item(27, "Gold Chest", "Sprites/Gold_Chest.png", CostTable(2926,1463,2633,1317,3511,1756));
	itemDB[28] = Item(28, "Gold Plate Legs", "Sprites/Gold_LegPlates.png", CostTable(1045, 522, 941, 470, 1254, 627));
	itemDB[29] = Item(29, "Gold Boots", "Sprites/Gold_Boots.png", CostTable(1254,627,1129,564,1505,752));

	//////////////////
	//Leather Items
	//////////////////
	itemDB[30] = Item(30, "Bear Leather Boots", "Sprites/Bear_LeatherBoots.png", CostTable());
	itemDB[31] = Item(31, "Bear Leather Chest", "Sprites/Bear_LeatherChest.png", CostTable());
	itemDB[32] = Item(32, "Bear Leather Leggings", "Sprites/Bear_LeatherLeggings.png", CostTable());
	itemDB[33] = Item(33, "Boar Leather Boots", "Sprites/Boar_LeatherBoots.png", CostTable());
	itemDB[34] = Item(34, "Boar Leather Chest", "Sprites/Boar_LeatherChest.png", CostTable());
	itemDB[35] = Item(35, "Boar Leather Leggings", "Sprites/Boar_LeatherLeggings.png", CostTable());
	itemDB[36] = Item(36, "Leopard Leather Boots", "Sprites/Bear_LeatherBoots.png", CostTable());
	itemDB[37] = Item(37, "Leopard Leather Chest", "Sprites/Bear_LeatherChest.png", CostTable());
	itemDB[38] = Item(38, "Leopard Leather Leggings", "Sprites/Bear_LeatherLeggings.png", CostTable());

	//////////////////
	//Cloth Items
	//////////////////
	itemDB[39] = Item(39, "Cloth Excellent", "Sprites/Cloth_Excellent.png", CostTable());
	itemDB[40] = Item(40, "Cloth Fine", "Sprites/Cloth_Fine.png", CostTable());
	itemDB[41] = Item(41, "Cloth Simple", "Sprites/Cloth_Simple.png", CostTable());
	itemDB[42] = Item(42, "Cloth Torn", "Sprites/Cloth_Torn.png", CostTable());

	//////////////////
	//Food Items
	//////////////////
	itemDB[43] = Item(43, "Bread", "Sprites/Bread.png", CostTable());
	itemDB[44] = Item(44, "Cooked Bear Meat", "Sprites/Cooked_BearMeat.png", CostTable());
	itemDB[45] = Item(45, "Cooked Boar Meat", "Sprites/Cooked_BoarMeat.png", CostTable());
	itemDB[46] = Item(46, "Cooked Egg", "Sprites/Cooked_Egg.png", CostTable());
	itemDB[47] = Item(47, "Cooked Leopard Meat", "Sprites/Cooked_LeopardMeat.png", CostTable());
	itemDB[48] = Item(48, "Pasta", "Sprites/Pasta.png", CostTable());
	itemDB[49] = Item(49, "Scrambled Egg", "Sprites/ScrambledEgg.png", CostTable());
	itemDB[50] = Item(50, "Unknown Soup", "Sprites/UnknownSoup.png", CostTable());

	//////////////////
	//Jewelry Items
	//////////////////
	itemDB[51] = Item(51, "Silver Ore", "Sprites/Ore_Silver.png", CostTable());
	itemDB[52] = Item(52, "Diamond Earrings", "Sprites/Diamond_Earrings.png", CostTable());
	itemDB[53] = Item(53, "Diamond Necklace", "Sprites/Diamond_Necklace.png", CostTable());
	itemDB[54] = Item(54, "Diamond Ring", "Sprites/Diamond_Ring.png", CostTable());
	itemDB[55] = Item(55, "Emerald Earrings", "Sprites/Emerald_Earrings.png", CostTable());
	itemDB[56] = Item(56, "Emerald Ring", "Sprites/Emerald_Ring.png", CostTable());
	itemDB[57] = Item(57, "Garnet Earrings", "Sprites/Garnet_Earrings.png", CostTable());
	itemDB[58] = Item(58, "Garnet Necklace", "Sprites/Garnet_Necklace.png", CostTable());
	itemDB[59] = Item(59, "Garnet Ring", "Sprites/Garnet_Ring.png", CostTable());
	itemDB[60] = Item(60, "Pearl Earrings", "Sprites/Pearl_Earrings.png", CostTable());
	itemDB[61] = Item(61, "Pearl Necklace", "Sprites/Pearl_Necklace.png", CostTable());
	itemDB[62] = Item(62, "Pearl Ring", "Sprites/Pearl_Ring.png", CostTable());
	itemDB[63] = Item(63, "Ruby Earrings", "Sprites/Ruby_Earrings.png", CostTable());
	itemDB[64] = Item(64, "Ruby Necklace", "Sprites/Ruby_Necklace.png", CostTable());
	itemDB[65] = Item(65, "Ruby Ring", "Sprites/Ruby_Ring.png", CostTable());
	itemDB[66] = Item(66, "Sapphire Earrings", "Sprites/Sapphire_Earrings.png", CostTable());
	itemDB[67] = Item(67, "Sapphire Necklace", "Sprites/Sapphire_Necklace.png", CostTable());
	itemDB[68] = Item(68, "Sapphire Ring", "Sprites/Sapphire_Ring.png", CostTable());
	itemDB[69] = Item(69, "Pearl Emerald Earrings", "Sprites/Pearl_Emerald.png", CostTable());
	itemDB[70] = Item(70, "Pearl Garnet Earrings", "Sprites/Pearl_Garnet.png", CostTable());

	//////////////////
	//Ingrediant Items
	//////////////////
	itemDB[71] = Item(71, "Basil", "Sprites/Ingrediant_Basil.png", CostTable());
	itemDB[72] = Item(72, "Bear Meat", "Sprites/Ingrediant_BearMeat.png", CostTable());
	itemDB[73] = Item(73, "Boar Meat", "Sprites/Ingrediant_BoarMeat.png", CostTable());
	itemDB[74] = Item(74, "Butter", "Sprites/Ingrediant_Butter.png", CostTable());
	itemDB[75] = Item(75, "Egg", "Sprites/Ingrediant_Egg.png", CostTable());
	itemDB[76] = Item(76, "Flour", "Sprites/Ingrediant_Flour.png", CostTable());
	itemDB[77] = Item(77, "Leopard Meat", "Sprites/Ingrediant_LeopardMeat.png", CostTable());
	itemDB[78] = Item(78, "Lettuce", "Sprites/Ingrediant_Lettuce.png", CostTable());
	itemDB[79] = Item(79, "Milk", "Sprites/Ingrediant_Milk.png", CostTable());
	itemDB[80] = Item(80, "Pepper", "Sprites/Ingrediant_Pepper.png", CostTable());
	itemDB[81] = Item(81, "Salt", "Sprites/Ingrediant_Salt.png", CostTable());
	itemDB[82] = Item(82, "Tomato", "Sprites/Ingrediant_Tomato.png", CostTable());
	itemDB[83] = Item(83, "Water", "Sprites/Ingrediant_Water.png", CostTable());

	//////////////////
	//Jewelry Material Items
	//////////////////
	itemDB[84] = Item(84, "Jewel Diamond", "Sprites/Jewel_Diamond.png", CostTable());
	itemDB[85] = Item(85, "Jewel Emerald", "Sprites/Jewel_Emerald.png", CostTable());
	itemDB[86] = Item(86, "Jewel Garnet", "Sprites/Jewel_Garnet.png", CostTable());
	itemDB[87] = Item(87, "Jewel Pearl", "Sprites/Jewel_Pearl.png", CostTable());
	itemDB[88] = Item(88, "Jewel Ruby", "Sprites/Jewel_Ruby.png", CostTable());
	itemDB[89] = Item(89, "Jewel Sapphire", "Sprites/Jewel_Sapphire.png", CostTable());

	//////////////////
	//Wood Items
	//////////////////
	itemDB[90] = Item(90, "Wood Ash", "Sprites/Wood_ash.png", CostTable());
	itemDB[91] = Item(91, "Wood Cherry", "Sprites/Wood_cherry.png", CostTable());
	itemDB[92] = Item(92, "Wood Mahogan", "Sprites/Wood_Mahogan.png", CostTable());
	itemDB[93] = Item(93, "Wood Maple", "Sprites/Wood_maple.png", CostTable());
	itemDB[94] = Item(94, "Wood Oak", "Sprites/Wood_Oak.png", CostTable());
	itemDB[95] = Item(95, "Wood Walnut", "Sprites/Wood_Walnut.png", CostTable());

	//////////////////
	//Alchemy Ingrediant Items
	//////////////////
	itemDB[96] = Item(96, "Sand Ore", "Sprites/Ore_Sand.png", CostTable());
	itemDB[97] = Item(97, "Alchemy Salt Water", "Sprites/AlcIngrediant_SaltWater.png", CostTable());

	//////////////////
	//Silver Items
	//////////////////
	itemDB[98] = Item(98, "Silver Helmet", "Sprites/Silver_helmet.png", CostTable());
	itemDB[99] = Item(99, "Silver Chest", "Sprites/Silver_Chest.png", CostTable());
	itemDB[100] = Item(100, "Silver Plate Legs", "Sprites/Silver_LegPlates.png", CostTable());
	itemDB[101] = Item(101, "Silver Boots", "Sprites/Silver_Boots.png", CostTable());

	//////////////////
	//Ship supplies
	//////////////////
	itemDB[102] = Item(102, "Ship Supplies", "Sprites/crate.png", CostTable());
}

Item ItemDatabase::getItem(int itemID)
{
	Item result = itemDB[itemID];
	return result;

}