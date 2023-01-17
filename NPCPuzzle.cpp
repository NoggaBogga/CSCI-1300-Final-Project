// Group People: Shehan Rajapakse Ashley Cody

#include <iostream>
#include "NPCPuzzle.h"
#include "Monster.h"
#include <fstream>

using namespace std;


	NPCPuzzle::NPCPuzzle()
	{

	};

    bool NPCPuzzle::loadRiddles(string filename)
    {
	    int count;
	    int split_size = 2; // only riddle and answer. two items after split
	    string arr[2];
	    string line;
		bool load = false;;

	    fin.open(filename); // open puzzles file

	    if (fin.fail())
	    {
		    cout << "missing puzzles file" << endl;
			return load;
	    }
	    else
	    {
			load = true;
		    while ((!fin.eof() && (actual_array_size < size_))) // iterates until end of file has been reached
		    {
			getline(fin, line);

			
			count = split(line, '~', arr, split_size);
			
            // stores riddle and anser in puzzle struct array (holds anser and riddle)
			if (count == 2)
			{
				puzzle_array_[actual_array_size].riddle_ = arr[0]; // riddle
				// remove control charaters from the riddle answer
				string temp = arr[1];
				string riddleAnswer;
				int i = 0;
				while (!iscntrl(temp[i]))
				{
					riddleAnswer.push_back(temp[i]);
					i++;
				}
				puzzle_array_[actual_array_size].answer_ = riddleAnswer; // answer
				actual_array_size ++;
			}
		    }
	    }
	return load;
    };

    string NPCPuzzle::getRiddle()
    {
	  
	    current_riddle_index = rand() % actual_array_size; // gets a number between 0 and actual_array_size
	    
	    return puzzle_array_[current_riddle_index].riddle_;
    };

    bool NPCPuzzle::checkAnswer(string player_answer)
    {
	    string puzArrayAnswer = puzzle_array_[current_riddle_index].answer_;
	    if (puzArrayAnswer.compare(player_answer) == 0)  // checks answer inputed with answer in text file
	    {
           
		    return true;
	    }
	    else
	    {
		    return false;
	    }
    };