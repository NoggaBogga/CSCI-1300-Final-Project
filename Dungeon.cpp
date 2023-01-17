// Group People: Shehan Rajapakse Ashley Cody

#include <iostream>
#include <fstream>
#include <vector>
#include "Map.h"
#include "Dungeon.h"	
#include "Party.h"
#include "Genprob.h"
#include "NPCPuzzle.h"
#include "Doorpuzzle.h"
#include <cmath>
#include "Monster.h"
#include <vector>

using namespace std;

	Dungeon::Dungeon()
    {
       // initialize monsters_list
        ifstream fin;
        fin.open("monsters.txt");
        if(fin.fail())
        {
            cout << "Dungeon class error- monster initialization failed (file could not be read)" << endl;
            abort();
        }
        string line = "";
        int i = 1;
        while (!fin.eof())
        {
            getline(fin, line);
            monsters_list.push_back(Monster(i, ("monsters.txt")));
            i++;
        }

        // test output to check monsters_list initialized correctly
        // for(int k = 0; k < monsters_list.size(); k++)
        // {
        //     cout << "Current line: " << k << endl;
        //     cout << "Monster name: " << monsters_list.at(k).getName() << endl;
        //     cout << "Monster power: " << monsters_list.at(k).getPower() << endl;
        // }

       sorcerer_power_ = 0;
       puz.loadRiddles("riddles.txt");
    }

	// prepare game map
	Map Dungeon::randomizeMap()
        {
            int npc_num = 0;
            int room_num = 0;
            int row_value = 0;
            int col_value = 0;

            // randomize NPC's into the map
            while (npc_num < 5)
            {
            row_value = 0; col_value = 0;
            row_value = rand() % 12; // row value from 0 - 11
            col_value = rand() % 12; // column value from 0 - 11
            // check if this row value and column value does not contains rooms and NPCs
            // then add NPC. all checks are done in the addNPC function in map class
            if (!gameMap.addNPC(row_value, col_value))
                {
            npc_num++;
            }
            }

            // randomize Rooms's into the map
            while (room_num < 5)
            {
            row_value = 0; col_value = 0;
            row_value = rand() % 12; // row value from 0 - 11
            col_value = rand() % 12; // column value from 0 - 11
            // check if this row value and column value does not contains rooms and NPCs
            // then add NPC. all checks are done in the addRoom function in map class
            if (!gameMap.addRoom(row_value, col_value))
                {
            room_num++;
            }
            }

            return gameMap;
        };

    Map Dungeon::getMap()
    {
        return gameMap;
    };
    Party Dungeon::getParty()
    {
        return gameParty;
    };

    // setters

    void Dungeon::setPartyName(string leader, string companion1, string companion2, string companion3, string companion4)
        {
            gameParty.setPartyName(leader, companion1, companion2, companion3, companion4);
            
            // we are going to run a rand function a number of times determined by the leader name, to make the map more unique on each playthrough
            for(int i = 0; i < int(gameParty.getPartyName(0)[0]); i++)
            {
                for(int k = 0; k < int(gameParty.getPartyName(3)[0]); k++){
                rand();
                }
            }
        };

    void Dungeon::setPartyFullness(int full1, int full2, int full3, int full4, int full5)
    {
	    gameParty.setPartyFullness(full1, full2, full3, full4, full5);

    }

    void Dungeon::setPartyGold(int amt_of_gold)
    {
	    gameParty.setPartyGold(amt_of_gold);
    }

    void Dungeon::setPartyIngredients(int amt_of_ingredients)
    {
        if (gameParty.enoughMoney(amt_of_ingredients) == true)
        {
	    gameParty.setPartyIngredients(amt_of_ingredients);
        }
    }

    void Dungeon::setPartyCookware(int cookware)
    {
	    gameParty.setPartyCookware(cookware);

    }

// Actions
	Party Dungeon::move(char the_move)
        {
        if (gameMap.move(the_move) == false)
        {
            cout << "Out of bounds" << endl;
            // tell user move failed
        }
         else if (gameMap.isDungeonExit(gameMap.getPlayerRow(),gameMap.getPlayerCol()))
        {
            if(gameMap.getRoomCount() > 0)
            {
                cout << "You have not yet cleared all of the rooms." << endl;
                // abort(); // test
                gameMap.setPlayerPosition(gameMap.getDungeonExitRow() - 1, gameMap.getDungeonExitCol());
            }
            else
            {
                sorcerer_battle = true;
            }
        total_game_moves++;
        }
        else
        { 
	    // count player moves for game stats
	    total_game_moves++;

            if (prob.twentyPercent() == true) // call probability function 20%
            {
                gameParty.decPartyFullness();
            }

            if(!gameMap.isExplored(gameMap.getPlayerRow(),gameMap.getPlayerCol()))
            {
                sorcerer_power_ += 1;
            }
        
        }
            
        
        return gameParty;
        };

// add misfortune probability
	Party Dungeon::investigate()
        {
     
      //  gameParty.investigate();
        if (gameMap.isExplored(gameMap.getPlayerRow(),gameMap.getPlayerCol()) == true)
        {   
            cout << "Space is already explored, choose another action!" << endl;
            //is explored
        }
        else if (gameMap.isNPCLocation(gameMap.getPlayerRow(),gameMap.getPlayerCol()) == true)
        {
            cout << "NPClocation" << endl;
            
        }
        else if (gameMap.isRoomLocation(gameMap.getPlayerRow(),gameMap.getPlayerCol()) == true)
        {
            cout << "Roomlocation" << endl;
        }
        
        else if (gameMap.isFreeSpace(gameMap.getPlayerRow(),gameMap.getPlayerCol()) == true)
        {
            cout << "Free Space" << endl;
            //probability 10% key
            if(prob.tenPercent() == 1)
            {
                // player gains a key
                gameParty.incKeys();
            }
            // probability 20% finds treasure
            if(prob.twentyPercent() == 1)
            {
                //player gets treasure based on number of rooms found
                if (5 - gameMap.getRoomCount() == 1)
                {
                    gameParty.setPartyTreasure(1);
                }
                else if (5 - gameMap.getRoomCount() == 2)
                {
                    gameParty.setPartyTreasure(2);
                }
                else if (5 - gameMap.getRoomCount() == 3)
                {
                    gameParty.setPartyTreasure(3);
                }
                else if (5 - gameMap.getRoomCount() == 4)
                {
                    gameParty.setPartyTreasure(4);
                }
                else if (5 - gameMap.getRoomCount() == 5)
                {
                    gameParty.setPartyTreasure(5);
                }
                
            }
            // 20% fights a monster
            if (prob.twentyPercent() == 1)
            {

                //if(//player beats monster)
                    if(prob.tenPercent() == 1)
                    {
                        gameParty.incKeys();
                    }
            }
            // 50% chance players fullness drops by one point
          for (int i = 0; i < 5; i++)
          {
            if (prob.fiftyPercent() == 1)
            {
                gameParty.decIndvidFullness(i); // decrease player or party fullness
            }
          }
          gameMap.exploreSpace(gameMap.getPlayerRow(),gameMap.getPlayerCol());
        }

		return gameParty;
        }

	bool Dungeon::pick_a_fight()
        {
        // gameParty.pick_a_fight();
        // randomly pick a monster based on number of rooms unlocked


        // an algorithm should be generated to pick a monster from a decreasing list, but for now it will use a monster pulled from a random slot
        // between a range based on the given level
        // gameMap.getRoomCount(); should tell which room we are in??????? i have no idea

        // take a monster from the first 5 slots (or less if there are fewer than 5) (at random) and check that none of them are the sorcerer
        // take that monster and store the index it is at
        // perform necessary calculations
        // delete the monster at that index (monsters_list.erase(monsters_list.begin() + index))
        bool win = false;
         int monster_index = 0;
        // cout << "test1" << endl;
        if(monsters_list.size() == 1) //  for now, if there is only the sorcerer left, print a message saying there is only the sorcerer left to fight in the last room
        {
            cout << "The only enemy left is the Sorcerer" << endl;
            return win;
        }

        do
        {
            // cout << "checking for sorcerer name..." << endl;
            // cout << monsters_list.at(monster_index).getName() << endl;
            if(monsters_list.size() < 6)
            {
                monster_index = rand() % monsters_list.size();
            }
            else
            {
                monster_index = rand() % 5;
            }
        } while(monsters_list.at(monster_index).getName() == "Sorcerer");
        string monster_name = monsters_list.at(monster_index).getName();
        cout << monster_name << " appears!" << endl;

        
        string userinput = "";
        while(userinput != "1" && userinput != "2")
        {
            cout << "What do you choose to do?" << endl << "1) Attack" << endl << "2) Surrender" << endl;
            cin >> userinput;
        }
        if(userinput == "1")
        {
            int monster_power = monsters_list.at(monster_index).getPower();
            // declare 2 rand numbers for combat calculation
            float rand1 = rand() % 6;
            float rand2 = rand() % 6;

            // define "d", 4 if each party member has a different type of weapon, 0 otherwise
            // this method probably does not work right! oops, might have to come back to it
            int d = 0;
            for(int i = 0; i < 5; i++)
            {
                int sum = 0;
                sum += gameParty.getPartyWeapons(i);
                if(sum >= gameParty.getPartySize())
                {
                    d = 4;
                }
            }

            // define "w", which counts the total power of all weapons owned
            int w = 0;
            w += gameParty.getPartyWeapons(0) + gameParty.getPartyWeapons(1) + gameParty.getPartyWeapons(2) + gameParty.getPartyWeapons(3) + gameParty.getPartyWeapons(4);
            if(gameParty.getPartyWeapons(2) > 0) w++;
            if(gameParty.getPartyWeapons(3) > 0) w += 2;
            if(gameParty.getPartyWeapons(4) > 0) w += 3;

            // cout << "Rand1: " << rand1 << endl << "Rand2" << rand2 << endl;
            float result = 0;
            if(gameParty.getPartyArmor() == 0)
            {
                result = ((rand1 * w) + d) - ((rand2 * monster_power));
            }
            else
            {
                result = ((rand1 * w) + d) - ((rand2 * monster_power) / gameParty.getPartyArmor());
            }
            // cout << "W: " << w << endl << "D: " << d << endl << "Result: " << result << endl;

            if(result <= 0) // if party loses the battle
            {
                cout << "You lost!" << endl;
                cout << "You lose " << float(gameParty.getPartyGold()) * 0.25 << " gold pieces..." << endl;
                // lose 25% of gold
                gameParty.setPartyGold(int(floor(float(gameParty.getPartyGold()) * 0.75)));

                cout << "You lose some ingredients..." << endl;
                // lose 30kg of ingredients, or all if player has less than that
                gameParty.setPartyIngredients(gameParty.getPartyIngredients() - 30);
                if(gameParty.getPartyIngredients() < 0) gameParty.setPartyIngredients(0);

                for(int i = 1; i < gameParty.getPartySize(); i++) // starts at 1 in order to exclude player character
                {
                    if(gameParty.getPartyArmor() > 0)
                    {
                        if(rand() % 20 == 2)
                        {
                            cout << "The " << monster_name << " has slain " << gameParty.getPartyName(i) << "!" << endl;
                            gameParty.killMember(i);
                        }
                        // i have to assume that when armor is used to calculate survivability, we decrease armor count? that's what i am doing here
                        gameParty.setPartyArmor(gameParty.getPartyArmor() - 1);
                    }
                    else
                    {
                        if(rand() % 10 == 2)
                        {
                            cout << "The " << monster_name << " has slain " << gameParty.getPartyName(i) << "!" << endl;
                            gameParty.killMember(i);
                        }
                    }
                }
            }
            else // if party wins the battle
            {
            win = true;
                gameParty.setPartyGold(gameParty.getPartyGold() + (10 * monster_power));
                cout << "You won and got " << (10 * monster_power) << " gold pieces!" << endl;
                gameParty.setPartyIngredients(gameParty.getPartyIngredients() + (5 * monster_power));
                cout << "You got " << 5 * monster_power << " ingredients!" << endl;
                // 10% monster drops a key
                if (rand() % 10 == 2)
                {
                    gameParty.incKeys();
                    cout << "The monster dropped a key! You now have " << gameParty.getPartyKeys() << " keys." << endl;
                }
                
                // erase monster just encountered
                monsters_list.erase(monsters_list.begin() + monster_index);
            }

            
            
            
        }
        else // if player chooses to surrender
        {
            int taken_index = (rand() % (5 - 1)) + 1; // takes rand number between 1 and 4 inclusive
            cout << gameParty.getPartyName(taken_index) << " has been taken by the monster! You must go on without them!" << endl;
            gameParty.killMember(taken_index);
        }

        // 50% party's fullness drops by one point
        if (rand() % 2 == 1)
        {
            gameParty.decPartyFullness();
        }
		return win;
        };
     Party Dungeon::cook_and_eat()
        {
       // gameParty.cook_and_eat();
        int cookware = 0;

        int ingredients = 0;
        cout << "How much ingredients do you want to cook? (increments of 5)" << endl;
        cin >> ingredients;

        if ((gameParty.getPartyIngredients() - ingredients) < 0)
        {
            cout << "Liar" << endl;
        }
            else if (ingredients > 0 && ingredients % 5 == 0)
            {
            gameParty.setPartyIngredients(gameParty.getPartyIngredients() - ingredients);

            cout << "Choose your cookware: 1. Pot (P) 2. Pan (F) 3. Cauldron (C)." << endl;
            cin >> cookware;

                if (cookware == 1)
                {
                    // 25% chance of pot breaking
                     if (prob.twenty5Percent() == 1 && gameParty.getPartyCookware(cookware) > 0)
                    {
                        gameParty.decPartyCookware(cookware);
                        cout << "Your pot broke and you lost your dinner!" << endl;
                    }
                    else if(gameParty.getPartyCookware(cookware) == 0)
                    {
                        cout << "You do not have a pot :(" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < ingredients / 5; i++)
                        {
                            gameParty.incPartyFullness();
                            cout << "Your Party's fullness has increased by one!" << endl;
                        }
                    }
                }
                else if (cookware == 2)
                {
                    // 10% chance frying pan breaks
                     if (prob.tenPercent() == 1 && gameParty.getPartyCookware(cookware) > 0)
                    {
                        cout << "Your frying pan broke and you lost your dinner!" << endl;
                        gameParty.decPartyCookware(cookware);
                    }
                    else if(gameParty.getPartyCookware(cookware) == 0)
                    {
                        cout << "You do not have a frying pan :(" << endl;
                    }
                    else 
                    {
                        for (int i = 0; i < ingredients / 5; i++)
                        {
                            gameParty.incPartyFullness();
                            cout << "Your Party's fullness has increased by one!" << endl;
                        }
                    }
                }
                else if (cookware == 3)

                {
                    // 2% cauldron breaks
                    if (prob.twoPercent() == 1 && gameParty.getPartyCookware(cookware) > 0)
                    {
                        cout << "Your cauldron broke and you lost your dinner!" << endl;
                        gameParty.decPartyCookware(cookware);
                    }
                    else if(gameParty.getPartyCookware(cookware) == 0)
                    {
                        cout << "You do not have a cauldron :(" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < ingredients / 5; i++)
                        {
                            gameParty.incPartyFullness();
                            cout << "Your Party's fullness has increased by one!" << endl;
                        }
                    }
                }
            }

        return gameParty;
        }

	Party Dungeon::give_up()
        {
       // gameParty.give_up();
        cout << "You Lose." << endl;
		return gameParty;
        };

	Party Dungeon::speak_to_npc()
        {
        string riddle_answer;

        cout << puz.getRiddle() << endl;
        cout << endl;
        cout << "enter your answer " << endl;
        cin >> riddle_answer;

        if (puz.checkAnswer(riddle_answer) == true)
        {
            int end_variable = true;
            while(end_variable == true)
            {
                {
                merch.displayMenu();
                end_variable = merchantMenuAcitons(); // Processes Merchant Menu Actions
                statusMenu();
                }
            }
		
        }
        else 
        {

            Dungeon::pick_a_fight();
        }
        
        return gameParty;
        }
    bool Dungeon::getBattle()
    {
        return sorcerer_battle;
    }
	bool Dungeon::open_the_door()
    {
        // if(gameMap.getRoomCount() == 4)
        // {
        //     sorcerer_battle = true;
        // }
        // else
        // {
        int tries = 0;
        int result;
        int member;
        bool escape = false;
        bool fight = false;
        bool door = false;
        // gameParty.open_the_door()
            if(gameParty.getPartyKeys() > 0)
            {   
                escape = true;
            }
            else if (gameParty.getPartyKeys() == 0)
            {
                int tries = 0;

                // Party falls into trap
                cout << "Your party fell into a trap after trying to enter the room without a key" << endl;
                cout << "You have three tries to beat the puzzle" << endl;
                int trap;
                while(tries < 3)
                {
                trap = 0;
                cout << "Choose one: 1. Boulder, 2. Shears, or 3. Parchment" << endl;
                cin >> trap;

                    result = door_puz.playPuzzle(door_puz.getChoice(trap - 1));
                    if(result == 1)
                    {
                        cout << "You Escaped!" << endl;
                        escape = true;
                        break;
                    }
                    else
                    {
                    cout << "Try Again" << endl;
                    }
                tries++;
                }
            }
                if (escape == false)
                {
                    //random party member dies
                    member = rand()% 5;
                    gameParty.killMember(member);

                    if (member == 0)
                    {
                        cout << gameParty.getPartyName(member) << " has been trapped. The party cannot go on without it's leader" << endl;
                    }
                    else 
                    {
                    cout << gameParty.getPartyName(member) << " is trapped!" << endl;
                    }

                }
                else
                {
                
                fight = pick_a_fight();
                
                    if(fight == 1) // party defeats monster, 60% chance of misfortune, room turns into normal space after resolved
                    {
                    cout << "You defeated the monster and cleared the room!" << endl;
                    door = true;
                    gameMap.exploreSpace(gameMap.getDungeonExitRow(),gameMap.getPlayerCol());

                    cout << gameMap.getRoomCount() << "After" << endl;

                        if(prob.sixtyPercent() == 1)
                        {
                            Misfortune();
                        }
                        if(prob.tenPercent() == 1)
                        {
                        gameParty.incKeys();
                        }
                    }
                    else
                    {
                        if(prob.fortyPercent() == 1)
                        {
                            Misfortune();
                        }
                    /*
                    if party fails, consquences from fighting a monster occur, key is loss. player must use another key. 40% chance of misfortune
                    */
                    }
    
                }
        
    return door;
    }

    int Dungeon::getSorcererAnger()
    {
        return sorcerer_power_;
    };
	
    void Dungeon::Misfortune()
    {
    randommis = rand() % 4;
    if (randommis == 0) 
    {
        if (prob.thirtyPercent() == 1)
        {
            randommis = rand() % 3;
        cout << "You've been robbed of your" << endl;
            if (randommis == 0) // ingredients
            {
            cout << " ingredients!";
            if (gameParty.getPartyIngredients() > 10)
            {
            gameParty.setPartyIngredients(gameParty.getPartyIngredients() - 10);
            }
            else
            {
                cout << "You have zero ingredients!" << endl;
            gameParty.setPartyIngredients(0);
            }
            }
            else if (randommis == 1) // cookware
            {
            cout << " cookware!";
            randommis = rand() % 3;
            if (gameParty.getPartyCookware(randommis) > 0)
            {
            gameParty.decPartyCookware(randommis);
            }
            
            }
            else if ( randommis == 2) // armor
            {
            cout << " armor!";

            if (gameParty.getPartyArmor() > 0)
            {
            gameParty.setPartyArmor(gameParty.getPartyArmor() - 1);
            }
            }
        }
    }
    else if (randommis == 1)
    {
        if (prob.tenPercent() == 1)
        {
            randommis = rand() % 5;
            if (gameParty.getPartyWeapons(randommis) == 0)
            {
                cout << "Lucky! Your weapons were saved!" << endl;
            }
            else
            {
            cout << " AHHHH your " << gameParty.getPartyWeapons(randommis) << " broke!" << endl;
            }
        }
    }
    else if (randommis == 2)
    {
        if (prob.thirtyPercent() == 1)
        {
            randommis = rand() % 5;
            for (int i = 0; i < 10; i++)
            {
                gameParty.decIndvidFullness(randommis);
            }
            
                if (gameParty.getPartyFullness(randommis) < 0 && randommis == 0)
                {
                    cout << "You died of hunger!" << endl;
                }
                else if (gameParty.getPartyFullness(randommis) < 0)
                {
                    cout << gameParty.getPartyName(randommis) << " died of hunger. RIP" << endl;
                }
        }
    }
    else if (randommis == 3)
    {
        if (prob.thirtyPercent() == 1)
        {
            randommis = rand() % 4 + 1;
            gameParty.decPartySize();
            cout << "Sadly, your party member " << gameParty.getPartyName(randommis) << " has been trapped in the last room. We must move forward." << endl;
            gameParty.killMember(randommis);
            cout << "Your party has " << gameParty.getPartySize() << " members left." << endl;
        }
    }
    };

    bool Dungeon::merchantMenuAcitons()
    {

    int choice;
    cin >> choice;

int merchant = true;
bool cook = true;

    if (choice == 1)
    {
    // sub menu for ingredients
    // party = gamerch.getIngredients(1,party);
    
        cout << "How many ingredients do you wish to buy?" << endl;
        int ingredients = 0;
        cin >> ingredients;
        if (ingredients > 0 )
        {
        setPartyIngredients(ingredients);
        setPartyGold(gameParty.getPartyGold()- (ingredients + ingredients * merch.getPriceIncrease(5 - gameMap.getRoomCount())));
        return true;
        }
        
    }
    else if (choice == 2)
    {
    // sub menu for cookware
    // party = gamerch.getCookware(5 - map.getRoomCount(),party);

        while (cook == true )
        {
                int cookware = 0;
                cout << "Do you want a 1. Pot (" << merch.getCookwareCost(0, 5 - gameMap.getRoomCount()) << "g), 2. Pan (" << merch.getCookwareCost(1, 5 - gameMap.getRoomCount()) << "g), or 3. Cauldron (" << merch.getCookwareCost(2, 5 - gameMap.getRoomCount()) << "g)?" << endl;
                cin >> cookware;

            if (cookware > 0 && cookware <= 3)
            {
                if(gameParty.enoughMoney(merch.getCookwareCost(cookware - 1, 5 - gameMap.getRoomCount())) == true )
                {
                    setPartyCookware(cookware - 1);
                    setPartyGold(gameParty.getPartyGold() - merch.getCookwareCost(cookware - 1, 5 - gameMap.getRoomCount()));
                    cook = false;  
                    return true;
                }
                
            }
            else 
            {
                cout << "Enter a valid value" << endl;
                return true;
            }
        }
    }
    else if (choice == 3)
    {

    // sub menu for weapons
    // party = gamerch.getWeapons(int weapontype,party);
     int weapon = 0;
     int player = 0;
                cout << "Do you want a 1. Club (" << merch.getWeaponCost(0,5 -gameMap.getRoomCount()) << "g) 2. Spear (" << merch.getWeaponCost(1,5 - gameMap.getRoomCount()) << "g) , 3. +1 Rapier (" << merch.getWeaponCost(2,5 - gameMap.getRoomCount()) << "g) , 4. +2 Battle-Axe (" << merch.getWeaponCost(3,5 - gameMap.getRoomCount()) << "g) , or 5. +3 Longsword ("<< merch.getWeaponCost(4,5 - gameMap.getRoomCount()) << "g) ?" << endl;
                cin >> weapon;

            if (weapon > 0 && weapon <= 5)
            {
                if(gameParty.enoughMoney(merch.getWeaponCost(weapon - 1,5 - gameMap.getRoomCount())) == true )
                {
                    

                    cout << "Who do you want to buy it for, 1. " << gameParty.getPartyName(0) << " 2. " << gameParty.getPartyName(1) << " 3. " << gameParty.getPartyName(2) << " 4." << gameParty.getPartyName(3) << " 5. " << gameParty.getPartyName(4) << " ?" << endl;
                    cin >> player;
                        if((player > 0 && player <= 5) && gameParty.getPartyWeapons(player - 1) == 0 )
                        {
                        gameParty.setPartyWeapons(weapon - 1,player - 1);

                        gameParty.setPartyGold(gameParty.getPartyGold() - merch.getWeaponCost(weapon - 1, 5 - gameMap.getRoomCount()));
                        cook = false;  
                        return true;
                        }
                        else if (gameParty.getPartyWeapons(player - 1) != 0)
                        {
                            cout << gameParty.getPartyName(player - 1) <<  " already has a weapon" << endl;
                            return true;
                        }
                        else 
                        cout << "Enter valid number" << endl;
                        return true;
                }
                
            }
            else 
            {
                cout << "Enter a valid value" << endl;
                return true;
            }
    }
    
    else if (choice == 4)
    {
    // sub menu for armor
    // party = gamerch.getArmor(int number, Party the_party);

    int armor = 0;
    cout << "How many pieces of armor do you want? (Armor does not stack)" << endl;
    cin >> armor;

        if(armor > 0 && gameParty.enoughMoney(merch.getArmorCost(5 - gameMap.getRoomCount())) == true)
        {
            gameParty.setPartyGold(gameParty.getPartyGold() - (armor * merch.getArmorCost(5 - gameMap.getRoomCount())));


            gameParty.setPartyArmor(armor);
            return true;
        }
        else if (armor > 0 && gameParty.enoughMoney(merch.getArmorCost(5 - gameMap.getRoomCount())) == false)
        {
            cout << "Not enough money" << endl;
            return true;
        }
        else if (armor <= 0)
        {
            cout << "Please enter a valid value" << endl;
            return true;
        }
    }
    else if (choice == 5)
    {
    // sub menu for treasure
    // party = gamerch.sellTreasure(string treasure, Party the_party);

    int treasure = 0;
    cout << "You got treasure to sell? I'll take: " << endl; 
    cout << "(1.) 10g for a Silver Ring" << endl;
    cout << "(2.) 20g for a Ruby Necklace" << endl;
    cout << "(3.) 30g for a Emerald Bracelet" << endl; 
    cout << "(4.) 40g for a Diamond Circlet" << endl;
    cout << "(5.) 50g for a Gem-Encrusted Goblet" << endl;

    cout << endl;
    cin >> treasure;

        if (treasure > 0 && treasure <= 5)
        {
            int amount = 0;
            cout << "How many do you want to sell? " << endl;
            cin >> amount;
            if(gameParty.getPartyTreasure(treasure - 1) == amount)
            {
                gameParty.setPartyGold(gameParty.getPartyGold() + (amount * merch.getTreasureCost(treasure - 1, 5 - gameMap.getRoomCount())));
                return true;
            }
            else 
            {
                cout << "Do you think you can lie to me?" << endl;
                return true;
            } 

        }
        else if ( treasure < 0 || treasure > 5)
        {
            cout << "Please enter a valid value" << endl;
            return true;
        }
        return true;
    }

    else if (choice == 6)
    {
        cout << "Good Luck " << endl;
        cout << merchant << endl;
        return false;
    }
    return true;
    }

    void Dungeon::statusMenu()
    {
    cout << "+----------------+" << endl;
    cout << "| STATUS         |" << endl;
    cout << "+----------------+" << endl;
    cout << "| Rooms Cleared: "  << 5 - gameMap.getRoomCount() << "| Keys: " << gameParty.getPartyKeys() << "| Anger Level: "<< getSorcererAnger() << endl;
    cout << "+----------------+" << endl;
    cout << "| INVENTORY      |" << endl;
    cout << "+----------------+" << endl;
    cout << "| Gold           |" << gameParty.getPartyGold() << endl;
    cout << "| Ingredients    |" << gameParty.getPartyIngredients() << endl;
    cout << "| Cookware       |" << "P: " << gameParty.getPartyCookware(0) << "| F: " << gameParty.getPartyCookware(1) << "| C: " << gameParty.getPartyCookware(2) << endl;
    cout << "| Weapons        |" << "C: " << gameParty.getPartyWeaponType(0) << "| S: " << gameParty.getPartyWeaponType(1) << "| R: " << gameParty.getPartyWeaponType(2) << "| B: " << gameParty.getPartyWeaponType(3) <<  "| L: " << gameParty.getPartyWeaponType(4) << endl;
    cout << "| Armor          |" << gameParty.getPartyArmor() << endl;
    cout << "| Treasures      |" << "R: " << gameParty.getPartyTreasure(0) << "| N: " << gameParty.getPartyTreasure(1) << "| B: " << gameParty.getPartyWeaponType(2) << "| C: " << gameParty.getPartyWeaponType(3) << "| G: " << gameParty.getPartyWeaponType(4) << endl;    
    cout << "+----------------+" << endl;
    cout << "| PARTY          |" << endl;
    cout << "+----------------+" << endl;
    cout << "| " << gameParty.getPartyName(0) <<" | Fullness: " << gameParty.getPartyFullness(0) << endl;
    cout << "| " << gameParty.getPartyName(1) <<" | Fullness: " << gameParty.getPartyFullness(1) << endl;
    cout << "| " << gameParty.getPartyName(2) <<" | Fullness: " << gameParty.getPartyFullness(2) << endl;
    cout << "| " << gameParty.getPartyName(3) <<" | Fullness: " << gameParty.getPartyFullness(3) << endl;
    cout << "| " << gameParty.getPartyName(4) <<" | Fullness: " << gameParty.getPartyFullness(4) << endl;
    cout << "+----------------+" << endl;
    }
    
    bool Dungeon::acitonMenu()
    {
    int game_end = 0;
    for (int i = 0; i < 5; i++)
    {
        if(gameParty.getPartyFullness(i) == 0)
        {
            game_end += 1;
        }
    }
    
    if (gameParty.getPartyFullness(0) == 0)
    {
        cout << gameParty.getPartyName(0) << " has died! The party cannot continue on without their leadership!" << endl;
        
        return false;
    }
    else if (game_end == 4)
    {
        cout << "You do not have enough party members to help you through the dungeon! Enjoy eternity!" << endl;
        return false;
    }
    else if (sorcerer_power_ >= 100)
    {
        cout << "The sorcerer has grown impatient with your party. He has decided to destroy the dungeon with your party inside of it!" << endl;
        return false;
    }
     
        if(gameMap.isFreeSpace(gameMap.getPlayerRow(),gameMap.getPlayerCol()))
        {
            cout << "Select one:" << endl;
            cout << "1. Move" << endl;
            cout << "2. Investigate" << endl;
            cout << "3. Pick a Fight" << endl;
            cout << "4. Cook and Eat" << endl;
            cout << "5. Give up" << endl;
            int action_choice;
            cin >> action_choice;

                if(action_choice == 1)
                {
                    char the_move = ' ';
                    cout << "Enter what direction you wish to go in (w,a,s,d): " << endl;
                    cin >> the_move;

                    move(the_move);
                    return true;
                }
                else if(action_choice == 2)
                {
                    investigate();
                    if(prob.fortyPercent() == 1)
                    {
                        Misfortune();
                    }
                    return true;

                }
                else if(action_choice == 3)
                {
                    pick_a_fight();
                    if(prob.fortyPercent() == 1)
                    {
                        Misfortune();
                    }
                    return true;
                }
                else if(action_choice == 4)
                {
                    cook_and_eat();
                    if(prob.fortyPercent() == 1)
                    {
                        Misfortune();
                    }
                    return true;
                }
                else if(action_choice == 5)
                {
                    give_up();
                    return false;
                }  
            }
        else if(gameMap.isNPCLocation(gameMap.getPlayerRow(),gameMap.getPlayerCol()) == true)
            {
            cout << "Select one:" << endl;
            cout << "1. Move" << endl;
            cout << "2. Speak to NPC" << endl;
            cout << "3. Give up" << endl;
            int npc_choice;
            cin >> npc_choice;

                if(npc_choice == 1)
                {
                    char the_move = ' ';
                    cout << "Enter what direction you wish to go in (w,a,s,d): " << endl;
                    cin >> the_move;

                    move(the_move);
                    return true;
                }
                else if (npc_choice == 2)
                {
                    speak_to_npc();
                    gameMap.removeNPC(gameMap.getPlayerRow(),gameMap.getPlayerCol());
                    return true;
                }
                else if (npc_choice == 3)
                {
                    give_up();
                    return false;
                }
            }
        else if(gameMap.isRoomLocation(gameMap.getPlayerRow(),gameMap.getPlayerCol()))
            {
            int room = 0;
            cout << "1. Move" << endl;
            cout << "2. Open the Door" << endl;
            cout << "3. Give up" << endl;
            cin >> room;

                if(room == 1)
                {
                    char the_move = ' ';
                    cout << "Enter what direction you wish to go in (w,a,s,d): " << endl;
                    cin >> the_move;

                    move(the_move);
                    return true;
                }
                else if (room == 2)
                {
                // open the door
                if (open_the_door() == true)
                {
                    gameMap.removeRoom(gameMap.getPlayerRow(),gameMap.getPlayerCol());
                    gameMap.exploreSpace(gameMap.getPlayerRow(),gameMap.getPlayerCol());
                }

                return true;
                }   
                else if (room == 3)
                {
                    // give up
                    give_up();
                    return false;
                }
            }
         else if(gameMap.isDungeonExit(gameMap.getPlayerRow(),gameMap.getPlayerCol()))
         {

        /* if(pick_a_fight() == true)
        {
            cout << "You've succesfully escaped the sorcerer's grasp! Congratulations" << endl;
        }*/
           if (gameMap.getRoomCount() == 0)
            {
            
             cout << "You have succesfully escaped the dungeon!" << endl;
             cout << "Congratulations!" << endl;
             return false;
            }
         }

            return true;
            }


	/**
 	* Algorithm: splits up a string, when a separator is encountered, stores split up strings in an array
 	* 1. Use for loop to interate through input_string, 
 	* 2. if a separator is found, store string before separator in array[count],
 	* 3. increment count by one until i == input_string.length() 
 	* Parameters: input_string (string), separator (char), arr (string array), arr_size (int)
 	* Returns: -1,0,1, int count
	*/

     int Dungeon::split ( string input_string, char separator, string arr [], int arr_size)
     {

	int count = 0;
	int sub_place = 0;


    	for ( int i = 0; i < input_string.length(); i++)
    	{
          // finds where the separator is, and stores the string before the separator in a array
          if (input_string[i] == separator)
          {
              input_string.substr(sub_place, i - sub_place);
              if (count >= arr_size)
              {
                return -1;
              }
              arr[count] = input_string.substr(sub_place, i - sub_place);
              sub_place = i + 1;

              count = count + 1;
          }
        }

	if (count >= arr_size)
	{
    	  // since there won't be a separator at the end of string, we need store the last value in the string one more time
    	  arr[count] = input_string.substr(sub_place, input_string.length() - sub_place);
    	  return count + 1;
	}
	else if (input_string == "")
	{
   	  return 0;
	}
	else if (count == 0)
	{
     	  arr[0] = input_string;
    	  return 1;
	}
	else
	{
    	  arr[count] = input_string.substr(sub_place, input_string.length() - sub_place);
    	  return count+1;
	}
    };

int Dungeon::getResult()
{
    return game_result;
}
void Dungeon::setResult(int n)
{
    game_result = n;
}

void Dungeon::displayDungeonStats()
{
	struct dungeonStats {
		string leader_name;
		int number_of_moves;
		string win_or_lose;  // 1 is a win, 0 is a lose
	};

	dungeonStats stat_row;

	vector<dungeonStats> gamestathistory_winners;
	vector<dungeonStats> gamestathistory_losers;

	// open file if it exists otherwise create it
	ifstream checkFileExist;
	fstream statFile;
	checkFileExist.open("Dungeon_stats.txt");

	if (!checkFileExist)
	{
		// file does not exist. 
		// create the file

		statFile.open("Dungeon_stats.txt", ios::out); 
		statFile.flush();
		statFile.close();
	}
	else
	{
		// read values from file in 
		string line;
		string arr[3];
		int count = 0;
		

		while (!checkFileExist.eof()) // iterates until end of file has been reached
		{
			getline(checkFileExist, line);
			count = split(line, ',', arr, 3); // splits line into 3 parts, leader_name, number_of_moves, win_or_lose

			if (count == 3)
			{
				stat_row.leader_name = arr[0];
				stat_row.number_of_moves = std::stoi(arr[1]);
				stat_row.win_or_lose = arr[2];
				if (arr[2] == "1")
				{
					gamestathistory_winners.push_back(stat_row);
				}
				else
				{
					gamestathistory_losers.push_back(stat_row);
				}
			}

		}
		checkFileExist.close();
	};


	// add the current game value
	stat_row.leader_name = gameParty.getPartyName(0);
	stat_row.number_of_moves = total_game_moves;
	string currentGame = to_string(game_result);
	stat_row.win_or_lose = currentGame;

	// now open the file for append
	statFile.open("Dungeon_stats.txt", ios::app);

	if (statFile)
	{
		// write the current result into the file (at the end)
		string comma_seperated_row;
		string gm_mv_str = to_string(total_game_moves);
		comma_seperated_row.append(stat_row.leader_name).append(",").append(gm_mv_str).append(",").append(stat_row.win_or_lose);
		statFile << comma_seperated_row << endl;
		statFile.close();
        }
	else
	{
		cout << "existing file not open for append" << endl;
	}		


	// now push the current values into the in memory vectors for sorting
	if (currentGame == "1")
	{
		gamestathistory_winners.push_back(stat_row);
	}
	else
	{
		gamestathistory_losers.push_back(stat_row);
	}


	// sort results for display by most number of moves by winners and losers
	int i;
	int j;
	int stop = 1;
	dungeonStats temp;

        // sort winners by number of moves and print
	int winner_array_size = gamestathistory_winners.size();

	if (winner_array_size > 0)
	{
          for(i = 1; (i <= winner_array_size) && stop; i++)
	  {
	     stop = 0;
             for (j=0; j < winner_array_size - 1; j++)
	     {
	       if(gamestathistory_winners[j+1].number_of_moves > gamestathistory_winners[j].number_of_moves)
	       {
		       temp = gamestathistory_winners[j];
		       gamestathistory_winners[j] = gamestathistory_winners[j+1];
		       gamestathistory_winners[j+1] = temp;
		       stop = 1;
	       }
	     }
	  }

	  cout << " ************* Dungeon winners sorted by number of moves *************" << endl;
	  cout << " Player  --  number of moves  -- Win (1) Lose (0) " << endl;
	  cout << " ------------------------------------------------  " << endl;

	  // now print the sorted vector elements in that order
	  for(auto item: gamestathistory_winners)
	  {
		cout << item.leader_name << " -- " << item.number_of_moves << " -- " << item.win_or_lose  << endl;
	  }
	  cout << " ------------------------------------------------  " << endl;
	}
	
        // sort loserrs by number of moves and print
	int loser_array_size = gamestathistory_losers.size();
	stop = 1;

	if (loser_array_size > 0)
	{
          for(i = 1; (i <= loser_array_size) && stop; i++)
	  {
	     stop = 0;
             for (j=0; j < loser_array_size - 1; j++)
	     {
	       if(gamestathistory_losers[j+1].number_of_moves > gamestathistory_losers[j].number_of_moves)
	       {
		       temp = gamestathistory_losers[j];
		       gamestathistory_losers[j] = gamestathistory_losers[j+1];
		       gamestathistory_losers[j+1] = temp;
		       stop = 1;
	       }
	     }
	  }

	  cout << " ************* Dungeon losers sorted by number of moves *************" << endl;
	  cout << " Player  --  number of moves  -- Win (1) Lose (0) " << endl;
	  cout << " ------------------------------------------------  " << endl;

	  // now print the sorted vector elements in that order
	  for(auto item: gamestathistory_losers)
	  {
		cout << item.leader_name << " -- " << item.number_of_moves << " -- " << item.win_or_lose  << endl;

	  }
	  cout << " ------------------------------------------------  " << endl;
	}

}


int Dungeon::getMoves()
{
    return total_game_moves;
}
void Dungeon::setMoves(int moves)
{
    total_game_moves = moves;
}