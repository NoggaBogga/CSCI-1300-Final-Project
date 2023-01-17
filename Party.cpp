// Group People: Shehan Rajapakse Ashley Cody

#include <iostream>
#include "Party.h"
#include <iostream>
#include <string>
#include "Map.h"

using namespace std;

    Party::Party()
    {
    };

    void Party::setMember(int position, string name)
    {
	    return;
    };
    // sets party armor, treasure, fullness,stores names, sets gold pieces, number of keys, ingredients
    void Party::setPartyArmor(int party_armor_)
    {
        party_armor = party_armor_;
    };
    void Party::setPartyWeapons(int weapon_index,int party_index)
    {
        party_weapons[party_index] = weapon_index; // stores weapon index from the selection of weapons in the merchant menu
        weapon_type[weapon_index] = weapon_type[weapon_index] + 1;
    };
    void Party::decPartyWeapons(int weapon_index)
    {
        party_weapons[weapon_index] = party_weapons[weapon_index] - 1;
        
    };
    void Party::setPartyTreasure(int index)
    {
        if (index > 0 && index <= 5)
        {
        treasure_array[index - 1] = treasure_array[index - 1] + 1;
        }
        return;
    };

    void Party::setPartyFullness(int leader_fullness,int companion1, int companion2,int companion3,int companion4)
    {
        fullness[0] = leader_fullness;
        fullness[1] = companion1; 
        fullness[2] = companion2;
        fullness[3] = companion3;
        fullness[4] = companion4; 
	    return;
    };
    void Party::incPartyFullness() // index
    {
        if (fullness[0] < 50)
        {
            fullness[0] = fullness[0] + 1;
        }
        if (fullness[1] < 50)
        {
            fullness[1] = fullness[1] + 1;
        }
        if (fullness[2] < 50)
        {
            fullness[2] = fullness[2] + 1;
        }
        if (fullness[3] < 50)
        {
            fullness[3] = fullness[3] + 1;
        }
        if (fullness[4] < 50)
        {
            fullness[4] = fullness[4] + 1;
        }
    };
    void Party::decPartyFullness() // index
    {
           if (fullness[0] > 0)
        {
            fullness[0] = fullness[0] - 1;
        }
        if (fullness[1] > 0)
        {
            fullness[1] = fullness[1] - 1;
        }
        if (fullness[2] > 0)
        {
            fullness[2] = fullness[2] - 1;
        }
        if (fullness[3] > 0)
        {
            fullness[3] = fullness[3] - 1;
        }
        if (fullness[4] > 0)
        {
            fullness[4] = fullness[4] - 1;
        }
        
        
    };
    void Party::decIndvidFullness(int index)
    {
        fullness[index] = fullness[index] - 1;
    }
    void Party::invIndvidFullness(int index)
    {
        fullness[index] = fullness[index] + 1;
    }
    void Party::killMember(int index)
    {
        fullness[index] = 0;
    }

    void Party::setPartyName(string leader, string companion1, string companion2, string companion3, string companion4)
    {
        member[0] = leader;
        member[1] = companion1; 
        member[2] = companion2;
        member[3] = companion3;
        member[4] = companion4; 
         
	    return;
    };

    void Party::setPartyGold(int gold_pieces_)
    {
        gold_pieces = gold_pieces_;
	return;
    };

    void Party::setPartyKeys(int keys)
    {
        keys_ = keys;
    };

    void Party::incKeys()
    {
        keys_ += 1;
    };
    void Party::decKeys()
    {
        keys_ -= 1;
    };


    void Party::setPartyIngredients(int ingredients)
    {
        kg_of_ingredients = ingredients;
	return;
    };

    bool Party::enoughMoney(int cost_of_item)
    {
        if(cost_of_item < gold_pieces)
        {
            return true;
        }
        else
        {
        return false;
        }
    }
    string Party::getPartyName(int index)
    {
        return member[index];      
    }

    void Party::setPartyCookware(int index)
    {
        party_cookware[index] = party_cookware[index] + 1;
    };
    void Party::decPartyCookware(int index)
    {
        party_cookware[index] = party_cookware[index] - 1;
    };
    int Party::getPartyArmor()
    {
	    return party_armor;
    };

    int Party::getPartyWeapons(int index)
    {
	    return party_weapons[index];
    };

    int Party::getPartyWeaponType(int weaponindex)
    {
        return weapon_type[weaponindex];
    }
    int Party::getPartyCookware(int index)
    {
            return party_cookware[index];
    };

    int Party::getPartyTreasure(int index)
    {
            return treasure_array[index];
    };

    void Party::decPartySize()
    {
        number_of_members = number_of_members - 1;
    }
    int Party::getPartySize()
    {
        return number_of_members;
    }
    int Party::getPartyFullness(int index)
    {
        return fullness[index];
    };
    int Party::getPartyGold()
    {
        return gold_pieces;
    };

    int Party::getPartyKeys()
    {
        return keys_;
    };

    int Party::getPartyIngredients()
    {
        return kg_of_ingredients;
    };
    
    bool Party::cookMeal()
    {
	    return true;
    };