// Group People: Shehan Rajapakse Ashley Cody

#ifndef PARTY_H
#define PARTY_H

#include <iostream>
#include "Map.h"

using namespace std;



class Party
{
    private:
    int fullness[5] = {50,50,50,50,50};

    // member of the party
    // leader and 4 companions
    string member[5]; //member 0 is player, members 1-4 are companions
    int number_of_members = 5;
    // inventory for the party
    int gold_pieces = 100;
    int kg_of_ingredients = 0;
    // number of cookware type ceramic, frying pan and cauldron
    int party_cookware[3] = {0, 0, 0};
    // array of weapons for the party- one weapon per play and member
    int party_weapons[5] = {0,0,0,0,0};
    // array of number of each type of weapon
    int weapon_type[5] = {0,0,0,0,0};

    int party_armor = 0;
    // this array gets filled as they find treasure depending on number of rooms cleared
    int treasure_array[5] = {0, 0, 0, 0, 0};
    // keys
    int keys_ = 0;

    public:
    Party();

    void setMember(int position, string name);

    void setPartyArmor(int party_armor_);
    void setPartyWeapons(int weapon_index,int player_index);
    void decPartyWeapons(int weapon_index);
    void setPartyTreasure(int index);
    void setPartyFullness(int leader_fullness,int companion1, int companion2,int companion3,int companion4);
    void setPartyCookware(int index);

    void incPartyFullness();
    void decPartyFullness();
    void invIndvidFullness(int index);
    void decIndvidFullness(int index);
    void killMember(int index);

    void setPartyName(string leader, string companion1, string companion2, string companion3, string companion4);
    void setPartyGold(int gold_pieces_);
    void setPartyKeys(int keys);

    void incKeys();
    void decKeys();


    void setPartyIngredients(int ingredients);
    void setMap(Map map_);

    bool enoughMoney(int cost_of_item);
    string getPartyName(int index);
    int getPartyArmor();
    int getPartyWeapons(int index);
    int getPartyWeaponType(int weapon_index);
    int getPartyCookware(int index);
  
    void decPartyCookware(int index);
    int getPartyTreasure(int index);
    void decPartySize();
    int getPartySize();
    int getPartyFullness(int memberIndex);
    int getPartyGold();
    int getPartyKeys();
    int getPartyIngredients();
    Map getMap();

    bool cookMeal();

};
#endif