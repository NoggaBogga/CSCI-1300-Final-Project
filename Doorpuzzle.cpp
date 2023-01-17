// Group People: Shehan Rajapakse Ashley Cody
#include <iostream>
#include <fstream>
#include "Doorpuzzle.h"

using namespace std;



	    
    Doorpuzzle::Doorpuzzle()
	{

	};
    // ask the user to enter 0 - Boulder, 1- Shears, 2- Parchement
    // get puzzle value from the choices array
    string Doorpuzzle::getChoice(int choice_index)
	{
		return choices[choice_index];
	}

    int Doorpuzzle::playPuzzle(string party_puzzle_choice)
    {
	int index = rand() % 3; // get a number from 0 - 2
	string door_choice = choices[index];
	if (party_puzzle_choice == door_choice)
			{
			// play again
			return 0;
			}
	// Boulder beats Shears - checking if party won
			else if ( (door_choice == choices[1]) && (party_puzzle_choice == choices[0]))
			{
			return 1;
			}
	// Parchment beats Boulder - checking if party won		
			else if ( (door_choice == choices[0]) && (party_puzzle_choice == choices[2]))
			{
			return 1;
			}
	// Shears beats Parchement - checking if party won
			else if ( (door_choice == choices[2]) && (party_puzzle_choice == choices[1]))
			{
			return 1;
			}
	// all the permutations where the door won the puzzle game
			else if ( (door_choice == choices[2]) && (party_puzzle_choice == choices[1]))
			{
			return -1;
			}
		return 0;
	}