#include <iostream>
#include <string>
#include "Treasure.h"
#include "Party.h"
#include "Merchant.h"
#include "Cookware.h"
#include "Map.h"
#include 
using namespace std;


int main()
{
    // generate map
    Map map;
    cout << "Initial map: " << endl;
    map.displayMap(); // starting point
    cout << "Default constructor: " << endl;
    cout << "Room #: " << map.getRoomCount() << endl;
    cout << "Let's add some rooms: " << endl;
    assert(map.addRoom(2, 3));
    assert(map.addRoom(8, 11));
    assert(map.addRoom(2, 7));
    assert(map.addRoom(8, 2));
    assert(!map.addRoom(15, 15)); // should not show on map nor error out, out of bounds
    assert(!map.addRoom(2, 3));   // will not do anything since space is occupied
    assert(map.addRoom(5, 7));
    assert(!map.addRoom(3, 7)); // will fail due to exceeding max_rooms_
    map.displayMap();
    // Enter Party Initials
    string leader_name;
    string companion1;
    string companion2;
    string companion3;
    string companion4;

    Party party;

    cout << "Enter leader name" << endl;
    cin >> leader_name; 

    cout << "Enter companion name" << endl;
    cin >> companion1;

    cout << "Enter companion name" << endl; 
    cin >> companion2;

    cout << "Enter companion name" << endl;
    cin >> companion3;

    cout << "Enter companion name" << endl; 
    cin >> companion4;

    party.setPartyName(leader_name,companion1,companion2,companion3,companion4);
    party.setPartyFullness()

    // Intiate Sorcerer

    // Visit Merchant
    Merchant gamerch;
    gamerch.displayMenu();
    
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        gamerch.getIngredients();
        
    }
    // Place party on map
    
    // display menu
    cout << "+----------------+" << endl;
    cout << "| STATUS         |" << endl;
    cout << "+----------------+" << endl;
    cout << "| Rooms Cleared: " << 5 - map.getRoomCount() << "| Keys: " << party.getPartyKeys() << "| Anger Level: "<< dung.getSorcererAnger() << endl;
    cout << "+----------------+" << endl;
    cout << "| INVENTORY      |" << endl;
    cout << "+----------------+" << endl;
    cout << "| Gold           |" << party.getPartyGold << endl;
    cout << "| Ingredients    |" << party.getPartyIngredients() << endl;
    cout << "| Cookware       |" << "P: " << party.getPartyCookware(0) << "| F: " << party.getPartyCookware(1) << "| C: " << party.getPartyCookware(2) << endl;
    cout << "| Weapons        |" << "C: " << party.getPartyWeapons(0) << "| S: " << party.getPartyWeapons(1) << "| R: " party.getPartyWeapons(2) << "| B: " << party.getPartyWeapons(3) <<  "| L: " << party.getPartyWeapons(4) << endl;
    cout << "| Armor          |" << party.getPartyArmor() << endl;
    cout << "| Treasures      |" << "R: " << party.getPartyTreasure(0) << "| N: " << party.getPartyTreasure(1) << "| B: " << party.getPartyTreasure(2) << "| C: " << party.getPartyTreasure(3) << "| G: " << party.getPartyTreasure(4) << endl;
}