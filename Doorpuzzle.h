// // Group People: Shehan Rajapakse Ashley Cody
#ifndef DOORPUZZLE_H
#define DOORPUZZLE_H

#include <iostream>
#include <fstream>

using namespace std;



class Doorpuzzle
{
    private:

	    string choices[3] = {"Boulder", "Shears", "Parchment"};

	    
    public:
    Doorpuzzle();

    // ask the user to enter 0 - Boulder, 1- Shears, 2- Parchement
    // get puzzle value from the choices array
    string getChoice(int choice_index);

    int playPuzzle(string party_puzzle_choice);
};
#endif