// Group People: Shehan Rajapakse Ashley Cody

#ifndef DUNGEON_H
#define DUNGEON_H
#include "Map.h"
#include "Party.h"
#include "Genprob.h"
#include "Merchant.h"
#include "NPCPuzzle.h"
#include "Doorpuzzle.h"
#include "Monster.h"
#include <vector>

using namespace std;

class Dungeon
{


private:
	
	int sorcerer_power_ = 0;
	bool sorcerer_battle = false;
	vector <Monster> monsters_list = {};
	string misfortune[3] = {"ingredients", "cookware","armor"};
	Party gameParty; 
	Map gameMap; 
	Genprob prob;
	Merchant merch;
	NPCPuzzle puz;
	Doorpuzzle door_puz;
// key to a room
	
	int total_game_moves = 0;
	int game_result = 0;

	int split( string input_string, char separator, string arr [], int arr_size);

public:

	// preapre game map
	Dungeon();
	Map randomizeMap();
	Map getMap();
	Party getParty();
	bool getBattle();
	void setBattle(bool b);
	int getResult();
	void setResult(int n);

	// setters
	void setPartyName(string leader_, string companion1_, string companion2_, string companion3_, string companion4_);
	void setPartyFullness(int full1, int full2, int full3, int full4, int full5);
	void setPartyGold(int amt_of_gold);
	void setPartyIngredients(int amt_of_ingredients);
	void setPartyCookware(int cookware);

	// getters
	
	// Actions
	Party move(char the_move);
	Party investigate();
	bool pick_a_fight();
	Party give_up();
	Party speak_to_npc();
	bool open_the_door();
	Party cook_and_eat();

	// sorcerer anger
	int getSorcererAnger();
	
	// Misfortune
	int randommis;
	void Misfortune();

	// Merchant Menu Actions
	bool merchantMenuAcitons();
	// Status Menu
	void statusMenu();
	// Action Menu
	bool acitonMenu();

	// display all time Dungeon game stats by moves
	void displayDungeonStats();
	int getMoves();
	void setMoves(int moves);
};
#endif