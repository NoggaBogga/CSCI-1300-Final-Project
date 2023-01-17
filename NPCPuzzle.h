// Group People: Shehan Rajapakse Ashley Cody

#ifndef NPCPUZZLE_H
#define NPCPUZZLE_H

#include <iostream>
#include <fstream>

using namespace std;



class NPCPuzzle
{
    private:
	    int size_ = 20;

        // puzzle object
	    struct the_puzzle {
		    string riddle_;
		    string answer_;
	    };

	    the_puzzle puzzle_array_[20];

	    int current_riddle_index = 0;
	    int actual_array_size = 0;
	    ifstream fin;

	    
    public:
    NPCPuzzle();

	bool loadRiddles(string filename);

    string getRiddle();
    bool checkAnswer(string player_answer);
};
#endif