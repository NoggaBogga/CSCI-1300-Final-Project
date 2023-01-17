// Group People: Shehan Rajapakse Ashley Cody

#include <iostream>
#include "Merchant.h"

using namespace std;

void Merchant::displayMenu()
{
    cout << "< ---------- >"  << endl;
    cout << "|| INVENTORY ||" << endl;
    cout << "< ---------- >"  << endl;
    cout << "| Gold        |" << endl;
    cout << "| Ingredients |" << endl;
    cout << "| Cookware    |" << endl;
    cout << "| Weapons     |" << endl;
    cout << "| Armor       |" << endl;
    cout << "| Treasures   |" << endl;
    cout << endl;

    cout << "Choose one of the following:" << endl;
    cout << "1. Ingredients: You will need ingredients in order to cook food." << endl;
    cout << "2. Cookware: You will need cookware in order to cook." << endl;
    cout << "3. Weapons: You will need to defend yourself." << endl;
    cout << "4. Armor: If you want to survive attacks within the dungeon, take this." << endl;
    cout << "5. Sell Treasures: If it shines, I'll take it." << endl;
    cout << "6. Leave: After you've gotten everything you need, I'll be leaving!" << endl;
}

// define member functions
Merchant::Merchant()
{
    // set all values in each data member to be equal to their default values
    // --- int cookware_cost[3] = {5, 10, 20};
    // --- int weapon_cost[5] = {2, 2, 5, 15, 50};
    // --- int treasure_value[5] = {10,20,30,40,50};

    cookware_cost[0] = 5;
    cookware_cost[1] = 10;
    cookware_cost[2] = 20;

    weapon_cost[0] = 2;
    weapon_cost[1] = 2;
    weapon_cost[2] = 5;
    weapon_cost[3] = 15;
    weapon_cost[4] = 50;

    treasure_cost[0] = 10;
    treasure_cost[1] = 20;
    treasure_cost[2] = 30;
    treasure_cost[3] = 40;
    treasure_cost[4] = 50;
}
Merchant::Merchant(int cookware_costs[3], int weapon_costs[5], int treasure_costs[5])
{
    // set all values in each data member to be equal to parameter values
    for(int i = 0; i < 3; i++)
    {
        cookware_cost[i] = cookware_costs[i];
    }
    for(int i = 0; i < 5; i++)
    {
        weapon_cost[i] = weapon_costs[i];
    }
    for(int i = 0; i < 5; i++)
    {
        treasure_cost[i] = treasure_costs[i];
    }
}

// moved function definitions into public
int Merchant::getCookwareCost(int index,int numRooms)
{
  
    if (numRooms > 0)
    {
        return cookware_cost[index] + cookware_cost[index] * price_increase[numRooms - 1];
    }
    else 
    return cookware_cost[index];

};
int Merchant::getCookwareStrength(int index)
{
    return cookware_strength[index];
}

int Merchant::getWeaponCost(int weapon_index, int numRooms)
{
    if (numRooms > 0)
    {
        return weapon_cost[weapon_index] + weapon_cost[weapon_index] * price_increase[numRooms - 1];
    }
    else 
    return weapon_cost[weapon_index];
}
int Merchant::getWeaponStrength(int weaponIndex)
{
    return weapon_strength[weaponIndex];
}

int Merchant::getTreasureCost(int treasureIndex, int numRooms)
{
    return treasure_cost[treasureIndex];
}
int Merchant::getArmorCost(int numRooms)
{

    if(numRooms > 0)
    {
    return 5 * price_increase[numRooms];
    }
    else
    return 5;

}
int Merchant::getPriceIncrease(int numRooms)
{
    return price_increase[numRooms - 1];
}


Merchant Weapons();
void displayMenu();

Party getIngredients(int kg_food, Party the_party);
Party getCookware(int num_rooms_cleared, int cookware_type, Party the_party);
Party getWeapons(int weapontype, Party the_party);
Party getArmor(int number, Party the_party);
Party getTreasure(int number, Party the_party);
Party sellTreasure(string treasure, Party the_party); // player gets paid for treasure
void leave();






// takes in the number of kilograms of ingredients the party wants, if the party has enough gold, store kg_food value into the party's ingredients0
Party Merchant::getIngredients(int kg_food, Party the_party)
{
return the_party;
}