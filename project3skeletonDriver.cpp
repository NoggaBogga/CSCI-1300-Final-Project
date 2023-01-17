// Group People: Shehan Rajapakse Ashley Cody

#include <iostream>
#include <string>
#include "Party.h"
#include "Merchant.h"
#include "Map.h"
#include "Dungeon.h"
#include "Monster.h"

using namespace std;


int main()
{
    // generate map
    
    Dungeon dung;

     
    // Place party on map
    // map.setPlayerPosition(0,0);

    // Enter Party Initials

    string leader_name;
    string companion1;
    string companion2;
    string companion3;
    string companion4;

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

    dung.setPartyName(leader_name,companion1,companion2,companion3,companion4);

    dung.randomizeMap(); // generates map
   
    



    // Intialize Party Gold and Fullness
    dung.setPartyFullness(50,50,50,50,50);
    dung.setPartyGold(100);

    // Visit Merchant
    Merchant gamerch;
    
  // gamerch.displayMenu(); 
  bool end_variable = true;
  while(end_variable == true)
  {
   gamerch.displayMenu();
   
   end_variable = dung.merchantMenuAcitons(); // Processes Merchant Menu Actions
   dung.statusMenu();
  }
// while() where loop starts
   // display status menu
bool loop = true; // true when not testing


while ( loop == true)
{
    cout << "+----------------+" << endl;
    cout << "| STATUS         |" << endl;
    cout << "+----------------+" << endl;
    cout << "| Rooms Cleared: "  << dung.getMap().getRoomCount() << "| Keys: " << dung.getParty().getPartyKeys() << "| Anger Level: "<< dung.getSorcererAnger() << endl;
    cout << "+----------------+" << endl;
    cout << "| INVENTORY      |" << endl;
    cout << "+----------------+" << endl;
    cout << "| Gold           |" << dung.getParty().getPartyGold() << endl;
    cout << "| Ingredients    |" << dung.getParty().getPartyIngredients() << endl;
    cout << "| Cookware       |" << "P: " << dung.getParty().getPartyCookware(0) << "| F: " << dung.getParty().getPartyCookware(1) << "| C: " << dung.getParty().getPartyCookware(2) << endl;
    cout << "| Weapons        |" << "C: " << dung.getParty().getPartyWeaponType(0) << "| S: " << dung.getParty().getPartyWeaponType(1) << "| R: " << dung.getParty().getPartyWeaponType(2) << "| B: " << dung.getParty().getPartyWeaponType(3) <<  "| L: " << dung.getParty().getPartyWeaponType(4) << endl;
    cout << "| Armor          |" << dung.getParty().getPartyArmor() << endl;
    cout << "| Treasures      |" << "R: " << dung.getParty().getPartyTreasure(0) << "| N: " << dung.getParty().getPartyTreasure(1) << "| B: " << dung.getParty().getPartyTreasure(2) << "| C: " << dung.getParty().getPartyTreasure(3) << "| G: " << dung.getParty().getPartyTreasure(4) << endl;    
    cout << "+----------------+" << endl;
    cout << "| PARTY          |" << endl;
    cout << "+----------------+" << endl;
    cout << "| " << dung.getParty().getPartyName(0) <<" | Fullness: " << dung.getParty().getPartyFullness(0) << endl;
    cout << "| " << dung.getParty().getPartyName(1) <<" | Fullness: " << dung.getParty().getPartyFullness(1) << endl;
    cout << "| " << dung.getParty().getPartyName(2) <<" | Fullness: " << dung.getParty().getPartyFullness(2) << endl;
    cout << "| " << dung.getParty().getPartyName(3) <<" | Fullness: " << dung.getParty().getPartyFullness(3) << endl;
    cout << "| " << dung.getParty().getPartyName(4) <<" | Fullness: " << dung.getParty().getPartyFullness(4) << endl;
    cout << "+----------------+" << endl;

    // display map
    dung.getMap().displayMap(); 

    // display action menu
   loop = dung.acitonMenu();

   if(dung.getBattle() == true)
   {
      loop = false;
   }
   // dung.setBattle(true); // only used for testing
}

if(dung.getBattle() == true)
{
cout << "You find the sorcerer guarding the exit to the dungeon! There is only one way out now..." << endl;
cout << "If you make the right choices, you can get away with a bonus toward the leaderboards. Make the wrong ones, and you might not get out alive." << endl << endl;

cout << "The sorcerer fires a beam your way! Which way will you dodge?" << endl;
cout << "1) left" << endl << "2) right" << endl;
string userinput = "";
while(userinput != "1" && userinput != "2")
{
   cin >> userinput;
   if(userinput != "1" && userinput != "2")
   {
      cout << "Invalid input. Please select one of the options." << endl;
   }
}
if(userinput == "1")
{
   userinput = "";
   cout << "The beam hits you directly, and you are knocked back! At least it wasn't as bad as it could have been." << endl;
   cout << "You get up and brace for the sorcerer's incoming fire attack! What are you going to do?" << endl;
   cout << "1) Use a piece of armor to block the attack!" << endl << "2) Hide behind a rock" << endl;
   while(userinput != "1" && userinput != "2")
   {
      cin >> userinput;
      if(userinput != "1" && userinput != "2")
      {
         cout << "Invalid input. Please select one of the options." << endl;
      }
   }
   if(userinput == "2" || (userinput == "1" && dung.getParty().getPartyArmor() <= 2))
   {
      userinput = "";
      cout << "It's not enough! You survive the blast, but just barely. You only have one more chance..." << endl;
      cout << "An electric blast is coming your way! You have to use one of your weapons to block it... Which one will you use?" << endl;
      cout << "1) Rapier" << endl << "2) Club" << endl << "3) Battle axe" << endl;
      while(userinput != "1" && userinput != "2" && userinput != "3")
      {
         cin >> userinput;
         if(userinput != "1" && userinput != "2" && userinput != "3")
         {
            cout << "Invalid input. Please select one of the options." << endl;
         }
      }
      if(userinput == "1" || userinput == "3" || (userinput == "2" && dung.getParty().getPartyWeaponType(0) == 0))
      {
         cout << "It's no good! The electricity flows right through you, and you are not able to survive the hit. You were so close, but here is where your journey must end..." << endl;
         cout << "You lose." << endl;
         // lose
         dung.setResult(0);
      }
      else
      {
         cout << "It worked! You had a wooden club that could block the electricity just fine, and then threw it right at the sorcerer! It was messy, but you escaped! +0 turns" << endl;
         // win
         dung.setResult(1);
      }

   }
   else
   {
      cout << "It worked! The attack was blocked successfully! The fireball bounces off the armor and hits the sorcerer right back, giving you a chance to retaliate and escape! +2 turns" << endl;
      dung.setMoves(dung.getMoves() + 2);
      // win
      dung.setResult(1);
   }
   
}
else
{
   cout << "You slip past the beam and run after the sorcerer, getting a lucky attack in and defeating the sorcerer! You get away victorious! +5 turns" << endl;
   dung.setMoves(dung.getMoves() + 5);
   // win
   dung.setResult(1);
}
}


// cout << "waga bobo (credit to andy foster (he/they (pisces sun taurus moon aquarius rising (instagram: discosinferno))))" << endl;
// sorry about that

// display all time stats for the game
dung.displayDungeonStats();

}