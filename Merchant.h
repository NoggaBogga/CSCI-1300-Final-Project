// Group People: Shehan Rajapakse Ashley Cody

#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include "Party.h"

using namespace std;



class Merchant
{
    private:
    const static int ingredients = 1;    

    // cookware details
    // Base cost for a pot, defined in constructor
    // --- int cookware_cost[3] = {5, 10, 20};
    int cookware_cost[3] = {5, 10, 20};
    // cookware price increase
    double price_increase[5] = {0.25,0.5,0.75,1,1.25};
    // strength for Pot, Frying Pan, Cauldron
    // determines which probability for possible breakage
    // 25%, 10% or 2%
    // changed to const static int
    int cookware_strength[3] = {25, 10, 2};

    // weapons details, defined in constructor
    // --- int weapon_cost[5] = {2, 2, 5, 15, 50}; // cost for club, spear, Rapier, Battle-Axe, Longsword
    int weapon_cost[5] = {2, 2, 5, 15, 50};
    // changed to const static int
    int weapon_strength[5] = {0, 0, 1, 2, 3}; // strength for club, spear, Rapier, Battle-Axe, Longsword

    // treasure details, defined in constructor
    // --- int treasure_value[5] = {10,20,30,40,50};
    int treasure_cost[5] = {10,20,30,40,50};
    
    public:

    Merchant();
    Merchant(int cookware_cost[3], int weapon_cost[5], int treasure_value[5]);

    // moved function definitions into public
    int getCookwareCost(int c_index, int numRooms);
    int getCookwareStrength(int c_index);

    int getWeaponCost(int weaponIndex, int numRooms);
    int getWeaponStrength(int weaponIndex);

    int getTreasureCost(int treasureIndex, int numRooms);

    int getArmorCost(int numRooms);
    
    int getPriceIncrease(int numRooms);


    Merchant Weapons();
    void displayMenu();

    Party getIngredients(int kg_food, Party the_party);
    Party getCookware(int num_rooms_cleared, int cookware_type, Party the_party);
    Party getWeapons(int weapontype, Party the_party);
    Party getArmor(int number, Party the_party);
    Party getTreasure(int number, Party the_party);
    Party sellTreasure(string treasure, Party the_party); // player gets paid for treasure
    void leave();
};
#endif