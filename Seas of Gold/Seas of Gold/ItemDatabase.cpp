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
	itemDB[0] = Item(0, "Bronze Ore", "Sprites/Ore_Bronze.png");
	itemDB[1] = Item(1, "Bronze Dagger", "Sprites/Bronze_dagger.png");
	itemDB[2] = Item(2, "Bronze Sword", "Sprites/Bronze_Sword.png");
	itemDB[3] = Item(3, "Bronze Axe", "Sprites/Bronze_Axe.png");
	itemDB[4] = Item(4, "Bronze Helmet", "Sprites/Bronze_helmet.png");
	itemDB[5] = Item(5, "Bronze Chest", "Sprites/Bronze_Chest.png");
	itemDB[6] = Item(6, "Bronze Plate Legs", "Sprites/Bronze_LegPlates.png");
	itemDB[7] = Item(7, "Bronze Boots", "Sprites/Bronze_Boots.png");

	//////////////////
	//Iron Items
	//////////////////
	itemDB[8] = Item(8, "Iron Ore", "Sprites/Ore_Iron.png");
	itemDB[9] = Item(9, "Iron Dagger", "Sprites/Iron_dagger.png");
	itemDB[10] = Item(10, "Iron Sword", "Sprites/Iron_Sword.png");
	itemDB[11] = Item(11, "Iron Axe", "Sprites/Iron_Axe.png");
	itemDB[12] = Item(12, "Iron Helmet", "Sprites/Iron_helmet.png");
	itemDB[13] = Item(13, "Iron Chest", "Sprites/Iron_Chest.png");
	itemDB[14] = Item(14, "Iron Plate Legs", "Sprites/Iron_LegPlates.png");
	itemDB[15] = Item(15, "Iron Boots", "Sprites/Iron_Boots.png");

	//////////////////
	//Obsidian Items
	//////////////////
	itemDB[16] = Item(16, "Coal Ore", "Sprites/Ore_Coal.png");
	itemDB[17] = Item(17, "Obsidian Ore", "Sprites/Ore_Obsidian.png");
	itemDB[18] = Item(18, "Obsidian Dagger", "Sprites/Obsidian_dagger.png");
	itemDB[19] = Item(19, "Obsidian Sword", "Sprites/Obsidian_Sword.png");
	itemDB[20] = Item(20, "Obsidian Axe", "Sprites/Obsidian_Axe.png");
	itemDB[21] = Item(21, "Obsidian Helmet", "Sprites/Obsidian_helmet.png");
	itemDB[22] = Item(22, "Obsidian Chest", "Sprites/Obsidian_Chest.png");
	itemDB[23] = Item(23, "Obsidian Plate Legs", "Sprites/Obsidian_LegPlates.png");
	itemDB[24] = Item(24, "Obsidian Boots", "Sprites/Obsidian_Boots.png");

	//////////////////
	//Gold Items
	//////////////////
	itemDB[25] = Item(25, "Gold Ore", "Sprites/Ore_Gold.png");
	itemDB[26] = Item(26, "Gold Helmet", "Sprites/Gold_helmet.png");
	itemDB[27] = Item(27, "Gold Chest", "Sprites/Gold_Chest.png");
	itemDB[28] = Item(28, "Gold Plate Legs", "Sprites/Gold_LegPlates.png");
	itemDB[29] = Item(29, "Gold Boots", "Sprites/Gold_Boots.png");

	//////////////////
	//Leather Items
	//////////////////
	itemDB[30] = Item(30, "Bear Leather Boots", "Sprites/Bear_LeatherBoots.png");
	itemDB[31] = Item(31, "Bear Leather Chest", "Sprites/Bear_LeatherChest.png");
	itemDB[32] = Item(32, "Bear Leather Leggings", "Sprites/Bear_LeatherLeggings.png");
	itemDB[33] = Item(33, "Boar Leather Boots", "Sprites/Boar_LeatherBoots.png");
	itemDB[34] = Item(34, "Boar Leather Chest", "Sprites/Boar_LeatherChest.png");
	itemDB[35] = Item(35, "Boar Leather Leggings", "Sprites/Boar_LeatherLeggings.png");
	itemDB[36] = Item(36, "Leopard Leather Boots", "Sprites/Bear_LeatherBoots.png");
	itemDB[37] = Item(37, "Leopard Leather Chest", "Sprites/Bear_LeatherChest.png");
	itemDB[38] = Item(38, "Leopard Leather Leggings", "Sprites/Bear_LeatherLeggings.png");

	//////////////////
	//Cloth Items
	//////////////////
	itemDB[39] = Item(39, "Cloth Excellent", "Sprites/Cloth_Excellent.png");
	itemDB[40] = Item(40, "Cloth Fine", "Sprites/Cloth_Fine.png");
	itemDB[41] = Item(41, "Cloth Simple", "Sprites/Cloth_Simple.png");
	itemDB[42] = Item(42, "Cloth Torn", "Sprites/Cloth_Torn.png");

	//////////////////
	//Food Items
	//////////////////
	itemDB[43] = Item(43, "Bread", "Sprites/Bread.png");
	itemDB[44] = Item(44, "Cooked Bear Meat", "Sprites/Cooked_BearMeat.png");
	itemDB[45] = Item(45, "Cooked Boar Meat", "Sprites/Cooked_BoarMeat.png");
	itemDB[46] = Item(46, "Cooked Egg", "Sprites/Cooked_Egg.png");
	itemDB[47] = Item(47, "Cooked Leopard Meat", "Sprites/Cooked_LeopardMeat.png");
	itemDB[48] = Item(48, "Pasta", "Sprites/Pasta.png");
	itemDB[49] = Item(49, "Scrambled Egg", "Sprites/ScrambledEgg.png");
	itemDB[50] = Item(50, "Unknown Soup", "Sprites/UnknownSoup.png");

	//////////////////
	//Jewelry Items
	//////////////////
	itemDB[51] = Item(51, "Silver Ore", "Sprites/Ore_Silver.png");
	itemDB[52] = Item(52, "Diamond Earrings", "Sprites/Diamond_Earrings.png");
	itemDB[53] = Item(53, "Diamond Necklace", "Sprites/Diamond_Necklace.png");
	itemDB[54] = Item(54, "Diamond Ring", "Sprites/Diamond_Ring.png");
	itemDB[55] = Item(55, "Emerald Earrings", "Sprites/Emerald_Earrings.png");
	itemDB[56] = Item(56, "Emerald Ring", "Sprites/Emerald_Ring.png");
	itemDB[57] = Item(57, "Garnet Earrings", "Sprites/Garnet_Earrings.png");
	itemDB[58] = Item(58, "Garnet Necklace", "Sprites/Garnet_Necklace.png");
	itemDB[59] = Item(59, "Garnet Ring", "Sprites/Garnet_Ring.png");
	itemDB[60] = Item(60, "Pearl Earrings", "Sprites/Pearl_Earrings.png");
	itemDB[61] = Item(61, "Pearl Necklace", "Sprites/Pearl_Necklace.png");
	itemDB[62] = Item(62, "Pearl Ring", "Sprites/Pearl_Ring.png");
	itemDB[63] = Item(63, "Ruby Earrings", "Sprites/Ruby_Earrings.png");
	itemDB[64] = Item(64, "Ruby Necklace", "Sprites/Ruby_Necklace.png");
	itemDB[65] = Item(65, "Ruby Ring", "Sprites/Ruby_Ring.png");
	itemDB[66] = Item(66, "Sapphire Earrings", "Sprites/Sapphire_Earrings.png");
	itemDB[67] = Item(67, "Sapphire Necklace", "Sprites/Sapphire_Necklace.png");
	itemDB[68] = Item(68, "Sapphire Ring", "Sprites/Sapphire_Ring.png");
	itemDB[69] = Item(69, "Pearl Emerald Earrings", "Sprites/Pearl_Emerald.png");
	itemDB[70] = Item(70, "Pearl Garnet Earrings", "Sprites/Pearl_Garnet.png");

	//////////////////
	//Ingrediant Items
	//////////////////
	itemDB[71] = Item(71, "Basil", "Sprites/Ingrediant_Basil.png");
	itemDB[72] = Item(72, "Bear Meat", "Sprites/Ingrediant_BearMeat.png");
	itemDB[73] = Item(73, "Boar Meat", "Sprites/Ingrediant_BoarMeat.png");
	itemDB[74] = Item(74, "Butter", "Sprites/Ingrediant_Butter.png");
	itemDB[75] = Item(75, "Egg", "Sprites/Ingrediant_Egg.png");
	itemDB[76] = Item(76, "Flour", "Sprites/Ingrediant_Flour.png");
	itemDB[77] = Item(77, "Leopard Meat", "Sprites/Ingrediant_LeopardMeat.png");
	itemDB[78] = Item(78, "Lettuce", "Sprites/Ingrediant_Lettuce.png");
	itemDB[79] = Item(79, "Milk", "Sprites/Ingrediant_Milk.png");
	itemDB[80] = Item(80, "Pepper", "Sprites/Ingrediant_Pepper.png");
	itemDB[81] = Item(81, "Salt", "Sprites/Ingrediant_Salt.png");
	itemDB[82] = Item(82, "Tomato", "Sprites/Ingrediant_Tomato.png");
	itemDB[83] = Item(83, "Water", "Sprites/Ingrediant_Water.png");

	//////////////////
	//Jewelry Material Items
	//////////////////
	itemDB[84] = Item(84, "Jewel Diamond", "Sprites/Jewel_Diamond.png");
	itemDB[85] = Item(85, "Jewel Emerald", "Sprites/Jewel_Emerald.png");
	itemDB[86] = Item(86, "Jewel Garnet", "Sprites/Jewel_Garnet.png");
	itemDB[87] = Item(87, "Jewel Pearl", "Sprites/Jewel_Pearl.png");
	itemDB[88] = Item(88, "Jewel Ruby", "Sprites/Jewel_Ruby.png");
	itemDB[89] = Item(89, "Jewel Sapphire", "Sprites/Jewel_Sapphire.png");

	//////////////////
	//Wood Items
	//////////////////
	itemDB[90] = Item(90, "Wood Ash", "Sprites/Wood_ash.png");
	itemDB[91] = Item(91, "Wood Cherry", "Sprites/Wood_cherry.png");
	itemDB[92] = Item(92, "Wood Mahogan", "Sprites/Wood_Mahogan.png");
	itemDB[93] = Item(93, "Wood Maple", "Sprites/Wood_maple.png");
	itemDB[94] = Item(94, "Wood Oak", "Sprites/Wood_Oak.png");
	itemDB[95] = Item(95, "Wood Walnut", "Sprites/Wood_Walnut.png");

	//////////////////
	//Alchemy Ingrediant Items
	//////////////////
	itemDB[96] = Item(96, "Sand Ore", "Sprites/Ore_Sand.png");
	itemDB[97] = Item(97, "Alchemy Salt Water", "Sprites/AlcIngrediant_SaltWater.png");

	//////////////////
	//Silver Items
	//////////////////
	itemDB[98] = Item(98, "Silver Helmet", "Sprites/Silver_helmet.png");
	itemDB[99] = Item(99, "Silver Chest", "Sprites/Silver_Chest.png");
	itemDB[100] = Item(100, "Silver Plate Legs", "Sprites/Silver_LegPlates.png");
	itemDB[101] = Item(101, "Silver Boots", "Sprites/Silver_Boots.png");

	//////////////////
	//Ship supplies
	//////////////////
	itemDB[102] = Item(102, "Ship Supplies", "Sprites/crate.png");
}

Item ItemDatabase::getItem(int itemID)
{
	Item result = itemDB[itemID];
	return result;

}